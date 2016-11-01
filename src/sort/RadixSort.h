/*
 * RadixSort.h
 *
 *  Created on: Nov 1, 2016
 *      Author: angel
 */

#ifndef RADIXSORT_H_
#define RADIXSORT_H_

#include <stdio.h>
#include <stdlib.h>

#define COUNT_SIZE 10
#define DECIMAL	10

void bucketSort(int a[], int size, int ex);
int getMaxNumInArray(int a[], int size);

#endif /* RADIXSORT_H_ */
