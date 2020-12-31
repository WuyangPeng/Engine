///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/18 16:16)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ARC2_CIRCLE2_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ARC2_CIRCLE2_ACHIEVE_H

#include "StaticFindIntersectorArc2Circle2.h"
#include "StaticFindIntersectorCircle2Circle2Detail.h"
#include "Detail/StaticFindIntersectorArc2Circle2ImplDetail.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Intersection/StaticIntersectorDetail.h"
#include "Mathematics/Objects2D/Arc2Detail.h"

template <typename Real>
Mathematics::StaticFindIntersectorArc2Circle2<Real>::StaticFindIntersectorArc2Circle2(const Arc2& arc, const Circle2& circle, const Real epsilon)
    : ParentType{ epsilon }, m_Impl{ std::make_shared<ImplType>(arc, circle) }
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real>
void Mathematics::StaticFindIntersectorArc2Circle2<Real>::Find()
{
    const auto arc = GetArc();
    const auto circle = GetCircle();

    const Circle2 circleOfArc{ arc.GetCenter(), arc.GetRadius() };
    StaticFindIntersectorCircle2Circle2<Real> intersector{ circleOfArc, circle };

    if (!intersector.IsIntersection())
    {
        // 圆和圆弧不相交。
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    if (intersector.GetIntersectionType() == IntersectionType::Other)
    {
        // 圆弧在圆上。
        this->SetIntersectionType(IntersectionType::Other);
        return;
    }

    // 测试圆与圆的交点是否在圆弧上。
    for (auto i = 0; i < intersector.GetQuantity(); ++i)
    {
        if (arc.Contains(intersector.GetPoint(i)))
        {
            m_Impl->AddIntersection(intersector.GetPoint(i));
        }
    }

    this->SetIntersectionType(0 < m_Impl->GetQuantity() ? IntersectionType::Point : IntersectionType::Empty);
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticFindIntersectorArc2Circle2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid() && m_Impl != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Arc2<Real> Mathematics::StaticFindIntersectorArc2Circle2<Real>::GetArc() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetArc();
}

template <typename Real>
const Mathematics::Circle2<Real> Mathematics::StaticFindIntersectorArc2Circle2<Real>::GetCircle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetCircle();
}

template <typename Real>
int Mathematics::StaticFindIntersectorArc2Circle2<Real>::GetQuantity() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetQuantity();
}

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::StaticFindIntersectorArc2Circle2<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetPoint(index);
}

template <typename Real>
const Mathematics::Arc2<Real> Mathematics::StaticFindIntersectorArc2Circle2<Real>::GetIntersectionArc() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (this->GetIntersectionType() == IntersectionType::Other)
    {
        return m_Impl->GetIntersectionArc();
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("要查询的圆弧和圆并不是重叠的。\n"s));
    }
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ARC2_CIRCLE2_ACHIEVE_H
