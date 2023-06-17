///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:42)

#ifndef MATHEMATICS_CONTAINMENT_CONT_LOZENGE3_H
#define MATHEMATICS_CONTAINMENT_CONT_LOZENGE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Lozenge3.h"

namespace Mathematics
{
    template <typename Real>
    class ContLozenge3 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = ContLozenge3<Real>;

    public:
        NODISCARD static Lozenge3<Real> ContLozenge(const std::vector<Vector3<Real>>& points);

        NODISCARD static bool InLozenge(const Vector3<Real>& point, const Lozenge3<Real>& lozenge);
    };
}

#endif  // MATHEMATICS_CONTAINMENT_CONT_LOZENGE3_H
