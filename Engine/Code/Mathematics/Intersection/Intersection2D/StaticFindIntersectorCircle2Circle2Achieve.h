///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.6.0.0 (2020/12/18 16:50)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_CIRCLE2_CIRCLE2_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_CIRCLE2_CIRCLE2_ACHIEVE_H

#include "StaticFindIntersectorCircle2Circle2.h"
#include "Detail/StaticFindIntersectorCircle2Circle2ImplDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"
#include "Mathematics/Intersection/StaticIntersectorDetail.h"
#include "Mathematics/Objects2D/Circle2Detail.h"

template <typename Real>
Mathematics::StaticFindIntersectorCircle2Circle2<Real>::StaticFindIntersectorCircle2Circle2(const Circle2& lhsCircle, const Circle2& rhsCircle, const Real epsilon)
    : ParentType{ epsilon }, m_Impl{ std::make_shared<ImplType>(lhsCircle, rhsCircle) }
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real>
void Mathematics::StaticFindIntersectorCircle2Circle2<Real>::Find()
{
    const auto lhsCircle = GetLhsCircle();
    const auto rhsCircle = GetRhsCircle();

    // ����Բ��|X - C0| = R0��|X - C1| = R1��
    // ����U = C1 - C0��V = Perp(U)����PerpPerp(x,y) = (y,-x)��
    // ע��Dot(U,V) = 0��|V|^2 = |U|^2��
    // �����X������X = C0 + s * U + t * V��X = C1 + (s - 1) * U + t * V����ʽд�롣
    // ��Բ���̽���ƽ����������Щ��ʽ����
    //   R0^2 = (s^2 + t^2)*|U|^2
    //   R1^2 = ((s-1)^2 + t^2) * |U|^2.
    // ��������s��ֵ
    //   s = ((R0^2-R1^2)/|U|^2 + 1)/2
    // Ȼ���ڵ�һ���������滻�����t^2
    //   t^2 = (R0^2/|U|^2) - s^2.
    // Ϊ���н⣬�Ҳ�����ǷǸ��ġ� һЩ�������½�Ĵ��ڵ�������
    //   (|U|^2 - (R0+R1)^2)*(|U|^2 - (R0-R1)^2) <= 0.
    // ����ٵ�
    //   |R0-R1| <= |U| <= |R0+R1|.
    // ��� |U| = |R0 - R1|, ��ô��ЩԲ�ǲ��ŵĲ���ǡ�����С�
    // ��� |U| = |R0 + R1|, ��ôԲ��Ƕ�׵ģ�����ǡ�����С�
    // ��� |R0-R1| < |U| < |R0+R1|����ô����Բ�ཻ����������

    auto centerDifference = rhsCircle.GetCenter() - lhsCircle.GetCenter();
    auto centerDifferenceSquaredLength = Vector2DTools::VectorMagnitudeSquared(centerDifference);
    auto lhsRadius = lhsCircle.GetRadius();
    auto rhsRadius = rhsCircle.GetRadius();
    auto lhsAdiusMinusRhsAdius = lhsRadius - rhsRadius;
    auto epsilon = ParentType::GetEpsilon();
    if (centerDifferenceSquaredLength < epsilon && Math::FAbs(lhsAdiusMinusRhsAdius) < epsilon)
    {
        // Բ������ͬ��
        this->SetIntersectionType(IntersectionType::Other);
        return;
    }

    auto lhsAdiusMinusRhsAdiusSquared = lhsAdiusMinusRhsAdius * lhsAdiusMinusRhsAdius;
    if (centerDifferenceSquaredLength + epsilon < lhsAdiusMinusRhsAdiusSquared)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    auto lhsRadiusPlusRhsRadius = lhsRadius + rhsRadius;
    auto lhsRadiusPlusRhsRadiusSquared = lhsRadiusPlusRhsRadius * lhsRadiusPlusRhsRadius;
    if (lhsRadiusPlusRhsRadiusSquared + epsilon < centerDifferenceSquaredLength)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        return;
    }

    if (centerDifferenceSquaredLength + epsilon < lhsRadiusPlusRhsRadiusSquared)
    {
        if (lhsAdiusMinusRhsAdiusSquared + epsilon < centerDifferenceSquaredLength)
        {
            auto ordinal = Math::GetRational(1, 2) * ((lhsRadius * lhsRadius - rhsRadius * rhsRadius) / centerDifferenceSquaredLength + Math::GetValue(1));
            auto amendmentCenter = lhsCircle.GetCenter() + ordinal * centerDifference;

            // �����ϣ�discriminant�ǷǸ��ġ�
            // Ȼ������ֵ��������������ʹ���Ը�������ض�Ϊ�㡣
            auto discriminant = lhsRadius * lhsRadius / centerDifferenceSquaredLength - ordinal * ordinal;
            if (discriminant < Math::GetValue(0))
            {
                discriminant = Math::GetValue(0);
            }
            auto discriminantSqrt = Math::Sqrt(discriminant);
            const auto perp = Vector2DTools::GetPerp(centerDifference);

            auto lhsPoint = amendmentCenter - discriminantSqrt * perp;
            auto rhsPoint = amendmentCenter + discriminantSqrt * perp;

            if (Vector2DTools::Approximate(lhsPoint, rhsPoint, epsilon))
            {
                m_Impl->AddIntersection((lhsPoint + rhsPoint) / Math::GetValue(2));
            }
            else
            {
                m_Impl->AddIntersection(lhsPoint);
                m_Impl->AddIntersection(rhsPoint);
            }
        }
        else
        {
            // |U| = |R0 - R1|,Բ�����еġ�
            auto point = lhsCircle.GetCenter() + (lhsRadius / lhsAdiusMinusRhsAdius) * centerDifference;
            m_Impl->AddIntersection(point);
        }
    }
    else
    {
        // |U| = |R0 + R1|, Բ�����еġ�
        auto point = lhsCircle.GetCenter() + (lhsRadius / lhsRadiusPlusRhsRadius) * centerDifference;
        m_Impl->AddIntersection(point);
    }

    this->SetIntersectionType(IntersectionType::Point);
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticFindIntersectorCircle2Circle2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid() && m_Impl != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Circle2<Real> Mathematics::StaticFindIntersectorCircle2Circle2<Real>::GetLhsCircle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetLhsCircle();
}

template <typename Real>
const Mathematics::Circle2<Real> Mathematics::StaticFindIntersectorCircle2Circle2<Real>::GetRhsCircle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetRhsCircle();
}

template <typename Real>
int Mathematics::StaticFindIntersectorCircle2Circle2<Real>::GetQuantity() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetQuantity();
}

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::StaticFindIntersectorCircle2Circle2<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetPoint(index);
}

template <typename Real>
const Mathematics::Circle2<Real> Mathematics::StaticFindIntersectorCircle2Circle2<Real>::GetIntersectionCircle() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (this->GetIntersectionType() == IntersectionType::Other)
    {
        return m_Impl->GetIntersectionCircle();
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("Ҫ��ѯ��Բ�������ص��ġ�\n"s));
    }
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_CIRCLE2_CIRCLE2_ACHIEVE_H
