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
