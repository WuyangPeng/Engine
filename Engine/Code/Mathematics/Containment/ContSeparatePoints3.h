///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:43)

#ifndef MATHEMATICS_CONTAINMENT_CONT_SEPARATE_POINTS3_H
#define MATHEMATICS_CONTAINMENT_CONT_SEPARATE_POINTS3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Plane3.h"

namespace Mathematics
{
    template <typename Real>
    class ContSeparatePoints3
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = ContSeparatePoints3<Real>;

    public:
        ContSeparatePoints3(const std::vector<Vector3<Real>>& points0, const std::vector<Vector3<Real>>& points1, Plane3<Real>& separatingPlane);

        CLASS_INVARIANT_DECLARE;

        NODISCARD operator bool() noexcept;

    private:
        NODISCARD static int OnSameSide(const Plane3<Real>& plane, const std::vector<int>& indices, const std::vector<Vector3<Real>>& points);

        NODISCARD static int WhichSide(const Plane3<Real>& plane, const std::vector<int>& indices, const std::vector<Vector3<Real>>& points);

    private:
        bool separated;
    };

    using SeparatePoints3F = ContSeparatePoints3<float>;
    using SeparatePoints3D = ContSeparatePoints3<double>;
}

#endif  // MATHEMATICS_CONTAINMENT_CONT_SEPARATE_POINTS3_H
