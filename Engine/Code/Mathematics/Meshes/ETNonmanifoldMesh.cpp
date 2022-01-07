// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 11:43)

#include "Mathematics/MathematicsExport.h"

#include "ETNonmanifoldMesh.h"

#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include <gsl/util>
#include <fstream>
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26482)
#include SYSTEM_WARNING_DISABLE(26486)
#include SYSTEM_WARNING_DISABLE(26487)
#include SYSTEM_WARNING_DISABLE(26489)
#include SYSTEM_WARNING_DISABLE(26409)
#include SYSTEM_WARNING_DISABLE(26402)
#include SYSTEM_WARNING_DISABLE(26429)
Mathematics::ETNonmanifoldMesh ::ETNonmanifoldMesh(ECreator eCreator, TCreator tCreator) noexcept
{
    mECreator = (eCreator ? eCreator : CreateEdge);
    mTCreator = (tCreator ? tCreator : CreateTriangle);
}

Mathematics::ETNonmanifoldMesh ::~ETNonmanifoldMesh(){
    EXCEPTION_TRY{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26447)
        EMapIterator eiter = mEMap.begin();
const EMapIterator eend = mEMap.end();
for (/**/; eiter != eend; ++eiter)
{
    //  Edge* edge = eiter->second;
    //DELETE0(edge);
}

TMapIterator titer = mTMap.begin();
const TMapIterator tend = mTMap.end();
for (/**/; titer != tend; ++titer)
{
    //  Triangle* tri = titer->second;
    // DELETE0(tri);
}
#include STSTEM_WARNING_POP
}
EXCEPTION_ALL_CATCH(Mathematics)
}

Mathematics::ETNonmanifoldMesh::EPtr Mathematics::ETNonmanifoldMesh ::CreateEdge(int v0, int v1)
{
    v0;
    v1;
    return nullptr;  //    NEW0 Edge(v0, v1);
}

Mathematics::ETNonmanifoldMesh::TPtr Mathematics::ETNonmanifoldMesh ::CreateTriangle(int v0, int v1, int v2)
{
    v0;
    v1;
    v2;
    return nullptr;  // NEW0 Triangle(v0, v1, v2);
}

Mathematics::ETNonmanifoldMesh::TPtr Mathematics::ETNonmanifoldMesh ::InsertTriangle(int v0, int v1, int v2)
{
    const TriangleKey tKey(v0, v1, v2);
    const TMapIterator titer = mTMap.find(tKey);
    if (titer != mTMap.end())
    {
        // Triangle already exists.
        return 0;
    }

    // Add new triangle.
    TPtr tri = mTCreator(v0, v1, v2);
    mTMap[tKey] = tri;

    // Add edges to mesh.
    for (int i0 = 2, i1 = 0; i1 < 3; i0 = i1++)
    {
        const EdgeKey eKey(tri->V[i0], tri->V[i1]);
        EPtr edge = nullptr;
        const EMapIterator eiter = mEMap.find(eKey);
        if (eiter == mEMap.end())
        {
            // First time edge encountered.
            edge = mECreator(tri->V[i0], tri->V[i1]);
            mEMap[eKey] = edge;
        }
        else
        {
            // Edge previously encountered and created.
            edge = eiter->second;
        }

        // Update edge and triangle.
        edge->T.insert(tri);
        tri->E[i0] = edge;
    }

    return tri;
}

bool Mathematics::ETNonmanifoldMesh ::RemoveTriangle(int v0, int v1, int v2)
{
    const TriangleKey tKey(v0, v1, v2);
    const TMapIterator titer = mTMap.find(tKey);
    if (titer == mTMap.end())
    {
        // Triangle does not exist.
        return false;
    }

    TPtr tri = titer->second;
    for (int i = 0; i < 3; ++i)
    {
        // Inform edges you are going away.
        EPtr edge = tri->E[i];
        edge->T.erase(tri);

        // Remove edge if you had the last reference to it.
        if (edge->T.size() == 0)
        {
            const EdgeKey eKey(edge->V[0], edge->V[1]);
            mEMap.erase(eKey);
            // DELETE0(edge);
        }
    }

    mTMap.erase(tKey);
    // DELETE0(tri);
    return true;
}

