#include "darray.h"

DArray self_init(DArray *self) {
	size_t size = 0;
	size_t capacity = 1;

	int *darray = (int *)malloc(sizeof(int) * capacity);
	assert(darray && "Could not allocate memory on heap.");

	self->darray = darray;
	self->size = size;
	self->capacity = capacity;

	return *self;
}

int get(DArray *self, int index) {
	assert((index >= 0 && index < self->size) && "Index out of range.");
	return self->darray[index];
}

void set(DArray *self, int index, int value) {
	assert((index >= 0 && index < self->size) && "Index out of range.");
	self->darray[index] = value;
}

void push_back(DArray *self, int value) {
	if (self->size == self->capacity) {
		int *new_darray = (int *)malloc(sizeof(int) * self->capacity*2);
		for (int i = 0; i < self->capacity; i++)
			new_darray[i] = self->darray[i];
		
		free(self->darray);
		self->darray = new_darray;
		self->capacity *= 2;
	}

	self->darray[self->size] = value;
	self->size++;
}

void rm(DArray *self, int index) {
	assert((index >= 0 && index < self->size) && "Index out of range.");
	for (int j = index; j < self->size - 1; j++) 
		self->darray[j] = self->darray[j + 1];

	self->size--;
}

size_t size(DArray *self) {
	return self->size;
}


// ==================================================
void print_data(size_t size, size_t capacity) {
	printf("size = %lli\nCapacity = %lli\n", size, capacity);
}

void print_array(DArray *cli) {
	printf("[ ");
	for (int i = 0; i < size(cli); i++) {
		printf("%i, ", get(cli, i));
	}
	printf("]\n");
}
// ===================================================