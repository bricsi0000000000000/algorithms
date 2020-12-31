#include <iterator> // For std::forward_iterator_tag
#include <cstddef>  // For std::ptrdiff_t

#include "iterator.hpp"

using namespace Ricsi;

template <typename U> Iterator<U>::Iterator(Node<U>* ptr) : item(ptr) {}

template <typename U> U& Iterator<U>::operator*() const { 
	return item->item; 
}

template <typename U>	U* Iterator<U>::operator->() { 
	return item;
}

template <typename U>	Iterator<U>& Iterator<U>::operator++() {
	item = item->next;
	return *this;
}  

template <typename U>	Iterator<U>& Iterator<U>::operator--() {
	item = item->prev;
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