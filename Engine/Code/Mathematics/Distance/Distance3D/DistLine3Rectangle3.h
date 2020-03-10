// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/10 16:07)

#ifndef MATHEMATICS_DISTANCE_DIST_LINE3_RECTANGLE3_H
#define MATHEMATICS_DISTANCE_DIST_LINE3_RECTANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects3D/Line3.h"
#include "Mathematics/Objects3D/Rectangle3.h" 

namespace Mathematics
{
	template <typename Real>
	class DistLine3Rectangle3 : public DistanceBase<Real,Vector3D<Real> >
	{
	public:
		using ClassType = DistLine3Rectangle3<Real>;
		using Vector3D = Vector3D<Real>;
		using ParentType = DistanceBase<Real, Vector3D>;
		using Line3 = Line3<Real>;
		using Rectangle3 = Rectangle3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using DistanceResult = typename ParentType::DistanceResult;
		using ParentType::GetZeroThreshold;

	public:
		DistLine3Rectangle3 (const Line3& line,const Rectangle3& rectangle);
		
		// Object access.
		const Line3& GetLine () const;
		const Rectangle3& GetRectangle () const;
		
		// Static distance queries.
		virtual const DistanceResult GetSquared() const override;
		
		// Function calculations for dynamic distance queries.
		virtual const DistanceResult GetSquared(Real t, const Vector3D& lhsVelocity,const Vector3D& rhsVelocity) const override;
		
		// Information about the closest points.
		Real GetLineParameter () const;
		Real GetRectangleCoordinate (int i) const;
		
	private:
		Line3 mLine;
		Rectangle3 mRectangle;
		
		// Information about the closest points.
		
		// closest0 = line.origin + param*line.direction
		mutable Real mLineParameter;
		
		// closest1 = rect.center + param0*rect.dir0 + param1*rect.dir1
		mutable Real mRectCoord[2];
	};
	
	using DistLine3Rectangle3f = DistLine3Rectangle3<float>;
	using DistLine3Rectangle3d = DistLine3Rectangle3<double>;
}

#endif // MATHEMATICS_DISTANCE_DIST_LINE3_RECTANGLE3_H
