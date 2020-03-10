// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 09:46)

#ifndef MATHEMATICS_INTERPOLATION_INTP_AKIMA_NONUNIFORM1_H
#define MATHEMATICS_INTERPOLATION_INTP_AKIMA_NONUNIFORM1_H

#include "Mathematics/MathematicsDll.h"

#include "IntpAkima1.h"

namespace Mathematics
{

	template <typename Real>
	class  IntpAkimaNonuniform1 : public IntpAkima1<Real>
	{
	public:
		// Construction and destruction.  IntpAkimaNonuniform1 does not
		// accept responsibility for deleting the input arrays.  The application
		// must do so.  The interpolator is for arbitrarily spaced x-values.
		IntpAkimaNonuniform1(int quantity, Real* X, Real* F);
		virtual ~IntpAkimaNonuniform1();

		const Real* GetX() const;
		virtual Real GetXMin() const;
		virtual Real GetXMax() const;

	protected:
		using IntpAkima1<Real>::mQuantity;
		using IntpAkima1<Real>::mPoly;
		using IntpAkima1<Real>::ComputeDerivative;

		virtual bool Lookup(Real x, int& index, Real& dx) const;

		Real* mX;
	};

	using IntpAkimaNonuniform1f = IntpAkimaNonuniform1<float>;
	using IntpAkimaNonuniform1d = IntpAkimaNonuniform1<double>;
}

#endif // MATHEMATICS_INTERPOLATION_INTP_AKIMA_NONUNIFORM1_H
