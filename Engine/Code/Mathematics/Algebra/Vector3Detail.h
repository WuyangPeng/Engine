///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 11:16)

#ifndef MATHEMATICS_ALGEBRA_VECTOR3_DETAIL_H
#define MATHEMATICS_ALGEBRA_VECTOR3_DETAIL_H

#include "Vector3.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_VECTOR3_ACHIEVE)

    #include "Vector3Achieve.h"

#endif  // !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_VECTOR3_ACHIEVE)

#include <iostream>

template <typename Real>
requires std::is_arithmetic_v<Real>
template <typename RhsType>
Mathematics::Vector3<Real>::Vector3(const Vector2<RhsType>& vector)
    : x{ boost::numeric_cast<Real>(vector.GetX()) }, y{ boost::numeric_cast<Real>(vector.GetY()) }, z{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
template <typename RhsType>
Mathematics::Vector3<Real>::Vector3(const Vector3<RhsType>& vector)
    : x{ boost::numeric_cast<Real>(vector.GetX()) }, y{ boost::numeric_cast<Real>(vector.GetY()) }, z{ boost::numeric_cast<Real>(vector.GetZ()) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
template <typename RhsType>
Mathematics::Vector3<Real>::Vector3(const Vector4<RhsType>& vector)
    : x{ boost::numeric_cast<Real>(vector.GetX()) }, y{ boost::numeric_cast<Real>(vector.GetY()) }, z{ boost::numeric_cast<Real>(vector.GetZ()) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
bool Mathematics::operator==(const Vector3<Real>& lhs, const Vector3<Real>& rhs)
{
    return lhs.GetCoordinate() == rhs.GetCoordinate();
}

template <typename Real>
bool Mathematics::operator<(const Vector3<Real>& lhs, const Vector3<Real>& rhs) noexcept
{
    if (lhs.GetX() < rhs.GetX())
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
std::ostream& Mathematics::operator<<(std::ostream& outFile, const Vector3<Real>& vector)
{
    return outFile << "x=" << vector.GetX() << "　y=" << vector.GetY() << "　z=" << vector.GetZ();
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR3_DETAIL_H