/*
 * queue.h
 *
 *  Created on: Nov 9, 2016
 *      Author: angellee
 */

#ifndef QUEUE_H_
#define QUEUE_H_

typedef int ElementType;
struct QueueRecord;
typedef struct QueueRecord *Queue;

int IsEmpty(Queue q);
int IsFull(Queue q);
Queue CreateQueue(int MaxElements);
void DisposeQueue(Queue q);
void makeEmpty(Queue q);
void Enqueue(ElementType X, Queue q);
ElementType Front(Queue q);
void Dequeue(Queue q);
ElementType FrontAndDequeue(Queue q);


#endif /* QUEUE_H_ */
