/*
 * infix2postfix.c
 *
 *  Created on: Nov 7, 2016
 *      Author: angellee
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

//从stdin 读入一行
	//参考链接
		//http://stackoverflow.com/questions/12252103/how-to-read-a-line-from-stdin-blocking-until-the-newline-is-found
		//http://man7.org/linux/man-pages/man3/getline.3.html
//把以'-'开头的表达式变换为'0-'的格式
//解析行，把infix转换为postfix

char *readInfixExpression(){
	char *buff = NULL;
	ssize_t len;
	size_t buffLen = 0;
	len = getline(&buff, &buffLen, stdin);
	char *line = malloc(len);
	strncpy(line, buff, len);
	line[len - 1] = '\0';
	return line;
}

void stringTrim(char *str){
	char *pTmp = str;
	while(*str != '\0'){
		if(*str != ' '){
			*pTmp = *str;
			pTmp++;
		}
		str++;
	}
	*pTmp = '\0';
}

char *changeStrIfMinusIsFirst(char *str){
	if(*str == '-'){
		size_t len = strlen(str);
		char *nstr = malloc(len + 1);
		*nstr = '0';
		strncpy(nstr + 1, str, len);
		free(str);
		return nstr;
	}
	return str;
}

//扫面字符串，当读取数字，输出；当读入符号，把符号压入栈，同时输出栈中优先级大于或者等于待入栈的符号。
//特殊情况：'('优先级最高，只有遇到 ')'时，把‘(’与‘)’之间的符号输出。
//扫描完字符串后，把栈中所有元素输出

char *infix2postfix(char *str){
	Stack stack = createStack();
	char *output1 = malloc(1024);
	char *output = output1;
	char c;
	while((c = *str) != '\0'){
		if(c >= '0' && c <= '9'){//数字
			*output++ = c;
		}
		if(c == '('){
			push(c, stack);
		}else
		if(c == '*' || c == '/'){
			if(isEmpty(stack)){
				push(c, stack);
			}else{
				char t;
				while(!isEmpty(stack) && ((t = top(stack)) == '*' || (t = top(stack)) == '/' )){
					*output++ = t;
					pop(stack);
				}
				push(c, stack);
			}
		}else
		if(c == '-' || c == '+'){
			if(isEmpty(stack)){
				push(c, stack);
			}else{
				char f;
				while(!isEmpty(stack) && ((f = top(stack)) == '*' || (f = top(stack)) == '/'
						|| (f = top(stack)) == '-' ||  (f = top(stack)) == '+')){
					*output++ = f;
					pop(stack);
				}
				push(c, stack);
			}
		}else
		if(c == ')'){
			char v;
			while(!isEmpty(stack) && ((v = top(stack)) != '(')){
				*output++ = v;
				pop(stack);
			}
			pop(stack);//ignode '('
		}
		str++;
	}

	while(!isEmpty(stack)){
		*output++ = top(stack);
		pop(stack);
	}
	*output='\0';
	free(stack);
	return output1;
}

int main(int argc, char **argv) {
	char *infixLine;
	char *trim;
	char *out;
	infixLine = readInfixExpression();
	stringTrim(infixLine);
	trim = changeStrIfMinusIsFirst(infixLine);
	out = infix2postfix(trim);
	printf("%s\n", out);
}

