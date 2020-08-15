// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 11:21)

#include "Mathematics/MathematicsExport.h"

#include "BasicMesh.h"
#include "EdgeKey.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/MemoryMacro.h"

#include "System/Helper/PragmaWarning.h"
#include <map>
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26486)
#include SYSTEM_WARNING_DISABLE(26488)
#include SYSTEM_WARNING_DISABLE(26489)
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26482)
Mathematics::BasicMesh ::BasicMesh(int numVertices, const void* points, int numTriangles, const int* indices)
{
    MATHEMATICS_ASSERTION_0(numVertices > 0 && numTriangles > 0 && indices, "Invalid input\n");

    if (numVertices <= 0 || numTriangles <= 0 || !indices)
    {
        mNumVertices = 0;
        mNumEdges = 0;
        mNumTriangles = 0;
        mVertices = 0;
        mEdges = 0;
        mTriangles = 0;
        mPoints = 0;
        mIndices = 0;
        mIsValid = false;
        return;
    }

    mNumVertices = numVertices;
    mNumEdges = 0;
    mNumTriangles = numTriangles;
    mPoints = points;
    mIndices = indices;
    mIsValid = true;

    // Dynamically construct triangle mesh from input.
    mVertices = NEW1<Vertex>(mNumVertices);
    mEdges = NEW1<Edge>(3 * mNumTriangles);
    mTriangles = NEW1<Triangle>(mNumTriangles);
    std::map<EdgeKey, int> edgeMap;
    for (int t = 0; t < mNumTriangles; t++)
    {
        // Update triangle.
        Triangle& tri = mTriangles[t];
        tri.V[0] = *indices++;
        tri.V[1] = *indices++;
        tri.V[2] = *indices++;

        // Add edges to mesh.
        for (int i0 = 2, i1 = 0; i1 < 3; i0 = i1++)
        {
            if (mVertices != nullptr && mTriangles != nullptr)
            {
                // Update vertices.
                mVertices[tri.V[i1]].InsertTriangle(t);

                const EdgeKey key(tri.V[i0], tri.V[i1]);
                const std::map<EdgeKey, int>::iterator eiter = edgeMap.find(key);
                if (eiter == edgeMap.end())
                {
                    // First time edge encountered.
                    edgeMap[key] = mNumEdges;

                    // Update edge.
                    Edge& edge = mEdges[mNumEdges];
                    edge.V[0] = tri.V[i0];
                    edge.V[1] = tri.V[i1];
                    edge.T[0] = t;

                    // Update vertices.
                    mVertices[edge.V[0]].InsertEdge(edge.V[1],
                                                    mNumEdges);
                    mVertices[edge.V[1]].InsertEdge(edge.V[0],
                                                    mNumEdges);

                    // Update triangle.
                    tri.E[i0] = mNumEdges;

                    ++mNumEdges;
                }
                else
                {
                    // Second time edge encountered.
                    int e = eiter->second;
                    Edge& edge = mEdges[e];

                    // update edge
                    MATHEMATICS_ASSERTION_0(edge.T[1] == -1, "Mesh must be manifold\n");
                    if (edge.T[1] != -1)
                    {
                        DELETE1(mVertices);
                        DELETE1(mEdges);
                        DELETE1(mTriangles);
                        mNumVertices = 0;
                        mNumEdges = 0;
                        mNumTriangles = 0;
                        mVertices = 0;
                        mEdges = 0;
                        mTriangles = 0;
                        mPoints = 0;
                        mIndices = 0;
                        mIsValid = false;
                    }
                    edge.T[1] = t;

                    // Update triangles.
                    int a = edge.T[0];
                    if (mTriangles != nullptr)
                    {
                        Triangle& adj = mTriangles[a];
                        for (int j = 0; j < 3; ++j)
                        {
                            if (adj.E[j] == e)
                            {
                                adj.T[j] = t;
                                break;
                            }
                        }
                        tri.E[i0] = e;
                        tri.T[i0] = a;
                    }
                }
            }
        }
    }
}

