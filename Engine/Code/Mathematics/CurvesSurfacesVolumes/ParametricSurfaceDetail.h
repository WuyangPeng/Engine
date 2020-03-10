// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/17 19:06)

#ifndef MATHEMATICS_CURVES_SURFACES_VOLUMES_PARAMETRIC_SURFACE_DETAIL_H
#define MATHEMATICS_CURVES_SURFACES_VOLUMES_PARAMETRIC_SURFACE_DETAIL_H

#include "ParametricSurface.h"

namespace Mathematics
{

template <typename Real>
ParametricSurface<Real>::ParametricSurface (Real umin, Real umax, Real vmin, Real vmax, bool rectangular)
{
    MATHEMATICS_ASSERTION_0(umin < umax && vmin < vmax, "Invalid domain\n");

    mUMin = umin;
    mUMax = umax;
    mVMin = vmin;
    mVMax = vmax;
    mRectangular = rectangular;
}

template <typename Real>
ParametricSurface<Real>::~ParametricSurface ()
{
}

template <typename Real>
Real ParametricSurface<Real>::GetUMin () const
{
    return mUMin;
}

template <typename Real>
Real ParametricSurface<Real>::GetUMax () const
{
    return mUMax;
}

template <typename Real>
Real ParametricSurface<Real>::GetVMin () const
{
    return mVMin;
}

template <typename Real>
Real ParametricSurface<Real>::GetVMax () const
{
    return mVMax;
}

template <typename Real>
bool ParametricSurface<Real>::IsRectangular () const
{
    return mRectangular;
}

template <typename Real>
void ParametricSurface<Real>::GetFrame (Real u, Real v,Vector3D<Real>& position, Vector3D<Real>& tangent0, Vector3D<Real>& tangent1, Vector3D<Real>& normal) const
{
    position = P(u, v);

    tangent0 = PU(u, v);
    tangent1 = PV(u, v);
    tangent0.Normalize();  // T0
    tangent1.Normalize();  // temporary T1 just to compute N
	normal = Vector3DTools<Real>::CrossProduct(tangent0,tangent1);  // N

    // The normalized first derivatives are not necessarily orthogonal.
    // Recompute T1 so that {T0,T1,N} is an orthonormal set.
	tangent1 = Vector3DTools<Real>::CrossProduct(normal,tangent0);
}

template <typename Real>
void ParametricSurface<Real>::ComputePrincipalCurvatureInfo (Real u, Real v,Real& curv0, Real& curv1, Vector3D<Real>& dir0, Vector3D<Real>& dir1)
{
    // Tangents:  T0 = (x_u,y_u,z_u), T1 = (x_v,y_v,z_v)
    // Normal:    N = Cross(T0,T1)/Length(Cross(T0,T1))
    // Metric Tensor:    G = +-                      -+
    //                       | Dot(T0,T0)  Dot(T0,T1) |
    //                       | Dot(T1,T0)  Dot(T1,T1) |
    //                       +-                      -+
    //
    // Curvature Tensor:  B = +-                          -+
    //                        | -Dot(N,T0_u)  -Dot(N,T0_v) |
    //                        | -Dot(N,T1_u)  -Dot(N,T1_v) |
    //                        +-                          -+
    //
    // Principal curvatures k are the generalized eigenvalues of
    //
    //     Bw = kGw
    //
    // If k is a curvature and w=(a,b) is the corresponding solution to
    // Bw = kGw, then the principal direction as a 3D vector is d = a*U+b*V.
    //
    // Let k1 and k2 be the principal curvatures.  The mean curvature
    // is (k1+k2)/2 and the Gaussian curvature is k1*k2.

    // Compute derivatives.
	auto derU = PU(u,v);
	auto derV = PV(u,v);
	auto derUU = PUU(u,v);
	auto derUV = PUV(u,v);
	auto derVV = PVV(u,v);

    // Compute the metric tensor.
    Matrix2<Real> metricTensor;
	metricTensor[0][0] = Vector3DTools<Real>::DotProduct(derU,derU);
	metricTensor[0][1] = Vector3DTools<Real>::DotProduct(derU,derV);
    metricTensor[1][0] = metricTensor[0][1];
	metricTensor[1][1] = Vector3DTools<Real>::DotProduct(derV,derV);

    // Compute the curvature tensor.
	auto normal = Vector3DTools<Real>::CrossProduct(derU,derV);
    Matrix2<Real> curvatureTensor;
	curvatureTensor[0][0] = -Vector3DTools<Real>::DotProduct(normal,derUU);
	curvatureTensor[0][1] = -Vector3DTools<Real>::DotProduct(normal,derUV);
    curvatureTensor[1][0] = curvatureTensor[0][1];
	curvatureTensor[1][1] = -Vector3DTools<Real>::DotProduct(normal,derVV);

    // Characteristic polynomial is 0 = det(B-kG) = c2*k^2+c1*k+c0.
	auto c0 = curvatureTensor.Determinant();
	auto c1 = ((Real)2)*curvatureTensor[0][1]* metricTensor[0][1] -  curvatureTensor[0][0]*metricTensor[1][1] - curvatureTensor[1][1]*metricTensor[0][0];
	auto c2 = metricTensor.Determinant();

    // Principal curvatures are roots of characteristic polynomial.
	auto temp = Math<Real>::Sqrt(Math<Real>::FAbs(c1*c1 - ((Real)4)*c0*c2));
	auto mult = (Real{0.5})/c2;
    curv0 = -mult*(c1+temp);
    curv1 = mult*(-c1+temp);

    // Principal directions are solutions to (B-kG)w = 0,
    // w1 = (b12-k1*g12,-(b11-k1*g11)) OR (b22-k1*g22,-(b12-k1*g12)).
	auto a0 = curvatureTensor[0][1] - curv0*metricTensor[0][1];
	auto a1 = curv0*metricTensor[0][0] - curvatureTensor[0][0];
	auto length = Math<Real>::Sqrt(a0*a0 + a1*a1);
    if (length >= Math<Real>::sm_ZeroTolerance)
    {
        dir0 = a0*derU + a1*derV;
    }
    else
    {
        a0 = curvatureTensor[1][1] - curv0*metricTensor[1][1];
        a1 = curv0*metricTensor[0][1] - curvatureTensor[0][1];
        length = Math<Real>::Sqrt(a0*a0 + a1*a1);
        if (length >= Math<Real>::sm_ZeroTolerance)
        {
            dir0 = a0*derU + a1*derV;
        }
        else
        {
            // Umbilic (surface is locally sphere, any direction principal).
            dir0 = derU;
        }
    }
    dir0.Normalize();

    // Second tangent is cross product of first tangent and normal.
	dir1 = Vector3DTools<Real>::CrossProduct(dir0,normal);
}



}

#endif // MATHEMATICS_CURVES_SURFACES_VOLUMES_PARAMETRIC_SURFACE_DETAIL_H