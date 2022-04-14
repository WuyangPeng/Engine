///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/23 14:59)

#include "Mathematics/MathematicsExport.h"

#include "TSManifoldMesh.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include <fstream>

Mathematics::TSManifoldMesh::TSManifoldMesh(TriangleCreator tCreator, TetrahedronCreator sCreator) noexcept
    : triangleCreator{ (tCreator ? tCreator : CreateTriangle) },
      triangleMap{},
      tetrahedronCreator{ (sCreator ? sCreator : CreateTetrahedron) },
      tetrahedronMap{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Mathematics, TSManifoldMesh)

const Mathematics::TSManifoldMesh::TriangleMap& Mathematics::TSManifoldMesh::GetTriangles() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return triangleMap;
}

const Mathematics::TSManifoldMesh::TetrahedronMap& Mathematics::TSManifoldMesh::GetTetrahedra() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return tetrahedronMap;
}

Mathematics::TSManifoldMesh::TriangleSharedPtr Mathematics::TSManifoldMesh::CreateTriangle(int v0, int v1, int v2)
{
    return std::make_shared<Triangle>(v0, v1, v2);
}

Mathematics::TSManifoldMesh::TetrahedronSharedPtr Mathematics::TSManifoldMesh::CreateTetrahedron(int v0, int v1, int v2, int v3)
{
    return std::make_shared<Tetrahedron>(v0, v1, v2, v3);
}

Mathematics::TSManifoldMesh::TetrahedronSharedPtr Mathematics::TSManifoldMesh::Insert(int v0, int v1, int v2, int v3)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const TetrahedronKey skey{ v0, v1, v2, v3 };
    if (tetrahedronMap.find(skey) != tetrahedronMap.end())
    {
        return nullptr;
    }

    auto tetra = tetrahedronCreator(v0, v1, v2, v3);
    tetrahedronMap[skey] = tetra;

    for (auto i = 0; i < 4; ++i)
    {
        if (tetra)
        {
            const std::array<int, 3> opposite{ TetrahedronKey::oppositeFace.at(i).at(0), TetrahedronKey::oppositeFace.at(i).at(1), TetrahedronKey::oppositeFace.at(i).at(2) };
            const UnorderedTriangleKey tkey{ tetra->v.at(opposite.at(0)), tetra->v.at(opposite.at(1)), tetra->v.at(opposite.at(2)) };
            TriangleSharedPtr face = nullptr;
            const auto titer = triangleMap.find(tkey);
            if (titer == triangleMap.end())
            {
                face = triangleCreator(tetra->v.at(opposite.at(0)), tetra->v.at(opposite.at(1)), tetra->v.at(opposite.at(2)));
                triangleMap[tkey] = face;

                face->t.at(0) = tetra;
                tetra->t.at(i) = face;
            }
            else
            {
                face = titer->second;
                if (!face)
                {
                    return nullptr;
                }

                if (face->t.at(1))
                {
                    return nullptr;
                }
                face->t.at(1) = tetra;

                auto adjacent = face->t.at(0);
                if (!adjacent)
                {
                    return nullptr;
                }
                for (auto j = 0; j < 4; ++j)
                {
                    if (adjacent->t.at(j) == face)
                    {
                        adjacent->s.at(j) = tetra;
                        break;
                    }
                }

                tetra->t.at(i) = face;
                tetra->s.at(i) = adjacent;
            }
        }
    }

    return tetra;
}

