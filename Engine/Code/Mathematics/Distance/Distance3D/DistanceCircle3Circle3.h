// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/23 17:17)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_CIRCLE3_CIRCLE3_H
#define MATHEMATICS_DISTANCE_DISTANCE_CIRCLE3_CIRCLE3_H 

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Circle3.h"
#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Distance/DistanceBase.h"

namespace Mathematics
{
	template <typename Real>
	class DistanceCircle3Circle3 : public DistanceBase<Real, Vector3D<Real> >
	{
	public:
		using ClassType = DistanceCircle3Circle3<Real>;
		using Vector3D = Vector3D<Real>;
		using ParentType = DistanceBase<Real, Vector3D>;
		using Circle3 = Circle3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using DistanceResult = typename ParentType::DistanceResult; 
		using Math = Math<Real>;

	public:
		DistanceCircle3Circle3(const Circle3& lhsCircle, const Circle3& rhsCircle);
		virtual ~DistanceCircle3Circle3();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		const Circle3 GetLhsCircle() const;
		const Circle3 GetRhsCircle() const;

		// æ≤Ã¨æ‡¿Î≤È—Ø°£
		 const DistanceResult GetSquared() const override;

		// ∫Ø ˝º∆À„∂ØÃ¨æ‡¿Î≤È—Ø°£	
		 const DistanceResult GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const override;

	private:
		Circle3 m_LhsCircle;
		Circle3 m_RhsCircle;
	};

	using DistanceCircle3Circle3f = DistanceCircle3Circle3<float>;
	using DistanceCircle3Circle3d = DistanceCircle3Circle3<double>;
}

#endif // MATHEMATICS_DISTANCE_DISTANCE_CIRCLE3_CIRCLE3_H
