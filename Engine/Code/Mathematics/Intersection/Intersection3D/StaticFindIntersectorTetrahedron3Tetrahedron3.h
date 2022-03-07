///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.3 (2022/03/02 23:45)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRAHEDRON3_TETRAHEDRON3_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRAHEDRON3_TETRAHEDRON3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects3D/Tetrahedron3.h"

namespace Mathematics
{
    template <typename Real>
    class StaticFindIntersectorTetrahedron3Tetrahedron3 : public StaticIntersector<Real, Vector3>
    {
    public:
        using ClassType = StaticFindIntersectorTetrahedron3Tetrahedron3<Real>;
        using ParentType = StaticIntersector<Real, Vector3>;
        using Vector3 = Vector3<Real>;
        using Tetrahedron3 = Tetrahedron3<Real>;
        using Plane3 = Plane3<Real>;
        using Vector3Tools = Vector3Tools<Real>;
        using Math = typename ParentType::Math;
        using IntersectionContainer = std::vector<Tetrahedron3>;

    public:
        StaticFindIntersectorTetrahedron3Tetrahedron3(const Tetrahedron3& tetrahedron0, const Tetrahedron3& tetrahedron1, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Tetrahedron3 GetTetrahedron0() const noexcept;
        NODISCARD Tetrahedron3 GetTetrahedron1() const noexcept;

        NODISCARD IntersectionContainer GetIntersection() const;

    private:
        void Find();

        NODISCARD static IntersectionContainer SplitAndDecompose(const Tetrahedron3& tetra, const Plane3& plane, const IntersectionContainer& inside);

    private:
        Tetrahedron3 tetrahedron0;
        Tetrahedron3 tetrahedron1;

        IntersectionContainer intersectionContainer;
    };
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRAHEDRON3_TETRAHEDRON3_H
