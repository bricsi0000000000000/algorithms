#include <iostream>

#include "insertion_sort/insertionSort.cpp"
#include "linked_list/linkedList.cpp"
#include "linked_list/iterator/iterator.cpp"

int main(){
  LinkedList<int> list1;
  list1.push_back(10);
  list1.push_back(20);
  list1.push_back(30);
  list1.push_back(40);
  list1.push_back(50);
  list1.push_back(60);
  list1.push_back(70);
  list1.push_back(80);
  list1.push_back(90);

  list1.Display();

  std::cout << '\n';

  list1.pop_range_item(30, 50);

  std::cout << '\n';
  std::cout << '\n';

  list1.Display();

  /*std::cout << '\n';

  list2.AddItemToEnd(111);

  list1.Display();*/

  return 0;
}