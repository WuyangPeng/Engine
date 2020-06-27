// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/23 17:13)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_SEGMENT2_SEGMENT2_H
#define MATHEMATICS_DISTANCE_DISTANCE_SEGMENT2_SEGMENT2_H 

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Distance/DistanceFwd.h"
#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects2D/Segment2.h"
#include "Mathematics/Algebra/AlgebraFwd.h"

namespace Mathematics
{
	template <typename Real>
	class DistanceSegment2Segment2 : public DistanceBase<Real, Vector2D<Real> >
	{
	public:
		using ClassType = DistanceSegment2Segment2<Real>;
		using Vector2D = Vector2D<Real>;
		using ParentType = DistanceBase<Real, Vector2D>;
		using Segment2 = Segment2<Real>;
		using Vector2DTools = Vector2DTools<Real>;
		using DistanceLine2Line2Tool = DistanceLine2Line2Tool<Real>;
		using DistanceResult = typename ParentType::DistanceResult;
		using Math = Math<Real>;

	public:
		DistanceSegment2Segment2(const Segment2& lhsSegment, const Segment2& rhsSegment);
		virtual ~DistanceSegment2Segment2();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		const Segment2 GetLhsSegment() const;
		const Segment2 GetRhsSegment() const;

		// æ≤Ã¨æ‡¿Î≤È—Ø°£
		virtual const DistanceResult GetSquared() const override;

		// ∫Ø ˝º∆À„∂ØÃ¨æ‡¿Î≤È—Ø°£	
		virtual const DistanceResult GetSquared(Real t, const Vector2D& lhsVelocity, const Vector2D& rhsVelocity) const override;

	private:
		const DistanceResult GetSquaredWithClosestPointsIsLhsSide(const DistanceLine2Line2Tool& tool, Real lhsExtent, Real rhsExtent) const;
		const DistanceResult GetSquaredWithClosestPointsIsRhsSide(const DistanceLine2Line2Tool& tool, Real lhsExtent, Real rhsExtent) const;
		const DistanceResult GetSquaredWithClosestPointsIsLhsCorner(const DistanceLine2Line2Tool& tool, Real lhsExtent, Real rhsExtent) const;
		const DistanceResult GetSquaredWithClosestPointsIsRhsCorner(const DistanceLine2Line2Tool& tool, Real lhsExtent, Real rhsExtent) const;

	private:
		Segment2 m_LhsSegment;
		Segment2 m_RhsSegment;
	};

	using DistanceSegment2Segment2f = DistanceSegment2Segment2<float>;
	using DistanceSegment2Segment2d = DistanceSegment2Segment2<double>;
}

#endif // MATHEMATICS_DISTANCE_DISTANCE_SEGMENT2_SEGMENT2_H
