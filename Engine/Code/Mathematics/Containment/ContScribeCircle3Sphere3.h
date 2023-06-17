///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:43)

#ifndef MATHEMATICS_CONTAINMENT_CONT_SCRIBE_CIRCLE3_SPHERE3_H
#define MATHEMATICS_CONTAINMENT_CONT_SCRIBE_CIRCLE3_SPHERE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Circle3.h"
#include "Mathematics/Objects3D/Sphere3.h"

    namespace Mathematics
{
    template <typename Real>
    class ContScribeCircle3Sphere3
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = ContScribeCircle3Sphere3<Real>;

    public:
        NODISCARD static bool Circumscribe(const Vector3<Real>& v0, const Vector3<Real>& v1, const Vector3<Real>& v2, Circle3<Real>& circle);

        NODISCARD static bool Circumscribe(const Vector3<Real>& v0, const Vector3<Real>& v1, const Vector3<Real>& v2, const Vector3<Real>& v3, Sphere3<Real>& sphere);

        NODISCARD static bool Inscribe(const Vector3<Real>& v0, const Vector3<Real>& v1, const Vector3<Real>& v2, Circle3<Real>& circle);

        NODISCARD static bool Inscribe(const Vector3<Real>& v0, const Vector3<Real>& v1, const Vector3<Real>& v2, const Vector3<Real>& v3, Sphere3<Real>& sphere);
    };
}

#endif  // MATHEMATICS_CONTAINMENT_CONT_SCRIBE_CIRCLE3_SPHERE3_H
