///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.6.0.1 (2021/01/06 16:46)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SEGMENT3_TRIANGLE3_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SEGMENT3_TRIANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/DynamicIntersector.h"
#include "Mathematics/Objects3D/Segment3.h"
#include "Mathematics/Objects3D/Triangle3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DynamicFindIntersectorSegment3Triangle3 : public DynamicIntersector<Real, Vector3D>
    {
    public:
        using ClassType = DynamicFindIntersectorSegment3Triangle3<Real>;
        using ParentType = DynamicIntersector<Real, Vector3D>;
        using Vector3D = Vector3D<Real>;
        using Segment3 = Segment3<Real>;
        using Triangle3 = Triangle3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        DynamicFindIntersectorSegment3Triangle3(const Segment3& segment, const Triangle3& triangle, Real tmax,
                                                const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Segment3 GetSegment() const noexcept;
        [[nodiscard]] const Triangle3 GetTriangle() const noexcept;

        [[nodiscard]] Real GetSegmentParameter() const noexcept;
        [[nodiscard]] Real GetTriangleBary0() const noexcept;
        [[nodiscard]] Real GetTriangleBary1() const noexcept;
        [[nodiscard]] Real GetTriangleBary2() const noexcept;

        /// ��Щ����ּ���ڶ�̬���ҽ�����ѯ֮����á�
        /// ���ڡ�Find()����ѯ��������ʹ��GetSegmentParameter()������GetTriangleBary?()�����Լ�����Ӵ��㡣
        [[nodiscard]] int GetQuantity() const noexcept;
        [[nodiscard]] const Vector3D GetPoint(int index) const;

    private:
        /// ��̬���ҽ�����ѯ�� ���е�������ʱ������ͨ��GetPoint(0)���ʵ�һ�����㣻
        /// ����ý�����һ���Σ������ͨ��GetPoint(0)��GetPoint(1)���ʵ�һ�����㣬����������£���ȡ�ĵ��Ƕζ˵㡣
        /// ��һ�ν�����ͨ��GetContactTime()���ʵġ�
        void Find();

        // Ҫ�ཻ�Ķ���
        Segment3 m_Segment;
        Triangle3 m_Triangle;

        // �йع̶���������Ϣ��
        Real m_SegmentParameter;
        Real m_TriangleBary0;
        Real m_TriangleBary1;
        Real m_TriangleBary2;

        // �йض�̬��������Ϣ��
        int m_Quantity;
        Vector3D m_Point0;
        Vector3D m_Point1;
    };

    using FloatDynamicFindIntersectorSegment3Triangle3 = DynamicFindIntersectorSegment3Triangle3<float>;
    using DoubleDynamicFindIntersectorSegment3Triangle3 = DynamicFindIntersectorSegment3Triangle3<double>;
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SEGMENT3_TRIANGLE3_H
