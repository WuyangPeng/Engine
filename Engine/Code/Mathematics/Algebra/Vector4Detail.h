///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 11:18)

#ifndef MATHEMATICS_ALGEBRA_VECTOR4_DETAIL_H
#define MATHEMATICS_ALGEBRA_VECTOR4_DETAIL_H

#include "Vector4.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_VECTOR4_ACHIEVE)

    #include "Vector4Achieve.h"

#endif  // !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_VECTOR4_ACHIEVE)

#include <iostream>

template <typename Real>
requires std::is_arithmetic_v<Real>
template <typename RhsType>
Mathematics::Vector4<Real>::Vector4(const Vector2<RhsType>& vector)
    : x{ boost::numeric_cast<Real>(vector.GetX()) }, y{ boost::numeric_cast<Real>(vector.GetY()) }, z{}, w{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
template <typename RhsType>
Mathematics::Vector4<Real>::Vector4(const Vector3<RhsType>& vector)
    : x{ boost::numeric_cast<Real>(vector.GetX()) }, y{ boost::numeric_cast<Real>(vector.GetY()) }, z{ boost::numeric_cast<Real>(vector.GetZ()) }, w{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
template <typename RhsType>
Mathematics::Vector4<Real>::Vector4(const Vector4<RhsType>& vector)
    : x{ boost::numeric_cast<Real>(vector.GetX()) }, y{ boost::numeric_cast<Real>(vector.GetY()) }, z{ boost::numeric_cast<Real>(vector.GetZ()) }, w{ boost::numeric_cast<Real>(vector.GetW()) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
bool Mathematics::operator==(const Vector4<Real>& lhs, const Vector4<Real>& rhs)
{
    return lhs.GetCoordinate() == rhs.GetCoordinate();
}

template <typename Real>
bool Mathematics::operator<(const Vector4<Real>& lhs, const Vector4<Real>& rhs) noexcept
{
    if (lhs.GetX() < rhs.GetX())
        return true;
    else if (rhs.GetX() < lhs.GetX())
        return false;
    else if (lhs.GetY() < rhs.GetY())
        return true;
    else if (rhs.GetY() < lhs.GetY())
        return false;
    else if (lhs.GetZ() < rhs.GetZ())
        return true;
    else if (rhs.GetZ() < lhs.GetZ())
        return false;
    else
        return lhs.GetW() < rhs.GetW();
}

template <typename Real>
std::ostream& Mathematics::operator<<(std::ostream& outFile, const Vector4<Real>& vector)
{
    return outFile << "x = "
                   << vector.GetX()
                   << " y = "
                   << vector.GetY()
                   << " z = "
                   << vector.GetZ()
                   << " w = "
                   << vector.GetW();
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR4_DETAIL_H