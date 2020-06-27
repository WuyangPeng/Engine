// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 10:04)

#ifndef MATHEMATICS_INTERPOLATION_INTP_AKIMA_NONUNIFORM1_DETAIL_H
#define MATHEMATICS_INTERPOLATION_INTP_AKIMA_NONUNIFORM1_DETAIL_H

#include "IntpAkimaNonuniform1.h"

namespace Mathematics
{

	template <typename Real>
	IntpAkimaNonuniform1<Real>::IntpAkimaNonuniform1(int quantity, Real* X, Real* F)
		: IntpAkima1<Real>{ quantity, F }, mX{ X }
	{
		// Compute slopes.
		Real* slope = NEW1<Real>(quantity + 3);
		int i, ip1, ip2;
		for (i = 0, ip1 = 1, ip2 = 2; i < quantity - 1; ++i, ++ip1, ++ip2)
		{
			Real dx = X[ip1] - X[i];
			Real df = F[ip1] - F[i];
			slope[ip2] = df / dx;
		}

		slope[1] = (static_cast<Real>(2))*slope[2] - slope[3];
		slope[0] = (static_cast<Real>(2))*slope[1] - slope[2];
		slope[quantity + 1] = (static_cast<Real>(2))*slope[quantity] - slope[quantity - 1];
		slope[quantity + 2] = (static_cast<Real>(2))*slope[quantity + 1] - slope[quantity];

		// Construct derivatives.
		Real* FDer = NEW1<Real>(quantity);
		for (i = 0; i < quantity; ++i)
		{
			FDer[i] = ComputeDerivative(slope + i);
		}

		// Construct polynomials.
		for (i = 0, ip1 = 1; i < quantity - 1; ++i, ++ip1)
		{
			auto& poly = mPoly[i];

			auto F0 = F[i];
			auto F1 = F[ip1];
			auto FDer0 = FDer[i];
			auto FDer1 = FDer[ip1];
			auto df = F1 - F0;
			auto dx = X[ip1] - X[i];
			auto dx2 = dx * dx;
			auto dx3 = dx2 * dx;

			poly[0] = F0;
			poly[1] = FDer0;
			poly[2] = ((static_cast<Real>(3))*df - dx * (FDer1 + (static_cast<Real>(2))*FDer0)) / dx2;
			poly[3] = (dx*(FDer0 + FDer1) - (static_cast<Real>(2))*df) / dx3;
		}

		DELETE1(slope);
		DELETE1(FDer);
	}

	template <typename Real>
	IntpAkimaNonuniform1<Real>::~IntpAkimaNonuniform1()
	{
	}

	template <typename Real>
	const Real* IntpAkimaNonuniform1<Real>::GetX() const
	{
		return mX;
	}

	template <typename Real>
	Real IntpAkimaNonuniform1<Real>::GetXMin() const
	{
		return mX[0];
	}

	template <typename Real>
	Real IntpAkimaNonuniform1<Real>::GetXMax() const
	{
		return mX[mQuantity - 1];
	}

	template <typename Real>
	bool IntpAkimaNonuniform1<Real>::Lookup(Real x, int& index, Real& dx) const
	{
		if (x >= mX[0])
		{
			if (x <= mX[mQuantity - 1])
			{
				for (index = 0; index + 1 < mQuantity; ++index)
				{
					if (x < mX[index + 1])
					{
						dx = x - mX[index];
						return true;
					}
				}

				--index;
				dx = x - mX[index];
				return true;
			}
		}

		return false;
	}


}

#endif // MATHEMATICS_INTERPOLATION_INTP_AKIMA_NONUNIFORM1_DETAIL_H