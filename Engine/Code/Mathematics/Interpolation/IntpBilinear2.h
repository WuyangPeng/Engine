// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 09:50)

#ifndef MATHEMATICS_INTERPOLATION_INTP_BILINEAR2_H
#define MATHEMATICS_INTERPOLATION_INTP_BILINEAR2_H

#include "Mathematics/MathematicsDll.h"

namespace Mathematics
{
	template <typename Real>
	class  IntpBilinear2
	{
	public:
		// Construction and destruction.  IntpBilinear2 does not accept
		// responsibility for deleting the input array.  The application must do
		// so.  The interpolator is for uniformly spaced (x,y)-values.  The
		// function values are assumed to be organized as f(x,y) = F[y][x].

		IntpBilinear2(int xBound, int yBound, Real xMin, Real xSpacing,
			Real yMin, Real ySpacing, Real** F);

		int GetXBound() const;
		int GetYBound() const;
		int GetQuantity() const;
		Real** GetF() const;

		Real GetXMin() const;
		Real GetXMax() const;
		Real GetXSpacing() const;
		Real GetYMin() const;
		Real GetYMax() const;
		Real GetYSpacing() const;

		// Evaluate the function and its derivatives.  The application is
		// responsible for ensuring that xmin <= x <= xmax and ymin <= y <= ymax.
		// If (x,y) is outside the extremes, the function returns MAXREAL.  The
		// first operator is for function evaluation.  The second operator is for
		// function or derivative evaluations.  The uiXOrder argument is the order
		// of the x-derivative and the uiYOrder argument is the order of the
		// y-derivative.  Both orders are zero to get the function value itself.
		Real operator() (Real x, Real y) const;
		Real operator() (int xOrder, int yOrder, Real x, Real y) const;

	private:
		int mXBound, mYBound, m_Quantity;
		Real mXMin, mXMax, mXSpacing, mInvXSpacing;
		Real mYMin, mYMax, mYSpacing, mInvYSpacing;
		Real** mF;

		static const Real msBlend[2][2];
	};

	using IntpBilinear2f = IntpBilinear2<float>;
	using IntpBilinear2d = IntpBilinear2<double>;

}

#endif // MATHEMATICS_INTERPOLATION_INTP_BILINEAR2_H
