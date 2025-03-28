///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 15:09)

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

        using Vector3Type = Vector3<Real>;
        using Tetrahedron3 = Tetrahedron3<Real>;
        using Plane3 = Plane3<Real>;
        using Vector3ToolsType = Vector3Tools<Real>;
        using MathType = typename ParentType::MathType;
        using IntersectionContainer = std::vector<Tetrahedron3>;

    public:
        StaticFindIntersectorTetrahedron3Tetrahedron3(const Tetrahedron3& tetrahedron0, const Tetrahedron3& tetrahedron1, const Real epsilon = MathType::GetZeroTolerance());

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
