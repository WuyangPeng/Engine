// Copyright (c) 2010-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/24 14:49)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE3_ELLIPSOID3_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE3_ELLIPSOID3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h" 
#include "Mathematics/Objects3D/Line3.h"  
#include "Mathematics/Objects3D/Ellipsoid3.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticFindIntersectorLine3Ellipsoid3 : public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticFindIntersectorLine3Ellipsoid3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Line3 = Line3<Real>;
		using Ellipsoid3 = Ellipsoid3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = typename ParentType::Math;

	public:
		StaticFindIntersectorLine3Ellipsoid3(const Line3& line, const Ellipsoid3& ellipsoid);

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		 [[nodiscard]] const Line3 GetLine() const;
                [[nodiscard]] const Ellipsoid3 GetEllipsoid() const;

		// The intersection set.
                [[nodiscard]] int GetQuantity() const;
                [[nodiscard]] const Vector3D GetPoint(int index) const;

		// Small thresholds are used for testing the discriminant of the quadratic
		// equation related to the computations: Q(t) = a2*t^2 + 2*a1*t + a0.  The
		// discriminant is D = a1*a1 - a0*a2.  Q(t) has no real-valued roots when
		// D < 0, one real-valued root when D = 0, or two real-valued roots when
		// D > 0.  The code logic involves user-defined thresholds:
		//   if (D < negThreshold) { no roots (no intersections) }
		//   else if (D > posThreshold) { two roots (two intersections) }
		//   else { one root (one intersection) }
		// The default values for the thresholds are zero, but you may set them
		// to be nonzero (negThreshold <= 0 and posThreshold >= 0).  Previously,
		// the negative threshold was hard-coded as zero.  The positive threshold
		// was hard-coded to Math<Real>::GetZeroTolerance(), which is not suitable for
		// some data sets (i.e. when ellipsoid extents are quite large).  The
		// default is now zero, so if your application relied on the old behavior,
		// you must modify this value.
		void SetNegativeThreshold(Real negThreshold);
                [[nodiscard]] Real GetNegativeThreshold() const;
		void SetPositiveThreshold(Real posThreshold);
                [[nodiscard]] Real GetPositiveThreshold() const;

	private:
		// Static intersection queries.		
		void Find();

		// The objects to intersect.
		Line3 mLine;
		Ellipsoid3 mEllipsoid;

		// Information about the intersection set.
		int m_Quantity;
		Vector3D m_Point[2];

		// For testing the discriminant.  The default values are zero.  You may
		// set the negative threshold to a (small) negative number and the
		// positive threshold to a  (small) positive number.
		Real mNegativeThreshold;
		Real mPositiveThreshold;
	};

	using FloatStaticFindIntersectorLine3Ellipsoid3 = StaticFindIntersectorLine3Ellipsoid3<float>;
	using DoubleStaticFindIntersectorLine3Ellipsoid3 = StaticFindIntersectorLine3Ellipsoid3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE3_ELLIPSOID3_H
