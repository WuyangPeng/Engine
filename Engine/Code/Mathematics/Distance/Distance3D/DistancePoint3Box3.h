// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/23 17:17)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT3_BOX3_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT3_BOX3_H 

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Box3.h"
#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Distance/DistanceBase.h"

namespace Mathematics
{
	template <typename Real>
	class DistancePoint3Box3 : public DistanceBase<Real, Vector3D<Real> >
	{
	public:
		using ClassType = DistancePoint3Box3<Real>;
		using Vector3D = Vector3D<Real>;
		using ParentType = DistanceBase<Real, Vector3D>;
		using Box3 = Box3<Real>;
		using Math = Math<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using DistanceResult = typename ParentType::DistanceResult;

	public:
		DistancePoint3Box3(const Vector3D& point, const Box3& ellipse);
		virtual ~DistancePoint3Box3();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		const Vector3D GetPoint() const;
		const Box3 GetBox() const;

		// æ≤Ã¨æ‡¿Î≤È—Ø°£		 
		 const DistanceResult GetSquared() const override;

		// ∫Ø ˝º∆À„∂ØÃ¨æ‡¿Î≤È—Ø°£		
		 const DistanceResult GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const override;

	private:
		Vector3D m_Point;
		Box3 m_Box;
	};

	using DistancePoint3Box3f = DistancePoint3Box3<float>;
	using DistancePoint3Box3d = DistancePoint3Box3<double>;
}

#endif // MATHEMATICS_DISTANCE_DISTANCE_POINT3_BOX3_H

