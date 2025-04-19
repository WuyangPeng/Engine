///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 10:19)

#ifndef MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX4_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX4_ACHIEVE_H

#include "AxesAlignBoundingBox4.h"
#include "Vector4Detail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename T>
requires std::is_arithmetic_v<T>
Mathematics::AxesAlignBoundingBox4<T>::AxesAlignBoundingBox4(const Vector4Type& minPoint, const Vector4Type& maxPoint) noexcept
    : minPoint{ minPoint }, maxPoint{ maxPoint }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename T>
requires std::is_arithmetic_v<T> bool Mathematics::AxesAlignBoundingBox4<T>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename T>
requires std::is_arithmetic_v<T> bool Mathematics::AxesAlignBoundingBox4<T>::IsBoxValid() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (maxPoint.GetX() < minPoint.GetX() ||
        maxPoint.GetY() < minPoint.GetY() ||
        maxPoint.GetZ() < minPoint.GetZ() ||
        maxPoint.GetW() < minPoint.GetW())
    {
        return false;
    }
    else
    {
        return true;
    }
}

template <typename T>
requires std::is_arithmetic_v<T>
Mathematics::Vector4<T> Mathematics::AxesAlignBoundingBox4<T>::GetMinPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return minPoint;
}

template <typename T>
requires std::is_arithmetic_v<T>
Mathematics::Vector4<T> Mathematics::AxesAlignBoundingBox4<T>::GetMaxPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return maxPoint;
}

#endif  // MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX4_ACHIEVE_H