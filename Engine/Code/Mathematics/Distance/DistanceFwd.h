// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/23 17:07)

#ifndef MATHEMATICS_DISTANCE_FWD_H
#define MATHEMATICS_DISTANCE_FWD_H

namespace Mathematics
{
	template <typename Real, typename Vector>
	class DistanceResult;

	template <typename Real, typename Vector>
	class DistanceBase;

	// 2D
	template <typename Real>
	class DistanceLine2Line2;

	template <typename Real>
	class DistanceRay2Ray2;

	template <typename Real>
	class DistanceSegment2Segment2;

	template <typename Real>
	class DistanceLine2Ray2;

	template <typename Real>
	class DistanceLine2Segment2;

	template <typename Real>
	class DistanceRay2Segment2;

	template <typename Real>
	class DistancePoint2Line2;

	template <typename Real>
	class DistancePoint2Ray2;

	template <typename Real>
	class DistancePoint2Segment2;

	template <typename Real>
	class DistancePoint2Ellipse2;

	template <typename Real>
	class DistancePoint2Box2;

	template <typename Real>
	class DistancePoint2Hyperbola2;

	// 3D
	template <typename Real>
	class DistancePoint3Ellipsoid3;

	template <typename Real>
	class DistanceLine3Line3;

	template <typename Real>
	class DistanceRay3Ray3;

	template <typename Real>
	class DistanceSegment3Segment3;

	template <typename Real>
	class DistanceLine3Ray3;

	template <typename Real>
	class DistanceRay3Segment3;

	template <typename Real>
	class DistanceLine3Segment3;

	template <typename Real>
	class DistancePoint3Line3;

	template <typename Real>
	class DistancePoint3Ray3;

	template <typename Real>
	class DistancePoint3Box3;

	template <typename Real>
	class DistanceCircle3Circle3;
}

#endif // MATHEMATICS_DISTANCE_FWD_H