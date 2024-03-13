#pragma once

#include <cassert>
#include <stdexcept>

namespace vec {
	class Vector {
	public:
		Vector();									// Allocate dynamic array of size 1.
		Vector(size_t size);						// Allocate dynamic array of size "size".
		Vector(size_t size, double def_val);		// Allocate dynamic array of size "size" and fill it with "def_val".
		~Vector();									
	
		double& operator[](size_t index);			// Access element operator. Throws out of index exception.
		double at(size_t index);					// Return element at "index".
		bool is_empty();							// Check if empty.
		void push(double item);						// Push to the end. Allocates more space if Capacity == Size of dynamic array.
		void insert(size_t index, double item); 	// Insert element at index >= 0 and shift everything to the right.
		double pop();								// Pop element from the end and shift to the left.
		void delete_at_index(size_t index);			// Delete element at index: "index".
		void remove(double item);					// Remove item, even if in multiple places.
		int find(double item);						// Find item at index, returns first index where item was found.
	
		size_t capacity();							// Return capacity of the array.
		size_t size();								// Return size of the array.
	private:	
		double* elements;					// static elements array, allocated on heap
		size_t m_capacity; 					// number of elements we can hold
		size_t m_size;						// number of held elements

		// ************* 
		// * Utiliites *
		// *************
		size_t shift_capacity(size_t& size);
		double* resize(size_t new_capacity);
	};
}


