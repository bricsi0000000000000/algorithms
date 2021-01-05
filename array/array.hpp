#ifndef ARRAY_HPP
#define ARRAY_HPP

namespace Ricsi{
  template <class T>
  class Array
  {
  private:
    T* items;
    size_t length;
  public:
    Array(size_t length);
    ~Array();

    /**
     * @return An item at index.
    */
    T& operator [](int index);


    /**
     * @return The size of the array.
    */
    size_t size();
  };
}

#endif //ARRAY_HPP