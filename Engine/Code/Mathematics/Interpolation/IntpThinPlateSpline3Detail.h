// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 10:22)

#ifndef MATHEMATICS_INTERPOLATION_INTP_THIN_PLATE_SPLINE3_DETAIL_H
#define MATHEMATICS_INTERPOLATION_INTP_THIN_PLATE_SPLINE3_DETAIL_H

#include "IntpThinPlateSpline3.h"

namespace Mathematics
{
	template <typename Real>
	IntpThinPlateSpline3<Real>::IntpThinPlateSpline3(int quantity,Real* X, Real* Y, Real* Z, Real* F, Real smooth, bool owner,bool transformToUnitCube)
		:mSmooth(smooth)
	{
		MATHEMATICS_ASSERTION_0(quantity >= 4 && X && Y && Z && F && smooth >= Math<Real>::GetValue(0),"Invalid input\n");

		mInitialized = false;
		mQuantity = quantity;
		mX = NEW1<Real>(mQuantity);
		mY = NEW1<Real>(mQuantity);
		mZ = NEW1<Real>(mQuantity);
		mA = NEW1<Real>(mQuantity);

		int i, row, col;

		if (transformToUnitCube)
		{
			// Map input (x,y,z) to unit cube.  This is not part of the classical
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

			mZMin = Z[0];
			mZMax = mZMin;
			for (i = 1; i < mQuantity; ++i)
			{
				if (Z[i] < mZMin)
				{
					mZMin = Z[i];
				}
				if (Z[i] > mZMax)
				{
					mZMax = Z[i];
				}
			}
			mZInvRange = (static_cast<Real>(1)) / (mZMax - mZMin);
			for (i = 0; i < mQuantity; ++i)
			{
				mZ[i] = (Z[i] - mZMin)*mZInvRange;
			}
		}
		else
		{
			// The classical thin-plate spline uses the data as is.  The values
			// mXMax, mYMax, and mZMax are not used, but they are initialized
			// anyway (to irrelevant numbers).
			mXMin = Math<Real>::GetValue(0);
			mXMax = static_cast<Real>(1);
			mXInvRange = static_cast<Real>(1);
			mYMin = Math<Real>::GetValue(0);
			mYMax = static_cast<Real>(1);
			mYInvRange = static_cast<Real>(1);
			mZMin = Math<Real>::GetValue(0);
			mZMax = static_cast<Real>(1);
			mZInvRange = static_cast<Real>(1);
			memcpy(mX, X, mQuantity * sizeof(Real));
			memcpy(mY, Y, mQuantity * sizeof(Real));
			memcpy(mZ, Z, mQuantity * sizeof(Real));
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
					Real dz = mZ[row] - mZ[col];
					Real t = Math<Real>::Sqrt(dx*dx + dy * dy + dz * dz);
					AMat[row][col] = Kernel(t);
				}
			}
		}

		// Compute matrix B [Nx4 matrix].
		VariableMatrix<Real> BMat(mQuantity, 4);
		for (row = 0; row < mQuantity; ++row)
		{
			BMat[row][0] = static_cast<Real>(1);
			BMat[row][1] = mX[row];
			BMat[row][2] = mY[row];
			BMat[row][3] = mZ[row];
		}

		// Compute A^{-1}.
		VariableMatrix<Real> invAMat(mQuantity, mQuantity);
		invAMat = LinearSystem<Real>().Inverse(AMat); //  ß∞‹≈◊≥ˆ“Ï≥£


		// Compute P = B^t A^{-1} [4xN matrix].
		VariableMatrix<Real> PMat = TransposeTimes(BMat, invAMat);

		// Compute Q = P B = B^t A^{-1} B  [4x4 matrix].
		VariableMatrix<Real> QMat = PMat * BMat;

		// Compute Q^{-1}.
		VariableMatrix<Real> invQMat(4, 4);
		invQMat = LinearSystem<Real>().Inverse(QMat);//  ß∞‹≈◊≥ˆ“Ï≥£


		 // Compute P*w.
		Real prod[4];
		for (row = 0; row < 4; ++row)
		{
			prod[row] = Math<Real>::GetValue(0);
			for (i = 0; i < mQuantity; ++i)
			{
				prod[row] += PMat[row][i] * F[i];
			}
		}

		// Compute 'b' vector for smooth thin plate spline.
		for (row = 0; row < 4; ++row)
		{
			mB[row] = Math<Real>::GetValue(0);
			for (i = 0; i < 4; ++i)
			{
				mB[row] += invQMat[row][i] * prod[i];
			}
		}

		// Compute w-B*b.
		Real* tmp = NEW1<Real>(mQuantity);
		for (row = 0; row < mQuantity; ++row)
		{
			tmp[row] = F[row];
			for (i = 0; i < 4; ++i)
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
			DELETE1(Z);
			DELETE1(F);
		}
	}

	template <typename Real>
	IntpThinPlateSpline3<Real>::~IntpThinPlateSpline3()
	{
		DELETE1(mX);
		DELETE1(mY);
		DELETE1(mZ);
		DELETE1(mA);
	}

	template <typename Real>
	bool IntpThinPlateSpline3<Real>::IsInitialized() const
	{
		return mInitialized;
	}

	template <typename Real>
	const Real* IntpThinPlateSpline3<Real>::GetACoefficients() const
	{
		return mA;
	}

	template <typename Real>
	const Real* IntpThinPlateSpline3<Real>::GetBCoefficients() const
	{
		return mB;
	}

	template <typename Real>
	Real IntpThinPlateSpline3<Real>::GetSmooth() const
	{
		return mSmooth;
	}

	template <typename Real>
	Real IntpThinPlateSpline3<Real>::operator() (Real x, Real y, Real z)
	{
		if (mInitialized)
		{
			// Map (x,y,z) to the unit cube.
			x = (x - mXMin)*mXInvRange;
			y = (y - mYMin)*mYInvRange;
			z = (z - mZMin)*mZInvRange;

			Real result = mB[0] + mB[1] * x + mB[2] * y + mB[3] * z;
			for (int i = 0; i < mQuantity; ++i)
			{
				Real dx = x - mX[i];
				Real dy = y - mY[i];
				Real dz = z - mZ[i];
				Real t = Math<Real>::Sqrt(dx*dx + dy * dy + dz * dz);
				result += mA[i] * Kernel(t);
			}
			return result;
		}

		return Math<Real>::sm_MaxReal;
	}

	template <typename Real>
	Real IntpThinPlateSpline3<Real>::ComputeFunctional() const
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
					Real dz = mZ[row] - mZ[col];
					Real t = Math<Real>::Sqrt(dx*dx + dy * dy + dz * dz);
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
	Real IntpThinPlateSpline3<Real>::Kernel(Real t)
	{
		return -Math<Real>::FAbs(t);
	}
}


#endif // MATHEMATICS_INTERPOLATION_INTP_THIN_PLATE_SPLINE3_DETAIL_H