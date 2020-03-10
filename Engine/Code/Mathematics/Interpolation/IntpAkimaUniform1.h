// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 09:47)

#ifndef MATHEMATICS_INTERPOLATION_INTP_AKIMA_UNIFORM1_H
#define MATHEMATICS_INTERPOLATION_INTP_AKIMA_UNIFORM1_H

#include "Mathematics/MathematicsDll.h"

#include "IntpAkima1.h"

namespace Mathematics
{
	template <typename Real>
	class  IntpAkimaUniform1 : public IntpAkima1<Real>
	{
	public:
		// Construction and destruction.  IntpAkimaUniform1 accepts
		// responsibility for deleting the input array.  The interpolator is for
		// uniformly spaced x-values.
		IntpAkimaUniform1(int quantity, Real xMin, Real xSpacing, Real* F);
		virtual ~IntpAkimaUniform1();

		virtual Real GetXMin() const;
		virtual Real GetXMax() const;
		Real GetXSpacing() const;

	protected:
		using IntpAkima1<Real>::mQuantity;
		using IntpAkima1<Real>::mPoly;
		using IntpAkima1<Real>::ComputeDerivative;

		virtual bool Lookup(Real x, int& index, Real& dx) const;

		Real mXMin, mXMax, mXSpacing;
	};

	using IntpAkimaUniform1f = IntpAkimaUniform1<float>;
	using IntpAkimaUniform1d = IntpAkimaUniform1<double>;
}

#endif // MATHEMATICS_INTERPOLATION_INTP_AKIMA_UNIFORM1_H
