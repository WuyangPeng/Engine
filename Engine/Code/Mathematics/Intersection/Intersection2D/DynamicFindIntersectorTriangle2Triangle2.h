// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/11 15:29)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_TRIANGLE2_TRIANGLE2_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_TRIANGLE2_TRIANGLE2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects2D/Triangle2.h"   
#include "Mathematics/Intersection/Intersector1.h"
#include "Mathematics/Intersection/DynamicIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class DynamicFindIntersectorTriangle2Triangle2 : public DynamicIntersector<Real, Vector2D>
	{
	public:
		using Math = Math<Real>;
		using ClassType = DynamicFindIntersectorTriangle2Triangle2<Real>;
		using ParentType = DynamicIntersector<Real, Vector2D>;
		using Vector2D = Vector2D<Real>;
		using Triangle2 = Triangle2<Real>;
		using Vector2DTools = Vector2DTools<Real>; 

	public:
		DynamicFindIntersectorTriangle2Triangle2(const Triangle2& triangle0, const Triangle2& triangle1,Real tmax,
												 const Vector2D& velocity0,const Vector2D& velocity1,const Real epsilon = Math::sm_ZeroTolerance);
		
		// Object access.
		const Triangle2 GetTriangle0 () const;
		const Triangle2 GetTriangle1 () const;    
		
		// Information about the intersection set.
		int GetQuantity () const;
		const Vector2D GetPoint (int i) const;
		
	private:
		// Dynamic queries.		 
		void Find();

	private:
		static int WhichSide (const Vector2D V[3], const Vector2D& P, const Vector2D& D);
		
		static void ClipConvexPolygonAgainstLine (const Vector2D& N, Real c, int& quantity,  Vector2D V[6]);
		
		enum class ProjectionMap
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
		
		void ComputeTwo(Configuration& cfg, const std::vector<Vector2D>& V,  const Vector2D& D, int i0, int i1, int i2);
		
		void ComputeThree(Configuration& cfg, const std::vector<Vector2D>& V, const Vector2D& D, const Vector2D& P);
		
		static bool NoIntersect (const Configuration& cfg0, const Configuration& cfg1, Real tmax, Real speed, int& side,
                                 Configuration& tcfg0, Configuration& tcfg1, Real& tfirst, Real& tlast);
		
		static void GetIntersection (const Configuration& cfg0, const Configuration& cfg1, int side, const Vector2D V0[3],
                                     const Vector2D V1[3], int& quantity, Vector2D vertex[6]);
		
		// The objects to intersect.
		Triangle2 mTriangle0;
		Triangle2 mTriangle1;
		
		// Information about the intersection set.
		int mQuantity;
		Vector2D mPoint[6];
	};
	
	using DynamicFindIntersectorTriangle2Triangle2f = DynamicFindIntersectorTriangle2Triangle2<float>;
	using DynamicFindIntersectorTriangle2Triangle2d = DynamicFindIntersectorTriangle2Triangle2<double>;
}

#endif // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_TRIANGLE2_TRIANGLE2_H
