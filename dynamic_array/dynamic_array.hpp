#ifndef DYNAMIC_ARRAY_HPP
#define DYNAMIC_ARRAY_HPP

#include "dynamic_array_iterator/dynamic_array_iterator.hpp"

namespace Ricsi{
  template <class T> class DynamicArray
  {
  private:
    T* items;
    int length;
  public:
    DynamicArray();
    ~DynamicArray();

    /**
     * @return An item at index.
    */
    T& operator [](int index);

    /**
     * Add an item to the end of the list.
     * @param item Item to add.
    */
    void operator +=(const T& item);

    /**
     * @return The size of the array.
    */
    int size();
    
    DynamicArrayIterator<T> begin();
    DynamicArrayIterator<T> end();
  };
}

#endif //DYNAMIC_ARRAY_HPP