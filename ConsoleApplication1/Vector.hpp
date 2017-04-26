////////////////////////////////////////////////////////////////////////////////
// File Name:      Vector.hpp
//
// Author:         Jacob Pollard & Jason Waner
// CS email:       jpollard2@wisc.edu & jwaner@wisc.edu
//
// Description:    A custom vector class with a subset
//                 of features from std::vector
//
// Sources:        cppreference.com, <sources, if any>
//
// URL(s) of sources:
//                 http://en.cppreference.com/w/cpp/container/vector
//                 <URLs of your sources, if any>
////////////////////////////////////////////////////////////////////////////////

#ifndef A6_VECTOR_HPP
#define A6_VECTOR_HPP

#include <cstdio>
#include <iostream>
#include <stdexcept>

/**
 * @brief A templated sequence container that encapsulates dynamic size arrays.
 */
template<typename T>
class Vector {
private:
    T *elems; // an array of the elements stored in the Vector
    std::size_t cap; // the current capacity of the array
    std::size_t length; // the number of elements inside the Vector
    static const std::size_t initialCapacity = 4;
    /* If you want to add methods, add them below this line */

    /* If you want to add methods, add them above this line */

public:
    /**
     * @brief Default Constructor.
     */
    Vector() {
		cap = initialCapacity;
		length = 0;
		elems = new T[cap];
    }

    /**
     * @brief Copy Constructor.
     * @param other The vector from which we should copy from.
     */
    Vector(const Vector &other) {

		cap = other.cap;
		length = other.length;
		elems = new T[cap];

		for (int i = 0; i < length; i++) {
			elems[i] = other.elems[i];
		}
    }

    /**
     * @brief Copy Assignment Operator.
     * @param other The vector on the RHS of the assignment.
     * @return A reference to the vector on the LHS.
     */
    Vector &operator=(const Vector &other) {

		//Check for self assignment?
		if (&(cap) == &(other.cap)) 
			return *this;
		
		cap = other.cap;
		length = other.length;

		//deallocate the old array and create new
		delete[] elems;
		elems = new T[cap];

		for (int i = 0; i < length; i++) {
			elems[i] = other.elems[i];
		}
		return *this;
    }

    /**
     * @brief Destructor.
     */
    ~Vector(){
		delete[] elems;
    }

    typedef T* iterator;
    typedef const T* constIterator;

    /**
     * @brief Begin iterator.
     * @return An iterator to the first element.
     */
    iterator begin() {
		return &elems[0];
	}

    /**
     * @brief End iterator.
     * @return An iterator to one past the last element.
     */
    iterator end() {
	// TODO: Implement this function.
		return &elems[length];
    }

    /**
     * @brief Const begin iterator. This is a const overloaded function.
     * @return A const iterator to the first element.
     */
    constIterator begin() const {
	// TODO: Implement this function.
		return &elems[0];
    }

    /**
     * @brief Const end iterator. This is a const overloaded function.
     * @return A const iterator to one past the last element.
     */
    constIterator end() const {
	// TODO: Implement this function.
		return &elems[length];
    }

    /**
     * @brief Gets the number of elements that the container has currently allocated space for.
     * @return The number of elements that can be held in currently allocated storage.
     */
    std::size_t capacity() const {
	// TODO: Implement this function.
		return cap;
    }

    /**
     * @brief Gets the number of elements.
     * @return The number of elements in the container.
     */
    std::size_t size() const {
		return length;
	}

    /**
     * @brief Adds an element to the end.
     *        If there is no space to add an element, then the capacity of the vector is doubled..
     * @param elem The element to be added.
     */
    void pushBack(T elem) {

		//if theres room just add to back
		if (length >= cap)
			cap = cap * 2;

		elems[length++] = elem;
    }

    /**
     * @brief Removes the last element of the container.
     *        The capacity of the vector is unchanged.
     *        If there are no elements in the container, then do nothing.
     */
    void popBack() {
	// TODO: Implement this function.
		if (length == 0)
			return;
		else {
			length--;
			return;
		}
	}

    /**
     * @brief Increases the capacity of the container to a value greater or equal to new_cap.
     *        If new_cap is greater than the current capacity(), new storage is allocated,
     *        otherwise the method does nothing.
     * @param new_cap new capacity of the container.
     */
    void reserve(std::size_t new_cap) {
		
		if (new_cap > cap)
			cap = new_cap;
    }

    /**
     * @brief Overloaded array subscripting operator.
     * @param pos The position of the element to access.
     * @return A reference to the element at specified location pos.
     *         No bounds checking is performed.
     */
    T &operator[](std::size_t pos) {
		return elems[pos];
	}

    /**
     * @brief Const overload of the overloaded array subscripting operator.
     * @param pos The position of the element to access.
     * @return A const reference to the element at specified location pos.
     *         No bounds checking is performed.
     */
    const T &operator[](std::size_t pos) const {
		return elems[pos];
	}

    /**
     * @brief Access specified element with bounds checking.
     * @param pos The position of the element to access.
     * @return A reference to the element at specified location pos, with bounds checking.
     * @throw std::out_of_range if pos >= the size of the vector.
     */
    T &at(std::size_t pos) {
	// TODO: Implement this function.
		if (pos >= length)
			throw out_of_range("ERROR");
		
		return elems[pos];
    }

    /**
     * @brief Const overload to access specified element with bounds checking.
     * @param pos The position of the element to access.
     * @return A const reference to the element at specified location pos, with bounds checking.
     * @throw std::out_of_range if pos >= the size of the vector.
     */
    const T &at(std::size_t pos) const {
	// TODO: Implement this function.
		if (pos >= length)
			throw out_of_range("ERROR");
		
		return elems[pos];
    }

    /**
     * @brief Checks whether the container is empty.
     * @return true if the container is empty, false otherwise.
     */
    bool empty() const {
		if (length == 0)
			return true;
		else
			return false;
	}

    /**
     * @brief Removes all elements from the container.
     *        Leaves the capacity of the vector unchanged.
     */
    void clear() {
		length = 0;
    }

    /**
     * @brief Erases an element at pos.
     * @param pos Iterator to the element to remove.
     * @return Iterator following the last removed element.
     *         If the iterator pos refers to the last element, the end() iterator is returned.
     */
    iterator erase(iterator pos) {
	// TODO: Implement this function.
		if (pos == &elems[length - 1]) {
			length--;
			return this->end();
		}
		
		//loop to find index to be erased
		int index = 0;
		while (index < length) {

			if (pos == &elems[index]) 
				break;

			index++;
		}

		//slide over elements left
		for (int i = index; i < length; i++) {
			elems[i] = elems[i + 1];
		}
		length--;
		return &elems[index];
    }
};

#endif //A6_VECTOR_HPP
