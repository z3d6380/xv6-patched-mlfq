// File: cqueue.h
// Date: 2022-11-05
// Author: Luis Moraguez
// Description: Circular Queue Constructors for MLFQ Scheduler

#ifndef CQUEUE_H
#define CQUEUE_H

#include "types.h"
#include "defs.h"
#include "param.h"

typedef struct CQueue {
    int head;
    int tail;
    int size;
    int capacity;
    struct proc* root[NPROC];
} CQueue;

void cqueue_init(CQueue*, int);
int cqueue_isEmpty(CQueue*);
int cqueue_isFull(CQueue*);
int cqueue_size(CQueue*);
int cqueue_capacity(CQueue*);
struct proc** cqueue_enqueue(CQueue*, struct proc*);
struct proc* cqueue_dequeue(CQueue*);
struct proc* cqueue_pop(CQueue*, int);
struct proc* cqueue_remove(CQueue*, int);
struct proc* cqueue_find(CQueue*, int);
void cqueue_print(CQueue*);

#endif // CQUEUE_H