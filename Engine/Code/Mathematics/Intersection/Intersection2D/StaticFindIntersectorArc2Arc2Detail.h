///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/27 17:26)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ARC2_ARC2_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ARC2_ARC2_DETAIL_H

#include "StaticFindIntersectorArc2Arc2.h"
#include "StaticFindIntersectorCircle2Circle2Detail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Intersection/StaticIntersectorDetail.h"
#include "Mathematics/Objects2D/Arc2Detail.h"

template <typename Real>
Mathematics::StaticFindIntersectorArc2Arc2<Real>::StaticFindIntersectorArc2Arc2(const Arc2& lhsArc, const Arc2& rhsArc, const Real epsilon)
    : ParentType{ epsilon }, lhsArc{ lhsArc }, rhsArc{ rhsArc }, point{}, intersectionArc{ lhsArc }
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
void Mathematics::StaticFindIntersectorArc2Arc2<Real>::Find()
{
    const Circle2 lhsCircle{ lhsArc.GetCenter(), lhsArc.GetRadius() };
    const Circle2 rhsCircle{ rhsArc.GetCenter(), rhsArc.GetRadius() };
    StaticFindIntersectorCircle2Circle2<Real> intersector{ lhsCircle, rhsCircle };
    if (!intersector.IsIntersection())
    {
        // Բ�����ཻ��
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    if (intersector.GetIntersectionType() == IntersectionType::Other)
    {
        // Բ����ͬ��Բ�� ȷ��Բ���Ƿ��ص���
        // ��m_LhsArcΪ<A0��A1>��m_RhsArcΪ<B0��B1>��
        // ��Χ��Բ����ʱ�����С�
        if (rhsArc.Contains(lhsArc.GetEnd0()))
        {
            if (rhsArc.Contains(lhsArc.GetEnd1()))
            {
                // m_LhsArc��m_RhsArc��, <B0,A0,A1,B1>.
                this->SetIntersectionType(IntersectionType::Other);
                intersectionArc = lhsArc;
            }
            else
            {
                if (!Vector2Tools::Approximate(lhsArc.GetEnd0(), rhsArc.GetEnd1(), this->GetEpsilon()))
                {
                    // m_LhsArc��m_RhsArc�ص�, <B0,A0,B1,A1>.
                    this->SetIntersectionType(IntersectionType::Other);
                    const Arc2 arc{ lhsArc.GetCenter(), lhsArc.GetRadius(), lhsArc.GetEnd0(), rhsArc.GetEnd1(), this->GetEpsilon() };
                    intersectionArc = arc;
                }
                else
                {
                    // m_LhsArc��m_RhsArc����˵� <B0,A0,B1,A1>, A0 = B1.
                    this->SetIntersectionType(IntersectionType::Point);
                    point.emplace_back((lhsArc.GetEnd0() + rhsArc.GetEnd1()) / MathType::GetValue(2));
                }
            }

            return;
        }

        if (rhsArc.Contains(lhsArc.GetEnd1()))
        {
            if (!Vector2Tools::Approximate(lhsArc.GetEnd1(), rhsArc.GetEnd0(), this->GetEpsilon()))
            {
                // m_LhsArc��m_RhsArc�ص�, <A0,B0,A1,B1>.
                this->SetIntersectionType(IntersectionType::Other);
                const Arc2 arc{ lhsArc.GetCenter(), lhsArc.GetRadius(), rhsArc.GetEnd0(), lhsArc.GetEnd1(), this->GetEpsilon() };
                intersectionArc = arc;
            }
            else
            {
                // m_LhsArc��m_RhsArc����˵㣬 <A0,B0,A1,B1>, B0 = A1.
                this->SetIntersectionType(IntersectionType::Point);
                point.emplace_back((rhsArc.GetEnd0() + lhsArc.GetEnd1()) / MathType::GetValue(2));
            }

            return;
        }

        if (lhsArc.Contains(rhsArc.GetEnd0()))
        {
            // m_RhsArc��m_LhsArc��, <A0,B0,B1,A1>.
            this->SetIntersectionType(IntersectionType::Other);
            intersectionArc = rhsArc;

            return;
        }
        else
        {
            // Բ�����ص� <A0,A1,B0,B1>.
            this->SetIntersectionType(IntersectionType::Empty);
            return;
        }
    }

    // ����Բ�����Ƿ��н��㡣
    for (auto i = 0; i < intersector.GetQuantity(); ++i)
    {
        if (lhsArc.Contains(intersector.GetPoint(i)) && rhsArc.Contains(intersector.GetPoint(i)))
        {
            point.emplace_back(intersector.GetPoint(i));
        }
    }

    this->SetIntersectionType(0 < GetQuantity() ? IntersectionType::Point : IntersectionType::Empty);
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticFindIntersectorArc2Arc2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Arc2<Real> Mathematics::StaticFindIntersectorArc2Arc2<Real>::GetLhsArc() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return lhsArc;
}

template <typename Real>
Mathematics::Arc2<Real> Mathematics::StaticFindIntersectorArc2Arc2<Real>::GetRhsArc() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return rhsArc;
}

template <typename Real>
int Mathematics::StaticFindIntersectorArc2Arc2<Real>::GetQuantity() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return boost::numeric_cast<int>(point.size());
}

template <typename Real>
Mathematics::Vector2<Real> Mathematics::StaticFindIntersectorArc2Arc2<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return point.at(index);
}

template <typename Real>
Mathematics::Arc2<Real> Mathematics::StaticFindIntersectorArc2Arc2<Real>::GetIntersectionArc() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (this->GetIntersectionType() == IntersectionType::Other)
    {
        return intersectionArc;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("Ҫ��ѯ��Բ���������ص��ġ�\n"s));
    }
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ARC2_ARC2_DETAIL_H
