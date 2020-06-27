// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/23 17:20)

#ifndef MATHEMATICS_DISTANCE_DIST_POINT3_TETRAHEDRON3_H
#define MATHEMATICS_DISTANCE_DIST_POINT3_TETRAHEDRON3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects3D/Tetrahedron3.h"    

namespace Mathematics
{
	template <typename Real>
	class DistPoint3Tetrahedron3 : public DistanceBase<Real, Vector3D<Real> >
	{
	public:
		using ClassType = DistPoint3Tetrahedron3<Real>;
		using Vector3D = Vector3D<Real>;
		using ParentType = DistanceBase<Real, Vector3D>;
		using Tetrahedron3 = Tetrahedron3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using DistanceResult = typename ParentType::DistanceResult; 

	public:
		DistPoint3Tetrahedron3(const Vector3D& point, const Tetrahedron3& tetrahedron);

		// Object access.
		const Vector3D& GetPoint() const;
		const Tetrahedron3& GetTetrahedron() const;

		// Static distance queries.
		virtual const DistanceResult GetSquared() const override;

		// Function calculations for dynamic distance queries.
		virtual const DistanceResult GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const override;

	private:
		Vector3D mPoint;
		Tetrahedron3 mTetrahedron;
	};

	using DistPoint3Tetrahedron3f = DistPoint3Tetrahedron3<float>;
	using DistPoint3Tetrahedron3d = DistPoint3Tetrahedron3<double>;
}

#endif // MATHEMATICS_DISTANCE_DIST_POINT3_TETRAHEDRON3_H
