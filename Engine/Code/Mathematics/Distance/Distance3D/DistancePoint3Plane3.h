// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/23 17:20)

#ifndef MATHEMATICS_DISTANCE_DIST_POINT3_PLANE3_H
#define MATHEMATICS_DISTANCE_DIST_POINT3_PLANE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Plane3.h"   
#include "Mathematics/Distance/DistanceBase.h"

namespace Mathematics
{
	template <typename Real>
	class  DistancePoint3Plane3 : public DistanceBase<Real, Vector3D<Real> >
	{
	public:
		using ClassType = DistancePoint3Plane3<Real>;
		using Vector3D = Vector3D<Real>;
		using ParentType = DistanceBase<Real, Vector3D>;
		using Plane3 = Plane3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using DistanceResult = typename ParentType::DistanceResult; 

	public:
		DistancePoint3Plane3(const Vector3D& point, const Plane3& plane);

		// Object access.
		const Vector3D& GetPoint() const;
		const Plane3& GetPlane() const;

		// Static distance queries.
		 const DistanceResult GetSquared() const override;

		// Function calculations for dynamic distance queries.
		 const DistanceResult GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const override;

	private:
		Vector3D mPoint;
		Plane3 mPlane;
	};

	using DistPoint3Plane3f = DistancePoint3Plane3<float>;
	using DistPoint3Plane3d = DistancePoint3Plane3<double>;
}

#endif // MATHEMATICS_DISTANCE_DIST_POINT3_PLANE3_H
