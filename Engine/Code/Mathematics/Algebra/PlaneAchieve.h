///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/07 14:09)

#ifndef MATHEMATICS_ALGEBRA_PLANE_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_PLANE_ACHIEVE_H

#include "APointDetail.h"
#include "AVectorDetail.h"
#include "Plane.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <typename T>
Mathematics::Plane<T>::Plane(const T epsilon) noexcept
    : homogeneousPoint{ Math::GetValue(1), Math::GetValue(0), Math::GetValue(0), Math::GetValue(0) }, epsilon{ epsilon }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename T>
Mathematics::Plane<T>::Plane() noexcept
    : Plane{ Math::GetZeroTolerance() }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename T>
Mathematics::Plane<T>::Plane(T normalX, T normalY, T normalZ, T constant, const T epsilon)
    : homogeneousPoint{ normalX, normalY, normalZ, -constant }, epsilon{ epsilon }
{
    Normalize();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename T>
Mathematics::Plane<T>::Plane(const AVector& normal, T constant, const T epsilon) noexcept
    : homogeneousPoint{ normal.GetX(), normal.GetY(), normal.GetZ(), -constant }, epsilon{ epsilon }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename T>
Mathematics::Plane<T>::Plane(const AVector& normal, const APoint& point, const T epsilon) noexcept
    : homogeneousPoint{ normal.GetX(), normal.GetY(), normal.GetZ(), -Dot(point, normal) }, epsilon{ epsilon }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename T>
Mathematics::Plane<T>::Plane(const APoint& lhs, const APoint& mhs, const APoint& rhs, const T epsilon)
    : homogeneousPoint{}, epsilon{ epsilon }
{
    const auto edge1 = mhs - lhs;
    const auto edge2 = rhs - lhs;
    const auto normal = UnitCross(edge1, edge2, epsilon);
    homogeneousPoint = HomogeneousPoint{ normal.GetX(), normal.GetY(), normal.GetZ(), -Dot(lhs, normal) };

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename T>
Mathematics::Plane<T>::Plane(const HomogeneousPoint& homogeneousPoint, const T epsilon)
    : homogeneousPoint{ homogeneousPoint }, epsilon{ epsilon }
{
    Normalize();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename T>
void Mathematics::Plane<T>::Normalize()
{
    const auto length = GetNormal().Length();

    if (epsilon < length)
    {
        for (auto i = 0; i < planeSize; ++i)
        {
            homogeneousPoint[i] /= length;
        }
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("除零错误。"s));
    }
}

#ifdef OPEN_CLASS_INVARIANT

template <typename T>
bool Mathematics::Plane<T>::IsValid() const noexcept
{
    try
    {
        const AVector normal{ homogeneousPoint.GetX(), homogeneousPoint.GetY(), homogeneousPoint.GetZ() };

        return normal.IsNormalize(epsilon);
    }
    catch (...)
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

template <typename T>
Mathematics::HomogeneousPoint<T> Mathematics::Plane<T>::GetHomogeneousPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return homogeneousPoint;
}

template <typename T>
const T& Mathematics::Plane<T>::operator[](int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return homogeneousPoint[index];
}

template <typename T>
T& Mathematics::Plane<T>::operator[](int index)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    return OPERATOR_SQUARE_BRACKETS(T, index);
}

template <typename T>
void Mathematics::Plane<T>::SetNormal(const AVector& normal) noexcept(gAssert < 2 || gMathematicsAssert < 2)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    MATHEMATICS_ASSERTION_2(normal.IsNormalize(epsilon), "传入的向量不是单位向量！");

    homogeneousPoint.SetX(normal.GetX());
    homogeneousPoint.SetY(normal.GetY());
    homogeneousPoint.SetZ(normal.GetZ());
}

template <typename T>
void Mathematics::Plane<T>::SetConstant(T constant) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    homogeneousPoint.SetW(-constant);
}

template <typename T>
void Mathematics::Plane<T>::SetEpsilon(T newEpsilon) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_1;

    epsilon = newEpsilon;
}

template <typename T>
T Mathematics::Plane<T>::GetEpsilon() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return epsilon;
}

template <typename T>
Mathematics::AVector<T> Mathematics::Plane<T>::GetNormal() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return AVector{ homogeneousPoint.GetX(), homogeneousPoint.GetY(), homogeneousPoint.GetZ() };
}

template <typename T>
T Mathematics::Plane<T>::GetConstant() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return -homogeneousPoint.GetW();
}

template <typename T>
T Mathematics::Plane<T>::DistanceTo(const APoint& point) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return homogeneousPoint.GetX() * point.GetX() + homogeneousPoint.GetY() * point.GetY() + homogeneousPoint.GetZ() * point.GetZ() + homogeneousPoint.GetW();
}

template <typename T>
Mathematics::NumericalValueSymbol Mathematics::Plane<T>::WhichSide(const APoint& point) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    auto distance = DistanceTo(point);

    if (distance < -epsilon)
    {
        return NumericalValueSymbol::Negative;
    }
    else if (epsilon < distance)
    {
        return NumericalValueSymbol::Positive;
    }
    else
    {
        return NumericalValueSymbol::Zero;
    }
}

#endif  // MATHEMATICS_ALGEBRA_PLANE_ACHIEVE_H
