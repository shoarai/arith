# arith
Arithmetic program - vector and matrix calculation

### Features
#### Vector calculation
* Set and get elements of a vector
* Addition and subtraction of vectors
* Multiplication and division of a vector and a scholar
* Cross product
* Inner product
* Norm
* Normalization

#### Matrix calculation
* Set and get elements of a matrix
* Addition and subtraction of matrixes
* Multiplication and division of matrixes
* Multiplication and division of a matrix and a scholar
* Transpose

#### Square Matrix calculation
* Determinant
* Inverse matrix

### Usage
Include "src/arith.h" file

### Example
Vector calculation

```cpp
#include "arith/src/arith.h"

using namespace arith;

int main()
{
  // Initialize x, y and z elements
  Vector vecA;
  Vector vecB(1, 10, 100);

  // Set elements
  vecA.set(1, 2, 3);

  // Get elements
  double x = vecA.getx();
  double y = vecA.gety();
  double z = vecA.getz();

  Vector vecC;

  // Addition and subtraction of vectors
  vecC  = vecA + vecB;
  vecC += vecA;
  vecC  = vecA - vecB;
  vecC -= vecA;

  int val = 10;

  // Multiplication and division of a vector and a scholar
  vecC  = vecA * val;
  vecC *= val;
  vecC  = vecA / val;
  vecC /= val;

  // Cross product
  vecC = vecA * vecB;

  // Inner product
  double inner = vecA % vecB;

  // Norm
  double norm = vecA.norm();

  // Normalization
  vecC = vecA.normalize();

	return 0;
}
```

Matrix calculation

```cpp
#include "arith/src/arith.h"

using namespace arith;

int main
{
  // Initialize the number of rows and columns
  Matrix matA(3, 2);
  Matrix matB(3, 2);

  // Set elements
  matA(0, 1) = 10;
  matB(2, 2) = 20;

  // Get elements
  double a01 = matA(0, 1);
  double b22 = matB(2, 2);

  // Addition and subtraction of matrixes
  Matrix matC = matA + matB;
  matC += matA;
  matC  = matA - matB;
  matC -= matB;

  Matrix matD(2, 3);

  // Multiplication and division of matrixes
  Matrix matE = matD * matA;

  int val = 10;

  // Multiplication and division of a matrix and a scholar
  matA  = matB * val;
  matA *= val;
  matA  = matB / val;
  matA /= val;

  // Transpose
  matA = matD.transpose();

	return 0;
}
```

Square matrix calculation

```cpp
#include "arith/src/arith.h"

using namespace arith;

int main
{
  // Initialize the number of rows and columns
  SquareMatrix smatA(3);

  Matrix matA(2, 2);

  // Convert a matrix with the same number of rows and columns
  // into square matrix type
  SquareMatrix smatB = matA;

  // Determinant
  double det = smatA.det();

  // Inverse matrix
  if(det != 0){
      SquareMatrix smatC = smatA.invrs(det);
  }

	return 0;
}
```
