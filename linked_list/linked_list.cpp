#include <sstream>

#include "linked_list.hpp"

using namespace Ricsi;

template <class T> LinkedList<T>::LinkedList():
  head(nullptr), tail(nullptr) 
  {
    srand(time(NULL)); 
  }

template <class T> LinkedList<T>::~LinkedList() {
  Node<T>* current = head;
  while (current != nullptr) {
    Node<T>* nextItem = current->next;
    delete current;
    current = nextItem;
  }
}

template <class T> int LinkedList<T>::length() {
  int length = 0;
  if(head == nullptr){
    return length;
  }

  Node<T>* current = head;
  while (current != nullptr) {
    length++;
    current = current->next;
  }

  return --length;
}

template <class T> Node<T>* LinkedList<T>::get(int index) {
  Node<T>* searchedItem;

  int i = 0;
  Node<T>* current = head;
  while (current != nullptr) {
      if(index == i) {
          searchedItem = current;
      }

      ++i;
      current = current->next;
  }

  return searchedItem;
}

template <class T> int LinkedList<T>::index(T item) {
  int index = 0;
  Node<T>* current = head;
  while (current != nullptr) {
    if(item == current->item) {
      return index;
    }

    ++index;
    current = current->next;
  }

  return -1;
}

template <class T> int LinkedList<T>::operator ()(T item) {
  int index = 0;
  Node<T>* current = head;
  while (current != nullptr) {
    if(item == current->item) {
      return index;
    }

    ++index;
    current = current->next;
  }

  return -1;
}

template <class T> T LinkedList<T>::operator [](int index) {
  Node<T>* searchItem;

  int i = 0;
  Node<T>* current = head;
  while (current != nullptr) {
    if(index == i) {
      searchItem = current;
    }

    ++i;
    current = current->next;
  }

  return searchItem->item;
}

template <class T> void LinkedList<T>::operator+=(const T& item){
  push_back(item);
}

template <class T> void LinkedList<T>::operator+=(LinkedList<T>& list){
  push_list_back(list);
}

template <class T> void LinkedList<T>::operator-=(const T& item){
  pop_item(item);
}

template <class T> void LinkedList<T>::operator-=(LinkedList<T>& list){
  for(auto item : list){
    try {
      pop_item(item);
    }
    catch(const std::exception& e) {}
  }
}

template <class T> void LinkedList<T>::operator--(int){
  pop_back();
}

template <class T> void LinkedList<T>::operator--(){
  pop_front();
}

template <class T> void LinkedList<T>::operator= (LinkedList<T>& list){
  clear();

  for(T item : list){
    push_back(item);
  }
}

template <class T> bool LinkedList<T>::operator ==(LinkedList<T>& list){
  if(length() != list.length()){
    return false;
  }
  else{
    for (int i = 0; i <= length(); i++) {
      if(get(i)->item != list[i]){
        return false;
      }
    }
  }

  return true;
}

template <class T> bool LinkedList<T>::operator !=(LinkedList<T>& list){
  if(length() == list.length()){
    return true;
  }
  else{
    for (int i = 0; i <= length(); i++) {
      if(get(i)->item == list[i]){
        return true;
      }
    }
  }

  return false;
}

template <class T> bool LinkedList<T>::operator <(LinkedList<T>& list){
  return length() < list.length();
}

template <class T> bool LinkedList<T>::operator >(LinkedList<T>& list){
  return length() > list.length();
}

template <class T> bool LinkedList<T>::operator <=(LinkedList<T>& list){
  return length() <= list.length();
}

template <class T> bool LinkedList<T>::operator >=(LinkedList<T>& list){
  return length() >= list.length();
}

template <class T> LinkedList<T>& LinkedList<T>::operator +(LinkedList<T>& list){
  Node<T>* current = tail;
  while (current != nullptr) {
    list.push_front(current->item);
    current = current->prev;
  }

  return list;
}

template <class T> bool LinkedList<T>::contains(T item) {
  Node<T>* current = head;
  while (current != nullptr) {
    if(item == current->item) {
      return item == current->item;
    }

    current = current->next;
  }

  return false;
}

