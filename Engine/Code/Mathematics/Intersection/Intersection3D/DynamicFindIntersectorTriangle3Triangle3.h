// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 14:46)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_TRIANGLE3_TRIANGLE3_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_TRIANGLE3_TRIANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Line3.h"
#include "Mathematics/Objects3D/Plane3.h" 
#include "Mathematics/Objects3D/Triangle3.h"
#include "Mathematics/Intersection/DynamicIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class DynamicFindIntersectorTriangle3Triangle3 : public  DynamicIntersector<Real, Vector3D>
	{
	public:
		using ClassType = DynamicFindIntersectorTriangle3Triangle3<Real>;
		using ParentType = DynamicIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Triangle3 = Triangle3<Real>;
		using Plane3 = Plane3<Real>;
		using Line3 = Line3<Real>;
		using  Vector3DTools = Vector3DTools<Real>;
		using Math = Math<Real>;

	public:
		DynamicFindIntersectorTriangle3Triangle3(const Triangle3& triangle0, const Triangle3& triangle1, Real tmax,
												 const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon = Math::sm_ZeroTolerance);

		// Object access.
		const Triangle3 GetTriangle0() const;
		const Triangle3 GetTriangle1() const;

		bool mReportCoplanarIntersections;  // default 'true'

		// The intersection set.
		int GetQuantity() const;
		const Vector3D GetPoint(int i) const;

	private:
		// Dynamic queries.
		void Find();

		static void ProjectOntoAxis(const Triangle3& triangle, const Vector3D& axis, Real& fmin, Real& fmax);

		static void TrianglePlaneRelations(const Triangle3& triangle, const Plane3& plane, Real distance[3], int sign[3], int& positive, int& negative, int& zero);

		static void GetInterval(const Triangle3& triangle, const Line3& line, const Real distance[3], const int sign[3], Real param[2]);

		bool ContainsPoint(const Triangle3& triangle, const Plane3& plane, const Vector3D& point);

		bool IntersectsSegment(const Plane3& plane, const Triangle3& triangle, const Vector3D& end0, const Vector3D& end1);

		bool GetCoplanarIntersection(const Plane3& plane, const Triangle3& tri0, const Triangle3& tri1);

		static bool TestOverlap(Real tmax, Real speed, Real umin, Real umax, Real vmin, Real vmax, Real& tfirst, Real& tlast);

		bool TestOverlap(const Vector3D& axis, Real tmax, const Vector3D& velocity, Real& tfirst, Real& tlast);

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

		bool FindOverlap(Real tmax, Real speed, const Configuration& UC, const Configuration& VC, ContactSide& side, Configuration& TUC, Configuration& TVC, Real& tfirst, Real& tlast);

		bool FindOverlap(const Vector3D & axis, Real tmax, const Vector3D & velocity, ContactSide& side,
						 Configuration& tcfg0, Configuration& tcfg1, Real& tfirst, Real& tlast);

		void FindContactSet(const Triangle3& tri0, const Triangle3& tri1, ContactSide& side,
							Configuration& cfg0, Configuration& cfg1);

		void GetEdgeEdgeIntersection(const Vector3D& U0, const Vector3D& U1, const Vector3D& V0, const Vector3D& V1);

		void GetEdgeFaceIntersection(const Vector3D& U0, const Vector3D& U1, const Triangle3& tri);

		// The objects to intersect.
		Triangle3 mTriangle0;
		Triangle3 mTriangle1;

		// Information about the intersection set.
		int mQuantity;
		Vector3D mPoint[6];
	};

	using DynamicFindIntersectorTriangle3Triangle3f = DynamicFindIntersectorTriangle3Triangle3<float>;
	using DynamicFindIntersectorTriangle3Triangle3d = DynamicFindIntersectorTriangle3Triangle3<double>;
}

#endif // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_TRIANGLE3_TRIANGLE3_H
