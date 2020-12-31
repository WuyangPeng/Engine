// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 09:49)

#ifndef MATHEMATICS_INTERPOLATION_INTP_AKIMA_UNIFORM3_H
#define MATHEMATICS_INTERPOLATION_INTP_AKIMA_UNIFORM3_H

#include "Mathematics/MathematicsDll.h"

namespace Mathematics
{
	template <typename Real>
	class  IntpAkimaUniform3
	{
	public:
		// Construction and destruction.  Interp3DAkimaUniform does not accept
		// responsibility for deleting the input array.  The application must do
		// so.  The interpolator is for uniformly spaced (x,y,z)-values.  The
		// function values are assumed to be organized as f(x,y,z) = F[z][y][x].
		IntpAkimaUniform3(int xBound, int yBound, int zBound, Real xMin,Real xSpacing, Real yMin, Real ySpacing, Real zMin, Real zSpacing,Real*** F);

		~IntpAkimaUniform3();

		class  Polynomial
		{
		public:
			Polynomial();

			// P(x,y,z) = sum_{i=0}^3 sum_{j=0}^3 sum_{k=0}^3 a_{ijk} x^i y^j z^k
			Real& A(int ix, int iy, int iz);

			Real operator() (Real x, Real y, Real z) const;
			Real operator() (int xOrder, int yOrder, int zOrder, Real x,Real y, Real z) const;

		protected:
			Real mCoeff[4][4][4];
		};

		int GetXBound() const;
		int GetYBound() const;
		int GetZBound() const;
		int GetQuantity() const;
		Real*** GetF() const;
		Polynomial*** GetPolynomials() const;
		const Polynomial& GetPolynomial(int ix, int iy, int iz) const;

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
		Real operator() (int xOrder, int yOrder, int zOrder, Real x,Real y, Real z) const;

	private:
		Real ComputeDerivative(Real* slope) const;
		void Construct(Polynomial& poly, Real F[2][2][2], Real FX[2][2][2],Real FY[2][2][2], Real FZ[2][2][2], Real FXY[2][2][2],Real FXZ[2][2][2], Real FYZ[2][2][2], Real FXYZ[2][2][2]);

		bool XLookup(Real x, int& xIndex, Real& dx) const;
		bool YLookup(Real y, int& yIndex, Real& dy) const;
		bool ZLookup(Real z, int& zIndex, Real& dz) const;

		int mXBound, mYBound, mZBound, m_Quantity;
		Real*** mF;
		Polynomial*** mPoly;
		Real mXMin, mXMax, mXSpacing;
		Real mYMin, mYMax, mYSpacing;
		Real mZMin, mZMax, mZSpacing;

	private:
		// These methods exist to split up the constructor into chunks of code
		// that compile quickly.

		Real*** GetFX();
		Real*** GetFY();
		Real*** GetFZ();
		Real*** GetFXY();
		Real*** GetFXZ();
		Real*** GetFYZ();
		Real*** GetFXYZ();

		void GetPolynomials(Real*** FX, Real*** FY, Real*** FZ,Real*** FXY, Real*** FXZ, Real*** FYZ,Real*** FXYZ);
	};

	using IntpAkimaUniform3f = IntpAkimaUniform3<float>;
	using IntpAkimaUniform3d = IntpAkimaUniform3<double>;

}

#endif // MATHEMATICS_INTERPOLATION_INTP_AKIMA_UNIFORM3_H
