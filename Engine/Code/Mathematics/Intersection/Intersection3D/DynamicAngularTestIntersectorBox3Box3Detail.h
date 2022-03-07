///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.3 (2022/02/26 14:36)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_ANGULAR_TEST_INTERSECTOR_BOX3_BOX3_DETAIL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_ANGULAR_TEST_INTERSECTOR_BOX3_BOX3_DETAIL_H

#include "DynamicAngularTestIntersectorBox3Box3.h"

#include "DynamicAngularTestIntersectorBox3Box3.h"
#include "DynamicTestIntersectorBox3Box3Detail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"

template <typename Real>
Mathematics::DynamicAngularTestIntersectorBox3Box3<Real>::DynamicAngularTestIntersectorBox3Box3(const Box3& box0,
                                                                                                const Box3& box1,
                                                                                                Real tmax,
                                                                                                int numSteps,
                                                                                                const Vector3& lhsVelocity,
                                                                                                const Vector3& lhsRotCenter,
                                                                                                const Vector3& lhsRotAxis,
                                                                                                const Vector3& rhsVelocity,
                                                                                                const Vector3& rhsRotCenter,
                                                                                                const Vector3& rhsRotAxis,
                                                                                                const Real epsilon)
    : ParentType{ tmax, lhsVelocity, rhsVelocity, epsilon },
      box0{ box0 },
      box1{ box1 },
      numSteps{ numSteps },
      lhsRotCenter{ lhsRotCenter },
      lhsRotAxis{ lhsRotAxis },
      rhsRotCenter{ rhsRotCenter },
      rhsRotAxis{ rhsRotAxis }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::DynamicAngularTestIntersectorBox3Box3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Box3<Real> Mathematics::DynamicAngularTestIntersectorBox3Box3<Real>::GetBox0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return box0;
}

template <typename Real>
Mathematics::Box3<Real> Mathematics::DynamicAngularTestIntersectorBox3Box3<Real>::GetBox1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return box1;
}

template <typename Real>
void Mathematics::DynamicAngularTestIntersectorBox3Box3<Real>::Test()
{
    // ���ɵ�ʱ�䲽�衣
    auto stepSize = this->GetTMax() / static_cast<Real>(numSteps);

    // ��ʼ���Ӽ����
    auto subBox0 = box0;
    auto subBox1 = box1;

    // ʹ��ŷ��������΢�ַ��̽��л��֡�
    for (auto step = 1; step <= numSteps; ++step)
    {
        // ������ٶȺ��ཻ�Ĳ��Կ�
        auto subTime = stepSize * static_cast<Real>(step);
        auto newRotCenter0 = lhsRotCenter + subTime * this->GetLhsVelocity();
        auto newRotCenter1 = rhsRotCenter + subTime * this->GetRhsVelocity();
        auto diff0 = subBox0.GetCenter() - newRotCenter0;
        auto diff1 = subBox1.GetCenter() - newRotCenter1;
        auto subVelocity0 = stepSize * (this->GetLhsVelocity() + Vector3Tools::CrossProduct(lhsRotAxis, diff0));
        auto subVelocity1 = stepSize * (this->GetRhsVelocity() + Vector3Tools::CrossProduct(rhsRotAxis, diff1));

        DynamicTestIntersectorBox3Box3<Real> calc{ subBox0, subBox1, stepSize, subVelocity0, subVelocity1 };
        if (calc.IsIntersection())
        {
            this->SetIntersectionType(calc.GetIntersectionType());
            return;
        }

        // ���º������ġ�
        subBox0 = subBox0.GetMove(1, subVelocity0);
        subBox1 = subBox1.GetMove(1, subVelocity1);

        // ���º����ᡣ
        using AxisType = std::vector<Vector3>;
        AxisType axis0{ subBox0.GetAxis(0) + stepSize * Vector3Tools::CrossProduct(lhsRotAxis, subBox0.GetAxis(0)),
                        subBox0.GetAxis(1) + stepSize * Vector3Tools::CrossProduct(lhsRotAxis, subBox0.GetAxis(1)),
                        subBox0.GetAxis(2) + stepSize * Vector3Tools::CrossProduct(lhsRotAxis, subBox0.GetAxis(2)) };
        AxisType axis1{ subBox1.GetAxis(0) + stepSize * Vector3Tools::CrossProduct(rhsRotAxis, subBox1.GetAxis(0)),
                        subBox1.GetAxis(1) + stepSize * Vector3Tools::CrossProduct(rhsRotAxis, subBox1.GetAxis(1)),
                        subBox1.GetAxis(2) + stepSize * Vector3Tools::CrossProduct(rhsRotAxis, subBox1.GetAxis(2)) };

        /// ʹ��Gram-Schmidt�Ը��µ���������򻯡�
        /// ע�⣺���T/NС��NС��������ڼٶ�������ӽ������������ɾ���˰���Ĳ�����
        const auto Vector3Orthonormalize0 = Vector3Tools::Orthonormalize(axis0);
        const auto Vector3Orthonormalize1 = Vector3Tools::Orthonormalize(axis1);

        subBox0 = Box3{ subBox0.GetCenter(), Vector3Orthonormalize0.GetUVector(),
                        Vector3Orthonormalize0.GetVVector(), Vector3Orthonormalize0.GetWVector(),
                        subBox0.GetExtent0(), subBox0.GetExtent1(), subBox0.GetExtent2() };

        subBox1 = Box3{ subBox1.GetCenter(), Vector3Orthonormalize1.GetUVector(),
                        Vector3Orthonormalize1.GetVVector(), Vector3Orthonormalize1.GetWVector(),
                        subBox1.GetExtent0(), subBox1.GetExtent1(), subBox1.GetExtent2() };
    }

    /// ע�⣺������ཻ����Ӧ�ó��������Ҫ�����ƶ�/��ת������λ�á�
    /// ����������£����뷵��subBox0��subBox1������ֵ���Ա�Ӧ�ó����������box0 < -subBox0��box1 < -subBox1��
    /// ����Ӧ�ó��򽫲��ò��ٴ����΢�ַ��̻�ʹ�÷����ʽ�ĸ����˶����������µĺ�λ�á�

    this->SetIntersectionType(IntersectionType::Empty); 
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_ANGULAR_TEST_INTERSECTOR_BOX3_BOX3_DETAIL_H