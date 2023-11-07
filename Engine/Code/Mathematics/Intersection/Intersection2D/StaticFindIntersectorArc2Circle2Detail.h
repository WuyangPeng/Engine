///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/27 17:26)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ARC2_CIRCLE2_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ARC2_CIRCLE2_DETAIL_H

#include "StaticFindIntersectorArc2Circle2.h"
#include "StaticFindIntersectorCircle2Circle2Detail.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Intersection/StaticIntersectorDetail.h"
#include "Mathematics/Objects2D/Arc2Detail.h"

template <typename Real>
Mathematics::StaticFindIntersectorArc2Circle2<Real>::StaticFindIntersectorArc2Circle2(const Arc2& arc, const Circle2& circle, const Real epsilon)
    : ParentType{ epsilon }, arc{ arc }, circle{ circle }, point{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
void Mathematics::StaticFindIntersectorArc2Circle2<Real>::Find()
{
    const Circle2 circleOfArc{ arc.GetCenter(), arc.GetRadius() };
    StaticFindIntersectorCircle2Circle2<Real> intersector{ circleOfArc, circle };

    if (!intersector.IsIntersection())
    {
        // Բ��Բ�����ཻ��
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    if (intersector.GetIntersectionType() == IntersectionType::Other)
    {
        // Բ����Բ�ϡ�
        this->SetIntersectionType(IntersectionType::Other);
        return;
    }

    // ����Բ��Բ�Ľ����Ƿ���Բ���ϡ�
    for (auto i = 0; i < intersector.GetQuantity(); ++i)
    {
        if (arc.Contains(intersector.GetPoint(i)))
        {
            point.emplace_back(intersector.GetPoint(i));
        }
    }

    this->SetIntersectionType(0 < GetQuantity() ? IntersectionType::Point : IntersectionType::Empty);
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticFindIntersectorArc2Circle2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Arc2<Real> Mathematics::StaticFindIntersectorArc2Circle2<Real>::GetArc() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return arc;
}

template <typename Real>
Mathematics::Circle2<Real> Mathematics::StaticFindIntersectorArc2Circle2<Real>::GetCircle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return circle;
}

template <typename Real>
int Mathematics::StaticFindIntersectorArc2Circle2<Real>::GetQuantity() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return boost::numeric_cast<int>(point.size());
}

template <typename Real>
Mathematics::Vector2<Real> Mathematics::StaticFindIntersectorArc2Circle2<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return point.at(index);
}

template <typename Real>
Mathematics::Arc2<Real> Mathematics::StaticFindIntersectorArc2Circle2<Real>::GetIntersectionArc() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (this->GetIntersectionType() == IntersectionType::Other)
    {
        return arc;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("Ҫ��ѯ��Բ����Բ�������ص��ġ�\n"s));
    }
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ARC2_CIRCLE2_DETAIL_H
