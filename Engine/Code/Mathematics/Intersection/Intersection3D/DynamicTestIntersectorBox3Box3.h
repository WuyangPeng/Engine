///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 15:01)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_BOX3_BOX3_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_BOX3_BOX3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/DynamicIntersector.h"
#include "Mathematics/Objects3D/Box3.h"

namespace Mathematics
{
    template <typename Real>
    class DynamicTestIntersectorBox3Box3 : public DynamicIntersector<Real, Vector3>
    {
    public:
        using ClassType = DynamicTestIntersectorBox3Box3<Real>;
        using ParentType = DynamicIntersector<Real, Vector3>;

        using Vector3 = Vector3<Real>;
        using Box3 = Box3<Real>;
        using Vector3Tools = Vector3Tools<Real>;
        using Math = typename ParentType::MathType;

    public:
        DynamicTestIntersectorBox3Box3(const Box3& box0, const Box3& box1, Real tmax, const Vector3& lhsVelocity, const Vector3& rhsVelocity, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Box3 GetBox0() const noexcept;
        NODISCARD Box3 GetBox1() const noexcept;

    private:
        using Separated = std::pair<bool, Real>;

    private:
        /// 动态测试相交查询。 计算第一次相交时间（如果有），但不计算有关相交集的任何信息。
        void Test();

        /// 支持动态查询。 输入框在潜在分隔轴上的投影间隔，间隔的相对速度以及查询的最大时间。
        /// 输出是第一次分离失败，最后一次是沿着该轴再次开始分离。
        /// 在某种意义上说，输出是“更新”，对于潜在的分离轴，该函数被重复调用。
        /// 仅在输出第一次大于输入第一次时才更新。 仅在上次输出小于上次输入时才更新。
        ///
        /// 注意：可以使用BoxBoxAxisTest函数，但是box-box代码可以优化box在各个轴上的投影。
        /// 该函数有效地是BoxBoxAxisTest，但是没有轴方向和速度的点积以获得速度。 优化是通过较少的操作来计算速度。
        NODISCARD Separated IsSeparated(Real min0, Real max0, Real min1, Real max1, Real speed, Real tmax, Real tlast) noexcept;

    private:
        Box3 box0;
        Box3 box1;
    };
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_BOX3_BOX3_H
