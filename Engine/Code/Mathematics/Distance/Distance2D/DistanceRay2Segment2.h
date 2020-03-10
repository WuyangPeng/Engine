// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/10 15:06)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_RAY2_SEGMENT2_H
#define MATHEMATICS_DISTANCE_DISTANCE_RAY2_SEGMENT2_H 

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects2D/Ray2.h"
#include "Mathematics/Objects2D/Segment2.h"
#include "Mathematics/Distance/DistanceBase.h"

namespace Mathematics
{
	template <typename Real>
	class Vector2DTools;

	template <typename Real>
	class DistanceLine2Line2Tool;

	template <typename Real>
	class DistanceRay2Segment2 : public DistanceBase<Real, Vector2D<Real>>
	{
	public:
		using ClassType = DistanceRay2Segment2<Real>;
		using Vector2D = Vector2D<Real>;
		using ParentType = DistanceBase<Real, Vector2D>;
		using Ray2 = Ray2<Real>;
		using Segment2 = Segment2<Real>;
		using Vector2DTools = Vector2DTools<Real>;
		using DistanceLine2Line2Tool = DistanceLine2Line2Tool<Real>;
		using DistanceResult = typename ParentType::DistanceResult;
		using ParentType::GetZeroThreshold;
		using Math = Math<Real>;

	public:
		DistanceRay2Segment2(const Ray2& ray, const Segment2& segment);
		virtual ~DistanceRay2Segment2();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		const Ray2 GetRay() const;
		const Segment2 GetSegment() const;

		// æ≤Ã¨æ‡¿Î≤È—Ø°£
		virtual const DistanceResult GetSquared() const override;

		// ∫Ø ˝º∆À„∂ØÃ¨æ‡¿Î≤È—Ø°£	
		virtual const DistanceResult GetSquared(Real t, const Vector2D& lhsVelocity,const Vector2D& rhsVelocity) const override;

	private:
		const DistanceResult GetSquaredWithClosestPointsIsSegmentEndPoint(const DistanceLine2Line2Tool& tool, Real rhsExtent) const;
		const DistanceResult GetSquaredWithClosestPointsIsSegmentBeginPoint(const DistanceLine2Line2Tool& tool, Real rhsExtent) const;
		const DistanceResult GetSquaredWithClosestPointsIsRayOrigin(const DistanceLine2Line2Tool& tool, Real rhsExtent) const;
	 
	private:
		Ray2 m_Ray;
		Segment2 m_Segment;
	};

	using DistanceRay2Segment2f = DistanceRay2Segment2<float>;
	using DistanceRay2Segment2d = DistanceRay2Segment2<double>;
}

#endif // MATHEMATICS_DISTANCE_DISTANCE_RAY2_SEGMENT2_H
