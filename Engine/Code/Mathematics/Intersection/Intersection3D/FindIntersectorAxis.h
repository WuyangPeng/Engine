///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.3 (2022/02/25 21:53)

#ifndef MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_AXIS_H
#define MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_AXIS_H

#include "Mathematics/MathematicsDll.h"

#include "IntersectorConfiguration.h"
#include "Mathematics/Intersection/IntersectionFwd.h"
#include "Mathematics/Objects3D/Box3.h"
#include "Mathematics/Objects3D/Segment3.h"
#include "Mathematics/Objects3D/Triangle3.h"

namespace Mathematics
{
    template <typename Real>
    class FindIntersectorAxis final
    {
    public:
        using ClassType = FindIntersectorAxis<Real>;
        using Vector3 = Vector3<Real>;
        using Triangle3 = Triangle3<Real>;
        using Box3 = Box3<Real>;
        using SegmentType = std::array<Vector3, 2>;
        using IntersectorConfiguration = IntersectorConfiguration<Real>;

    public:
        /// ���Ҳ�ѯͶӰ����Ľ����� ������ٶ���objectVelocity1 - objectVelocity0֮�
        /// ����Ӵ��ĵ�һ�κ����һ�Σ��Լ����ڽӴ��ṹ��ͶӰ���Ӵ��ࣩ˳�����Ϣ��
        FindIntersectorAxis(const Vector3& axis, const SegmentType& segment, const Triangle3& triangle, const Vector3& velocity, Real tmax);

        FindIntersectorAxis(const Vector3& axis, const SegmentType& segment, const Box3& box, const Vector3& velocity, Real tmax);

        FindIntersectorAxis(const Vector3& axis, const Triangle3& triangle, const Box3& box, const Vector3& velocity, Real tmax);

        FindIntersectorAxis(const Vector3& axis, const Box3& box0, const Box3& box1, const Vector3& velocity, Real tmax);

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool GetResult() const noexcept;
        NODISCARD Real GetTFirst() const noexcept;
        NODISCARD Real GetTLast() const noexcept;

        NODISCARD ContactSide Getside() const noexcept;
        NODISCARD IntersectorConfiguration GetCfgFinal0() const noexcept;
        NODISCARD IntersectorConfiguration GetCfgFinal1() const noexcept;

        // Configurations.
        NODISCARD static IntersectorConfiguration GetConfiguration(const Vector3& axis, const SegmentType& segment);

        NODISCARD static IntersectorConfiguration GetConfiguration(const Vector3& axis, const Triangle3& triangle);

        NODISCARD static IntersectorConfiguration GetConfiguration(const Vector3& axis, const Box3& box);

    private:
        // ͶӰ�ĵͼ����Ҳ�ѯ��
        void Find(const Vector3& axis, const Vector3& velocity, const IntersectorConfiguration& cfg0Start, const IntersectorConfiguration& cfg1Start, Real tmax) noexcept;

    private:
        bool result;
        Real tFirst;
        Real tLast;
        ContactSide side;
        IntersectorConfiguration cfgFinal0;
        IntersectorConfiguration cfgFinal1;
    };
}

#endif  // MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_AXIS_H
