/*
 * listDirectory.c
 *
 *  Created on: Nov 18, 2016
 *      Author: angel
 */

#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//root: last char is '/'
static char *getPath(char *root, char *ep){
	char *newRoot;
	int rootSize, fileNameSize;
	rootSize = strlen(root);
	fileNameSize = strlen(ep);
	newRoot = malloc(rootSize + fileNameSize + 2);
	memset(newRoot, '\0', rootSize + fileNameSize + 2);
	strcat(newRoot, root);
	strcat(newRoot, ep);
	strcat(newRoot, "/");
	return newRoot;
}

static void printfName(char *root, struct dirent *ep, int depth){
	int i = 0;
	for(; i<=depth; i++){
		printf("  ");
	}
	printf("%s\n", ep->d_name);
}

//root: last char is '/'
static void listDir(char *root, DIR *d, int depth){
	depth++;
	char *newRoot;
	char * httpServerName;
	DIR *nd;
	struct dirent *ep;
	while((ep = readdir(d))!= NULL){
		if(strstr(ep->d_name, "..") == NULL && strcmp(ep->d_name, ".") != 0){
			httpServerName = ep->d_name;
			printfName(root, ep, depth);
			if(ep->d_type == DT_DIR){
				newRoot = getPath(root, ep->d_name);
				nd = opendir(newRoot);
				if(nd != NULL){// 如果没有打开的权限， 则nd为NULL
					listDir(newRoot, nd, depth);
				}else {
					printf("NULL-> %s\n", ep->d_name);
				}
				free(newRoot);
			}
		}
	}
	closedir(d);
}

int main(int argc, char **argv) {
	DIR *d;
	d = opendir(argv[1]);
	if(d != NULL){
		listDir(argv[1],d, 0);
	}
}

