///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/28 15:09)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_TRIANGLE3_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_TRIANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects3D/Segment3.h"
#include "Mathematics/Objects3D/Triangle3.h"

namespace Mathematics
{
    template <typename Real>
    class StaticFindIntersectorSegment3Triangle3 : public StaticIntersector<Real, Vector3>
    {
    public:
        using ClassType = StaticFindIntersectorSegment3Triangle3<Real>;
        using ParentType = StaticIntersector<Real, Vector3>;

        using Vector3Type = Vector3<Real>;
        using Segment3 = Segment3<Real>;
        using Triangle3 = Triangle3<Real>;
        using Vector3ToolsType = Vector3Tools<Real>;
        using MathType = typename ParentType::MathType;

    public:
        StaticFindIntersectorSegment3Triangle3(const Segment3& segment, const Triangle3& triangle, const Real epsilon = MathType::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Segment3 GetSegment() const noexcept;
        NODISCARD Triangle3 GetTriangle() const noexcept;

        // ���ҽ�����ѯ�� �ཻ��Ϊ P = origin + t * direction = b0 * V0 + b1 * V1 + b2 * V2
        NODISCARD Real GetSegmentParameter() const noexcept;
        NODISCARD Real GetTriBary0() const noexcept;
        NODISCARD Real GetTriBary1() const noexcept;
        NODISCARD Real GetTriBary2() const noexcept;

        /// ע�⣺��Щ����ּ���ڶ�̬�����ཻ��ѯ֮����á�
        /// ���ڡ� bool Find()����ѯ��������ʹ��GetSegmentParameter()������GetTriBary?()�����Լ�����Ӵ��㡣
        ///  ���ڣ���Щ������֧�֡�bool Find()����ѯ��
        NODISCARD int GetQuantity() const noexcept;
        NODISCARD Vector3Type GetPoint(int index) const;

    private:
        void Find();

        Segment3 segment;
        Triangle3 triangle;

        // �йع̶���������Ϣ��
        Real segmentParameter;
        Real triBary0;
        Real triBary1;
        Real triBary2;

        int quantity;
        Vector3Type point0;
        Vector3Type point1;
    };
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_TRIANGLE3_H
