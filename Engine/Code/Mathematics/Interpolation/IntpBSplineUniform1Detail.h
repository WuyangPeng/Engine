// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 10:17)

#ifndef MATHEMATICS_INTERPOLATION_INTP_BSPLINE_UNIFORM1_DETAIL_H
#define MATHEMATICS_INTERPOLATION_INTP_BSPLINE_UNIFORM1_DETAIL_H

#include "IntpBSplineUniform1.h"

namespace Mathematics
{

	template <typename Real>
	IntpBSplineUniform1<Real>::IntpBSplineUniform1(int degree, int dim,Real* data)
		:IntpBSplineUniform<Real>(1, degree, &dim, data)
	{
	}

	template <typename Real>
	Real IntpBSplineUniform1<Real>::operator() (Real* X)
	{
		return (*this)(*X);
	}

	template <typename Real>
	Real IntpBSplineUniform1<Real>::operator() (int* dx, Real* X)
	{
		return (*this)(*dx, *X);
	}

	template <typename Real>
	Real IntpBSplineUniform1<Real>::operator() (Real x)
	{
		mBase[0] = (int)Math<Real>::Floor(x);
		if (mOldBase[0] != mBase[0])
		{
			// Switch to new local grid.
			mOldBase[0] = mBase[0];
			mGridMin[0] = mBase[0] - 1;
			mGridMax[0] = mGridMin[0] + mDegree;

			// Fill in missing grid data if necessary.
			if (mEvaluateCallback)
			{
				EvaluateUnknownData();
			}

			ComputeIntermediate();
		}

		SetPolynomial(0, x - mBase[0], mPoly[0]);

		Real result = Math<Real>::GetValue(0);
		for (int k = 0; k <= mDegree; ++k)
		{
			result += mPoly[0][k] * mInter[k];
		}
		return result;
	}

	template <typename Real>
	Real IntpBSplineUniform1<Real>::operator() (int dx, Real x)
	{
		mBase[0] = (int)Math<Real>::Floor(x);
		if (mOldBase[0] != mBase[0])
		{
			// Switch to new local grid.
			mOldBase[0] = mBase[0];
			mGridMin[0] = mBase[0] - 1;
			mGridMax[0] = mGridMin[0] + mDegree;

			// Fill in missing grid data if necessary.
			if (mEvaluateCallback)
			{
				EvaluateUnknownData();
			}

			ComputeIntermediate();
		}

		SetPolynomial(dx, x - mBase[0], mPoly[0]);

		Real result = Math<Real>::GetValue(0);
		for (int k = dx; k <= mDegree; ++k)
		{
			result += mPoly[0][k] * mInter[k];
		}
		return result;
	}

	template <typename Real>
	void IntpBSplineUniform1<Real>::EvaluateUnknownData()
	{
		for (int k = mGridMin[0]; k <= mGridMax[0]; ++k)
		{
			if (mData[k] == Math<Real>::sm_MaxReal)
			{
				mData[k] = mEvaluateCallback(k);
			}
		}
	}

	template <typename Real>
	void IntpBSplineUniform1<Real>::ComputeIntermediate()
	{
		for (int k = 0; k <= mDegree; ++k)
		{
			mInter[k] = Math<Real>::GetValue(0);
			for (int i = 0, j = mBase[0] - 1; i <= mDegree; ++i, ++j)
			{
				mInter[k] += mData[j] * mMatrix[i][k];
			}
		}
	}



}


#endif // MATHEMATICS_INTERPOLATION_INTP_BSPLINE_UNIFORM1_DETAIL_H