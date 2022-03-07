// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 11:16)

#ifndef MATHEMATICS_MESHES_CONFORMAL_MAP_DETAIL_H
#define MATHEMATICS_MESHES_CONFORMAL_MAP_DETAIL_H

#include "ConformalMap.h"

template <typename Real>
Mathematics::ConformalMap<Real>::ConformalMap(int numPoints, const Vector3<Real>* points, int numTriangles, const int* indices, int punctureTriangle)
{
    // Construct a vertex-triangle-edge representation of mesh.
    BasicMesh mesh(numPoints, points, numTriangles, indices);
    int numEdges = mesh.GetNumEdges();
    const BasicMesh::Edge* edges = mesh.GetEdges();
    const BasicMesh::Triangle* triangles = mesh.GetTriangles();

    mPlanes = nullptr;  // NEW1<Vector2<Real> >(numPoints);
    mSpheres = nullptr;  // NEW1<Vector3<Real> >(numPoints);

    // Construct sparse matrix A nondiagonal entries.
    typename LinearSystem<Real>::SparseMatrix AMat(numEdges, numEdges);
    int i, e, t, v0, v1, v2;
    Real value = Math<Real>::GetValue(0);
    for (e = 0; e < numEdges; ++e)
    {
        const BasicMesh::Edge& edge = edges[e];
        v0 = edge.V[0];
        v1 = edge.V[1];

        Vector3<Real> E0, E1;

        const BasicMesh::Triangle& T0 = triangles[edge.T[0]];
        for (i = 0; i < 3; ++i)
        {
            v2 = T0.V[i];
            if (v2 != v0 && v2 != v1)
            {
                E0 = points[v0] - points[v2];
                E1 = points[v1] - points[v2];
                value = Vector3Tools<Real>::DotProduct(E0, E1) /
                        Vector3Tools<Real>::GetLength(Vector3Tools<Real>::CrossProduct(E0, E1));
            }
        }

        const BasicMesh::Triangle& T1 = triangles[edge.T[1]];
        for (i = 0; i < 3; ++i)
        {
            v2 = T1.V[i];
            if (v2 != v0 && v2 != v1)
            {
                E0 = points[v0] - points[v2];
                E1 = points[v1] - points[v2];
                value += Vector3Tools<Real>::DotProduct(E0, E1) / Vector3Tools<Real>::GetLength(Vector3Tools<Real>::CrossProduct(E0, E1));
            }
        }

        value *= -Math::GetRational(1, 2);
        AMat(v0, v1) = value;
    }

    // Aonstruct sparse matrix A diagonal entries.
    Real* tmp = nullptr;  // NEW1<Real>(numPoints);
    memset(tmp, 0, numPoints * sizeof(Real));
    typename LinearSystem<Real>::SparseMatrix::ConstIter iter = AMat.begin();
    typename LinearSystem<Real>::SparseMatrix::ConstIter end = AMat.GetEnd();
    for (/**/; iter != end; ++iter)
    {
        v0 = iter.GetKey().GetRow();
        v1 = iter.GetKey().GetColumn();
        value = iter.GetMapped();
        MATHEMATICS_ASSERTION_0(v0 != v1, "Unexpected condition\n");
        tmp[v0] -= value;
        tmp[v1] -= value;
    }
    for (int v = 0; v < numPoints; ++v)
    {
        AMat(v, v) = tmp[v];
    }

    MATHEMATICS_ASSERTION_0(numPoints + numEdges == (int)AMat.GetRowsNumber(),
                            "Mismatch in sizes\n");

    // Construct column vector B (happens to be sparse).
    const BasicMesh::Triangle& tri = triangles[punctureTriangle];
    v0 = tri.V[0];
    v1 = tri.V[1];
    v2 = tri.V[2];
    Vector3<Real> V0 = points[v0];
    Vector3<Real> V1 = points[v1];
    Vector3<Real> V2 = points[v2];
    Vector3<Real> E10 = V1 - V0;
    Vector3<Real> E20 = V2 - V0;
    Vector3<Real> E12 = V1 - V2;
    Vector3<Real> cross = Vector3Tools<Real>::CrossProduct(E20, E10);
    Real len10 = Vector3Tools<Real>::GetLength(E10);
    Real invLen10 = (Math::GetValue(1)) / len10;
    Real twoArea = Vector3Tools<Real>::GetLength(cross);
    Real invLenCross = (Math::GetValue(1)) / twoArea;
    Real invProd = invLen10 * invLenCross;
    Real re0 = -invLen10;
    Real im0 = invProd * Vector3Tools<Real>::DotProduct(E12, E10);
    Real re1 = invLen10;
    Real im1 = invProd * Vector3Tools<Real>::DotProduct(E20, E10);
    Real re2 = Math<Real>::GetValue(0);
    Real im2 = -len10 * invLenCross;

    // Solve sparse system for real parts.
    memset(tmp, 0, numPoints * sizeof(Real));
    tmp[v0] = re0;
    tmp[v1] = re1;
    tmp[v2] = re2;
    Real* result = nullptr;  // NEW1<Real>(numPoints);
    try
    {
        LinearSystem<Real>().SolveSymmetricConjugateGradient(AMat, tmp, result);
    }
    catch (CoreTools::Error&)
    {
    }
    for (i = 0; i < numPoints; ++i)
    {
        mPlanes[i].SetX(result[i]);
    }

    // Solve sparse system for imaginary parts.
    memset(tmp, 0, numPoints * sizeof(Real));
    tmp[v0] = -im0;
    tmp[v1] = -im1;
    tmp[v2] = -im2;

    try
    {
        LinearSystem<Real>().SolveSymmetricConjugateGradient(AMat, tmp, result);
    }
    catch (CoreTools::Error&)
    {
    }

    for (i = 0; i < numPoints; ++i)
    {
        mPlanes[i].SetY(result[i]);
    }
    DELETE1(tmp);
    DELETE1(result);

    // Scale to [-1,1]^2 for numerical conditioning in later steps.
    Real fmin = mPlanes[0].GetX(), fmax = fmin;
    for (i = 0; i < numPoints; i++)
    {
        if (mPlanes[i].GetX() < fmin)
        {
            fmin = mPlanes[i].GetX();
        }
        else if (mPlanes[i].GetX() > fmax)
        {
            fmax = mPlanes[i].GetX();
        }
        if (mPlanes[i].GetY() < fmin)
        {
            fmin = mPlanes[i].GetY();
        }
        else if (mPlanes[i].GetY() > fmax)
        {
            fmax = mPlanes[i].GetY();
        }
    }
    Real halfRange = (Math::GetRational(1, 2)) * (fmax - fmin);
    Real invHalfRange = (Math::GetValue(1)) / halfRange;
    for (i = 0; i < numPoints; ++i)
    {
        mPlanes[i].SetX(-Math::GetValue(1) + invHalfRange * (mPlanes[i].GetX() - fmin));
        mPlanes[i].SetY(-Math::GetValue(1) + invHalfRange * (mPlanes[i].GetY() - fmin));
    }

    // Map plane points to sphere using inverse stereographic projection.
    // The main issue is selecting a translation in (x,y) and a radius of
    // the projection sphere.  Both factors strongly influence the final
    // result.

    // Use the average as the south pole.  The points tend to be clustered
    // approximately in the middle of the conformally mapped punctured
    // triangle, so the average is a good choice to place the pole.
    Vector2<Real> origin(Math<Real>::GetValue(0), Math<Real>::GetValue(0));
    for (i = 0; i < numPoints; ++i)
    {
        origin += mPlanes[i];
    }
    origin /= (Real)numPoints;
    for (i = 0; i < numPoints; ++i)
    {
        mPlanes[i] -= origin;
    }

    mPlaneMin = mPlanes[0];
    mPlaneMax = mPlanes[0];
    for (i = 1; i < numPoints; ++i)
    {
        if (mPlanes[i].GetX() < mPlaneMin.GetX())
        {
            mPlaneMin.SetX(mPlanes[i].GetX());
        }
        else if (mPlanes[i].GetX() > mPlaneMax.GetX())
        {
            mPlaneMax.SetX(mPlanes[i].GetX());
        }

        if (mPlanes[i].GetY() < mPlaneMin.GetY())
        {
            mPlaneMin.SetY(mPlanes[i].GetY());
        }
        else if (mPlanes[i].GetY() > mPlaneMax.GetY())
        {
            mPlaneMax.SetY(mPlanes[i].GetY());
        }
    }

    // Select the radius of the sphere so that the projected punctured
    // triangle has an area whose fraction of total spherical area is the
    // same fraction as the area of the punctured triangle to the total area
    // of the original triangle mesh.
    Real twoTotalArea = Math<Real>::GetValue(0);
    for (t = 0; t < numTriangles; ++t)
    {
        const BasicMesh::Triangle& T0 = triangles[t];
        const Vector3<Real>& V0 = points[T0.V[0]];
        const Vector3<Real>& V1 = points[T0.V[1]];
        const Vector3<Real>& V2 = points[T0.V[2]];
        Vector3<Real> E0 = V1 - V0, E1 = V2 - V0;
        twoTotalArea += Vector3Tools<Real>::GetLength(Vector3Tools<Real>::CrossProduct(E0, E1));
    }
    mRadius = ComputeRadius(mPlanes[v0], mPlanes[v1], mPlanes[v2], twoArea / twoTotalArea);
    Real radiusSqr = mRadius * mRadius;

    // Inverse stereographic projection to obtain sphere coordinates.  The
    // sphere is centered at the origin and has radius 1.
    for (i = 0; i < numPoints; i++)
    {
        Real rSqr = Vector3Tools<Real>::GetLengthSquared(mPlanes[i]);
        Real mult = (Math::GetValue(1)) / (rSqr + radiusSqr);
        Real x = (Math::GetValue(2)) * mult * radiusSqr * mPlanes[i].GetX();
        Real y = (Math::GetValue(2)) * mult * radiusSqr * mPlanes[i].GetY();
        Real z = mult * mRadius * (rSqr - radiusSqr);
        mSpheres[i] = Vector3<Real>(x, y, z) / mRadius;
    }
}

