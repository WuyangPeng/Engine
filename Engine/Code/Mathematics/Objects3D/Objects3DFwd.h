/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.6 (2024/02/26 17:13)

#ifndef MATHEMATICS_OBJECTS_3D_FWD_H
#define MATHEMATICS_OBJECTS_3D_FWD_H

namespace Mathematics
{
    template <typename Real>
    class Box3;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Circle3;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Line3;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Ray3;

    template <typename Real>
    class Triangle3;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Sphere3;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Segment3;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Capsule3;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Cone3;

    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Cylinder3;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Ellipse3;

    template <typename Real>
    class Ellipsoid3;

    template <typename Real>
    class Ellipsoid3Coefficients;

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Frustum3;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Plane3;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Torus3Parameters;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Torus3;

    template <typename Real>
    class Tetrahedron3;

    template <typename Real>
    class Rectangle3;

    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    class Lozenge3;

    template <typename Real>
    class Polyhedron3;

    template <typename Real>
    class ConvexPolyhedron3;

    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class ConvexMesh3;

    namespace Algebra
    {
        template <typename Real>
        requires std::is_arithmetic_v<Real>
        class Circle3;

        template <typename Real>
        requires(std::is_arithmetic_v<Real>)
        class ConvexPolyhedron3;

        template <typename Real>
        requires(std::is_arithmetic_v<Real>)
        class Ellipse3;

        template <typename Real>
        requires(std::is_arithmetic_v<Real>)
        class Polyhedron3;

        template <typename Real>
        requires(std::is_arithmetic_v<Real>)
        class Tetrahedron3;

        template <typename Real>
        requires(std::is_arithmetic_v<Real>)
        class Torus3;
    }

    enum class ConvexMesh3Type;
}

#endif  // MATHEMATICS_OBJECTS_3D_FWD_H