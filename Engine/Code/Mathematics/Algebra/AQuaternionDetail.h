///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/03 14:45)

#ifndef MATHEMATICS_ALGEBRA_HQUATERNION_DETAIL_H
#define MATHEMATICS_ALGEBRA_HQUATERNION_DETAIL_H

#include "AQuaternion.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_AQUATERNION_ACHIEVE)

    #include "AQuaternionAchieve.h"

#endif  //  !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_AQUATERNION_ACHIEVE)

template <typename Real>
bool Mathematics::operator==(const AQuaternion<Real>& lhs, const AQuaternion<Real>& rhs)
{
    return lhs.GetCoordinate() == rhs.GetCoordinate();
}

template <typename Real>
bool Mathematics::operator<(const AQuaternion<Real>& lhs, const AQuaternion<Real>& rhs) noexcept
{
    if (lhs.GetW() < rhs.GetW())
        return true;
    else if (rhs.GetW() < lhs.GetW())
        return false;
    else if (lhs.GetX() < rhs.GetX())
        return true;
    else if (rhs.GetX() < lhs.GetX())
        return false;
    else if (lhs.GetY() < rhs.GetY())
        return true;
    else if (rhs.GetY() < lhs.GetY())
        return false;
    else
        return lhs.GetZ() < rhs.GetZ();
}

template <typename Real>
const Mathematics::AQuaternion<Real> Mathematics::operator*(const AQuaternion<Real>& lhs, const AQuaternion<Real>& rhs) noexcept
{
    // 注意:  乘法一般不是可交换的，所以在大多数情况下，
    // p * q != q * p

    return AQuaternion<Real>{ lhs.GetW() * rhs.GetW() - lhs.GetX() * rhs.GetX() - lhs.GetY() * rhs.GetY() - lhs.GetZ() * rhs.GetZ(),
                              lhs.GetW() * rhs.GetX() + lhs.GetX() * rhs.GetW() + lhs.GetY() * rhs.GetZ() - lhs.GetZ() * rhs.GetY(),
                              lhs.GetW() * rhs.GetY() + lhs.GetY() * rhs.GetW() + lhs.GetZ() * rhs.GetX() - lhs.GetX() * rhs.GetZ(),
                              lhs.GetW() * rhs.GetZ() + lhs.GetZ() * rhs.GetW() + lhs.GetX() * rhs.GetY() - lhs.GetY() * rhs.GetX() };
}

template <typename Real>
Real Mathematics::Dot(const AQuaternion<Real>& lhs, const AQuaternion<Real>& rhs) noexcept
{
    return lhs.GetW() * rhs.GetW() + lhs.GetX() * rhs.GetX() + lhs.GetY() * rhs.GetY() + lhs.GetZ() * rhs.GetZ();
}

template <typename Real>
bool Mathematics::Approximate(const AQuaternion<Real>& lhs, const AQuaternion<Real>& rhs, const Real epsilon) noexcept
{
    return Math<Real>::FAbs(lhs.GetW() - rhs.GetW()) <= epsilon &&
           Math<Real>::FAbs(lhs.GetX() - rhs.GetX()) <= epsilon &&
           Math<Real>::FAbs(lhs.GetY() - rhs.GetY()) <= epsilon &&
           Math<Real>::FAbs(lhs.GetZ() - rhs.GetZ()) <= epsilon;
}

template <typename Real>
std::ostream& Mathematics::operator<<(std::ostream& outFile, const AQuaternion<Real>& quaternion)
{
    outFile << "w = " << quaternion.GetW()
            << "x = " << quaternion.GetX()
            << "y = " << quaternion.GetY()
            << "z = " << quaternion.GetZ();

    return outFile;
}

#endif  // MATHEMATICS_ALGEBRA_HQUATERNION_DETAIL_H
