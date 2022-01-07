// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 18:48)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_SURFACE_FIT_DETAIL_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_SURFACE_FIT_DETAIL_H

#include "BSplineSurfaceFit.h"

namespace Mathematics
{

template <typename Real>
BSplineSurfaceFit<Real>::BSplineSurfaceFit (int degree0, int numControls0, int numSamples0, int degree1, int numControls1, int numSamples1, Vector3D<Real>** samples)
{
    MATHEMATICS_ASSERTION_0(1 <= degree0 && degree0 + 1 < numControls0, "Invalid input\n");
    MATHEMATICS_ASSERTION_0(numControls0 <= numSamples0, "Invalid input\n");
    MATHEMATICS_ASSERTION_0(1 <= degree1 && degree1 + 1 < numControls1, "Invalid input\n");
    MATHEMATICS_ASSERTION_0(numControls1 <= numSamples1, "Invalid input\n");

    mDegree[0] = degree0;
    mNumSamples[0] = numSamples0;
    mNumControls[0] = numControls0;
    mDegree[1] = degree1;
    mNumSamples[1] = numSamples1;
    mNumControls[1] = numControls1;
    mSamples = samples;
   // mControls = NEW2<Vector3D<Real> >(numControls0, numControls1);

    // The double-precision basis functions are used to help with the
    // numerical round-off errors.
	BSplineFitBasis<Real>* dBasis[2];
	Real tMultiplier[2];
    int dim;
    for (dim = 0; dim < 2; ++dim)
    {
        mBasis[dim] = nullptr;  // NEW0 BSplineFitBasis<Real>(mNumControls[dim], mDegree[dim]);

		dBasis[dim] = nullptr;  // NEW0 BSplineFitBasis<Real>(mNumControls[dim],  mDegree[dim]);

        tMultiplier[dim] = 1.0f/(Real)(mNumSamples[dim] - 1);
    }

    // Fit the data points with a B-spline surface using a least-squares error
    // metric.  The problem is of the form A0^T*A0*Q*A1^T*A1 = A0^T*P*A1, where
    // A0^T*A0 and A1^T*A1 are banded matrices, P contains the sample data, and
    // Q is the unknown matrix of control points.

	Real t;
    int i0, i1, i2, imin, imax;

    // Construct the matrices A0^T*A0 and A1^T*A1.
	BandedMatrixSolve<Real>* ATAMat[2];
    for (dim = 0; dim < 2; ++dim)
    {
        ATAMat[dim] = nullptr;  //  NEW0 BandedMatrixSolve<Real>(mNumControls[dim],  mDegree[dim] + 1, mDegree[dim] + 1);

        for (i0 = 0; i0 < mNumControls[dim]; ++i0)
        {
            for (i1 = 0; i1 < i0; ++i1)
            {
                (*ATAMat[dim])(i0, i1) = (*ATAMat[dim])(i1, i0);
            }

            int i1Max = i0 + mDegree[dim];
            if (i1Max >= mNumControls[dim])
            {
                i1Max = mNumControls[dim] - 1;
            }

            for (i1 = i0; i1 <= i1Max; ++i1)
            {
				auto value = 0.0;
                for (i2 = 0; i2 < mNumSamples[dim]; ++i2)
                {
                    t = tMultiplier[dim]*(Real)i2;
                    dBasis[dim]->Compute(t, imin, imax);
                    if (imin <= i0 && i0 <= imax && imin <= i1 && i1 <= imax)
                    {
						auto b0 = dBasis[dim]->GetValue(i0 - imin);
						auto b1 = dBasis[dim]->GetValue(i1 - imin);
                        value += b0*b1;
                    }
                }
                (*ATAMat[dim])(i0, i1) = value;
            }
        }
    }

    // Construct the matrices A0^T and A1^T.  A[d]^T has mNumControls[d]
    // rows and mNumSamples[d] columns.
	VariableMatrix<Real> ATMat[2];
    for (dim = 0; dim < 2; dim++)
    {
        ATMat[dim].ResetSize(mNumSamples[dim], mNumControls[dim]);
        memset(ATMat[dim][0], 0, mNumControls[dim] * mNumSamples[dim] * sizeof(Real));

        for (i0 = 0; i0 < mNumControls[dim]; ++i0)
        {
            for (i1 = 0; i1 < mNumSamples[dim]; ++i1)
            {
				t = tMultiplier[dim] * (Real)i1;
                dBasis[dim]->Compute(t, imin, imax);
                if (imin <= i0 && i0 <= imax)
                {
                    ATMat[dim][i0][i1] = dBasis[dim]->GetValue(i0 - imin);
                }
            }
        }
    }

    // Compute X0 = (A0^T*A0)^{-1}*A0^T and X1 = (A1^T*A1)^{-1}*A1^T by
    // solving the linear systems A0^T*A0*X0 = A0^T and A1^T*A1*X1 = A1^T.
    for (dim = 0; dim < 2; ++dim)
    {
		//*(ATAMat[dim]) = 
		ATMat[dim] = ATAMat[dim]->SolveSystem(ATMat[dim]);
       // MATHEMATICS_ASSERTION_0(solved, "Failed to solve linear system\n");
        //WM5_UNUSED(solved);
    }

    // The control points for the fitted surface are stored in the matrix
    // Q = X0*P*X1^T, where P is the matrix of sample data.
    for (i1 = 0; i1 < mNumControls[1]; ++i1)
    {
        for (i0 = 0; i0 < mNumControls[0]; ++i0)
        {
            Vector3D<Real> sum = Vector3D<Real>::sm_Zero;
            for (auto j1 = 0; j1 < mNumSamples[1]; ++j1)
            {
				auto x1Value = (Real)ATMat[1][i1][j1];
                for (auto j0 = 0; j0 < mNumSamples[0]; ++j0)
                {
					auto x0Value = (Real)ATMat[0][i0][j0];
                    sum += (x0Value*x1Value)*mSamples[j1][j0];
                }
            }
            mControls[i1][i0] = sum;
        }
    }

    for (dim = 0; dim < 2; ++dim)
    {
        DELETE0(dBasis[dim]);
        DELETE0(ATAMat[dim]);
        //DELETE2(ATMat[dim]);
    }
}

template <typename Real>
BSplineSurfaceFit<Real>::~BSplineSurfaceFit ()
{
    DELETE0(mBasis[0]);
    DELETE0(mBasis[1]);
    DELETE2(mControls);
}

template <typename Real>
int BSplineSurfaceFit<Real>::GetSampleQuantity (int i) const
{
    return mNumSamples[i];
}

template <typename Real>
Vector3D<Real>** BSplineSurfaceFit<Real>::GetSamplePoints () const
{
    return mSamples;
}

template <typename Real>
int BSplineSurfaceFit<Real>::GetDegree (int i) const
{
    return mDegree[i];
}

template <typename Real>
int BSplineSurfaceFit<Real>::GetControlQuantity (int i) const
{
    return mNumControls[i];
}

template <typename Real>
Vector3D<Real>** BSplineSurfaceFit<Real>::GetControlPoints () const
{
    return mControls;
}

template <typename Real>
const BSplineFitBasis<Real>& BSplineSurfaceFit<Real>::GetBasis (int i) const
{
    return *mBasis[i];
}

template <typename Real>
Vector3D<Real> BSplineSurfaceFit<Real>::GetPosition (Real u, Real v) const
{
    int iumin, iumax, ivmin, ivmax;
    mBasis[0]->Compute(u, iumin, iumax);
    mBasis[1]->Compute(v, ivmin, ivmax);

	auto pos = Vector3D<Real>::sm_Zero;
    for (int iv = ivmin, j = 0; iv <= ivmax; ++iv, ++j)
    {
		auto value1 = mBasis[1]->GetValue(j);
        for (int iu = iumin, i = 0; iu <= iumax; ++iu, ++i)
        {
			auto value0 = mBasis[0]->GetValue(i);
            pos += (value0*value1)*mControls[iv][iu];
        }
    }
    return pos;
}

}


#endif // MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_SURFACE_FIT_DETAIL_H