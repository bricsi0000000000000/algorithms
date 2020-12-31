#include <iterator> // For std::forward_iterator_tag
#include <cstddef>  // For std::ptrdiff_t

#include "iterator.hpp"

template <typename U> Iterator<U>::Iterator(LinkedListItem<U>* ptr) : m_ptr(ptr) {}

template <typename U> U& Iterator<U>::operator*() const { 
	return m_ptr->item; 
}

template <typename U>	U* Iterator<U>::operator->() { 
	return m_ptr;
}

template <typename U>	Iterator<U>& Iterator<U>::operator++() {
	m_ptr = m_ptr->next;
	return *this;
}  

template <typename U>	Iterator<U>& Iterator<U>::operator--() {
	m_ptr = m_ptr->prev;
	return *this;
}  

template <typename U>	Iterator<U> Iterator<U>::operator++(U) { 
	Iterator iterator = *this; 
	++*this; 
	return iterator; 
}

template <typename U>	Iterator<U> Iterator<U>::operator--(U) { 
	Iterator iterator = *this; 
	--*this; 
	return iterator; 
}