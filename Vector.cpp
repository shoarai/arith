//--------------------------------------------------//
// 名前：Vector.cpp                                  //
// 機能：ベクトル計算                                	//
// Copyright(C) 2013 shoarai, all rights reserved.  //
//--------------------------------------------------//

//------------------------------------------//
//              インクルード              		//
//------------------------------------------//
#include <math.h>
#include "Vector.h"

//------------------------------------------//
//              関           数              //
//------------------------------------------//
// コンストラクタ
Vector::Vector()
    : m_x(0)
    , m_y(0)
    , m_z(0)
{
    // 処理なし
}

// コンストラクタ
Vector::Vector(
    const double &x,
    const double &y,
    const double &z)
    : m_x(x)
    , m_y(y)
    , m_z(z)
{
    // 処理なし
}

// ベクトル成分の設定
void Vector::set(
    const double &x,
    const double &y,
    const double &z)
{
    m_x = x;
    m_y = y;
    m_z = z;
}

// ベクトルの加算
Vector Vector::operator+(const Vector &vecArg)
{
    Vector vecAns;
    vecAns.m_x = m_x + vecArg.m_x;
    vecAns.m_y = m_y + vecArg.m_y;
    vecAns.m_z = m_z + vecArg.m_z;

    return vecAns;
}

// ベクトルの加算
Vector& Vector::operator+=(const Vector &vecArg)
{
    m_x += vecArg.m_x;
    m_y += vecArg.m_y;
    m_z += vecArg.m_z;

    return *this;
}

// ベクトルの減算
Vector Vector::operator-(const Vector &vecArg)
{
    Vector vecAns;
    vecAns.m_x = m_x - vecArg.m_x;
    vecAns.m_y = m_y - vecArg.m_y;
    vecAns.m_z = m_z - vecArg.m_z;

    return vecAns;
}

// ベクトルの減算
Vector& Vector::operator-=(const Vector &vecArg)
{
    m_x -= vecArg.m_x;
    m_y -= vecArg.m_y;
    m_z -= vecArg.m_z;

    return *this;
}

// 数値の乗算
Vector Vector::operator*(const double &val)
{
    Vector vecAns;
    vecAns.m_x = m_x * val;
    vecAns.m_y = m_y * val;
    vecAns.m_z = m_z * val;

    return vecAns;
}

// 数値の乗算
Vector& Vector::operator*=(const double &val)
{
    m_x *= val;
    m_y *= val;
    m_z *= val;

    return *this;
}

// 数値の除算
Vector Vector::operator/(const double &val)
{
    Vector vecAns;
    vecAns.m_x = m_x / val;
    vecAns.m_y = m_y / val;
    vecAns.m_z = m_z / val;

    return vecAns;
}

// 数値の除算
Vector& Vector::operator/=(const double &val)
{
    m_x /= val;
    m_y /= val;
    m_z /= val;

    return *this;
}

// ベクトルの外積
Vector Vector::operator*(const Vector &vecArg)
{
    Vector vecAns;
    vecAns.m_x = m_y * vecArg.m_z - m_z * vecArg.m_y;
    vecAns.m_y = m_z * vecArg.m_x - m_x * vecArg.m_z;
    vecAns.m_z = m_x * vecArg.m_y - m_y * vecArg.m_x;

    return vecAns;
}

// ベクトルの内積
double Vector::operator%(const Vector &vecArg)
{
    return (m_x * vecArg.getx() + m_y * vecArg.gety() + m_z * vecArg.getz());
}

// ノルム計算
double Vector::norm() const
{
    return sqrt((m_x * m_x) + (m_y * m_y) + (m_z * m_z));
}

// ベクトル正規化
Vector Vector::normalize() const
{
    Vector vecAns = *this;
    vecAns /= vecAns.norm();

    return vecAns;
}
