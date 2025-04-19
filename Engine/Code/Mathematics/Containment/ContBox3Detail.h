///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/09 09:38)

#ifndef MATHEMATICS_CONTAINMENT_CONT_BOX3_DETAIL_H
#define MATHEMATICS_CONTAINMENT_CONT_BOX3_DETAIL_H

#include "ContBox3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/AxesAlignBoundingBox3Detail.h"
#include "Mathematics/Algebra/QuaternionDetail.h"
#include "Mathematics/Algebra/Vector3Detail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Approximation/GaussPointsFit3Detail.h"

template <typename Real>
Mathematics::ContBox3<Real>::ContBox3() noexcept
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::ContBox3<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
typename Mathematics::ContBox3<Real>::Box3Type Mathematics::ContBox3<Real>::ContAlignedBox(const Points& points)
{
    const auto aabb = Vector3Tools<Real>::ComputeExtremes(points);
    auto halfDiagonal = MathType::GetRational(1, 2) * (aabb.GetMaxPoint() - aabb.GetMinPoint());

    return Box3Type{ MathType::GetRational(1, 2) * (aabb.GetMinPoint() + aabb.GetMaxPoint()),
                 Vector3Type::GetUnitX(),
                 Vector3Type::GetUnitY(),
                 Vector3Type::GetUnitZ(),
                 halfDiagonal[0],
                 halfDiagonal[1],
                 halfDiagonal[2] };
}

template <typename Real>
typename Mathematics::ContBox3<Real>::Box3Type Mathematics::ContBox3<Real>::ContOrientedBox(const Points& points)
{
    const GaussPointsFit3<Real> gaussPointsFit3{ points };
    const auto box = gaussPointsFit3.GetBox3();

    // ��C�ǰ�Χ�����ģ���U0,U1��U2�ǰ�Χ�е��ᡣ
    // ÿһ����������ʽΪX = C + y0 * U0 + y1 * U1 + y2 * U2��
    // ����Ĵ������min(y0), max(y0), min(y1),max(y1), min(y2)��max(y2)��
    // Ȼ���Χ�����ı�����Ϊ
    //   C' = C + 0.5 * (min(y0) + max(y0)) * U0 + 0.5 * (min(y1) + max(y1)) * U1 +
    //        0.5 * (min(y2) + max(y2)) * U2
    std::vector<Real> firstDotCollection{};
    std::vector<Real> secondDotCollection{};
    std::vector<Real> thirdDotCollection{};
    firstDotCollection.reserve(points.size());
    secondDotCollection.reserve(points.size());
    thirdDotCollection.reserve(points.size());

    for (const auto& point : points)
    {
        auto diff = point - box.GetCenter();

        auto firstDot = Vector3Tools<Real>::DotProduct(diff, box.GetAxis0());
        firstDotCollection.push_back(firstDot);

        auto secondDot = Vector3Tools<Real>::DotProduct(diff, box.GetAxis1());
        secondDotCollection.push_back(secondDot);

        auto thirdDot = Vector3Tools<Real>::DotProduct(diff, box.GetAxis2());
        thirdDotCollection.push_back(thirdDot);
    }

    const auto firstBoundary = std::minmax_element(firstDotCollection.begin(), firstDotCollection.end());

    const auto secondBoundary = std::minmax_element(secondDotCollection.begin(), secondDotCollection.end());

    const auto thirdBoundary = std::minmax_element(thirdDotCollection.begin(), thirdDotCollection.end());

    auto center = box.GetCenter() +
                  (MathType::GetRational(1, 2) * (*firstBoundary.first + *firstBoundary.second) * box.GetAxis0() +
                   MathType::GetRational(1, 2) * (*secondBoundary.first + *secondBoundary.second) * box.GetAxis1() +
                   MathType::GetRational(1, 2) * (*thirdBoundary.first + *thirdBoundary.second) * box.GetAxis2());

    auto firstExtent = (*firstBoundary.second - *firstBoundary.first) * MathType::GetRational(1, 2);
    auto secondExtent = (*secondBoundary.second - *secondBoundary.first) * MathType::GetRational(1, 2);
    auto thirdExtent = (*thirdBoundary.second - *thirdBoundary.first) * MathType::GetRational(1, 2);

    return Box3Type{ center, box.GetAxis0(), box.GetAxis1(), box.GetAxis2(), firstExtent, secondExtent, thirdExtent };
}

template <typename Real>
bool Mathematics::ContBox3<Real>::InBox(const Vector3Type& point, const Box3Type& box)
{
    auto diff = point - box.GetCenter();
    auto firstCoeff = Vector3Tools<Real>::DotProduct(diff, box.GetAxis0());

    if (box.GetExtent0() + box.GetEpsilon() < firstCoeff)
        return false;

    auto secondCoeff = Vector3Tools<Real>::DotProduct(diff, box.GetAxis1());

    if (box.GetExtent1() + box.GetEpsilon() < secondCoeff)
        return false;

    auto thirdCoeff = Vector3Tools<Real>::DotProduct(diff, box.GetAxis2());

    if (box.GetExtent2() + box.GetEpsilon() < thirdCoeff)
        return false;

    return true;
}

