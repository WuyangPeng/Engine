/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.5 (2024/02/03 18:20)

#ifndef MATHEMATICS_ALGEBRA_QUATERNION_DETAIL_H
#define MATHEMATICS_ALGEBRA_QUATERNION_DETAIL_H

#include "Quaternion.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_QUATERNION_ACHIEVE)

    #include "QuaternionAchieve.h"

#endif  // !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_QUATERNION_ACHIEVE)

template <typename Real>
bool Mathematics::operator==(const Quaternion<Real>& lhs, const Quaternion<Real>& rhs) noexcept
{
    return lhs.GetW() == rhs.GetW() && lhs.GetX() == rhs.GetX() && lhs.GetY() == rhs.GetY() && lhs.GetZ() == rhs.GetZ();
}

template <typename Real>
bool Mathematics::operator<(const Quaternion<Real>& lhs, const Quaternion<Real>& rhs) noexcept
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
Mathematics::Quaternion<Real> Mathematics::operator*(const Quaternion<Real>& lhs, const Quaternion<Real>& rhs) noexcept
{
    /// (x0*i + y0*j + z0*k + w0)*(x1*i + y1*j + z1*k + w1)
    /// =
    /// i*(+x0*w1 + y0*z1 - z0*y1 + w0*x1) +
    /// j*(-x0*z1 + y0*w1 + z0*x1 + w0*y1) +
    /// k*(+x0*y1 - y0*x1 + z0*w1 + w0*z1) +
    /// 1*(-x0*x1 - y0*y1 - z0*z1 + w0*w1)

    const auto x = +lhs.GetX() * rhs.GetW() + lhs.GetY() * rhs.GetZ() - lhs.GetZ() * rhs.GetY() + lhs.GetW() * rhs.GetX();
    const auto y = -lhs.GetX() * rhs.GetZ() + lhs.GetY() * rhs.GetW() + lhs.GetZ() * rhs.GetX() + lhs.GetW() * rhs.GetY();
    const auto z = +lhs.GetX() * rhs.GetY() - lhs.GetY() * rhs.GetX() + lhs.GetZ() * rhs.GetW() + lhs.GetW() * rhs.GetZ();
    const auto w = -lhs.GetX() * rhs.GetX() - lhs.GetY() * rhs.GetY() - lhs.GetZ() * rhs.GetZ() + lhs.GetW() * rhs.GetW();

    return Quaternion<Real>{ w, x, y, z };
}

template <typename Real>
Real Mathematics::Dot(const Quaternion<Real>& lhs, const Quaternion<Real>& rhs) noexcept
{
    return lhs.GetW() * rhs.GetW() + lhs.GetX() * rhs.GetX() + lhs.GetY() * rhs.GetY() + lhs.GetZ() * rhs.GetZ();
}

template <typename Real>
bool Mathematics::Approximate(const Quaternion<Real>& lhs, const Quaternion<Real>& rhs, Real epsilon) noexcept
{
    return Math<Real>::FAbs(lhs.GetW() - rhs.GetW()) <= epsilon &&
           Math<Real>::FAbs(lhs.GetX() - rhs.GetX()) <= epsilon &&
           Math<Real>::FAbs(lhs.GetY() - rhs.GetY()) <= epsilon &&
           Math<Real>::FAbs(lhs.GetZ() - rhs.GetZ()) <= epsilon;
}

template <typename Real>
std::ostream& Mathematics::operator<<(std::ostream& stream, const Quaternion<Real>& quaternion)
{
    return stream << "w = "
                  << quaternion.GetW()
                  << " x = "
                  << quaternion.GetX()
                  << " y = "
                  << quaternion.GetY()
                  << " z = "
                  << quaternion.GetZ();
}

#endif  // MATHEMATICS_ALGEBRA_QUATERNION_DETAIL_H
