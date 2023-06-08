///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 17:34)

#ifndef MATHEMATICS_APPROXIMATION_GREAT_ARC_FIT3_ACHIEVE_H
#define MATHEMATICS_APPROXIMATION_GREAT_ARC_FIT3_ACHIEVE_H

#include "GreatArcFit3.h"
#include "GreatCircleFit3Detail.h"
#include "Detail/GreatArcFit3ItemDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::GreatArcFit3<Real>::GreatArcFit3(const Points& points)
    : normal{}, arcEnd0{}, arcEnd1{}
{
    Calculate(points);

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

// private
template <typename Real>
void Mathematics::GreatArcFit3<Real>::Calculate(const Points& points)
{
    // 得到最小二乘向量的大圆。圆是平面上的点 Dot(N,X) = 0。
    GreatCircleFit3<Real> greatCircleFit{ points };

    normal = greatCircleFit.GetNormal();

    // 计算向量的坐标系统允许投影到大圆。坐标轴线方向为U,V和N。
    const auto basis = Vector3Tools<Real>::GenerateComplementBasis(normal);

    // 向量是 X[i] = u[i] * U + v[i] * V + w[i] * N。
    // 投影是P[i] = (u[i] * U + v[i] * V) / sqrt(u[i] * u[i] + v[i] * v[i])
    // 大圆是参数化为C(t) = cos(t) * U + sin(t) * V。
    // 计算角度t在[-pi,pi]投影到大圆。
    // 它不是必要正则化(u[i],v[i]),相反去计算t = atan2(v[i],u[i])
    std::vector<GreatArcFit3Item<Real>> items;

    for (const auto& point : points)
    {
        items.emplace_back(basis.GetUVector(), basis.GetVVector(), point);
    }

    std::sort(items.begin(), items.end());

    // 连续定位的角度是一个最大的差值。
    // 实际上, 我们构建一个圆锥包含最小角的单位长度向量。
    const auto numPointsMinus1 = points.size() - 1;
    auto maxDiff = Math::GetTwoPI() + items.at(0).GetAngle() - items.at(numPointsMinus1).GetAngle();
    auto end0 = 0;
    auto end1 = numPointsMinus1;
    for (auto index = 0u; index < numPointsMinus1; ++index)
    {
        const auto next = index + 1;
        auto diff = items.at(next).GetAngle() - items.at(index).GetAngle();
        if (maxDiff < diff)
        {
            maxDiff = diff;
            end0 = index + 1;
            end1 = index;
        }
    }

    arcEnd0 = items.at(end0).GetUDot() * basis.GetUVector() + items.at(end0).GetVDot() * basis.GetVVector();
    arcEnd1 = items.at(end1).GetUDot() * basis.GetUVector() + items.at(end1).GetVDot() * basis.GetVVector();
    arcEnd0.Normalize();
    arcEnd1.Normalize();
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::GreatArcFit3<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Vector3<Real> Mathematics::GreatArcFit3<Real>::GetNormal() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return normal;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::GreatArcFit3<Real>::GetArcEnd0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return arcEnd0;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::GreatArcFit3<Real>::GetArcEnd1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return arcEnd1;
}

#endif  // MATHEMATICS_APPROXIMATION_GREAT_ARC_FIT3_ACHIEVE_H
