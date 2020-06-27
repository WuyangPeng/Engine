// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/23 17:17)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_LINE3_SEGMENT3_H
#define MATHEMATICS_DISTANCE_DISTANCE_LINE3_SEGMENT3_H 

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Line3.h"
#include "Mathematics/Objects3D/Segment3.h"
#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Algebra/AlgebraFwd.h"

namespace Mathematics
{
	template <typename Real>
	class DistanceLine3Segment3 : public DistanceBase<Real, Vector3D<Real> >
	{
	public:
		using ClassType = DistanceLine3Segment3<Real>;
		using Vector3D = Vector3D<Real>;
		using ParentType = DistanceBase<Real, Vector3D>;
		using Line3 = Line3<Real>;
		using Segment3 = Segment3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using DistanceLine3Line3Tool = DistanceLine3Line3Tool<Real>;
		using DistanceResult = typename ParentType::DistanceResult; 
		using Math = Math<Real>;

	public:
		DistanceLine3Segment3(const Line3& line, const Segment3& ray);
		virtual ~DistanceLine3Segment3();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		const Line3 GetLine() const;
		const Segment3 GetSegment() const;

		// æ≤Ã¨æ‡¿Î≤È—Ø°£
		virtual const DistanceResult GetSquared() const override;

		// ∫Ø ˝º∆À„∂ØÃ¨æ‡¿Î≤È—Ø°£	
		virtual const DistanceResult GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const override;

	private:
		const DistanceResult GetSquaredWithClosestPoints(const DistanceLine3Line3Tool& tool, Real rhsExtent) const;
		const DistanceResult GetSquaredWithClosestPointsIsParallel(const DistanceLine3Line3Tool& tool) const;

	private:
		Line3 m_Line;
		Segment3 m_Segment;
	};

	using DistanceLine3Segment3f = DistanceLine3Segment3<float>;
	using DistanceLine3Segment3d = DistanceLine3Segment3<double>;
}

#endif // MATHEMATICS_DISTANCE_DISTANCE_LINE3_SEGMENT3_H


