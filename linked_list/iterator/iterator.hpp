#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iterator> // For std::forward_iterator_tag
#include <cstddef>  // For std::ptrdiff_t

#include "../linkedListItem.hpp"

template <typename U>
struct Iterator{
	Iterator(LinkedListItem<U>* ptr);

	U& operator*() const;

	U* operator->();

	// Prefix increment
	Iterator& operator++();
	Iterator& operator--();

	// Postfix increment
	Iterator operator++(U);
	Iterator operator--(U);

	friend bool operator== (const Iterator<U>& a, const Iterator<U>& b) {return a.m_ptr == b.m_ptr; }
	friend bool operator!= (const Iterator<U>& a, const Iterator<U>& b) {return a.m_ptr != b.m_ptr; }

private:
	LinkedListItem<U>* m_ptr;
};

#endif //ITERATOR_HPP