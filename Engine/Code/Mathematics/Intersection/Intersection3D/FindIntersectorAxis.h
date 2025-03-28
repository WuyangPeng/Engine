///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/28 15:04)

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

        using Vector3Type = Vector3<Real>;
        using Triangle3Type = Triangle3<Real>;
        using Box3Type = Box3<Real>;
        using SegmentType = std::array<Vector3Type, 2>;
        using IntersectorConfiguration = IntersectorConfiguration<Real>;

    public:
        /// ���Ҳ�ѯͶӰ����Ľ����� ������ٶ���objectVelocity1 - objectVelocity0֮�
        /// ����Ӵ��ĵ�һ�κ����һ�Σ��Լ����ڽӴ��ṹ��ͶӰ���Ӵ��ࣩ˳�����Ϣ��
        FindIntersectorAxis(const Vector3Type& axis, const SegmentType& segment, const Triangle3Type& triangle, const Vector3Type& velocity, Real tmax);

        FindIntersectorAxis(const Vector3Type& axis, const SegmentType& segment, const Box3Type& box, const Vector3Type& velocity, Real tmax);

        FindIntersectorAxis(const Vector3Type& axis, const Triangle3Type& triangle, const Box3Type& box, const Vector3Type& velocity, Real tmax);

        FindIntersectorAxis(const Vector3Type& axis, const Box3Type& box0, const Box3Type& box1, const Vector3Type& velocity, Real tmax);

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool GetResult() const noexcept;
        NODISCARD Real GetTFirst() const noexcept;
        NODISCARD Real GetTLast() const noexcept;

        NODISCARD ContactSide Getside() const noexcept;
        NODISCARD IntersectorConfiguration GetCfgFinal0() const noexcept;
        NODISCARD IntersectorConfiguration GetCfgFinal1() const noexcept;

        // Configurations.
        NODISCARD static IntersectorConfiguration GetConfiguration(const Vector3Type& axis, const SegmentType& segment);

        NODISCARD static IntersectorConfiguration GetConfiguration(const Vector3Type& axis, const Triangle3Type& triangle);

        NODISCARD static IntersectorConfiguration GetConfiguration(const Vector3Type& axis, const Box3Type& box);

    private:
        // ͶӰ�ĵͼ����Ҳ�ѯ��
        void Find(const Vector3Type& axis, const Vector3Type& velocity, const IntersectorConfiguration& cfg0Start, const IntersectorConfiguration& cfg1Start, Real tmax) noexcept;

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
