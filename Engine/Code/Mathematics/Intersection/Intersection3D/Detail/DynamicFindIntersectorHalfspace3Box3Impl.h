///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/31 16:26)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_HALFSPACE3_BOX3_IMPL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_HALFSPACE3_BOX3_IMPL_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Box3.h"
#include "Mathematics/Objects3D/Plane3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE DynamicFindIntersectorHalfspace3Box3Impl final
    {
    public:
        using ClassType = DynamicFindIntersectorHalfspace3Box3Impl<Real>;
        using Vector3D = Vector3D<Real>;
        using Box3 = Box3<Real>;
        using Plane3 = Plane3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = Math<Real>;
        using Container = std::vector<Vector3D>;

    public:
        DynamicFindIntersectorHalfspace3Box3Impl(const Plane3& halfspace, const Box3& box) noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Plane3 GetHalfspace() const noexcept;
        [[nodiscard]] const Box3 GetBox() const noexcept;

        // 相交点集合为空，点，线段或矩形。 函数 GetQuantity()返回0、1、2或4。
        [[nodiscard]] int GetQuantity() const;
        [[nodiscard]] const Vector3D GetPoint(int index) const;

        void SetPoint(const Container& point);

    private:
        // 要相交的对象。
        Plane3 m_Halfspace;
        Box3 m_Box;

        // 有关交集的信息。
        Container m_Point;
    };
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_HALFSPACE3_BOX3_IMPL_H
