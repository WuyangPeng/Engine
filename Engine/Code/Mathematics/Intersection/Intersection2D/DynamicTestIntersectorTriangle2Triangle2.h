// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 14:34)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_TRIANGLE2_TRIANGLE2_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_TRIANGLE2_TRIANGLE2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects2D/Triangle2.h"   
#include "Mathematics/Intersection/Intersector1.h"   
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class DynamicTestIntersectorTriangle2Triangle2 : public DynamicIntersector<Real, Vector2D>
	{
	public:
		using ClassType = DynamicTestIntersectorTriangle2Triangle2<Real>;
		using ParentType = DynamicIntersector<Real, Vector2D>;
		using Vector2D = Vector2D<Real>;
		using Triangle2 = Triangle2<Real>;
		using Vector2DTools = Vector2DTools<Real>;
		using Math = Math<Real>;

	public:
		DynamicTestIntersectorTriangle2Triangle2(const Triangle2& triangle0, const Triangle2& triangle1, Real tmax,
												 const Vector2D& velocity0, const Vector2D& velocity1, const Real epsilon = Math::GetZeroTolerance());

		// Object access.
		const Triangle2 GetTriangle0() const;
		const Triangle2 GetTriangle1() const;

	private:
		// Dynamic queries.		 
		void Test();

	private:
		static int WhichSide(const Vector2D V[3], const Vector2D& P, const Vector2D& D);

		static void ClipConvexPolygonAgainstLine(const Vector2D& N, Real c, int& quantity, Vector2D V[6]);

		enum ProjectionMap
		{
			M21,  // 2 vertices map to min, 1 vertex maps to max
			M12,  // 1 vertex maps to min, 2 vertices map to max
			M11   // 1 vertex maps to min, 1 vertex maps to max
		};

		class Configuration
		{
		public:
			ProjectionMap Map;  // how vertices map to the projection interval
			int Index[3];       // the sorted indices of the vertices
			Real Min, Max;      // the interval is [min,max]
		};

		void ComputeTwo(Configuration& cfg, const std::vector<Vector2D>& V, const Vector2D& D, int i0, int i1, int i2);

		void ComputeThree(Configuration& cfg, const std::vector<Vector2D>& V, const Vector2D& D, const Vector2D& P);

		static bool NoIntersect(const Configuration& cfg0, const Configuration& cfg1, Real tmax, Real speed, int& side,
								Configuration& tcfg0, Configuration& tcfg1, Real& tfirst, Real& tlast);

		static void GetIntersection(const Configuration& cfg0, const Configuration& cfg1, int side, const Vector2D V0[3],
									const Vector2D V1[3], int& quantity, Vector2D vertex[6]);

		// The objects to intersect.
		Triangle2 mTriangle0;
		Triangle2 mTriangle1;
	};

	using DynamicTestIntersectorTriangle2Triangle2f = DynamicTestIntersectorTriangle2Triangle2<float>;
	using DynamicTestIntersectorTriangle2Triangle2d = DynamicTestIntersectorTriangle2Triangle2<double>;
}

#endif // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_TRIANGLE2_TRIANGLE2_H
