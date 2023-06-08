///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/06/08 17:34)

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
    // �õ���С���������Ĵ�Բ��Բ��ƽ���ϵĵ� Dot(N,X) = 0��
    GreatCircleFit3<Real> greatCircleFit{ points };

    normal = greatCircleFit.GetNormal();

    // ��������������ϵͳ����ͶӰ����Բ���������߷���ΪU,V��N��
    const auto basis = Vector3Tools<Real>::GenerateComplementBasis(normal);

    // ������ X[i] = u[i] * U + v[i] * V + w[i] * N��
    // ͶӰ��P[i] = (u[i] * U + v[i] * V) / sqrt(u[i] * u[i] + v[i] * v[i])
    // ��Բ�ǲ�����ΪC(t) = cos(t) * U + sin(t) * V��
    // ����Ƕ�t��[-pi,pi]ͶӰ����Բ��
    // �����Ǳ�Ҫ����(u[i],v[i]),�෴ȥ����t = atan2(v[i],u[i])
    std::vector<GreatArcFit3Item<Real>> items;

    for (const auto& point : points)
    {
        items.emplace_back(basis.GetUVector(), basis.GetVVector(), point);
    }

    std::sort(items.begin(), items.end());

    // ������λ�ĽǶ���һ�����Ĳ�ֵ��
    // ʵ����, ���ǹ���һ��Բ׶������С�ǵĵ�λ����������
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
