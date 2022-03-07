// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 13:32)

#ifndef MATHEMATICS_MISCELLANEOUS_QUAD_TO_QUAD_TRANSFORMS_H
#define MATHEMATICS_MISCELLANEOUS_QUAD_TO_QUAD_TRANSFORMS_H

#include "Mathematics/MathematicsDll.h"

namespace Mathematics
{
	// Homogeneous mapping of quadrilateral <p00,p10,p11,p01> to square [0,1]^2.
	// The quadrilateral points are ordered counterclockwise and map onto the
	// corners (0,0), (1,0), (1,1), and (0,1), respectively.

	template <typename Real>
	class   HmQuadToSqr
	{
	public:
		HmQuadToSqr(const Vector2<Real>& P00, const Vector2<Real>& P10,const Vector2<Real>& P11, const Vector2<Real>& P01);

		Vector2<Real> Transform(const Vector2<Real>& P);

	protected:
		Vector2<Real> mT, mG, mD;
		Matrix2<Real> mM;
	};


	// Homogeneous mapping of square [0,1]^2 to quadrilateral <p00,p10,p11,p01>.
	// The quadrilateral points are ordered counterclockwise and map onto the
	// corners (0,0), (1,0), (1,1), and (0,1), respectively.

	template <typename Real>
	class   HmSqrToQuad
	{
	public:
		HmSqrToQuad(const Vector2<Real>& P00, const Vector2<Real>& P10,const Vector2<Real>& P11, const Vector2<Real>& P01);

		Vector2<Real> Transform(const Vector2<Real>& P);

	protected:
		Vector2<Real> mT, mG, mD;
		Matrix2<Real> mM;
	};


	// Bilinear mapping of quadrilateral <p00,p10,p11,p01> to square [0,1]^2.
	// The quadrilateral points are ordered counterclockwise and map onto the
	// corners (0,0), (1,0), (1,1), and (0,1), respectively.
	//
	// If p is strictly inside the quadrilateral, then
	//   p = (1-t)*[(1-s)*p00+s*p10]+t*[(1-s)*p01+s*p11]
	//     = p00 + s*(p10-p00) + t*(p01-p00) + s*t*(p11+p00-p01-p10)
	//   (0,0) = (p00-p) + s*(p10-p00) + t*(p01-p00) + s*t*(p11+p00-p10-p01)
	//         = A + s*B + t*C + s*t*D (this equation defines A, B, C, D)
	//
	// Define K((x1,y1),(x2,y2)) = x1*y2-x2*y1.  Note that K(U,V) = -K(V,U).
	//   0 = K(A,C) + s*K(B,C) + s*t*K(D,C) = ac + bc*s - cd*s*t
	//   0 = K(A,B) + t*K(C,B) + s*t*K(D,B) = ab - bc*t - bd*s*t
	// where ac = K(A,C), bc = K(B,C), cd = K(C,D), ab = K(A,B), and bd = K(B,D).
	// Also, bc is not zero.  If bc is zero (nearly zero), then B and C are
	// parallel (nearly parallel) and the quadrilateral is degenerate (nearly
	// degenerate).
	//
	// The second equation is solved for
	//   t = ab/(bc + bd*s)
	// Replace in the first equation to obtain
	//   0 = ac + bc*s - cd*s*(ab/(bc+bd*s))
	// Multiply by bc+bd*s to obtain the quadratic equation
	//   0 = (ac+bc*s)*(bc+bd*s)-ab*cd*s
	//     = ac*bc+(bc^2+ac*bd-ab*cd)*s+bc*bd*s^2

	template <typename Real>
	class   BiQuadToSqr
	{
	public:
		BiQuadToSqr(const Vector2<Real>& P00, const Vector2<Real>& P10,const Vector2<Real>& P11, const Vector2<Real>& P01);

		Vector2<Real> Transform(const Vector2<Real>& P);

	protected:
		static Real Deviation(const Vector2<Real>& SPoint);

		Vector2<Real> mP00, mB, mC, mD;
		Real mBC, mBD, mCD;
	};


	// Bilinear mapping of square [0,1]^2 to quadrilateral <p00,p10,p11,p01>.
	// The quadrilateral points are ordered counterclockwise and map onto the
	// corners (0,0), (1,0), (1,1), and (0,1), respectively.
	//
	// Let be in the square.  The corresponding quadrilateral point is
	// p = (1-t)*[(1-s)*p00+s*p10]+t*[(1-s)*p01+s*p11].

	template <typename Real>
	class   BiSqrToQuad
	{
	public:
		BiSqrToQuad(const Vector2<Real>& P00, const Vector2<Real>& P10,const Vector2<Real>& P11, const Vector2<Real>& P01);

		Vector2<Real> Transform(const Vector2<Real>& P);

	protected:
		Vector2<Real> mS00, mS01, mS10, mS11;
	};

	using HmQuadToSqrf = HmQuadToSqr<float>;
	using HmQuadToSqrd = HmQuadToSqr<double>;
	using HmSqrToQuadf = HmSqrToQuad<float>;
	using HmSqrToQuadd = HmSqrToQuad<double>;
	using BiQuadToSqrf = BiQuadToSqr<float>;
	using BiQuadToSqrd = BiQuadToSqr<double>;
	using BiSqrToQuadf = BiSqrToQuad<float>;
	using BiSqrToQuadd = BiSqrToQuad<double>;
}

#endif // MATHEMATICS_MISCELLANEOUS_QUAD_TO_QUAD_TRANSFORMS_H
