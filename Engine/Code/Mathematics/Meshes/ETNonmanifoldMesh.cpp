///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 10:18)

#include "Mathematics/MathematicsExport.h"

#include "ETNonmanifoldMesh.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include <gsl/util>
#include <fstream>

Mathematics::ETNonmanifoldMesh::ETNonmanifoldMesh(EdgeCreator eCreator, TriangleCreator tCreator) noexcept
    : edgeCreator{ eCreator ? eCreator : CreateEdge },
      edgeMap{},
      triangleCreator{ tCreator ? tCreator : CreateTriangle },
      triangleMap{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Mathematics, ETNonmanifoldMesh)

Mathematics::ETNonmanifoldMesh::EdgeSharedPtr Mathematics::ETNonmanifoldMesh::CreateEdge(int v0, int v1)
{
    return std::make_shared<Edge>(v0, v1);
}

Mathematics::ETNonmanifoldMesh::TriangleSharedPtr Mathematics::ETNonmanifoldMesh::CreateTriangle(int v0, int v1, int v2)
{
    return std::make_shared<Triangle>(v0, v1, v2);
}

Mathematics::ETNonmanifoldMesh::TriangleSharedPtr Mathematics::ETNonmanifoldMesh::InsertTriangle(int v0, int v1, int v2)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const TriangleKey tKey{ v0, v1, v2 };
    const auto titer = triangleMap.find(tKey);
    if (titer != triangleMap.end())
    {
        return nullptr;
    }

    auto tri = triangleCreator(v0, v1, v2);
    triangleMap[tKey] = tri;

    for (auto i0 = 2, i1 = 0; i1 < 3; i0 = i1++)
    {
        const EdgeKey eKey{ tri->v.at(i0), tri->v.at(i1) };
        EdgeSharedPtr edge{};
        const auto eiter = edgeMap.find(eKey);
        if (eiter == edgeMap.end())
        {
            edge = edgeCreator(tri->v.at(i0), tri->v.at(i1));
            edgeMap[eKey] = edge;
        }
        else
        {
            edge = eiter->second;
        }

        edge->t.insert(tri);
        tri->e.at(i0) = edge;
    }

    return tri;
}

bool Mathematics::ETNonmanifoldMesh::RemoveTriangle(int v0, int v1, int v2)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const TriangleKey tKey{ v0, v1, v2 };
    const auto titer = triangleMap.find(tKey);
    if (titer == triangleMap.end())
    {
        return false;
    }

    auto tri = titer->second;
    for (auto i = 0; i < 3; ++i)
    {
        auto edge = tri->e.at(i);
        edge->t.erase(tri);

        if (edge->t.size() == 0)
        {
            const EdgeKey eKey{ edge->v.at(0), edge->v.at(1) };
            edgeMap.erase(eKey);
        }
    }

    triangleMap.erase(tKey);

    return true;
}

bool Mathematics::ETNonmanifoldMesh::IsManifold() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    for (const auto& value : edgeMap)
    {
        if (value.second->t.size() > 2)
        {
            return false;
        }
    }
    return true;
}

bool Mathematics::ETNonmanifoldMesh::IsClosed() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    for (const auto& value : edgeMap)
    {
        if (value.second->t.size() != 2)
        {
            return false;
        }
    }
    return true;
}

bool Mathematics::ETNonmanifoldMesh::IsConnected() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (triangleMap.begin() == triangleMap.end())
    {
        return true;
    }

    std::set<TriangleSharedPtr> component{};
    std::set<TriangleSharedPtr> boundary{ triangleMap.begin()->second };

    while (boundary.size() > 0)
    {
        std::set<TriangleSharedPtr> exterior{};

        for (const auto& tri : boundary)
        {
            component.insert(tri);

            for (auto i = 0; i < 3; ++i)
            {
                auto edge = tri->e.at(i);

                for (const auto& value : edge->t)
                {
                    if (value != tri && component.find(value) == component.end() && boundary.find(value) == boundary.end())
                    {
                        exterior.insert(value);
                    }
                }
            }
        }

        boundary = exterior;
    }

    return component.size() == triangleMap.size();
}

