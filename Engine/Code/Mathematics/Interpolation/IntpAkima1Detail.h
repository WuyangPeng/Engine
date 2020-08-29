// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 10:01)

#ifndef MATHEMATICS_INTERPOLATION_INTP_AKIMA1_DETAIL_H
#define MATHEMATICS_INTERPOLATION_INTP_AKIMA1_DETAIL_H

#include "IntpAkima1.h"

namespace Mathematics
{

	template <typename Real>
	IntpAkima1<Real>::IntpAkima1(int quantity, Real* F)
	{
		// At least three data points are needed to construct the estimates of
		// the boundary derivatives.
		MATHEMATICS_ASSERTION_0(quantity >= 3 && F, "Invalid input\n");

		mQuantity = quantity;
		mF = F;
		mPoly = NEW1<Polynomial>(quantity - 1);
	}

	template <typename Real>
	IntpAkima1<Real>::~IntpAkima1()
	{
		DELETE1(mPoly);
	}

	template <typename Real>
	int IntpAkima1<Real>::GetQuantity() const
	{
		return mQuantity;
	}

	template <typename Real>
	const Real* IntpAkima1<Real>::GetF() const
	{
		return mF;
	}

	template <typename Real>
	const typename IntpAkima1<Real>::Polynomial* IntpAkima1<Real>::GetPolynomials() const
	{
		return mPoly;
	}

	template <typename Real>
	const typename IntpAkima1<Real>::Polynomial& IntpAkima1<Real>::GetPolynomial(int i) const
	{
		return mPoly[i];
	}

	template <typename Real>
	Real IntpAkima1<Real>::ComputeDerivative(Real* slope) const
	{
		if (slope[1] != slope[2])
		{
			if (slope[0] != slope[1])
			{
				if (slope[2] != slope[3])
				{
					auto ad0 = Math<Real>::FAbs(slope[3] - slope[2]);
					auto ad1 = Math<Real>::FAbs(slope[0] - slope[1]);
					return (ad0*slope[1] + ad1 * slope[2]) / (ad0 + ad1);
				}
				else
				{
					return slope[2];
				}
			}
			else
			{
				if (slope[2] != slope[3])
				{
					return slope[1];
				}
				else
				{
					return (static_cast<Real>(0.5))*(slope[1] + slope[2]);
				}
			}
		}
		else
		{
			return slope[1];
		}
	}

	template <typename Real>
	Real IntpAkima1<Real>::operator() (Real x) const
	{
		int index;
		Real dx;

		if (Lookup(x, index, dx))
		{
			return mPoly[index](dx);
		}

		return Math<Real>::sm_MaxReal;
	}

	template <typename Real>
	Real IntpAkima1<Real>::operator() (int order, Real x) const
	{
		int index;
		Real dx;

		if (Lookup(x, index, dx))
		{
			return mPoly[index](order, dx);
		}

		return Math<Real>::sm_MaxReal;
	} 

	// IntpAkima1::Polynomial

	template <typename Real>
	Real IntpAkima1<Real>::Polynomial::operator() (Real x) const
	{
		return mCoeff[0] + x * (mCoeff[1] + x * (mCoeff[2] + x * mCoeff[3]));
	}

	template <typename Real>
	Real IntpAkima1<Real>::Polynomial::operator() (int order, Real x) const
	{
		switch (order)
		{
		case 0:
			return mCoeff[0] + x * (mCoeff[1] + x * (mCoeff[2] + x * mCoeff[3]));
		case 1:
			return mCoeff[1] + x * ((static_cast<Real>(2))*mCoeff[2] + x * (static_cast<Real>(3))*mCoeff[3]);
		case 2:
			return (static_cast<Real>(2))*mCoeff[2] + x * ((Real)6)*mCoeff[3];
		case 3:
			return ((Real)6)*mCoeff[3];
		}

		return Math<Real>::GetValue(0);
	}

}


#endif // MATHEMATICS_INTERPOLATION_INTP_AKIMA1_DETAIL_H