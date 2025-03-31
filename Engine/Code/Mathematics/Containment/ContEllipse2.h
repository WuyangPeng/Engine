///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:42)

#ifndef MATHEMATICS_CONTAINMENT_CONT_ELLIPSE2_H
#define MATHEMATICS_CONTAINMENT_CONT_ELLIPSE2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects2D/Ellipse2.h"
#include "Mathematics/Objects2D/Line2.h"

namespace Mathematics
{
    template <typename Real>
    class ContEllipse2 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = ContEllipse2<Real>;

    public:
        NODISCARD static Ellipse2<Real> ContEllipse(const std::vector<Vector2<Real>>& points);

        static void ProjectEllipse(const Ellipse2<Real>& ellipse, const Line2<Real>& line, Real& smin, Real& smax);

        NODISCARD static Ellipse2<Real> MergeEllipses(const Ellipse2<Real>& ellipse0, const Ellipse2<Real>& ellipse1);
    };
}

#endif  // MATHEMATICS_CONTAINMENT_CONT_ELLIPSE2_H
