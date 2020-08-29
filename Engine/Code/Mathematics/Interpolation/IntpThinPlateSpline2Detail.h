// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 10:22)

#ifndef MATHEMATICS_INTERPOLATION_INTP_THIN_PLATE_SPLINE2_DETAIL_H
#define MATHEMATICS_INTERPOLATION_INTP_THIN_PLATE_SPLINE2_DETAIL_H

#include "IntpThinPlateSpline2.h"

namespace Mathematics
{

	template <typename Real>
	IntpThinPlateSpline2<Real>::IntpThinPlateSpline2(int quantity, Real* X, Real* Y, Real* F, Real smooth, bool owner, bool transformToUnitSquare)
		:mSmooth(smooth)
	{
		MATHEMATICS_ASSERTION_0(quantity >= 3 && X && Y && F && smooth >= Math<Real>::GetValue(0), "Invalid input\n");

		mInitialized = false;
		mQuantity = quantity;
		mX = NEW1<Real>(mQuantity);
		mY = NEW1<Real>(mQuantity);
		mA = NEW1<Real>(mQuantity);

		int i, row, col;

		if (transformToUnitSquare)
		{
			// Map input (x,y) to unit square.  This is not part of the classical
			// thin-plate spline algorithm, because the interpolation is not
			// invariant to scalings.
			mXMin = X[0];
			mXMax = mXMin;
			for (i = 1; i < mQuantity; ++i)
			{
				if (X[i] < mXMin)
				{
					mXMin = X[i];
				}
				if (X[i] > mXMax)
				{
					mXMax = X[i];
				}
			}
			mXInvRange = (static_cast<Real>(1)) / (mXMax - mXMin);
			for (i = 0; i < mQuantity; ++i)
			{
				mX[i] = (X[i] - mXMin)*mXInvRange;
			}

			mYMin = Y[0];
			mYMax = mYMin;
			for (i = 1; i < mQuantity; ++i)
			{
				if (Y[i] < mYMin)
				{
					mYMin = Y[i];
				}
				if (Y[i] > mYMax)
				{
					mYMax = Y[i];
				}
			}
			mYInvRange = (static_cast<Real>(1)) / (mYMax - mYMin);
			for (i = 0; i < mQuantity; ++i)
			{
				mY[i] = (Y[i] - mYMin)*mYInvRange;
			}
		}
		else
		{
			// The classical thin-plate spline uses the data as is.  The values
			// mXMax and mYMax are not used, but they are initialized anyway
			// (to irrelevant numbers).
			mXMin = Math<Real>::GetValue(0);
			mXMax = static_cast<Real>(1);
			mXInvRange = static_cast<Real>(1);
			mYMin = Math<Real>::GetValue(0);
			mYMax = static_cast<Real>(1);
			mYInvRange = static_cast<Real>(1);
			memcpy(mX, X, mQuantity * sizeof(Real));
			memcpy(mY, Y, mQuantity * sizeof(Real));
		}

		// Compute matrix A = M + lambda*I [NxN matrix].
		VariableMatrix<Real> AMat(mQuantity, mQuantity);
		for (row = 0; row < mQuantity; ++row)
		{
			for (col = 0; col < mQuantity; ++col)
			{
				if (row == col)
				{
					AMat[row][col] = mSmooth;
				}
				else
				{
					Real dx = mX[row] - mX[col];
					Real dy = mY[row] - mY[col];
					Real t = Math<Real>::Sqrt(dx*dx + dy * dy);
					AMat[row][col] = Kernel(t);
				}
			}
		}

		// Compute matrix B [Nx3 matrix].
		VariableMatrix<Real> BMat(mQuantity, 3);
		for (row = 0; row < mQuantity; ++row)
		{
			BMat[row][0] = static_cast<Real>(1);
			BMat[row][1] = mX[row];
			BMat[row][2] = mY[row];
		}

		// Compute A^{-1}.
		VariableMatrix<Real> invAMat(mQuantity, mQuantity);
		try
		{
			invAMat = LinearSystem<Real>().Inverse(AMat);
		}
		catch (CoreTools::Error&)
		{
			return;
		}


		// Compute P = B^t A^{-1}  [3xN matrix].
		VariableMatrix<Real> PMat = TransposeTimes(BMat, invAMat);

		// Compute Q = P B = B^t A^{-1} B  [3x3 matrix].
		VariableMatrix<Real> QMat = PMat * BMat;

		// Compute Q^{-1}.
		VariableMatrix<Real> invQMat(3, 3);
		try
		{
			invQMat = LinearSystem<Real>().Inverse(QMat);
		}
		catch (CoreTools::Error&)
		{
			return;
		}

		// Compute P*z.
		Real prod[3];
		for (row = 0; row < 3; ++row)
		{
			prod[row] = Math<Real>::GetValue(0);
			for (i = 0; i < mQuantity; ++i)
			{
				prod[row] += PMat[row][i] * F[i];
			}
		}

		// Compute 'b' vector for smooth thin plate spline.
		for (row = 0; row < 3; ++row)
		{
			mB[row] = Math<Real>::GetValue(0);
			for (i = 0; i < 3; ++i)
			{
				mB[row] += invQMat[row][i] * prod[i];
			}
		}

		// Compute z-B*b.
		Real* tmp = NEW1<Real>(mQuantity);
		for (row = 0; row < mQuantity; ++row)
		{
			tmp[row] = F[row];
			for (i = 0; i < 3; ++i)
			{
				tmp[row] -= BMat[row][i] * mB[i];
			}
		}

		// Compute 'a' vector for smooth thin plate spline.
		for (row = 0; row < mQuantity; ++row)
		{
			mA[row] = Math<Real>::GetValue(0);
			for (i = 0; i < mQuantity; ++i)
			{
				mA[row] += invAMat[row][i] * tmp[i];
			}
		}
		DELETE1(tmp);

		mInitialized = true;

		if (owner)
		{
			DELETE1(X);
			DELETE1(Y);
			DELETE1(F);
		}
	}

