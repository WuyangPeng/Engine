///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/05 10:51)

// 轴对齐包围盒4D类的实现
#ifndef MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX_4D_DETAIL_H
#define MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX_4D_DETAIL_H

#include "AxesAlignBoundingBox4D.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_AXES_ALIGN_BOUNDING_BOX_4D_ACHIEVE)

    #include "AxesAlignBoundingBox4DAchieve.h"

#endif  // !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_AXES_ALIGN_BOUNDING_BOX_4D_ACHIEVE)

template <typename T>
template <typename RhsType>
Mathematics::AxesAlignBoundingBox4D<T>::AxesAlignBoundingBox4D(const AxesAlignBoundingBox4D<RhsType>& aabb)
    : m_MinPoint{ aabb.GetMinPoint() }, m_MaxPoint{ aabb.GetMaxPoint() }
{
    Recalculate();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#endif  // MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX_4D_DETAIL_H