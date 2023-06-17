///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 10:22)

#ifndef MATHEMATICS_MISCELLANEOUS_PERS_PPROJ_ELLIPSOID_DETAIL_H
#define MATHEMATICS_MISCELLANEOUS_PERS_PPROJ_ELLIPSOID_DETAIL_H

#include "PerspProjEllipsoid.h"
#include "Mathematics/Objects2D/Ellipse2Detail.h"
#include "Mathematics/Objects3D/Ellipsoid3Detail.h"
#include "Mathematics/Objects3D/Plane3Detail.h"

template <typename Real>
void Mathematics::PerspProjEllipsoid<Real>::PerspectiveProjectEllipsoid(const Ellipsoid3<Real>& ellipsoid,
                                                                        const Vector3<Real>& eye,
                                                                        const Plane3<Real>& plane,
                                                                        const Vector3<Real>& u,
                                                                        const Vector3<Real>& v,
                                                                        Vector3<Real>& p,
                                                                        Ellipse2<Real>& ellipse)
{
    auto ellipsoid3Coefficients = ellipsoid.ToCoefficients();
    const auto a = ellipsoid3Coefficients.GetMatrix();
    const auto b = ellipsoid3Coefficients.GetVector();
    const auto c = ellipsoid3Coefficients.GetConstants();

    const auto ae = a * eye;
    auto eae = Vector3Tools<Real>::DotProduct(eye, ae);
    auto be = Vector3Tools<Real>::DotProduct(b, eye);
    auto quadE = (Math<Real>::GetValue(4)) * (eae + be + c);
    auto bp2AE = b + (Math<Real>::GetValue(2)) * ae;
    auto mat = Matrix3<Real>(bp2AE, bp2AE) - quadE * a;

    const auto mu = mat * u;
    const auto mv = mat * v;
    const auto mn = mat * plane.GetNormal();
    auto dmnde = -plane.DistanceTo(eye);
    p = eye + dmnde * plane.GetNormal();

    Matrix2<Real> aOut{};
    Vector2<Real> bOut{};
    Real cOut{};
    aOut[0][0] = Vector3Tools<Real>::DotProduct(u, mu);
    aOut[0][1] = Vector3Tools<Real>::DotProduct(u, mv);
    aOut[1][1] = Vector3Tools<Real>::DotProduct(v, mv);
    aOut[1][0] = aOut[0][1];
    bOut[0] = (Math<Real>::GetValue(2)) * dmnde * (Vector3Tools<Real>::DotProduct(u, mn));
    bOut[1] = (Math<Real>::GetValue(2)) * dmnde * (Vector3Tools<Real>::DotProduct(v, mn));
    cOut = dmnde * dmnde * (Vector3Tools<Real>::DotProduct(plane.GetNormal(), mn));

    Ellipse2Coefficients<Real> ellipsoid3Coefficients1{ aOut, bOut, cOut };
    ellipse.FromCoefficients(ellipsoid3Coefficients1);
}

#endif  // MATHEMATICS_MISCELLANEOUS_PERS_PPROJ_ELLIPSOID_DETAIL_H