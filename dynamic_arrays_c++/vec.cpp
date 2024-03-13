#include "vec.h"


namespace vec {
	Vector::Vector() {
		elements = new double[1];
		m_capacity = 1;
		m_size = 1;
	}

	Vector::Vector(size_t size) {
		m_capacity = shift_capacity(size);
		m_size = size;
		
		elements = new double[m_capacity];
		assert(elements && "Could not allocate an array.");
		for (size_t i = 0; i < size; i++) 
			elements[i] = 0;
	}

	Vector::Vector(size_t size, double def_val) {
		m_capacity = shift_capacity(size); 
		m_size = size;
		
		elements = new double[m_capacity];
		assert(elements && "Could not allocate an array.");
		for (size_t i = 0; i < size; i++) 
			elements[i] = def_val;
	}

	Vector::~Vector() { delete[] elements; }

	double& Vector::operator[](size_t index) {
		return index >= m_size ? throw std::out_of_range("Index out of range.") : elements[index];
	}

	double Vector::at(size_t index) {
		return index >= capacity() ?
			throw std::out_of_range("Index out of range.") : elements[index];
	}

	bool Vector::is_empty() { return m_size > 0 ? true : false; }

	void Vector::push(double item) {
		if (m_size == m_capacity) elements = resize(m_capacity * 2);

		elements[m_size] = item;
		m_size++;
	}

	void Vector::insert(size_t index, double item) {
		assert(index < m_size && "Invalid index. Out of range.");


		push(elements[m_size - 1]);
		for (size_t i = m_size - 1; i > index; i--) {
			elements[i] = elements[i - 1];
		}

		elements[index] = item;
	}

	double Vector::pop() {
		double pop_value = elements[m_size - 1];
		m_size--;
		if (m_size <= m_capacity / 4) elements = resize(m_capacity / 2);

		return pop_value;
	}

	void Vector::delete_at_index(size_t index) {
		assert(index < m_size && "Invalid index. Out of range.");

		for (size_t i = index; i < m_size; i++)
			elements[i] = elements[i + 1];

		pop();
		if (m_size <= m_capacity / 4) elements = resize(m_capacity / 2);
	}

	void Vector::remove(double item) {
		for (size_t i = 0; i < m_size; i++)
			if (elements[i] == item) delete_at_index(i);
	}

	int Vector::find(double item) {
		for (size_t i = 0; i < m_size; i++)
			if (elements[i] == item) return (int)i;

		return -1;
	}

	size_t Vector::capacity() { return m_capacity; }
	size_t Vector::size() { return m_size; }

	// utiliites
	size_t Vector::shift_capacity(size_t& size) {
		size_t base_capacity = 1;
		while (base_capacity < size) base_capacity <<= 1;

		return base_capacity;
	}

	double* Vector::resize(size_t new_capacity) {
		if (new_capacity > m_capacity) {
			double* new_elements = new double[new_capacity];
			assert(new_elements && "Could not allocate an array.");
			for (size_t i = 0; i < m_capacity; i++)
				new_elements[i] = elements[i];
			delete[] elements;
			m_capacity = new_capacity;

			return new_elements;
		}
		else {
			double* new_elements = new double[new_capacity];
			assert(new_elements && "Could not allocate an array.");
			for (size_t i = 0; i < new_capacity; i++)
				new_elements[i] = elements[i];
			delete[] elements;
			m_capacity = new_capacity;

			return new_elements;
		}
	}
}
