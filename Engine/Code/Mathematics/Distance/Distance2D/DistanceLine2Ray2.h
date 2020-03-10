// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/10 14:52)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_LINE2_RAY2_H
#define MATHEMATICS_DISTANCE_DISTANCE_LINE2_RAY2_H 

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects2D/Line2.h"
#include "Mathematics/Objects2D/Ray2.h"

namespace Mathematics
{
	template <typename Real>
	class Vector2DTools;

	template <typename Real>
	class DistanceLine2Line2Tool;

	template <typename Real>
	class DistanceLine2Ray2 : public DistanceBase<Real, Vector2D<Real>>
	{
	public:
		using ClassType = DistanceLine2Ray2<Real>;
		using Vector2D = Vector2D<Real>;
		using ParentType = DistanceBase<Real, Vector2D>;
		using Line2 = Line2<Real>;
		using Ray2 = Ray2<Real>;
		using Vector2DTools = Vector2DTools<Real>;
		using DistanceLine2Line2Tool = DistanceLine2Line2Tool<Real>;
		using DistanceResult = typename ParentType::DistanceResult; 

	public:
		DistanceLine2Ray2(const Line2& line, const Ray2& ray);
		virtual ~DistanceLine2Ray2();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		const Line2 GetLine() const;
		const Ray2 GetRay() const;

		// æ≤Ã¨æ‡¿Î≤È—Ø°£
		virtual const DistanceResult GetSquared() const override;

		// ∫Ø ˝º∆À„∂ØÃ¨æ‡¿Î≤È—Ø°£	
		virtual const DistanceResult GetSquared(Real t, const Vector2D& lhsVelocity,const Vector2D& rhsVelocity) const override;

	private:
		const DistanceResult GetSquaredWithClosestPoints(const DistanceLine2Line2Tool& tool) const;

	private:
		Line2 m_Line;
		Ray2 m_Ray;
	};

	using DistanceLine2Ray2f = DistanceLine2Ray2<float>;
	using DistanceLine2Ray2d = DistanceLine2Ray2<double>;
}

#endif // MATHEMATICS_DISTANCE_DISTANCE_LINE2_RAY2_H
