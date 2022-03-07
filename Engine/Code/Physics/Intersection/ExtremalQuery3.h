// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 17:29)

#ifndef PHYSICS_INTERSECTION_EXTREMAL_QUERY3_H
#define PHYSICS_INTERSECTION_EXTREMAL_QUERY3_H

#include "Physics/PhysicsDll.h"

#include "Mathematics/Objects3D/ConvexPolyhedron3.h"

namespace Physics
{
    template <typename Real>
    class PHYSICS_TEMPLATE_DEFAULT_DECLARE ExtremalQuery3
    {
    public:
        using ConvexPolyhedron3 = Mathematics::ConvexPolyhedron3<Real>;
        using Vector3D = Mathematics::Vector3<Real>;

    public:
        // Abstract base class.
        virtual ~ExtremalQuery3();
        ExtremalQuery3(const ExtremalQuery3&) = delete;
        ExtremalQuery3& operator=(const ExtremalQuery3&) = delete;
        ExtremalQuery3(ExtremalQuery3&&) = delete;
        ExtremalQuery3& operator=( ExtremalQuery3&&) = delete;

        // Member access.
        const ConvexPolyhedron3* GetPolytope() const noexcept;
        const Vector3D* GetFaceNormals() const noexcept;

        // Compute the extreme vertices in the specified direction and return the
        // indices of the vertices in the polyhedron vertex array.
        virtual void GetExtremeVertices(const Vector3D& direction, int& positiveDirection, int& negativeDirection) = 0;

    protected:
        ExtremalQuery3(const ConvexPolyhedron3* polytope);

        const ConvexPolyhedron3* mPolytope;
        Vector3D* mFaceNormals;
    };

    using ExtremalQuery3f = ExtremalQuery3<float>;
    using ExtremalQuery3d = ExtremalQuery3<double>;
}

#endif  // PHYSICS_INTERSECTION_EXTREMAL_QUERY3_H
