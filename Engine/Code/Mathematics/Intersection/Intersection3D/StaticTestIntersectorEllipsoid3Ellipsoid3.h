// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/12 13:40)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_ELLIPSOID3_ELLIPSOID3_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_ELLIPSOID3_ELLIPSOID3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Ellipsoid3.h" 
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticTestIntersectorEllipsoid3Ellipsoid3: public  StaticIntersector<Real, Vector3D>
	{
	public:
		using ClassType = StaticTestIntersectorEllipsoid3Ellipsoid3<Real>;
		using ParentType = StaticIntersector<Real, Vector3D>;
		using Vector3D = Vector3D<Real>;
		using Ellipsoid3 = Ellipsoid3<Real>;
		using Vector3DTools = Vector3DTools<Real>; 
		using Math = Math<Real>;		
		
	public:
		StaticTestIntersectorEllipsoid3Ellipsoid3 (const Ellipsoid3& ellipsoid0,const Ellipsoid3& ellipsoid1);
		
		// Object access.
		const Ellipsoid3 GetEllipsoid0 () const;
		const Ellipsoid3 GetEllipsoid1 () const;
		
		// A form of test query.  The ellipsoids are separated, intersecting
		// (at points or curves), ellipsoid0 is strictly contained in ellipsoid1,
		// or ellipsoid1 is strictly contained in ellipsoid0.
		enum Classification
		{
			EC_ELLIPSOIDS_SEPARATED,
			EC_ELLIPSOIDS_INTERSECTING,
			EC_ELLIPSOID0_CONTAINS_ELLIPSOID1,
			EC_ELLIPSOID1_CONTAINS_ELLIPSOID0
		};
		
		Classification GetClassification () const;
		
	private:
		void Test();

		// Support functions for GetClassification().
		static void BisectF (Real d0, Real d1, Real d2, Real d0c0, Real d1c1,Real d2c2, Real smin, Real fmin, Real smax, Real fmax, Real& s,Real& f);
		
		static void BisectDF (Real d0, Real d1, Real d2, Real d0c0, Real d1c1,Real d2c2, Real smin, Real dfmin, Real smax, Real dfmax, Real& s,Real& df);
		
		static void GetRoots (Real d0, Real d1, Real d2, Real c0, Real c1,Real c2, int& numRoots, Real* roots);
		
		static void BisectF (Real d0, Real d1, Real d0c0, Real d1c1, Real smin,Real fmin, Real smax, Real fmax, Real& s, Real& f);
		
		static void BisectDF (Real d0, Real d1, Real d0c0, Real d1c1, Real smin,Real dfmin, Real smax, Real dfmax, Real& s, Real& df);
		
		static void GetRoots (Real d0, Real d1, Real c0, Real c1, int& numRoots,Real* roots);
		
		static void GetRoots (Real d0, Real c0, int& numRoots, Real* roots);
		
		// The objects to intersect.
		Ellipsoid3 mEllipsoid0;
		Ellipsoid3 mEllipsoid1;
		Classification m_Classification;
	};

	using StaticTestIntersectorEllipsoid3Ellipsoid3f = StaticTestIntersectorEllipsoid3Ellipsoid3<float>;
	using StaticTestIntersectorEllipsoid3Ellipsoid3d = StaticTestIntersectorEllipsoid3Ellipsoid3<double>;

}

#endif // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_ELLIPSOID3_ELLIPSOID3_H
