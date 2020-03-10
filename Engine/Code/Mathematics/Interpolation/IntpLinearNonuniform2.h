// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 09:53)

#ifndef MATHEMATICS_INTERPOLATION_INTP_LINEAR_NONUNIFORM2_H
#define MATHEMATICS_INTERPOLATION_INTP_LINEAR_NONUNIFORM2_H

// Linear interpolation of a network of triangles whose vertices are of the
// form (x,y,f(x,y)).

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/ComputationalGeometry/Delaunay2.h"

namespace Mathematics
{
	template <typename Real>
	class  IntpLinearNonuniform2
	{
	public:
		// Construction and destruction.  If you want IntpLinearNonuniform2 to
		// delete the input array during destruction, set owner to 'true'.
		// Otherwise, you own the array and must delete it yourself.
		IntpLinearNonuniform2(const Delaunay2<Real>& DT, Real* F, bool owner);
		~IntpLinearNonuniform2();

		// Linear interpolation.  The return value is 'true' if and only if the
		// input point P is in the convex hull of the input vertices, in which
		// case the interpolation is valid.
		bool Evaluate(const Vector2D<Real>& P, Real& F);

	private:
		const Delaunay2<Real>* mDT;
		Real* mF;
		bool mOwner;
	};

	using IntpLinearNonuniform2f = IntpLinearNonuniform2<float>;
	using IntpLinearNonuniform2d = IntpLinearNonuniform2<double>;
}

#endif // MATHEMATICS_INTERPOLATION_INTP_LINEAR_NONUNIFORM2_H
