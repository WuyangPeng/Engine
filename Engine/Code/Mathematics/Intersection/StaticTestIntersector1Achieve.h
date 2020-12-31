///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.6.0.0 (2020/12/16 14:56)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR1_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR1_ACHIEVE_H

#include "Intersector1Detail.h"
#include "StaticTestIntersector1.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticTestIntersector1<Real>::StaticTestIntersector1(Real u0, Real u1, Real v0, Real v1, const Real epsilon) noexcept
    : ParentType{ u0, u1, v0, v1, epsilon }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticTestIntersector1<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticTestIntersector1<Real>::IsIntersection() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return (this->GetU(0) - this->GetEpsilon() <= this->GetV(1)) && (this->GetV(0) - this->GetEpsilon() <= this->GetU(1));
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR1_ACHIEVE_H
