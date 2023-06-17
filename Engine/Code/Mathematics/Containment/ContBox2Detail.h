///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/09 09:38)

#ifndef MATHEMATICS_CONTAINMENT_CONT_BOX2_DETAIL_H
#define MATHEMATICS_CONTAINMENT_CONT_BOX2_DETAIL_H

#include "ContBox2.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector2Detail.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Approximation/GaussPointsFit2Detail.h"

template <typename Real>
Mathematics::ContBox2<Real>::ContBox2() noexcept
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::ContBox2<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

// static
template <typename Real>
typename Mathematics::ContBox2<Real>::Box2 Mathematics::ContBox2<Real>::ContAlignedBox(const Points& points)
{
    const auto aabb = Vector2Tools<Real>::ComputeExtremes(points);
    const auto halfDiagonal = Math::GetRational(1, 2) * (aabb.GetMaxPoint() - aabb.GetMinPoint());

    return Box2{ Math::GetRational(1, 2) * (aabb.GetMinPoint() + aabb.GetMaxPoint()),
                 Vector2::GetUnitX(),
                 Vector2::GetUnitY(),
                 halfDiagonal[0],
                 halfDiagonal[1] };
}

// static
template <typename Real>
typename Mathematics::ContBox2<Real>::Box2 Mathematics::ContBox2<Real>::ContOrientedBox(const Points& points)
{
    const GaussPointsFit2<Real> gaussPointsFit2{ points };
    const auto box = gaussPointsFit2.GetBox2();

    // ��C�ǰ�Χ�����ģ���U0��U1�ǰ�Χ�е��ᡣ
    // ÿһ����������ʽΪX = C + y0 * U0 + y1 * U1��
    // ����Ĵ������min(y0), max(y0), min(y1)��max(y1)��
    // Ȼ���Χ�����ı�����Ϊ
    // C' = C + 0.5*(min(y0) + max(y0)) * U0 + 0.5 * (min(y1) + max(y1)) * U1

    std::vector<Real> firstDotCollection{};
    std::vector<Real> secondDotCollection{};
    firstDotCollection.reserve(points.size());
    secondDotCollection.reserve(points.size());

    for (const auto& point : points)
    {
        const auto diff = point - box.GetCenter();

        const auto firstDot = Vector2Tools<Real>::DotProduct(diff, box.GetAxis0());
        firstDotCollection.push_back(firstDot);

        const auto secondDot = Vector2Tools<Real>::DotProduct(diff, box.GetAxis1());
        secondDotCollection.push_back(secondDot);
    }

    const auto firstBoundary = std::minmax_element(firstDotCollection.begin(), firstDotCollection.end());

    const auto secondBoundary = std::minmax_element(secondDotCollection.begin(), secondDotCollection.end());

    auto center = box.GetCenter() +
                  (Math::GetRational(1, 2) * (*firstBoundary.first + *firstBoundary.second) * box.GetAxis0() +
                   Math::GetRational(1, 2) * (*secondBoundary.first + *secondBoundary.second) * box.GetAxis1());

    const auto firstExtent = (*firstBoundary.second - *firstBoundary.first) * Math::GetRational(1, 2);
    const auto secondExtent = (*secondBoundary.second - *secondBoundary.first) * Math::GetRational(1, 2);

    return Box2{ center, box.GetAxis0(), box.GetAxis1(), firstExtent, secondExtent };
}

// static
template <typename Real>
bool Mathematics::ContBox2<Real>::InBox(const Vector2& point, const Box2& box)
{
    const auto diff = point - box.GetCenter();
    const auto firstCoeff = Vector2Tools<Real>::DotProduct(diff, box.GetAxis0());

    if (box.GetExtent0() + box.GetEpsilon() < firstCoeff)
        return false;

    const auto secondCoeff = Vector2Tools<Real>::DotProduct(diff, box.GetAxis1());

    if (box.GetExtent1() + box.GetEpsilon() < secondCoeff)
        return false;

    return true;
}

