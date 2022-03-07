///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/17 16:12)

#ifndef MATHEMATICS_QUERY_QUERY_DOT_TOOLS_ACHIEVE_H
#define MATHEMATICS_QUERY_QUERY_DOT_TOOLS_ACHIEVE_H

#include "QueryDotTools.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Rational/IntegerDetail.h"
#include "Mathematics/Rational/SignRationalDetail.h"

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::QueryDotTools<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::QueryDotTools<Real>::Dot(Real x0, Real y0, Real x1, Real y1) noexcept(std::is_arithmetic_v<Real>)
{
    return x0 * x1 + y0 * y1;
}

template <typename Real>
Real Mathematics::QueryDotTools<Real>::Det2(Real x0, Real y0, Real x1, Real y1) noexcept(std::is_arithmetic_v<Real>)
{
    return x0 * y1 - x1 * y0;
}

template <typename Real>
Real Mathematics::QueryDotTools<Real>::Det3(Real x0, Real y0, Real z0, Real x1, Real y1, Real z1, Real x2, Real y2, Real z2) noexcept(std::is_arithmetic_v<Real>)
{
    const auto c00 = y1 * z2 - y2 * z1;
    const auto c01 = y2 * z0 - y0 * z2;
    const auto c02 = y0 * z1 - y1 * z0;

    return x0 * c00 + x1 * c01 + x2 * c02;
}

template <typename Real>
Real Mathematics::QueryDotTools<Real>::Dot(Real x0, Real y0, Real z0, Real x1, Real y1, Real z1) noexcept(std::is_arithmetic_v<Real>)
{
    return x0 * x1 + y0 * y1 + z0 * z1;
}

template <typename Real>
Real Mathematics::QueryDotTools<Real>::Det4(Real x0,
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
                                            Real w3) noexcept(std::is_arithmetic_v<Real>)
{
    const auto a0 = x0 * y1 - x1 * y0;
    const auto a1 = x0 * y2 - x2 * y0;
    const auto a2 = x0 * y3 - x3 * y0;
    const auto a3 = x1 * y2 - x2 * y1;
    const auto a4 = x1 * y3 - x3 * y1;
    const auto a5 = x2 * y3 - x3 * y2;
    const auto b0 = z0 * w1 - z1 * w0;
    const auto b1 = z0 * w2 - z2 * w0;
    const auto b2 = z0 * w3 - z3 * w0;
    const auto b3 = z1 * w2 - z2 * w1;
    const auto b4 = z1 * w3 - z3 * w1;
    const auto b5 = z2 * w3 - z3 * w2;

    return a0 * b5 - a1 * b4 + a2 * b3 + a3 * b2 - a4 * b1 + a5 * b0;
}

#endif  // MATHEMATICS_QUERY_QUERY_DOT_TOOLS_ACHIEVE_H