///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 14:56)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_BOX3_BOX3_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_BOX3_BOX3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/DynamicIntersector.h"
#include "Mathematics/Objects3D/Box3.h"

namespace Mathematics
{
    template <typename Real>
    class DynamicFindIntersectorBox3Box3 : public DynamicIntersector<Real, Vector3>
    {
    public:
        using ClassType = DynamicFindIntersectorBox3Box3<Real>;
        using ParentType = DynamicIntersector<Real, Vector3>;

        using Vector3Type = Vector3<Real>;
        using Box3 = Box3<Real>;
        using Vector3ToolsType = Vector3Tools<Real>;
        using MathType = typename ParentType::MathType;

    public:
        DynamicFindIntersectorBox3Box3(const Box3& box0,
                                       const Box3& box1,
                                       Real tmax,
                                       const Vector3Type& lhsVelocity,
                                       const Vector3Type& rhsVelocity,
                                       const Real epsilon = MathType::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Box3 GetBox0() const noexcept;
        NODISCARD Box3 GetBox1() const noexcept;

        NODISCARD int GetQuantity() const;
        NODISCARD Vector3Type GetPoint(int index) const;

    private:
        using Container = std::vector<Vector3Type>;

    private:
        // 动态查找交叉点查询。 该触点组被计算出来。
        void Find();

    private:
        Box3 box0;
        Box3 box1;

        // 动态查找相交的相交集。 最坏的情况是具有8个顶点的多边形。
        Container point;
    };
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_BOX3_BOX3_H
