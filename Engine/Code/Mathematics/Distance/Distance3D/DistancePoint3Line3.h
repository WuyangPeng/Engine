// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/10 15:37)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT3_LINE3_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT3_LINE3_H 

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects3D/Line3.h"
#include "Mathematics/Algebra/Vector3D.h"

namespace Mathematics
{
	template <typename Real>
	class Vector3DTools;

	template <typename Real>
	class DistancePoint3Line3 : public DistanceBase<Real, Vector3D<Real> >
	{
	public:
		using ClassType = DistancePoint3Line3<Real>;
		using Vector3D = Vector3D<Real>;
		using ParentType = DistanceBase<Real, Vector3D>;
		using Line3 = Line3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using DistanceResult = typename ParentType::DistanceResult;
		using ParentType::GetZeroThreshold;

	public:
		DistancePoint3Line3(const Vector3D& point, const Line3& line);
		virtual ~DistancePoint3Line3();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		const Vector3D GetPoint() const;
		const Line3 GetLine() const;

		// æ≤Ã¨æ‡¿Î≤È—Ø°£
		virtual const DistanceResult GetSquared() const override;

		// ∫Ø ˝º∆À„∂ØÃ¨æ‡¿Î≤È—Ø°£	
		virtual const DistanceResult GetSquared(Real t, const Vector3D& lhsVelocity,  const Vector3D& rhsVelocity) const override;

	private:
		Vector3D m_Point;
		Line3 m_Line;
	};

	using DistancePoint3Line3f = DistancePoint3Line3<float>;
	using DistancePoint3Line3d = DistancePoint3Line3<double>;
}

#endif // MATHEMATICS_DISTANCE_DISTANCE_POINT3_LINE3_H
 
