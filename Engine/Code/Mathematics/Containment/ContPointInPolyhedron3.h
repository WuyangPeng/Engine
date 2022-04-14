///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/11 18:29)

#ifndef MATHEMATICS_CONTAINMENT_CONT_POINT_IN_POLYHEDRON3_H
#define MATHEMATICS_CONTAINMENT_CONT_POINT_IN_POLYHEDRON3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector2.h"
#include "Mathematics/Objects3D/Plane3.h"
#include "Mathematics/Objects3D/Ray3.h"

namespace Mathematics
{
    template <typename Real>
    class ContPointInPolyhedron3
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = ContPointInPolyhedron3<Real>;

    public:
        class TriangleFace
        {
        public:
            std::array<int, 3> indices{};

            Plane3<Real> plane;
        };

        ContPointInPolyhedron3(const std::vector<Vector3<Real>>& points, const std::vector<TriangleFace>& faces, const std::vector<Vector3<Real>>& directions);

        class ConvexFace
        {
        public:
            std::vector<int> indices;

            Plane3<Real> plane;
        };

        ContPointInPolyhedron3(const std::vector<Vector3<Real>>& points, const std::vector<ConvexFace>& faces, const std::vector<Vector3<Real>>& directions, int method);

        class SimpleFace
        {
        public:
            std::vector<int> indices;

            Plane3<Real> plane;

            std::vector<int> triangles;
        };

        ContPointInPolyhedron3(const std::vector<Vector3<Real>>& points, const std::vector<SimpleFace>& faces, const std::vector<Vector3<Real>>& directions, int method);

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool Contains(const Vector3<Real>& p) const;

    private:
        NODISCARD static bool FastNoIntersect(const Ray3<Real>& ray, const Plane3<Real>& plane) noexcept;

        NODISCARD bool ContainsT0(const Vector3<Real>& p) const;

        NODISCARD bool ContainsC0(const Vector3<Real>& p) const;
        NODISCARD bool ContainsC1C2(const Vector3<Real>& p, int pMethod) const;

        NODISCARD bool ContainsS0(const Vector3<Real>& p) const;
        NODISCARD bool ContainsS1(const Vector3<Real>& p) const;

    private:
        std::vector<Vector3<Real>> points;

        std::vector<TriangleFace> tFaces;
        std::vector<ConvexFace> cFaces;
        std::vector<SimpleFace> sFaces;

        int method;

        std::vector<Vector3<Real>> directions;

        mutable std::vector<Vector2<Real>> projVertices;
    };

    using PointInPolyhedron3F = ContPointInPolyhedron3<float>;
    using PointInPolyhedron3D = ContPointInPolyhedron3<double>;
}

#endif  // MATHEMATICS_CONTAINMENT_CONT_POINT_IN_POLYHEDRON3_H
