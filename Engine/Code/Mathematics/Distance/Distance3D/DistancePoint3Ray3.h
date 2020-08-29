// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/23 17:18)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT3_RAY3_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT3_RAY3_H 

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Ray3.h"
#include "Mathematics/Algebra/Vector3D.h"
#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Distance/DistanceBase.h"

namespace Mathematics
{ 
	template <typename Real>
	class DistancePoint3Ray3 : public DistanceBase<Real, Vector3D<Real> >
	{
	public:
		using ClassType = DistancePoint3Ray3<Real>;
		using Vector3D = Vector3D<Real>;
		using ParentType = DistanceBase<Real, Vector3D>;
		using Ray3 = Ray3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using DistanceResult = typename ParentType::DistanceResult; 

	public:
		DistancePoint3Ray3(const Vector3D& point, const Ray3& ray);
		virtual ~DistancePoint3Ray3();

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		const Vector3D GetPoint() const;
		const Ray3 GetRay() const;

		// æ≤Ã¨æ‡¿Î≤È—Ø°£
		 const DistanceResult GetSquared() const override;

		// ∫Ø ˝º∆À„∂ØÃ¨æ‡¿Î≤È—Ø°£	
		 const DistanceResult GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const override;

	private:
		Vector3D m_Point;
		Ray3 m_Ray;
	};

	using DistancePoint3Ray3f = DistancePoint3Ray3<float>;
	using DistancePoint3Ray3d = DistancePoint3Ray3<double>;
}

#endif // MATHEMATICS_DISTANCE_DISTANCE_POINT2_RAY2_H
