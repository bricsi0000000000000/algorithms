#include <sstream>

#include "array.hpp"

using namespace Ricsi;

template <class T> Array<T>::Array(size_t length){
  items = new T(length);
  this->length = length;
}

template <class T> Array<T>::~Array(){
  delete[] items;
}

template <class T> T& Array<T>::operator [](int index) {
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



template <class T> size_t Array<T>::size(){
  return this->length;
}