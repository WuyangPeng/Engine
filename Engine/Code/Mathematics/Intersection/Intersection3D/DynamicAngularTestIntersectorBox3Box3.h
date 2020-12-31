///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.6.0.0 (2020/12/24 17:24)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_ANGULAR_TEST_INTERSECTOR_BOX3_BOX3_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_ANGULAR_TEST_INTERSECTOR_BOX3_BOX3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/DynamicIntersector.h"
#include "Mathematics/Objects3D/Box3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DynamicAngularTestIntersectorBox3Box3 : public DynamicIntersector<Real, Vector3D>
    {
    public:
        using ClassType = DynamicAngularTestIntersectorBox3Box3<Real>;
        using ParentType = DynamicIntersector<Real, Vector3D>;
        using Vector3D = Vector3D<Real>;
        using Box3 = Box3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        DynamicAngularTestIntersectorBox3Box3(const Box3& box0, const Box3& box1, Real tmax, int numSteps, const Vector3D& lhsVelocity, const Vector3D& lhsRotCenter,
                                              const Vector3D& lhsRotAxis, const Vector3D& rhsVelocity, const Vector3D& rhsRotCenter, const Vector3D& rhsRotAxis, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Box3 GetBox0() const noexcept;
        [[nodiscard]] const Box3 GetBox1() const noexcept;

    private:
        /// ��̬���Խ�����ѯ�����п���к㶨�����ٶȺͺ㶨�Ľ��ٶȡ� ��ת��ĳ����ǽ��ٶȡ�
        /// ΢�ַ������������Ԥ�⽻�㡣 ����numSteps������ODE������ĵ���������
        void Test();

        Box3 m_Box0;
        Box3 m_Box1;

        int m_NumSteps;
        Vector3D m_LhsRotCenter;
        Vector3D m_LhsRotAxis;
        Vector3D m_RhsRotCenter;
        Vector3D m_RhsRotAxis;
    };

    using FloatDynamicAngularTestIntersectorBox3Box3 = DynamicAngularTestIntersectorBox3Box3<float>;
    using DoubleDynamicAngularTestIntersectorBox3Box3 = DynamicAngularTestIntersectorBox3Box3<double>;
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_ANGULAR_TEST_INTERSECTOR_BOX3_BOX3_H
