//--------------------------------------------------//
// File Name: Matrix.cpp                            //
// Function: Matrix calculation                     //
// Copyright(C) 2013 shoarai                        //
// The MIT License (MIT)                            //
//--------------------------------------------------//

//------------------------------------------//
//              インクルード              		//
//------------------------------------------//
#include "Vector.h"
#include <string>

//------------------------------------------//
//              名　前　空　間             	 //
//------------------------------------------//
using namespace std;

// 行列要素を初期化する
Matrix::Matrix(unsigned int row, unsigned int col) : m_row(row), m_col(col)
{
    // 行の要素数を設定する
/*  val.resize(m_row);

    for(unsigned int i = 0; i < m_row; i++)
    {
        // 列の要素数を設定する
        val[i].resize(m_col);
    }
*/
    // 行要素を生成する
    val = new double*[m_row];

    for (unsigned int i = 0; i < m_row; i++)
    {
        // 列要素を生成する
        val[i] = new double[m_col];
    }

    // 行列要素を初期化する
    for(unsigned int i = 0; i < m_row; i++)
    {
        for(unsigned int j = 0; j < m_col; j++)
        {
            val[i][j] = 0;
        }
    }
}

// 行列要素をオブジェクトで初期化する
Matrix::Matrix(const Matrix& mat) :
    m_row(mat.m_row), m_col(mat.m_col)
{
    // 行の要素数を設定する
/*  val.resize(m_row);

    for(unsigned int i = 0; i < m_row; i++)
    {
        // 列の要素数を設定する
        val[i].resize(m_col);
    }
*/
    // 列要素生成
    val = new double*[m_row];

    for (unsigned int i = 0; i < m_row; i++)
    {
        // 行要素生成
        val[i] = new double[m_col];
    }

    // 値代入
    for(unsigned int i = 0; i < m_row; i++)
    {
        for(unsigned int j = 0; j < m_col; j++)
        {
            val[i][j] = mat.val[i][j];
        }
    }
}

// 行列要素を破棄する
Matrix::~Matrix()
{
    // 行列要素破棄
    for (unsigned int i = 0; i < m_row; i++){
        delete[] val[i];
    }

    delete[] val;
}

// 行列要素を取得する
double& Matrix::operator()(unsigned int row, unsigned int col)
{
    return val[row-1][col-1];
}

// 代入演算子
Matrix& Matrix::operator=(const Matrix& mat)
{
    // 行列同士の行数と列数が等しくないとき
    if(m_row != mat.m_row || m_col != mat.m_col)
    {
        string err = "Matrix can't be substituted";
        throw err;
    }

    for(unsigned int i = 0; i < m_row; i++)
    {
        for(unsigned int j = 0; j < m_col; j++)
        {
            val[i][j] = mat.val[i][j];
        }
    }

    return *this;
}

// +演算子
Matrix Matrix::operator+(const Matrix& mat) const
{
    // 行列同士の行数と列数が等しくないとき
    if(m_row != mat.m_row || m_col != mat.m_col){
        string err = "Matrix can't be added";
        throw err;
    }

    // 解となる行列
    Matrix matAns(m_row, m_col);

    // 受け取った2つの行列を加算する
    for(unsigned int i = 0; i < m_row; i++)
    {
        for(unsigned int j = 0; j < m_col; j++)
        {
            matAns.val[i][j] = val[i][j] + mat.val[i][j];
        }
    }

    return matAns;
}

// +=演算子
Matrix& Matrix::operator+=(const Matrix& mat)
{
    // 行列同士の行数と列数が等しくないとき
    if(m_row != mat.m_row || m_col != mat.m_col){
        string err = "Matrix can't be added";
        throw err;
    }

    // 受け取った2つの行列を加算する
    for(unsigned int i = 0; i < m_row; i++)
    {
        for(unsigned int j = 0; j < m_col; j++)
        {
            val[i][j] += mat.val[i][j];
        }
    }

    return *this;
}

// -演算子
Matrix Matrix::operator-(const Matrix& mat) const
{
    // 行列同士の行数と列数が等しくないとき
    if(m_row != mat.m_row || m_col != mat.m_col){
        string err = "Matrix can't be subtracted";
        throw err;
    }

    // 解となる行列
    Matrix matAns(m_row, m_col);

    // 行列減算
    for(unsigned int i = 0; i < m_row; i++)
    {
        for(unsigned int j = 0; j < m_col; j++)
        {
            matAns.val[i][j] = val[i][j] - mat.val[i][j];
        }
    }

    return matAns;
}


// -=演算子
Matrix& Matrix::operator-=(const Matrix& mat)
{
    // 行列同士の行数と列数が等しくないとき
    if(m_row != mat.m_row || m_col != mat.m_col){
        string err = "Matrix can't be subtracted";
        throw err;
    }

    // 行列加算
    for(unsigned int i = 0; i < m_row; i++){
        for(unsigned int j = 0; j < m_col; j++)
        {
            val[i][j] -= mat.val[i][j];
        }
    }

    return *this;
}

// 行列同士の乗算
Matrix Matrix::operator*(const Matrix& mat) const
{
    // 被乗数の行列の列数＝乗数の行列の行数
    if(m_col != mat.m_row){
        string err = "Matrix can't be producted";
        throw err;
    }

    // 解となる行列（被乗数の行列の列数、乗数の行列の行数）
    Matrix matAns(m_row, mat.m_col);

    // 行列の乗算
    for(unsigned int i = 0; i < m_row; i++){
        for(unsigned int j = 0; j < mat.m_col; j++)
        {
            for(unsigned int k = 0; k < m_row; k++)
            {
                matAns.val[i][j] += val[i][k] * mat.val[k][j];
            }
        }
    }

    return matAns;
}

// 行列と値の乗算
Matrix Matrix::operator*(CDBL& in_val) const
{
    // 解となる行列
    Matrix matAns(m_row, m_col);

    for(unsigned int i = 0; i < m_row; i++)
    {
        for(unsigned int j = 0; j < m_col; j++)
        {
            matAns.val[i][j] = val[i][j] * in_val;
        }
    }

    return matAns;
}

// 行列と値の乗算
Matrix& Matrix::operator*=(CDBL& in_val)
{
    for(unsigned int i = 0; i < m_row; i++)
    {
        for(unsigned int j = 0; j < m_col; j++)
        {
            val[i][j] *= in_val;
        }
    }

    return *this;
}

// 行列と値の除算
Matrix Matrix::operator/(CDBL& in_val) const
{
    // 解となる行列
    Matrix matAns(m_row, m_col);

    for(unsigned int i = 0; i < m_row; i++)
    {
        for(unsigned int j = 0; j < m_col; j++)
        {
            matAns.val[i][j] = val[i][j] / in_val;
        }
    }

    return matAns;
}

// 行列と値の除算
Matrix& Matrix::operator/=(CDBL& in_val)
{
    for(unsigned int i = 0; i < m_row; i++)
    {
        for(unsigned int j = 0; j < m_col; j++)
        {
            val[i][j] /= in_val;
        }
    }

    return *this;
}

// 転置行列を求める
Matrix Matrix::transpose() const
{
    // 解となる行列（行と列を反対に設定）
    Matrix matAns(m_col, m_row);

    for(unsigned int i = 0; i < m_row; i++)
    {
        for(unsigned int j = 0;j < m_col; j++)
        {
            matAns.val[i][j] = val[j][i];
        }
    }

    return matAns;
}
