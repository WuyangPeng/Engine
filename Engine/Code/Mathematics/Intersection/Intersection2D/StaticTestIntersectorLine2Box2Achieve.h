///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/23 13:59)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_BOX2_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_BOX2_ACHIEVE_H

#include "StaticTestIntersectorLine2Box2.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"

template <typename Real>
Mathematics::StaticTestIntersectorLine2Box2<Real>::StaticTestIntersectorLine2Box2(const Line2& line, const Box2& box, const Real epsilon)
    : ParentType{ epsilon }, m_Line{ line }, m_Box{ box }
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
const Mathematics::Line2<Real> Mathematics::StaticTestIntersectorLine2Box2<Real>::GetLine() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Line;
}

template <typename Real>
const Mathematics::Box2<Real> Mathematics::StaticTestIntersectorLine2Box2<Real>::GetBox() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Box;
}

template <typename Real>
void Mathematics::StaticTestIntersectorLine2Box2<Real>::Test()
{
    auto diff = m_Line.GetOrigin() - m_Box.GetCenter();
    const auto perp = Vector2DTools::GetPerp(m_Line.GetDirection());
    auto lhs = Math::FAbs(Vector2DTools::DotProduct(perp, diff));
    auto part0 = Math::FAbs(Vector2DTools::DotProduct(perp, m_Box.GetAxis0()));
    auto part1 = Math::FAbs(Vector2DTools::DotProduct(perp, m_Box.GetAxis1()));
    auto rhs = m_Box.GetExtent0() * part0 + m_Box.GetExtent1() * part1;
    if (lhs <= rhs)
    {
        this->SetIntersectionType(IntersectionType::Point);
    }
    else
    {
        this->SetIntersectionType(IntersectionType::Empty);
    }
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE2_BOX2_ACHIEVE_H