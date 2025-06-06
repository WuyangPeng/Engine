///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/26 10:13)

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
Mathematics::APoint<T>::APoint(const Vector3Type& rhs) noexcept
    : APoint{ rhs.GetX(), rhs.GetY(), rhs.GetZ() }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename T>
requires std::is_arithmetic_v<T>
Mathematics::APoint<T>::APoint(const ArrayType& rhs)
    : APoint{ rhs.at(HomogeneousPointType::xIndex), rhs.at(HomogeneousPointType::yIndex), rhs.at(HomogeneousPointType::zIndex) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename T>
requires std::is_arithmetic_v<T> bool Mathematics::APoint<T>::IsValid() const noexcept
{
    if (MathType::FAbs(homogeneousPoint.GetW() - MathType::GetValue(1)) <= MathType::GetZeroTolerance())
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

    return Vector3Type{ GetX(), GetY(), GetZ() };
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
Mathematics::APoint<T>& Mathematics::APoint<T>::operator+=(const AVectorType& rhs)
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
Mathematics::APoint<T>& Mathematics::APoint<T>::operator-=(const AVectorType& rhs)
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

    if (MathType::GetZeroTolerance() < MathType::FAbs(scalar))
    {
        auto invScalar = MathType::GetValue(1) / scalar;

        *this *= invScalar;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("�������"s))
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

    const auto xFAbs = MathType::FAbs(GetX());
    const auto yFAbs = MathType::FAbs(GetY());
    const auto zFAbs = MathType::FAbs(GetZ());

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
    SetX(coordinate.at(HomogeneousPointType::xIndex));
    SetY(coordinate.at(HomogeneousPointType::yIndex));
    SetZ(coordinate.at(HomogeneousPointType::zIndex));
}

#endif  //  MATHEMATICS_ALGEBRA_A_POINT_ACHIEVE_H