template <class T> void LinkedList<T>::push_front(T item) {
  Node<T>* newItem = new Node<T>{item, nullptr, nullptr};

  if(head == nullptr) {
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

template <class T> void LinkedList<T>::push_back(T item) {
  Node<T>* newItem = new Node<T>{item, nullptr, nullptr};

  if(head == nullptr) {
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

template <class T> void LinkedList<T>::insert(T item, int index) {
  if(index < 0) {
    std::stringstream errorMessage;
    errorMessage << "The index(" << index << ") is smaller than zero";
    throw std::runtime_error(errorMessage.str());
  }
  else if(index == 0) {
    push_front(item);
  }
  else if(index == length()) {
    push_back(item);
  }
  else if(index > length()) {
    std::stringstream errorMessage;
    errorMessage << "The index(" << index << ") is bigger than list length(" << length() << ")";
    throw std::runtime_error(errorMessage.str());
  }
  else{
    int i = 0;
    Node<T>* current = head;
    while (current != nullptr && (index != i)) {
      if(index == i + 1) {
        Node<T>* newItem = new Node<T>{item, nullptr, nullptr};
        Node<T>* currentNext = current->next;
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

template <class T> void LinkedList<T>::insert(T item, T which, Position position) {
  if(contains(which)) {
    Node<T>* current = head;

    int index = 0;
    while (current != nullptr) {
      if(current->item == which) {
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

template <class T> void LinkedList<T>::insert(LinkedList &list, int index) {
  if(index < 0) {
    std::stringstream errorMessage;
    errorMessage << "The index(" << index << ") is smaller than zero";
    throw std::runtime_error(errorMessage.str());
  }
  else if(index > length()) {
    std::stringstream errorMessage;
    errorMessage << "The index(" << index << ") is bigger than list length(" << length() << ")";
    throw std::runtime_error(errorMessage.str());
  }
  else{
    int i = index;
    for(auto item : list) {
      insert(item, i);
      i++;
    }
  }
}

template <class T> void LinkedList<T>::insert(LinkedList &list, T which, Position position) {
  if(contains(which)) {
    Node<T>* current = head;

    int index = 0;
    while (current != nullptr) {
      if(current->item == which) {
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

template <class T> void LinkedList<T>::push_list_front(LinkedList &list) {
  for(auto item : list) {
    push_front(item);
  }
}

template <class T> void LinkedList<T>::push_list_back(LinkedList &list) {
   for(auto item : list) {
    push_back(item);
  }
}

template <class T> void LinkedList<T>::pop_front() {
  if(length() == 0) {
    throw std::runtime_error("The list is empty");
  }
  else{
    Node<T>* headNext = head->next;
    delete head;
    head = headNext;
    headNext->prev = nullptr;
  }
}

template <class T> void LinkedList<T>::pop_back() {
  if(length() == 0) {
    throw std::runtime_error("The list is empty");
  }
  else if(length() == 1) {
    pop_front();
  }
  else if(length() > 1) {
    Node<T>* current = head;
    while (current->next->next != nullptr) {
      current = current->next;
    }
    current->next = nullptr;
    delete tail;
    tail = current;
  }
}

template <class T> void LinkedList<T>::pop(int index) {
  if(index < 0) {
    std::stringstream errorMessage;
    errorMessage << "The index(" << index << ") is smaller than zero";
    throw std::runtime_error(errorMessage.str());
  }
  else if(index > length()) {
    std::stringstream errorMessage;
    errorMessage << "The index(" << index << ") is bigger than list length(" << length() << ")";
    throw std::runtime_error(errorMessage.str());
  }
  else if(index == 0) {
    pop_front();
  }
  else if(index == length()) {
    pop_back();
  }
  else {
    int i = 0;
    Node<T>* current = head;
    while (current != nullptr) {
      if(index == i + 1) {
        Node<T>* currentNextNext = current->next->next;
        delete current->next;
        current->next = currentNextNext;
        currentNextNext->prev = current;
      }
      ++i;
      current = current->next;
    }
  }
}

template <class T> void LinkedList<T>::pop_item(T item) {
  if(contains(item)) {
    while(contains(item)) {
      if(item == head->item) {
        pop_front();
      }
      else if(item == tail->item) {
        pop_back();
      }
      else{
        pop(index(item));
      }
    }
  }
  else{
    std::stringstream errorMessage;
    errorMessage << "The item(" << item << ") is not in the list";
    throw std::runtime_error(errorMessage.str());
  }
}

template <class T> void LinkedList<T>::pop_range_item(T from_item, T until_item) {
  if(!contains(from_item)) {
    std::stringstream errorMessage;
    errorMessage << "The from item(" << from_item << ") is not found";
    throw std::runtime_error(errorMessage.str());
  }
  else if(!contains(until_item)) {
    std::stringstream errorMessage;
    errorMessage << "The until item(" << until_item << ") is not found";
    throw std::runtime_error(errorMessage.str());
  }
  else if(!contains(from_item) && !contains(until_item)) {
    std::stringstream errorMessage;
    errorMessage << "The from item(" << from_item << ") and the until item(" << until_item << ") are not found";
    throw std::runtime_error(errorMessage.str());
  }
  else{
    int start_index = index(from_item);
    int end_index = index(until_item);

    if(start_index == end_index) {
      std::stringstream errorMessage;
      errorMessage << "The from item(" << from_item << ") is equals to the until item(" << until_item << ")";
      throw std::runtime_error(errorMessage.str());
    }
    else if(start_index > end_index) {
      std::stringstream errorMessage;
      errorMessage << "The from item(" << from_item << ") is backwards from the until item(" << until_item << ")";
      throw std::runtime_error(errorMessage.str());
    }
    else{
      pop_range(start_index, end_index);
    }
  }
}

template <class T> void LinkedList<T>::pop_range(int start_index, int end_index) {
  if(start_index == end_index) {
    std::stringstream errorMessage;
    errorMessage << "The start index(" << start_index << ") is equals to end index(" << end_index << ")";
    throw std::runtime_error(errorMessage.str());
  }
  else if(start_index > end_index) {
    std::stringstream errorMessage;
    errorMessage << "The start index(" << start_index << ") is bigger than end index(" << end_index << ")";
    throw std::runtime_error(errorMessage.str());
  }
  else{
    if(start_index < 0) {
      std::stringstream errorMessage;
      errorMessage << "The start index(" << start_index << ") is smaller than zero";
      throw std::runtime_error(errorMessage.str());
    }
    else if(end_index > length()) {
      std::stringstream errorMessage;
      errorMessage << "The end index(" << end_index << ") is bigger than list length(" << length() << ")";
      throw std::runtime_error(errorMessage.str());
    }
    else{
      bool end_index_is_length = end_index == length();
      if(end_index_is_length) {
        end_index--;
      }

      for (int i = start_index; i < end_index; i++) {
        pop(start_index);
      }

      if(end_index_is_length) {
        pop_back();
      }
    }
  }
}

template <class T> void LinkedList<T>::invert() {
  Node<T>* current = head->next;
  while (current != nullptr) {
    Node<T> add = *current;
    current = current->next;
    if(current != nullptr) {
      pop_item(add.item);
    }
    else{
      pop_back();
    }

    push_front(add.item);
  }
}

template <class T> void LinkedList<T>::display() {
  if(length() > 0) {
    Node<T>* current = head;
    while (current != nullptr) {
      std::cout << current->item << ", ";
      current = current->next;
    }
  }

  std::cout << '\n';
}

template <class T> void LinkedList<T>::display_backwards() {
  if(length() > 0) {
    Node<T>* current = tail;
    while (current != nullptr) {
      std::cout << current->item << ", ";
      current = current->prev;
    }
  }

  std::cout << '\n';
}

template <class T> void LinkedList<T>::swap(int index1, int index2) {
  if(index1 == index2) {
    return;
  }
  else{
    if(index1 < 0) {
      std::stringstream errorMessage;
      errorMessage << "The first index(" << index1 << ") is smaller than zero";
      throw std::runtime_error(errorMessage.str());
    }
    else if(index2 < 0) {
      std::stringstream errorMessage;
      errorMessage << "The second index(" << index2 << ") is smaller than zero";
      throw std::runtime_error(errorMessage.str());
    }
    else if(index2 > length()) {
      std::stringstream errorMessage;
      errorMessage << "The second index(" << index2 << ") is bigger than list length(" << length() << ")";
      throw std::runtime_error(errorMessage.str());
    }
    else if(index1 > length()) {
      std::stringstream errorMessage;
      errorMessage << "The first index(" << index1 << ") is bigger than list length(" << length() << ")";
      throw std::runtime_error(errorMessage.str());
    }
    else{
      T item1 = get(index1)->item;
      T item2 = get(index2)->item;
      pop(index1);
      if(index1 > length()) {
        push_back(item2);
      }
      else {
        insert(item2, index1);
      }

      pop(index2);
      if(index2 > length()) {
        push_back(item1);
      }
      else {
        insert(item1, index2);
      }
    }
  }
}

template <class T> void LinkedList<T>::swap(Node<T> *node1, Node<T> *node2) 
{ 
    T temp = node1->item; 
    node1->item = node2->item; 
    node2->item = temp; 
} 

template <class T> void LinkedList<T>::clear(){
  Node<T>* current = head;
  while (current != nullptr) {
    Node<T>* nextItem = current->next;
    delete current;
    current = nextItem;
  }

  head = nullptr;
  tail = nullptr;
}

template <class T> void LinkedList<T>::fill(int from, int to) {
  for (int i = from; i <= to; i++) {
    push_back(i);
  }
}

template <class T> void LinkedList<T>::fill_reverse(int from, int to) {
  for (int i = from; i <= to; i++) {
    push_front(i);
  }
}

template <class T> void LinkedList<T>::fill_random(int min, int max, int size) {

  if(length() > 0){
    clear();
  }

  for (int i = 0; i < size; i++) {
    push_back(rand() % (max - min + 1) + min);
  }
}

template <class T> void LinkedList<T>::sort_insertion() {
  LinkedList<T> sorted_list;
  sorted_list.push_back(head->item);

  Node<T>* current_j = head->next;
  while (current_j != nullptr) {
    bool add = false;
    for (int i = 0; i < sorted_list.length() && !add; i++) {
      if(current_j->item < sorted_list[i]){
        add = true;
        sorted_list.insert(current_j->item, i);
      }
    }

    if(!add){
      sorted_list.push_back(current_j->item);
    }

    current_j = current_j->next;
  }

  clear();

  for(auto item : sorted_list){
    push_back(item);
  }
}

template <class T> void LinkedList<T>::sort_merge() {
  merge_sort(&head);
}

template <class T> void LinkedList<T>::merge_sort(Node<T>** head_ref) {
  Node<T>* source = *head_ref;
  Node<T>* front;
  Node<T>* back;

  if((source == nullptr) || (source->next == nullptr)){
    return;
  }

  front_back_split(source, &front, &back);

  merge_sort(&front);
  merge_sort(&back);

  *head_ref = sorted_merge(front, back);
}

template <class T> Node<T>* LinkedList<T>::sorted_merge(Node<T>* front, Node<T>* back){
  Node<T>* result = nullptr;

  if(front == nullptr){
    return back;
  }
  else if(back == nullptr){
    return front;
  }

  if(front->item <= back->item){
    result = front;
    result->next = sorted_merge(front->next, back);
  }
  else {
    result = back;
    result->next = sorted_merge(front, back->next);
  }

  return result;
}

template <class T> void LinkedList<T>::front_back_split(Node<T>* source, Node<T>** front, Node<T>** back) {
  Node<T>* fast;
  Node<T>* slow;
  slow = source;
  fast = source->next;

  while (fast != nullptr){
    fast = fast->next;
    if(fast != nullptr){
      slow = slow->next;
      fast = fast->next;
    }
  }

  *front = source;
  *back = slow->next;
  slow->next = nullptr;
}

template <class T> void LinkedList<T>::sort_selection(){
  Node<T>* current_i = head;
  while(current_i != nullptr){
    Node<T>* min = current_i;
    Node<T>* current_j = current_i->next;

    while(current_j != nullptr){
      if(current_j->item < min->item){
        min = current_j;
      }
      current_j = current_j->next;
    }

    T temp = current_i->item;
    current_i->item = min->item;
    min->item = temp;

    current_i = current_i->next;
  }
}

template <class T> void LinkedList<T>::sort_bubble(){
  if(length() == 0){
    return;
  }
  bool swapped = false;
  Node<T>* current_j = nullptr;

  do {
    swapped = false;

    Node<T>* current_i = head;
    while (current_i->next != current_j){
      if(current_i->item > current_i->next->item){
        swap(current_i, current_i->next);
        swapped = true;
      }
      current_i = current_i->next;
    }
    current_j = current_i;
  } while (swapped);
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
