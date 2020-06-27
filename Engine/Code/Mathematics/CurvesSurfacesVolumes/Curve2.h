// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 18:02)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_CURVE2_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_CURVE2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector2D.h"

namespace Mathematics
{
	template <typename Real>
	class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Curve2
	{
	public:
		// Abstract base class.
		Curve2 (Real tmin, Real tmax);
		virtual ~Curve2 ();
		
		// Interval on which curve parameter is defined.  If you are interested
		// in only a subinterval of the actual domain of the curve, you may set
		// that subinterval with SetTimeInterval.  This function requires that
		// tmin < tmax.
		Real GetMinTime () const;
		Real GetMaxTime () const;
		void SetTimeInterval (Real tmin, Real tmax);
		
		// Position and derivatives.
		virtual Vector2D<Real> GetPosition (Real t) const = 0;
		virtual Vector2D<Real> GetFirstDerivative (Real t) const = 0;
		virtual Vector2D<Real> GetSecondDerivative (Real t) const = 0;
		virtual Vector2D<Real> GetThirdDerivative (Real t) const = 0;

		// Differential geometric quantities.
		Real GetSpeed (Real t) const;
		virtual Real GetLength (Real t0, Real t1) const = 0;
		Real GetTotalLength () const;
		Vector2D<Real> GetTangent (Real t) const;
		Vector2D<Real> GetNormal (Real t) const;
		void GetFrame (Real t, Vector2D<Real>& position, Vector2D<Real>& tangent, Vector2D<Real>& normal) const;
		Real GetCurvature (Real t) const;

		// Inverse mapping of s = Length(t) given by t = Length^{-1}(s).
		virtual Real GetTime (Real length, int iterations = 32, Real tolerance = static_cast<Real>(1e-06)) const = 0;

		// Subdivision.
		void SubdivideByTime (int numPoints, Vector2D<Real>*& points) const;
		void SubdivideByLength (int numPoints, Vector2D<Real>*& points) const;

	protected:
		// Curve parameter is t where tmin <= t <= tmax.
		Real mTMin, mTMax;
	};

	using Curve2f = Curve2<float>;
	using Curve2d = Curve2<double>;
}

#endif // MATHEMATICS_CURVES_SURFACES_VOLUMES_CURVE2_H
