#ifndef LINKED_LIST_ITEM_HPP
#define LINKED_LIST_ITEM_HPP

namespace Ricsi{
  /**
   * @struct Node
   * @brief Represents an item for LinkedList.
  */
  template <typename T>
  struct Node{
    /**
     * An item to store in each Node.
    */
    T item;

    /**
     * Next node in list.
    */
    Node* next;

    /**
     * Previous node in list.
    */
    Node* prev;
  };
}

#endif //LINKED_LIST_ITEM_HPP