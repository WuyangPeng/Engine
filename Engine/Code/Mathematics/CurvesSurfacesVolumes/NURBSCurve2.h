// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/17 18:08)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_NURBS_CURVE2_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_NURBS_CURVE2_H

#include "Mathematics/MathematicsDll.h"

#include "SingleCurve2.h"
#include "BSplineBasis.h"

namespace Mathematics
{
	template <typename Real>
	class   NURBSCurve2 : public SingleCurve2<Real>
	{
	public:
		// Construction and destruction.  The caller is responsible for deleting
		// the input arrays if they were dynamically allocated.  Internal copies
		// of the arrays are made, so to dynamically change control points,
		// control weights, or knots, you must use the 'SetControlPoint',
		// 'GetControlPoint', 'SetControlWeight', 'GetControlWeight', and 'Knot'
		// member functions.

		// The homogeneous input points are (x,y,w) where the (x,y) values are
		// stored in the ctrlPoin array and the w values are stored in the
		// ctrlWeight array.  The output points from curve evaluations are of
		// the form (x',y') = (x/w,y/w).

		// Uniform spline.  The number of control points is n+1 >= 2.  The degree
		// of the spline is d and must satisfy 1 <= d <= n.  The knots are
		// implicitly calculated in [0,1].  If open is 'true', the spline is
		// open and the knots are
		//   t[i] = 0,               0 <= i <= d
		//          (i-d)/(n+1-d),   d+1 <= i <= n
		//          1,               n+1 <= i <= n+d+1
		// If open is 'false', the spline is periodic and the knots are
		//   t[i] = (i-d)/(n+1-d),   0 <= i <= n+d+1
		// If loop is 'true', extra control points are added to generate a closed
		// curve.  For an open spline, the control point array is reallocated and
		// one extra control point is added, set to the first control point
		// C[n+1] = C[0].  For a periodic spline, the control point array is
		// reallocated and the first d points are replicated.  In either case the
		// knot array is calculated accordingly.

		NURBSCurve2(int numCtrlPoints, const Vector2D<Real>* ctrlPoint, const Real* ctrlWeight, int degree, bool loop, bool open);

		// Open, nonuniform spline.  The knot array must have n-d elements.  The
		// elements must be nondecreasing.  Each element must be in [0,1].
		NURBSCurve2(int numCtrlPoints, const Vector2D<Real>* ctrlPoint, const Real* ctrlWeight, int degree, bool loop, const Real* knot);

		virtual ~NURBSCurve2();

		int GetNumCtrlPoints() const;
		int GetDegree() const;
		bool IsOpen() const;
		bool IsUniform() const;
		bool IsLoop() const;

		// Control points and weights may be changed at any time.  The input index
		// should be valid (0 <= i <= n).  If it is invalid, the return value of
		// GetControlPoint is a vector whose components are all MAX_REAL, and the
		// return value of GetControlWeight is MAX_REAL.
		// undefined.
		void SetControlPoint(int i, const Vector2D<Real>& ctrl);
		Vector2D<Real> GetControlPoint(int i) const;
		void SetControlWeight(int i, Real weight);
		Real GetControlWeight(int i) const;

		// The knot values can be changed only if the basis function is nonuniform
		// and the input index is valid (0 <= i <= n-d-1).  If these conditions
		// are not satisfied, GetKnot returns MAX_REAL.
		void SetKnot(int i, Real knot);
		Real GetKnot(int i) const;

		// The spline is defined for 0 <= t <= 1.  If a t-value is outside [0,1],
		// an open spline clamps t to [0,1].  That is, if t > 1, t is set to 1;
		// if t < 0, t is set to 0.  A periodic spline wraps to to [0,1].  That
		// is, if t is outside [0,1], then t is set to t-floor(t).
		virtual Vector2D<Real> GetPosition(Real t) const;
		virtual Vector2D<Real> GetFirstDerivative(Real t) const;
		virtual Vector2D<Real> GetSecondDerivative(Real t) const;
		virtual Vector2D<Real> GetThirdDerivative(Real t) const;

		// If you need position and derivatives at the same time, it is more
		// efficient to call these functions.  Pass the addresses of those
		// quantities whose values you want.  You may pass 0 in any argument
		// whose value you do not want.
		void Get(Real t, Vector2D<Real>* pos, Vector2D<Real>* der1, Vector2D<Real>* der2, Vector2D<Real>* der3) const;

		// Access the basis function to compute it without control points.  This
		// is useful for least squares fitting of curves.
		BSplineBasis<Real>& GetBasis();

	protected:
		// Replicate the necessary number of control points when the Create
		// function has loop equal to true, in which case the spline curve must
		// be a closed curve.
		void CreateControl(const Vector2D<Real>* ctrlPoint, const Real* ctrlWeight);

		int mNumCtrlPoints;
		Vector2D<Real>* mCtrlPoint;  // ctrl[n+1]
		Real* mCtrlWeight;           // weight[n+1]
		bool mLoop;
		BSplineBasis<Real> mBasis;
		int mReplicate;  // the number of replicated control points
	};

	using NURBSCurve2f = NURBSCurve2<float>;
	using NURBSCurve2d = NURBSCurve2<double>;
}

#endif // MATHEMATICS_CURVES_SURFACES_VOLUMES_NURBS_CURVE2_H
