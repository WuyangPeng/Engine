///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.4 (2022/03/10 11:24)

#ifndef MATHEMATICS_CONTAINMENT_CONT_CAPSULE3_H
#define MATHEMATICS_CONTAINMENT_CONT_CAPSULE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Capsule3.h"
#include "Mathematics/Objects3D/Sphere3.h"

namespace Mathematics
{
    template <typename Real>
    class ContCapsule3 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = ContCapsule3<Real>;

    public:
        NODISCARD static Capsule3<Real> ContCapsule(const std::vector<Vector3<Real>>& points);

        NODISCARD static bool InCapsule(const Vector3<Real>& point, const Capsule3<Real>& capsule);

        NODISCARD static bool InCapsule(const Sphere3<Real>& sphere, const Capsule3<Real>& capsule);

        NODISCARD static bool InCapsule(const Capsule3<Real>& testCapsule, const Capsule3<Real>& capsule);

        NODISCARD static Capsule3<Real> MergeCapsules(const Capsule3<Real>& capsule0, const Capsule3<Real>& capsule1);
    };
}

#endif  // MATHEMATICS_CONTAINMENT_CONT_CAPSULE3_H
