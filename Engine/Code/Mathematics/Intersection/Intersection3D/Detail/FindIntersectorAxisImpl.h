///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.6.0.0 (2020/12/28 13:47)

#ifndef MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_AXIS_IMPL_H
#define MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_AXIS_IMPL_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/Intersection3D/IntersectorConfiguration.h"
#include "Mathematics/Intersection/IntersectionFwd.h"
#include "Mathematics/Objects3D/Box3.h"
#include "Mathematics/Objects3D/Segment3.h"
#include "Mathematics/Objects3D/Triangle3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE FindIntersectorAxisImpl final
    {
    public:
        using ClassType = FindIntersectorAxisImpl<Real>;
        using Vector3D = Vector3D<Real>;
        using Triangle3 = Triangle3<Real>;
        using Box3 = Box3<Real>;
        using SegmentType = std::array<Vector3D, 2>;
        using IntersectorConfiguration = IntersectorConfiguration<Real>;

        /// ���Ҳ�ѯͶӰ����Ľ����� ������ٶ���objectVelocity1 - objectVelocity0֮�
        /// ����Ӵ��ĵ�һ�κ����һ�Σ��Լ����ڽӴ��ṹ��ͶӰ���Ӵ��ࣩ˳�����Ϣ��
        FindIntersectorAxisImpl(const Vector3D& axis, const SegmentType& segment, const Triangle3& triangle, const Vector3D& velocity, Real tmax);

        FindIntersectorAxisImpl(const Vector3D& axis, const SegmentType& segment, const Box3& box, const Vector3D& velocity, Real tmax);

        FindIntersectorAxisImpl(const Vector3D& axis, const Triangle3& triangle, const Box3& box, const Vector3D& velocity, Real tmax);

        FindIntersectorAxisImpl(const Vector3D& axis, const Box3& box0, const Box3& box1, const Vector3D& velocity, Real tmax);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] bool GetResult() const noexcept;
        [[nodiscard]] Real GetTFirst() const noexcept;
        [[nodiscard]] Real GetTLast() const noexcept;

        [[nodiscard]] ContactSide Getside() const noexcept;
        [[nodiscard]] IntersectorConfiguration GetCfgFinal0() const;
        [[nodiscard]] IntersectorConfiguration GetCfgFinal1() const;

        // Configurations.
        static IntersectorConfiguration GetConfiguration(const Vector3D& axis, const SegmentType& segment);

        static IntersectorConfiguration GetConfiguration(const Vector3D& axis, const Triangle3& triangle);

        static IntersectorConfiguration GetConfiguration(const Vector3D& axis, const Box3& box);

    private:
        using Projections = std::pair<Real, Real>;

        // ͶӰ�ĵͼ����Ҳ�ѯ��
        void Find(const Vector3D& axis, const Vector3D& velocity, const IntersectorConfiguration& cfg0Start, const IntersectorConfiguration& cfg1Start, Real tmax);

    private:
        bool m_Result;
        Real m_TFirst;
        Real m_TLast;
        ContactSide m_Side;
        IntersectorConfiguration m_CfgFinal0;
        IntersectorConfiguration m_CfgFinal1;
    };
}

#endif  // MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_AXIS_IMPL_H
