///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/06/08 19:33)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SEGMENT3_TRIANGLE3_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SEGMENT3_TRIANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/DynamicIntersector.h"
#include "Mathematics/Objects3D/Segment3.h"
#include "Mathematics/Objects3D/Triangle3.h"

namespace Mathematics
{
    template <typename Real>
    class DynamicFindIntersectorSegment3Triangle3 : public DynamicIntersector<Real, Vector3>
    {
    public:
        using ClassType = DynamicFindIntersectorSegment3Triangle3<Real>;
        using ParentType = DynamicIntersector<Real, Vector3>;
        using Vector3 = Vector3<Real>;
        using Segment3 = Segment3<Real>;
        using Triangle3 = Triangle3<Real>;
        using Vector3Tools = Vector3Tools<Real>;
        using Math = typename ParentType::Math;

    public:
        DynamicFindIntersectorSegment3Triangle3(const Segment3& segment,
                                                const Triangle3& triangle,
                                                Real tmax,
                                                const Vector3& lhsVelocity,
                                                const Vector3& rhsVelocity,
                                                const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Segment3 GetSegment() const noexcept;
        NODISCARD Triangle3 GetTriangle() const noexcept;

        NODISCARD Real GetSegmentParameter() const noexcept;
        NODISCARD Real GetTriangleBary0() const noexcept;
        NODISCARD Real GetTriangleBary1() const noexcept;
        NODISCARD Real GetTriangleBary2() const noexcept;

        /// ��Щ����ּ���ڶ�̬���ҽ�����ѯ֮����á�
        /// ���ڡ�Find()����ѯ��������ʹ��GetSegmentParameter()������GetTriangleBary?()�����Լ�����Ӵ��㡣
        NODISCARD int GetQuantity() const noexcept;
        NODISCARD Vector3 GetPoint(int index) const;

    private:
        /// ��̬���ҽ�����ѯ�� ���е�������ʱ������ͨ��GetPoint(0)���ʵ�һ�����㣻
        /// ����ý�����һ���Σ������ͨ��GetPoint(0)��GetPoint(1)���ʵ�һ�����㣬����������£���ȡ�ĵ��Ƕζ˵㡣
        /// ��һ�ν�����ͨ��GetContactTime()���ʵġ�
        void Find();

    private:
        // Ҫ�ཻ�Ķ���
        Segment3 segment;
        Triangle3 triangle;

        // �йع̶���������Ϣ��
        Real segmentParameter;
        Real triangleBary0;
        Real triangleBary1;
        Real triangleBary2;

        // �йض�̬��������Ϣ��
        int quantity;
        Vector3 point0;
        Vector3 point1;
    };
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SEGMENT3_TRIANGLE3_H
