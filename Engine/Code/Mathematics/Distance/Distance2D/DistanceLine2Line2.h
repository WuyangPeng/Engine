// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/10 14:51)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_LINE2_LINE2_H
#define MATHEMATICS_DISTANCE_DISTANCE_LINE2_LINE2_H 

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects2D/Line2.h"
#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Distance/DistanceBase.h"

namespace Mathematics
{
	template <typename Real>
	class DistanceLine2Line2 : public DistanceBase<Real, Vector2D<Real>>
	{
	public:
		using ClassType = DistanceLine2Line2<Real>;
		using Vector2D = Vector2D<Real>;
		using ParentType = DistanceBase<Real, Vector2D>;
		using Line2 = Line2<Real>;
		using Vector2DTools = Vector2DTools<Real>;
		using DistanceResult = typename ParentType::DistanceResult;

	public:
		DistanceLine2Line2(const Line2& lhsLine, const Line2& rhsLine);
		virtual ~DistanceLine2Line2();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		const Line2 GetLhsLine() const;
		const Line2 GetRhsLine() const;

		// æ≤Ã¨æ‡¿Î≤È—Ø°£
		virtual const DistanceResult GetSquared() const override;

		// ∫Ø ˝º∆À„∂ØÃ¨æ‡¿Î≤È—Ø°£	
		virtual const DistanceResult GetSquared(Real t, const Vector2D& lhsVelocity, const Vector2D& rhsVelocity) const override;

	private:
		Line2 m_LhsLine;
		Line2 m_RhsLine;
	};

	using DistanceLine2Line2f = DistanceLine2Line2<float>;
	using DistanceLine2Line2d = DistanceLine2Line2<double>;
}

#endif // MATHEMATICS_DISTANCE_DISTANCE_LINE2_LINE2_H
