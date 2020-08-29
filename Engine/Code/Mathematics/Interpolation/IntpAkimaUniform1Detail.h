// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 10:05)

#ifndef MATHEMATICS_INTERPOLATION_INTP_AKIMA_UNIFORM1_DETAIL_H
#define MATHEMATICS_INTERPOLATION_INTP_AKIMA_UNIFORM1_DETAIL_H

#include "IntpAkimaUniform1.h"

namespace Mathematics
{
	template <typename Real>
	IntpAkimaUniform1<Real>::IntpAkimaUniform1(int quantity, Real xMin,Real xSpacing, Real* F)
		:IntpAkima1<Real>{ quantity, F }
	{
		MATHEMATICS_ASSERTION_0(xSpacing > Math<Real>::GetValue(0), "Spacing must be positive\n");

		mXMin = xMin;
		mXMax = xMin + xSpacing * (quantity - 1);
		mXSpacing = xSpacing;

		// Compute slopes.
		auto invDX = (static_cast<Real>(1)) / xSpacing;
		Real* slope = NEW1<Real>(quantity + 3);
		int i, ip1, ip2;
		for (i = 0, ip1 = 1, ip2 = 2; i < quantity - 1; ++i, ++ip1, ++ip2)
		{
			slope[ip2] = (F[ip1] - F[i])*invDX;
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
		auto invDX2 = (static_cast<Real>(1)) / (xSpacing*xSpacing);
		auto invDX3 = invDX2 / xSpacing;
		for (i = 0, ip1 = 1; i < quantity - 1; ++i, ++ip1)
		{
			auto& poly = mPoly[i];

			auto F0 = F[i];
			auto F1 = F[ip1];
			auto df = F1 - F0;
			auto FDer0 = FDer[i];
			auto FDer1 = FDer[ip1];

			poly[0] = F0;
			poly[1] = FDer0;
			poly[2] = ((static_cast<Real>(3))*df - xSpacing * (FDer1 + (static_cast<Real>(2))*FDer0))*invDX2;
			poly[3] = (xSpacing*(FDer0 + FDer1) - (static_cast<Real>(2))*df)*invDX3;
		}

		DELETE1(slope);
		DELETE1(FDer);
	}

	template <typename Real>
	IntpAkimaUniform1<Real>::~IntpAkimaUniform1()
	{
	}

	template <typename Real>
	Real IntpAkimaUniform1<Real>::GetXMin() const
	{
		return mXMin;
	}

	template <typename Real>
	Real IntpAkimaUniform1<Real>::GetXMax() const
	{
		return mXMax;
	}

	template <typename Real>
	Real IntpAkimaUniform1<Real>::GetXSpacing() const
	{
		return mXSpacing;
	}

	template <typename Real>
	bool IntpAkimaUniform1<Real>::Lookup(Real x, int& index, Real& dx) const
	{
		if (x >= mXMin)
		{
			if (x <= mXMax)
			{
				for (index = 0; index + 1 < mQuantity; ++index)
				{
					if (x < mXMin + mXSpacing * (index + 1))
					{
						dx = x - (mXMin + mXSpacing * index);
						return true;
					}
				}

				--index;
				dx = x - (mXMin + mXSpacing * index);
				return true;
			}
		}

		return false;
	}


}


#endif // MATHEMATICS_INTERPOLATION_INTP_AKIMA_UNIFORM1_DETAIL_H