#include "dynamic_array_iterator.hpp"

using namespace Ricsi;

template <typename U> DynamicArrayIterator<U>::DynamicArrayIterator(U* ptr) : item(ptr) {}

template <typename U> U& DynamicArrayIterator<U>::operator*() const { 
	return *item; 
}

template <typename U>	U* DynamicArrayIterator<U>::operator->() { 
	return item;
}

template <typename U>	DynamicArrayIterator<U>& DynamicArrayIterator<U>::operator++() {
	item++; 
  return *this;
}  

template <typename U>	DynamicArrayIterator<U>& DynamicArrayIterator<U>::operator--() { 
  DynamicArrayIterator tmp = *this;
  ++(*this); return tmp;
}

template <typename U>	DynamicArrayIterator<U> DynamicArrayIterator<U>::operator++(U) { 
	DynamicArrayIterator iterator = *this; 
	++*this; 
	return iterator; 
}

template <typename U>	DynamicArrayIterator<U> DynamicArrayIterator<U>::operator--(U) { 
	DynamicArrayIterator iterator = *this; 
	--*this; 
	return iterator; 
}