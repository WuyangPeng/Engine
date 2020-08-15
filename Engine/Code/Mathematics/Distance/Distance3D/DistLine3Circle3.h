// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/23 17:19)

#ifndef MATHEMATICS_DISTANCE_DIST_LINE3_CIRCLE3_H
#define MATHEMATICS_DISTANCE_DIST_LINE3_CIRCLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Line3.h"
#include "Mathematics/Objects3D/Circle3.h"
#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Distance/DistanceBase.h"

namespace Mathematics
{
	template <typename Real>
	class DistLine3Circle3 : public DistanceBase<Real, Vector3D<Real> >
	{
	public:
		using ClassType = DistLine3Circle3<Real>;
		using Vector3D = Vector3D<Real>;
		using ParentType = DistanceBase<Real, Vector3D>;
		using Line3 = Line3<Real>;
		using Circle3 = Circle3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using DistanceResult = typename ParentType::DistanceResult; 

	public:
		DistLine3Circle3(const Line3& line, const Circle3& circle);

		// Object access.
		const Line3& GetLine() const;
		const Circle3& GetCircle() const;

		// Static distance queries.  Compute the distance from the point P to the
		// circle.  When P is on the normal line C+t*N where C is the circle
		// center and N is the normal to the plane containing the circle, then
		// all circle points are equidistant from P.  In this case the returned
		// point is C+r*U, where U is a vector perpendicular to N.
		 const DistanceResult GetSquared() const override;

		// Member access.  The possible combinations for number of line-circle
		// closest points is (1,1), (2,2), or (1,INT_MAX).		

		// Function calculations for dynamic distance queries.
		 const DistanceResult GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const override;

	private:
		// The mClosestLine[i] is an input.  The mClosestCircle[i] is an output.
		// The squared distance between these is returned.  The value of
		// mNumClosest is set to 1 or INT_MAX.  If the latter, all circle points
		// are equidistance from mClosestLine[i].
		Real SqrDistancePointCircle(int i) const;

		// Bisect the function F(s) = s + m2b2 - r*m0sqr*s/sqrt(m0sqr*s*s + b1sqr)
		// on the specified interval [smin,smax].
		static Real BisectF(Real m2b2, Real rm0sqr, Real m0sqr, Real b1sqr, Real smin, Real smax);

		Line3 mLine;
		Circle3 mCircle;

		mutable int mNumClosestLine;
		mutable Vector3D mClosestLine[2];
		mutable int mNumClosestCircle;
		mutable Vector3D mClosestCircle[2];
	};

	using DistLine3Circle3f = DistLine3Circle3<float>;
	using DistLine3Circle3d = DistLine3Circle3<double>;
}

#endif // MATHEMATICS_DISTANCE_DIST_LINE3_CIRCLE3_H
