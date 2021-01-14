#include <iostream>
#include <vector>

#include "algorithms/randomize_in_place.cpp"

int main(){
 
  int* array = new int[5];
  array[0] = 1;
  array[1] = 2;
  array[2] = 3;
  array[3] = 4;
  array[4] = 5;

  RandomizeInPlace<int> randomize_in_place;
  randomize_in_place.Randomize(array, 5);

  for (size_t i = 0; i < 5; i++) {
    std::cout << array[i] << ", ";
  }

  std::cout << '\n';
  
  delete[] array;
  
  return 0;
}
