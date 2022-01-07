// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 18:37)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_CURVE_FIT_DETAIL_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_CURVE_FIT_DETAIL_H

#include "BSplineCurveFit.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Algebra/BandedMatrixSolveDetail.h"

namespace Mathematics
{

template <typename Real>
BSplineCurveFit<Real>::BSplineCurveFit (int dimension, int numSamples,
    const Real* sampleData, int degree, int numControls)
	: mBasis{ numControls, degree }
{
    MATHEMATICS_ASSERTION_0(dimension >= 1, "Invalid input\n");
    MATHEMATICS_ASSERTION_0(1 <= degree && degree < numControls, "Invalid input\n");
    MATHEMATICS_ASSERTION_0(numControls <= numSamples, "Invalid input\n");

    mDimension = dimension;
    mNumSamples = numSamples;
    mSampleData = sampleData;
    mDegree = degree;
    mNumControls = numControls;
    mControlData = nullptr;  //  NEW1<Real>(mDimension*numControls);

    // The double-precision basis functions are used to help with the
    // numerical round-off errors.
	BSplineFitBasis<Real> dBasis{ mNumControls,mDegree };
	auto tMultiplier = 1.0f/(Real)(mNumSamples - 1);

    // Fit the data points with a B-spline curve using a least-squares error
    // metric.  The problem is of the form A^T*A*Q = A^T*P, where A^T*A is a
    // banded matrix, P contains the sample data, and Q is the unknown vector
    // of control points.

    Real t;
    int i0, i1, i2, imin, imax, j;

    // Construct the matrix A^T*A.
    auto ATAMat = nullptr;  // NEW0 BandedMatrixSolve<Real>(mNumControls,mDegree + 1, mDegree + 1);

    for (i0 = 0; i0 < mNumControls; ++i0)
    {
        for (i1 = 0; i1 < i0; ++i1)
        {
           // (*ATAMat)(i0, i1) = (*ATAMat)(i1, i0);
        }

		auto i1Max = i0 + mDegree;
        if (i1Max >= mNumControls)
        {
            i1Max = mNumControls - 1;
        }

        for (i1 = i0; i1 <= i1Max; ++i1)
        {
			auto value = 0.0;
            for (i2 = 0; i2 < mNumSamples; ++i2)
            {
                t = tMultiplier*(Real)i2;
                dBasis.Compute(t, imin, imax);
                if (imin <= i0 && i0 <= imax && imin <= i1 && i1 <= imax)
                {
					auto dB0 = dBasis.GetValue(i0 - imin);
					auto dB1 = dBasis.GetValue(i1 - imin);
                    value += dB0*dB1;
                }
            }
           // (*ATAMat)(i0, i1) = value;
        }
    }

    // Construct the matrix A^T.
	VariableMatrix<Real> ATMat{ mNumSamples, mNumControls };
    //memset(ATMat[0], 0, mNumControls*mNumSamples*sizeof(double));
    for (i0 = 0; i0 < mNumControls; ++i0)
    {
        for (i1 = 0; i1 < mNumSamples; ++i1)
        {
            t = tMultiplier*(Real)i1;
            dBasis.Compute(t, imin, imax);
            if (imin <= i0 && i0 <= imax)
            {
                ATMat[i0][i1] = dBasis.GetValue(i0 - imin);
            }
        }
    }

    // Compute X0 = (A^T*A)^{-1}*A^T by solving the linear system
    // A^T*A*X = A^T.
    //bool solved = ATAMat->SolveSystem(ATMat,mNumSamples);
	//bool solved = 
	ATMat = 	ATAMat->SolveSystem(ATMat); // ¥ÌŒÛª·≈◊≥ˆ“Ï≥£
   // MATHEMATICS_ASSERTION_0(solved, "Failed to solve linear system\n");
   // solved;

    // The control points for the fitted curve are stored in the vector
    // Q = X0*P, where P is the vector of sample data.
    memset(mControlData, 0, mNumControls*mDimension*sizeof(Real));
    for (i0 = 0; i0 < mNumControls; ++i0)
    {
        Real* Q = mControlData + i0*mDimension;
        for (i1 = 0; i1 < mNumSamples; ++i1)
        {
            const Real* P = mSampleData + i1*mDimension;
			auto xValue = (Real)ATMat[i0][i1];
            for (j = 0; j < mDimension; j++)
            {
                Q[j] += xValue*P[j];
            }
        }
    }

    // Set the first and last output control points to match the first and
    // last input samples.  This supports the application of fitting keyframe
    // data with B-spline curves.  The user expects that the curve passes
    // through the first and last positions in order to support matching two
    // consecutive keyframe sequences.
    Real* cEnd0 = mControlData;
    const Real* sEnd0 = mSampleData;
    Real* cEnd1 = &mControlData[mDimension*(mNumControls-1)];
    const Real* sEnd1 = &mSampleData[mDimension*(mNumSamples-1)];
    for (j = 0; j < mDimension; j++)
    {
        *cEnd0++ = *sEnd0++;
        *cEnd1++ = *sEnd1++;
    }

    //DELETE2(ATMat);
    //DELETE0(ATAMat);
}

template <typename Real>
BSplineCurveFit<Real>::~BSplineCurveFit ()
{
    //DELETE1(mControlData);
}

template <typename Real>
int BSplineCurveFit<Real>::GetDimension () const
{
    return mDimension;
}

template <typename Real>
int BSplineCurveFit<Real>::GetSampleQuantity () const
{
    return mNumSamples;
}

template <typename Real>
const Real* BSplineCurveFit<Real>::GetSampleData () const
{
    return mSampleData;
}

template <typename Real>
int BSplineCurveFit<Real>::GetDegree () const
{
    return mDegree;
}

template <typename Real>
int BSplineCurveFit<Real>::GetControlQuantity () const
{
    return mNumControls;
}

template <typename Real>
const Real* BSplineCurveFit<Real>::GetControlData () const
{
    return mControlData;
}

template <typename Real>
const BSplineFitBasis<Real>& BSplineCurveFit<Real>::GetBasis () const
{
    return mBasis;
}

template <typename Real>
void BSplineCurveFit<Real>::GetPosition (Real t, Real* position) const
{
    int imin, imax;
    mBasis.Compute(t, imin, imax);

    Real* source = &mControlData[mDimension*imin];
	auto basisValue = mBasis.GetValue(0);
    int j;
    for (j = 0; j < mDimension; ++j)
    {
        position[j] = basisValue*(*source++);
    }

    for (auto i = imin+1, index = 1; i <= imax; ++i, ++index)
    {
        basisValue = mBasis.GetValue(index);
        for (j = 0; j < mDimension; ++j)
        {
            position[j] += basisValue*(*source++);
        }
    }
}

}


#endif // MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_CURVE_FIT_DETAIL_H