// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/10 14:58)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT2_ELLIPSE2_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT2_ELLIPSE2_H 

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects2D/Ellipse2.h" 
#include "Mathematics/Algebra/AlgebraFwd.h"

namespace Mathematics
{
	template <typename Real>
	class DistancePoint2Ellipse2 : public DistanceBase<Real, Vector2D<Real> >
	{
	public:
		using ClassType = DistancePoint2Ellipse2<Real>;
		using Vector2D = Vector2D<Real>;
		using ParentType = DistanceBase<Real, Vector2D>;
		using Ellipse2 = Ellipse2<Real>;
		using Vector2DTools = Vector2DTools<Real>;
		using DistanceResult = typename ParentType::DistanceResult;
		using ParentType::GetZeroThreshold;

	public:
		DistancePoint2Ellipse2(const Vector2D& point, const Ellipse2& ellipse);
		virtual ~DistancePoint2Ellipse2();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		const Vector2D GetPoint() const;
		const Ellipse2 GetEllipse() const;

		// æ≤Ã¨æ‡¿Î≤È—Ø°£		 
		virtual const DistanceResult GetSquared() const override;

		// ∫Ø ˝º∆À„∂ØÃ¨æ‡¿Î≤È—Ø°£		
		virtual const DistanceResult GetSquared(Real t, const Vector2D& lhsVelocity, const Vector2D& rhsVelocity) const override;

	private:
		Vector2D m_Point;
		Ellipse2 m_Ellipse;
	};

	using DistancePoint2Ellipse2f = DistancePoint2Ellipse2<float>;
	using DistancePoint2Ellipse2d = DistancePoint2Ellipse2<double>;
}

#endif // MATHEMATICS_DISTANCE_DISTANCE_POINT2_ELLIPSE2_H
