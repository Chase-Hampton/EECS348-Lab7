#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int SIZE = 4; // Global variable for matrix size

class Matrix {
private:
  int data[SIZE][SIZE];  // 2D array for matrix data (using int for simplicity)

public:
  // 1. Read values from File into a matrix
  void readFromFile(ifstream& file) {
    for (int i = 0; i < SIZE; ++i) {
      for (int j = 0; j < SIZE; ++j) {
        if (!(file >> data[i][j])) return;
      }
    }
  }

  // 2. Display a matrix
  void display() const {
    for (int i = 0; i < SIZE; ++ i) {
      for (int j = 0; j < SIZE; ++j) {
        cout << setw(3) << data[i][j] << " ";
      }
      cout << endl;
    }
  }

  // 3. Add two matrices (operator overloading for +)
  Matrix operator+(const Matrix& other) const {
    Matrix result;
    for (int i = 0; i < SIZE; ++i) {
      for (int j = 0; j < SIZE; ++j) {
        result.data[i][j] = this->data[i][j] + other.data[i][j];
      }
    }
    return result;
  }

  // 4. Multiply two matrices (operator overloading for *)
  Matrix operator*(const Matrix& other) const {
    Matrix result;
    for (int i = 0; i < SIZE; ++i) {
      for (int j = 0; j < SIZE; ++j) {
        result.data[i][j] = 0;
        for (int k = 0; k < SIZE; ++k) {
          result.data[i][j] += this->data[i][k] * other.data[k][j];
        }
      }
    }
    return result;
  }

  // 5. Compute the sum of matrix diagonal elements
  int sumOfDiagonals() const {
    int sum = 0;
    for (int i = 0; i < SIZE; ++i) {
      sum += data[i][i];
      sum += data[i][SIZE - 1 - i];
    }
    return sum;
  }

  // 6. Swap matrix rows
  void swapRows(int row1, int row2) {
    if (row1 >= 0 && row1 < SIZE && row2 >= 0 && row2 < SIZE) {
      for (int j = 0; j < SIZE; ++j) {
        int temp = data[row1][j];
        data[row1][j] = data[row2][j];
        data[row2][j] = temp;
      }
    }
  }
};

int main() {
  ifstream inFile("matrix-data.txt");
  if (!inFile) {
    cerr << "Error: Could not open matrix-data.txt" << endl;
    return 1;
  }

  int nFromFile;
  inFile >> nFromFile;

  Matrix mat1, mat2;

  mat1.readFromFile(inFile);
  cout << "Matrix 1:" << endl;
  mat1.display();

  mat2.readFromFile(inFile);
  cout << "Matrix 2:" << endl;
  mat2.display();

  cout << "\nSum of matrices:" << endl;
  (mat1 + mat2).display();

  cout << "\nProduct of matrices:" << endl;
  (mat1 * mat2).display();

  cout << "\nSum of diagonals of matrix 1: " << mat1.sumOfDiagonals() << endl;

  mat1. swapRows(0, 2);
  cout << "\nMatrix 1 after swapping rows 0 and 2:" << endl;
  mat1.display();

  inFile.close();
  return 0;
}