///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/21 12:48)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRAHEDRON3_TETRAHEDRON3_IMPL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRAHEDRON3_TETRAHEDRON3_IMPL_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects3D/Tetrahedron3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE StaticFindIntersectorTetrahedron3Tetrahedron3Impl final
    {
    public:
        using ClassType = StaticFindIntersectorTetrahedron3Tetrahedron3Impl<Real>;
        using Vector3D = Vector3D<Real>;
        using Tetrahedron3 = Tetrahedron3<Real>;
        using Plane3 = Plane3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = Math<Real>;
        using IntersectionContainer = std::vector<Tetrahedron3>;

    public:
        StaticFindIntersectorTetrahedron3Tetrahedron3Impl(const Tetrahedron3& tetrahedron0, const Tetrahedron3& tetrahedron1) noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Tetrahedron3 GetTetrahedron0() const noexcept;
        [[nodiscard]] const Tetrahedron3 GetTetrahedron1() const noexcept;

        [[nodiscard]] const IntersectionContainer GetIntersection() const;

        void SetIntersectionContainer(const IntersectionContainer& intersectionContainer);

    private:
        Tetrahedron3 m_Tetrahedron0;
        Tetrahedron3 m_Tetrahedron1;

        IntersectionContainer m_Intersection;
    };
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRAHEDRON3_TETRAHEDRON3_IMPL_H
