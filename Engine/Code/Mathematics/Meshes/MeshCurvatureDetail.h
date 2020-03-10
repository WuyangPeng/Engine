// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 11:17)

#ifndef MATHEMATICS_MESHES_MESH_CURVATURE_DETAIL_H
#define MATHEMATICS_MESHES_MESH_CURVATURE_DETAIL_H

#include "MeshCurvature.h"
#include "CoreTools/Helper/MemoryMacro.h"

template <typename Real>
Mathematics::MeshCurvature<Real>
	::MeshCurvature (int numVertices,const Vector3D<Real>* vertices, int numTriangles, const int* indices)
{
    mNumVertices = numVertices;
    mVertices = vertices;
    mNumTriangles = numTriangles;
    mIndices = indices;

    // Compute normal vectors.
    mNormals = NEW1<Vector3D<Real> >(mNumVertices);
    memset(mNormals, 0, mNumVertices*sizeof(Vector3D<Real>));
    int i, v0, v1, v2;
    for (i = 0; i < mNumTriangles; ++i)
    {
        // Get vertex indices.
        v0 = *indices++;
        v1 = *indices++;
        v2 = *indices++;

        // Compute the normal (length provides a weighted sum).
        Vector3D<Real> edge1 = mVertices[v1] - mVertices[v0];
        Vector3D<Real> edge2 = mVertices[v2] - mVertices[v0];
        Vector3D<Real> normal = Vector3DTools<Real>::CrossProduct(edge1,edge2);

        mNormals[v0] += normal;
        mNormals[v1] += normal;
        mNormals[v2] += normal;
    }
    for (i = 0; i < mNumVertices; ++i)
    {
        mNormals[i].Normalize();
    }

    // Compute the matrix of normal derivatives.
    Matrix3<Real>* DNormal = NEW1<Matrix3<Real> >(mNumVertices);
    Matrix3<Real>* WWTrn = NEW1<Matrix3<Real> >(mNumVertices);
    Matrix3<Real>* DWTrn = NEW1<Matrix3<Real> >(mNumVertices);
    bool* DWTrnZero = NEW1<bool>(mNumVertices);
    memset(WWTrn, 0, mNumVertices*sizeof(Matrix3<Real>));
    memset(DWTrn, 0, mNumVertices*sizeof(Matrix3<Real>));
    memset(DWTrnZero, 0, mNumVertices*sizeof(bool));

    int row, col;
    indices = mIndices;
    for (i = 0; i < mNumTriangles; ++i)
    {
        // Get vertex indices.
        int V[3];
        V[0] = *indices++;
        V[1] = *indices++;
        V[2] = *indices++;

        for (int j = 0; j < 3; j++)
        {
            v0 = V[j];
            v1 = V[(j+1)%3];
            v2 = V[(j+2)%3];

            // Compute edge from V0 to V1, project to tangent plane of vertex,
            // and compute difference of adjacent normals.
            Vector3D<Real> E = mVertices[v1] - mVertices[v0];
            Vector3D<Real> W = E - (Vector3DTools<Real>::DotProduct(E,mNormals[v0]))*mNormals[v0];
            Vector3D<Real> D = mNormals[v1] - mNormals[v0];
            for (row = 0; row < 3; ++row)
            {
                for (col = 0; col < 3; ++col)
                {
                    WWTrn[v0][row][col] += W[row]*W[col];
                    DWTrn[v0][row][col] += D[row]*W[col];
                }
            }

            // Compute edge from V0 to V2, project to tangent plane of vertex,
            // and compute difference of adjacent normals.
            E = mVertices[v2] - mVertices[v0];
            W = E - (Vector3DTools<Real>::DotProduct(E,mNormals[v0]))*mNormals[v0];
            D = mNormals[v2] - mNormals[v0];
            for (row = 0; row < 3; ++row)
            {
                for (col = 0; col < 3; ++col)
                {
                    WWTrn[v0][row][col] += W[row]*W[col];
                    DWTrn[v0][row][col] += D[row]*W[col];
                }
            }
        }
    }

    // Add in N*N^T to W*W^T for numerical stability.  In theory 0*0^T gets
    // added to D*W^T, but of course no update is needed in the
    // implementation.  Compute the matrix of normal derivatives.
    for (i = 0; i < mNumVertices; ++i)
    {
        for (row = 0; row < 3; ++row)
        {
            for (col = 0; col < 3; ++col)
            {
                WWTrn[i][row][col] = (Real{0.5})*WWTrn[i][row][col] +
                    mNormals[i][row]*mNormals[i][col];
                DWTrn[i][row][col] *= Real{0.5};
            }
        }

        // Compute the max-abs entry of D*W^T.  If this entry is (nearly)
        // zero, flag the DNormal matrix as singular.
        Real maxAbs = Real{};
        for (row = 0; row < 3; ++row)
        {
            for (col = 0; col < 3; ++col)
            {
                Real absEntry = Math<Real>::FAbs(DWTrn[i][row][col]);
                if (absEntry > maxAbs)
                {
                    maxAbs = absEntry;
                }
            }
        }
        if (maxAbs < (Real)1e-07)
        {
            DWTrnZero[i] = true;
        }

        DNormal[i] = DWTrn[i]*WWTrn[i].Inverse();
    }

    DELETE1(WWTrn);
    DELETE1(DWTrn);

    // If N is a unit-length normal at a vertex, let U and V be unit-length
    // tangents so that {U, V, N} is an orthonormal set.  Define the matrix
    // J = [U | V], a 3-by-2 matrix whose columns are U and V.  Define J^T
    // to be the transpose of J, a 2-by-3 matrix.  Let dN/dX denote the
    // matrix of first-order derivatives of the normal vector field.  The
    // shape matrix is
    //   S = (J^T * J)^{-1} * J^T * dN/dX * J = J^T * dN/dX * J
    // where the superscript of -1 denotes the inverse.  (The formula allows
    // for J built from non-perpendicular vectors.) The matrix S is 2-by-2.
    // The principal curvatures are the eigenvalues of S.  If k is a principal
    // curvature and W is the 2-by-1 eigenvector corresponding to it, then
    // S*W = k*W (by definition).  The corresponding 3-by-1 tangent vector at
    // the vertex is called the principal direction for k, and is J*W.
    mMinCurvatures = NEW1<Real>(mNumVertices);
    mMaxCurvatures = NEW1<Real>(mNumVertices);
    mMinDirections = NEW1<Vector3D<Real> >(mNumVertices);
    mMaxDirections = NEW1<Vector3D<Real> >(mNumVertices);
    for (i = 0; i < mNumVertices; ++i)
    {
        // Compute U and V given N.
        Vector3D<Real> U, V;
		Vector3DOrthonormalBasis<Real> vector3DOrthonormalBasis =
        Vector3DTools<Real>::GenerateComplementBasis(mNormals[i]);
		U = vector3DOrthonormalBasis.GetUVector();
		V = vector3DOrthonormalBasis.GetVVector();

        if (DWTrnZero[i])
        {
            // At a locally planar point.
            mMinCurvatures[i] = Real{};
            mMaxCurvatures[i] = Real{};
            mMinDirections[i] = U;
            mMaxDirections[i] = V;
            continue;
        }

        // Compute S = J^T * dN/dX * J.  In theory S is symmetric, but
        // because we have estimated dN/dX, we must slightly adjust our
        // calculations to make sure S is symmetric.
        Real s01 = Vector3DTools<Real>::DotProduct(U,DNormal[i]*V);
        Real s10 = Vector3DTools<Real>::DotProduct(V,DNormal[i]*U);
        Real sAvr = (Real{0.5})*(s01 + s10);
        Matrix2<Real> S
        (
            Vector3DTools<Real>::DotProduct(U,DNormal[i]*U), sAvr,
            sAvr, Vector3DTools<Real>::DotProduct(V,DNormal[i]*V)
        );

        // Compute the eigenvalues of S (min and max curvatures).
        Real trace = S[0][0] + S[1][1];
        Real det = S[0][0]*S[1][1] - S[0][1]*S[1][0];
        Real discr = trace*trace - ((Real)4.0)*det;
        Real rootDiscr = Math<Real>::Sqrt(Math<Real>::FAbs(discr));
        mMinCurvatures[i] = (Real{0.5})*(trace - rootDiscr);
        mMaxCurvatures[i] = (Real{0.5})*(trace + rootDiscr);

        // Compute the eigenvectors of S.
        Vector2D<Real> W0(S[0][1], mMinCurvatures[i] - S[0][0]);
        Vector2D<Real> W1(mMinCurvatures[i] - S[1][1], S[1][0]);
        if ( Vector2DTools<Real>::VectorMagnitudeSquared(W0) >= Vector2DTools<Real>::VectorMagnitudeSquared(W1))
        {
            W0.Normalize();
            mMinDirections[i] = W0.GetXCoordinate()*U + W0.GetYCoordinate()*V;
        }
        else
        {
            W1.Normalize();
            mMinDirections[i] = W1.GetXCoordinate()*U + W1.GetYCoordinate()*V;
        }

        W0 = Vector2D<Real>(S[0][1], mMaxCurvatures[i] - S[0][0]);
        W1 = Vector2D<Real>(mMaxCurvatures[i] - S[1][1], S[1][0]);
        if (Vector2DTools<Real>::VectorMagnitudeSquared(W0) >= Vector2DTools<Real>::VectorMagnitudeSquared(W1))
        {
            W0.Normalize();
            mMaxDirections[i] = W0.GetXCoordinate()*U + W0.GetYCoordinate()*V;
        }
        else
        {
            W1.Normalize();
            mMaxDirections[i] = W1.GetXCoordinate()*U + W1.GetYCoordinate()*V;
        }
    }

    DELETE1(DWTrnZero);
    DELETE1(DNormal);
}

