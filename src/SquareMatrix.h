//--------------------------------------------------//
// File Name: SquareMatrix.h                        //
// Function: Square matrix calculation              //
// Copyright(C) 2016 shoarai                        //
// The MIT License (MIT)                            //
//--------------------------------------------------//
#ifndef _SQUARE_MATRIX_H_
#define _SQUARE_MATRIX_H_

//------------------------------------------//
//              インクルード                  //
//------------------------------------------//
#include "Matrix.h"

namespace arith {

//------------------------------------------//
//              ク　ラ　ス                   //
//------------------------------------------//
class SquareMatrix : public Matrix{
public:
    unsigned int num;  // 行列の行数（＝列数）

public:
    explicit SquareMatrix(unsigned int);  // コンストラクタ
    SquareMatrix(const Matrix&);          // コピーコンストラクタ
    virtual ~SquareMatrix(){};            // デストラクタ

    SquareMatrix& operator=(const Matrix&);   // 正方行列の代入
    // operator      Matrix();                   // 行列クラスへのキャスト

    double       det() const;                      // 行列式
    SquareMatrix invrs(const double& det) const;   // 逆行列

private:
    double       cofactor
        (unsigned int, unsigned int) const;   // 余因子
    double       trace()  const;              // 対角和
    SquareMatrix adjMat() const;              // 余因子行列
};

}

#endif  // _SQUARE_MATRIX_H_
