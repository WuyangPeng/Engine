// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 09:54)

#ifndef MATHEMATICS_INTERPOLATION_INTP_LINEAR_NONUNIFORM3_H
#define MATHEMATICS_INTERPOLATION_INTP_LINEAR_NONUNIFORM3_H

// Linear interpolation of a network of triangles whose vertices are of the
// form (x,y,z,f(x,y,z)).

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/ComputationalGeometry/Delaunay3.h"

namespace Mathematics
{
	template <typename Real>
	class  IntpLinearNonuniform3
	{
	public:
		// Construction and destruction.  If you want IntpLinearNonuniform3 to
		// delete the input array during destruction, set owner to 'true'.
		// Otherwise, you own the array and must delete it yourself.
		IntpLinearNonuniform3(const Delaunay3<Real>& DT, Real* F, bool owner);
		~IntpLinearNonuniform3();

		// Linear interpolation.  The return value is 'true' if and only if the
		// input point is in the convex hull of the input vertices, in which case
		// the interpolation is valid.
		bool Evaluate(const Vector3D<Real>& P, Real& F);

	private:
		const Delaunay3<Real>* mDT;
		Real* mF;
		bool mOwner;
	};

	using IntpLinearNonuniform3f = IntpLinearNonuniform3<float>;
	using IntpLinearNonuniform3d = IntpLinearNonuniform3<double>;

}

#endif // MATHEMATICS_INTERPOLATION_INTP_LINEAR_NONUNIFORM3_H
