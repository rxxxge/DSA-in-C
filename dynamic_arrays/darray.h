#ifndef DARRAY_H_
#define DARRAY_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef struct {
	int* darray;
	size_t size;
	size_t capacity;
} DArray;

// ========================
// *          API         *
// ========================
DArray self_init(DArray *self); 				// Initialize dynamic array. No initial values. Initial capacity is 1
int get(DArray *self, int index); 				// Get element of the array at position "index"
void set(DArray *arr, int index, int value);	// Set value at position "index"
void push_back(DArray *arr, int value);			// Add to the end of array "value"
void rm(DArray *arr, int index);				// Remove element at "index"
size_t size(DArray *arr);						// Get size of array
/*
* For some tests
*/
void print_data(size_t size, size_t capacity);	// Print size and capacity
void print_array(DArray *cli);					// Print whole array

#endif