#include <vector>

template<class T>
class InsertionSort
{
private:
  std::vector<T> numbers;
public:
  InsertionSort();
  ~InsertionSort();
  void AddNumbers(std::vector<T> numbers);
  std::vector<T> GetNumbers() const;
  void WriteNumbers();
  void Sort();
};

