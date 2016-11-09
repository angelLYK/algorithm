/*
 * testQueue.c
 *
 *  Created on: Nov 9, 2016
 *      Author: angellee
 */

#include "queue.h"
#include <stdio.h>

int main(int argc, char **argv) {
	Queue q = CreateQueue(15);
	int i = 10;
	for(; i>=0; i--){
		Enqueue(i, q);
	}

	while(!IsEmpty(q)){
		ElementType x = Front(q);
		printf("%d\t", x);
		Dequeue(q);
	}
	printf("\n");
	DisposeQueue(q);

}

