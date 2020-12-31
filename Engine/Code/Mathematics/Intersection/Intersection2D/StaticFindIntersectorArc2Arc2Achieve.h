///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.6.0.0 (2020/12/18 15:07)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ARC2_ARC2_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ARC2_ARC2_ACHIEVE_H

#include "StaticFindIntersectorArc2Arc2.h"
#include "StaticFindIntersectorCircle2Circle2Detail.h"
#include "Detail/StaticFindIntersectorArc2Arc2ImplDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Intersection/StaticIntersectorDetail.h"
#include "Mathematics/Objects2D/Arc2Detail.h"

template <typename Real>
Mathematics::StaticFindIntersectorArc2Arc2<Real>::StaticFindIntersectorArc2Arc2(const Arc2& lhsArc, const Arc2& rhsArc, const Real epsilon)
    : ParentType{ epsilon }, m_Impl{ std::make_shared<ImplType>(lhsArc, rhsArc) }
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real>
void Mathematics::StaticFindIntersectorArc2Arc2<Real>::Find()
{
    const auto lhsArc = m_Impl->GetLhsArc();
    const auto rhsArc = m_Impl->GetRhsArc();

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
                m_Impl->SetIntersection(lhsArc);
            }
            else
            {
                if (!Vector2DTools::Approximate(lhsArc.GetEnd0(), rhsArc.GetEnd1(), this->GetEpsilon()))
                {
                    // m_LhsArc��m_RhsArc�ص�, <B0,A0,B1,A1>.
                    this->SetIntersectionType(IntersectionType::Other);
                    const Arc2 intersectionArc{ lhsArc.GetCenter(), lhsArc.GetRadius(), lhsArc.GetEnd0(), rhsArc.GetEnd1(), this->GetEpsilon() };
                    m_Impl->SetIntersection(intersectionArc);
                }
                else
                {
                    // m_LhsArc��m_RhsArc����˵� <B0,A0,B1,A1>, A0 = B1.
                    this->SetIntersectionType(IntersectionType::Point);
                    m_Impl->AddIntersection((lhsArc.GetEnd0() + rhsArc.GetEnd1()) / Math::GetValue(2));
                }
            }

            return;
        }

        if (rhsArc.Contains(lhsArc.GetEnd1()))
        {
            if (!Vector2DTools::Approximate(lhsArc.GetEnd1(), rhsArc.GetEnd0(), this->GetEpsilon()))
            {
                // m_LhsArc��m_RhsArc�ص�, <A0,B0,A1,B1>.
                this->SetIntersectionType(IntersectionType::Other);
                const Arc2 intersectionArc{ lhsArc.GetCenter(), lhsArc.GetRadius(), rhsArc.GetEnd0(), lhsArc.GetEnd1(), this->GetEpsilon() };

                m_Impl->SetIntersection(intersectionArc);
            }
            else
            {
                // m_LhsArc��m_RhsArc����˵㣬 <A0,B0,A1,B1>, B0 = A1.
                this->SetIntersectionType(IntersectionType::Point);
                m_Impl->AddIntersection((rhsArc.GetEnd0() + lhsArc.GetEnd1()) / Math::GetValue(2));
            }

            return;
        }

        if (lhsArc.Contains(rhsArc.GetEnd0()))
        {
            // m_RhsArc��m_LhsArc��, <A0,B0,B1,A1>.
            this->SetIntersectionType(IntersectionType::Other);
            m_Impl->SetIntersection(rhsArc);

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
            m_Impl->AddIntersection(intersector.GetPoint(i));
        }
    }

    this->SetIntersectionType(0 < m_Impl->GetQuantity() ? IntersectionType::Point : IntersectionType::Empty);
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
const Mathematics::Arc2<Real> Mathematics::StaticFindIntersectorArc2Arc2<Real>::GetLhsArc() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetLhsArc();
}

template <typename Real>
const Mathematics::Arc2<Real> Mathematics::StaticFindIntersectorArc2Arc2<Real>::GetRhsArc() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetRhsArc();
}

template <typename Real>
int Mathematics::StaticFindIntersectorArc2Arc2<Real>::GetQuantity() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetQuantity();
}

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::StaticFindIntersectorArc2Arc2<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetPoint(index);
}

template <typename Real>
const Mathematics::Arc2<Real> Mathematics::StaticFindIntersectorArc2Arc2<Real>::GetIntersectionArc() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (this->GetIntersectionType() == IntersectionType::Other)
    {
        return m_Impl->GetIntersectionArc();
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("Ҫ��ѯ��Բ���������ص��ġ�\n"s));
    }
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ARC2_ARC2_ACHIEVE_H
