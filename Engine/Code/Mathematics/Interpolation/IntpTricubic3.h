// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/16 09:56)

#ifndef MATHEMATICS_INTERPOLATION_INTP_TRICUBIC3_H
#define MATHEMATICS_INTERPOLATION_INTP_TRICUBIC3_H

#include "Mathematics/MathematicsDll.h"

namespace Mathematics
{
	template <typename Real>
	class  IntpTricubic3
	{
	public:
		// Construction and destruction.  IntpTricubic3 does not accept
		// responsibility for deleting the input array.  The application must do
		// so.  The interpolator is for uniformly spaced (x,y,z)-values.  The
		// function values are assumed to be organized as f(x,y,z) = F[z][y][x].
		// Exact interpolation is achieved by setting catmullRom to 'true',
		// giving you the Catmull-Rom blending matrix.  If a smooth interpolation
		// is desired, set catmullRom to 'false' to obtain B-spline blending.

		IntpTricubic3(int xBound, int yBound, int zBound, Real xMin,Real xSpacing, Real yMin, Real ySpacing, Real zMin, Real zSpacing,Real*** F, bool catmullRom);

		int GetXBound() const;
		int GetYBound() const;
		int GetZBound() const;
		int GetQuantity() const;
		Real*** GetF() const;

		Real GetXMin() const;
		Real GetXMax() const;
		Real GetXSpacing() const;
		Real GetYMin() const;
		Real GetYMax() const;
		Real GetYSpacing() const;
		Real GetZMin() const;
		Real GetZMax() const;
		Real GetZSpacing() const;

		// Evaluate the function and its derivatives.  The application is
		// responsible for ensuring that xmin <= x <= xmax, ymin <= y <= ymax,
		// and zmin <= z <= zmax.  If (x,y,z) is outside the extremes, the
		// function returns MAXREAL.  The first operator is for function
		// evaluation.  The second operator is for function or derivative
		// evaluations.  The uiXOrder argument is the order of the x-derivative,
		// the uiYOrder argument is the order of the y-derivative, and the
		// uiZOrder argument is the order of the z-derivative.  All orders are
		// zero to get the function value itself.
		Real operator() (Real x, Real y, Real z) const;
		Real operator() (int xOrder, int yOrder, int zOrder, Real x, Real y,Real z) const;

	private:
		int mXBound, mYBound, mZBound, mQuantity;
		Real mXMin, mXMax, mXSpacing, mInvXSpacing;
		Real mYMin, mYMax, mYSpacing, mInvYSpacing;
		Real mZMin, mZMax, mZSpacing, mInvZSpacing;
		Real*** mF;
		const Real(*mBlend)[4];

		static const Real msCRBlend[4][4];
		static const Real msBSBlend[4][4];
	};

	using IntpTricubic3f = IntpTricubic3<float>;
	using IntpTricubic3d = IntpTricubic3<double>;
}

#endif // MATHEMATICS_INTERPOLATION_INTP_TRICUBIC3_H
