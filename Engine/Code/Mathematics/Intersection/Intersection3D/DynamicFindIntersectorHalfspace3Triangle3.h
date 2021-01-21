///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/04 13:50)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_HALFSPACE3_TRIANGLE3_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_HALFSPACE3_TRIANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/DynamicIntersector.h"
#include "Mathematics/Objects3D/Plane3.h"
#include "Mathematics/Objects3D/Triangle3.h"

/// 半空间是平面法线指向的平面侧面上的点集。 这里的查询是三角形和半空间的交集。
/// 在动态查找查询中，如果三角形已经与半空间相交，则返回值为'false'。 这个想法是寻找第一次接触。

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DynamicFindIntersectorHalfspace3Triangle3 : public DynamicIntersector<Real, Vector3D>
    {
    public:
        using ClassType = DynamicFindIntersectorHalfspace3Triangle3<Real>;
        using ParentType = DynamicIntersector<Real, Vector3D>;
        using Vector3D = Vector3D<Real>;
        using Triangle3 = Triangle3<Real>;
        using Plane3 = Plane3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        DynamicFindIntersectorHalfspace3Triangle3(const Plane3& halfspace, const Triangle3& triangle, Real tmax,
                                                  const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Plane3 GetHalfspace() const noexcept;
        [[nodiscard]] const Triangle3 GetTriangle() const noexcept;

        /// 相交集为空，点，线段或三角形。 函数GetQuantity()返回0、1、2或3。
        [[nodiscard]] int GetQuantity() const noexcept;
        [[nodiscard]] const Vector3D GetPoint(int index) const;

    private:
        void Find();

        Plane3 m_Halfspace;
        Triangle3 m_Triangle;

        int m_Quantity;
        Vector3D m_Point0;
        Vector3D m_Point1;
        Vector3D m_Point2;
    };

    using FloatDynamicFindIntersectorHalfspace3Triangle3 = DynamicFindIntersectorHalfspace3Triangle3<float>;
    using DoubleDynamicFindIntersectorHalfspace3Triangle3 = DynamicFindIntersectorHalfspace3Triangle3<double>;
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_HALFSPACE3_TRIANGLE3_H
