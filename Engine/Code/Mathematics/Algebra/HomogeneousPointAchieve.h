//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.0.0 (2020/08/25 23:38)

#ifndef MATHEMATICS_ALGEBRA_POINT_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_POINT_ACHIEVE_H

#include "HomogeneousPoint.h"
#include "System/Helper/EnumCast.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

#ifdef OPEN_CLASS_INVARIANT
template <typename T>
bool Mathematics::HomogeneousPoint<T>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename T>
const typename Mathematics::HomogeneousPoint<T>::ArrayType Mathematics::HomogeneousPoint<T>::GetCoordinate() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return ArrayType{ m_X, m_Y, m_Z, m_W };
}

template <typename T>
const T& Mathematics::HomogeneousPoint<T>::operator[](int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    switch (System::UnderlyingCastEnum<PointIndex>(index))
    {
    case PointIndex::X:
        return m_X;
    case PointIndex::Y:
        return m_Y;
    case PointIndex::Z:
        return m_Z;
    case PointIndex::W:
        return m_W;
    default:
        break;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("索引错误！"s));
}

template <typename T>
T& Mathematics::HomogeneousPoint<T>::operator[](int index)
{
    MATHEMATICS_CLASS_IS_VALID_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26492)
    return const_cast<T&>(static_cast<const ClassType&>(*this)[index]);
#include STSTEM_WARNING_POP
}

template <typename T>
T Mathematics::HomogeneousPoint<T>::GetX() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_X;
}

template <typename T>
void Mathematics::HomogeneousPoint<T>::SetX(T x) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_X = x;
}

template <typename T>
T Mathematics::HomogeneousPoint<T>::GetY() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Y;
}

template <typename T>
void Mathematics::HomogeneousPoint<T>::SetY(T y) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_Y = y;
}

template <typename T>
T Mathematics::HomogeneousPoint<T>::GetZ() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Z;
}

template <typename T>
void Mathematics::HomogeneousPoint<T>::SetZ(T z) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_Z = z;
}

template <typename T>
T Mathematics::HomogeneousPoint<T>::GetW() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_W;
}

template <typename T>
void Mathematics::HomogeneousPoint<T>::SetW(T w) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_W = w;
}

#endif  //  MATHEMATICS_ALGEBRA_POINT_ACHIEVE_H