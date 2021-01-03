#include <iostream>

#include "linked_list/linked_list.cpp"
#include "linked_list/iterator/iterator.cpp"

using namespace Ricsi;

int main(){
  LinkedList<int> list1;
  list1 += 1;
  list1 += 2;
  list1 += 3;
  list1 += 4;
  std::cout << "list 1\n" << list1 << '\n';

  LinkedList<int> list2;
  list2 += 2;
  list2 += 3;
  list2 += 4;
  list2 += 5;
  std::cout << "list 2\n" << list2 << '\n';


  return 0;
}