//--------------------------------------------------//
// File Name: main.cpp                              //
// Function: Arithmetic calculation                 //
// Copyright(C) 2016 shoarai                        //
// The MIT License (MIT)                            //
//--------------------------------------------------//
#include "../src/arith.h"
#include <stdio.h>

using namespace arith;

void calcVetor();
void calcMatrix();

int main()
{
    calcVetor();
    calcMatrix();
  	return 0;
}

void calcVetor () {
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
}

void calcMatrix() {
    // Initialize the number of row and columns
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
}