template <typename Real>
Mathematics::ConformalMap<Real>::~ConformalMap()
{
    DELETE1(mPlanes);
    DELETE1(mSpheres);
}

template <typename Real>
const Mathematics::Vector2<Real>* Mathematics::ConformalMap<Real>::GetPlaneCoordinates() const
{
    return mPlanes;
}

template <typename Real>
const Mathematics::Vector2<Real>& Mathematics::ConformalMap<Real>::GetPlaneMin() const
{
    return mPlaneMin;
}

template <typename Real>
const Mathematics::Vector2<Real>& Mathematics::ConformalMap<Real>::GetPlaneMax() const
{
    return mPlaneMax;
}

template <typename Real>
const Mathematics::Vector3<Real>* Mathematics::ConformalMap<Real>::GetSphereCoordinates() const
{
    return mSpheres;
}

template <typename Real>
Real Mathematics::ConformalMap<Real>::GetSphereRadius() const
{
    return mRadius;
}

template <typename Real>
Real Mathematics::ConformalMap<Real>::ComputeRadius(const Vector2<Real>& V0, const Vector2<Real>& V1, const Vector2<Real>& V2, Real areaFraction) const
{
    Real r0Sqr = Vector3Tools<Real>::GetLengthSquared(V0);
    Real r1Sqr = Vector3Tools<Real>::GetLengthSquared(V1);
    Real r2Sqr = Vector3Tools<Real>::GetLengthSquared(V2);
    Real diffR10 = r1Sqr - r0Sqr;
    Real diffR20 = r2Sqr - r0Sqr;
    Real diffX10 = V1.GetX() - V0.GetX();
    Real diffY10 = V1.GetY() - V0.GetY();
    Real diffX20 = V2.GetX() - V0.GetX();
    Real diffY20 = V2.GetY() - V0.GetY();
    Real diffRX10 = V1.GetX() * r0Sqr - V0.GetX() * r1Sqr;
    Real diffRY10 = V1.GetY() * r0Sqr - V0.GetY() * r1Sqr;
    Real diffRX20 = V2.GetX() * r0Sqr - V0.GetX() * r2Sqr;
    Real diffRY20 = V2.GetY() * r0Sqr - V0.GetY() * r2Sqr;

    Real c0 = diffR20 * diffRY10 - diffR10 * diffRY20;
    Real c1 = diffR20 * diffY10 - diffR10 * diffY20;
    Real d0 = diffR10 * diffRX20 - diffR20 * diffRX10;
    Real d1 = diffR10 * diffX20 - diffR20 * diffX10;
    Real e0 = diffRX10 * diffRY20 - diffRX20 * diffRY10;
    Real e1 = diffRX10 * diffY20 - diffRX20 * diffY10;
    Real e2 = diffX10 * diffY20 - diffX20 * diffY10;

    Polynomial<Real> poly0(6);
    poly0[0] = Math<Real>::GetValue(0);
    poly0[1] = Math<Real>::GetValue(0);
    poly0[2] = e0 * e0;
    poly0[3] = c0 * c0 + d0 * d0 + (Math::GetValue(2)) * e0 * e1;
    poly0[4] = (Math::GetValue(2)) * (c0 * c1 + d0 * d1 + e0 * e1) + e1 * e1;
    poly0[5] = c1 * c1 + d1 * d1 + (Math::GetValue(2)) * e1 * e2;
    poly0[6] = e2 * e2;

    Polynomial<Real> qpoly0(1), qpoly1(1), qpoly2(1);
    qpoly0[0] = r0Sqr;
    qpoly0[1] = Math::GetValue(1);
    qpoly1[0] = r1Sqr;
    qpoly1[1] = Math::GetValue(1);
    qpoly2[0] = r2Sqr;
    qpoly2[1] = Math::GetValue(1);

    Real tmp = areaFraction * Math<Real>::GetPI();
    Real amp = tmp * tmp;

    Polynomial<Real> poly1 = amp * qpoly0;
    poly1 = poly1 * qpoly0;
    poly1 = poly1 * qpoly0;
    poly1 = poly1 * qpoly0;
    poly1 = poly1 * qpoly1;
    poly1 = poly1 * qpoly1;
    poly1 = poly1 * qpoly2;
    poly1 = poly1 * qpoly2;

    Polynomial<Real> final = poly1 - poly0;
    MATHEMATICS_ASSERTION_0(final.GetDegree() <= 8, "Unexpected condition\n");

    // Bound a root near zero and apply bisection to find t.
    Real tmin = Math<Real>::GetValue(0), fmin = final(tmin);
    Real tmax = Math::GetValue(1), fmax = final(tmax);
    MATHEMATICS_ASSERTION_0(fmin > Math<Real>::GetValue(0) && fmax < Math<Real>::GetValue(0), "Unexpected condition\n");

    // Determine the number of iterations to get 'digits' of accuracy.
    const int digits = 6;
    Real tmp0 = Math<Real>::Log(tmax - tmin);
    Real tmp1 = ((Real)digits) * Math<Real>::Log(static_cast<Real>(10));
    Real arg = (tmp0 + tmp1) / Math<Real>::Log(Math::GetValue(2));
    int maxIter = (int)(arg + Math::GetRational(1, 2));
    Real tmid = Math<Real>::GetValue(0), fmid;
    for (int i = 0; i < maxIter; ++i)
    {
        tmid = (Math::GetRational(1, 2)) * (tmin + tmax);
        fmid = final(tmid);
        Real product = fmid * fmin;
        if (product < Math<Real>::GetValue(0))
        {
            tmax = tmid;
            fmax = fmid;
        }
        else
        {
            tmin = tmid;
            fmin = fmid;
        }
    }

    Real radius = Math<Real>::Sqrt(tmid);
    return radius;
}

#endif  // MATHEMATICS_MESHES_CONFORMAL_MAP_DETAIL_H