///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.2 (2020/11/05 10:51)

// ������Χ��4D���ʵ��
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