template <typename Real>
Mathematics::MeshCurvature<Real>
	::~MeshCurvature ()
{
    DELETE1(mNormals);
    DELETE1(mMinCurvatures);
    DELETE1(mMaxCurvatures);
    DELETE1(mMinDirections);
    DELETE1(mMaxDirections);
}

template <typename Real>
int Mathematics::MeshCurvature<Real>
	::GetNumVertices () const
{
    return mNumVertices;
}

template <typename Real>
const Mathematics::Vector3D<Real>* Mathematics::MeshCurvature<Real>
	::GetVertices () const
{
    return mVertices;
}

template <typename Real>
int Mathematics::MeshCurvature<Real>
	::GetNumTriangles () const
{
    return mNumTriangles;
}

template <typename Real>
const int* Mathematics::MeshCurvature<Real>
	::GetIndices () const
{
    return mIndices;
}

template <typename Real>
const Mathematics::Vector3D<Real>* Mathematics::MeshCurvature<Real>
	::GetNormals () const
{
    return mNormals;
}

template <typename Real>
const Real* Mathematics::MeshCurvature<Real>
	::GetMinCurvatures () const
{
    return mMinCurvatures;
}

template <typename Real>
const Real* Mathematics::MeshCurvature<Real>
	::GetMaxCurvatures () const
{
    return mMaxCurvatures;
}

template <typename Real>
const Mathematics::Vector3D<Real>* Mathematics::MeshCurvature<Real>
	::GetMinDirections () const
{
    return mMinDirections;
}

template <typename Real>
const Mathematics::Vector3D<Real>* Mathematics::MeshCurvature<Real>
	::GetMaxDirections () const
{
    return mMaxDirections;
}

#endif // MATHEMATICS_MESHES_MESH_CURVATURE_DETAIL_H