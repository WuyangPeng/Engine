// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/17 17:54)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_BEZIER_CURVE3_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_BEZIER_CURVE3_H

#include "Mathematics/MathematicsDll.h"

#include "SingleCurve3.h"

namespace Mathematics
{
	template <typename Real>
	class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE BezierCurve3 : public SingleCurve3<Real>
	{
	public:
		// Construction and destruction.  BezierCurve3 accepts responsibility for
		// deleting the input arrays.
		BezierCurve3 (int degree, Vector3D<Real>* ctrlPoint);
		virtual ~BezierCurve3 ();
		
		int GetDegree () const;
		const Vector3D<Real>* GetControlPoints () const;
		
		virtual Vector3D<Real> GetPosition (Real t) const;
		virtual Vector3D<Real> GetFirstDerivative (Real t) const;
		virtual Vector3D<Real> GetSecondDerivative (Real t) const;
		virtual Vector3D<Real> GetThirdDerivative (Real t) const;

	protected:
		int mDegree;
		int mNumCtrlPoints;
		Vector3D<Real>* mCtrlPoint;
		Vector3D<Real>* mDer1CtrlPoint;
		Vector3D<Real>* mDer2CtrlPoint;
		Vector3D<Real>* mDer3CtrlPoint;
		Real** mChoose;
	};
	
	using BezierCurve3f = BezierCurve3<float>;
	using BezierCurve3d = BezierCurve3<double>;
}

#endif // MATHEMATICS_CURVES_SURFACES_VOLUMES_BEZIER_CURVE3_H
