#include <vector>

class MatrixMultiplication
{
public:
  std::vector<std::vector<int>> Multiply(std::vector<std::vector<int>> A, std::vector<std::vector<int>> B, int dimension){
    std::vector<std::vector<int>> C;
    for (int i = 0; i < dimension; i++) {
      std::vector<int> c;
      for (int j = 0; j < dimension; j++) {
        c.push_back(0);
      }
      C.push_back(c);
    }

    for (int i = 0; i < dimension; i++) {
      for (int j = 0; j < dimension; j++) {
        C[i][j] = 0;
        for (int k = 0; k < dimension; k++) {
          C[i][j] = C[i][j] + A[i][k] * B [k][j];
        }  
      }
    }

    return C;
  }
};
