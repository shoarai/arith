//--------------------------------------------------//
// File Name: SquareMatrix.h                        //
// Function: Square matrix calculation              //
// Copyright(C) 2013 shoarai                        //
// The MIT License (MIT)                            //
//--------------------------------------------------//
#ifndef _SQUARE_MATRIX_H_
#define _SQUARE_MATRIX_H_

//------------------------------------------//
//              インクルード                  //
//------------------------------------------//
#include <string>
#include "Matrix.h"

//------------------------------------------//
//              ク　ラ　ス                   //
//------------------------------------------//
class SquareMatrix : public Matrix{
public:
    Cunsigned int num;  // 行列の行数（＝列数）

public:
    // コンストラクタ
    explicit SquareMatrix(unsigned int);

    SquareMatrix(const Matrix&);   // コピーコンストラクタ
    virtual ~SquareMatrix(){};     // デストラクタ

    // 正方行列の代入
    SquareMatrix& operator=(const Matrix&);

    // 行列クラスへのキャスト
    operator Matrix();

    double    det()  const;                     // 行列式
    SquareMatrix invrs(const double& det) const;   // 逆行列

private:
    double    cofactor
        (unsigned int, unsigned int) const; // 余因子
    double    trace()  const;               // 対角和
    SquareMatrix adjMat() const;               // 余因子行列
};

#endif  // _SQUARE_MATRIX_H_