// static
template <typename Real>
typename Mathematics::ContBox2<Real>::Box2 Mathematics::ContBox2<Real>::MergeBoxes(const Box2& lhs, const Box2& rhs)
{
    // �ڰ�Χ�����ĵĵ�һ�����롣�����Χ�ж���ͶӰ��ȷ����ƽ����Χ�е��ᣬ
    // ��ֵ���ں�����и��¡�
    auto center = Math::GetRational(1, 2) * (lhs.GetCenter() + rhs.GetCenter());

    // �ϲ��İ�Χ�е����������Χ�����ƽ��ֵ��
    // �����Ҫ�Ļ����ڶ�����Χ�е��ᱻȡ�������������γ����һ����Χ�е�����Ϊ��ǡ�
    Vector2 firstAxis{};
    if (Math::GetValue(0) <= Vector2Tools<Real>::DotProduct(lhs.GetAxis0(), rhs.GetAxis0()))
    {
        firstAxis = Math::GetRational(1, 2) * (lhs.GetAxis0() + rhs.GetAxis0());
        firstAxis.Normalize();
    }
    else
    {
        firstAxis = Math::GetRational(1, 2) * (lhs.GetAxis0() - rhs.GetAxis0());
        firstAxis.Normalize();
    }
    const auto secondAxis = -Vector2Tools<Real>::GetPerp(firstAxis);

    // ��Ŀ�������Χ�ж��㵽�ϲ���İ�Χ�е��ᡣ
    // ��������D[i]������ǰ����C������СͶӰֵmin[i]�����ͶӰֵmax[i]��
    // �����ϵ���Ӧ��������C + min[i] * D[i]��C + max[i] * D[i]��
    // C�㲢��һ�����κ�ʱ�������е㡣
    // ʵ�ʰ�Χ�����Ľ���C����Ϊ��C'��ÿ��������е㣬
    //   C' = C + sum_{i=0}^1 0.5 * (min[i] + max[i]) * D[i]
    // ��Χ�еķ�Χ��
    //   e[i] = 0.5 * (max[i] - min[i])

    auto lhsVertices = lhs.ComputeVertices();
    auto rhsVertices = rhs.ComputeVertices();

    lhsVertices.insert(lhsVertices.end(), rhsVertices.begin(), rhsVertices.end());

    std::vector<Real> firstDotCollection{};
    std::vector<Real> secondDotCollection{};
    firstDotCollection.reserve(lhsVertices.size());
    secondDotCollection.reserve(lhsVertices.size());

    for (const auto& point : lhsVertices)
    {
        const auto diff = point - center;

        const auto firstDot = Vector2Tools<Real>::DotProduct(diff, firstAxis);
        firstDotCollection.push_back(firstDot);

        const auto secondDot = Vector2Tools<Real>::DotProduct(diff, secondAxis);
        secondDotCollection.push_back(secondDot);
    }

    const auto firstBoundary = std::minmax_element(firstDotCollection.begin(), firstDotCollection.end());

    const auto secondBoundary = std::minmax_element(secondDotCollection.begin(), secondDotCollection.end());

    // [min,max] Ϊ�ϲ���İ�Χ�е���������ϵ��Ϊ������Χ�С�
    // ���µ�ǰ��Χ�����ĳ�Ϊ�°�Χ�е����ġ���������µ����ĵķ�Χ��
    center += Math::GetRational(1, 2) * (*firstBoundary.first + *firstBoundary.second) * firstAxis +
              Math::GetRational(1, 2) * (*secondBoundary.first + *secondBoundary.second) * secondAxis;

    const auto firstExtent = (*firstBoundary.second - *firstBoundary.first) * Math::GetRational(1, 2);
    const auto secondExtent = (*secondBoundary.second - *secondBoundary.first) * Math::GetRational(1, 2);

    return Box2{ center, firstAxis, secondAxis, firstExtent, secondExtent };
}

#endif  // MATHEMATICS_CONTAINMENT_CONT_BOX2_DETAIL_H
