// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/23 17:20)

#ifndef MATHEMATICS_DISTANCE_DIST_POINT3_CIRCLE3_H
#define MATHEMATICS_DISTANCE_DIST_POINT3_CIRCLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Circle3.h" 
#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Algebra/AlgebraFwd.h"

namespace Mathematics
{
	template <typename Real>
	class DistPoint3Circle3 : public DistanceBase<Real, Vector3D<Real> >
	{
	public:
		using ClassType = DistPoint3Circle3<Real>;
		using Vector3D = Vector3D<Real>;
		using ParentType = DistanceBase<Real, Vector3D>;
		using Circle3 = Circle3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using DistanceResult = typename ParentType::DistanceResult; 

	public:
		DistPoint3Circle3(const Vector3D& point, const Circle3& circle);

		// Object access.
		const Vector3D& GetPoint() const;
		const Circle3& GetCircle() const;

		// Static distance queries.  Compute the distance from the point P to the
		// circle.  When P is on the normal line C+t*N where C is the circle
		// center and N is the normal to the plane containing the circle, then
		// all circle points are equidistant from P.  In this case the returned
		// point is C+r*U, where U is a vector perpendicular to N.
		virtual const DistanceResult GetSquared() const override;

		// Function calculations for dynamic distance queries.
		virtual const DistanceResult GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const override;

	private:
		Vector3D mPoint;
		Circle3 mCircle;
	};

	using DistPoint3Circle3f = DistPoint3Circle3<float>;
	using DistPoint3Circle3d = DistPoint3Circle3<double>;
}

#endif // MATHEMATICS_DISTANCE_DIST_POINT3_CIRCLE3_H
