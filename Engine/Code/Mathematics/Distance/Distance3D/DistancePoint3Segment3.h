// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/23 17:18)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT3_SEGMENT3_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT3_SEGMENT3_H 

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects3D/Segment3.h"
#include "Mathematics/Algebra/Vector3D.h"
#include "Mathematics/Algebra/AlgebraFwd.h"

namespace Mathematics
{
	template <typename Real>
	class DistancePoint3Segment3 : public DistanceBase<Real, Vector3D<Real> >
	{
	public:
		using ClassType = DistancePoint3Segment3<Real>;
		using Vector3D = Vector3D<Real>;
		using ParentType = DistanceBase<Real, Vector3D>;
		using Segment3 = Segment3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using DistanceResult = typename ParentType::DistanceResult;

	public:
		DistancePoint3Segment3(const Vector3D& point, const Segment3& segment);
		virtual ~DistancePoint3Segment3();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		const Vector3D GetPoint() const;
		const Segment3 GetSegment() const;

		// æ≤Ã¨æ‡¿Î≤È—Ø°£
		 const DistanceResult GetSquared() const override;

		// ∫Ø ˝º∆À„∂ØÃ¨æ‡¿Î≤È—Ø°£	
		 const DistanceResult GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const override;

	private:
		Vector3D m_Point;
		Segment3 m_Segment;
	};

	using DistancePoint3Segment3f = DistancePoint3Segment3<float>;
	using DistancePoint3Segment3d = DistancePoint3Segment3<double>;
}

#endif // MATHEMATICS_DISTANCE_DISTANCE_POINT3_SEGMENT3_H
