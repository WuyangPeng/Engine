// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 18:28)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_TCB_SPLINE2_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_TCB_SPLINE2_H

#include "Mathematics/MathematicsDll.h"

#include "MultipleCurve2.h"

namespace Mathematics
{
	template <typename Real>
	class   TCBSpline2 : public MultipleCurve2<Real>
	{
	public:
		// Construction and destruction.  TCBSpline2 accepts responsibility for
		// deleting the input arrays.
		TCBSpline2(int numSegments, Real* times, Vector2<Real>* points, Real* tension, Real* continuity, Real* bias);

		virtual ~TCBSpline2();

		const Vector2<Real>* GetPoints() const;
		const Real* GetTensions() const;
		const Real* GetContinuities() const;
		const Real* GetBiases() const;

		virtual Vector2<Real> GetPosition(Real t) const;
		virtual Vector2<Real> GetFirstDerivative(Real t) const;
		virtual Vector2<Real> GetSecondDerivative(Real t) const;
		virtual Vector2<Real> GetThirdDerivative(Real t) const;

	protected:
		using MultipleCurve2<Real>::mNumSegments;
		using MultipleCurve2<Real>::mTimes;
		using MultipleCurve2<Real>::GetKeyInfo;
		using MultipleCurve2<Real>::GetSpeedWithData;

		void ComputePoly(int i0, int i1, int i2, int i3);

		virtual Real GetSpeedKey(int key, Real t) const;
		virtual Real GetLengthKey(int key, Real t0, Real t1) const;

		Vector2<Real>* mPoints;
		Real* mTension;
		Real* mContinuity;
		Real* mBias;
		Vector2<Real>* mA;
		Vector2<Real>* mB;
		Vector2<Real>* mC;
		Vector2<Real>* mD;

		class   SplineKey
		{
		public:
			SplineKey(const TCBSpline2* spline, int key);

			const TCBSpline2* Spline;
			int Key;
		};

		static Real GetSpeedWithDataKey(Real t, const SplineKey* data);
	};

	using TCBSpline2f = TCBSpline2<float>;
	using TCBSpline2d = TCBSpline2<double>;
}

#endif // MATHEMATICS_CURVES_SURFACES_VOLUMES_TCB_SPLINE2_H
