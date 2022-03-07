// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 18:05)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_NATURAL_SPLINE2_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_NATURAL_SPLINE2_H

#include "Mathematics/MathematicsDll.h"

#include "MultipleCurve2.h"

namespace Mathematics
{
	template <typename Real>
	class  NaturalSpline2 : public MultipleCurve2<Real>
	{
	public:
		enum BoundaryType
		{
			BT_FREE,
			BT_CLAMPED,
			BT_CLOSED
		};

		// Construction and destruction.
		//   1. If N is the number of points, the number of segments must be N-1.
		//   2. NaturalSpline2 accepts responsibility for deleting the input
		//      arrays, so these arrays must be dynamically allocated by the
		//      caller.
		//   3. When the boundary type is BT_CLAMPED, the endpoint derivatives are
		//      automatically chosen to be
		//        derivativeStart = points[1] - points[0]
		//        derivativeFinal = points[N] - points[N-1]
		//      To specify the derivatives for BT_CLAMPED, use the second
		//      constructor listed below.
		NaturalSpline2(BoundaryType type, int numSegments, Real* times, Vector2<Real>* points);

		// Specify the derivative vectors for clamped splines.
		NaturalSpline2(int numSegments, Real* times, Vector2<Real>* points, const Vector2<Real>& derivativeStart, const Vector2<Real>& derivativeFinal);

		virtual ~NaturalSpline2();

		const Vector2<Real>* GetPoints() const;

		virtual Vector2<Real> GetPosition(Real t) const;
		virtual Vector2<Real> GetFirstDerivative(Real t) const;
		virtual Vector2<Real> GetSecondDerivative(Real t) const;
		virtual Vector2<Real> GetThirdDerivative(Real t) const;

	protected:
		using MultipleCurve2<Real>::mNumSegments;
		using MultipleCurve2<Real>::mTimes;
		using MultipleCurve2<Real>::GetKeyInfo;
		using MultipleCurve2<Real>::GetSpeedWithData;

		void CreateFreeSpline();

		void CreateClampedSpline(const Vector2<Real>& derivativeStart, const Vector2<Real>& derivativeFinal);

		void CreateClosedSpline();

		virtual Real GetSpeedKey(int key, Real t) const;
		virtual Real GetLengthKey(int key, Real t0, Real t1) const;

		Vector2<Real>* mA;
		Vector2<Real>* mB;
		Vector2<Real>* mC;
		Vector2<Real>* mD;

		class  SplineKey
		{
		public:
			SplineKey(const NaturalSpline2* spline, int key);

			const NaturalSpline2* Spline;
			int Key;
		};

		static Real GetSpeedWithDataKey(Real t, const SplineKey* data);
	};

	using NaturalSpline2f = NaturalSpline2<float>;
	using NaturalSpline2d = NaturalSpline2<double>;
}

#endif // MATHEMATICS_CURVES_SURFACES_VOLUMES_NATURAL_SPLINE2_H
