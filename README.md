# arith
Arithmetic program - vector and matrix

### Usage
Include "arith/src/Vector.h" file.

```cpp
#include <iostream>
#include "arith/src/Vector.h"

using namespace std;

int main()
{
    // Initialize
    Vector vecA;
    Vector vecB(1, 10, 100);

    // Set elements
    vecA.set(1, 2, 3);

    // Get elements
    double x = vecA.getx();	// x axis
    double y = vecA.gety();	// y axis
    double z = vecA.getz();	// z axis

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
    vecC  = vecA * vecB;
    vecC *= vecA;

    // Inner product
    vecC  = vecA / vecB;
    vecC /= vecA;

    // Norm
    double norm = vecA.norm();

    // Normalization
    vecC = vecA.normarize();

	return 0;
}
```

Include "arith/src/Matrix.h" file.

```cpp
#include <iostream>
#include "arith/src/Matrix.h"

using namespace std;

int main
{
    // Initialize
    Matrix matA(3, 2);
    Matrix matB(3, 2);

    // Get elements
    double a01 = Matrix(0, 1);
    double a32 = Matrix(3, 2);

    // Addition and subtraction of matrixes
    Matrix matC = matA + matB;
    matC += matA;
    matC  = matA - matB;
    matC -= matB;

    Matrix matD(2, 3);

    // Multiplication and division of matrixes
    Matrix matE = matA * matD;

    int val = 10;

    // Multiplication and division of a matrix and a scholar
    matE  = matA * val;
    matE *= val;
    matE  = matA / val;
    matE /= val;

    // Transpose
    Matrix matF = matA.transpose();

    return 0;
}
```
