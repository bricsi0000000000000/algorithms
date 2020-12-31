#include <sstream>

#include "linkedList.hpp"

template <class T> LinkedList<T>::LinkedList():
  head(nullptr), tail(nullptr){}

template <class T> LinkedList<T>::~LinkedList(){
  LinkedListItem<T>* current = head;
  while (current != nullptr) {
    LinkedListItem<T>* nextItem = current->next;
    delete current;
    current = nextItem;
  }
}

template <class T> int LinkedList<T>::length(){
  int length = 0;
  LinkedListItem<T>* current = head;
  while (current != nullptr) {
    ++length;
    current = current->next;
  }

  return length;
}

template <class T> LinkedListItem<T>* LinkedList<T>::get(int index){
  LinkedListItem<T>* searchedItem;

  int i = 1;
  LinkedListItem<T>* current = head;
  while (current != nullptr) {
      if(index == i){
          searchedItem = current;
      }

      ++i;
      current = current->next;
  }

  return searchedItem;
}

template <class T> int LinkedList<T>::index(T item){
  int index = 0;
  LinkedListItem<T>* current = head;
  while (current != nullptr) {
    if(item == current->item){
      return index;
    }

    ++index;
    current = current->next;
  }

  return -1;
}

template <class T> int LinkedList<T>::operator ()(T item){
  int index = 0;
  LinkedListItem<T>* current = head;
  while (current != nullptr) {
    if(item == current->item){
      return index;
    }

    ++index;
    current = current->next;
  }

  return -1;
}

template <class T> T LinkedList<T>::operator [](int findIndex){
  LinkedListItem<T>* searchItem;

  int index = 0;
  LinkedListItem<T>* current = head;
  while (current != nullptr) {
    if(findIndex == index){
      searchItem = current;
    }

    ++index;
    current = current->next;
  }

  return searchItem->item;
}

template <class T> bool LinkedList<T>::contains(T item){
  LinkedListItem<T>* current = head;
  while (current != nullptr) {
    if(item == current->item){
      return item == current->item;
    }

    current = current->next;
  }

  return false;
}

template <class T> void LinkedList<T>::push_front(T item){
  LinkedListItem<T>* newItem = new LinkedListItem<T>{item, nullptr, nullptr};

  if(head == nullptr){
    head = newItem;
    tail = newItem;
  }
  else{
    newItem->next = head;
    head->prev = newItem;
    newItem->prev = nullptr;
    head = newItem;
  }
}

template <class T> void LinkedList<T>::push_back(T item){
  LinkedListItem<T>* newItem = new LinkedListItem<T>{item, nullptr, nullptr};

  if(head == nullptr){
    head = newItem;
    tail = newItem;
  }
  else {
    tail->next = newItem;
    newItem->prev = tail;
    newItem->next = nullptr;
    tail = newItem;
  }
}

template <class T> void LinkedList<T>::insert(T item, int index){
  if(index < 0){
    std::stringstream errorMessage;
    errorMessage << "The index(" << index << ") is smaller than zero";
    throw std::runtime_error(errorMessage.str());
  }
  else if(index == 0){
    push_front(item);
  }
  else if(index == length()){
    push_back(item);
  }
  else if(index > length()){
    std::stringstream errorMessage;
    errorMessage << "The index(" << index << ") is bigger than list length(" << length() << ")";
    throw std::runtime_error(errorMessage.str());
  }
  else{
    int i = 0;
    LinkedListItem<T>* current = head;
    while (current != nullptr && (index != i)) {
      if(index == i + 1){
        LinkedListItem<T>* newItem = new LinkedListItem<T>{item, nullptr, nullptr};
        LinkedListItem<T>* currentNext = current->next;
        newItem->next = currentNext;
        current->next= newItem;

        newItem->prev = current;
        currentNext->prev = newItem;
      }
      i++;
      current = current->next;
    }
  }
}

template <class T> void LinkedList<T>::insert(T item, T which, Position position){
  if(contains(which)){
    LinkedListItem<T>* current = head;

    int index = 0;
    while (current != nullptr) {
      if(current->item == which){
        switch (position) {
          case Before:
              insert(item, index);
          break;
          case After:
              insert(item, index + 1);
          break;
        }
      }
      ++index;
      current = current->next;
    }
  }
  else{
    throw std::runtime_error("The item is not in the list!");
  }
}

template <class T> void LinkedList<T>::insert(LinkedList &list, int index){
  if(index < 0){
    std::stringstream errorMessage;
    errorMessage << "The index(" << index << ") is smaller than zero";
    throw std::runtime_error(errorMessage.str());
  }
  else if(index > length()){
    std::stringstream errorMessage;
    errorMessage << "The index(" << index << ") is bigger than list length(" << length() << ")";
    throw std::runtime_error(errorMessage.str());
  }
  else{
    int i = index;
    for(auto item : list){
      insert(item, i);
      i++;
    }
  }
}

template <class T> void LinkedList<T>::insert(LinkedList &list, T which, Position position){
  if(contains(which)){
    LinkedListItem<T>* current = head;

    int index = 0;
    while (current != nullptr) {
      if(current->item == which){
        switch (position) {
          case Before:
            insert(list, index);
          break;
          case After:
            insert(list, index + 1);
          break;
        }
      }
      ++index;
      current = current->next;
    }
  }
  else{
    throw std::runtime_error("The item is not in the list!");
  }
}

