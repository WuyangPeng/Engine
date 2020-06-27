// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/23 17:09)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_LINE2_LINE2_TOOL_H
#define MATHEMATICS_DISTANCE_DISTANCE_LINE2_LINE2_TOOL_H 

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector2D.h"
#include "Mathematics/Algebra/AlgebraFwd.h"

namespace Mathematics
{
	template <typename Real>
	class DistanceLine2Line2Tool
	{
	public:
		using ClassType = DistanceLine2Line2Tool<Real>;
		using Vector2D = Vector2D<Real>;
		using Vector2DTools = Vector2DTools<Real>;
		using Math = Math<Real>;

	public:
		DistanceLine2Line2Tool(const Vector2D& lhsOrigin, const Vector2D& lhsDirection, const Vector2D& rhsOrigin, const Vector2D& rhsDirection);

		CLASS_INVARIANT_DECLARE;

		Real GetDet() const;
		Real GetLhsT() const;
		Real GetRhsT() const;
		Real GetLhsT(Real extent) const;
		Real GetRhsT(Real extent) const;
		Real GetOriginDifferenceDotLhsDirection() const;
		Real GetOriginDifferenceDotRhsDirection() const;
		Real GetOriginDifferenceSquaredLength() const;
		Real GetDirectionDot() const;
		Real GetSquaredDistanceWithParallel() const;
		Real GetSquaredDistanceWithLhs() const;
		Real GetSquaredDistanceWithRhs() const;
		Real GetOriginDifferenceDotDirectionAverage() const;

	private:
		Vector2D m_OriginDifference;
		Real m_DirectionDot;
		Real m_OriginDifferenceDotLhsDirection;
		Real m_OriginDifferenceDotRhsDirection;
		Real m_OriginDifferenceSquaredLength;
		Real m_Det;
	};
}

#endif // MATHEMATICS_DISTANCE_DISTANCE_LINE2_LINE2_TOOL_H
