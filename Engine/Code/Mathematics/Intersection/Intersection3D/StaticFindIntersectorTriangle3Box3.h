///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/21 13:39)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRIANGLE3_BOX3_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRIANGLE3_BOX3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects3D/Box3.h"
#include "Mathematics/Objects3D/Triangle3.h"

namespace Mathematics
{
    template <typename Real>
    class StaticFindIntersectorTriangle3Box3Impl;

    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<StaticFindIntersectorTriangle3Box3Impl<float>>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<StaticFindIntersectorTriangle3Box3Impl<double>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<StaticFindIntersectorTriangle3Box3Impl<Real>>;

    template <typename Real>
    class StaticFindIntersectorTriangle3Box3 : public StaticIntersector<Real, Vector3D>
    {
    public:
        using StaticFindIntersectorTriangle3Box3Impl = StaticFindIntersectorTriangle3Box3Impl<Real>;
        PERFORMANCE_UNSHARE_CLASSES_TYPE_DECLARE(StaticFindIntersectorTriangle3Box3);

        using ParentType = StaticIntersector<Real, Vector3D>;
        using Vector3D = Vector3D<Real>;
        using Triangle3 = Triangle3<Real>;
        using Box3 = Box3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        StaticFindIntersectorTriangle3Box3(const Triangle3& triangle, const Box3& box, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Triangle3 GetTriangle() const noexcept;
        [[nodiscard]] const Box3 GetBox() const noexcept;

        [[nodiscard]] int GetQuantity() const;
        [[nodiscard]] const Vector3D GetPoint(int index) const;

    private:
        void Find();

    private:
        IMPL_TYPE_DECLARE(StaticFindIntersectorTriangle3Box3);
    };

    using FloatStaticFindIntersectorTriangle3Box3 = StaticFindIntersectorTriangle3Box3<float>;
    using DoubleStaticFindIntersectorTriangle3Box3 = StaticFindIntersectorTriangle3Box3<double>;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRIANGLE3_BOX3_H
