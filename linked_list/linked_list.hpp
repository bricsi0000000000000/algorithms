#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>
#include <time.h>

#include "node.hpp"
#include "position.hpp"
#include "iterator/iterator.hpp"

namespace Ricsi{
  /**
   * @class LinkedList
   * @brief Represents a doubly linked list
  */
  template <class T>
  class LinkedList{
  private:
    /**
     * First item in list.
    */
    Node<T> *head;

    /**
     * Last item in list.
    */
    Node<T> *tail;

    /**
     * @return An item at index.
    */
    Node<T>* get(int index);

    /**
     * Start of merge sort.
     * `sort_merge` calls it with `head`.
     * @param head_ref `head` node.
    */
    void merge_sort(Node<T>** head_ref);

    /**
     * Split the nodes of the given list into front and back halves,  
     * and return the two lists using the reference parameters.  
     * If the length is odd, the extra node should go in the front list.  
     * Uses the fast/slow pointer strategy.
    */
    void front_back_split(Node<T>* source, Node<T>** front, Node<T>** back);

    /**
     * Merges front and back
    */
    Node<T>* sorted_merge(Node<T>* front, Node<T>* back);


  public:
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
    T operator [](int index);

    /**
     * Add an item to the end of the list.
     * @param item Item to add.
    */
    void operator +=(const T& item);

    /**
     * Adds the parameter list to the end of this list.
    */
    void operator +=(LinkedList<T>& list);

    /**
     * Removes all instances of an item from the list.
     * @param item Item to remove.
    */
    void operator -=(const T& item);

    /**
     * Removes the parameter lists items from this list.
    */
    void operator -=(LinkedList<T>& list);

    /**
     * Removes the last element from list.
    */
    void operator --(int);

    /**
     * Removes the first element from list.
    */
    void operator --();

    /**
     * Put this list equals to the parameter list.
    */
    void operator =(LinkedList<T>& list);

    /**
     * Check if this lists all item is equals to the parameter list.
    */
    bool operator ==(LinkedList<T> &list);

    /**
     * Check if this lists all item isn't equals to the parameter list.
    */
    bool operator !=(LinkedList<T> &list);

    /**
     * Check if this lists length is smaller than parameter lists length.
    */
    bool operator <(LinkedList<T> &list);

    /**
     * Check if this lists length is bigger than parameter lists length.
    */
    bool operator >(LinkedList<T> &list);

    /**
     * Check if this lists length is smaller or equals to parameter lists length.
    */
    bool operator <=(LinkedList<T> &list);

    /**
     * Check if this lists length is bigger or equals to parameter lists length.
    */
    bool operator >=(LinkedList<T> &list);

    /**
     * Adds parameters lists items to this list.
    */
    LinkedList<T>& operator+(LinkedList<T>& list);

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
     * Removes the last item of the list
    */
    void pop_back();

    /**
     * Removes an item from the list at specific index
     * @param index The index where the item should be removed. Default is 0.
    */
    void pop(int index = 0);

    /**
     * Removes all instance of item from the list.
     * @param item The item that should be removed.
    */
    void pop_item(T item);

    /**
     * Removes items from the list from from_item to until_item
     * @param from_item Item from where delete items.
     * @param until_item Item until delete items.
    */
    void pop_range_item(T from_item, T until_item);

    /**
     * Removes items from the list from start_index to end_index
     * @param start_index Index from delete items.
     * @param end_index Index until delete items.
    */
    void pop_range(int start_index, int end_index);

    /**
     * Invert the list.
    */
    void invert();

    /**
     * Go through the list and displays all items.
    */
    void display();

    /**
     * Go through the list backwards and displays all items.
    */
    void display_backwards();

    /**
     * Swap two items.
     * @param index1 items index to swap.
     * @param index2 items index to swap.
    */
    void swap(int index1, int index2);

    /**
     * Swap two items.
     * @param node1 First node to swap.
     * @param node2 Seconds node to swap.
    */
    void swap(Node<T> *node1, Node<T> *node2);

    /**
     * Clears the list.
    */
    void clear();

    /**
     * Fill up the list with integers from **from** until **to**.
     * @param from A number from fill up the list.
     * @param to A number until fill up the list.
    */
    void fill(int from, int to);

    /**
     * Fill up the list with integers from **from** until **to** in reversed order.
     * @param from A number from fill up the list.
     * @param to A number until fill up the list.
    */
    void fill_reverse(int from, int to);

    /**
     * Fill up the list with random integers from **from** until **to**.
     * @param from The random numbers minimum value.
     * @param to The random numbers maximum value.
     * @param size Number of random numbers to add to the list.
    */
    void fill_random(int from, int to, int size);

    /**
     * Sorts the list using insertion sort.
     * @brief Time complexity: `O(n*2)`
    */
    void sort_insertion();

    /**
     * Sorts the list using merge sort.
     * @brief Time complexity: `O(n)`
    */
    void sort_merge();

    /**
     * Sorts the list using selection sort.
     * @brief Time complexity: `O(n^2)`
    */
    void sort_selection();

    /**
     * Sorts the list using bubble sort.
     * @brief Time complexity: `O(n^2)`
    */
    void sort_bubble();

    Iterator<T> begin();
    Iterator<T> end();
    Iterator<T> rbegin();
    Iterator<T> rend();

    template<class U> friend std::ostream& operator<< (std::ostream& stream, const LinkedList<U>& list);
  };

  template<class T> std::ostream& operator<< (std::ostream& stream, const LinkedList<T>& list){
    Node<T>* current = list.head;
    while (current != nullptr) {
      stream << current->item << ", ";
      current = current->next;
    }
    stream << '\n';

    return stream;
  }
}


#endif // LINKED_LIST_HPP
