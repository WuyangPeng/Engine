// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 09:59)

#ifndef MATHEMATICS_INTERPOLATION_INTP_VECTOR_FIELD2_H
#define MATHEMATICS_INTERPOLATION_INTP_VECTOR_FIELD2_H

// Given points (x0[i],y0[i]) which are mapped to (x1[i],y1[i]) for
// 0 <= i < N, interpolate positions (xIn,yIn) to (xOut,yOut).

#include "Mathematics/MathematicsDll.h"

#include "IntpQdrNonuniform2.h"

namespace Mathematics
{
	template <typename Real>
	class  IntpVectorField2
	{
	public:
		// Construction and destruction.  If you want IntpVectorField2 to delete
		// the input arrays during destruction, set owner to 'true'.  Otherwise,
		// you own the arrays and must delete them yourself.
		//
		// The computation type is for the Delaunay triangulation and should be
		// one of Query::{QT_INT64,QT_INTEGER,QT_RATIONAL,QT_REAL}.
		IntpVectorField2(const std::vector<Vector2<Real> >& domain,Vector2<Real>* range, bool owner, QueryType queryType);

		~IntpVectorField2();

		// Return 'true' if and only if (xIn,yIn) is in the convex hull of the
		// input points.  In this case, (xOut,yOut) is valid.  If the return
		// value is 'false', (xOut,yOut) is invalid and should not be used.
		bool Evaluate(const Vector2<Real>& input, Vector2<Real>& output);

	protected:
		Delaunay2<Real>* mDT;
		IntpQdrNonuniform2<Real>* mXInterp;
		IntpQdrNonuniform2<Real>* mYInterp;
	};

	using IntpVectorField2f = IntpVectorField2<float>;
	using IntpVectorField2d = IntpVectorField2<double>;

}

#endif // MATHEMATICS_INTERPOLATION_INTP_VECTOR_FIELD2_H
