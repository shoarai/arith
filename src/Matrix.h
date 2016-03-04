//--------------------------------------------------//
// File Name: Matrix.h                              //
// Function: Matrix calculation                     //
// Copyright(C) 2016 shoarai                        //
// The MIT License (MIT)                            //
//--------------------------------------------------//
#ifndef _MATRIX_H_
#define _MATRIX_H_

namespace arith {

//------------------------------------------//
//              ク　ラ　ス                   //
//------------------------------------------//
class Matrix{
public:
    unsigned int m_row;    // 行
    unsigned int m_col;    // 列

    double** val;   // 行列要素用ポインタ
//  vector< vector<double> > val;

public:
    explicit Matrix
        (unsigned int, unsigned int);   // コンストラクタ
    Matrix(const Matrix&);              // コピーコンストラクタ
    virtual ~Matrix();                  // デストラクタ

    // 行列要素を取り出す
    double& operator()(unsigned int row, unsigned int col);

    // 行列の代入
    Matrix& operator= (const Matrix&);

    // 行列との加減算
    Matrix  operator+ (const Matrix&) const;
    Matrix& operator+=(const Matrix&);
    Matrix  operator- (const Matrix&) const;
    Matrix& operator-=(const Matrix&);

    // 行列との積
    Matrix  operator* (const Matrix&) const;

    // 数値との乗除算
    Matrix  operator* (const double&) const;
    Matrix& operator*=(const double&);
    Matrix  operator/ (const double&) const;
    Matrix& operator/=(const double&);

    // 転置行列
    Matrix transpose() const;
};

}

#endif  // _MATRIX_H_
