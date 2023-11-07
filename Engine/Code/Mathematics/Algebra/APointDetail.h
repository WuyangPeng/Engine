///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 10:14)

#ifndef MATHEMATICS_ALGEBRA_A_POINT_DETAIL_H
#define MATHEMATICS_ALGEBRA_A_POINT_DETAIL_H

#include "APoint.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_A_POINT_ACHIEVE)

    #include "APointAchieve.h"

#endif  // !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_A_POINT_ACHIEVE)

#include "AVector.h"

template <typename T>
Mathematics::AVector<T> Mathematics::operator-(const APoint<T>& lhs, const APoint<T>& rhs) noexcept
{
    return AVector<T>{ lhs.GetX() - rhs.GetX(), lhs.GetY() - rhs.GetY(), lhs.GetZ() - rhs.GetZ() };
}

template <typename T>
Mathematics::APoint<T> Mathematics::operator+(const APoint<T>& lhs, const AVector<T>& rhs)
{
    APoint<T> result{ lhs };

    result += rhs;

    return result;
}

template <typename T>
Mathematics::APoint<T> Mathematics::operator-(const APoint<T>& lhs, const AVector<T>& rhs)
{
    APoint<T> result{ lhs };

    result -= rhs;

    return result;
}

template <typename T>
Mathematics::APoint<T> Mathematics::operator+(const APoint<T>& lhs, const APoint<T>& rhs)
{
    APoint<T> result{ lhs };

    result += rhs;

    return result;
}

template <typename T>
Mathematics::APoint<T> Mathematics::operator*(const APoint<T>& lhs, T scalar)
{
    APoint<T> result{ lhs };

    result *= scalar;

    return result;
}

template <typename T>
Mathematics::APoint<T> Mathematics::operator/(const APoint<T>& lhs, T scalar)
{
    APoint<T> result{ lhs };

    result /= scalar;

    return result;
}

template <typename T>
Mathematics::APoint<T> Mathematics::operator*(T scalar, const APoint<T>& rhs)
{
    return rhs * scalar;
}

template <typename T>
T Mathematics::Dot(const APoint<T>& lhs, const AVector<T>& rhs) noexcept
{
    return lhs.GetX() * rhs.GetX() + lhs.GetY() * rhs.GetY() + lhs.GetZ() * rhs.GetZ();
}

template <typename T>
bool Mathematics::Approximate(const APoint<T>& lhs, const APoint<T>& rhs, T epsilon) noexcept
{
    return Math<T>::FAbs(lhs.GetX() - rhs.GetX()) <= epsilon &&
           Math<T>::FAbs(lhs.GetY() - rhs.GetY()) <= epsilon &&
           Math<T>::FAbs(lhs.GetZ() - rhs.GetZ()) <= epsilon;
}

template <typename T>
std::ostream& Mathematics::operator<<(std::ostream& outFile, const APoint<T>& point)
{
    outFile << point.GetX() << "　" << point.GetY() << "　" << point.GetZ();

    return outFile;
}

#endif  // MATHEMATICS_ALGEBRA_A_POINT_DETAIL_H
