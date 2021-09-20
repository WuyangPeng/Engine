///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.5 (2020/12/03 14:32)

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
    // �õ���С���������Ĵ�Բ��Բ��ƽ���ϵĵ� Dot(N,X) = 0��
    GreatCircleFit3<Real> greatCircleFit{ points };

    m_Normal = greatCircleFit.GetNormal();

    // ��������������ϵͳ����ͶӰ����Բ���������߷���ΪU,V��N��
    const auto basis = Vector3DTools<Real>::GenerateComplementBasis(m_Normal);

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

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    // ������λ�ĽǶ���һ�����Ĳ�ֵ��
    // ʵ����, ���ǹ���һ��Բ׶������С�ǵĵ�λ����������
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