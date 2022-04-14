///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/22 20:45)

#include "Mathematics/MathematicsExport.h"

#include "ETManifoldMesh.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include <fstream>

Mathematics::ETManifoldMesh::ETManifoldMesh(EdgeCreator eCreator, TriangleCreator tCreator) noexcept
    : edgeCreator{ eCreator ? eCreator : CreateEdge },
      edgeMap{},
      triangleCreator{ tCreator ? tCreator : CreateTriangle },
      triangleMap{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Mathematics, ETManifoldMesh)

Mathematics::ETManifoldMesh::EdgeSharedPtr Mathematics::ETManifoldMesh::CreateEdge(int v0, int v1)
{
    return std::make_shared<Edge>(v0, v1);
}

Mathematics::ETManifoldMesh::TriangleSharedPtr Mathematics::ETManifoldMesh::CreateTriangle(int v0, int v1, int v2)
{
    return std::make_shared<Triangle>(v0, v1, v2);
}

Mathematics::ETManifoldMesh::TriangleSharedPtr Mathematics::ETManifoldMesh::InsertTriangle(int v0, int v1, int v2)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const TriangleKey tkey{ v0, v1, v2 };
    const auto titer = triangleMap.find(tkey);
    if (titer != triangleMap.end())
    {
        return nullptr;
    }

    auto tri = triangleCreator(v0, v1, v2);
    triangleMap[tkey] = tri;

    for (auto i0 = 2, i1 = 0; i1 < 3; i0 = i1++)
    {
        if (tri)
        {
            const EdgeKey ekey{ tri->v.at(i0), tri->v.at(i1) };

            const auto eiter = edgeMap.find(ekey);
            if (eiter == edgeMap.end())
            {
                auto edge = edgeCreator(tri->v.at(i0), tri->v.at(i1));
                edgeMap[ekey] = edge;

                edge->t.at(0) = tri;
                tri->e.at(i0) = edge;
            }
            else
            {
                auto edge = eiter->second;

                if (edge == 0)
                {
                    THROW_EXCEPTION(SYSTEM_TEXT("意外情况。\n"s));
                }

                if (edge->t.at(1))
                {
                    MATHEMATICS_ASSERTION_0(false, "网格必须是多面的\n");
                    return 0;
                }
                edge->t.at(1) = tri;

                auto adjacent = edge->t.at(0);
                if (adjacent == 0)
                {
                    THROW_EXCEPTION(SYSTEM_TEXT("意外情况。\n"s));
                }
                for (auto i = 0; i < 3; i++)
                {
                    if (adjacent->e.at(i) == edge)
                    {
                        adjacent->t.at(i) = tri;
                        break;
                    }
                }

                tri->e.at(i0) = edge;
                tri->t.at(i0) = adjacent;
            }
        }
    }

    return tri;
}

bool Mathematics::ETManifoldMesh::RemoveTriangle(int v0, int v1, int v2)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const TriangleKey tkey{ v0, v1, v2 };
    const auto titer = triangleMap.find(tkey);
    if (titer == triangleMap.end())
    {
        return false;
    }

    auto tri = titer->second;
    for (auto i = 0; i < 3; ++i)
    {
        auto edge = tri->e.at(i);
        if (edge == 0)
        {
            THROW_EXCEPTION(SYSTEM_TEXT("意外情况。\n"s));
        }
        if (edge->t.at(0) == tri)
        {
            edge->t.at(0) = edge->t.at(1);
            edge->t.at(1) = 0;
        }
        else if (edge->t.at(1) == tri)
        {
            edge->t.at(1) = 0;
        }
        else
        {
            MATHEMATICS_ASSERTION_0(false, "意外情况。\n");
            return false;
        }

        if (!edge->t.at(0) && !edge->t.at(1))
        {
            const EdgeKey ekey{ edge->v.at(0), edge->v.at(1) };
            edgeMap.erase(ekey);
        }

        auto adjacent = tri->t.at(i);
        if (adjacent)
        {
            for (auto j = 0; j < 3; ++j)
            {
                if (adjacent->t.at(j) == tri)
                {
                    adjacent->t.at(j) = 0;
                    break;
                }
            }
        }
    }

    triangleMap.erase(tkey);
    return true;
}

