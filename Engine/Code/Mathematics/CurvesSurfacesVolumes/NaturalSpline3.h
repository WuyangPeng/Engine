// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 18:07)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_NATURAL_SPLINE3_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_NATURAL_SPLINE3_H

#include "Mathematics/MathematicsDll.h"

#include "MultipleCurve3.h"

namespace Mathematics
{
	template <typename Real>
	class   NaturalSpline3 : public MultipleCurve3<Real>
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
		//   2. NaturalSpline3 accepts responsibility for deleting the input
		//      arrays, so these arrays must be dynamically allocated by the
		//      caller.
		//   3. When the boundary type is BT_CLAMPED, the endpoint derivatives are
		//      automatically chosen to be
		//        derivativeStart = points[1] - points[0]
		//        derivativeFinal = points[N] - points[N-1]
		//      To specify the derivatives for BT_CLAMPED, use the second
		//      constructor listed below.
		NaturalSpline3(BoundaryType type, int numSegments, Real* times, Vector3<Real>* points);

		// Specify the derivative vectors for clamped splines.
		NaturalSpline3(int numSegments, Real* times, Vector3<Real>* points, const Vector3<Real>& derivativeStart, const Vector3<Real>& derivativeFinal);

		virtual ~NaturalSpline3();

		const Vector3<Real>* GetPoints() const;

		virtual Vector3<Real> GetPosition(Real t) const;
		virtual Vector3<Real> GetFirstDerivative(Real t) const;
		virtual Vector3<Real> GetSecondDerivative(Real t) const;
		virtual Vector3<Real> GetThirdDerivative(Real t) const;

	protected:
		using MultipleCurve3<Real>::mNumSegments;
		using MultipleCurve3<Real>::mTimes;
		using MultipleCurve3<Real>::GetSpeedWithData;
		using MultipleCurve3<Real>::GetKeyInfo;

		void CreateFreeSpline();

		void CreateClampedSpline(const Vector3<Real>& derivativeStart, const Vector3<Real>& derivativeFinal);

		void CreateClosedSpline();

		virtual Real GetSpeedKey(int key, Real t) const;
		virtual Real GetLengthKey(int key, Real t0, Real t1) const;

		Vector3<Real>* mA;
		Vector3<Real>* mB;
		Vector3<Real>* mC;
		Vector3<Real>* mD;

		class  SplineKey
		{
		public:
			SplineKey(const NaturalSpline3* spline, int key);

			const NaturalSpline3* Spline;
			int Key;
		};

		static Real GetSpeedWithDataKey(Real t, const SplineKey* data);
	};

	using NaturalSpline3f = NaturalSpline3<float>;
	using NaturalSpline3d = NaturalSpline3<double>;
}

#endif // MATHEMATICS_CURVES_SURFACES_VOLUMES_NATURAL_SPLINE3_H
