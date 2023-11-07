///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 17:53)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_BOX2_BOX2_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_BOX2_BOX2_DETAIL_H

#include "StaticTestIntersectorBox2Box2.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Intersection/StaticIntersectorDetail.h"
#include "Mathematics/Objects2D/Box2Detail.h"

template <typename Real>
Mathematics::StaticTestIntersectorBox2Box2<Real>::StaticTestIntersectorBox2Box2(const Box2& lhsBox, const Box2& rhsBox, const Real epsilon)
    : ParentType{ epsilon }, lhsBox{ lhsBox }, rhsBox{ rhsBox }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
void Mathematics::StaticTestIntersectorBox2Box2<Real>::Test()
{
    // 计算盒中心的距离，D = C1 - C0。
    auto boxCentersDifference = rhsBox.GetCenter() - lhsBox.GetCenter();

    // 轴 C0 + t * A0
    auto absLhs0DotRhs0 = Math::FAbs(Vector2Tools::DotProduct(lhsBox.GetAxis0(), rhsBox.GetAxis0()));
    auto absLhs0DotRhs1 = Math::FAbs(Vector2Tools::DotProduct(lhsBox.GetAxis0(), rhsBox.GetAxis1()));

    auto absLhs0DotDifference = Math::FAbs(Vector2Tools::DotProduct(lhsBox.GetAxis0(), boxCentersDifference));
    auto sum = lhsBox.GetExtent0() + rhsBox.GetExtent0() * absLhs0DotRhs0 + rhsBox.GetExtent1() * absLhs0DotRhs1;

    if (sum < absLhs0DotDifference)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // 轴 C0 + t * A1
    auto absLhs1DotRhs0 = Math::FAbs(Vector2Tools::DotProduct(lhsBox.GetAxis1(), rhsBox.GetAxis0()));
    auto absLhs1DotRhs1 = Math::FAbs(Vector2Tools::DotProduct(lhsBox.GetAxis1(), rhsBox.GetAxis1()));

    auto absLhs1DotDifference = Math::FAbs(Vector2Tools::DotProduct(lhsBox.GetAxis1(), boxCentersDifference));

    sum = lhsBox.GetExtent1() + rhsBox.GetExtent0() * absLhs1DotRhs0 + rhsBox.GetExtent1() * absLhs1DotRhs1;

    if (sum < absLhs1DotDifference)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // 轴 C0 + t * B0
    auto absRhs0DotDifference = Math::FAbs(Vector2Tools::DotProduct(rhsBox.GetAxis0(), boxCentersDifference));

    sum = rhsBox.GetExtent0() + lhsBox.GetExtent0() * absLhs0DotRhs0 + lhsBox.GetExtent1() * absLhs1DotRhs0;

    if (sum < absRhs0DotDifference)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    // 轴 C0 + t * B1
    auto absRhs1DotDifference = Math::FAbs(Vector2Tools::DotProduct(rhsBox.GetAxis1(), boxCentersDifference));
    sum = rhsBox.GetExtent1() + lhsBox.GetExtent0() * absLhs0DotRhs1 + lhsBox.GetExtent1() * absLhs1DotRhs1;

    if (sum < absRhs1DotDifference)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    this->SetIntersectionType(IntersectionType::Other);
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticTestIntersectorBox2Box2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Box2<Real> Mathematics::StaticTestIntersectorBox2Box2<Real>::GetLhsBox() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return lhsBox;
}

template <typename Real>
Mathematics::Box2<Real> Mathematics::StaticTestIntersectorBox2Box2<Real>::GetRhsBox() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return rhsBox;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_BOX2_BOX2_DETAIL_H
