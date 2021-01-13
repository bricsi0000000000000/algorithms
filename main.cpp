#include <iostream>

#include "algorithms/sorting_algorithms/insertion_sort.cpp"
#include "algorithms/searching_algorithms/binary_search.cpp"

int main(){
  int length = 5;
  int* array = new int[length];
  array[0] = 6;
  array[1] = 3;
  array[2] = 5;
  array[3] = 1;
  array[4] = 9;

  InsertionSort<int> insertion_sort;
  insertion_sort.Sort(array, length);

  BinarySearch<int> binary_search;
  std::cout << binary_search.Search(array, 5, 0, length) << '\n';
  
  delete[] array;

  return 0;
}