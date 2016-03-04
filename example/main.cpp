//--------------------------------------------------//
// File Name: Arith.h                               //
// Function: arithmetic calculation                 //
// Copyright(C) 2016 shoarai                        //
// The MIT License (MIT)                            //
//--------------------------------------------------//
#include "../src/arith.h"

using namespace arith;

void calcVetor();

int main()
{
    calcVetor();

  	return 0;
}

void calcVetor () {
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

    // // Cross product
    vecC = vecA * vecB;

    // Inner product
    double inner = vecA % vecB;

    // Norm
    double norm = vecA.norm();

    // Normalization
    vecC = vecA.normalize();
}
