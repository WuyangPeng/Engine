// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/10 16:25)

#ifndef MATHEMATICS_DISTANCE_DIST_SEGMENT3_RECTANGLE3_H
#define MATHEMATICS_DISTANCE_DIST_SEGMENT3_RECTANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects3D/Segment3.h"  
#include "Mathematics/Objects3D/Rectangle3.h"    

namespace Mathematics
{
	template <typename Real>
	class DistSegment3Rectangle3 : public DistanceBase<Real,Vector3D<Real> >
	{
	public:
		using ClassType = DistSegment3Rectangle3<Real>;
		using Vector3D = Vector3D<Real>;
		using ParentType = DistanceBase<Real, Vector3D>;
		using Segment3 = Segment3<Real>;
		using Rectangle3 = Rectangle3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using DistanceResult = typename ParentType::DistanceResult;
		using ParentType::GetZeroThreshold;

	public:
		DistSegment3Rectangle3 (const Segment3& segment,const Rectangle3& rectangle);
		
		// Object access.
		const Segment3& GetSegment () const;
		const Rectangle3& GetRectangle () const;
		
		// Static distance queries.
		virtual const DistanceResult GetSquared() const override;
		// Function calculations for dynamic distance queries.
		virtual const DistanceResult GetSquared(Real t, const Vector3D& lhsVelocity,const Vector3D& rhsVelocity) const override;
		
		// Information about the closest points.
		Real GetSegmentParameter () const;
		Real GetRectangleCoordinate (int i) const;
		
	private:
		Segment3 mSegment;
		Rectangle3 mRectangle;
		
		// Information about the closest points.
		
		// closest0 = seg.origin + param*seg.direction
		mutable Real mSegmentParameter;
		
		// closest1 = rect.center + param0*rect.dir0 + param1*rect.dir1
		mutable Real mRectCoord[2];
	};
	
	using DistSegment3Rectangle3f = DistSegment3Rectangle3<float>;
	using DistSegment3Rectangle3d = DistSegment3Rectangle3<double>;
}

#endif // MATHEMATICS_DISTANCE_DIST_SEGMENT3_RECTANGLE3_H
