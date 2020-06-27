// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/23 17:20)

#ifndef MATHEMATICS_DISTANCE_DIST_RAY3_TRIANGLE3_H
#define MATHEMATICS_DISTANCE_DIST_RAY3_TRIANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects3D/Ray3.h"  
#include "Mathematics/Objects3D/Triangle3.h"   

namespace Mathematics
{
	template <typename Real>
	class DistRay3Triangle3 : public DistanceBase<Real, Vector3D<Real> >
	{
	public:
		using ClassType = DistRay3Triangle3<Real>;
		using Vector3D = Vector3D<Real>;
		using ParentType = DistanceBase<Real, Vector3D>;
		using Ray3 = Ray3<Real>;
		using Triangle3 = Triangle3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using DistanceResult = typename ParentType::DistanceResult; 

	public:
		DistRay3Triangle3(const Ray3& ray, const Triangle3& triangle);

		// Object access.
		const Ray3& GetRay() const;
		const Triangle3& GetTriangle() const;

		// Static distance queries.
		virtual const DistanceResult GetSquared() const override;

		// Function calculations for dynamic distance queries.
		virtual const DistanceResult GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const override;

		// Information about the closest points.
		Real GetRayParameter() const;
		Real GetTriangleBary(int i) const;

	private:
		Ray3 mRay;
		Triangle3 mTriangle;

		// Information about the closest points.
		mutable Real mRayParameter;  // closest0 = ray.origin+param*ray.direction
		mutable Real mTriangleBary[3];  // closest1 = sum_{i=0}^2 bary[i]*tri.vertex[i]
	};

	using DistRay3Triangle3f = DistRay3Triangle3<float>;
	using DistRay3Triangle3d = DistRay3Triangle3<double>;
}

#endif // MATHEMATICS_DISTANCE_DIST_RAY3_TRIANGLE3_H
