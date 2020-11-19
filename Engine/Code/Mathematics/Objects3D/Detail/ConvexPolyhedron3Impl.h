///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/18 10:15)

#ifndef MATHEMATICS_OBJECTS3D_CONVEX_POLYHEDRON3_IMPL_H
#define MATHEMATICS_OBJECTS3D_CONVEX_POLYHEDRON3_IMPL_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Base/MathDetail.h"

#include <set>
#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE ConvexPolyhedron3Impl final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = ConvexPolyhedron3Impl<Real>;
        using Math = Math<Real>;
        using Vector3D = Vector3D<Real>;
        using Plane3 = Plane3<Real>;
        using PlaneContainerType = std::vector<Plane3>;
        using TrianglesType = std::set<int>;
        using PlaneContainerTypeConstIter = typename PlaneContainerType::const_iterator;

    public:
        explicit ConvexPolyhedron3Impl(const PlaneContainerType& planes);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const PlaneContainerType GetPlanes() const;
        [[nodiscard]] const Plane3& GetPlane(int index) const;

        [[nodiscard]] int GetNumPlane() const;

        void ResetTriangles(int numTriangles);

        void SetVertex(int index);
        [[nodiscard]] bool IsUpdatePlanes() const noexcept;
        void ClearSharingTriangles() noexcept;
        void UpdatePlane(int index, const Vector3D& origin, const Vector3D& direction);

        PlaneContainerTypeConstIter begin() const noexcept;
        PlaneContainerTypeConstIter end() const noexcept;

    private:
        // 	面的数量是三角形的数量。
        PlaneContainerType m_Planes;

        // 要在UpdatePlane处理的共享三角形
        TrianglesType m_SharingTriangles;
    }; 
}

#endif  // MATHEMATICS_OBJECTS3D_CONVEX_POLYHEDRON3_IMPL_H
