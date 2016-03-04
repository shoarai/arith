//--------------------------------------------------//
// File Name: SquareMatrix.cpp                      //
// Function: Square matrix calculation              //
// Copyright(C) 2016 shoarai                        //
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

//------------------------------------------//
//              関           数              //
//------------------------------------------//
SquareMatrix::SquareMatrix(unsigned int n) :
    num(n),
    Matrix(n, n)
{
    // 処理なし
}

SquareMatrix::SquareMatrix(const Matrix& mat)
    : num(mat.m_row), Matrix(mat.m_row, mat.m_row)
{
    // 行と列の要素数が等しいか
    if(mat.m_row != mat.m_col){
        string err = "Matrix isn't square matrix";
        throw err;
    }

    // 値代入
    for(unsigned int i = 0; i < num; i++)
    {
        for(unsigned int j = 0; j < num; j++)
        {
            val[i][j] = mat.val[i][j];
        }
    }
}

// 行列を正方行列に変換
SquareMatrix& SquareMatrix::operator=(const Matrix& mat)
{
    // 行と列の要素数が等しいか
    if(mat.m_row != mat.m_col){
        string err = "Matrix isn't square matrix";
        throw err;
    }

    // 値代入
    for(unsigned int i = 0; i < num; i++)
    {
        for(unsigned int j = 0; j < num; j++)
        {
            val[i][j] = mat.val[i][j];
        }
    }

    return *this;
}

// キャスト演算子オーバーロード
SquareMatrix::operator Matrix()
{
    Matrix matAns(num, num);

    // 値代入
    for(unsigned int i = 0; i < num; i++)
    {
        for(unsigned int j = 0; j < num; j++)
        {
            matAns.val[i][j] = val[i][j];
        }
    }

    return matAns;
}

// 余因子を求める
double SquareMatrix::cofactor(unsigned int row, unsigned int col) const
{
    // 次数が１少ない行列を作る
    SquareMatrix tmp(num - 1);

    // 代入先の行番号
    unsigned int i2 = 0;

    // 代入元の行番号
    for(unsigned int i = 0; i < num; i++)
    {
        // 余因子展開の対象の行をとばす
        if(i == row){
            continue;
        }

        // 代入先の列番号
        unsigned int j2 = 0;

        // 代入元の列番号
        for(unsigned int j = 0; j < num; j++)
        {
            // 余因子展開の対象の列をとばす
            if(j == col){
                continue;
            }

            // 次数が１小さい行列を作る
            tmp.val[i2][j2] = val[i][j];

            j2++;
        }

        i2++;
    }

    // 解となる余因子
    double ans = tmp.det();

    // 行番号＋列番号が奇数の時は、マイナスをかける
    if((row+col) % 2 != 0){
        ans *= -1;
    }

    return ans;
}

// 余因子行列を求める
SquareMatrix SquareMatrix::adjMat() const
{
    // 解となる行列
    SquareMatrix smatAns(num);

    for(unsigned int i = 0; i < num; i++)
    {
        for(unsigned int j = 0; j < num; j++)
        {
            // 余因子を転置して代入する
            smatAns.val[i][j] = this->cofactor(j, i);
        }
    }

    return smatAns;
}