std::vector<int> Mathematics::ETNonmanifoldMesh::RemoveComponent()
{
    MATHEMATICS_CLASS_IS_VALID_9;

    std::vector<int> indices{};

    if (triangleMap.size() == 0)
    {
        return indices;
    }

    std::set<TriangleSharedPtr> visited{ triangleMap.begin()->second };

    while (!visited.empty())
    {
        auto tri = *visited.begin();

        for (auto i = 0; i < 3; ++i)
        {
            auto edge = tri->e.at(i);

            for (const auto& value : edge->t)
            {
                if (value != tri)
                {
                    visited.insert(value);
                }
            }
        }

        indices.emplace_back(tri->v.at(0));
        indices.emplace_back(tri->v.at(1));
        indices.emplace_back(tri->v.at(2));

        visited.erase(tri);
        RemoveTriangle(tri->v.at(0), tri->v.at(1), tri->v.at(2));
    }

    return indices;
}

void Mathematics::ETNonmanifoldMesh::Print(const std::string& filename)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    std::ofstream outfile{ filename };
    if (!outfile)
    {
        return;
    }

    std::map<EdgeSharedPtr, int> eIndex{};
    eIndex[nullptr] = 0;

    auto i = 1;
    for (const auto& value : edgeMap)
    {
        if (value.second)
        {
            eIndex[value.second] = i;
            ++i;
        }
    }

    std::map<TriangleSharedPtr, int> tIndex{};

    tIndex[nullptr] = 0;
    i = 1;

    for (const auto& value : triangleMap)
    {
        if (value.second)
        {
            tIndex[value.second] = i;
            ++i;
        }
    }

    outfile << "edge quantity = " << edgeMap.size() << std::endl;

    for (const auto& value : edgeMap)
    {
        auto edge = value.second;
        outfile << 'e' << eIndex[edge] << " <" << 'v' << edge->v.at(0) << ",v" << edge->v.at(1) << "; ";

        for (const auto& aiter : edge->t)
        {
            outfile << 't' << tIndex[aiter] << ',';
        }
        outfile << '>' << std::endl;
    }
    outfile << std::endl;

    outfile << "triangle quantity = " << triangleMap.size() << std::endl;

    for (const auto& value : triangleMap)
    {
        auto tri = value.second;
        outfile << 't' << tIndex[tri] << " <" << 'v' << tri->v.at(0) << ",v" << tri->v.at(1) << ",v" << tri->v.at(2) << "; ";
        if (tri->e.at(0))
        {
            outfile << 'e' << eIndex[tri->e.at(0)];
        }
        else
        {
            outfile << '*';
        }
        outfile << ',';
        if (tri->e.at(1))
        {
            outfile << 'e' << eIndex[tri->e.at(1)];
        }
        else
        {
            outfile << '*';
        }
        outfile << ',';
        if (tri->e.at(2))
        {
            outfile << 'e' << eIndex[tri->e.at(2)];
        }
        else
        {
            outfile << '*';
        }
        outfile << '>' << std::endl;
    }
    outfile << std::endl;
}

const Mathematics::ETNonmanifoldMesh::EdgeMap& Mathematics::ETNonmanifoldMesh::GetEdges() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return edgeMap;
}

int Mathematics::ETNonmanifoldMesh::GetNumTriangles() const noexcept
{
    return gsl::narrow_cast<int>(triangleMap.size());
}

const Mathematics::ETNonmanifoldMesh::TriangleMap& Mathematics::ETNonmanifoldMesh::GetTriangles() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return triangleMap;
}

int Mathematics::ETNonmanifoldMesh::GetNumEdges() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return gsl::narrow_cast<int>(edgeMap.size());
}

// ETNonmanifoldMesh::Edge

Mathematics::ETNonmanifoldMesh::Edge::Edge(int v0, int v1)  
    : v{ v0, v1 }, t{}
{
}

// ETNonmanifoldMesh::Triangle

Mathematics::ETNonmanifoldMesh::Triangle::Triangle(int v0, int v1, int v2)  
    : e{}, v{ v0, v1, v2 }
{
}