bool Mathematics::TSManifoldMesh::Remove(int v0, int v1, int v2, int v3)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const TetrahedronKey skey{ v0, v1, v2, v3 };
    const auto siter = tetrahedronMap.find(skey);
    if (siter == tetrahedronMap.end())
    {
        return false;
    }

    auto tetra = siter->second;

    for (auto i = 0; i < 4; ++i)
    {
        const auto face = tetra->t.at(i);
        if (!face)
        {
            return false;
        }

        if (face->t.at(0) == tetra)
        {
            face->t.at(0) = face->t.at(1);
            face->t.at(1) = nullptr;
        }
        else if (face->t.at(1) == tetra)
        {
            face->t.at(1) = nullptr;
        }
        else
        {
            return false;
        }

        if (!face->t.at(0) && !face->t.at(1))
        {
            const UnorderedTriangleKey tkey{ face->v.at(0), face->v.at(1), face->v.at(2) };
            triangleMap.erase(tkey);
        }

        auto adjacent = tetra->s.at(i);
        if (adjacent)
        {
            for (auto j = 0; j < 4; ++j)
            {
                if (adjacent->s.at(j) == tetra)
                {
                    adjacent->s.at(j) = 0;
                    break;
                }
            }
        }
    }

    tetrahedronMap.erase(skey);

    return true;
}

bool Mathematics::TSManifoldMesh::IsClosed() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    for (const auto& element : triangleMap)
    {
        auto tri = element.second;
        if (!tri->t.at(0) || !tri->t.at(1))
        {
            return false;
        }
    }
    return true;
}

bool Mathematics::TSManifoldMesh::Print(const std::string& filename)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    std::ofstream outFile{ filename };
    if (!outFile)
    {
        return false;
    }

    std::map<TriangleSharedPtr, int> triIndex{};
    triIndex[TriangleSharedPtr{}] = 0;
    auto i = 1;

    for (const auto& telement : triangleMap)
    {
        if (telement.second)
        {
            triIndex[telement.second] = i++;
        }
    }

    std::map<TetrahedronSharedPtr, int> tetraIndex{};
    tetraIndex[TetrahedronSharedPtr{}] = 0;
    i = 1;

    for (const auto& selement : tetrahedronMap)
    {
        if (selement.second)
        {
            tetraIndex[selement.second] = i++;
        }
    }

    outFile << "triangle quantity = " << triangleMap.size() << std::endl;
    for (const auto& telement : triangleMap)
    {
        const auto& tri = *telement.second;
        outFile << 't' << triIndex[telement.second] << " <" << 'v' << tri.v.at(0) << ",v" << tri.v.at(1) << ",v" << tri.v.at(2) << "; ";
        for (auto j = 0; j < 2; ++j)
        {
            if (tri.t.at(j))
            {
                outFile << 's' << tetraIndex[tri.t.at(j)];
            }
            else
            {
                outFile << '*';
            }
            outFile << (j == 0 ? '*' : '>');
        }
        outFile << std::endl;
    }
    outFile << std::endl;

    outFile << "tetrahedron quantity = " << tetrahedronMap.size() << std::endl;
    for (const auto& selement : tetrahedronMap)
    {
        const auto& tetra = *selement.second;
        outFile << 's' << tetraIndex[selement.second] << " <" << 'v' << tetra.v.at(0) << ",v" << tetra.v.at(1) << ",v" << tetra.v.at(2) << ",v" << tetra.v.at(3) << "; ";
        for (auto j = 0; j < 4; ++j)
        {
            if (tetra.t.at(j))
            {
                outFile << 't' << triIndex[tetra.t.at(j)];
            }
            else
            {
                outFile << '*';
            }
            outFile << (j < 3 ? "," : "; ");
        }

        for (auto j = 0; j < 4; ++j)
        {
            if (tetra.s.at(j))
            {
                outFile << 't' << tetraIndex[tetra.s.at(j)];
            }
            else
            {
                outFile << '*';
            }
            outFile << (j < 3 ? ',' : '>');
        }

        outFile << std::endl;
    }
    outFile << std::endl;
    return true;
}

Mathematics::TSManifoldMesh::Triangle::Triangle(int v0, int v1, int v2) noexcept
    : v{ v0, v1, v2 }, t{}
{
}

Mathematics::TSManifoldMesh::Tetrahedron::Tetrahedron(int v0, int v1, int v2, int v3) noexcept
    : v{ v0, v1, v2, v3 }, t{}, s{}
{
}
