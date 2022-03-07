///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/02/02 22:42)

#ifndef MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX4_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX4_ACHIEVE_H

#include "AxesAlignBoundingBox4.h"
#include "Vector4Detail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename T>
Mathematics::AxesAlignBoundingBox4<T>::AxesAlignBoundingBox4(const Vector4& minPoint, const Vector4& maxPoint) noexcept
    : minPoint{ minPoint }, maxPoint{ maxPoint }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename T>
bool Mathematics::AxesAlignBoundingBox4<T>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename T>
bool Mathematics::AxesAlignBoundingBox4<T>::IsBoxValid() const noexcept
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
Mathematics::Vector4<T> Mathematics::AxesAlignBoundingBox4<T>::GetMinPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return minPoint;
}

template <typename T>
Mathematics::Vector4<T> Mathematics::AxesAlignBoundingBox4<T>::GetMaxPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return maxPoint;
}

#endif  // MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX4_ACHIEVE_H