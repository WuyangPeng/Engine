///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/28 14:56)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_ANGULAR_TEST_INTERSECTOR_BOX3_BOX3_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_ANGULAR_TEST_INTERSECTOR_BOX3_BOX3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/DynamicIntersector.h"
#include "Mathematics/Objects3D/Box3.h"

namespace Mathematics
{
    template <typename Real>
    class DynamicAngularTestIntersectorBox3Box3 : public DynamicIntersector<Real, Vector3>
    {
    public:
        using ClassType = DynamicAngularTestIntersectorBox3Box3<Real>;
        using ParentType = DynamicIntersector<Real, Vector3>;

        using Vector3Type = Vector3<Real>;
        using Box3 = Box3<Real>;
        using Vector3ToolsType = Vector3Tools<Real>;
        using MathType = typename ParentType::MathType;

    public:
        DynamicAngularTestIntersectorBox3Box3(const Box3& box0,
                                              const Box3& box1,
                                              Real tMax,
                                              int numSteps,
                                              const Vector3Type& lhsVelocity,
                                              const Vector3Type& lhsRotCenter,
                                              const Vector3Type& lhsRotAxis,
                                              const Vector3Type& rhsVelocity,
                                              const Vector3Type& rhsRotCenter,
                                              const Vector3Type& rhsRotAxis,
                                              const Real epsilon = MathType::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Box3 GetBox0() const noexcept;
        NODISCARD Box3 GetBox1() const noexcept;

    private:
        /// ��̬���Խ�����ѯ�����п���к㶨�����ٶȺͺ㶨�Ľ��ٶȡ� ��ת��ĳ����ǽ��ٶȡ�
        /// ΢�ַ������������Ԥ�⽻�㡣 ����numSteps������ODE������ĵ���������
        void Test();

    private:
        Box3 box0;
        Box3 box1;

        int numSteps;
        Vector3Type lhsRotCenter;
        Vector3Type lhsRotAxis;
        Vector3Type rhsRotCenter;
        Vector3Type rhsRotAxis;
    };
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_ANGULAR_TEST_INTERSECTOR_BOX3_BOX3_H
