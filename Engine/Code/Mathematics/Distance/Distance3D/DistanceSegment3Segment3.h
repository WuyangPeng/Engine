// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/23 17:19)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_SEGMENT3_SEGMENT3_H
#define MATHEMATICS_DISTANCE_DISTANCE_SEGMENT3_SEGMENT3_H 

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Segment3.h"
#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Distance/DistanceBase.h"

namespace Mathematics
{
	template <typename Real>
	class DistanceSegment3Segment3 : public DistanceBase<Real, Vector3D<Real> >
	{
	public:
		using ClassType = DistanceSegment3Segment3<Real>;
		using Vector3D = Vector3D<Real>;
		using ParentType = DistanceBase<Real, Vector3D>;
		using Segment3 = Segment3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using DistanceLine3Line3Tool = DistanceLine3Line3Tool<Real>;
		using DistanceResult = typename ParentType::DistanceResult;
		using Math = Math<Real>;

	public:
		DistanceSegment3Segment3(const Segment3& lhsSegment, const Segment3& rhsSegment);
		virtual ~DistanceSegment3Segment3();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		const Segment3 GetLhsSegment() const;
		const Segment3 GetRhsSegment() const;

		// æ≤Ã¨æ‡¿Î≤È—Ø°£
		virtual const DistanceResult GetSquared() const override;

		// ∫Ø ˝º∆À„∂ØÃ¨æ‡¿Î≤È—Ø°£	
		virtual const DistanceResult GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const override;

	private:
		const DistanceResult GetSquaredWithClosestPointsIsLhsSide(const DistanceLine3Line3Tool& tool, Real lhsExtent, Real rhsExtent) const;
		const DistanceResult GetSquaredWithClosestPointsIsRhsSide(const DistanceLine3Line3Tool& tool, Real lhsExtent, Real rhsExtent) const;
		const DistanceResult GetSquaredWithClosestPointsIsLhsCorner(const DistanceLine3Line3Tool& tool, Real lhsExtent, Real rhsExtent) const;
		const DistanceResult GetSquaredWithClosestPointsIsRhsCorner(const DistanceLine3Line3Tool& tool, Real lhsExtent, Real rhsExtent) const;

	private:
		Segment3 m_LhsSegment;
		Segment3 m_RhsSegment;
	};

	using DistanceSegment3Segment3f = DistanceSegment3Segment3<float>;
	using DistanceSegment3Segment3d = DistanceSegment3Segment3<double>;
}

#endif // MATHEMATICS_DISTANCE_DISTANCE_SEGMENT3_SEGMENT3_H
