///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/09 09:43)

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
