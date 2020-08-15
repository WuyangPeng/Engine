// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/23 17:18)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_RAY3_RAY3_H
#define MATHEMATICS_DISTANCE_DISTANCE_RAY3_RAY3_H 

#include "Mathematics/MathematicsDll.h"
#include "Mathematics/Objects3D/Ray3.h"
#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Distance/Distance3D/Detail/DistanceLine3Line3Tool.h"

namespace Mathematics
{ 
	template <typename Real>
	class DistanceRay3Ray3 : public DistanceBase<Real, Vector3D<Real> >
	{
	public:
		using ClassType = DistanceRay3Ray3<Real>;
		using Vector3D = Vector3D<Real>;
		using ParentType = DistanceBase<Real, Vector3D>;
		using Ray3 = Ray3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using DistanceLine3Line3Tool = DistanceLine3Line3Tool<Real>;
		using DistanceResult = typename ParentType::DistanceResult;
		using Math = Math<Real>;

	public:
		DistanceRay3Ray3(const Ray3& lhsRay, const Ray3& rhsRay);
		virtual ~DistanceRay3Ray3();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		const Ray3 GetLhsRay() const;
		const Ray3 GetRhsRay() const;

		// æ≤Ã¨æ‡¿Î≤È—Ø°£
		 const DistanceResult GetSquared() const override;

		// ∫Ø ˝º∆À„∂ØÃ¨æ‡¿Î≤È—Ø°£	
		 const DistanceResult GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const override;

	private:
		const DistanceResult GetSquaredWithClosestPointsIsOrigin(const DistanceLine3Line3Tool& tool) const;
		const DistanceResult GetSquaredWithClosestPointsIsLhs(const DistanceLine3Line3Tool& tool) const;
		const DistanceResult GetSquaredWithClosestPointsIsRhs(const DistanceLine3Line3Tool& tool) const;

	private:
		Ray3 m_LhsRay;
		Ray3 m_RhsRay;
	};

	using DistanceRay3Ray3f = DistanceRay3Ray3<float>;
	using DistanceRay3Ray3d = DistanceRay3Ray3<double>;
}

#endif // MATHEMATICS_DISTANCE_DISTANCE_RAY3_RAY3_H


