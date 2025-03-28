///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 14:56)

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
        /// 动态测试交叉点查询，其中框具有恒定的线速度和恒定的角速度。 旋转轴的长度是角速度。
        /// 微分方程求解器用于预测交点。 输入numSteps是数字ODE求解器的迭代次数。
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
