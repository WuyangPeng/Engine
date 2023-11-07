///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 14:56)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_HALFSPACE3_BOX3_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_HALFSPACE3_BOX3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/DynamicIntersector.h"
#include "Mathematics/Objects3D/Box3.h"
#include "Mathematics/Objects3D/Plane3.h"

/// 半空间是平面法线指向的平面侧面上的点集。 这里的查询是一个盒子和半个空格的交集。
/// 在动态查找查询中，如果该框已经与半个空格相交，则返回值为'false'。 这个想法是寻找第一次接触。

namespace Mathematics
{
    template <typename Real>
    class DynamicFindIntersectorHalfspace3Box3 : public DynamicIntersector<Real, Vector3>
    {
    public:
        using ClassType = DynamicFindIntersectorHalfspace3Box3<Real>;
        using ParentType = DynamicIntersector<Real, Vector3>;

        using Vector3 = Vector3<Real>;
        using Box3 = Box3<Real>;
        using Plane3 = Plane3<Real>;
        using Vector3Tools = Vector3Tools<Real>;
        using Math = typename ParentType::Math;
        using Container = std::vector<Vector3>;

    public:
        DynamicFindIntersectorHalfspace3Box3(const Plane3& halfSpace,
                                             const Box3& box,
                                             Real tMax,
                                             const Vector3& lhsVelocity,
                                             const Vector3& rhsVelocity,
                                             const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Plane3 GetHalfspace() const noexcept;
        NODISCARD Box3 GetBox() const noexcept;

        // 相交点集合为空，点，线段或矩形。 函数 GetQuantity()返回0、1、2或4。
        NODISCARD int GetQuantity() const;
        NODISCARD Vector3 GetPoint(int index) const;

    private:
        void Find();

    private:
        // 要相交的对象。
        Plane3 halfSpace;
        Box3 box;

        // 有关交集的信息。
        Container point;
    };
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_HALFSPACE3_BOX3_H
