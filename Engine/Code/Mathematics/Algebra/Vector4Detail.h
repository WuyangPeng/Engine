///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/02/01 22:13)

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
template <typename RhsType>
Mathematics::Vector4<Real>::Vector4(const Vector2<RhsType>& vector)
    : m_X{ boost::numeric_cast<Real>(vector.GetX()) }, m_Y{ boost::numeric_cast<Real>(vector.GetY()) }, m_Z{}, m_W{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
template <typename RhsType>
Mathematics::Vector4<Real>::Vector4(const Vector3<RhsType>& vector)
    : m_X{ boost::numeric_cast<Real>(vector.GetX()) }, m_Y{ boost::numeric_cast<Real>(vector.GetY()) }, m_Z{ boost::numeric_cast<Real>(vector.GetZ()) }, m_W{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
template <typename RhsType>
Mathematics::Vector4<Real>::Vector4(const Vector4<RhsType>& vector)
    : m_X{ boost::numeric_cast<Real>(vector.GetX()) }, m_Y{ boost::numeric_cast<Real>(vector.GetY()) }, m_Z{ boost::numeric_cast<Real>(vector.GetZ()) }, m_W{ boost::numeric_cast<Real>(vector.GetW()) }
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