bool Mathematics::ETManifoldMesh::IsClosed() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    for (const auto& value : edgeMap)
    {
        const auto pkEdge = value.second;
        if (!pkEdge->t.at(0) || !pkEdge->t.at(1))
        {
            return false;
        }
    }
    return true;
}

void Mathematics::ETManifoldMesh::Print(const std::string& filename)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    std::ofstream outFile{ filename };
    if (!outFile)
    {
        return;
    }

    std::map<EdgeSharedPtr, int> edgeIndex{};
    edgeIndex[nullptr] = 0;

    auto i = 1;
    for (const auto& value : edgeMap)
    {
        if (value.second)
        {
            edgeIndex[value.second] = i;
            ++i;
        }
    }

    std::map<TriangleSharedPtr, int> triIndex{};
    triIndex[nullptr] = 0;
    i = 1;
    for (const auto& value : triangleMap)
    {
        if (value.second)
        {
            triIndex[value.second] = i;
            ++i;
        }
    }

    outFile << "edge quantity = " << edgeMap.size() << std::endl;

    for (const auto& value : edgeMap)
    {
        const auto& edge = *value.second;
        outFile << 'e' << edgeIndex[value.second] << " <" << 'v' << edge.v.at(0) << ",v" << edge.v.at(1) << "; ";
        if (edge.t.at(0))
        {
            outFile << 't' << triIndex[edge.t.at(0)];
        }
        else
        {
            outFile << '*';
        }
        outFile << ',';
        if (edge.t.at(1))
        {
            outFile << 't' << triIndex[edge.t.at(1)];
        }
        else
        {
            outFile << '*';
        }
        outFile << '>' << std::endl;
    }
    outFile << std::endl;

    outFile << "triangle quantity = " << triangleMap.size() << std::endl;

    for (const auto& value : triangleMap)
    {
        const auto& tri = *value.second;
        outFile << 't' << triIndex[value.second] << " <" << 'v' << tri.v.at(0) << ",v" << tri.v.at(1) << ",v" << tri.v.at(2) << "; ";
        if (tri.e.at(0))
        {
            outFile << 'e' << edgeIndex[tri.e.at(0)];
        }
        else
        {
            outFile << '*';
        }
        outFile << ',';
        if (tri.e.at(1))
        {
            outFile << 'e' << edgeIndex[tri.e.at(1)];
        }
        else
        {
            outFile << '*';
        }
        outFile << ',';
        if (tri.e.at(2))
        {
            outFile << 'e' << edgeIndex[tri.e.at(2)];
        }
        else
        {
            outFile << '*';
        }
        outFile << "; ";

        if (tri.t.at(0))
        {
            outFile << 't' << triIndex[tri.t.at(0)];
        }
        else
        {
            outFile << '*';
        }
        outFile << ',';
        if (tri.t.at(1))
        {
            outFile << 't' << triIndex[tri.t.at(1)];
        }
        else
        {
            outFile << '*';
        }
        outFile << ',';
        if (tri.t.at(2))
        {
            outFile << 't' << triIndex[tri.t.at(2)];
        }
        else
        {
            outFile << '*';
        }
        outFile << '>' << std::endl;
    }
    outFile << std::endl;
}

const Mathematics::ETManifoldMesh::EdgeMap& Mathematics::ETManifoldMesh::GetEdges() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return edgeMap;
}

const Mathematics::ETManifoldMesh::TriangleMap& Mathematics::ETManifoldMesh::GetTriangles() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return triangleMap;
}

// ETManifoldMesh::Edge

Mathematics::ETManifoldMesh::Edge::Edge(int v0, int v1) noexcept
    : v{ v0, v1 }, t{}
{
}

// ETManifoldMesh::Triangle

Mathematics::ETManifoldMesh::Triangle::Triangle(int v0, int v1, int v2) noexcept
    : e{}, v{ v0, v1, v2 }, t{}
{
}
