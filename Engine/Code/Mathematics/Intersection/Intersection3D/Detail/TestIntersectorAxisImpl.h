///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/28 9:56)

#ifndef MATHEMATICS_INTERSECTION_TEST_INTERSECTOR_AXIS_IMPL_H
#define MATHEMATICS_INTERSECTION_TEST_INTERSECTOR_AXIS_IMPL_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/IntersectionFwd.h"
#include "Mathematics/Objects3D/Box3.h"
#include "Mathematics/Objects3D/Segment3.h"
#include "Mathematics/Objects3D/Triangle3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE TestIntersectorAxisImpl final
    {
    public:
        using ClassType = TestIntersectorAxisImpl<Real>;
        using Vector3D = Vector3D<Real>;
        using Triangle3 = Triangle3<Real>;
        using Box3 = Box3<Real>;
        using SegmentType = std::array<Vector3D, 2>;

        /// 测试查询投影间隔的交集。 输入的速度是objectVelocity1 - objectVelocity0之差。
        /// 计算第一次和最后一次接触时间。
        TestIntersectorAxisImpl(const Vector3D& axis, const SegmentType& segment, const Triangle3& triangle, const Vector3D& velocity, Real tmax);

        TestIntersectorAxisImpl(const Vector3D& axis, const SegmentType& segment, const Box3& box, const Vector3D& velocity, Real tmax);

        TestIntersectorAxisImpl(const Vector3D& axis, const Triangle3& triangle, const Box3& box, const Vector3D& velocity, Real tmax);

        TestIntersectorAxisImpl(const Vector3D& axis, const Box3& box0, const Box3& box1, const Vector3D& velocity, Real tmax);

        TestIntersectorAxisImpl(const Vector3D& axis, const Vector3D& velocity, Real min0, Real max0, Real min1, Real max1, Real tmax) noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] bool GetResult() const noexcept;
        [[nodiscard]] Real GetTFirst() const noexcept;
        [[nodiscard]] Real GetTLast() const noexcept;

    private:
        using Projections = std::pair<Real, Real>;

    private:
        // Projections.
        static Projections GetProjection(const Vector3D& axis, const SegmentType& segment) noexcept;

        static Projections GetProjection(const Vector3D& axis, const Triangle3& triangle);

        static Projections GetProjection(const Vector3D& axis, const Box3& box);

        //  预测的低级测试查询。
        void Test(const Vector3D& axis, const Vector3D& velocity, Real min0, Real max0, Real min1, Real max1, Real tmax) noexcept;

    private:
        bool m_Result;
        Real m_TFirst;
        Real m_TLast;
    };
}

#endif  // MATHEMATICS_INTERSECTION_TEST_INTERSECTOR_AXIS_IMPL_H
