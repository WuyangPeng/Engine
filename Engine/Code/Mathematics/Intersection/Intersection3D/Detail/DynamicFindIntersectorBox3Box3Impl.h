///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/25 10:53)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_BOX3_BOX3_IMPL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_BOX3_BOX3_IMPL_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/DynamicIntersector.h"
#include "Mathematics/Objects3D/Box3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE DynamicFindIntersectorBox3Box3Impl final
    {
    public:
        using ClassType = DynamicFindIntersectorBox3Box3Impl<Real>;
        using Vector3D = Vector3D<Real>;
        using Box3 = Box3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = Math<Real>;
        using Container = std::vector<Vector3D>;

    public:
        DynamicFindIntersectorBox3Box3Impl(const Box3& box0, const Box3& box1) noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Box3 GetBox0() const noexcept;
        [[nodiscard]] const Box3 GetBox1() const noexcept;

        [[nodiscard]] int GetQuantity() const;
        [[nodiscard]] const Vector3D GetPoint(int index) const;

        void SetPoint(const Container& point);

    private:
        Box3 m_Box0;
        Box3 m_Box1;

        // 动态查找相交的相交集。 最坏的情况是具有8个顶点的多边形。
        Container m_Point;
    };
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_BOX3_BOX3_IMPL_H
