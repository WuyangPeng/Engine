// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/23 17:20)

#ifndef MATHEMATICS_DISTANCE_DIST_RAY3_RECTANGLE3_H
#define MATHEMATICS_DISTANCE_DIST_RAY3_RECTANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Ray3.h"  
#include "Mathematics/Objects3D/Rectangle3.h"    
#include "Mathematics/Distance/DistanceBase.h"

namespace Mathematics
{
	template <typename Real>
	class DistanceRay3Rectangle3 : public DistanceBase<Real, Vector3D<Real> >
	{
	public:
		using ClassType = DistanceRay3Rectangle3<Real>;
		using Vector3D = Vector3D<Real>;
		using ParentType = DistanceBase<Real, Vector3D>;
		using Ray3 = Ray3<Real>;
		using Rectangle3 = Rectangle3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using DistanceResult = typename ParentType::DistanceResult; 

	public:
		DistanceRay3Rectangle3(const Ray3& ray, const Rectangle3& rectangle);

		// Object access.
		const Ray3& GetRay() const;
		const Rectangle3& GetRectangle() const;

		// Static distance queries.
		 const DistanceResult GetSquared() const override;

		// Function calculations for dynamic distance queries.
		 const DistanceResult GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const override;

		// Information about the closest points.
		Real GetRayParameter() const;
		Real GetRectangleCoordinate(int i) const;

	private:
		Ray3 mRay;
		Rectangle3 mRectangle;

		// Information about the closest points.

		// closest0 = ray.origin + param*ray.direction
		mutable Real mRayParameter;

		// closest1 = rect.center + param0*rect.dir0 + param1*rect.dir1
		mutable Real mRectCoord[2];
	};

	using DistRay3Rectangle3f = DistanceRay3Rectangle3<float>;
	using DistRay3Rectangle3d = DistanceRay3Rectangle3<double>;
}

#endif // MATHEMATICS_DISTANCE_DIST_RAY3_RECTANGLE3_H
