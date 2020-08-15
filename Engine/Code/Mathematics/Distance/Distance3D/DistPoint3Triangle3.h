// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/23 17:20)

#ifndef MATHEMATICS_DISTANCE_DIST_POINT3_RIANGLE3_H
#define MATHEMATICS_DISTANCE_DIST_POINT3_RIANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects3D/Triangle3.h"  

namespace Mathematics
{
	template <typename Real>
	class DistPoint3Triangle3 : public DistanceBase<Real, Vector3D<Real> >
	{
	public:
		using ClassType = DistPoint3Triangle3<Real>;
		using Vector3D = Vector3D<Real>;
		using ParentType = DistanceBase<Real, Vector3D>;
		using Triangle3 = Triangle3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using DistanceResult = typename ParentType::DistanceResult; 

	public:
		DistPoint3Triangle3(const Vector3D& point, const Triangle3& triangle);

		// Object access.
		const Vector3D& GetPoint() const;
		const Triangle3& GetTriangle() const;

		// Static distance queries.
		 const DistanceResult GetSquared() const override;

		// Function calculations for dynamic distance queries.
		 const DistanceResult GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const override;

		// Information about the closest triangle point.
		Real GetTriangleBary(int i) const;

	private:
		Vector3D mPoint;
		Triangle3 mTriangle;

		// Information about the closest triangle point.
		mutable Real mTriangleBary[3];  // closest1 = sum_{i=0}^2 bary[i]*tri.vertex[i]
	};

	using DistPoint3Triangle3f = DistPoint3Triangle3<float>;
	using DistPoint3Triangle3d = DistPoint3Triangle3<double>;
}

#endif // MATHEMATICS_DISTANCE_DIST_POINT3_RIANGLE3_H
