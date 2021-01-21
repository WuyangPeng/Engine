///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/07 10:51)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_TRIANGLE3_BOX3_IMPL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_TRIANGLE3_BOX3_IMPL_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Box3.h"
#include "Mathematics/Objects3D/Triangle3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE DynamicFindIntersectorTriangle3Box3Impl final
    {
    public:
        using ClassType = DynamicFindIntersectorTriangle3Box3<Real>;
        using Vector3D = Vector3D<Real>;
        using Triangle3 = Triangle3<Real>;
        using Box3 = Box3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = Math<Real>;
        using Container = std::vector<Vector3D>;

    public:
        DynamicFindIntersectorTriangle3Box3Impl(const Triangle3& triangle, const Box3& box) noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Triangle3 GetTriangle() const noexcept;
        [[nodiscard]] const Box3 GetBox() const noexcept;

        [[nodiscard]] int GetQuantity() const;
        [[nodiscard]] const Vector3D GetPoint(int index) const;

        void SetPoint(const Container& point);

    private:
        // 要相交的对象。
        Triangle3 m_Triangle;
        Box3 m_Box;

        /// 静态查询的交集。 一个三角形最多可以在7个顶点处相交一个框。
        Container m_Point;
    };
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_TRIANGLE3_BOX3_IMPL_H
