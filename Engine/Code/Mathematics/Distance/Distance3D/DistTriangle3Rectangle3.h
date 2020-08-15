// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/23 17:21)

#ifndef MATHEMATICS_DISTANCE_DIST_TRIANGLE3_RECTANGLE3_H
#define MATHEMATICS_DISTANCE_DIST_TRIANGLE3_RECTANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects3D/Rectangle3.h"  
#include "Mathematics/Objects3D/Triangle3.h"   

namespace Mathematics
{
	template <typename Real>
	class DistTriangle3Rectangle3 : public DistanceBase<Real, Vector3D<Real> >
	{
	public:
		using ClassType = DistTriangle3Rectangle3<Real>;
		using Vector3D = Vector3D<Real>;
		using ParentType = DistanceBase<Real, Vector3D>;
		using Rectangle3 = Rectangle3<Real>;
		using Triangle3 = Triangle3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using DistanceResult = typename ParentType::DistanceResult; 

	public:
		DistTriangle3Rectangle3(const Triangle3& triangle, const Rectangle3& rectangle);

		// Object access.
		const Triangle3& GetTriangle() const;
		const Rectangle3& GetRectangle() const;

		// Static distance queries.
		 const DistanceResult GetSquared() const override;

		// Function calculations for dynamic distance queries.
		 const DistanceResult GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const override;

	private:
		Triangle3 mTriangle;
		Rectangle3 mRectangle;
	};

	using DistTriangle3Rectangle3f = DistTriangle3Rectangle3<float>;
	using DistTriangle3Rectangle3d = DistTriangle3Rectangle3<double>;
}

#endif // MATHEMATICS_DISTANCE_DIST_TRIANGLE3_RECTANGLE3_H
