/*
 * stackTest.c
 *
 *  Created on: Nov 7, 2016
 *      Author: angel
 */

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	Stack s;
	int i = 0;
	s = createStack();
	for(; i < 10; i++){
		push(i, s);
	}
	while(!isEmpty(s)){
		printf("%d\n", top(s));
		pop(s);
	}
}

