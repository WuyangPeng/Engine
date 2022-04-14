///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/10 14:50)

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

        NODISCARD static void ProjectEllipse(const Ellipse2<Real>& ellipse, const Line2<Real>& line, Real& smin, Real& smax);

        NODISCARD static Ellipse2<Real> MergeEllipses(const Ellipse2<Real>& ellipse0, const Ellipse2<Real>& ellipse1);
    };
}

#endif  // MATHEMATICS_CONTAINMENT_CONT_ELLIPSE2_H