bool Mathematics::ETNonmanifoldMesh ::IsManifold() const noexcept
{
    EMapCIterator eiter = mEMap.begin();
    const EMapCIterator eend = mEMap.end();
    for (/**/; eiter != eend; ++eiter)
    {
        if (eiter->second->T.size() > 2)
        {
            return false;
        }
    }
    return true;
}

bool Mathematics::ETNonmanifoldMesh ::IsClosed() const noexcept
{
    EMapCIterator eiter = mEMap.begin();
    const EMapCIterator eend = mEMap.end();
    for (/**/; eiter != eend; ++eiter)
    {
        if (eiter->second->T.size() != 2)
        {
            return false;
        }
    }
    return true;
}

bool Mathematics::ETNonmanifoldMesh ::IsConnected() const
{
    // Perform a breadth-first search to locate the connected component
    // containing the first triangle in the triangle map.
    if (mTMap.begin() == mTMap.end())
    {
        // No triangles in the mesh, by default mesh is connected.
        return true;
    }

    // Start search at first triangle in mesh.
    std::set<Triangle*> component, boundary;
    boundary.insert(mTMap.begin()->second);

    while (boundary.size() > 0)
    {
        std::set<Triangle*> exterior;

        // Process boundary triangles.
        std::set<Triangle*>::iterator titer = boundary.begin();
        const std::set<Triangle*>::iterator tend = boundary.end();
        for (/**/; titer != tend; ++titer)
        {
            // Boundary triangle is adjacent to current connected component.
            TPtr tri = *titer;
            component.insert(tri);

            // Locate adjacent, exterior triangles for later processing.
            for (int i = 0; i < 3; ++i)
            {
                EPtr edge = tri->E[i];
                std::set<Triangle*>::const_iterator aiter =
                    edge->T.begin();
                const std::set<Triangle*>::const_iterator aend =
                    edge->T.end();
                for (/**/; aiter != aend; ++aiter)
                {
                    if (*aiter != tri && component.find(*aiter) == component.end() && boundary.find(*aiter) == boundary.end())
                    {
                        exterior.insert(*aiter);
                    }
                }
            }
        }

        // Exterior triangles are next in line to be processed.
        boundary = exterior;
    }

    return component.size() == mTMap.size();
}

void Mathematics::ETNonmanifoldMesh ::RemoveComponent(int& numIndices, int* indices)
{
    // Do a breadth-first search of the mesh to find connected components.
    // The input array is assumed to be large enough to hold the component.
    // (See the comments in ETNonmanifoldMesh.h for RemoveComponent.)
    numIndices = 0;

    if (mTMap.size() == 0)
    {
        return;
    }

    // Find the connected component containing the first triangle in the mesh.
    std::set<Triangle*> visited;
    visited.insert(mTMap.begin()->second);

    // Traverse the connected component.
    while (!visited.empty())
    {
        // Start at the current triangle.
        Triangle* tri = *visited.begin();

        // Add adjacent triangles to the set for recursive processing.
        for (int i = 0; i < 3; ++i)
        {
            EPtr edge = tri->E[i];
            std::set<Triangle*>::const_iterator aiter = edge->T.begin();
            const std::set<Triangle*>::const_iterator aend = edge->T.end();
            for (/**/; aiter != aend; ++aiter)
            {
                if (*aiter != tri)
                {
                    visited.insert(*aiter);
                }
            }
        }

        // Add triangle to connectivity array.
        indices[numIndices++] = tri->V[0];
        indices[numIndices++] = tri->V[1];
        indices[numIndices++] = tri->V[2];

        // Remove the current triangle (visited, no longer needed).
        visited.erase(tri);
        RemoveTriangle(tri->V[0], tri->V[1], tri->V[2]);
    }
}

