// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 17:57)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_RECTANGLE_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_RECTANGLE_H

#include "BSplineBasis.h"
#include "ParametricSurface.h"

namespace Mathematics
{
    template <typename Real>
    class BSplineRectangle : public ParametricSurface<Real>
    {
    public: using Math = Math<Real>;
        // Construction and destruction.   The caller is responsible for deleting
        // the input arrays if they were dynamically allocated.  Internal copies
        // of the arrays are made, so to dynamically change control points or
        // knots you must use the 'SetControlPoint', 'GetControlPoint', and
        // 'Knot' member functions.

        // Spline types for curves are
        //   open uniform (OU)
        //   periodic uniform (PU)
        //   open nonuniform (ON)
        // For tensor product surfaces, you have to choose a type for each of two
        // dimensions, leading to nine possible spline types for surfaces.  The
        // constructors below represent these choices.

        // (OU,OU), (OU,PU), (PU,OU), or (PU,PU)
        BSplineRectangle(int numUCtrlPoints, int numVCtrlPoints, Vector3D<Real>** ctrlPoint, int uDegree, int vDegree, bool uLoop, bool vLoop, bool uOpen, bool vOpen);

        // (OU,ON) or (PU,ON)
        BSplineRectangle(int numUCtrlPoints, int numVCtrlPoints, Vector3D<Real>** ctrlPoint, int uDegree, int vDegree, bool uLoop, bool vLoop, bool uOpen, Real* vKnot);

        // (ON,OU) or (ON,PU)
        BSplineRectangle(int numUCtrlPoints, int numVCtrlPoints, Vector3D<Real>** ctrlPoint, int uDegree, int vDegree, bool uLoop, bool vLoop, Real* uKnot, bool vOpen);

        // (ON,ON)
        BSplineRectangle(int numUCtrlPoints, int numVCtrlPoints, Vector3D<Real>** ctrlPoint, int uDegree, int vDegree, bool uLoop, bool vLoop, Real* uKnot, Real* vKnot);

        ~BSplineRectangle();
        BSplineRectangle(const BSplineRectangle&) = default;
        BSplineRectangle& operator=(const BSplineRectangle&) = default;
        BSplineRectangle(BSplineRectangle&&) = default;
        BSplineRectangle& operator=(BSplineRectangle&&) = default;

        int GetNumCtrlPoints(int dim) const noexcept;
        int GetDegree(int dim) const noexcept;
        bool IsOpen(int dim) const noexcept;
        bool IsUniform(int dim) const;
        bool IsLoop(int dim) const noexcept;

        // Control points may be changed at any time.  If either input index is
        // invalid, GetControlPoint returns a vector whose components are all
        // MAX_REAL.
        void SetControlPoint(int uIndex, int vIndex, const Vector3D<Real>& ctrl);
        Vector3D<Real> GetControlPoint(int uIndex, int vIndex) const noexcept;

        // The knot values can be changed only if the surface is nonuniform in the
        // selected dimension and only if the input index is valid.  If these
        // conditions are not satisfied, GetKnot returns MAX_REAL.
        void SetKnot(int dim, int i, Real knot);
        Real GetKnot(int dim, int i) const;

        // The spline is defined for 0 <= u <= 1 and 0 <= v <= 1.  The input
        // values should be in this domain.  Any inputs smaller than 0 are clamped
        // to 0.  Any inputs larger than 1 are clamped to 1.
          Vector3D<Real> P(Real u, Real v) const override;
          Vector3D<Real> PU(Real u, Real v) const override;
          Vector3D<Real> PV(Real u, Real v) const override;
          Vector3D<Real> PUU(Real u, Real v) const override;
          Vector3D<Real> PUV(Real u, Real v) const override;
          Vector3D<Real> PVV(Real u, Real v) const override;

        // If you need position and derivatives at the same time, it is more
        // efficient to call these functions.  Pass the addresses of those
        // quantities whose values you want.  You may pass 0 in any argument
        // whose value you do not want.
        void Get(Real u, Real v, Vector3D<Real>* pos, Vector3D<Real>* derU, Vector3D<Real>* derV, Vector3D<Real>* derUU, Vector3D<Real>* derUV, Vector3D<Real>* derVV) const;

    protected:
        // Replicate the necessary number of control points when the Create
        // function has bLoop equal to true, in which case the spline surface
        // must be a closed surface in the corresponding dimension.
        void CreateControl(Vector3D<Real>** ctrlPoint);

        int mNumUCtrlPoints, mNumVCtrlPoints;
        Vector3D<Real>** mCtrlPoint;  // ctrl[unum][vnum]
        bool mLoop[2];
        BSplineBasis<Real> mBasis[2];
        int mUReplicate, mVReplicate;
    };

    using BSplineRectanglef = BSplineRectangle<float>;
    using BSplineRectangled = BSplineRectangle<double>;
}

#endif  // MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_RECTANGLE_H
