// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 11:18)

#ifndef MATHEMATICS_MESHES_MESH_SMOOTHER_DETAIL_H
#define MATHEMATICS_MESHES_MESH_SMOOTHER_DETAIL_H

#include "MeshSmoother.h"

template <typename Real>
Mathematics::MeshSmoother<Real>::MeshSmoother()
{
    mNumVertices = 0;
    mVertices = 0;
    mNumTriangles = 0;
    mIndices = 0;
    mNormals = 0;
    mMeans = 0;
    mNeighborCounts = 0;
}

template <typename Real>
Mathematics::MeshSmoother<Real>::MeshSmoother(int numVertices, Vector3D<Real>* vertices, int numTriangles, const int* indices)
{
    mVertices = 0;
    mNormals = 0;
    mIndices = 0;
    mMeans = 0;
    mNeighborCounts = 0;

    Create(numVertices, vertices, numTriangles, indices);
}

template <typename Real>
Mathematics::MeshSmoother<Real>::~MeshSmoother()
{
    Destroy();
}

template <typename Real>
void Mathematics::MeshSmoother<Real>::Create(int numVertices, Vector3D<Real>* vertices, int numTriangles, const int* indices)
{
    // Remove previously allocated smoother data.
    Destroy();

    mNumVertices = numVertices;
    mVertices = vertices;
    mNumTriangles = numTriangles;
    mIndices = indices;

    mNormals = nullptr;  //  NEW1<Vector3D<Real> >(mNumVertices);
    mMeans = nullptr;  // NEW1<Vector3D<Real> >(mNumVertices);
    mNeighborCounts = nullptr;  // NEW1<int>(mNumVertices);

    // Count the number of vertex neighbors.
    memset(mNeighborCounts, 0, mNumVertices * sizeof(int));
    const int* current = mIndices;
    for (int i = 0; i < mNumTriangles; ++i)
    {
        mNeighborCounts[*current++] += 2;
        mNeighborCounts[*current++] += 2;
        mNeighborCounts[*current++] += 2;
    }
}

template <typename Real>
void Mathematics::MeshSmoother<Real>::Destroy()
{
    //     DELETE1(mNormals);
    //     DELETE1(mMeans);
    //     DELETE1(mNeighborCounts);
}

template <typename Real>
void Mathematics::MeshSmoother<Real>::Update(Real t)
{
    memset(mNormals, 0, mNumVertices * sizeof(Vector3D<Real>));
    memset(mMeans, 0, mNumVertices * sizeof(Vector3D<Real>));

    const int* current = mIndices;
    int i;
    for (i = 0; i < mNumTriangles; ++i)
    {
        int v0 = *current++;
        int v1 = *current++;
        int v2 = *current++;

        Vector3D<Real>& V0 = mVertices[v0];
        Vector3D<Real>& V1 = mVertices[v1];
        Vector3D<Real>& V2 = mVertices[v2];

        Vector3D<Real> edge1 = V1 - V0;
        Vector3D<Real> edge2 = V2 - V0;
        Vector3D<Real> normal = Vector3DTools<Real>::CrossProduct(edge1, edge2);

        mNormals[v0] += normal;
        mNormals[v1] += normal;
        mNormals[v2] += normal;

        mMeans[v0] += V1 + V2;
        mMeans[v1] += V2 + V0;
        mMeans[v2] += V0 + V1;
    }

    for (i = 0; i < mNumVertices; ++i)
    {
        mNormals[i].Normalize();
        mMeans[i] /= (Real)mNeighborCounts[i];
    }

    for (i = 0; i < mNumVertices; ++i)
    {
        if (VertexInfluenced(i, t))
        {
            Vector3D<Real> localDiff = mMeans[i] - mVertices[i];
            Vector3D<Real> surfaceNormal = Vector3DTools<Real>::DotProduct(localDiff, mNormals[i]) * mNormals[i];
            Vector3D<Real> tangent = localDiff - surfaceNormal;

            Real tanWeight = GetTangentWeight(i, t);
            Real norWeight = GetNormalWeight(i, t);
            mVertices[i] += tanWeight * tangent + norWeight * mNormals[i];
        }
    }
}

template <typename Real>
bool Mathematics::MeshSmoother<Real>::VertexInfluenced(int, Real)
{
    return true;
}

template <typename Real>
Real Mathematics::MeshSmoother<Real>::GetTangentWeight(int, Real)
{
    return Real{ 0.5 };
}

template <typename Real>
Real Mathematics::MeshSmoother<Real>::GetNormalWeight(int, Real)
{
    return Real{ 0.0 };
}

template <typename Real>
int Mathematics::MeshSmoother<Real>::GetNumVertices() const
{
    return mNumVertices;
}

template <typename Real>
const Mathematics::Vector3D<Real>* Mathematics::MeshSmoother<Real>::GetVertices() const
{
    return mVertices;
}

template <typename Real>
int Mathematics::MeshSmoother<Real>::GetNumTriangles() const
{
    return mNumTriangles;
}

template <typename Real>
const int* Mathematics::MeshSmoother<Real>::GetIndices() const
{
    return mIndices;
}

template <typename Real>
const Mathematics::Vector3D<Real>* Mathematics::MeshSmoother<Real>::GetNormals() const
{
    return mNormals;
}

template <typename Real>
const Mathematics::Vector3D<Real>* Mathematics::MeshSmoother<Real>::GetMeans() const
{
    return mMeans;
}

#endif  // MATHEMATICS_MESHES_MESH_SMOOTHER_DETAIL_H