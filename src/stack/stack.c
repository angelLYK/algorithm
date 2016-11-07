/*
 * stack.c
 *
 *  Created on: Nov 4, 2016
 *      Author: angel
 */

#include <stdlib.h>
#include <stdio.h>
#include "../fatal.h"
#include "stack.h"

struct Node{
	ElementType Element;
	PtrToNode Next;
};

int isEmpty(Stack s){
	return s->Next == NULL;
}

Stack createStack(void){
	Stack s = malloc(sizeof(struct Node));
	if(s == NULL){
		Error("OOM");
	}
	s->Next = NULL;
	return s;
}

void makeEmpty(Stack s){
	if(s == NULL){
		Error("null pointer");
	}

	while(!isEmpty(s)){
		pop(s);
	}
}

void push(ElementType X, Stack s){
	PtrToNode node;
	if(s == NULL){
		Error("null pointer");
	}
	node = malloc(sizeof(struct Node));
	node->Element = X;
	node->Next = s->Next;
	s->Next = node;
}

ElementType top(Stack s){
	if(s == NULL){
		Error("null pointer");
	}
	if(!isEmpty(s)){
		return s->Next->Element;
	}
	Error("stack empty");
	return 0;
}

void pop(Stack s){
	PtrToNode node;

	if(s == NULL){
		Error("null pointer");
	}

	node = s->Next;
	s->Next = node->Next;
	free(node);
}
