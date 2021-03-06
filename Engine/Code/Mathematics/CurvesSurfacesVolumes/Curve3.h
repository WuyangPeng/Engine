// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/17 18:02)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_CURVE3_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_CURVE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3D.h"

namespace Mathematics
{
	template <typename Real>
	class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Curve3
	{
	public:
		// Abstract base class.
            Curve3(Real tmin, Real tmax) noexcept;
		virtual ~Curve3 ();
		Curve3(const Curve3&) = default;
		Curve3& operator=(const Curve3&) = default;
		Curve3(Curve3&&) = default;
		Curve3& operator=(Curve3&&) = default;
		// Interval on which curve parameter is defined.  If you are interested
		// in only a subinterval of the actual domain of the curve, you may set
		// that subinterval with SetTimeInterval.  This function requires that
		// tmin < tmax.
                Real GetMinTime() const noexcept;
                Real GetMaxTime() const noexcept;
		void SetTimeInterval (Real tmin, Real tmax);
		
		// Position and derivatives.
		virtual Vector3D<Real> GetPosition (Real t) const = 0;
		virtual Vector3D<Real> GetFirstDerivative (Real t) const = 0;
		virtual Vector3D<Real> GetSecondDerivative (Real t) const = 0;
		virtual Vector3D<Real> GetThirdDerivative (Real t) const = 0;
		
		// Differential geometric quantities.
		Real GetSpeed (Real t) const;
		virtual Real GetLength (Real t0, Real t1) const = 0;
		Real GetTotalLength () const;
		Vector3D<Real> GetTangent (Real t) const;
		Vector3D<Real> GetNormal (Real t) const;
		Vector3D<Real> GetBinormal (Real t) const;
		void GetFrame (Real t, Vector3D<Real>& position, Vector3D<Real>& tangent, Vector3D<Real>& normal, Vector3D<Real>& binormal) const;
		Real GetCurvature (Real t) const;
		Real GetTorsion (Real t) const;
		
		// Inverse mapping of s = Length(t) given by t = Length^{-1}(s).
		virtual Real GetTime (Real length, int iterations = 32, Real tolerance = static_cast<Real>(1e-06)) const = 0;
		
		// Subdivision.
		void SubdivideByTime (int numPoints, Vector3D<Real>*& points) const;
		void SubdivideByLength (int numPoints, Vector3D<Real>*& points) const;
		
	protected:
		// Curve parameter is t where tmin <= t <= tmax.
		Real mTMin, mTMax;
	};
	
	using Curve3f = Curve3<float>;
	using Curve3d = Curve3<double>;
}

#endif // MATHEMATICS_CURVES_SURFACES_VOLUMES_CURVE3_H
