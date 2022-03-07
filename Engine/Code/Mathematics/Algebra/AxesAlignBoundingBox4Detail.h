///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/02 22:43)

#ifndef MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX4_DETAIL_H
#define MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX4_DETAIL_H

#include "AxesAlignBoundingBox4.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_AXES_ALIGN_BOUNDING_BOX4_ACHIEVE)

    #include "AxesAlignBoundingBox4Achieve.h"

#endif  // !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_AXES_ALIGN_BOUNDING_BOX4_ACHIEVE)

template <typename T>
template <typename RhsType>
Mathematics::AxesAlignBoundingBox4<T>::AxesAlignBoundingBox4(const AxesAlignBoundingBox4<RhsType>& aabb)
    : minPoint{ aabb.GetMinPoint() }, maxPoint{ aabb.GetMaxPoint() }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#endif  // MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX4_DETAIL_H