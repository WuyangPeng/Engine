///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:43)

#ifndef MATHEMATICS_CONTAINMENT_CONT_SEPARATE_POINTS2_H
#define MATHEMATICS_CONTAINMENT_CONT_SEPARATE_POINTS2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects2D/Line2.h"

namespace Mathematics
{
    template <typename Real>
    class ContSeparatePoints2
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = ContSeparatePoints2<Real>;

    public:
        ContSeparatePoints2(const std::vector<Vector2<Real>>& points0, const std::vector<Vector2<Real>>& points1, Line2<Real>& separatingLine);

        CLASS_INVARIANT_DECLARE;

        NODISCARD operator bool() noexcept;

    private:
        NODISCARD static int OnSameSide(const Vector2<Real>& lineNormal, Real lineConstant, const std::vector<int>& edges, const std::vector<Vector2<Real>>& points);

        NODISCARD static int WhichSide(const Vector2<Real>& lineNormal, Real lineConstant, const std::vector<int>& edges, const std::vector<Vector2<Real>>& points);

    private:
        bool separated;
    };

    using SeparatePoints2F = ContSeparatePoints2<float>;
    using SeparatePoints2D = ContSeparatePoints2<double>;
}

#endif  // MATHEMATICS_CONTAINMENT_CONT_SEPARATE_POINTS2_H