// 行列式算出
double SquareMatrix::det() const
{
    // 行列式
    double ans = 0;

    //------------------------------------------//
    // 次数が２のとき、たすきがけで解く         //
    //------------------------------------------//
    if(num == 2)
    {
        ans = val[0][0] * val[1][1] - val[0][1] * val[1][0];
    }
    //------------------------------------------//
    // 次数が３のとき、サラスの方法で解く        //
    //------------------------------------------//
    else if(num == 3)
    {
        ans  = val[0][0] * val[1][1] * val[2][2];
        ans += val[0][1] * val[1][2] * val[2][0];
        ans += val[0][2] * val[1][0] * val[2][1];
        ans -= val[0][2] * val[1][1] * val[2][0];
        ans -= val[0][0] * val[1][2] * val[2][1];
        ans -= val[0][1] * val[1][0] * val[2][2];
    }
    //------------------------------------------//
    // 次数が４以上のとき                        //
    //------------------------------------------//
    else
    {
        // 行列の対角要素に０があるか判定
        bool dia0 = true;
//      bool dia0 = false;

        for(unsigned int i = 0; i < num; i++)
        {
            if(val[i][i] == 0){
                dia0 = true;
            }
        }

        //------------------------------------------//
        // 行列の対角要素に０があるとき、余因子展開で解く
        //------------------------------------------//
        if(dia0 == true)
        {
            // 余因子の対象位置をずらす
            for(unsigned int i = 0; i < num; i++)
            {
                // 余因子展開の対象にする値が０なら
                if(val[i][0] == 0){
                    continue;
                }

                // 余因子展開の対象にする値 × 余因子
                ans += val[i][0] * this->cofactor(i, 0);
            }
        }
        //------------------------------------------//
        // 行列の対角要素に０がないとき、三角行列で解く
        //------------------------------------------//
        else
        {
            ans = 1;        // 行列式
            double buf = 0; // 一次保存

            // 上三角行列
            SquareMatrix triMat = *this;

            // 上三角行列を作成
            // http://thira.plavox.info/blog/2008/06/_c.html
            for(unsigned int i = 0; i < num; i++)
            {
                for(unsigned int j = 0; j < num; j++)
                {
                    if(i < j)
                    {
                        if(triMat.val[i][i] == 0){
                            return 0;
                        };

                        buf = triMat.val[j][i] / triMat.val[i][i];  // 対角要素に0がないとき

                        for(unsigned int k = 0; k < num; k++)
                        {
                            triMat.val[j][k] -= triMat.val[i][k] * buf;
                        }
                    }
                }
            }

            // 対角部分の積
            for(unsigned int i = 0; i < num; i++)
            {
                ans *= triMat.val[i][i];
            }
        }
    }

    return ans;
}

// 逆行列算出
SquareMatrix SquareMatrix::invrs(CDBL& deter) const
{
    // 行列式を求める
//  double det = this->det();

    if(deter == 0){
        string err = "Determinant is zero, so inverse matrix don't exist";
        throw err;
//      throw std::overflow_error("invrs():InverseMatrix don't exist"); //error処理
    }

    // 解となる行列
    SquareMatrix smatAns(num);

    bool dia0 = true;
//  bool dia0 = false;

    // 行列の対角要素に０があるか判定
    for(unsigned int i = 0; i < num; i++)
    {
        if(val[i][i] == 0){
            dia0 = true;
        }
    }

    //------------------------------------------//
    // 行列の対角要素に０があるとき、余因子行列を使って解く
    //------------------------------------------//
    if(dia0 == true)
    {
        smatAns = this->adjMat() / deter;
    }
    //------------------------------------------//
    // 行列の対角要素に０がないとき、三角行列を使って解く
    //------------------------------------------//
    else
    {
        double matBuf[6][6];    // 一時的な行列
        double buf = 0;         // 一時的なデータを蓄える
        int n = 6;              // 配列の次数

        // 行列を一時保存
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                matBuf[i][j] = val[i][j];
            }
        }

        // 単位行列を作る
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == j){
                    smatAns.val[i][j] = 1;
                }else{
                    smatAns.val[i][j] = 0;
                }
            }
        }

        // 掃き出し法
        for(int i = 0; i < n; i++)
        {
            buf = 1 / matBuf[i][i];

            for(int j = 0; j < n; j++)
            {
                matBuf[i][j] *= buf;
                smatAns/val[i][j] *= buf;
            }

            for(int j = 0; j < n; j++)
            {
                if( i != j )
                {
                    buf = matBuf[j][i]; // ０の可能性あり（エラー）

                    for(int k = 0; k < n; k++)
                    {
                        matBuf[j][k] -= matBuf[i][k] * buf;
                        smatAns.val[j][k] -= smatAns.val[i][k] * buf;
                    }
                }
            }
        }
    }

    return smatAns;
}

// 対角和算出
double SquareMatrix::trace() const
{
    double ans = 0;

    for(unsigned int i = 0; i < num; i++)
    {
        ans += val[i][i];
    }

    return ans;
}
