///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/28 11:58)

#ifndef MATHEMATICS_INTERSECTION_TEST_INTERSECTOR_AXIS_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_TEST_INTERSECTOR_AXIS_ACHIEVE_H

#include "TestIntersectorAxis.h"
#include "Detail/TestIntersectorAxisImplDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::TestIntersectorAxis<Real>::TestIntersectorAxis(const Vector3D& axis, const SegmentType& segment, const Triangle3& triangle, const Vector3D& velocity, Real tmax)
    : m_Impl{ std::make_shared<ImplType>(axis, segment, triangle, velocity, tmax) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::TestIntersectorAxis<Real>::TestIntersectorAxis(const Vector3D& axis, const SegmentType& segment, const Box3& box, const Vector3D& velocity, Real tmax)
    : m_Impl{ std::make_shared<ImplType>(axis, segment, box, velocity, tmax) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::TestIntersectorAxis<Real>::TestIntersectorAxis(const Vector3D& axis, const Triangle3& triangle, const Box3& box, const Vector3D& velocity, Real tmax)
    : m_Impl{ std::make_shared<ImplType>(axis, triangle, box, velocity, tmax) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::TestIntersectorAxis<Real>::TestIntersectorAxis(const Vector3D& axis, const Box3& box0, const Box3& box1, const Vector3D& velocity, Real tmax)
    : m_Impl{ std::make_shared<ImplType>(axis, box0, box1, velocity, tmax) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::TestIntersectorAxis<Real>::IsValid() const noexcept
{
    return m_Impl != nullptr;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::TestIntersectorAxis<Real>::GetResult() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetResult();
}

template <typename Real>
Real Mathematics::TestIntersectorAxis<Real>::GetTFirst() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetTFirst();
}

template <typename Real>
Real Mathematics::TestIntersectorAxis<Real>::GetTLast() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetTLast();
}

#endif  // MATHEMATICS_INTERSECTION_TEST_INTERSECTOR_AXIS_ACHIEVE_H
