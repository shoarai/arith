//--------------------------------------------------//
// File Name: Vector.h                              //
// Function: Vector calicuration                    //
// Copyright(C) 2013 shoarai                        //
// The MIT License (MIT)                            //
//--------------------------------------------------//
#ifndef _VECTOR_H_
#define _VECTOR_H_

//------------------------------------------//
//              ク　ラ　ス                    //
//------------------------------------------//
class Vector{
public:
    Vector();                                   // コンストラクタ
    Vector(                                     // コンストラクタ
        const double &x,
        const double &y,
        const double &z);
    inline double getx() const;                 // ベクトル成分xの取得
    inline double gety() const;                 // ベクトル成分yの取得
    inline double getz() const;                 // ベクトル成分zの取得
    void    set(                                // ベクトル成分の設定
        const double &x,
        const double &y,
        const double &z);
    inline void setx(const double &x);          // ベクトルx成分の設定
    inline void sety(const double &y);          // ベクトルy成分の設定
    inline void setz(const double &z);          // ベクトルz成分の設定
    Vector  operator+ (const Vector &vecArg);   // ベクトルの加算
    Vector& operator+=(const Vector &vecArg);
    Vector  operator- (const Vector &vecArg);   // ベクトルの減算
    Vector& operator-=(const Vector &vecArg);
    Vector  operator* (const double &val);      // 数値の乗算
    Vector& operator*=(const double &val);
    Vector  operator/ (const double &val);      // 数値の除算
    Vector& operator/=(const double &val);
    Vector  operator* (const Vector &vecArg);   // ベクトルの外積
    double  operator% (const Vector &vecArg);   // ベクトルの内積
    double  norm() const;                       // ノルム計算
    Vector  normalize() const;                  // ベクトル正規化

private:
    double m_x;     // x成分
    double m_y;     // y成分
    double m_z;     // z成分
};

//------------------------------------------//
//              インライン関数             //
//------------------------------------------//
// ベクトル成分xの取得
inline double Vector::getx() const
{
    return m_x;
}

// ベクトル成分yの取得
inline double Vector::gety() const
{
    return m_y;
}

// ベクトル成分zの取得
inline double Vector::getz() const
{
    return m_z;
}

// ベクトル成分xの設定
inline void Vector::setx(const double &x)
{
    m_x = x;
}

// ベクトル成分yの設定
inline void Vector::sety(const double &y)
{
    m_y = y;
}

// ベクトル成分zの設定
inline void Vector::setz(const double &z)
{
    m_z = z;
}

#endif  // _VECTOR_H_
