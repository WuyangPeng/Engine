// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/23 17:19)

#ifndef MATHEMATICS_DISTANCE_DIST_LINE3_TRIANGLE3_H
#define MATHEMATICS_DISTANCE_DIST_LINE3_TRIANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Line3.h"
#include "Mathematics/Objects3D/Triangle3.h"  
#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Algebra/AlgebraFwd.h"

namespace Mathematics
{
	template <typename Real>
	class DistLine3Triangle3 : public DistanceBase<Real, Vector3D<Real> >
	{
	public:
		using ClassType = DistLine3Triangle3<Real>;
		using Vector3D = Vector3D<Real>;
		using ParentType = DistanceBase<Real, Vector3D>;
		using Line3 = Line3<Real>;
		using Triangle3 = Triangle3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using DistanceResult = typename ParentType::DistanceResult; 

	public:
		DistLine3Triangle3(const Line3& line, const Triangle3& triangle);

		// Object access.
		const Line3& GetLine() const;
		const Triangle3& GetTriangle() const;

		// Static distance queries.
		virtual const DistanceResult GetSquared() const override;

		// Function calculations for dynamic distance queries.
		virtual const DistanceResult GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const override;

		// Information about the closest points.
		Real GetLineParameter() const;
		Real GetTriangleBary(int i) const;

	private:
		Line3 mLine;
		Triangle3 mTriangle;

		// Information about the closest points.

		// closest0 = line.origin + param*line.direction
		mutable Real mLineParameter;

		// closest1 = sum_{i=0}^2 bary[i]*tri.vertex[i]
		mutable Real mTriangleBary[3];
	};

	using DistLine3Triangle3f = DistLine3Triangle3<float>;
	using DistLine3Triangle3d = DistLine3Triangle3<double>;
}

#endif // MATHEMATICS_DISTANCE_DIST_LINE3_TRIANGLE3_H