	template <typename Real>
	IntpThinPlateSpline2<Real>::~IntpThinPlateSpline2()
	{
		DELETE1(mX);
		DELETE1(mY);
		DELETE1(mA);
	}

	template <typename Real>
	bool IntpThinPlateSpline2<Real>::IsInitialized() const
	{
		return mInitialized;
	}

	template <typename Real>
	const Real* IntpThinPlateSpline2<Real>::GetACoefficients() const
	{
		return mA;
	}

	template <typename Real>
	const Real* IntpThinPlateSpline2<Real>::GetBCoefficients() const
	{
		return mB;
	}

	template <typename Real>
	Real IntpThinPlateSpline2<Real>::GetSmooth() const
	{
		return mSmooth;
	}

	template <typename Real>
	Real IntpThinPlateSpline2<Real>::ComputeFunctional() const
	{
		Real functional = Math<Real>::GetValue(0);
		for (int row = 0; row < mQuantity; ++row)
		{
			for (int col = 0; col < mQuantity; ++col)
			{
				if (row == col)
				{
					functional += mSmooth * mA[row] * mA[col];
				}
				else
				{
					Real dx = mX[row] - mX[col];
					Real dy = mY[row] - mY[col];
					Real t = Math<Real>::Sqrt(dx*dx + dy * dy);
					Real k = Kernel(t);
					functional += k * mA[row] * mA[col];
				}
			}
		}

		if (mSmooth > Math<Real>::GetValue(0))
		{
			functional *= mSmooth;
		}

		return functional;
	}

	template <typename Real>
	Real IntpThinPlateSpline2<Real>::operator() (Real x, Real y)
	{
		if (mInitialized)
		{
			// Map (x,y) to the unit square.
			x = (x - mXMin)*mXInvRange;
			y = (y - mYMin)*mYInvRange;

			Real result = mB[0] + mB[1] * x + mB[2] * y;
			for (int i = 0; i < mQuantity; ++i)
			{
				Real dx = x - mX[i];
				Real dy = y - mY[i];
				Real t = Math<Real>::Sqrt(dx*dx + dy * dy);
				result += mA[i] * Kernel(t);
			}
			return result;
		}

		return Math<Real>::sm_MaxReal;
	}

	template <typename Real>
	Real IntpThinPlateSpline2<Real>::Kernel(Real t)
	{
		if (t > Math<Real>::GetValue(0))
		{
			Real t2 = t * t;
			return t2 * Math<Real>::Log(t2);
		}
		return Math<Real>::GetValue(0);
	}

}


#endif // MATHEMATICS_INTERPOLATION_INTP_THIN_PLATE_SPLINE2_DETAIL_H