template <class T> class RandomizeInPlace
{
private:
  void swap(T* array, int index1, int index2){
    T t3 = array[index1];
    array[index1] = array[index2];
    array[index2] = t3;
  }

public:
  void Randomize(T* array, int length){
    for (int i = 0; i < length - 1; i++) {
      swap(array, i, rand() % length + i);
    }
  }
};
