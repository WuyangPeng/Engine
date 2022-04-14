///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/12 13:46)

#ifndef MATHEMATICS_CONTAINMENT_CONT_SPHERE3_H
#define MATHEMATICS_CONTAINMENT_CONT_SPHERE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Sphere3.h"

namespace Mathematics
{
    template <typename Real>
    class ContSphere3
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = ContSphere3<Real>;

    public:
        NODISCARD static Sphere3<Real> ContSphereOfAABB(const std::vector<Vector3<Real>>& points);

        NODISCARD static Sphere3<Real> ContSphereAverage(const std::vector<Vector3<Real>>& points);

        NODISCARD static bool InSphere(const Vector3<Real>& point, const Sphere3<Real>& sphere);

        NODISCARD static Sphere3<Real> MergeSpheres(const Sphere3<Real>& sphere0, const Sphere3<Real>& sphere1);
    };
}

#endif  // MATHEMATICS_CONTAINMENT_CONT_SPHERE3_H
