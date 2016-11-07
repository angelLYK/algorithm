/*
 * stack.h
 *
 *  Created on: Nov 4, 2016
 *      Author: angel
 */

#ifndef STACK_H_
#define STACK_H_

typedef int ElementType;
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;

int isEmpty(Stack s);
Stack createStack(void);
void disposeStack(Stack s);
void makeEmpty(Stack s);
void push(ElementType X, Stack s);
ElementType top(Stack s);
void pop(Stack s);

#endif /* STACK_H_ */
