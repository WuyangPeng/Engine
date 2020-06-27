// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/23 17:21)

#ifndef MATHEMATICS_DISTANCE_DIST_SEGMENT3_BOX3_H
#define MATHEMATICS_DISTANCE_DIST_SEGMENT3_BOX3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects3D/Segment3.h"  
#include "Mathematics/Objects3D/Box3.h"    

namespace Mathematics
{
	template <typename Real>
	class DistSegment3Box3 : public DistanceBase<Real, Vector3D<Real> >
	{
	public:
		using ClassType = DistSegment3Box3<Real>;
		using Vector3D = Vector3D<Real>;
		using ParentType = DistanceBase<Real, Vector3D>;
		using Segment3 = Segment3<Real>;
		using Box3 = Box3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using DistanceResult = typename ParentType::DistanceResult; 

	public:
		DistSegment3Box3(const Segment3& segment, const Box3& box);

		// Object access.
		const Segment3& GetSegment() const;
		const Box3& GetBox() const;

		// Static distance queries.
		virtual const DistanceResult GetSquared() const override;

		// Function calculations for dynamic distance queries.
		virtual const DistanceResult GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const override;

	private:
		Segment3 mSegment;
		Box3 mBox;
	};

	using DistSegment3Box3f = DistSegment3Box3<float>;
	using DistSegment3Box3d = DistSegment3Box3<double>;
}

#endif // MATHEMATICS_DISTANCE_DIST_SEGMENT3_BOX3_H
