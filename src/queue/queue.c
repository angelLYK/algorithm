/*
 * queue.c
 *
 *  Created on: Nov 9, 2016
 *      Author: angellee
 */

#include "queue.h"
#include "../fatal.h"
#include <stdio.h>
#include <stdlib.h>

#define MinQueueSize (5)

struct QueueRecord {
	int Capacity;
	int Front;
	int Rear;
	int Size;
	ElementType *Array;
};

int IsEmpty(Queue q){
	return q->Size == 0;
}

int IsFull(Queue q){
	return q->Size == q->Capacity;
}

Queue CreateQueue(int MaxElements){
	if (MaxElements < MinQueueSize) {
		Error("不允许创建大小小于5的队列");
	}

	Queue queue = malloc(sizeof(struct QueueRecord));
	if(queue == NULL){
		Error("OOM");
	}
	queue->Array = malloc(sizeof(ElementType) * MaxElements);
	if(queue->Array == NULL){
		Error("OOM");
	}

	queue->Capacity = MaxElements;
	makeEmpty(queue);
	return queue;
}

void makeEmpty(Queue q){
	q->Size = 0;
	q->Front = 1;
	q->Rear = 0;
}

void DisposeQueue(Queue q){
	if(q != NULL){
		free(q->Array);
		free(q);
	}
}

void Enqueue(ElementType X, Queue q){
	if(IsFull(q)){
		Error("队列已经满了");
	}else{
		q->Size++;
		q->Rear = Succ(q->Rear, q);
		q->Array[q->Rear] = X;
	}
}

void Dequeue(Queue q){
	if(IsEmpty(q)){
		Error("队列为空");
	}else{
		q->Size--;
		q->Front = Succ(q->Front, q);
	}
}

ElementType Front(Queue q){
	if(!IsEmpty(q)){
		return q->Array[q->Front];
	}else{
		Error("队列为空");
		return 0;
	}
}

ElementType FrontAndDequeue(Queue q){
	if(!IsEmpty(q)){
		q->Size--;
		ElementType X = q->Array[q->Front];
		q->Front = Succ(q->Front, q);
		return X;
	}else{
		Error("队列为空");
		return 0;
	}
}

int static Succ(int v, Queue q){
	if(++v == q->Capacity){
		v=0;
	}
	return v;
}


