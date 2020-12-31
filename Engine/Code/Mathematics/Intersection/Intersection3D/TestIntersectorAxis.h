///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.6.0.0 (2020/12/28 11:52)

#ifndef MATHEMATICS_INTERSECTION_TEST_INTERSECTOR_AXIS_H
#define MATHEMATICS_INTERSECTION_TEST_INTERSECTOR_AXIS_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/IntersectionFwd.h"
#include "Mathematics/Objects3D/Box3.h"
#include "Mathematics/Objects3D/Segment3.h"
#include "Mathematics/Objects3D/Triangle3.h"

namespace Mathematics
{
    template <typename Real>
    class TestIntersectorAxisImpl;

    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<TestIntersectorAxisImpl<float>>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<TestIntersectorAxisImpl<double>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<TestIntersectorAxisImpl<Real>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE TestIntersectorAxis final
    {
    public:
        using TestIntersectorAxisImpl = TestIntersectorAxisImpl<Real>;
        PERFORMANCE_UNSHARE_CLASSES_TYPE_DECLARE(TestIntersectorAxis);

        using Vector3D = Vector3D<Real>;
        using Triangle3 = Triangle3<Real>;
        using Box3 = Box3<Real>;
        using SegmentType = std::array<Vector3D, 2>;

        /// ���Բ�ѯͶӰ����Ľ����� ������ٶ���objectVelocity1 - objectVelocity0֮�
        /// �����һ�κ����һ�νӴ�ʱ�䡣
        TestIntersectorAxis(const Vector3D& axis, const SegmentType& segment, const Triangle3& triangle, const Vector3D& velocity, Real tmax);

        TestIntersectorAxis(const Vector3D& axis, const SegmentType& segment, const Box3& box, const Vector3D& velocity, Real tmax);

        TestIntersectorAxis(const Vector3D& axis, const Triangle3& triangle, const Box3& box, const Vector3D& velocity, Real tmax);

        TestIntersectorAxis(const Vector3D& axis, const Box3& box0, const Box3& box1, const Vector3D& velocity, Real tmax);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] bool GetResult() const noexcept;
        [[nodiscard]] Real GetTFirst() const noexcept;
        [[nodiscard]] Real GetTLast() const noexcept;

    private:
        IMPL_TYPE_DECLARE(TestIntersectorAxis);
    };

    using FloatTestIntersectorAxis = TestIntersectorAxis<float>;
    using DoubleTestIntersectorAxis = TestIntersectorAxis<double>;
}

#endif  // MATHEMATICS_INTERSECTION_TEST_INTERSECTOR_AXIS_H
