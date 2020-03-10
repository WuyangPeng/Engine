// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/10 15:26)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_LINE3_RAY3_H
#define MATHEMATICS_DISTANCE_DISTANCE_LINE3_RAY3_H 

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Ray3.h"
#include "Mathematics/Objects3D/Line3.h"
#include "Mathematics/Distance/DistanceBase.h"

namespace Mathematics
{
	template <typename Real>
	class Vector3DTools;

	template <typename Real>
	class DistanceLine3Line3Tool;

	template <typename Real>
	class DistanceLine3Ray3 : public DistanceBase<Real, Vector3D<Real> >
	{
	public:
		using ClassType = DistanceLine3Ray3<Real>;
		using Vector3D = Vector3D<Real>;
		using ParentType = DistanceBase<Real, Vector3D>;
		using Line3 = Line3<Real>;
		using Ray3 = Ray3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using DistanceLine3Line3Tool = DistanceLine3Line3Tool<Real>;
		using DistanceResult = typename ParentType::DistanceResult;
		using ParentType::GetZeroThreshold;
		using Math = Math<Real>;

	public:
		DistanceLine3Ray3(const Line3& line, const Ray3& ray);
		virtual ~DistanceLine3Ray3();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		const Line3 GetLine() const;
		const Ray3 GetRay() const;

		// æ≤Ã¨æ‡¿Î≤È—Ø°£
		virtual const DistanceResult GetSquared() const override;

		// ∫Ø ˝º∆À„∂ØÃ¨æ‡¿Î≤È—Ø°£	
		virtual const DistanceResult GetSquared(Real t, const Vector3D& lhsVelocity,const Vector3D& rhsVelocity) const override;

	private:
		const DistanceResult GetSquaredWithClosestPoints(const DistanceLine3Line3Tool& tool) const;

	private:
		Line3 m_Line;
		Ray3 m_Ray;
	};

	using DistanceLine3Ray3f = DistanceLine3Ray3<float>;
	using DistanceLine3Ray3d = DistanceLine3Ray3<double>;
}

#endif // MATHEMATICS_DISTANCE_DISTANCE_LINE3_RAY3_H

 
