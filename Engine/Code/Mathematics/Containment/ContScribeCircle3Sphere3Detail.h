///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:40)

#ifndef MATHEMATICS_CONTAINMENT_CONT_SCRIBE_CIRCLE3_SPHERE3_DETAIL_H
#define MATHEMATICS_CONTAINMENT_CONT_SCRIBE_CIRCLE3_SPHERE3_DETAIL_H

#include "ContScribeCircle3Sphere3.h"
#include "Mathematics/NumericalAnalysis/LinearSystem.h"

template <typename Real>
bool Mathematics::ContScribeCircle3Sphere3<Real>::Circumscribe(const Vector3<Real>& v0, const Vector3<Real>& v1, const Vector3<Real>& v2, Circle3<Real>& circle)
{
    auto e02 = v0 - v2;
    auto e12 = v1 - v2;
    auto e02e02 = Vector3Tools<Real>::DotProduct(e02, e02);
    auto e02e12 = Vector3Tools<Real>::DotProduct(e02, e12);
    auto e12e12 = Vector3Tools<Real>::DotProduct(e12, e12);
    auto det = e02e02 * e12e12 - e02e12 * e02e12;
    if (Math<Real>::FAbs(det) < Math<Real>::GetZeroTolerance())
    {
        return false;
    }

    auto halfInvDet = Math<Real>::GetRational(1, 2) / det;
    auto u0 = halfInvDet * e12e12 * (e02e02 - e02e12);
    auto u1 = halfInvDet * e02e02 * (e12e12 - e02e12);
    auto tmp = u0 * e02 + u1 * e12;

    auto center = v2 + tmp;
    auto radius = Vector3Tools<Real>::GetLength(tmp);

    const auto normal = Vector3Tools<Real>::UnitCrossProduct(e02, e12);
    Vector3<Real> direction0;

    if (Math<Real>::FAbs(normal.GetX()) >= Math<Real>::FAbs(normal.GetY()) && Math<Real>::FAbs(normal.GetX()) >= Math<Real>::FAbs(normal.GetZ()))
    {
        direction0.SetX(-normal.GetY());
        direction0.SetY(normal.GetX());
        direction0.SetZ(Math<Real>::GetValue(0));
    }
    else
    {
        direction0.SetX(Math<Real>::GetValue(0));
        direction0.SetY(normal.GetZ());
        direction0.SetZ(-normal.GetY());
    }

    direction0.Normalize();
    const auto direction1 = Vector3Tools<Real>::CrossProduct(normal, direction0);

    circle = Circle3<Real>{ center, direction0, direction1, normal, radius };

    return true;
}

template <typename Real>
bool Mathematics::ContScribeCircle3Sphere3<Real>::Circumscribe(const Vector3<Real>& v0, const Vector3<Real>& v1, const Vector3<Real>& v2, const Vector3<Real>& v3, Sphere3<Real>& sphere)
{
    auto e10 = v1 - v0;
    auto e20 = v2 - v0;
    auto e30 = v3 - v0;

    typename LinearSystem<Real>::Matrix3 a{ typename LinearSystem<Real>::Vector3{ e10.GetX(), e10.GetY(), e10.GetZ() },
                                            typename LinearSystem<Real>::Vector3{ e20.GetX(), e20.GetY(), e20.GetZ() },
                                            typename LinearSystem<Real>::Vector3{ e30.GetX(), e30.GetY(), e30.GetZ() } };

    const typename LinearSystem<Real>::Vector3 b{ Math<Real>::GetRational(1, 2) * Vector3Tools<Real>::GetLengthSquared(e10),
                                                  Math<Real>::GetRational(1, 2) * Vector3Tools<Real>::GetLengthSquared(e20),
                                                  Math<Real>::GetRational(1, 2) * Vector3Tools<Real>::GetLengthSquared(e30) };

    try
    {
        const auto solution = LinearSystem<Real>().Solve3(a, b);
        const Vector3<Real> result{ solution.at(0), solution.at(1), solution.at(2) };

        sphere.SetSphere(v0 + result, Vector3Tools<Real>::GetLength(result));

        return true;
    }
    catch (CoreTools::Error&)
    {
        return false;
    }
}

