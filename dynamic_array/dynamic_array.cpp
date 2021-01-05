#include <sstream>

#include "dynamic_array.hpp"

using namespace Ricsi;

template <class T> DynamicArray<T>::DynamicArray(){
  this->length = 0;
  items = new T(length);
}
template <class T> DynamicArray<T>::~DynamicArray(){
  delete[] items;
}

template <class T> T& DynamicArray<T>::operator [](int index) {
  if(index < 0){
    std::stringstream errorMessage;
    errorMessage << "The index(" << index << ") is smaller than zero";
    throw std::runtime_error(errorMessage.str());
  }
  else if(index >= length){
    std::stringstream errorMessage;
    errorMessage << "The index(" << index << ") is larger than the size of the array(" << length << ")";
    throw std::runtime_error(errorMessage.str());
  }

  return items[index];
}

template <class T> void DynamicArray<T>::operator+=(const T& item){
  T* new_items = new T(length + 1);
  for (size_t i = 0; i < length; i++) {
    new_items[i] = items[i];
  }

  new_items[length] = item;
  length++;

  delete[] items;
  items = new_items;
}

template <class T> int DynamicArray<T>::size(){
  return this->length;
}

template <class T> DynamicArrayIterator<T> DynamicArray<T>::begin() {
  return DynamicArrayIterator<T>(&items[0]); 
}

template <class T> DynamicArrayIterator<T> DynamicArray<T>::end() {
  return DynamicArrayIterator<T>(&items[length]); 
}
