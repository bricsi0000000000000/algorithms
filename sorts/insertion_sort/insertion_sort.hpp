#ifndef INSERTION_SORT_HPP
#define INSERTION_SORT_HPP

#include "../../linked_list/linked_list.hpp"

namespace Ricsi{
  template <class T>
  class InsertionSort
  {
  private:
  public:
    InsertionSort();
    ~InsertionSort();
    void sort(LinkedList<T>* list);
  };
}

#endif //INSERTION_SORT_HPP