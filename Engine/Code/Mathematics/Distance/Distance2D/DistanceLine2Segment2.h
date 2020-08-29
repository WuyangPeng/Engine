// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/10 14:54)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_LINE2_SEGMENT2_H
#define MATHEMATICS_DISTANCE_DISTANCE_LINE2_SEGMENT2_H 

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects2D/Line2.h"
#include "Mathematics/Objects2D/Segment2.h"
#include "Mathematics/Distance/DistanceFwd.h"
#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Distance/DistanceBase.h"

namespace Mathematics
{
	template <typename Real>
	class DistanceLine2Segment2 : public DistanceBase<Real, Vector2D<Real>>
	{
	public:
		using ClassType = DistanceLine2Segment2<Real>;
		using Vector2D = Vector2D<Real>;
		using ParentType = DistanceBase<Real, Vector2D>;
		using Line2 = Line2<Real>;
		using Segment2 = Segment2<Real>;
		using Vector2DTools = Vector2DTools<Real>;
		using DistanceLine2Line2Tool = DistanceLine2Line2Tool<Real>;
		using DistanceResult = typename ParentType::DistanceResult;
		using Math = Math<Real>;

	public:
		DistanceLine2Segment2(const Line2& line, const Segment2& ray);
		virtual ~DistanceLine2Segment2();

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		const Line2 GetLine() const;
		const Segment2 GetSegment() const;

		// æ≤Ã¨æ‡¿Î≤È—Ø°£
		  const DistanceResult GetSquared() const override;

		// ∫Ø ˝º∆À„∂ØÃ¨æ‡¿Î≤È—Ø°£	
		  const DistanceResult GetSquared(Real t, const Vector2D& lhsVelocity, const Vector2D& rhsVelocity) const override;

	private:
		const DistanceResult GetSquaredWithClosestPoints(const DistanceLine2Line2Tool& tool, Real rhsExtent) const;
		const DistanceResult GetSquaredWithClosestPointsIsParallel(const DistanceLine2Line2Tool& tool) const;

	private:
		Line2 m_Line;
		Segment2 m_Segment;
	};

	using DistanceLine2Segment2f = DistanceLine2Segment2<float>;
	using DistanceLine2Segment2d = DistanceLine2Segment2<double>;
}

#endif // MATHEMATICS_DISTANCE_DISTANCE_LINE2_SEGMENT2_H


