// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/23 17:12)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT2_SEGMENT2_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT2_SEGMENT2_H 

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector2D.h"
#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Objects2D/Segment2.h"
#include "Mathematics/Distance/DistanceBase.h"

namespace Mathematics
{
	template <typename Real>
	class DistancePoint2Segment2 : public DistanceBase<Real, Vector2D<Real> >
	{
	public:
		using ClassType = DistancePoint2Segment2<Real>;
		using Vector2D = Vector2D<Real>;
		using ParentType = DistanceBase<Real, Vector2D>;
		using Segment2 = Segment2<Real>;
		using Vector2DTools = Vector2DTools<Real>;
		using DistanceResult = typename ParentType::DistanceResult;

	public:
		DistancePoint2Segment2(const Vector2D& point, const Segment2& segment);
		virtual ~DistancePoint2Segment2();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		const Vector2D GetPoint() const;
		const Segment2 GetSegment() const;

		// æ≤Ã¨æ‡¿Î≤È—Ø°£
		  const DistanceResult GetSquared() const override;

		// ∫Ø ˝º∆À„∂ØÃ¨æ‡¿Î≤È—Ø°£	
		  const DistanceResult GetSquared(Real t, const Vector2D& lhsVelocity, const Vector2D& rhsVelocity) const override;

	private:
		Vector2D m_Point;
		Segment2 m_Segment;
	};

	using DistancePoint2Segment2f = DistancePoint2Segment2<float>;
	using DistancePoint2Segment2d = DistancePoint2Segment2<double>;
}

#endif // MATHEMATICS_DISTANCE_DISTANCE_POINT2_SEGMENT2_H
