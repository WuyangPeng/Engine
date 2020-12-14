// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/23 17:21)

#ifndef MATHEMATICS_DISTANCE_DIST_SEGMENT3_TRIANGLE3_H
#define MATHEMATICS_DISTANCE_DIST_SEGMENT3_TRIANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects3D/Segment3.h"  
#include "Mathematics/Objects3D/Triangle3.h"    

namespace Mathematics
{
	template <typename Real>
	class DistanceSegment3Triangle3 : public DistanceBase<Real, Vector3D<Real> >
	{
	public:
		using ClassType = DistanceSegment3Triangle3<Real>;
		using Vector3D = Vector3D<Real>;
		using ParentType = DistanceBase<Real, Vector3D>;
		using Segment3 = Segment3<Real>;
		using Triangle3 = Triangle3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using DistanceResult = typename ParentType::DistanceResult; 

	public:
		DistanceSegment3Triangle3(const Segment3& segment, const Triangle3& triangle);

		// Object access.
		const Segment3& GetSegment() const;
		const Triangle3& GetTriangle() const;

		// Static distance queries.
		 const DistanceResult GetSquared() const override;

		// Function calculations for dynamic distance queries.
		 const DistanceResult GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const override;

		// Information about the closest points.
		Real GetSegmentParameter() const;
		Real GetTriangleBary(int i) const;

	private:
		Segment3 mSegment;
		Triangle3 mTriangle;

		// Information about the closest points.
		mutable Real mSegmentParameter;  // closest0 = seg.origin+param*seg.direction
		mutable Real mTriangleBary[3];  // closest1 = sum_{i=0}^2 bary[i]*tri.vertex[i]
	};

	using DistSegment3Triangle3f = DistanceSegment3Triangle3<float>;
	using DistSegment3Triangle3d = DistanceSegment3Triangle3<double>;
}

#endif // MATHEMATICS_DISTANCE_DIST_SEGMENT3_TRIANGLE3_H
