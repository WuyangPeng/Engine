// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/10 14:57)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT2_BOX2_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT2_BOX2_H 

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects2D/Box2.h" 
#include "Mathematics/Algebra/AlgebraFwd.h"

namespace Mathematics
{
	template <typename Real>
	class DistancePoint2Box2 : public DistanceBase<Real, Vector2D<Real> >
	{
	public:
		using ClassType = DistancePoint2Box2<Real>;
		using Vector2D = Vector2D<Real>;
		using ParentType = DistanceBase<Real, Vector2D>;
		using Box2 = Box2<Real>;
		using Vector2DTools = Vector2DTools<Real>;
		using DistanceResult = typename ParentType::DistanceResult; 

	public:
		DistancePoint2Box2(const Vector2D& point, const Box2& ellipse);
		virtual ~DistancePoint2Box2();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		const Vector2D GetPoint() const;
		const Box2 GetBox() const;

		// æ≤Ã¨æ‡¿Î≤È—Ø°£		 
		virtual const DistanceResult GetSquared() const override;

		// ∫Ø ˝º∆À„∂ØÃ¨æ‡¿Î≤È—Ø°£		
		virtual const DistanceResult GetSquared(Real t, const Vector2D& lhsVelocity, const Vector2D& rhsVelocity) const override;

	private:
		Vector2D m_Point;
		Box2 m_Box;
	};

	using DistancePoint2Box2f = DistancePoint2Box2<float>;
	using DistancePoint2Box2d = DistancePoint2Box2<double>;
}

#endif // MATHEMATICS_DISTANCE_DISTANCE_POINT2_BOX2_H
