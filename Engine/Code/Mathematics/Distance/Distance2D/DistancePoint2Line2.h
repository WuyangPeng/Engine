// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/23 17:12)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT2_LINE2_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT2_LINE2_H 

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects2D/Line2.h"
#include "Mathematics/Algebra/Vector2D.h"
#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Distance/DistanceBase.h"

namespace Mathematics
{
	template <typename Real>
	class DistancePoint2Line2 : public DistanceBase<Real, Vector2D<Real>>
	{
	public:
		using ClassType = DistancePoint2Line2<Real>;
		using Vector2D = Vector2D<Real>;
		using ParentType = DistanceBase<Real, Vector2D>;
		using Line2 = Line2<Real>;
		using Vector2DTools = Vector2DTools<Real>;
		using DistanceResult = typename ParentType::DistanceResult; 

	public:
		DistancePoint2Line2(const Vector2D& point, const Line2& line);
		virtual ~DistancePoint2Line2();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		const Vector2D GetPoint() const;
		const Line2 GetLine() const;

		// æ≤Ã¨æ‡¿Î≤È—Ø°£
		virtual const DistanceResult GetSquared() const override;

		// ∫Ø ˝º∆À„∂ØÃ¨æ‡¿Î≤È—Ø°£	
		virtual const DistanceResult GetSquared(Real t, const Vector2D& lhsVelocity, const Vector2D& rhsVelocity) const override;

	private:
		Vector2D m_Point;
		Line2 m_Line;
	};

	using DistancePoint2Line2f = DistancePoint2Line2<float>;
	using DistancePoint2Line2d = DistancePoint2Line2<double>;
}

#endif // MATHEMATICS_DISTANCE_DISTANCE_POINT2_LINE2_H
