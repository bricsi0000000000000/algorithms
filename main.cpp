#include <iostream>

#include "linked_list/linked_list.cpp"
#include "linked_list/iterator/iterator.cpp"
#include "sorts/insertion_sort/insertion_sort.cpp"

using namespace Ricsi;

int main(){
  LinkedList<int> list1;
 /* list1.push_back(10);
  list1.push_back(70);
  list1.push_back(40);
  list1.push_back(50);
  list1.push_back(30);
  list1.push_back(20);
  list1.push_back(60);
  list1.push_back(80);
  list1.push_back(90);*/
  list1.fill_random(1, 100, 10);

  list1.display();

  list1.sort_insertion();

  list1.display();

  //list1.sort_insertion();
  //list1.display();

  //std::cout << std::endl;

 /* list1.display();
  list1.display();*/

/*  int array[11];
  array[0] = 4;
  array[1] = 7;
  array[2] = 8;
  array[3] = 6;
  array[4] = 4;
  array[5] = 6;
  array[6] = 7;
  array[7] = 3;
  array[8] = 10;
  array[9] = 2;
  array[10] = 3;

  for (size_t j = 1; j < 11; j++)
  {
    int key = array[j];
    int i = j - 1;
    while (i >= 0 && array[i] > key)
    {
      array[i + 1] = array[i];
      i--;
    }
    array[i + 1] = key;
  }

  for(auto a : array){
    std::cout << a << std::endl;
  }
 */

  return 0;
}