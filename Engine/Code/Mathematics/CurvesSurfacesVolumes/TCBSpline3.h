// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 18:28)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_TCB_SPLINE3_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_TCB_SPLINE3_H

#include "Mathematics/MathematicsDll.h"

#include "MultipleCurve3.h"

namespace Mathematics
{
	template <typename Real>
	class   TCBSpline3 : public MultipleCurve3<Real>
	{
	public:
		// Construction and destruction.  TCBSpline3 accepts responsibility for
		// deleting the input arrays.
		TCBSpline3(int numSegments, Real* times, Vector3D<Real>* points, Real* tension, Real* continuity, Real* bias);

		virtual ~TCBSpline3();

		const Vector3D<Real>* GetPoints() const;
		const Real* GetTensions() const;
		const Real* GetContinuities() const;
		const Real* GetBiases() const;

		virtual Vector3D<Real> GetPosition(Real t) const;
		virtual Vector3D<Real> GetFirstDerivative(Real t) const;
		virtual Vector3D<Real> GetSecondDerivative(Real t) const;
		virtual Vector3D<Real> GetThirdDerivative(Real t) const;

	protected:
		using MultipleCurve3<Real>::mNumSegments;
		using MultipleCurve3<Real>::mTimes;
		using MultipleCurve3<Real>::GetKeyInfo;
		using MultipleCurve3<Real>::GetSpeedWithData;

		void ComputePoly(int i0, int i1, int i2, int i3);

		virtual Real GetSpeedKey(int key, Real t) const;
		virtual Real GetLengthKey(int key, Real t0, Real t1) const;

		Vector3D<Real>* mPoints;
		Real* mTension;
		Real* mContinuity;
		Real* mBias;
		Vector3D<Real>* mA;
		Vector3D<Real>* mB;
		Vector3D<Real>* mC;
		Vector3D<Real>* mD;

		class   SplineKey
		{
		public:
			SplineKey(const TCBSpline3* spline, int key);

			const TCBSpline3* Spline;
			int Key;
		};

		static Real GetSpeedWithDataKey(Real t, const SplineKey* data);
	};

	using TCBSpline3f = TCBSpline3<float>;
	using TCBSpline3d = TCBSpline3<double>;
}
 
#endif // MATHEMATICS_CURVES_SURFACES_VOLUMES_TCB_SPLINE3_H
