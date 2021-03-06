// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/16 09:54)

#ifndef MATHEMATICS_INTERPOLATION_INTP_QUADRATIC_NONUNIFORM2_H
#define MATHEMATICS_INTERPOLATION_INTP_QUADRATIC_NONUNIFORM2_H

// Quadratic interpolation of a network of triangles whose vertices are of
// the form (x,y,f(x,y)).  This code is an implementation of the algorithm
// found in
//
//   Zoltan J. Cendes and Steven H. Wong,
//   C1 quadratic interpolation over arbitrary point sets,
//   IEEE Computer Graphics & Applications,
//   pp. 8-16, 1987

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/ComputationalGeometry/Delaunay2.h"

namespace Mathematics
{
	template <typename Real>
	class  IntpQdrNonuniform2
	{
	public:
		// Construction and destruction.  If you want IntpQdrNonuniform2 to
		// delete the input array during destruction, set owner to 'true'.
		// Otherwise, you own the array and must delete it yourself.
		//
		// The first constructor requires you to specify function values F and
		// first-order partial derivative values Fx and Fy.  The second
		// constructor requires only F, but the Fx and Fy values are estimated
		// at the sample points.

		IntpQdrNonuniform2(const Delaunay2<Real>& DT, Real* F, Real* FX,Real* FY, bool owner);

		IntpQdrNonuniform2(const Delaunay2<Real>& DT, Real* F, bool owner);

		~IntpQdrNonuniform2();

		// Quadratic interpolation.  The return value is 'true' if and only if the
		// input point is in the convex hull of the input vertices, in which case
		// the interpolation is valid.
		bool Evaluate(const Vector2D<Real>& P, Real& F, Real& FX, Real& FY);

	private:
		class TriangleData
		{
		public:
			Vector2D<Real> Center;
			Vector2D<Real> Intersect[3];
			Real Coeff[19];
		};

		class Jet
		{
		public:
			Real F, FX, FY;
		};

		const Delaunay2<Real>* mDT;
		Real* mF;
		Real* mFX;
		Real* mFY;
		TriangleData* mTData;  // triangle data
		bool mFOwner, mFXFYOwner;

		void EstimateDerivatives();
		void ProcessTriangles();
		void ComputeCrossEdgeIntersections(int t);
		void ComputeCoefficients(int t);
	};

	using IntpQdrNonuniform2f = IntpQdrNonuniform2<float>;
	using IntpQdrNonuniform2d = IntpQdrNonuniform2<double>;
}

#endif // MATHEMATICS_INTERPOLATION_INTP_QUADRATIC_NONUNIFORM2_H
