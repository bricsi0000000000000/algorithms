template <class T> class BinarySearch
{
public:
  T Search(T* array, T value, int low, int high){
    while(low <= high){
      T middle = (low + high) / 2;
      if (value == array[middle]) {
        return middle;
      }
      else if(value > array[middle]){
        low = middle + 1;
      }
      else{
        high = middle - 1;
      }
    }

    return -1;
  }
};