template <typename Real>
bool Mathematics::ContScribeCircle3Sphere3<Real>::Inscribe(const Vector3<Real>& v0, const Vector3<Real>& v1, const Vector3<Real>& v2, Circle3<Real>& circle)
{
    auto e0 = v1 - v0;
    auto e1 = v2 - v1;
    auto e2 = v0 - v2;

    auto normal = Vector3Tools<Real>::CrossProduct(e1, e0);

    const auto n0 = Vector3Tools<Real>::UnitCrossProduct(normal, e0);
    const auto n1 = Vector3Tools<Real>::UnitCrossProduct(normal, e1);
    const auto n2 = Vector3Tools<Real>::UnitCrossProduct(normal, e2);

    auto a0 = Vector3Tools<Real>::DotProduct(n1, e0);
    if (Math<Real>::FAbs(a0) < Math<Real>::GetZeroTolerance())
    {
        return false;
    }

    auto a1 = Vector3Tools<Real>::DotProduct(n2, e1);
    if (Math<Real>::FAbs(a1) < Math<Real>::GetZeroTolerance())
    {
        return false;
    }

    auto a2 = Vector3Tools<Real>::DotProduct(n0, e2);
    if (Math<Real>::FAbs(a2) < Math<Real>::GetZeroTolerance())
    {
        return false;
    }

    auto invA0 = (Math<Real>::GetValue(1)) / a0;
    auto invA1 = (Math<Real>::GetValue(1)) / a1;
    auto invA2 = (Math<Real>::GetValue(1)) / a2;

    auto radius = (Math<Real>::GetValue(1)) / (invA0 + invA1 + invA2);
    auto center = circle.GetRadius() * (invA0 * v0 + invA1 * v1 + invA2 * v2);

    normal.Normalize();
    const auto direction0 = n0;
    const auto direction1 = Vector3Tools<Real>::CrossProduct(normal, direction0);

    circle = Circle3<Real>{ center, direction0, direction1, normal, radius };

    return true;
}

template <typename Real>
bool Mathematics::ContScribeCircle3Sphere3<Real>::Inscribe(const Vector3<Real>& v0, const Vector3<Real>& v1, const Vector3<Real>& v2, const Vector3<Real>& v3, Sphere3<Real>& sphere)
{
    auto e10 = v1 - v0;
    auto e20 = v2 - v0;
    auto e30 = v3 - v0;
    auto e21 = v2 - v1;
    auto e31 = v3 - v1;

    auto n0 = Vector3Tools<Real>::CrossProduct(e31, e21);
    auto n1 = Vector3Tools<Real>::CrossProduct(e20, e30);
    auto n2 = Vector3Tools<Real>::CrossProduct(e30, e10);
    auto n3 = Vector3Tools<Real>::CrossProduct(e10, e20);

    if (Math<Real>::FAbs(Vector3Tools<Real>::GetLength(n0)) < Math<Real>::GetZeroTolerance())
    {
        return false;
    }
    n0.Normalize();
    if (Math<Real>::FAbs(Vector3Tools<Real>::GetLength(n1)) < Math<Real>::GetZeroTolerance())
    {
        return false;
    }
    n1.Normalize();
    if (Math<Real>::FAbs(Vector3Tools<Real>::GetLength(n2)) < Math<Real>::GetZeroTolerance())
    {
        return false;
    }
    n2.Normalize();
    if (Math<Real>::FAbs(Vector3Tools<Real>::GetLength(n3)) < Math<Real>::GetZeroTolerance())
    {
        return false;
    }
    n3.Normalize();

    typename LinearSystem<Real>::Matrix3 a{ typename LinearSystem<Real>::Vector3{ n1.GetX() - n0.GetX(), n1.GetY() - n0.GetY(), n1.GetZ() - n0.GetZ() },
                                            typename LinearSystem<Real>::Vector3{ n2.GetX() - n0.GetX(), n2.GetY() - n0.GetY(), n2.GetZ() - n0.GetZ() },
                                            typename LinearSystem<Real>::Vector3{ n3.GetX() - n0.GetX(), n3.GetY() - n0.GetY(), n3.GetZ() - n0.GetZ() } };

    const typename LinearSystem<Real>::Vector3 b{ Math<Real>::GetValue(0),
                                                  Math<Real>::GetValue(0),
                                                  -Vector3Tools<Real>::DotProduct(n3, e30) };

    try
    {
        const auto solution = LinearSystem<Real>().Solve3(a, b);
        const Vector3<Real> result{ solution.at(0), solution.at(1), solution.at(2) };

        sphere.SetSphere(v3 + result, Math<Real>::FAbs(Vector3Tools<Real>::DotProduct(n0, result)));

        return true;
    }
    catch (CoreTools::Error&)
    {
        return false;
    }
}

#endif  // MATHEMATICS_CONTAINMENT_CONT_SCRIBE_CIRCLE3_SPHERE3_DETAIL_H