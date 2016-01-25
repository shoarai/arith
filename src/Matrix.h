//--------------------------------------------------//
// File Name: Matrix.h                              //
// Function: Matrix calculation                     //
// Copyright(C) 2013 shoarai                        //
// The MIT License (MIT)                            //
//--------------------------------------------------//
#ifndef _MATRIX_H_
#define _MATRIX_H_

//------------------------------------------//
//              インクルード              //
//------------------------------------------//
#include <string>

//------------------------------------------//
//              ク　ラ　ス                   //
//------------------------------------------//
class Matrix{
public:
    Cunsigned int m_row;    // 行
    Cunsigned int m_col;    // 列

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

//--------------------------//
// 正方行列                 //
//--------------------------//
class SquareMat : public Matrix{
public:
    Cunsigned int num;  // 行列の行数（＝列数）

public:
    // コンストラクタ
    explicit SquareMat(unsigned int);

    SquareMat(const Matrix&);   // コピーコンストラクタ
    virtual ~SquareMat(){};     // デストラクタ

    // 正方行列の代入
    SquareMat& operator=(const Matrix&);

    // 行列クラスへのキャスト
    operator Matrix();

    double    det()  const;                     // 行列式
    SquareMat invrs(const double& det) const;   // 逆行列

private:
    double    cofactor
        (unsigned int, unsigned int) const; // 余因子
    double    trace()  const;               // 対角和
    SquareMat adjMat() const;               // 余因子行列
};

#endif  // _MATRIX_H_