void Mathematics::ETNonmanifoldMesh ::Print(const char* filename)
{
    std::ofstream outfile(filename);
    if (!outfile)
    {
        return;
    }

    // Assign unique indices to the edges.
    std::map<Edge*, int> eIndex;
    eIndex[(Edge*)0] = 0;
    int i = 1;
    EMapIterator eiter = mEMap.begin();
    EMapIterator eend = mEMap.end();
    for (/**/; eiter != eend; ++eiter)
    {
        if (eiter->second)
        {
            eIndex[eiter->second] = i;
            ++i;
        }
    }

    // Assign unique indices to the triangles.
    std::map<Triangle*, int> tIndex;
    Triangle* triNull{};
    tIndex[triNull] = 0;
    i = 1;
    TMapIterator titer = mTMap.begin();
    TMapIterator tend = mTMap.end();
    for (/**/; titer != tend; ++titer)
    {
        if (titer->second)
        {
            tIndex[titer->second] = i;
            ++i;
        }
    }

    // Print edges.
    outfile << "edge quantity = " << mEMap.size() << std::endl;
    eiter = mEMap.begin();
    eend = mEMap.end();
    for (/**/; eiter != eend; ++eiter)
    {
        Edge* edge = eiter->second;
        outfile << 'e' << eIndex[edge] << " <"
                << 'v' << edge->V[0] << ",v" << edge->V[1] << "; ";

        std::set<Triangle*>::const_iterator aiter = edge->T.begin();
        const std::set<Triangle*>::const_iterator aend = edge->T.end();
        for (/**/; aiter != aend; ++aiter)
        {
            outfile << 't' << tIndex[*aiter] << ',';
        }
        outfile << '>' << std::endl;
    }
    outfile << std::endl;

    // Print triangles.
    outfile << "triangle quantity = " << mTMap.size() << std::endl;
    titer = mTMap.begin();
    tend = mTMap.end();
    for (/**/; titer != tend; ++titer)
    {
        Triangle* tri = titer->second;
        outfile << 't' << tIndex[tri] << " <"
                << 'v' << tri->V[0] << ",v" << tri->V[1] << ",v"
                << tri->V[2] << "; ";
        if (tri->E[0])
        {
            outfile << 'e' << eIndex[tri->E[0]];
        }
        else
        {
            outfile << '*';
        }
        outfile << ',';
        if (tri->E[1])
        {
            outfile << 'e' << eIndex[tri->E[1]];
        }
        else
        {
            outfile << '*';
        }
        outfile << ',';
        if (tri->E[2])
        {
            outfile << 'e' << eIndex[tri->E[2]];
        }
        else
        {
            outfile << '*';
        }
        outfile << '>' << std::endl;
    }
    outfile << std::endl;
}

// ETNonmanifoldMesh::Edge

Mathematics::ETNonmanifoldMesh::Edge ::Edge(int v0, int v1) noexcept
{
    V[0] = v0;
    V[1] = v1;
}

Mathematics::ETNonmanifoldMesh::Edge ::~Edge()
{
}

// ETNonmanifoldMesh::Triangle

Mathematics::ETNonmanifoldMesh::Triangle ::Triangle(int v0, int v1, int v2) noexcept
    : E{}, V{}
{
    V[0] = v0;
    V[1] = v1;
    V[2] = v2;

    for (int i = 0; i < 3; ++i)
    {
        E[i] = 0;
    }
}

Mathematics::ETNonmanifoldMesh::Triangle ::~Triangle()
{
}

int Mathematics::ETNonmanifoldMesh ::GetNumEdges() const noexcept
{
    return gsl::narrow_cast<int>(mEMap.size());
}

const Mathematics::ETNonmanifoldMesh::EMap& Mathematics::ETNonmanifoldMesh ::GetEdges() const noexcept
{
    return mEMap;
}

int Mathematics::ETNonmanifoldMesh ::GetNumTriangles() const noexcept
{
    return gsl::narrow_cast<int>(mTMap.size());
}

const Mathematics::ETNonmanifoldMesh::TMap& Mathematics::ETNonmanifoldMesh ::GetTriangles() const noexcept
{
    return mTMap;
}

#include STSTEM_WARNING_POP