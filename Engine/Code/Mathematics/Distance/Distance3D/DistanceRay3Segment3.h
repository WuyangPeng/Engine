// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/10 15:56)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_RAY3_SEGMENT3_H
#define MATHEMATICS_DISTANCE_DISTANCE_RAY3_SEGMENT3_H 

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Ray3.h"
#include "Mathematics/Objects3D/Segment3.h"
#include "Mathematics/Distance/DistanceBase.h"

namespace Mathematics
{
	template <typename Real>
	class Vector3DTools;

	template <typename Real>
	class DistanceLine3Line3Tool;

	template <typename Real>
	class DistanceRay3Segment3 : public DistanceBase<Real, Vector3D<Real> >
	{
	public:
		using ClassType = DistanceRay3Segment3<Real>;
		using Vector3D = Vector3D<Real>;
		using ParentType = DistanceBase<Real, Vector3D>;
		using Ray3 = Ray3<Real>;
		using Segment3 = Segment3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using DistanceLine3Line3Tool = DistanceLine3Line3Tool<Real>;
		using DistanceResult = typename ParentType::DistanceResult;
		using ParentType::GetZeroThreshold;
		using Math = Math<Real>;

	public:
		DistanceRay3Segment3(const Ray3& ray, const Segment3& segment);
		virtual ~DistanceRay3Segment3();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		const Ray3 GetRay() const;
		const Segment3 GetSegment() const;

		// æ≤Ã¨æ‡¿Î≤È—Ø°£
		virtual const DistanceResult GetSquared() const override;

		// ∫Ø ˝º∆À„∂ØÃ¨æ‡¿Î≤È—Ø°£	
		virtual const DistanceResult GetSquared(Real t, const Vector3D& lhsVelocity,const Vector3D& rhsVelocity) const override;

	private:
		const DistanceResult GetSquaredWithClosestPointsIsSegmentEndPoint(const DistanceLine3Line3Tool& tool, Real rhsExtent) const;
		const DistanceResult GetSquaredWithClosestPointsIsSegmentBeginPoint(const DistanceLine3Line3Tool& tool, Real rhsExtent) const;
		const DistanceResult GetSquaredWithClosestPointsIsRayOrigin(const DistanceLine3Line3Tool& tool, Real rhsExtent) const;

	private:
		Ray3 m_Ray;
		Segment3 m_Segment;
	};

	using DistanceRay3Segment3f = DistanceRay3Segment3<float>;
	using DistanceRay3Segment3d = DistanceRay3Segment3<double>;
}

#endif // MATHEMATICS_DISTANCE_DISTANCE_RAY3_SEGMENT3_H
