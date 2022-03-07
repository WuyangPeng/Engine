///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.3 (2022/02/26 14:36)

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
    // 集成的时间步骤。
    auto stepSize = this->GetTMax() / static_cast<Real>(numSteps);

    // 初始化子间隔框。
    auto subBox0 = box0;
    auto subBox1 = box1;

    // 使用欧拉方法对微分方程进行积分。
    for (auto step = 1; step <= numSteps; ++step)
    {
        // 计算框速度和相交的测试框。
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

        // 更新盒子中心。
        subBox0 = subBox0.GetMove(1, subVelocity0);
        subBox1 = subBox1.GetMove(1, subVelocity1);

        // 更新盒子轴。
        using AxisType = std::vector<Vector3>;
        AxisType axis0{ subBox0.GetAxis(0) + stepSize * Vector3Tools::CrossProduct(lhsRotAxis, subBox0.GetAxis(0)),
                        subBox0.GetAxis(1) + stepSize * Vector3Tools::CrossProduct(lhsRotAxis, subBox0.GetAxis(1)),
                        subBox0.GetAxis(2) + stepSize * Vector3Tools::CrossProduct(lhsRotAxis, subBox0.GetAxis(2)) };
        AxisType axis1{ subBox1.GetAxis(0) + stepSize * Vector3Tools::CrossProduct(rhsRotAxis, subBox1.GetAxis(0)),
                        subBox1.GetAxis(1) + stepSize * Vector3Tools::CrossProduct(rhsRotAxis, subBox1.GetAxis(1)),
                        subBox1.GetAxis(2) + stepSize * Vector3Tools::CrossProduct(rhsRotAxis, subBox1.GetAxis(2)) };

        /// 使用Gram-Schmidt对更新的轴进行正则化。
        /// 注意：如果T/N小而N小，则可以在假定更新轴接近正交的情况下删除此昂贵的步长。
        const auto Vector3Orthonormalize0 = Vector3Tools::Orthonormalize(axis0);
        const auto Vector3Orthonormalize1 = Vector3Tools::Orthonormalize(axis1);

        subBox0 = Box3{ subBox0.GetCenter(), Vector3Orthonormalize0.GetUVector(),
                        Vector3Orthonormalize0.GetVVector(), Vector3Orthonormalize0.GetWVector(),
                        subBox0.GetExtent0(), subBox0.GetExtent1(), subBox0.GetExtent2() };

        subBox1 = Box3{ subBox1.GetCenter(), Vector3Orthonormalize1.GetUVector(),
                        Vector3Orthonormalize1.GetVVector(), Vector3Orthonormalize1.GetWVector(),
                        subBox1.GetExtent0(), subBox1.GetExtent1(), subBox1.GetExtent2() };
    }

    /// 注意：如果框不相交，则应用程序可能需要将框移动/旋转到其新位置。
    /// 在这种情况下，您想返回subBox0和subBox1的最终值，以便应用程序可以设置box0 < -subBox0和box1 < -subBox1。
    /// 否则，应用程序将不得不再次求解微分方程或使用封闭形式的刚性运动解来计算新的盒位置。

    this->SetIntersectionType(IntersectionType::Empty); 
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_ANGULAR_TEST_INTERSECTOR_BOX3_BOX3_DETAIL_H