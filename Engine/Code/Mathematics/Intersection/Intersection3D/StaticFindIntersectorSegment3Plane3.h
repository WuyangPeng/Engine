///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/28 15:08)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_PLANE3_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_PLANE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects3D/Plane3.h"
#include "Mathematics/Objects3D/Segment3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorSegment3Plane3 : public StaticIntersector<Real, Vector3>
    {
    public:
        using ClassType = StaticFindIntersectorSegment3Plane3<Real>;
        using ParentType = StaticIntersector<Real, Vector3>;

        using Vector3Type = Vector3<Real>;
        using Segment3Type = Segment3<Real>;
        using Plane3Type = Plane3<Real>;
        using Vector3ToolsType = Vector3Tools<Real>;
        using MathType = typename ParentType::MathType;

    public:
        StaticFindIntersectorSegment3Plane3(const Segment3Type& segment, const Plane3Type& plane, const Real epsilon = MathType::GetZeroTolerance()) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Segment3Type GetSegment() const noexcept;
        NODISCARD Plane3Type GetPlane() const noexcept;

        NODISCARD Real GetSegmentParameter() const noexcept;

    private:
        // ���ҽ�����ѯ�� �ཻ��ΪP = origin + t * direction��|t| <= e������e���߶η�Χ��
        void Find() noexcept;

    private:
        Segment3Type segment;
        Plane3Type plane;

        Real segmentParameter;
    };
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_PLANE3_H
