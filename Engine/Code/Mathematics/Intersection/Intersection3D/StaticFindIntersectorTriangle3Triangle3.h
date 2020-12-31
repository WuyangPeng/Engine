// Copyright (c) 2010-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/24 14:52)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRIANGLE3_TRIANGLE3_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRIANGLE3_TRIANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Line3.h"
#include "Mathematics/Objects3D/Plane3.h"
#include "Mathematics/Objects3D/Triangle3.h"
#include "Mathematics/Intersection/StaticIntersector.h"

namespace Mathematics
{
	template <typename Real>
	class StaticFindIntersectorTriangle3Triangle3 : public StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticFindIntersectorTriangle3Triangle3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Line3 = Line3<Real>;
		using Plane3 = Plane3<Real>;
		using Triangle3 = Triangle3<Real>;
		using Vector3DTools = Vector3DTools<Real>;
		using Math = typename ParentType::Math;

	public:
		StaticFindIntersectorTriangle3Triangle3(const Triangle3& lhsTriangle, const Triangle3& rhsTriangle, bool reportCoplanarIntersections = true, const Real epsilon = Math::GetZeroTolerance());
		virtual ~StaticFindIntersectorTriangle3Triangle3();

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		 [[nodiscard]] const Triangle3 GetLhsTriangle() const;
                [[nodiscard]] const Triangle3 GetRhsTriangle() const;

		// The intersection set.
                [[nodiscard]] int GetQuantity() const;
                [[nodiscard]] const Vector3D GetPoint(int index) const;

	private:
		void Find();

		static void ProjectOntoAxis(const Triangle3& triangle, const Vector3D& axis, Real& fmin, Real& fmax);

		static void GetInterval(const Triangle3& triangle, const Line3& line, const Real distance[3], const int sign[3], Real param[2]);

		 [[nodiscard]] bool ContainsPoint(const Triangle3& triangle, const Plane3& plane, const Vector3D& point);

		 [[nodiscard]] bool IntersectsSegment(const Plane3& plane, const Triangle3& triangle, const Vector3D& end0, const Vector3D& end1);

		 [[nodiscard]] bool GetCoplanarIntersection(const Plane3& plane, const Triangle3& tri0, const Triangle3& tri1);

		 [[nodiscard]] static bool TestOverlap(Real tmax, Real speed, Real umin, Real umax, Real vmin, Real vmax, Real& tfirst, Real& tlast);

		 [[nodiscard]] bool TestOverlap(const Vector3D& axis, Real tmax, const Vector3D& velocity, Real& tfirst, Real& tlast);

		enum ProjectionMap
		{
			M2, M11,                // lines
			M3, M21, M12, M111,     // triangles
			M44, M2_2, M1_1         // boxes
		};

		enum ContactSide
		{
			CS_LEFT,
			CS_RIGHT,
			CS_NONE
		};

		class Configuration
		{
		public:
			ProjectionMap mMap;  // how vertices map to the projection interval
			int mIndex[8];       // the sorted indices of the vertices
			Real mMin, mMax;      // the interval is [min,max]
		};

		static void ProjectOntoAxis(const Triangle3& triangle, const Vector3D& axis, Configuration& cfg);

		 [[nodiscard]] bool FindOverlap(Real tmax, Real speed, const Configuration& UC, const Configuration& VC, ContactSide& side, Configuration& TUC, Configuration& TVC, Real& tfirst, Real& tlast);

		 [[nodiscard]] bool FindOverlap(const Vector3D& axis, Real tmax, const Vector3D& velocity, ContactSide& side, Configuration& tcfg0, Configuration& tcfg1, Real& tfirst, Real& tlast);

		void FindContactSet(const Triangle3& tri0, const Triangle3& tri1, ContactSide& side, Configuration& cfg0, Configuration& cfg1);

		void GetEdgeEdgeIntersection(const Vector3D& U0, const Vector3D& U1, const Vector3D& V0, const Vector3D& V1);

		void GetEdgeFaceIntersection(const Vector3D& U0, const Vector3D& U1, const Triangle3& tri);

	private:
		// 要相交的对象。
		Triangle3 m_LhsTriangle;
		Triangle3 m_RhsTriangle;

		// 默认 'true'
		bool m_ReportCoplanarIntersections;

		// Information about the intersection set.
		int m_Quantity;
		Vector3D m_Point[6];
	};

	using FloatStaticFindIntersectorTriangle3Triangle3 = StaticFindIntersectorTriangle3Triangle3<float>;
        using DoubleStaticFindIntersectorTriangle3Triangle3 = StaticFindIntersectorTriangle3Triangle3<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_TRIANGLE3_TRIANGLE3_H
