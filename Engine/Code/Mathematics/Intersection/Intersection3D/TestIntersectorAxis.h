///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/28 16:03)

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
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE TestIntersectorAxis final
    {
    public:
        using ClassType = TestIntersectorAxis<Real>;

        using Vector3 = Vector3<Real>;
        using Triangle3 = Triangle3<Real>;
        using Box3 = Box3<Real>;
        using SegmentType = std::array<Vector3, 2>;
        using Projections = std::pair<Real, Real>;

    public:
        /// ���Բ�ѯͶӰ����Ľ����� ������ٶ���objectVelocity1 - objectVelocity0֮�
        /// �����һ�κ����һ�νӴ�ʱ�䡣
        TestIntersectorAxis(const Vector3& axis, const SegmentType& segment, const Triangle3& triangle, const Vector3& velocity, Real tmax);

        TestIntersectorAxis(const Vector3& axis, const SegmentType& segment, const Box3& box, const Vector3& velocity, Real tmax);

        TestIntersectorAxis(const Vector3& axis, const Triangle3& triangle, const Box3& box, const Vector3& velocity, Real tmax);

        TestIntersectorAxis(const Vector3& axis, const Box3& box0, const Box3& box1, const Vector3& velocity, Real tmax);

        TestIntersectorAxis(const Vector3& axis, const Vector3& velocity, Real min0, Real max0, Real min1, Real max1, Real tmax) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool GetResult() const noexcept;
        NODISCARD Real GetTFirst() const noexcept;
        NODISCARD Real GetTLast() const noexcept;

        // Projections.
        NODISCARD static Projections GetProjection(const Vector3& axis, const SegmentType& segment) noexcept;

        NODISCARD static Projections GetProjection(const Vector3& axis, const Triangle3& triangle);

        NODISCARD static Projections GetProjection(const Vector3& axis, const Box3& box);

    private:
        //  Ԥ��ĵͼ����Բ�ѯ��
        void Test(const Vector3& axis, const Vector3& velocity, Real min0, Real max0, Real min1, Real max1, Real tmax) noexcept;

    private:
        bool result;
        Real tFirst;
        Real tLast;
    };
}

#endif  // MATHEMATICS_INTERSECTION_TEST_INTERSECTOR_AXIS_H
