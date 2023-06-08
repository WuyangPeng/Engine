///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/06/08 17:50)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT2_HYPERBOLA2_ACHIEVE_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT2_HYPERBOLA2_ACHIEVE_H

#include "DistancePoint2Hyperbola2.h"
#include "Mathematics/Algebra/Vector2Detail.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Distance/DistanceBaseDetail.h"

template <typename Real>
Mathematics::DistancePoint2Hyperbola2<Real>::DistancePoint2Hyperbola2(const Vector2& point, const Vector2& extent) noexcept
    : ParentType{}, point{ point }, extent{ extent }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::DistancePoint2Hyperbola2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid() && Math::GetValue(0) < extent.GetX() && Math::GetValue(0) < extent.GetY())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Vector2<Real> Mathematics::DistancePoint2Hyperbola2<Real>::GetPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return point;
}

template <typename Real>
Mathematics::Vector2<Real> Mathematics::DistancePoint2Hyperbola2<Real>::GetExtent() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return extent;
}

template <typename Real>
typename Mathematics::DistancePoint2Hyperbola2<Real>::DistanceResult Mathematics::DistancePoint2Hyperbola2<Real>::GetSquared() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    Vector2 extentSquared{ extent.GetX() * extent.GetX(), extent.GetY() * extent.GetY() };
    const Vector2 reciprocalExtentSquared{ Math::GetValue(1) / extentSquared[0], Math::GetValue(1) / extentSquared[1] };

    // ��ʼ�����ַ��� ��H(-a^2)= +������H(b^2)= -infinity����أ�
    // �������ֻ��Ҫ����Ӧ���з������ֳ�ʼ������ֵ��
    auto t0 = -extentSquared.GetX();
    auto t1 = extentSquared.GetY();
    auto tRoot = Math::GetRational(1, 2) * (t0 + t1);
    auto hyperbolaRoot = GetHyperbola(tRoot, reciprocalExtentSquared);

    // ����ֱ�� H(troot)����Ϊ���ֱ��һ������˵㲻�ٸı䡣
    // ��һ��������IEEE�����������ʣ����ѭ�����������������Ĳ�����ֹ��
    const auto maximumIterations = this->GetMaximumIterations();
    for (auto loop = 0; loop < maximumIterations; ++loop)
    {
        if (!Math::Approximate(hyperbolaRoot, Math::GetValue(0), this->GetZeroThreshold()) &&
            !Math::Approximate(tRoot, t0, this->GetZeroThreshold()) &&
            !Math::Approximate(tRoot, t1, this->GetZeroThreshold()))
        {
            break;
        }

        if (Math::GetValue(0) < hyperbolaRoot)
        {
            t0 = tRoot;
            tRoot = Math::GetRational(1, 2) * (t0 + t1);
        }
        else  // hyperbolaRoot < Math<Real>::sm_Zero
        {
            t1 = tRoot;
        }

        tRoot = Math::GetRational(1, 2) * (t0 + t1);
        hyperbolaRoot = GetHyperbola(tRoot, reciprocalExtentSquared);

        if (loop + 1 == maximumIterations)
        {
            MATHEMATICS_ASSERTION_2(false, "δ�ܵ����������������");
        }
    }

    const Vector2 closest{ point.GetX() / (Math::GetValue(1) + tRoot * reciprocalExtentSquared.GetX()),
                           point.GetY() / (Math::GetValue(1) - tRoot * reciprocalExtentSquared.GetY()) };

    const auto diff = point - closest;

    return DistanceResult{ Vector2Tools::GetLengthSquared(diff), Math::GetValue(0), point, closest };
}

// private
template <typename Real>
Real Mathematics::DistancePoint2Hyperbola2<Real>::GetHyperbola(Real t, const Vector2& reciprocalExtentSquared) const
{
    const auto ratio0 = point.GetX() / (Math::GetValue(1) + t * reciprocalExtentSquared[0]);
    const auto ratio1 = point.GetY() / (Math::GetValue(1) - t * reciprocalExtentSquared[1]);

    return ratio0 * ratio0 - ratio1 * ratio1 - Math::GetValue(1);
}

template <typename Real>
typename Mathematics::DistancePoint2Hyperbola2<Real>::DistanceResult Mathematics::DistancePoint2Hyperbola2<Real>::GetSquared(Real t, const Vector2& lhsVelocity, [[maybe_unused]] const Vector2& rhsVelocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto movePoint = point.GetMove(t, lhsVelocity);

    ClassType distance{ movePoint, extent };
    distance.SetZeroThreshold(this->GetZeroThreshold());
    auto distanceResult = distance.GetSquared();
    distanceResult.SetContactTime(t);

    return distanceResult;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_POINT2_HYPERBOLA2_ACHIEVE_H
