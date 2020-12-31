#ifndef LINKED_LIST_ITEM_HPP
#define LINKED_LIST_ITEM_HPP

template <typename T>
struct LinkedListItem{
    T item;
    LinkedListItem* next;
    LinkedListItem* prev;
};

#endif //LINKED_LIST_ITEM_HPP