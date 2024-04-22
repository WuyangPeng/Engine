///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:41)

#ifndef MATHEMATICS_CONTAINMENT_FWD_H
#define MATHEMATICS_CONTAINMENT_FWD_H

namespace Mathematics
{
    template <typename Real>
    class ScribeCircle2Circumscribe;

    template <typename Real>
    class ScribeCircle2Inscribe;

    template <typename Real>
    class ContBox2;

    template <typename Real>
    class ContBox3;

    template <typename Real>
    class ContCapsule3;

    template <typename Real>
    class ContCylinder3;

    template <typename Real>
    class ContEllipse2;

    template <typename Real>
    class ContEllipse2MinCR;

    template <typename Real>
    class ContEllipsoid3;

    template <typename Real>
    class ContEllipsoid3MinCR;

    template <typename Real>
    class ContMinBox2;

    template <typename Real>
    class ContMinBox3;

    template <typename Real>
    class ContMinCircle2;

    template <typename Real>
    class ContMinSphere3;

    template <typename Real>
    class ContPointInPolygon2;

    template <typename Real>
    class ContPointInPolyhedron3;

    template <typename Real>
    class ContSeparatePoints2;

    template <typename Real>
    class ContSeparatePoints3;

    template <typename Real>
    class ContScribeCircle3Sphere3;

    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    class ContOrientedBox2;
}

#endif  // MATHEMATICS_CONTAINMENT_FWD_H