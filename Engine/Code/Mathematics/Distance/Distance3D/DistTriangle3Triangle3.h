// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/10 16:32)

#ifndef MATHEMATICS_DISTANCE_DIST_TRIANGLE3_TRIANGLE3_H
#define MATHEMATICS_DISTANCE_DIST_TRIANGLE3_TRIANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Distance/DistanceBase.h" 
#include "Mathematics/Objects3D/Triangle3.h" 

namespace Mathematics
{
	template <typename Real>
	class DistTriangle3Triangle3 : public DistanceBase<Real,Vector3D<Real> >
	{
	public:
		using ClassType = DistTriangle3Triangle3<Real>;
		using Vector3D = Vector3D<Real>;
		using ParentType = DistanceBase<Real, Vector3D>;
		using Triangle3 = Triangle3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using DistanceResult = typename ParentType::DistanceResult;
		using ParentType::GetZeroThreshold;

	public:
		DistTriangle3Triangle3 (const Triangle3& triangle0, const Triangle3& triangle1);
		
		// Object access.
		const Triangle3& GetTriangle0 () const;
		const Triangle3& GetTriangle1 () const;
		
		// Static distance queries.
		virtual const DistanceResult GetSquared() const override;
		
		// Function calculations for dynamic distance queries.
		virtual const DistanceResult GetSquared(Real t, const Vector3D& lhsVelocity,const Vector3D& rhsVelocity) const override;
		
		// Information about the closest points.
		Real GetTriangleBary0 (int i) const;
		Real GetTriangleBary1 (int i) const;
		
	private:
		Triangle3 mTriangle0;
		Triangle3 mTriangle1;
		
		// Information about the closest points.
		mutable Real mTriangleBary0[3];  // closest0 = sum_{i=0}^2 bary0[i]*vertex0[i]
		mutable Real mTriangleBary1[3];  // closest1 = sum_{i=0}^2 bary1[i]*vertex1[i]
	};
	
	using DistTriangle3Triangle3f = DistTriangle3Triangle3<float>;
	using DistTriangle3Triangle3d = DistTriangle3Triangle3<double>;
}

#endif // MATHEMATICS_DISTANCE_DIST_TRIANGLE3_TRIANGLE3_H
