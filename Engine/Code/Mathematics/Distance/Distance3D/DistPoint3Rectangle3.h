// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/23 17:20)

#ifndef MATHEMATICS_DISTANCE_DIST_POINT3_RECTANGLE3_H
#define MATHEMATICS_DISTANCE_DIST_POINT3_RECTANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Rectangle3.h"
#include "Mathematics/Distance/DistanceBase.h"    

namespace Mathematics
{
	template <typename Real>
	class DistPoint3Rectangle3 : public DistanceBase<Real, Vector3D<Real> >
	{
	public:
		using ClassType = DistPoint3Rectangle3<Real>;
		using Vector3D = Vector3D<Real>;
		using ParentType = DistanceBase<Real, Vector3D>;
		using Rectangle3 = Rectangle3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using DistanceResult = typename ParentType::DistanceResult; 

	public:
		DistPoint3Rectangle3(const Vector3D& point, const Rectangle3& rectangle);

		// Object access.
		const Vector3D& GetPoint() const;
		const Rectangle3& GetRectangle() const;

		// Static distance queries.
		virtual const DistanceResult GetSquared() const override;

		// Function calculations for dynamic distance queries.
		virtual const DistanceResult GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const override;

		// Information about the closest rectangle point.
		Real GetRectangleCoordinate(int i) const;

	private:
		Vector3D mPoint;
		Rectangle3 mRectangle;

		// Information about the closest rectangle point.
		// closest1 = rect.center + param0*rect.dir0 + param1*rect.dir1
		mutable Real mRectCoord[2];
	};

	using DistPoint3Rectangle3f = DistPoint3Rectangle3<float>;
	using DistPoint3Rectangle3d = DistPoint3Rectangle3<double>;
}

#endif // MATHEMATICS_DISTANCE_DIST_POINT3_RECTANGLE3_H
