// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 17:54)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_BEZIER_CURVE3_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_BEZIER_CURVE3_H

#include "Mathematics/MathematicsDll.h"

#include "SingleCurve3.h"
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)
namespace Mathematics
{
	template <typename Real>
	class  BezierCurve3 : public SingleCurve3<Real>
    {
    public:
        using Math = Math<Real>;

	public:
		// Construction and destruction.  BezierCurve3 accepts responsibility for
		// deleting the input arrays.
		BezierCurve3 (int degree, Vector3<Real>* ctrlPoint);
		  ~BezierCurve3 ();
		
		BezierCurve3(const BezierCurve3&) = default;
		BezierCurve3& operator=(const BezierCurve3&) = default;
		BezierCurve3(BezierCurve3&&) = default;
		BezierCurve3& operator=(BezierCurve3&&) = default;
		
		int GetDegree () const noexcept;
		const Vector3<Real>* GetControlPoints () const noexcept;
		
		  Vector3<Real> GetPosition (Real t) const override;
		  Vector3<Real> GetFirstDerivative (Real t) const override;
		  Vector3<Real> GetSecondDerivative (Real t) const override;
		  Vector3<Real> GetThirdDerivative (Real t) const override;

	protected:
		int mDegree;
		int mNumCtrlPoints;
		Vector3<Real>* mCtrlPoint;
		Vector3<Real>* mDer1CtrlPoint;
		Vector3<Real>* mDer2CtrlPoint;
		Vector3<Real>* mDer3CtrlPoint;
		Real** mChoose;
	};
	
	using BezierCurve3f = BezierCurve3<float>;
	using BezierCurve3d = BezierCurve3<double>;
}
#include STSTEM_WARNING_POP
#endif // MATHEMATICS_CURVES_SURFACES_VOLUMES_BEZIER_CURVE3_H
