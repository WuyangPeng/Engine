// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/23 17:19)

#ifndef MATHEMATICS_DISTANCE_DIST_LINE3_BOX3_H
#define MATHEMATICS_DISTANCE_DIST_LINE3_BOX3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Box3.h"
#include "Mathematics/Objects3D/Line3.h"
#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Distance/DistanceBase.h"

namespace Mathematics
{
	template <typename Real>
	class DistLine3Box3 : public DistanceBase<Real, Vector3D<Real> >
	{
	public:
		using ClassType = DistLine3Box3<Real>;
		using Vector3D = Vector3D<Real>;
		using ParentType = DistanceBase<Real, Vector3D>;
		using Line3 = Line3<Real>;
		using Box3 = Box3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using DistanceResult = typename ParentType::DistanceResult; 

	public:
		DistLine3Box3(const Line3& line, const Box3& box);

		// Object access.
		const Line3 GetLine() const;
		const Box3 GetBox() const;

		// Static distance queries.
		virtual const DistanceResult GetSquared() const override;

		// Function calculations for dynamic distance queries.	 
		virtual const DistanceResult GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const override;

		// Access to the line parameter for the closest point.  This is used by
		// the ray-box and segment-box distance calculators.
		Real GetLineParameter() const;

	private:
		void Face(int i0, int i1, int i2, Vector3D& pnt, const Vector3D& dir, const Vector3D& PmE, Real& sqrDistance) const;

		void CaseNoZeros(Vector3D& pnt, const Vector3D& dir, Real& sqrDistance) const;

		void Case0(int i0, int i1, int i2, Vector3D& pnt, const Vector3D& dir, Real& sqrDistance) const;

		void Case00(int i0, int i1, int i2, Vector3D& pnt, const Vector3D& dir, Real& sqrDistance) const;

		void Case000(Vector3D& pnt, Real& sqrDistance) const;

	private:
		Line3 mLine;
		Box3 mBox;
		mutable Real mLineParameter;
	};

	using DistLine3Box3f = DistLine3Box3<float>;
	using DistLine3Box3d = DistLine3Box3<double>;
}

#endif // MATHEMATICS_DISTANCE_DIST_LINE3_BOX3_H
