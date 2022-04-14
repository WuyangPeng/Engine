///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/10 15:02)

#ifndef MATHEMATICS_CONTAINMENT_CONT_ELLIPSE2_MINCR_H
#define MATHEMATICS_CONTAINMENT_CONT_ELLIPSE2_MINCR_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Matrix2.h"

namespace Mathematics
{
    template <typename Real>
    class ContEllipse2MinCR
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = ContEllipse2MinCR<Real>;

    public:
        ContEllipse2MinCR(const std::vector<Vector2<Real>>& points, const Vector2<Real>& c, const Matrix2<Real>& r, std::array<Real, 2>& d);

        CLASS_INVARIANT_DECLARE;

    private:
        NODISCARD static bool XGreater(const Vector2<Real>& p0, const Vector2<Real>& p1) noexcept;
        NODISCARD static bool XEqual(const Vector2<Real>& p0, const Vector2<Real>& p1) noexcept;
        NODISCARD static bool YGreater(const Vector2<Real>& p0, const Vector2<Real>& p1) noexcept;
        NODISCARD static bool YEqual(const Vector2<Real>& p0, const Vector2<Real>& p1) noexcept;
        static void MaxProduct(std::vector<Vector2<Real>>& a, std::array<Real, 2>& d);
    };

    using ContEllipse2MinCRF = ContEllipse2MinCR<float>;
    using ContEllipse2MinCRD = ContEllipse2MinCR<double>;
}

#endif  // MATHEMATICS_CONTAINMENT_CONT_ELLIPSE2_MINCR_H
