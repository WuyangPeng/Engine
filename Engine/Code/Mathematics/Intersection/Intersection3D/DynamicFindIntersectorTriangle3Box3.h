///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 15:01)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_TRIANGLE3_BOX3_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_TRIANGLE3_BOX3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/DynamicIntersector.h"
#include "Mathematics/Objects3D/Box3.h"
#include "Mathematics/Objects3D/Triangle3.h"

namespace Mathematics
{
    template <typename Real>
    class DynamicFindIntersectorTriangle3Box3 : public DynamicIntersector<Real, Vector3>
    {
    public:
        using ClassType = DynamicFindIntersectorTriangle3Box3<Real>;
        using ParentType = DynamicIntersector<Real, Vector3>;

        using Vector3Type = Vector3<Real>;
        using Triangle3Type = Triangle3<Real>;
        using Box3Type = Box3<Real>;
        using Vector3ToolsType = Vector3Tools<Real>;
        using MathType = typename ParentType::MathType;
        using Container = std::vector<Vector3Type>;

    public:
        DynamicFindIntersectorTriangle3Box3(const Triangle3Type& triangle,
                                            const Box3Type& box,
                                            Real tMax,
                                            const Vector3Type& lhsVelocity,
                                            const Vector3Type& rhsVelocity,
                                            const Real epsilon = MathType::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Triangle3Type GetTriangle() const noexcept;
        NODISCARD Box3Type GetBox() const noexcept;

        NODISCARD int GetQuantity() const;
        NODISCARD Vector3Type GetPoint(int index) const;

    private:
        void Find();

    private:
        // 要相交的对象。
        Triangle3Type triangle;
        Box3Type box;

        /// 静态查询的交集。 一个三角形最多可以在7个顶点处相交一个框。
        Container point;
    };
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_TRIANGLE3_BOX3_H
