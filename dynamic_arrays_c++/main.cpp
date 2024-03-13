#include <iostream>

#include "vec.h"


using namespace vec;

// Some functions for test output
void print_arr(Vector& v, const char* name);
void fprint_arr(Vector& v, const char* name);
// Some macro for test output
#define print(x) print_arr(x, #x);
#define fprint(x) fprint_arr(x, #x);


int main() {

	Vector a;
	Vector v(5);
	Vector c(10, 0);

	// fprint(a);
	a[0] = 1;
	print(a);
	fprint(v);
	print(c);

	std::cout << "capacity of array: " << a.capacity() << "\n";
	std::cout << "capacity of array: " << v.capacity() << "\n";
	std::cout << "capacity of array: " << c.capacity() << "\n";

	std::cout << "size of array: " << a.size() << "\n";
	std::cout << "size of array: " << v.size() << "\n";
	std::cout << "size of array: " << c.size() << "\n";


	for (size_t i = 0; i < 7; i++) {
		c.push(-2);
	}

	print(c);

	std::cout << "capacity of array: " << c.capacity() << "\n";
	std::cout << "size of array: " << c.size() << "\n";

	c.insert(0, 1);

	for (size_t i = 0; i < 10; i++)
		c.insert(i, 1);
	print(c);

	std::cout << "capacity of array: " << c.capacity() << "\n";
	std::cout << "size of array: " << c.size() << "\n";


	for (size_t i = 0; i < 10; i++) {
		double r = c.pop();
		a.push(r);
	}

	print(a);
	print(c);

	std::cout << "capacity of array: " << c.capacity() << "\n";
	std::cout << "size of array: " << c.size() << "\n";

	
	a.delete_at_index(0);
	a.delete_at_index(a.size() - 1);
	a.delete_at_index(a.size() - 1);
	a.delete_at_index(a.size() - 1);

	print(a);
	std::cout << "capacity of array: " << a.capacity() << "\n";
	std::cout << "size of array: " << a.size() << "\n";



	return 0;
}




void print_arr(Vector& v, const char* name) {
	size_t size = v.size();

	std::cout << name << " = [ ";
	for (size_t i = 0; i < size - 1; i++)
		std::cout << v[i] << ", ";

	std::cout << v[size - 1] << " ]";

	std::cout << "\n";
}

void fprint_arr(Vector& v, const char* name) {
	size_t size = v.size();

	std::cout << name << " = [ ";
	for (size_t i = 0; i < size - 1; i++) {
		v[i] = (double)i + 1;
		std::cout << v[i] << ", ";
	}

	v[size - 1] = v[size - 2] + 1;
	std::cout << v[size - 1] << " ]";

	std::cout << "\n";
}