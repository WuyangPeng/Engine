// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 18:04)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_MULTIPLE_CURVE3_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_MULTIPLE_CURVE3_H

#include "Mathematics/MathematicsDll.h"

#include "Curve3.h"

namespace Mathematics
{
	template <typename Real>
	class  MultipleCurve3 : public Curve3<Real>
	{
	public:
		// Construction and destruction for abstract base class.  MultipleCurve3
		// accepts responsibility for deleting the input array.
		MultipleCurve3(int numSegments, Real* times);
		virtual ~MultipleCurve3();

		// Member access.
		int GetSegments() const;
		const Real* GetTimes() const;

		// Length-from-time and time-from-length.
		virtual Real GetLength(Real t0, Real t1) const;
		virtual Real GetTime(Real length, int iterations = 32, Real tolerance = static_cast<Real>(1e-06)) const;

	protected:
		using Curve3<Real>::mTMin;
		using Curve3<Real>::mTMax;

		int mNumSegments;
		Real* mTimes;

		// These quantities are allocated by GetLength when they are needed the
		// first time.  The allocations occur in InitializeLength (called by
		// GetLength), so this member function must be 'const'. In order to
		// allocate the arrays in a 'const' function, they must be declared as
		// 'mutable'.
		mutable Real* mLengths;
		mutable Real* mAccumLengths;

		void GetKeyInfo(Real t, int& key, Real& dt) const;

		void InitializeLength() const;
		virtual Real GetSpeedKey(int key, Real t) const = 0;
		virtual Real GetLengthKey(int key, Real t0, Real t1) const = 0;

		static Real GetSpeedWithData(Real t, void* data);
	};

	using MultipleCurve3f = MultipleCurve3<float>;
	using MultipleCurve3d = MultipleCurve3<double>;
}

#endif // MATHEMATICS_CURVES_SURFACES_VOLUMES_MULTIPLE_CURVE3_H
