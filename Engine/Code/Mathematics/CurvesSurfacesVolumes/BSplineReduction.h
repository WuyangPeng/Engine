// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 17:58)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_REDUCTION_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_REDUCTION_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector2D.h"
#include "Mathematics/Algebra/Vector3D.h"

namespace Mathematics
{

template <typename Real, typename TVector>
class   BSplineReduction
{
public:
    // The input quantity numCtrlPoints must be 2 or larger.  The caller is
    // responsible for deleting the input array ctrlPoints and the output array
    // akCtrlOut.  The degree degree of the input curve must satisfy the
    // condition 1 <= degree <= numCtrlPoints-1.  The degree of the output
    // curve is the same as that of the input curve.  The value fraction
    // must be in [0,1].  If the fraction is 1, the output curve is identical
    // to the input curve.  If the fraction is too small to produce a valid
    // number of control points, the output control quantity is chosen to be
    // outNumCtrlPoints = degree+1.

    BSplineReduction (int numCtrlPoints, const TVector* ctrlPoints, int degree, Real fraction, int& outNumCtrlPoints, TVector*& outCtrlPoints);

    ~BSplineReduction ();

private:
    Real MinSupport (int basis, int i) const;
    Real MaxSupport (int basis, int i) const;
    Real F (int basis, int i, int j, Real t);
    static Real Integrand (Real t, const BSplineReduction* data);

    int mDegree;
    int m_Quantity[2];
    int mNumKnots[2];  // N+D+2
    Real* mKnot[2];

    // For the integration-based least-squares fitting.
    int mBasis[2], mIndex[2];
};

using BSplineReduction2f = BSplineReduction<float,FloatVector2D>;
using BSplineReduction2d = BSplineReduction<double,DoubleVector2D>;
using BSplineReduction3f = BSplineReduction<float,FloatVector3D>;
using BSplineReduction3d = BSplineReduction<double,DoubleVector3D>;

}

#endif // MATHEMATICS_CURVES_SURFACES_VOLUMES_BSPLINE_REDUCTION_H
