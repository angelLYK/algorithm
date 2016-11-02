/*
 * list.c
 *
 *  Created on: Nov 2, 2016
 *      Author: angel
 */

#include <stdlib.h>
#include "list.h"
#include "../fatal.h"

struct Node {
	ElementType Element;
	Position Next;
};

enum InternalError{
	NULL_POINTER
};

List makeEmpty(List L) {
	if(L != NULL){
		deleteList(L);
	}
	L = malloc(sizeof(struct Node));
	if(L == NULL){
		FatalError("OOM");
	}
	L->Next = NULL;
	return L;
}

int isEmpty(List L){
	if(L == NULL){//return true
		WarnError("L is NULL");
		return NULL_POINTER;
	}

	return L->Next == NULL;
}

int isLast(List L, Position P){
	if(P == NULL){
		WarnError("L is NULL");
		return NULL_POINTER;
	}

	return P->Next == NULL;
}

Position find(ElementType e, List L){//可以优化
	Position po;
	if(L ==NULL){
		return NULL;
	}

	while(L->Next != NULL){
		po = L->Next;
		if(po != NULL && po->Element == e){//find
			return po;
		}
		L = po;
	}

	return NULL;
}

void Delete( ElementType X, List L ){
	Position p, tmp;

	if(L == NULL){
		WarnError("L is NULL");
		return;
	}

	p = findPrevious(X, L);
	if(p != NULL){
		tmp = p->Next;
		p->Next = tmp->Next;
		tmp->Next = NULL;
		free(tmp);
	}
}

Position FindPrevious( ElementType X, List L ){
	Position p, pre;

	if(L == NULL || L->Next == NULL){
		return NULL;
	}

	p = L->Next;
	if(p->Element == X){//只有一个元素
		return L;
	}

	while(p->Next != NULL){
		pre = p;
		p = p->Next;
		if(p != NULL && p->Element == X){
			return pre;
		}
	}

	return NULL;
}
