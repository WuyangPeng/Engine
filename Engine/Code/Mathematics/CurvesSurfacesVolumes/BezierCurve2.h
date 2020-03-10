// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 17:54)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_BEZIER_CURVE2_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_BEZIER_CURVE2_H

#include "Mathematics/MathematicsDll.h"

#include "SingleCurve2.h"

namespace Mathematics
{
	template <typename Real>
	class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE BezierCurve2 : public SingleCurve2<Real>
	{
	public:	
		// Construction and destruction.  BezierCurve2 accepts responsibility for
		// deleting the input array.
		BezierCurve2 (int degree, Vector2D<Real>* ctrlPoint);
		virtual ~BezierCurve2 ();
		
		int GetDegree () const;
		const Vector2D<Real>* GetControlPoints () const;
		
		virtual Vector2D<Real> GetPosition (Real t) const;
		virtual Vector2D<Real> GetFirstDerivative (Real t) const;
		virtual Vector2D<Real> GetSecondDerivative (Real t) const;
		virtual Vector2D<Real> GetThirdDerivative (Real t) const;

	protected:
		int mDegree;
		int mNumCtrlPoints;
		Vector2D<Real>* mCtrlPoint;
		Vector2D<Real>* mDer1CtrlPoint;
		Vector2D<Real>* mDer2CtrlPoint;
		Vector2D<Real>* mDer3CtrlPoint;
		Real** mChoose;
	};
	
	using BezierCurve2f = BezierCurve2<float>;
	using BezierCurve2d = BezierCurve2<double>;
}

#endif // MATHEMATICS_CURVES_SURFACES_VOLUMES_BEZIER_CURVE2_H
