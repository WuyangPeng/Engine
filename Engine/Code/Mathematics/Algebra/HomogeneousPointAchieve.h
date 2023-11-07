///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 10:25)

#ifndef MATHEMATICS_ALGEBRA_POINT_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_POINT_ACHIEVE_H

#include "HomogeneousPoint.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#ifdef OPEN_CLASS_INVARIANT

template <typename T>
requires std::is_arithmetic_v<T> bool Mathematics::HomogeneousPoint<T>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename T>
requires std::is_arithmetic_v<T>
typename Mathematics::HomogeneousPoint<T>::ArrayType Mathematics::HomogeneousPoint<T>::GetCoordinate() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return ArrayType{ x, y, z, w };
}

template <typename T>
requires std::is_arithmetic_v<T>
const T& Mathematics::HomogeneousPoint<T>::operator[](int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    switch (index)
    {
        case xIndex:
            return x;
        case yIndex:
            return y;
        case zIndex:
            return z;
        case wIndex:
            return w;
        default:
            break;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("索引错误！"s))
}

template <typename T>
requires std::is_arithmetic_v<T>
T& Mathematics::HomogeneousPoint<T>::operator[](int index)
{
    MATHEMATICS_CLASS_IS_VALID_9;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26492)

    return const_cast<T&>(static_cast<const ClassType&>(*this)[index]);

#include SYSTEM_WARNING_POP
}

template <typename T>
requires std::is_arithmetic_v<T>
T Mathematics::HomogeneousPoint<T>::GetX() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return x;
}

template <typename T>
requires std::is_arithmetic_v<T>
void Mathematics::HomogeneousPoint<T>::SetX(T aX) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    x = aX;
}

template <typename T>
requires std::is_arithmetic_v<T>
T Mathematics::HomogeneousPoint<T>::GetY() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return y;
}

template <typename T>
requires std::is_arithmetic_v<T>
void Mathematics::HomogeneousPoint<T>::SetY(T aY) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    y = aY;
}

template <typename T>
requires std::is_arithmetic_v<T>
T Mathematics::HomogeneousPoint<T>::GetZ() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return z;
}

template <typename T>
requires std::is_arithmetic_v<T>
void Mathematics::HomogeneousPoint<T>::SetZ(T aZ) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    z = aZ;
}

template <typename T>
requires std::is_arithmetic_v<T>
T Mathematics::HomogeneousPoint<T>::GetW() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return w;
}

template <typename T>
requires std::is_arithmetic_v<T>
void Mathematics::HomogeneousPoint<T>::SetW(T aW) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    w = aW;
}

template <typename T>
requires std::is_arithmetic_v<T>
void Mathematics::HomogeneousPoint<T>::Set(const ArrayType& coordinate)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    SetX(coordinate.at(xIndex));
    SetY(coordinate.at(yIndex));
    SetZ(coordinate.at(zIndex));
    SetW(coordinate.at(wIndex));
}

#endif  //  MATHEMATICS_ALGEBRA_POINT_ACHIEVE_H