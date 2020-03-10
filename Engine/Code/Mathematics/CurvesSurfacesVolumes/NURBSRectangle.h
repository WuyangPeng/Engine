// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 18:10)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_NURBS_RECTANGLE_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_NURBS_RECTANGLE_H

#include "Mathematics/MathematicsDll.h"

#include "ParametricSurface.h"
#include "BSplineBasis.h"

namespace Mathematics
{
	template <typename Real>
	class   NURBSRectangle : public ParametricSurface<Real>
	{
	public:
		// Construction and destruction.   The caller is responsible for deleting
		// the input arrays if they were dynamically allocated.  Internal copies
		// of the arrays are made, so to dynamically change control points,
		// control weights, or knots, you must use the 'SetControlPoint',
		// 'GetControlPoint', 'SetControlWeight', 'GetControlWeight', and 'Knot'
		// member functions.

		// The homogeneous input points are (x,y,z,w) where the (x,y,z) values are
		// stored in the akCtrlPoint array and the w values are stored in the
		// afCtrlWeight array.  The output points from curve evaluations are of
		// the form (x',y',z') = (x/w,y/w,z/w).

		// Spline types for curves are
		//   open uniform (OU)
		//   periodic uniform (PU)
		//   open nonuniform (ON)
		// For tensor product surfaces, you have to choose a type for each of two
		// dimensions, leading to nine possible spline types for surfaces.  The
		// constructors below represent these choices.

		// (OU,OU), (OU,PU), (PU,OU), or (PU,PU)
		NURBSRectangle(int numUCtrlPoints, int numVCtrlPoints, Vector3D<Real>** ctrlPoint, Real** ctrlWeight, int uDegree, int vDegree, bool uLoop, bool vLoop, bool uOpen, bool vOpen);

		// (OU,ON) or (PU,ON)
		NURBSRectangle(int numUCtrlPoints, int numVCtrlPoints, Vector3D<Real>** ctrlPoint, Real** ctrlWeight, int uDegree, int vDegree, bool uLoop, bool vLoop, bool uOpen, Real* vKnot);

		// (ON,OU) or (ON,PU)
		NURBSRectangle(int numUCtrlPoints, int numVCtrlPoints,Vector3D<Real>** ctrlPoint, Real** ctrlWeight, int uDegree,int vDegree, bool uLoop, bool vLoop, Real* uKnot, bool vOpen);

		// (ON,ON)
		NURBSRectangle(int numUCtrlPoints, int numVCtrlPoints,Vector3D<Real>** ctrlPoint, Real** ctrlWeight, int uDegree,int vDegree, bool uLoop, bool vLoop, Real* uKnot, Real* vKnot);

		virtual ~NURBSRectangle();

		int GetNumCtrlPoints(int dim) const;
		int GetDegree(int dim) const;
		bool IsOpen(int dim) const;
		bool IsUniform(int dim) const;
		bool IsLoop(int dim) const;

		// Control points and weights may be changed at any time.  If either input
		// index is invalid, GetControlPoint returns a vector whose components
		// are all MAX_REAL, and GetControlWeight returns MAX_REAL.
		void SetControlPoint(int uIndex, int vIndex, const Vector3D<Real>& ctrl);
		Vector3D<Real> GetControlPoint(int uIndex, int vIndex) const;
		void SetControlWeight(int uIndex, int vIndex, Real weight);
		Real GetControlWeight(int uIndex, int vIndex) const;

		// The knot values can be changed only if the surface is nonuniform in the
		// selected dimension and only if the input index is valid.  If these
		// conditions are not satisfied, GetKnot returns MAX_REAL.
		void SetKnot(int dim, int i, Real knot);
		Real GetKnot(int dim, int i) const;

		// The spline is defined for 0 <= u <= 1 and 0 <= v <= 1.  The input
		// values should be in this domain.  Any inputs smaller than 0 are clamped
		// to 0.  Any inputs larger than 1 are clamped to 1.
		virtual Vector3D<Real> P(Real u, Real v) const;
		virtual Vector3D<Real> PU(Real u, Real v) const;
		virtual Vector3D<Real> PV(Real u, Real v) const;
		virtual Vector3D<Real> PUU(Real u, Real v) const;
		virtual Vector3D<Real> PUV(Real u, Real v) const;
		virtual Vector3D<Real> PVV(Real u, Real v) const;

		// If you need position and derivatives at the same time, it is more
		// efficient to call these functions.  Pass the addresses of those
		// quantities whose values you want.  You may pass 0 in any argument
		// whose value you do not want.
		void Get(Real u, Real v, Vector3D<Real>* pos, Vector3D<Real>* derU,Vector3D<Real>* derV, Vector3D<Real>* derUU, Vector3D<Real>* derUV,Vector3D<Real>* derVV) const;

	protected:
		// Replicate the necessary number of control points when the Create
		// function has bLoop equal to true, in which case the spline surface
		// must be a closed surface in the corresponding dimension.
		void CreateControl(Vector3D<Real>** ctrlPoint, Real** ctrlWeight);

		int mNumUCtrlPoints, mNumVCtrlPoints;
		Vector3D<Real>** mCtrlPoint;  // ctrl[unum][vnum]
		Real** mCtrlWeight;    // weight[unum][vnum]
		bool mLoop[2];
		BSplineBasis<Real> mBasis[2];
		int mUReplicate, mVReplicate;
	};

	using NURBSRectanglef = NURBSRectangle<float>;
	using NURBSRectangled = NURBSRectangle<double>;
}

#endif // MATHEMATICS_CURVES_SURFACES_VOLUMES_NURBS_RECTANGLE_H
