#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>

#include "linkedListItem.hpp"
#include "position.hpp"
#include "iterator/iterator.hpp"

/**
 * @class LinkedList
 * @brief Represents a doubly linked list
*/
template <class T>
class LinkedList{
private:
  LinkedListItem<T> *head;
  LinkedListItem<T> *tail;

  /**
   * @return An item at index.
  */
  LinkedListItem<T>* get(int index);
public:

  Iterator<T> begin();
  Iterator<T> end();
  Iterator<T> rbegin();
  Iterator<T> rend();

  /**
   * Constructor for LinkedList
  */
  LinkedList();

  /**
   * Destructor for LinkedList
  */
  ~LinkedList();

  /**
   * @return Index of an item
  */
  int index(T item);

  /**
   * @return Index of an item
  */
  int operator ()(T item);

  /**
   * @return An item at index.
  */
  T operator [](int findIndex);

  /**
   * @return The length of the list.
  */
  int length();

  /**
   * @return Determines whether the item is in the list.
  */
  bool contains(T item);

  /**
   * Add an item to the front of the list.
   * @param item A **T** typed item to add to the list.
  */
  void push_front(T item);

  /**
   * Add an item to the end of the list.
   * @param item A **T** typed item to add to the list.
  */
  void push_back(T item);

  /**
   * Insert an item at specific index.
   * @param item A **T** typed item to add to the list.
   * @param index Index to put the item.
  */
  void insert(T item, int index);

  /**
   * Insert an item before or after of an item from the list.
   * @param item A **T** typed item to add to the list.
   * @param which A **T** typed item in the list.
   * @param Position Determines wheter before or after should the new item be added.
  */
  void insert(T item, T which, Position position);

  /**
   * Insert a LinkedLists items at specific index.
   * @param list A LinkedList to add to the list.
   * @param index Index to put the items. Default is 0.
  */
  void insert(LinkedList &list, int index = 0);

  /**
   * Insert a LinkedLists items before or after of an item from the list.
   * @param list A LinkedList to add to the list.
   * @param which A **T** typed item in the list.
   * @param Position Determines wheter before or after should the new items be added.
  */
  void insert(LinkedList &list, T which, Position position);

  /**
   * Add a new LinkedList to the front of this list.
   * @param Other LinkedList to add.
  */
  void push_list_front(LinkedList &list);

  /**
   * Add a new LinkedList to the end of this list.
   * @param Other LinkedList to add.
  */
  void push_list_back(LinkedList &list);

  /**
   * Removes the first item of the list, and reduces size of the list by 1.
  */
  void pop_front();

  /**
   * Removes the last item of the list, and reduces size of the list by 1 
  */
  void pop_back();

  /**
   * Removes an item from the list at specific index, and reduces size of the list by 1 
   * @param index The index where the item should be removed. Default is 0.
  */
  void pop(int index = 0);

  /**
   * Removes an item from the list, and reduces size of the list by 1 
   * @param item The item that should be removed.
  */
  void pop_item(T item);

  void pop_range_item(T fromItem, T toItem);

  void pop_range(int startIndex, int endIndex);

  void Invert();

  void Display();

  void DisplayBackwards();

};


#endif // LINKED_LIST_HPP
