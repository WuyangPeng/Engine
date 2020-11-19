// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 18:46)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_REDUCTION_DETAIL_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_REDUCTION_DETAIL_H

#include "BSplineReduction.h"

namespace Mathematics
{

template <typename Real, typename TVector>
BSplineReduction<Real,TVector>::BSplineReduction (int numCtrlPoints,const TVector* ctrlPoints, int degree, Real fraction, int& outNumCtrlPoints,TVector*& outCtrlPoints)
{
    // Check for valid input.  If invalid, return a "null" curve.
    MATHEMATICS_ASSERTION_0(numCtrlPoints >= 2, "Invalid input\n");
    MATHEMATICS_ASSERTION_0(ctrlPoints != 0, "Invalid input\n");
    MATHEMATICS_ASSERTION_0(1 <= degree && degree < numCtrlPoints, "Invalid input\n");
    if (numCtrlPoints < 2 || !ctrlPoints || degree < 1 ||  degree >= numCtrlPoints)
    {
        outNumCtrlPoints = 0;
        outCtrlPoints = 0;
        return;
    }

    // Clamp the number of control points to [degree+1,quantity-1].
    outNumCtrlPoints = boost::numeric_cast<int>(fraction*numCtrlPoints);
    if (outNumCtrlPoints > numCtrlPoints)
    {
        outNumCtrlPoints = numCtrlPoints;
        outCtrlPoints = NEW1<TVector>(outNumCtrlPoints);
        memcpy(outCtrlPoints, ctrlPoints, numCtrlPoints*sizeof(TVector));
        return;
    }
    if (outNumCtrlPoints < degree + 1)
    {
        outNumCtrlPoints = degree + 1;
    }

    // Allocate output control points and set all to the zero vector.
    outCtrlPoints = NEW1<TVector>(outNumCtrlPoints);

    // Set up basis function parameters.  Function 0 corresponds to the
    // output curve.  Function 1 corresponds to the input curve.
    mDegree = degree;
    mQuantity[0] = outNumCtrlPoints;
    mQuantity[1] = numCtrlPoints;

    for (auto j = 0; j <= 1; ++j)
    {
        mNumKnots[j] = mQuantity[j] + mDegree + 1;
        mKnot[j] = NEW1<Real>(mNumKnots[j]);

        int i;
        for (i = 0; i <= mDegree; ++i)
        {
            mKnot[j][i] = Math<Real>::GetValue(0);
        }

		auto factor = (Math::GetValue(1))/(Real)(mQuantity[j] - mDegree);
        for (/**/; i < mQuantity[j]; ++i)
        {
            mKnot[j][i] = (i-mDegree)*factor;
        }

        for (/**/; i < mNumKnots[j]; i++)
        {
            mKnot[j][i] = Math::GetValue(1);
        }
    }

    // Construct matrix A (depends only on the output basis function).
    Real value, tmin, tmax;
    int i0, i1;

    mBasis[0] = 0;
    mBasis[1] = 0;

	BandedMatrix<Real> A{ mQuantity[0], mDegree, mDegree };
    for (i0 = 0; i0 < mQuantity[0]; ++i0)
    {
        mIndex[0] = i0;
        tmax = MaxSupport(0, i0);

        for (i1 = i0; i1 <= i0 + mDegree && i1 < mQuantity[0]; ++i1)
        {
            mIndex[1] = i1;
            tmin = MinSupport(0, i1);

            value = RombergIntegral<Real,BSplineReduction>(8, tmin, tmax,Integrand, this).GetValue();
            A(i0, i1) = value;
            A(i1, i0) = value;
        }
    }

    // Construct A^{-1}.
	VariableMatrix<Real> invA{ mQuantity[0], mQuantity[0] };
    invA = LinearSystem<Real>().Invert(A); // ¥ÌŒÛ≈◊≥ˆ“Ï≥£
    //MATHEMATICS_ASSERTION_0(solved, "Failed to solve linear system\n");
   // WM5_UNUSED(solved);

    // Construct B (depends on both input and output basis functions).
    mBasis[1] = 1;
	VariableMatrix<Real> B{ mQuantity[0], mQuantity[1] };
    for (i0 = 0; i0 < mQuantity[0]; ++i0)
    {
        mIndex[0] = i0;
		auto tmin0 = MinSupport(0, i0);
		auto tmax0 = MaxSupport(0, i0);

        for (i1 = 0; i1 < mQuantity[1]; ++i1)
        {
            mIndex[1] = i1;
			auto tmin1 = MinSupport(1, i1);
			auto tmax1 = MaxSupport(1, i1);

			StaticFindIntersector1<Real> intr{ tmin0, tmax0, tmin1, tmax1 };
         
            int quantity = intr.GetNumIntersections();

            if (quantity == 2)
            {
				value = RombergIntegral<Real, BSplineReduction>{ 8,intr.GetIntersection(0), intr.GetIntersection(1),Integrand, this }.GetValue();
                B[i0][i1] = value;
            }
            else
            {
                B[i0][i1] = Math<Real>::GetValue(0);
            }
        }
    }

    // Construct A^{-1}*B.
	auto prod = invA*B;

    // Construct the control points for the least-squares curve.
    memset(outCtrlPoints,0,outNumCtrlPoints*sizeof(TVector));
    for (i0 = 0; i0 < mQuantity[0]; ++i0)
    {
        for (i1 = 0; i1 < mQuantity[1]; ++i1)
        {
            outCtrlPoints[i0] += ctrlPoints[i1]*prod[i0][i1];
        }
    }
}

template <typename Real, typename TVector>
BSplineReduction<Real,TVector>::~BSplineReduction ()
{
    DELETE1(mKnot[0]);
    DELETE1(mKnot[1]);
}

template <typename Real, typename TVector>
Real BSplineReduction<Real,TVector>::MinSupport (int basis, int i) const
{
    return mKnot[basis][i];
}

template <typename Real, typename TVector>
Real BSplineReduction<Real,TVector>::MaxSupport (int basis, int i) const
{
    return mKnot[basis][i+1+mDegree];
}

template <typename Real, typename TVector>
Real BSplineReduction<Real,TVector>::F (int basis, int i, int j, Real t)
{
    if (j > 0)
    {
		auto result = Math<Real>::GetValue(0);

		auto denom = mKnot[basis][i + j] - mKnot[basis][i];
        if (denom > Math<Real>::GetValue(0))
        {
            result += (t - mKnot[basis][i])*F(basis, i, j - 1, t)/denom;
        }

        denom = mKnot[basis][i + j + 1] - mKnot[basis][i + 1];
        if (denom > Math<Real>::GetValue(0))
        {
            result += (mKnot[basis][i + j + 1] - t) * F(basis, i + 1, j - 1, t)/denom;
        }

        return result;
    }

    if (mKnot[basis][i] <= t && t < mKnot[basis][i + 1])
    {
        return Math::GetValue(1);
    }
    else
    {
        return Math<Real>::GetValue(0);
    }
}

template <typename Real, typename TVector>
Real BSplineReduction<Real,TVector>::Integrand (Real t, const BSplineReduction* data)
{
	auto& self = *(BSplineReduction<Real,TVector>*)data;

	auto value0 = self.F(self.mBasis[0], self.mIndex[0], self.mDegree, t);
	auto value1 = self.F(self.mBasis[1], self.mIndex[1], self.mDegree, t);
    return value0*value1;
}

}


#endif // MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_REDUCTION_DETAIL_H