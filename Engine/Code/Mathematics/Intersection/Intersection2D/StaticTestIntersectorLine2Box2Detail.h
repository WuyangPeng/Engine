///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 19:28)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_BOX2_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_BOX2_DETAIL_H

#include "StaticTestIntersectorLine2Box2.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"

template <typename Real>
Mathematics::StaticTestIntersectorLine2Box2<Real>::StaticTestIntersectorLine2Box2(const Line2& line, const Box2& box, const Real epsilon)
    : ParentType{ epsilon }, line{ line }, box{ box }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticTestIntersectorLine2Box2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Line2<Real> Mathematics::StaticTestIntersectorLine2Box2<Real>::GetLine() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return line;
}

template <typename Real>
Mathematics::Box2<Real> Mathematics::StaticTestIntersectorLine2Box2<Real>::GetBox() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return box;
}

template <typename Real>
void Mathematics::StaticTestIntersectorLine2Box2<Real>::Test()
{
    const auto diff = line.GetOrigin() - box.GetCenter();
    const auto perp = Vector2Tools::GetPerp(line.GetDirection());
    const auto lhs = Math::FAbs(Vector2Tools::DotProduct(perp, diff));
    const auto part0 = Math::FAbs(Vector2Tools::DotProduct(perp, box.GetAxis0()));
    const auto part1 = Math::FAbs(Vector2Tools::DotProduct(perp, box.GetAxis1()));
    const auto rhs = box.GetExtent0() * part0 + box.GetExtent1() * part1;

    if (lhs <= rhs)
    {
        this->SetIntersectionType(IntersectionType::Point);
    }
    else
    {
        this->SetIntersectionType(IntersectionType::Empty);
    }
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_BOX2_DETAIL_H