///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 14:02)

#ifndef MATHEMATICS_QUERY_QUERY_DOT_TOOLS_H
#define MATHEMATICS_QUERY_QUERY_DOT_TOOLS_H

#include "Mathematics/MathematicsDll.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE QueryDotTools final
    {
    public:
        using ClassType = QueryDotTools<Real>;

    public:
        CLASS_INVARIANT_DECLARE;

        // 帮助函数

        NODISCARD static Real Dot(Real x0, Real y0, Real x1, Real y1) noexcept(std::is_arithmetic_v<Real>);
        NODISCARD static Real Det2(Real x0, Real y0, Real x1, Real y1) noexcept(std::is_arithmetic_v<Real>);
        NODISCARD static Real Det3(Real x0, Real y0, Real z0, Real x1, Real y1, Real z1, Real x2, Real y2, Real z2) noexcept(std::is_arithmetic_v<Real>);

        NODISCARD static Real Dot(Real x0, Real y0, Real z0, Real x1, Real y1, Real z1) noexcept(std::is_arithmetic_v<Real>);
        NODISCARD static Real Det4(Real x0,
                                   Real y0,
                                   Real z0,
                                   Real w0,
                                   Real x1,
                                   Real y1,
                                   Real z1,
                                   Real w1,
                                   Real x2,
                                   Real y2,
                                   Real z2,
                                   Real w2,
                                   Real x3,
                                   Real y3,
                                   Real z3,
                                   Real w3) noexcept(std::is_arithmetic_v<Real>);
    };

    using QueryDotToolsF = QueryDotTools<float>;
    using QueryDotToolsD = QueryDotTools<double>;
}

#endif  // MATHEMATICS_QUERY_QUERY_DOT_TOOLS_H
