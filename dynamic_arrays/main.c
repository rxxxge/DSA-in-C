#include "darray.h"


int main(void) {
	DArray cli;
	cli = self_init(&cli);

	push_back(&cli, 0);
	print_data(size(&cli), cli.capacity);

	print_array(&cli);
	for (int i = 1; i < 11; i++)
		push_back(&cli, i);

	rm(&cli, 0);
	for (int i = 0; i < size(&cli); i++) {
		set(&cli, i, 5 - i);
	}
	
	print_array(&cli);
	print_data(size(&cli), cli.capacity);


	return 0;
}