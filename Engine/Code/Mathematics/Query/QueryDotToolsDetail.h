// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/10 10:21)

#ifndef MATHEMATICS_QUERY_QUERY_DOT_TOOLS_DETAIL_H
#define MATHEMATICS_QUERY_QUERY_DOT_TOOLS_DETAIL_H

#include "QueryDotTools.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::QueryDotTools<Real>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::QueryDotTools<Real>
	::Dot (Real x0, Real y0, Real x1, Real y1)
{
     return x0 * x1 + y0 * y1;
}

template <typename Real>
Real Mathematics::QueryDotTools<Real>
	::Det2 (Real x0, Real y0, Real x1, Real y1)
{
    return x0 * y1 - x1 * y0;
}

template <typename Real>
Real Mathematics::QueryDotTools<Real>
	::Det3 (Real x0, Real y0, Real z0, Real x1, Real y1, Real z1, Real x2, Real y2, Real z2)
{
    auto c00 = y1 * z2 - y2 * z1;
	auto c01 = y2 * z0 - y0 * z2;
	auto c02 = y0 * z1 - y1 * z0;
    
    return x0 * c00 + x1 * c01 + x2 * c02;
}

template <typename Real>
Real Mathematics::QueryDotTools<Real>
	::Dot(Real x0, Real y0, Real z0, Real x1, Real y1, Real z1)
{
	return x0 * x1 + y0 * y1 + z0 * z1;
}

template <typename Real>
Real Mathematics::QueryDotTools<Real>
	::Det4(Real x0, Real y0, Real z0, Real w0, Real x1, Real y1, Real z1, Real w1, 
		   Real x2, Real y2, Real z2, Real w2,Real x3, Real y3, Real z3, Real w3)
{
	auto a0 = x0 * y1 - x1 * y0;
	auto a1 = x0 * y2 - x2 * y0;
	auto a2 = x0 * y3 - x3 * y0;
	auto a3 = x1 * y2 - x2 * y1;
	auto a4 = x1 * y3 - x3 * y1;
	auto a5 = x2 * y3 - x3 * y2;
	auto b0 = z0 * w1 - z1 * w0;
	auto b1 = z0 * w2 - z2 * w0;
	auto b2 = z0 * w3 - z3 * w0;
	auto b3 = z1 * w2 - z2 * w1;
	auto b4 = z1 * w3 - z3 * w1;
	auto b5 = z2 * w3 - z3 * w2;

    return a0 * b5 - a1 * b4 + a2 * b3 + a3 * b2 - a4 * b1 + a5 * b0;
}

#endif // MATHEMATICS_QUERY_QUERY_DOT_TOOLS_DETAIL_H