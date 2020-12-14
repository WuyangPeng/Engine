// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/23 17:20)

#ifndef MATHEMATICS_DISTANCE_DIST_RAY3_BOX3_H
#define MATHEMATICS_DISTANCE_DIST_RAY3_BOX3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Ray3.h"  
#include "Mathematics/Objects3D/Box3.h"   
#include "Mathematics/Distance/DistanceBase.h"

namespace Mathematics
{
	template <typename Real>
	class DistanceRay3Box3 : public DistanceBase<Real, Vector3D<Real> >
	{
	public:
		using ClassType = DistanceRay3Box3<Real>;
		using Vector3D = Vector3D<Real>;
		using ParentType = DistanceBase<Real, Vector3D>;
		using Ray3 = Ray3<Real>;
		using Box3 = Box3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using DistanceResult = typename ParentType::DistanceResult; 

	public:
		DistanceRay3Box3(const Ray3& ray, const Box3& box);

		// Object access.
		const Ray3& GetRay() const;
		const Box3& GetBox() const;

		// Static distance queries.
		 const DistanceResult GetSquared() const override;

		// Function calculations for dynamic distance queries.
		 const DistanceResult GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const override;

	private:
		Ray3 mRay;
		Box3 mBox;
	};

	using DistRay3Box3f = DistanceRay3Box3<float>;
	using DistRay3Box3d = DistanceRay3Box3<double>;
}

#endif // MATHEMATICS_DISTANCE_DIST_RAY3_BOX3_H
