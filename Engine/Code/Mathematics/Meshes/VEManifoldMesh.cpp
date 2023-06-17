///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 10:22)

#include "Mathematics/MathematicsExport.h"

#include "VEManifoldMesh.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include <fstream>

Mathematics::VEManifoldMesh::VEManifoldMesh(VertexCreator vCreator, EdgeCreator eCreator) noexcept
    : vertexCreator{ vCreator ? vCreator : CreateVertex },
      vertexMap{},
      edgeCreator{ eCreator ? eCreator : CreateEdge },
      edgeMap{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Mathematics, VEManifoldMesh)

Mathematics::VEManifoldMesh::VertexSharedPtr Mathematics::VEManifoldMesh::CreateVertex(int v)
{
    return std::make_shared<Vertex>(v);
}

Mathematics::VEManifoldMesh::EdgeSharedPtr Mathematics::VEManifoldMesh::CreateEdge(int v0, int v1)
{
    return std::make_shared<Edge>(v0, v1);
}

Mathematics::VEManifoldMesh::EdgeSharedPtr Mathematics::VEManifoldMesh::InsertEdge(int v0, int v1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const std::pair<int, int> ekey{ v0, v1 };
    const auto eiter = edgeMap.find(ekey);
    if (eiter != edgeMap.end())
    {
        return nullptr;
    }

    auto edge = edgeCreator(v0, v1);
    edgeMap[ekey] = edge;

    for (auto i = 0; i < 2; ++i)
    {
        if (edge)
        {
            const auto v = edge->v.at(i);
            VertexSharedPtr vertex{};
            const auto viter = vertexMap.find(v);
            if (viter == vertexMap.end())
            {
                vertex = vertexCreator(v);
                vertexMap[v] = vertex;

                vertex->e.at(0) = edge;
            }
            else
            {
                vertex = viter->second;

                if (vertex == nullptr)
                {
                    THROW_EXCEPTION(SYSTEM_TEXT("意外情况\n"));
                }

                if (vertex->e.at(1))
                {
                    return nullptr;
                }
                vertex->e.at(1) = edge;

                auto adjacent = vertex->e.at(0);

                if (adjacent == 0)
                {
                    THROW_EXCEPTION(SYSTEM_TEXT("意外情况\n"s));
                }
                for (auto j = 0; j < 2; ++j)
                {
                    if (adjacent->v.at(j) == v)
                    {
                        adjacent->e.at(j) = edge;
                        break;
                    }
                }

                edge->e.at(i) = adjacent;
            }
        }
    }

    return edge;
}

bool Mathematics::VEManifoldMesh::RemoveEdge(int v0, int v1)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const std::pair<int, int> ekey{ v0, v1 };
    const auto eiter = edgeMap.find(ekey);
    if (eiter == edgeMap.end())
    {
        return false;
    }

    auto edge = eiter->second;
    for (auto i = 0; i < 2; ++i)
    {
        const auto viter = vertexMap.find(edge->v.at(i));
        MATHEMATICS_ASSERTION_0(viter != vertexMap.end(), "意外情况\n");
        auto vertex = viter->second;
        if (vertex == nullptr)
        {
            THROW_EXCEPTION(SYSTEM_TEXT("意外情况\n"s));
        }
        if (vertex->e.at(0) == edge)
        {
            vertex->e.at(0) = vertex->e.at(1);
            vertex->e.at(1) = nullptr;
        }
        else if (vertex->e.at(1) == edge)
        {
            vertex->e.at(1) = nullptr;
        }
        else
        {
            MATHEMATICS_ASSERTION_0(false, "意外情况\n");
            return false;
        }

        if (!vertex->e.at(0) && !vertex->e.at(1))
        {
            vertexMap.erase(vertex->v);
        }

        auto adjacent = edge->e.at(i);
        if (adjacent)
        {
            for (auto j = 0; j < 2; ++j)
            {
                if (adjacent->e.at(j) == edge)
                {
                    adjacent->e.at(j) = 0;
                    break;
                }
            }
        }
    }

    edgeMap.erase(ekey);

    return true;
}

bool Mathematics::VEManifoldMesh::IsClosed() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    for (const auto& viter : vertexMap)
    {
        const auto vertex = viter.second;
        if (!vertex->e.at(0) || !vertex->e.at(1))
        {
            return false;
        }
    }
    return true;
}

void Mathematics::VEManifoldMesh::Print(const std::string& filename)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    std::ofstream outFile{ filename };

    if (!outFile)
    {
        return;
    }

    std::map<EdgeSharedPtr, int> edgeIndex{};
    edgeIndex[EdgeSharedPtr{}] = 0;

    auto i = 1;
    for (const auto& eiter : edgeMap)
    {
        if (eiter.second)
        {
            edgeIndex[eiter.second] = i;
            ++i;
        }
    }

    outFile << "vertex quantity = " << vertexMap.size() << std::endl;

    for (const auto& viter : vertexMap)
    {
        const Vertex& vertex = *viter.second;
        outFile << 'v' << vertex.v << " <";
        if (vertex.e.at(0))
        {
            outFile << 'e' << edgeIndex[vertex.e.at(0)];
        }
        else
        {
            outFile << '*';
        }
        outFile << ',';
        if (vertex.e.at(1))
        {
            outFile << 'e' << edgeIndex[vertex.e.at(1)];
        }
        else
        {
            outFile << '*';
        }
        outFile << '>' << std::endl;
    }

    outFile << "edge quantity = " << edgeMap.size() << std::endl;
    for (const auto& eiter : edgeMap)
    {
        const auto& edge = *eiter.second;
        outFile << 'e' << edgeIndex[eiter.second] << " <" << 'v' << edge.v.at(0) << ",v" << edge.v.at(1) << "; ";
        if (edge.e.at(0))
        {
            outFile << 'e' << edgeIndex[edge.e.at(0)];
        }
        else
        {
            outFile << '*';
        }
        outFile << ',';
        if (edge.e.at(1))
        {
            outFile << 'e' << edgeIndex[edge.e.at(1)];
        }
        else
        {
            outFile << '*';
        }
        outFile << '>' << std::endl;
    }
    outFile << std::endl;
}

// VEManifoldMesh::Vertex

Mathematics::VEManifoldMesh::Vertex::Vertex(int v) noexcept
    : v{ v }, e{}
{
}

// VEManifoldMesh::Edge

Mathematics::VEManifoldMesh::Edge::Edge(int v0, int v1) noexcept
    : v{ v0, v1 }, e{}
{
}

const Mathematics::VEManifoldMesh::VertexMap& Mathematics::VEManifoldMesh::GetVertices() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return vertexMap;
}

const Mathematics::VEManifoldMesh::EdgeMap& Mathematics::VEManifoldMesh::GetEdges() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return edgeMap;
}
