// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 18:38)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_FIT_BASIS_DETAIL_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_FIT_BASIS_DETAIL_H

#include "BSplineFitBasis.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE1) || defined(MATHEMATICS_INCLUDED_BSPLINE_FIT_BASIS_DETAIL)


#include "CoreTools/Contract/Assertion.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Base/MathDetail.h"
#include "System/Helper/PragmaWarning.h" 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
template <typename Real>
Mathematics::BSplineFitBasis<Real>
	::BSplineFitBasis (int quantity, int degree)
{
    MATHEMATICS_ASSERTION_0(1 <= degree && degree < quantity, "Invalid inputs.\n");
    quantity = quantity;
    mDegree = degree;

    mValue = NEW1<Real>(degree + 1);
    mKnot = NEW1<Real>(2*degree);
}

template <typename Real>
Mathematics::BSplineFitBasis<Real>
	::~BSplineFitBasis ()
{
	EXCEPTION_TRY
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26447)
 DELETE1(mValue);
    DELETE1(mKnot);
#include STSTEM_WARNING_POP
}
EXCEPTION_ALL_CATCH(Mathematics) 
    
}

template <typename Real>
int Mathematics::BSplineFitBasis<Real>
	::GetQuantity () const noexcept
{
    return quantity;
}

template <typename Real>
int Mathematics::BSplineFitBasis<Real>
	::GetDegree () const noexcept
{
    return mDegree;
}

template <typename Real>
void Mathematics::BSplineFitBasis<Real>
	::Compute (Real t, int& imin, int& imax) const
{
    MATHEMATICS_ASSERTION_0(Math::GetValue(0) <= t && t <= Math::GetValue(1), "Invalid input.\n");

    // Use scaled time and scaled knots so that 1/(Q-D) does not need to
    // be explicitly stored by the class object.  Determine the extreme
    // indices affected by local control.
	const auto temp = quantity - mDegree;
	auto QmD = static_cast<Real>(temp);
    Real tValue { };
    if (t <= Math::GetValue(0))
    {
        tValue = Math::GetValue(0);
        imin = 0;
        imax = mDegree;
    }
    else if (t >= Math::GetValue(1))
    {
        tValue = QmD;
        imax = quantity - 1;
        imin = imax - mDegree;
    }
    else
    {
        tValue = QmD*t;
        imin = static_cast<int>(tValue);
        imax = imin + mDegree;
    }

    // Precompute the knots.
    for (int i0 = 0, i1 = imax+1-mDegree; i0 < 2*mDegree; ++i0, ++i1)
    {
        if (i1 <= mDegree)
        {
            mKnot[i0] = Math::GetValue(0);
        }
        else if (i1 >= quantity)
        {
            mKnot[i0] = QmD;
        }
        else
        {
			const auto temp2 = i1 - mDegree;
            mKnot[i0] = static_cast<Real>(temp2);
        }
    }

    // Initialize the basis function evaluation table.  The first degree-1
    // entries are zero, but they do not have to be set explicitly.
    mValue[mDegree] = Math::GetValue(1);

    // Update the basis function evaluation table, each iteration overwriting
    // the results from the previous iteration.
    for (auto row = mDegree-1; row >= 0; --row)
    {
		auto k0 = mDegree, k1 = row;
		auto knot0 = mKnot[k0], knot1 = mKnot[k1];
		auto invDenom = (Math::GetValue(1))/(knot0 - knot1);
		Real c1 = (knot0 - tValue)*invDenom;
		Real c0{ };
        mValue[row] = c1*mValue[row + 1];

        for (auto col = row + 1; col < mDegree; ++col)
        {
            c0 = (tValue - knot1)*invDenom;
            mValue[col] *= c0;

            knot0 = mKnot[++k0];
            knot1 = mKnot[++k1];
            invDenom = (Math::GetValue(1))/(knot0 - knot1);
            c1 = (knot0 - tValue)*invDenom;
            mValue[col] += c1*mValue[col + 1];
        }

        c0 = (tValue - knot1)*invDenom;
        mValue[mDegree] *= c0;
    }
}

template <typename Real>
Real Mathematics::BSplineFitBasis<Real>
	::GetValue (int i) const
{
    MATHEMATICS_ASSERTION_0(0 <= i && i <= mDegree, "Invalid index\n");
    return mValue[i];
}
#include STSTEM_WARNING_POP
#endif // !defined(MATHEMATICS_EXPORT_TEMPLATE1) || defined(MATHEMATICS_INCLUDED_BSPLINE_FIT_BASIS_DETAIL)

#endif // MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_FIT_BASIS_DETAIL_H