template <class T> void LinkedList<T>::push_list_front(LinkedList &list){
  for(auto item : list){
    push_front(item);
  }
}

template <class T> void LinkedList<T>::push_list_back(LinkedList &list){
   for(auto item : list){
    push_back(item);
  }
}

template <class T> void LinkedList<T>::pop_front(){
  if(length() == 0){
    throw std::runtime_error("The list is empty");
  }
  else{
    LinkedListItem<T>* headNext = head->next;
    delete head;
    head = headNext;
    headNext->prev = nullptr;
  }
}

template <class T> void LinkedList<T>::pop_back(){
  if(length() == 0){
    throw std::runtime_error("The list is empty");
  }
  else if(length() == 1){
    pop_front();
  }
  else if(length() > 1){
    LinkedListItem<T>* current = head;
    while (current->next->next != nullptr) {
      current = current->next;
    }
    current->next = nullptr;
    delete tail;
    tail = current;
  }
}

template <class T> void LinkedList<T>::pop(int index){
  if(index < 0){
    std::stringstream errorMessage;
    errorMessage << "The index(" << index << ") is smaller than zero";
    throw std::runtime_error(errorMessage.str());
  }
  else if(index >= length()){
    std::stringstream errorMessage;
    errorMessage << "The index(" << index << ") is bigger than list length(" << length() << ")";
    throw std::runtime_error(errorMessage.str());
  }
  else if(index == 0){
    pop_front();
  }
  else if(index == length()){
    pop_back();
  }
  else {
    int i = 0;
    LinkedListItem<T>* current = head;
    while (current != nullptr) {
      if(index == i + 1){
        LinkedListItem<T>* currentNextNext = current->next->next;
        delete current->next;
        current->next = currentNextNext;
        currentNextNext->prev = current;
      }
      ++i;
      current = current->next;
    }
  }
}

template <class T> void LinkedList<T>::pop_item(T item){
  if(contains(item)){
    if(item == head->item){
      pop_front();
    }
    else if(item == tail->item){
      pop_back();
    }
    else{
      pop(index(item));
    }
  }
  else{
    throw std::runtime_error("The item is not in the list!");
  }
}

template <class T> void LinkedList<T>::pop_range_item(T fromItem, T toItem){
  if(contains(fromItem) && contains(toItem)){
    if(index(fromItem) < index(toItem)){
      LinkedListItem<T>* current = head;
      LinkedListItem<T>* startItem;
      LinkedListItem<T>* endItem;

      current = head;
      while (current != nullptr) {
        if(current->item == fromItem){
          startItem = current;
        }
        if(current->item == toItem){
          endItem = current;
        }
        current = current->next;
      }

      startItem->next = endItem;
      endItem->prev = startItem;
    }
    else if(fromItem == toItem){
      std::cout << "The 'start' and 'end' elements are the same!\n";
    }
    else{
      std::cout << "The 'start' item is after the 'end' item!\n";
    }
  }
  else if(!contains(fromItem) && !contains(toItem)){
    std::cout << "None of the two elements are in the list!\n";
  }
  else if(!contains(fromItem)){
    std::cout << "The 'start' item is not in the list!\n";
  }
  else if(!contains(toItem)){
    std::cout << "The 'end' item is not in the list!\n";
  }
}

template <class T>
void LinkedList<T>::pop_range(int startIndex, int endIndex){
  if(startIndex <= 0){
    std::cout << "The start index(" << startIndex << ") is less than or equal to zero!\n";
  }
  else if(endIndex > length()){
    std::cout << "The end index(" << endIndex << ") is bigger than the length(" << length() << ") of the list!\n";
  }
  else if(startIndex > endIndex){
    std::cout << "The start index(" << startIndex << ") is bigger than the end index(" << endIndex << ")\n";
  }
  else if(startIndex == endIndex){
    std::cout << "The start index(" << startIndex << ") is equal to the end index(" << endIndex << ")\n";
  }
  else{
    LinkedListItem<T>* startItem = get(startIndex);
    LinkedListItem<T>* endItem = get(endIndex);

    startItem->next = endItem;
    endItem->prev = startItem;
  }
}

template <class T>
void LinkedList<T>::Invert(){
  LinkedListItem<T>* current = head;
  while (current != nullptr) {
    if(current != head){
      pop(current->item);
      push_front(current->item);
    }
    current = current->next;
  }
}

template <class T>
void LinkedList<T>::Display(){
  if(length() == 0){
    std::cout << "The list is empty\n";
  }
  else{
    LinkedListItem<T>* current = head;
    while (current != nullptr) {
      std::cout << current->item << "\n";
      current = current->next;
    }
  }
}

template <class T>
void LinkedList<T>::DisplayBackwards(){
  if(length() == 0){
    std::cout << "The list is empty\n";
  }
  else{
    LinkedListItem<T>* current = tail;
    while (current != nullptr) {
      std::cout << current->item << "\n";
      current = current->prev;
    }
  }
}

template <class T> Iterator<T> LinkedList<T>::begin() {
  return Iterator<T>(head); 
}

template <class T> Iterator<T> LinkedList<T>::end() {
  return Iterator<T>(tail->next); 
}

template <class T> Iterator<T> LinkedList<T>::rbegin() {
  return Iterator<T>(head->prev); 
}

template <class T> Iterator<T> LinkedList<T>::rend() {
  return Iterator<T>(tail); 
}