Mathematics::BasicMesh ::~BasicMesh(){
    EXCEPTION_TRY{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26447)
        DELETE1(mVertices);
DELETE1(mEdges);
DELETE1(mTriangles);
#include STSTEM_WARNING_POP
}
EXCEPTION_ALL_CATCH(Mathematics)
}

// BasicMesh::Vertex

Mathematics::BasicMesh::Vertex ::Vertex() noexcept
    : NumVertices(0), V(0), E(0), NumTriangles(0), T(0)
{
}

Mathematics::BasicMesh::Vertex ::~Vertex()
{
    EXCEPTION_TRY
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26447)
        DELETE1(V);
        DELETE1(E);
        DELETE1(T);
#include STSTEM_WARNING_POP
    }
    EXCEPTION_ALL_CATCH(Mathematics)
}

void Mathematics::BasicMesh::Vertex ::InsertEdge(int v, int e)
{
    // Check whether vertex/edge in adjacency array (nothing to do if in
    // array).
    for (int i = 0; i < NumVertices; ++i)
    {
        if (v == V[i])
        {
            return;
        }
    }

    if ((NumVertices % MV_CHUNK) == 0)
    {
        int* save = V;
        V = NEW1<int>(NumVertices + MV_CHUNK);
        if (save)
        {
            memcpy(V, save, NumVertices * sizeof(int));
            DELETE1(save);
        }

        save = E;
        E = NEW1<int>(NumVertices + MV_CHUNK);
        if (save)
        {
            memcpy(E, save, NumVertices * sizeof(int));
            DELETE1(save);
        }
    }

    V[NumVertices] = v;
    E[NumVertices] = e;
    ++NumVertices;
}

void Mathematics::BasicMesh::Vertex ::InsertTriangle(int t)
{
    // Check whether triangle in adjacency array (nothing to do if in array).
    for (int i = 0; i < NumTriangles; ++i)
    {
        if (t == T[i])
        {
            return;
        }
    }

    if ((NumTriangles % MV_CHUNK) == 0)
    {
        int* save = T;
        T = NEW1<int>(NumTriangles + MV_CHUNK);
        if (save)
        {
            memcpy(T, save, NumTriangles * sizeof(int));
            DELETE1(save);
        }
    }

    T[NumTriangles] = t;
    ++NumTriangles;
}

// BasicMesh::Edge

Mathematics::BasicMesh::Edge ::Edge() noexcept
    : V{}, T{}
{
    for (int i = 0; i < 2; ++i)
    {
        V[i] = -1;
        T[i] = -1;
    }
}

// BasicMesh::Triangle

Mathematics::BasicMesh::Triangle ::Triangle() noexcept
    : E{}, V{}, T{}
{
    for (int i = 0; i < 3; ++i)
    {
        V[i] = -1;
        E[i] = -1;
        T[i] = -1;
    }
}

bool Mathematics::BasicMesh ::IsValid() const noexcept
{
    return mIsValid;
}

int Mathematics::BasicMesh ::GetNumVertices() const noexcept
{
    return mNumVertices;
}

int Mathematics::BasicMesh ::GetNumEdges() const noexcept
{
    return mNumEdges;
}

int Mathematics::BasicMesh ::GetNumTriangles() const noexcept
{
    return mNumTriangles;
}

const void* Mathematics::BasicMesh ::GetPoints() const noexcept
{
    return mPoints;
}

const int* Mathematics::BasicMesh ::GetIndices() const noexcept
{
    return mIndices;
}

const Mathematics::BasicMesh::Vertex* Mathematics::BasicMesh ::GetVertices() const noexcept
{
    return mVertices;
}

const Mathematics::BasicMesh::Edge* Mathematics::BasicMesh ::GetEdges() const noexcept
{
    return mEdges;
}

const Mathematics::BasicMesh::Triangle* Mathematics::BasicMesh ::GetTriangles() const noexcept
{
    return mTriangles;
}

#include STSTEM_WARNING_POP