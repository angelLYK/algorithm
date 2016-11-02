/*
 * list.h
 *
 *  Created on: Nov 2, 2016
 *      Author: angel
 */

#ifndef LIST_H_
#define LIST_H_

typedef int ElementType;
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List; //List aways point to the header of the list.
typedef PtrToNode Position;

List makeEmpty(List L);
int isEmpty(List L);
int isLast(List L, Position P);
Position find(ElementType e, List L);
void delete(ElementType e, List L);
Position findPrevious(ElementType e, List L);
void insert(ElementType e, List L, Position P);
void deleteList(List L);
Position header(List L);
Position first(List L);
Position advance(Position P);
ElementType retrieve(Position P);

#endif /* LIST_H_ */
