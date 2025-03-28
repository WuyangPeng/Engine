///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/28 14:30)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE3_TRIANGLE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE3_TRIANGLE3_DETAIL_H

#include "StaticTestIntersectorTriangle3Triangle3.h"
#include "Detail/TriangleProjectOntoAxisDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3Detail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Intersection/IntersectorDetail.h"
#include "Mathematics/Intersection/StaticIntersectorDetail.h"
#include "Mathematics/Objects3D/Line3Detail.h"
#include "Mathematics/Objects3D/Plane3Detail.h"
#include "Mathematics/Objects3D/Triangle3Detail.h"

template <typename Real>
Mathematics::StaticTestIntersectorTriangle3Triangle3<Real>::StaticTestIntersectorTriangle3Triangle3(const Triangle3& lhsTriangle, const Triangle3& rhsTriangle, const Real epsilon)
    : ParentType{ epsilon }, lhsTriangle{ lhsTriangle }, rhsTriangle{ rhsTriangle }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticTestIntersectorTriangle3Triangle3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
void Mathematics::StaticTestIntersectorTriangle3Triangle3<Real>::Test()
{
    // ��ȡlhsTriangle�ı�����
    const auto lhsEdge = lhsTriangle.GetEdgeVectors();

    // ��ȡlhsTriangle�ķ���
    const auto lhsNormal = lhsTriangle.GetNormal();

    // ��������rhsTriangleͶӰ��������m_LhsTriangle�ķ����ϣ����зָ���ԡ�
    auto lhsNormalDotVertex0 = Vector3ToolsType::DotProduct(lhsNormal, lhsTriangle.GetVertex(0));

    const TriangleProjectOntoAxis<Real> rhsTriangleProjectOntoAxis{ rhsTriangle, lhsNormal };

    if (lhsNormalDotVertex0 < rhsTriangleProjectOntoAxis.GetMin() || rhsTriangleProjectOntoAxis.GetMax() < lhsNormalDotVertex0)
    {
        return;
    }

    // ��ȡm_RhsTriangle�ı�����
    auto rhsEdge = rhsTriangle.GetEdgeVectors();

    // ��ȡm_RhsTriangle�ķ���
    const auto rhsNormal = rhsTriangle.GetNormal();

    const auto lhsNormalCrossRhsNormal = Vector3ToolsType::UnitCrossProduct(lhsNormal, rhsNormal);

    if (this->GetEpsilon() <= Vector3ToolsType::DotProduct(lhsNormalCrossRhsNormal, lhsNormalCrossRhsNormal))
    {
        // �����β�ƽ�С�

        // ��������m_LhsTriangleͶӰ��������m_RhsTriangle�ķ����ϣ����зָ���ԡ�
        auto rhsNormalDotVertex0 = Vector3ToolsType::DotProduct(rhsNormal, rhsTriangle.GetVertex(0));

        const TriangleProjectOntoAxis<Real> lhsTriangleProjectOntoAxis{ lhsTriangle, rhsNormal };

        if (rhsNormalDotVertex0 < lhsTriangleProjectOntoAxis.GetMin() || lhsTriangleProjectOntoAxis.GetMax() < rhsNormalDotVertex0)
        {
            return;
        }

        // ���� lhsEdge[lhsIndex] X rhsEdge[rhsIndex]
        for (auto rhsIndex = 0; rhsIndex < 3; ++rhsIndex)
        {
            for (auto lhsIndex = 0; lhsIndex < 3; ++lhsIndex)
            {
                const auto dir = Vector3ToolsType::UnitCrossProduct(lhsEdge.at(lhsIndex), rhsEdge.at(rhsIndex));

                const TriangleProjectOntoAxis<Real> lhsTriangleProjectOntoDir{ lhsTriangle, dir };
                const TriangleProjectOntoAxis<Real> rhsTriangleProjectOntoDir{ rhsTriangle, dir };

                if (lhsTriangleProjectOntoDir.GetMax() < rhsTriangleProjectOntoDir.GetMin() || rhsTriangleProjectOntoDir.GetMax() < lhsTriangleProjectOntoDir.GetMin())
                {
                    return;
                }
            }
        }

        // ���Բ�ѯ��֪��������
        this->SetIntersectionType(IntersectionType::Other);
    }
    else  // ��������ƽ�еģ�������ʵ���ǹ���ģ���
    {
        // ���� lhsTriangle X lhsEdge[index]
        for (auto index = 0; index < 3; ++index)
        {
            const auto dir = Vector3ToolsType::UnitCrossProduct(lhsNormal, lhsEdge.at(index));

            const TriangleProjectOntoAxis<Real> lhsTriangleProjectOntoDir{ lhsTriangle, dir };
            const TriangleProjectOntoAxis<Real> rhsTriangleProjectOntoDir{ rhsTriangle, dir };

            if (lhsTriangleProjectOntoDir.GetMax() < rhsTriangleProjectOntoDir.GetMin() || rhsTriangleProjectOntoDir.GetMax() < lhsTriangleProjectOntoDir.GetMin())
            {
                return;
            }
        }

        // ���� rhsTriangle X rhsEdge[index]
        for (auto index = 0; index < 3; ++index)
        {
            const auto dir = Vector3ToolsType::UnitCrossProduct(rhsNormal, rhsEdge.at(index));

            const TriangleProjectOntoAxis<Real> lhsTriangleProjectOntoDir{ lhsTriangle, dir };
            const TriangleProjectOntoAxis<Real> rhsTriangleProjectOntoDir{ rhsTriangle, dir };

            if (lhsTriangleProjectOntoDir.GetMax() < rhsTriangleProjectOntoDir.GetMin() || rhsTriangleProjectOntoDir.GetMax() < lhsTriangleProjectOntoDir.GetMin())
            {
                return;
            }
        }

        // ���Բ�ѯ��֪��������
        this->SetIntersectionType(IntersectionType::Plane);
    }
}

template <typename Real>
typename Mathematics::StaticTestIntersectorTriangle3Triangle3<Real>::Triangle3 Mathematics::StaticTestIntersectorTriangle3Triangle3<Real>::GetLhsTriangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return lhsTriangle;
}

template <typename Real>
typename Mathematics::StaticTestIntersectorTriangle3Triangle3<Real>::Triangle3 Mathematics::StaticTestIntersectorTriangle3Triangle3<Real>::GetRhsTriangle() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return rhsTriangle;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE3_TRIANGLE3_DETAIL_H
