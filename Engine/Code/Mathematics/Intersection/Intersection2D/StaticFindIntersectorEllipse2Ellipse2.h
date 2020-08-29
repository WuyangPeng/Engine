// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/24 14:35)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ELLIPSE2_ELLIPSE2_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ELLIPSE2_ELLIPSE2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects2D/Ellipse2.h"
#include "Mathematics/Algebra/Polynomial.h"
#include "Mathematics/Intersection/StaticIntersector.h" 

namespace Mathematics
{
	template <typename Real>
	class StaticFindIntersectorEllipse2Ellipse2 : public StaticIntersector<Real, Vector2D>
	{
	public:
		using ClassType = StaticFindIntersectorEllipse2Ellipse2<Real>;
		using ParentType = StaticIntersector<Real, Vector2D>;
		using Vector2D = Vector2D<Real>;
		using Ellipse2 = Ellipse2<Real>;
		using Vector2DTools = Vector2DTools<Real>;
		using Math = Math<Real>;

	public:
		StaticFindIntersectorEllipse2Ellipse2(const Ellipse2& ellipse0, const Ellipse2& ellipse1, const Real epsilon = Math::GetZeroTolerance());
		virtual ~StaticFindIntersectorEllipse2Ellipse2();

		// Object access.
		const Ellipse2& GetEllipse0() const;
		const Ellipse2& GetEllipse1() const;

	private:
		// Static intersection queries.
		void Find();

		// Intersection set for static find-intersection query.  The quantity Q
		// satisfies 0 <= Q <= 4.  When Q > 0, the interpretation depends on the
		// intersection type.
		//   IT_POINT:  Q distinct points of intersection
		//   IT_OTHER:  The ellipses are the same.  One of the ellipse objects is
		//              returned by GetIntersectionEllipse.  Q is invalid.
		int GetQuantity() const;
		const Vector2D& GetPoint(int i) const;
		const Ellipse2& GetIntersectionEllipse() const;
		bool IsTransverseIntersection(int i) const;

		// Digits of accuracy for root finding.  The default value is 10.
		int DIGITS_ACCURACY;

		// A form of test query.  The ellipses are separated, intersecting,
		// ellipse0 is strictly contained in ellipse1, or ellipse1 is strictly
		// contained in ellipse0.
		enum Classification
		{
			EC_ELLIPSES_SEPARATED,
			EC_ELLIPSES_INTERSECTING,
			EC_ELLIPSE0_CONTAINS_ELLIPSE1,
			EC_ELLIPSE1_CONTAINS_ELLIPSE0
		};

		Classification GetClassification() const;

	private:

		// Support for sorting potential intersection points.
		class Measurement
		{
		public:
			Measurement();
			bool operator< (const Measurement& measure) const;

			// <x, y, sqrt(Q0(x,y)^2 + Q1(x,y)^2)>
			Vector2D Point;
			Real Q0, Q1, Norm, Angle0;
			bool Transverse;
		};

		static Polynomial<Real> GetQuartic(const Ellipse2& ellipse0, const Ellipse2& ellipse1);

		bool RefinePoint(const Real coeff[6], Vector2D& point, Real& q0, Real& q1, Real& angle0);

		// Support functions for GetClassification().
		static void BisectF(Real d0, Real d1, Real d0c0, Real d1c1, Real smin,
							Real fmin, Real smax, Real fmax, Real& s, Real& f);

		static void BisectDF(Real d0, Real d1, Real d0c0, Real d1c1, Real smin,
							 Real dfmin, Real smax, Real dfmax, Real& s, Real& df);

		static void GetRoots(Real d0, Real d1, Real c0, Real c1, int& numRoots,
							 Real* roots);

		static void GetRoots(Real d0, Real c0, int& numRoots, Real* roots);

		// The objects to intersect.
		Ellipse2 mEllipse0;
		Ellipse2 mEllipse1;

		// Points of intersection.
		int mQuantity;
		Vector2D mPoint[4];
		bool mTransverse[4];
	};

	using StaticFindIntersectorEllipse2Ellipse2f = StaticFindIntersectorEllipse2Ellipse2<float>;
	using StaticFindIntersectorEllipse2Ellipse2d = StaticFindIntersectorEllipse2Ellipse2<double>;
}

#endif // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_ELLIPSE2_ELLIPSE2_H
