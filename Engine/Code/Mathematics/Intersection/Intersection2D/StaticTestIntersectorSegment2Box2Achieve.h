///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/23 19:21)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT2_BOX2_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT2_BOX2_ACHIEVE_H

#include "StaticTestIntersectorLine2Box2.h"
#include "StaticTestIntersectorSegment2Box2.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticTestIntersectorSegment2Box2<Real>::StaticTestIntersectorSegment2Box2(const Segment2& segment, const Box2& box, bool solid, const Real dotThreshold)
    : ParentType{ dotThreshold }, m_Segment{ segment }, m_Box{ box }, m_Solid{ solid }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticTestIntersectorSegment2Box2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Segment2<Real> Mathematics::StaticTestIntersectorSegment2Box2<Real>::GetSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Segment;
}

template <typename Real>
const Mathematics::Box2<Real> Mathematics::StaticTestIntersectorSegment2Box2<Real>::GetBox() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Box;
}

template <typename Real>
void Mathematics::StaticTestIntersectorSegment2Box2<Real>::Test()
{
    auto diff = m_Segment.GetCenterPoint() - m_Box.GetCenter();

    Vector2D directionDotBox{};
    Vector2D diffDotBox{};

    directionDotBox[0] = Math::FAbs(Vector2DTools::DotProduct(m_Segment.GetDirection(), m_Box.GetAxis0()));
    diffDotBox[0] = Math::FAbs(Vector2DTools::DotProduct(diff, m_Box.GetAxis0()));
    auto rhs = m_Box.GetExtent0() + m_Segment.GetExtent() * directionDotBox[0];
    if (rhs < diffDotBox[0])
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    directionDotBox[1] = Math::FAbs(Vector2DTools::DotProduct(m_Segment.GetDirection(), m_Box.GetAxis1()));
    diffDotBox[1] = Math::FAbs(Vector2DTools::DotProduct(diff, m_Box.GetAxis1()));
    rhs = m_Box.GetExtent1() + m_Segment.GetExtent() * directionDotBox[1];
    if (rhs < diffDotBox[1])
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    const auto perp = Vector2DTools::GetPerp(m_Segment.GetDirection());
    auto lhs = Math::FAbs(Vector2DTools::DotProduct(perp, diff));
    auto part0 = Math::FAbs(Vector2DTools::DotProduct(perp, m_Box.GetAxis0()));
    auto part1 = Math::FAbs(Vector2DTools::DotProduct(perp, m_Box.GetAxis1()));
    rhs = m_Box.GetExtent0() * part0 + m_Box.GetExtent1() * part1;
    if (lhs <= rhs)
    {
        this->SetIntersectionType(IntersectionType::Point);
    }
    else
    {
        this->SetIntersectionType(IntersectionType::Empty);
    }
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SEGMENT2_BOX2_ACHIEVE_H