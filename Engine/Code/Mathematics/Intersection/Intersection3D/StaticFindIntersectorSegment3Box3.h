///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/28 15:08)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_BOX3_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_BOX3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects3D/Box3.h"
#include "Mathematics/Objects3D/Segment3.h"

namespace Mathematics
{
    template <typename Real>
    class StaticFindIntersectorSegment3Box3 : public StaticIntersector<Real, Vector3>
    {
    public:
        using ClassType = StaticFindIntersectorSegment3Box3<Real>;
        using ParentType = StaticIntersector<Real, Vector3>;

        using Vector3 = Vector3<Real>;
        using Segment3 = Segment3<Real>;
        using Box3 = Box3<Real>;
        using Vector3Tools = Vector3Tools<Real>;
        using Math = typename ParentType::MathType;

    public:
        StaticFindIntersectorSegment3Box3(const Segment3& segment, const Box3& box, bool solid, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Segment3 GetSegment() const noexcept;
        NODISCARD Box3 GetBox() const noexcept;

        NODISCARD int GetQuantity() const noexcept;
        NODISCARD Vector3 GetPoint(int index) const;

    private:
        // ��̬���ҽ�����ѯ�� ��������ͨ��GetQuantity()��GetPoint(i)���ʡ�
        void Find();

    private:
        Segment3 segment;
        Box3 box;
        bool solid;

        int quantity;
        Vector3 point0;
        Vector3 point1;
    };
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_BOX3_H