template <typename Real>
typename Mathematics::ContBox3<Real>::Box3Type Mathematics::ContBox3<Real>::MergeBoxes(const Box3Type& lhs, const Box3Type& rhs)
{
    // �ڰ�Χ�����ĵĵ�һ�����롣�����Χ�ж���ͶӰ��ȷ����ƽ����Χ�е��ᣬ
    // ��ֵ���ں�����и��¡�
    auto center = MathType::GetRational(1, 2) * (lhs.GetCenter() + rhs.GetCenter());

    // һ����Χ�е��ᣬ����һ���о����γ�һ����ת����
    // �����Χ�е��ᱻת��Ϊ��Ԫ����
    // ����ƽ����Ԫ����Ȼ���׼��Ϊ��λ���ȡ�
    // ���Ϊ����tֵΪ1/2������������Ԫ�����������Բ�ֵ��
    // �����ת������ת����������б�ѡ����Ϊ�ϲ���Χ�е��ᡣ
    std::vector<Vector3Type> lhsRotationColumn{ lhs.GetAxis0(), lhs.GetAxis1(), lhs.GetAxis2() };

    std::vector<Vector3Type> rhsRotationColumn{ rhs.GetAxis0(), rhs.GetAxis1(), rhs.GetAxis2() };

    const Quaternion<Real> lhsQuaternion{ lhsRotationColumn };
    Quaternion<Real> rhsQuaternion{ rhsRotationColumn };

    if (Dot(lhsQuaternion, rhsQuaternion) < MathType::GetValue(0))
    {
        rhsQuaternion = -rhsQuaternion;
    }

    auto sumQuaternion = lhsQuaternion + rhsQuaternion;
    auto invLength = MathType::InvSqrt(Dot(sumQuaternion, sumQuaternion));
    sumQuaternion = invLength * sumQuaternion;

    const auto sumRotationColumn = sumQuaternion.ToRotationColumnVector3();

    // ��Ŀ�������Χ�ж��㵽�ϲ���İ�Χ�е��ᡣ
    // ��������D[i]������ǰ����C������СͶӰֵmin[i]�����ͶӰֵmax[i]��
    // �����ϵ���Ӧ��������C + min[i] * D[i] and C + max[i] * D[i]��
    // C�㲢��һ�����κ�ʱ�������е㡣
    // ʵ�ʰ�Χ�����Ľ���C����Ϊ��C'��ÿ��������е㣬
    //   C' = C + sum_{i=0}^2 0.5 * (min[i] + max[i]) * D[i]
    // ��Χ�еķ�Χ��
    //  e[i] = 0.5 * (max[i] - min[i])
    auto lhsVertices = lhs.ComputeVertices();
    auto rhsVertices = rhs.ComputeVertices();

    lhsVertices.insert(lhsVertices.end(), rhsVertices.begin(), rhsVertices.end());

    std::vector<Real> firstDotCollection{};
    std::vector<Real> secondDotCollection{};
    std::vector<Real> thirdDotCollection{};
    firstDotCollection.reserve(lhsVertices.size());
    secondDotCollection.reserve(lhsVertices.size());
    thirdDotCollection.reserve(lhsVertices.size());

    for (const auto& point : lhsVertices)
    {
        auto diff = point - center;

        auto firstDot = Vector3Tools<Real>::DotProduct(diff, sumRotationColumn.at(0));
        firstDotCollection.emplace_back(firstDot);

        auto secondDot = Vector3Tools<Real>::DotProduct(diff, sumRotationColumn.at(1));
        secondDotCollection.emplace_back(secondDot);

        auto thirdDot = Vector3Tools<Real>::DotProduct(diff, sumRotationColumn.at(2));
        thirdDotCollection.emplace_back(thirdDot);
    }

    const auto firstBoundary = std::minmax_element(firstDotCollection.begin(), firstDotCollection.end());

    const auto secondBoundary = std::minmax_element(secondDotCollection.begin(), secondDotCollection.end());

    const auto thirdBoundary = std::minmax_element(thirdDotCollection.begin(), thirdDotCollection.end());

    // [min,max] Ϊ�ϲ���İ�Χ�е���������ϵ��Ϊ������Χ�С�
    // ���µ�ǰ��Χ�����ĳ�Ϊ�°�Χ�е����ġ���������µ����ĵķ�Χ��
    center += MathType::GetRational(1, 2) * (*firstBoundary.first + *firstBoundary.second) * sumRotationColumn.at(0) +
              MathType::GetRational(1, 2) * (*secondBoundary.first + *secondBoundary.second) * sumRotationColumn.at(1) +
              MathType::GetRational(1, 2) * (*thirdBoundary.first + *thirdBoundary.second) * sumRotationColumn.at(2);

    auto firstExtent = (*firstBoundary.second - *firstBoundary.first) * MathType::GetRational(1, 2);
    auto secondExtent = (*secondBoundary.second - *secondBoundary.first) * MathType::GetRational(1, 2);
    auto thirdExtent = (*thirdBoundary.second - *thirdBoundary.first) * MathType::GetRational(1, 2);

    return Box3Type{ center, sumRotationColumn.at(0), sumRotationColumn.at(1), sumRotationColumn.at(2), firstExtent, secondExtent, thirdExtent };
}

#endif  // MATHEMATICS_CONTAINMENT_CONT_BOX3_DETAIL_H
