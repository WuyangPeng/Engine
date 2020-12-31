///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.6.0.0 (2020/12/24 17:29)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_ANGULAR_TEST_INTERSECTOR_BOX3_BOX3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_ANGULAR_TEST_INTERSECTOR_BOX3_BOX3_ACHIEVE_H

#include "DynamicAngularTestIntersectorBox3Box3.h"
#include "DynamicTestIntersectorBox3Box3Detail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"

template <typename Real>
Mathematics::DynamicAngularTestIntersectorBox3Box3<Real>::DynamicAngularTestIntersectorBox3Box3(
    const Box3& box0,
    const Box3& box1,
    Real tmax,
    int numSteps,
    const Vector3D& lhsVelocity,
    const Vector3D& lhsRotCenter,
    const Vector3D& lhsRotAxis,
    const Vector3D& rhsVelocity,
    const Vector3D& rhsRotCenter,
    const Vector3D& rhsRotAxis,
    const Real epsilon)
    : ParentType{ tmax, lhsVelocity, rhsVelocity, epsilon },
      m_Box0{ box0 },
      m_Box1{ box1 },
      m_NumSteps{ numSteps },
      m_LhsRotCenter{ lhsRotCenter },
      m_LhsRotAxis{ lhsRotAxis },
      m_RhsRotCenter{ rhsRotCenter },
      m_RhsRotAxis{ rhsRotAxis }
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
const Mathematics::Box3<Real> Mathematics::DynamicAngularTestIntersectorBox3Box3<Real>::GetBox0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Box0;
}

template <typename Real>
const Mathematics::Box3<Real> Mathematics::DynamicAngularTestIntersectorBox3Box3<Real>::GetBox1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Box1;
}

template <typename Real>
void Mathematics::DynamicAngularTestIntersectorBox3Box3<Real>::Test()
{
    // ���ɵ�ʱ�䲽�衣
    auto stepSize = this->GetTMax() / static_cast<Real>(m_NumSteps);

    // ��ʼ���Ӽ����
    auto subBox0 = m_Box0;
    auto subBox1 = m_Box1;

    // ʹ��ŷ��������΢�ַ��̽��л��֡�
    for (auto step = 1; step <= m_NumSteps; ++step)
    {
        // ������ٶȺ��ཻ�Ĳ��Կ�
        auto subTime = stepSize * static_cast<Real>(step);
        auto newRotCenter0 = m_LhsRotCenter + subTime * this->GetLhsVelocity();
        auto newRotCenter1 = m_RhsRotCenter + subTime * this->GetRhsVelocity();
        auto diff0 = subBox0.GetCenter() - newRotCenter0;
        auto diff1 = subBox1.GetCenter() - newRotCenter1;
        auto subVelocity0 = stepSize * (this->GetLhsVelocity() + Vector3DTools::CrossProduct(m_LhsRotAxis, diff0));
        auto subVelocity1 = stepSize * (this->GetRhsVelocity() + Vector3DTools::CrossProduct(m_RhsRotAxis, diff1));

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
        using AxisType = std::vector<Vector3D>;
        AxisType axis0{ subBox0.GetAxis(0) + stepSize * Vector3DTools::CrossProduct(m_LhsRotAxis, subBox0.GetAxis(0)),
                        subBox0.GetAxis(1) + stepSize * Vector3DTools::CrossProduct(m_LhsRotAxis, subBox0.GetAxis(1)),
                        subBox0.GetAxis(2) + stepSize * Vector3DTools::CrossProduct(m_LhsRotAxis, subBox0.GetAxis(2)) };
        AxisType axis1{ subBox1.GetAxis(0) + stepSize * Vector3DTools::CrossProduct(m_RhsRotAxis, subBox1.GetAxis(0)),
                        subBox1.GetAxis(1) + stepSize * Vector3DTools::CrossProduct(m_RhsRotAxis, subBox1.GetAxis(1)),
                        subBox1.GetAxis(2) + stepSize * Vector3DTools::CrossProduct(m_RhsRotAxis, subBox1.GetAxis(2)) };

        /// ʹ��Gram-Schmidt�Ը��µ���������򻯡�
        /// ע�⣺���T/NС��NС��������ڼٶ�������ӽ������������ɾ���˰���Ĳ�����
        const auto vector3DOrthonormalize0 = Vector3DTools::Orthonormalize(axis0);
        const auto vector3DOrthonormalize1 = Vector3DTools::Orthonormalize(axis1);

        subBox0 = Box3{ subBox0.GetCenter(), vector3DOrthonormalize0.GetUVector(),
                        vector3DOrthonormalize0.GetVVector(), vector3DOrthonormalize0.GetWVector(),
                        subBox0.GetExtent0(), subBox0.GetExtent1(), subBox0.GetExtent2() };

        subBox1 = Box3{ subBox1.GetCenter(), vector3DOrthonormalize1.GetUVector(),
                        vector3DOrthonormalize1.GetVVector(), vector3DOrthonormalize1.GetWVector(),
                        subBox1.GetExtent0(), subBox1.GetExtent1(), subBox1.GetExtent2() };
    }

    /// ע�⣺������ཻ����Ӧ�ó��������Ҫ�����ƶ�/��ת������λ�á�
    /// ����������£����뷵��subBox0��subBox1������ֵ���Ա�Ӧ�ó����������box0 < -subBox0��box1 < -subBox1��
    /// ����Ӧ�ó��򽫲��ò��ٴ����΢�ַ��̻�ʹ�÷����ʽ�ĸ����˶����������µĺ�λ�á�

    this->SetIntersectionType(IntersectionType::Empty);
    return;
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_ANGULAR_TEST_INTERSECTOR_BOX3_BOX3_ACHIEVE_H