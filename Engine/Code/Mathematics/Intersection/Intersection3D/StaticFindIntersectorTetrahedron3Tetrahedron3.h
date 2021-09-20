///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/21 13:31)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRAHEDRON3_TETRAHEDRON3_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRAHEDRON3_TETRAHEDRON3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects3D/Tetrahedron3.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
namespace Mathematics
{
    template <typename Real>
    class StaticFindIntersectorTetrahedron3Tetrahedron3Impl;

    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE CoreTools::PerformanceUnsharedImpl<StaticFindIntersectorTetrahedron3Tetrahedron3Impl<float>>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE CoreTools::PerformanceUnsharedImpl<StaticFindIntersectorTetrahedron3Tetrahedron3Impl<double>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE CoreTools::PerformanceUnsharedImpl<StaticFindIntersectorTetrahedron3Tetrahedron3Impl<Real>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorTetrahedron3Tetrahedron3 : public StaticIntersector<Real, Vector3D>
    {
    public:
        using StaticFindIntersectorTetrahedron3Tetrahedron3Impl = StaticFindIntersectorTetrahedron3Tetrahedron3Impl<Real>;
        
        TYPE_DECLARE(StaticFindIntersectorTetrahedron3Tetrahedron3);
        using PackageType = CoreTools::PerformanceUnsharedImpl<ImplType>;
        using ClassShareType = typename PackageType::ClassShareType;
        using ParentType = StaticIntersector<Real, Vector3D>;
        using Vector3D = Vector3D<Real>;
        using Tetrahedron3 = Tetrahedron3<Real>;
        using Plane3 = Plane3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;
        using IntersectionContainer = std::vector<Tetrahedron3>;

    public:
        StaticFindIntersectorTetrahedron3Tetrahedron3(const Tetrahedron3& tetrahedron0, const Tetrahedron3& tetrahedron1, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Tetrahedron3 GetTetrahedron0() const noexcept;
        [[nodiscard]] const Tetrahedron3 GetTetrahedron1() const noexcept;

        [[nodiscard]] const IntersectionContainer GetIntersection() const;

    private:
        void Find();

        static IntersectionContainer SplitAndDecompose(const Tetrahedron3& tetra, const Plane3& plane, const IntersectionContainer& inside);

    private:
        PackageType impl;
    };

    using FloatStaticFindIntersectorTetrahedron3Tetrahedron3 = StaticFindIntersectorTetrahedron3Tetrahedron3<float>;
    using DoubleStaticFindIntersectorTetrahedron3Tetrahedron3 = StaticFindIntersectorTetrahedron3Tetrahedron3<double>;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRAHEDRON3_TETRAHEDRON3_H
