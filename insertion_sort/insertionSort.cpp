#include "insertionSort.hpp"

template<class T>
InsertionSort<T>::InsertionSort(){}

template<class T>
InsertionSort<T>::~InsertionSort(){}

template<class T>
void InsertionSort<T>::AddNumbers(std::vector<T> numbers){
  this->numbers.insert(this->numbers.begin(), numbers.begin(), numbers.end());
}

template<class T>
std::vector<T> InsertionSort<T>::GetNumbers() const{
  return this->numbers;
}

template<class T>
void InsertionSort<T>::WriteNumbers(){
  for(const auto& number : this->numbers){
    std::cout << number << " ";
  }
  std::cout << '\n';
}

template<class T>
void InsertionSort<T>:: Sort(){
  std::vector<T> sortedNumbers;

  for (size_t i = 0; i < this->numbers.size(); i++){
    for (size_t j = 0; j < sortedNumbers.size(); j++){
      if(this->numbers[i] < sortedNumbers[j]){
      //  sortedNumbers.insert
      }
    }
    
  }
  
}