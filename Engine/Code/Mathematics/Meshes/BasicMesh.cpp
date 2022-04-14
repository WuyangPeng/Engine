///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/22 14:53)

#include "Mathematics/MathematicsExport.h"

#include "BasicMesh.h"
#include "EdgeKey.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include <map>

Mathematics::BasicMesh::BasicMesh(int numVertices, int numTriangles, const std::vector<int>& indices)
    : numVertices{ numVertices },
      numEdges{ 0 },
      numTriangles{ numTriangles },
      indices{ indices },
      vertices(numVertices),
      edges(3 * boost::numeric_cast<size_t>(numTriangles)),
      triangles(numTriangles),
      isValid{ true }
{
    MATHEMATICS_ASSERTION_0(numVertices > 0 && numTriangles > 0, "输入无效。\n");

    if (numVertices <= 0 || numTriangles <= 0 || indices.empty())
    {
        isValid = false;
        return;
    }

    std::map<EdgeKey, int> edgeMap{};
    auto index = 0;
    for (auto t = 0; t < numTriangles; t++)
    {
        auto& tri = triangles.at(t);
        tri.v.at(0) = indices.at(index++);
        tri.v.at(1) = indices.at(index++);
        tri.v.at(2) = indices.at(index++);

        for (auto i0 = 2, i1 = 0; i1 < 3; i0 = i1++)
        {
            if (!vertices.empty() && !triangles.empty())
            {
                vertices.at(tri.v.at(i1)).InsertTriangle(t);

                const EdgeKey key{ tri.v.at(i0), tri.v.at(i1) };
                const auto eiter = edgeMap.find(key);
                if (eiter == edgeMap.end())
                {
                    edgeMap[key] = numEdges;

                    Edge& edge = edges.at(numEdges);
                    edge.v.at(0) = tri.v.at(i0);
                    edge.v.at(1) = tri.v.at(i1);
                    edge.t.at(0) = t;

                    vertices.at(edge.v.at(0)).InsertEdge(edge.v.at(1), numEdges);
                    vertices.at(edge.v.at(1)).InsertEdge(edge.v.at(0), numEdges);

                    tri.e.at(i0) = numEdges;

                    ++numEdges;
                }
                else
                {
                    auto e = eiter->second;
                    auto& edge = edges.at(e);

                    if (edge.t.at(1) != -1)
                    {
                        numVertices = 0;
                        numEdges = 0;
                        numTriangles = 0;
                        vertices.clear();
                        edges.clear();
                        triangles.clear();
                        isValid = false;
                    }
                    edge.t.at(1) = t;

                    auto a = edge.t.at(0);
                    if (!triangles.empty())
                    {
                        auto& adj = triangles.at(a);
                        for (int j = 0; j < 3; ++j)
                        {
                            if (adj.e.at(j) == e)
                            {
                                adj.t.at(j) = t;
                                break;
                            }
                        }
                        tri.e.at(i0) = e;
                        tri.t.at(i0) = a;
                    }
                }
            }
        }
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Mathematics, BasicMesh)

// BasicMesh::Vertex

Mathematics::BasicMesh::Vertex::Vertex() noexcept
    : numVertices{}, v{}, e{}, numTriangles{}, t{}
{
}

void Mathematics::BasicMesh::Vertex::InsertEdge(int v0, int e0)
{
    for (auto i = 0; i < numVertices; ++i)
    {
        if (v0 == v.at(i))
        {
            return;
        }
    }

    v.emplace_back(v0);
    e.emplace_back(e0);

    ++numVertices;
}

void Mathematics::BasicMesh::Vertex::InsertTriangle(int t0)
{
    for (auto i = 0; i < numTriangles; ++i)
    {
        if (t0 == t.at(i))
        {
            return;
        }
    }

    t.emplace_back(t0);
    ++numTriangles;
}

// BasicMesh::Edge

Mathematics::BasicMesh::Edge::Edge() noexcept
    : v{ -1, -1 }, t{ -1, -1 }
{
}

// BasicMesh::Triangle

Mathematics::BasicMesh::Triangle::Triangle() noexcept
    : e{ -1, -1, -1 }, v{ -1, -1, -1 }, t{ -1, -1, -1 }
{
}

bool Mathematics::BasicMesh::IsBasicMeshValid() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return isValid;
}

int Mathematics::BasicMesh::GetNumVertices() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return numVertices;
}

int Mathematics::BasicMesh::GetNumEdges() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return numEdges;
}

int Mathematics::BasicMesh::GetNumTriangles() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return numTriangles;
}

std::vector<int> Mathematics::BasicMesh::GetIndices() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return indices;
}

std::vector<Mathematics::BasicMesh::Vertex> Mathematics::BasicMesh::GetVertices() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return vertices;
}

std::vector<Mathematics::BasicMesh::Edge> Mathematics::BasicMesh::GetEdges() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return edges;
}

std::vector<Mathematics::BasicMesh::Triangle> Mathematics::BasicMesh::GetTriangles() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return triangles;
}
