///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/03 14:32)

#ifndef MATHEMATICS_APPROXIMATION_GREAT_ARC_FIT3_ACHIEVE_H
#define MATHEMATICS_APPROXIMATION_GREAT_ARC_FIT3_ACHIEVE_H

#include "GreatArcFit3.h"
#include "GreatCircleFit3Detail.h"
#include "Detail/GreatArcFit3ItemDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::GreatArcFit3<Real>::GreatArcFit3(const Points& points)
    : m_Normal{}, m_ArcEnd0{}, m_ArcEnd1{}
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

    m_Normal = greatCircleFit.GetNormal();

    // 计算向量的坐标系统允许投影到大圆。坐标轴线方向为U,V和N。
    const auto basis = Vector3DTools<Real>::GenerateComplementBasis(m_Normal);

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

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    // 连续定位的角度是一个最大的差值。
    // 实际上, 我们构建一个圆锥包含最小角的单位长度向量。
    const auto numPointsMinus1 = points.size() - 1;
    auto maxDiff = Math::GetTwoPI() + items[0].GetAngle() - items[numPointsMinus1].GetAngle();
    auto end0 = 0;
    auto end1 = numPointsMinus1;
    for (auto index = 0u; index < numPointsMinus1; ++index)
    {
        const auto next = index + 1;
        auto diff = items[next].GetAngle() - items[index].GetAngle();
        if (maxDiff < diff)
        {
            maxDiff = diff;
            end0 = index + 1;
            end1 = index;
        }
    }

    m_ArcEnd0 = items[end0].GetUDot() * basis.GetUVector() + items[end0].GetVDot() * basis.GetVVector();
    m_ArcEnd1 = items[end1].GetUDot() * basis.GetUVector() + items[end1].GetVDot() * basis.GetVVector();
    m_ArcEnd0.Normalize();
    m_ArcEnd1.Normalize();

#include STSTEM_WARNING_POP
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::GreatArcFit3<Real>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::GreatArcFit3<Real>::GetNormal() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Normal;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::GreatArcFit3<Real>::GetArcEnd0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_ArcEnd0;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::GreatArcFit3<Real>::GetArcEnd1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_ArcEnd1;
}

#endif  // MATHEMATICS_APPROXIMATION_GREAT_ARC_FIT3_ACHIEVE_H
