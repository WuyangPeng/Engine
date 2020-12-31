///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/29 10:53)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_BOX3_BOX3_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_BOX3_BOX3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/DynamicIntersector.h"
#include "Mathematics/Objects3D/Box3.h"

namespace Mathematics
{
    template <typename Real>
    class DynamicFindIntersectorBox3Box3Impl;

    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<DynamicFindIntersectorBox3Box3Impl<float>>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<DynamicFindIntersectorBox3Box3Impl<double>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<DynamicFindIntersectorBox3Box3Impl<Real>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DynamicFindIntersectorBox3Box3 : public DynamicIntersector<Real, Vector3D>
    {
    public:
        using DynamicFindIntersectorBox3Box3Impl = DynamicFindIntersectorBox3Box3Impl<Real>;
        PERFORMANCE_UNSHARE_CLASSES_TYPE_DECLARE(DynamicFindIntersectorBox3Box3);

        using ParentType = DynamicIntersector<Real, Vector3D>;
        using Vector3D = Vector3D<Real>;
        using Box3 = Box3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        DynamicFindIntersectorBox3Box3(
            const Box3& box0,
            const Box3& box1,
            Real tmax,
            const Vector3D& lhsVelocity,
            const Vector3D& rhsVelocity,
            const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Box3 GetBox0() const noexcept;
        [[nodiscard]] const Box3 GetBox1() const noexcept;

        [[nodiscard]] int GetQuantity() const;
        [[nodiscard]] const Vector3D GetPoint(int index) const;

    private:
        // 动态查找交叉点查询。 该触点组被计算出来。
        void Find();

    private:
        IMPL_TYPE_DECLARE(DynamicFindIntersectorBox3Box3);
    };

    using FloatDynamicFindIntersectorBox3Box3 = DynamicFindIntersectorBox3Box3<float>;
    using DoubleDynamicFindIntersectorBox3Box3 = DynamicFindIntersectorBox3Box3<double>;
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_BOX3_BOX3_H
