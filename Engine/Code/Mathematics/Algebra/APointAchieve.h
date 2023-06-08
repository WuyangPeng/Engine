///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/05/31 13:56)

#ifndef MATHEMATICS_ALGEBRA_A_POINT_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_A_POINT_ACHIEVE_H

#include "APoint.h"
#include "AVectorDetail.h"
#include "Vector3.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/TemplateTools/MaxElement.h"

template <typename T>
requires std::is_arithmetic_v<T>
Mathematics::APoint<T>::APoint(const Vector3& rhs) noexcept
    : APoint{ rhs.GetX(), rhs.GetY(), rhs.GetZ() }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename T>
requires std::is_arithmetic_v<T>
Mathematics::APoint<T>::APoint(const ArrayType& rhs)
    : APoint{ rhs.at(HomogeneousPoint::xIndex), rhs.at(HomogeneousPoint::yIndex), rhs.at(HomogeneousPoint::zIndex) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename T>
requires std::is_arithmetic_v<T> bool Mathematics::APoint<T>::IsValid() const noexcept
{
    if (Math::FAbs(homogeneousPoint.GetW() - Math::GetValue(1)) <= Math::GetZeroTolerance())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename T>
requires std::is_arithmetic_v<T>
Mathematics::Vector3<T> Mathematics::APoint<T>::GetVector3() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return Vector3{ GetX(), GetY(), GetZ() };
}

template <typename T>
requires std::is_arithmetic_v<T>
Mathematics::HomogeneousPoint<T> Mathematics::APoint<T>::GetHomogeneousPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return homogeneousPoint;
}

template <typename T>
requires std::is_arithmetic_v<T>
const T& Mathematics::APoint<T>::operator[](int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return homogeneousPoint[index];
}

template <typename T>
requires std::is_arithmetic_v<T>
T& Mathematics::APoint<T>::operator[](int index)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    return OPERATOR_SQUARE_BRACKETS(T, index);
}

template <typename T>
requires std::is_arithmetic_v<T>
T Mathematics::APoint<T>::GetX() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return homogeneousPoint.GetX();
}

template <typename T>
requires std::is_arithmetic_v<T>
void Mathematics::APoint<T>::SetX(T x) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    homogeneousPoint.SetX(x);
}

template <typename T>
requires std::is_arithmetic_v<T>
T Mathematics::APoint<T>::GetY() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return homogeneousPoint.GetY();
}

template <typename T>
requires std::is_arithmetic_v<T>
void Mathematics::APoint<T>::SetY(T y) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    homogeneousPoint.SetY(y);
}

template <typename T>
requires std::is_arithmetic_v<T>
T Mathematics::APoint<T>::GetZ() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return homogeneousPoint.GetZ();
}

template <typename T>
requires std::is_arithmetic_v<T>
void Mathematics::APoint<T>::SetZ(T z) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    homogeneousPoint.SetZ(z);
}

template <typename T>
requires std::is_arithmetic_v<T>
Mathematics::APoint<T>& Mathematics::APoint<T>::operator+=(const AVector& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    for (auto i = 0; i < pointSize; ++i)
    {
        homogeneousPoint[i] += rhs[i];
    }

    return *this;
}

template <typename T>
requires std::is_arithmetic_v<T>
Mathematics::APoint<T>& Mathematics::APoint<T>::operator-=(const AVector& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    for (auto i = 0; i < pointSize; ++i)
    {
        homogeneousPoint[i] -= rhs[i];
    }

    return *this;
}

template <typename T>
requires std::is_arithmetic_v<T>
Mathematics::APoint<T>& Mathematics::APoint<T>::operator+=(const APoint& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    for (auto i = 0; i < pointSize; ++i)
    {
        homogeneousPoint[i] += rhs[i];
    }

    return *this;
}

template <typename T>
requires std::is_arithmetic_v<T>
Mathematics::APoint<T>& Mathematics::APoint<T>::operator-=(const APoint& rhs)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    for (auto i = 0; i < pointSize; ++i)
    {
        homogeneousPoint[i] -= rhs[i];
    }

    return *this;
}

template <typename T>
requires std::is_arithmetic_v<T>
Mathematics::APoint<T>& Mathematics::APoint<T>::operator*=(T scalar)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    for (auto i = 0; i < pointSize; ++i)
    {
        homogeneousPoint[i] *= scalar;
    }

    return *this;
}

template <typename T>
requires std::is_arithmetic_v<T>
Mathematics::APoint<T>& Mathematics::APoint<T>::operator/=(T scalar)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    if (Math::GetZeroTolerance() < Math::FAbs(scalar))
    {
        auto invScalar = Math::GetValue(1) / scalar;

        *this *= invScalar;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("除零错误。"s))
    }

    return *this;
}

template <typename T>
requires std::is_arithmetic_v<T>
Mathematics::APoint<T> Mathematics::APoint<T>::operator-() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return APoint{ -homogeneousPoint.GetX(), -homogeneousPoint.GetY(), -homogeneousPoint.GetZ() };
}

template <typename T>
requires std::is_arithmetic_v<T>
T Mathematics::APoint<T>::GetNorm() const  
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto xFAbs = Math::FAbs(GetX());
    const auto yFAbs = Math::FAbs(GetY());
    const auto zFAbs = Math::FAbs(GetZ());

    return CoreTools::MaxElement({ xFAbs, yFAbs, zFAbs });
}

template <typename T>
requires std::is_arithmetic_v<T>
typename Mathematics::APoint<T>::ArrayType Mathematics::APoint<T>::GetCoordinate() const noexcept
{
    return ArrayType{ GetX(), GetY(), GetZ() };
}

template <typename T>
requires std::is_arithmetic_v<T>
void Mathematics::APoint<T>::Set(const ArrayType& coordinate)
{
    SetX(coordinate.at(HomogeneousPoint::xIndex));
    SetY(coordinate.at(HomogeneousPoint::yIndex));
    SetZ(coordinate.at(HomogeneousPoint::zIndex));
}

#endif  //  MATHEMATICS_ALGEBRA_A_POINT_ACHIEVE_H
