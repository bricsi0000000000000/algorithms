template <class T> class InsertionSort
{
public:
  void Sort(T* array, int length) {
    for (size_t i = 1; i < length; i++) {
      T key = array[i];
      size_t j = i - 1;
      while (j >= 0 && array[j] > key) {
        array[j + 1] = array[j];
        j--;
      }
      array[j + 1] = key;
    }
  }
};
