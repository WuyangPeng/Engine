///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/01/31 3:54)

#ifndef MATHEMATICS_ALGEBRA_VECTOR2_DETAIL_H
#define MATHEMATICS_ALGEBRA_VECTOR2_DETAIL_H

#include "Vector2.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_VECTOR2_ACHIEVE)

    #include "Vector2Achieve.h"

#endif  // !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_VECTOR2_ACHIEVE)

#include <iostream>

template <typename Real>
template <typename RhsType>
Mathematics::Vector2<Real>::Vector2(const Vector2<RhsType>& vector)
    : m_X{ boost::numeric_cast<Real>(vector.GetX()) }, m_Y{ boost::numeric_cast<Real>(vector.GetY()) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
template <typename RhsType>
Mathematics::Vector2<Real>::Vector2(const Vector3<RhsType>& vector)
    : m_X{ boost::numeric_cast<Real>(vector.GetX()) }, m_Y{ boost::numeric_cast<Real>(vector.GetY()) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
template <typename RhsType>
Mathematics::Vector2<Real>::Vector2(const Vector4<RhsType>& vector)
    : m_X{ boost::numeric_cast<Real>(vector.GetX()) }, m_Y{ boost::numeric_cast<Real>(vector.GetY()) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
bool Mathematics::operator==(const Vector2<Real>& lhs, const Vector2<Real>& rhs)
{
    return lhs.GetCoordinate() == rhs.GetCoordinate();
}

template <typename Real>
bool Mathematics::operator<(const Vector2<Real>& lhs, const Vector2<Real>& rhs) noexcept
{
    if (lhs.GetX() < rhs.GetX())
        return true;
    else if (rhs.GetX() < lhs.GetX())
        return false;
    else
        return lhs.GetY() < rhs.GetY();
}

template <typename Real>
std::ostream& Mathematics::operator<<(std::ostream& outFile, const Vector2<Real>& vector)
{
    return outFile << "x=" << vector.GetX() << "　y=" << vector.GetY();
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR2_DETAIL_H
