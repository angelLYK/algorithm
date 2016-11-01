/*
 * RadixSort.c
 *
 *  Created on: Nov 1, 2016
 *      Author: angel
 */

#include "RadixSort.h"

int getMaxNumInArray(int a[], int size) {
	int max;
	max = a[0];
	for (int i = 1; i < size; i++) {
		if (max < a[i]) {
			max = a[i];
		}
	}
	return max;

}

void bucketSort(int a[], int size, int ex) {
	int count[DECIMAL];
	int output[size];
	//init count
	for (int i = 0; i < DECIMAL; i++) {
		count[i] = 0;
	}

	//
	for (int i = 0; i < size; i++) {
		count[(a[i]/ex)%10]++;
	}

	//计算在output数组中的位置
	for (int i = 1; i < DECIMAL; i++) {
		count[i] = count[i] + count[i - 1];
	}

	//入坑
	for (int i = size - 1; i >= 0; i--) {
		output[count[(a[i] / ex) % 10] - 1] = a[i];
		count[(a[i] / ex) % 10]--;
	}

	//出坑
	for (int i = 0; i < size; i++) {
		a[i] = output[i];
	}

}

static void printBeforeSort(int a[], int size) {
	printf("beforeSort-> ");
	for (int i = 0; i < size - 1; i++) {
		printf("%d, ", a[i]);
	}
	printf("%d\n", a[size - 1]);
}

static void printAfterSort(int a[], int size) {
	printf("afterSort-> ");
	for (int i = 0; i < size - 1; i++) {
		printf("%d, ", a[i]);
	}
	printf("%d\n", a[size - 1]);
}

int main(int argc, char **argv) {
	int a[] = { 300, 25, 22, 43, 66, 8, 2, 6, 99, 1000 };
	int size = sizeof(a) / sizeof(a[0]);
	int ex = 1;

	int maxNum = getMaxNumInArray(a, size);

	printBeforeSort(a, size);

	while ((maxNum / ex) != 0) {
		printf("%d\n", (maxNum / ex));
		bucketSort(a, size, ex);
		ex = ex * 10;
	}

	printAfterSort(a, size);

}

