// File: cqueue.c
// Date: 2022-11-05
// Author: Luis Moraguez
// Description: Circular Queue Implementation for MLFQ Scheduler

#include "cqueue.h"
#include "defs.h"
#include "mmu.h"
#include "param.h"
#include "proc.h"
#include "types.h"

// Utility function to initialize a circular queue
// NAME         : cqueue_init()
// INPUT        : CQueue* q, int _capacity
// OUTPUT       : void
// DESCRIPTION  : Initializes a circular queue with a given capacity
void cqueue_init(CQueue* q, int _capacity) {
    q->head = 0;
    q->tail = -1;
    q->size = 0;
    q->capacity = _capacity;
    // q->root[NPROC] = NULL;
}

// Utility functions

// NAME         : cqueue_isEmpty()
// INPUT        : CQueue* q
// OUTPUT       : int : -1 if NULL, 1 if empty, 0 if not empty
// DESCRIPTION  : Checks if a circular queue is empty
int cqueue_isEmpty(CQueue* q) {
    if (q == NULL) {
        return -1;
    }
    return q->size == 0;
}

// NAME         : cqueue_isFull()
// INPUT        : CQueue* q
// OUTPUT       : int : -1 if NULL, 1 if full, 0 if not full
// DESCRIPTION  : Checks if a circular queue is full
int cqueue_isFull(CQueue* q) {
    if (q == NULL) {
        return -1;
    }
    return q->size == q->capacity;
}

// NAME         : cqueue_size()
// INPUT        : CQueue* q
// OUTPUT       : int : -1 if NULL, size of queue otherwise
// DESCRIPTION  : Returns the size of a circular queue
int cqueue_size(CQueue* q) {
    if (q == NULL) {
        return -1;
    }
    return q->size;
}

// NAME         : cqueue_capacity()
// INPUT        : CQueue* q
// OUTPUT       : int : -1 if NULL, capacity of queue otherwise
// DESCRIPTION  : Returns the capacity of a circular queue
int cqueue_capacity(CQueue* q) {
    if (q == NULL) {
        return -1;
    }
    return q->capacity;
}

// NAME         : cqueue_enqueue()
// INPUT        : CQueue* q, struct proc* p
// OUTPUT       : struct proc** : Do nothing if NULL, Do nothing if FULL, pointer to the new element otherwise
// DESCRIPTION  : Enqueues a process into a circular queue
struct proc** cqueue_enqueue(CQueue* q, struct proc* p) {
    if (q == NULL || cqueue_isFull(q)) {
        return NULL;
    }
    q->tail = (q->tail + 1) % q->capacity;
    q->root[q->tail] = p;
    q->size++;
    return &q->root[q->tail];
}

// NAME         : cqueue_dequeue()
// INPUT        : CQueue* q
// OUTPUT       : struct proc* : Do nothing if NULL, Do nothing if EMPTY, pointer to the dequeued element otherwise
// DESCRIPTION  : Dequeues a process from a circular queue
struct proc* cqueue_dequeue(CQueue* q) {
    if (q == NULL || cqueue_isEmpty(q)) {
        return NULL;
    }
    struct proc* p = q->root[q->head];
    q->head = (q->head + 1) % q->capacity;
    q->size--;
    return p;
}

// NAME         : cqueue_pop()
// INPUT        : CQueue* q, int index
// OUTPUT       : struct proc* : Do nothing if NULL, Do nothing if EMPTY, pointer to the popped element otherwise
// DESCRIPTION  : Pops a process from a circular queue
struct proc* cqueue_pop(CQueue* q, int index) {
    if (q == NULL || cqueue_isEmpty(q)) {
        return NULL;
    }
    struct proc* p = q->root[index];
    for (int i = index; i < q->size - 1; i++) {
        q->root[i] = q->root[i + 1];
    }
    q->size--;
    return p;
}

// NAME         : cqueue_remove()
// INPUT        : CQueue* q, int pid
// OUTPUT       : struct proc* : Do nothing if NULL, Do nothing if EMPTY, pointer to the removed element otherwise
// DESCRIPTION  : Removes a process from a circular queue by PID
struct proc* cqueue_remove(CQueue* q, int pid) {
    if (q == NULL || cqueue_isEmpty(q)) {
        return NULL;
    }
    for (int i = 0; i < q->size; i++) {
        if (q->root[i]->pid == pid) {
            return cqueue_pop(q, i);
        }
    }
    return NULL;    
}

// NAME         : cqueue_find()
// INPUT        : CQueue* q, int pid
// OUTPUT       : struct proc* : Do nothing if NULL, Do nothing if EMPTY, pointer to the found element otherwise
// DESCRIPTION  : Finds a process in a circular queue by PID
struct proc* cqueue_find(CQueue* q, int pid) {
    if (q == NULL || cqueue_isEmpty(q)) {
        return NULL;
    }
    for (int i = 0; i < q->size; i++) {
        if (q->root[i]->pid == pid) {
            return q->root[i];
        }
    }
    return NULL;
}

// NAME         : cqueue_print()
// INPUT        : CQueue* q
// OUTPUT       : void
// DESCRIPTION  : Prints a circular queue
void cqueue_print(CQueue* q) {
    if (q == NULL) {
        return;
    }
    for (int i = 0; i < q->size; i++) {
        cprintf("%d, ", q->root[i]->pid);
    }
    cprintf("\n");
}