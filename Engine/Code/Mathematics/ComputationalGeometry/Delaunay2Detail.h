///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:35)

#ifndef MATHEMATICS_COMPUTATIONAL_GEOMETRY_DELAUNAY2_DETAIL_H
#define MATHEMATICS_COMPUTATIONAL_GEOMETRY_DELAUNAY2_DETAIL_H

#include "ConvexHull1.h"
#include "Delaunay1.h"
#include "Delaunay2.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Algebra/BarycentricCoordinates.h"
#include "Mathematics/Algebra/Vector2Detail.h"
#include "Mathematics/Algebra/Vector2Information.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Query/Query2Filtered.h"
#include "Mathematics/Query/Query2Int64.h"
#include "Mathematics/Query/Query2Integer.h"
#include "Mathematics/Query/Query2Rational.h"

template <typename Real>
const std::array<std::array<int32_t, 2>, 3> Mathematics::Delaunay2<Real>::index{ std::array<int32_t, 2>{ 0, 1 }, std::array<int32_t, 2>{ 1, 2 }, std::array<int32_t, 2>{ 2, 0 } };

template <typename Real>
Mathematics::Delaunay2<Real>::Delaunay2(const Vertices& vertices, Real epsilon, QueryType queryType)
    : ParentType{ boost::numeric_cast<int>(vertices.size()), epsilon, queryType },
      vertices{ vertices },
      numUniqueVertices{ 0 },
      sVertices{},
      query{},
      min{},
      scale{},
      triMesh{},
      lineOrigin{},
      lineDirection{},
      pathLast{ -1 },
      path{},
      lastEdgeV0{ -1 },
      lastEdgeV1{ -1 },
      lastEdgeOpposite{ -1 },
      lastEdgeOppositeIndex{ -1 }
{
    Init();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Delaunay2<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
void Mathematics::Delaunay2<Real>::Init()
{
    Vector2Information<Real> info{ vertices, this->GetEpsilon() };
    if (info.GetDimension() == 0)
    {
        return;
    }

    if (info.GetDimension() == 1)
    {
        this->SetDimension(1);

        lineOrigin = info.GetOrigin();
        lineDirection = info.GetDirectionX();

        return;
    }

    this->SetDimension(1);

    const auto numVertices = this->GetNumVertices();
    sVertices.resize(numVertices);

    const auto queryType = this->GetQueryType();

    if (queryType != QueryType::Rational && queryType != QueryType::Filtered)
    {
        min = info.GetMinExtreme();
        scale = Math<Real>::GetValue(1) / info.GetMaxRange();
        for (auto i = 0; i < numVertices; ++i)
        {
            sVertices.at(i) = (vertices.at(i) - min) * scale;
        }

        Real expand{};
        if (queryType == QueryType::Int64)
        {
            expand = Math<Real>::GetValue(1 << 16);
            query = std::make_shared<Query2Int64<Real>>(sVertices);
        }
        else if (queryType == QueryType::Integer)
        {
            expand = Math<Real>::GetValue(1 << 20);
            query = std::make_shared<Query2Integer<Real>>(sVertices);
        }
        else
        {
            expand = Math<Real>::GetValue(1);
            query = std::make_shared<Query2>(sVertices);
        }

        scale *= expand;
        for (auto i = 0; i < numVertices; ++i)
        {
            sVertices.at(i) *= expand;
        }
    }
    else
    {
        min = Vector2Type::GetZero();
        scale = Math<Real>::GetValue(1);
        sVertices = vertices;

        if (queryType == QueryType::Rational)
        {
            query = std::make_shared<Query2Rational<Real>>(sVertices);
        }
        else
        {
            query = std::make_shared<Query2Filtered<Real>>(sVertices, this->GetEpsilon());
        }
    }

    std::array<int32_t, 3> extreme{ info.GetMinExtremeIndex(), info.GetPerpendicularExtremeIndex(), info.GetMaxExtremeIndex() };

    if (!info.IsExtremeCCW())
    {
        std::swap(extreme.at(1), extreme.at(2));
    }

    triMesh.InsertTriangle(extreme.at(0), extreme.at(1), extreme.at(2));

    std::set<Vector2Type> processed{};
    for (auto i = 0; i < 3; ++i)
    {
        processed.insert(sVertices.at(extreme.at(i)));
    }
    for (auto i = 0; i < numVertices; ++i)
    {
        if (processed.find(sVertices.at(i)) == processed.end())
        {
            Update(i);
            processed.insert(sVertices.at(i));
        }
    }
    numUniqueVertices = boost::numeric_cast<int>(processed.size());

    std::map<TriangleSharedPtr, int> permute{};
    auto i = -1;
    permute[TriangleSharedPtr{}] = i++;
    const auto& tmap = triMesh.GetTriangles();

    for (auto element = tmap.begin(); element != tmap.end(); ++element)
    {
        permute[element->second] = i++;
    }

    auto numSimplices = boost::numeric_cast<int>(triMesh.GetTriangles().size());
    this->SetNumSimplices(numSimplices);
    if (0 < numSimplices)
    {
        for (auto element = tmap.begin(); element != tmap.end(); ++element)
        {
            const auto& tri = element->second;
            for (int j = 0; j < 3; ++j)
            {
                this->AddIndex(tri->v.at(j));
                this->AddAdjacency(permute[tri->t.at(j)]);
            }
        }
        MATHEMATICS_ASSERTION_0(i == 3 * numSimplices, "意外的不匹配。\n");

        pathLast = -1;

        const auto size = numSimplices + 1;
        path.resize(size);
    }
}

template <typename Real>
typename Mathematics::Delaunay2<Real>::Vertices Mathematics::Delaunay2<Real>::GetVertices() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return vertices;
}

template <typename Real>
int Mathematics::Delaunay2<Real>::GetNumUniqueVertices() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return numUniqueVertices;
}

template <typename Real>
Mathematics::Vector2<Real> Mathematics::Delaunay2<Real>::GetLineOrigin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return lineOrigin;
}

template <typename Real>
Mathematics::Vector2<Real> Mathematics::Delaunay2<Real>::GetLineDirection() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return lineDirection;
}

template <typename Real>
Mathematics::Delaunay1<Real> Mathematics::Delaunay2<Real>::GetDelaunay1() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto dimension = this->GetDimension();

    if (dimension != 1)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("维度必须为1。"));
    }

    typename Delaunay1Type::Vertices projection{};
    for (const auto& value : vertices)
    {
        auto diff = value - lineOrigin;
        projection.emplace_back(Vector2Tools<Real>::DotProduct(lineDirection, diff));
    }

    Delaunay1Type delaunay1(projection, this->GetEpsilon(), this->GetQueryType());

    return delaunay1;
}

template <typename Real>
typename Mathematics::Delaunay2<Real>::HullType Mathematics::Delaunay2<Real>::GetHull() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto dimension = this->GetDimension();

    if (dimension != 2)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("维度必须为2。"));
    }

    auto numEdges = 0;

    const int numAdjacent = 3 * this->GetNumSimplices();
    for (auto i = 0; i < numAdjacent; ++i)
    {
        if (this->GetAdjacency(i) == -1)
        {
            ++numEdges;
        }
    }

    MATHEMATICS_ASSERTION_0(0 < numEdges, "必须至少有一个三角形。\n");
    if (numEdges == 0)
    {
        return { IndicesType{}, false };
    }

    const auto size = 2 * numEdges;
    IndicesType indices(size);

    auto currentIndex = 0;
    for (auto i = 0; i < numAdjacent; ++i)
    {
        if (this->GetAdjacency(i) == -1)
        {
            const auto tri = i / 3;
            const auto j = i % 3;
            indices.at(currentIndex++) = this->GetIndex(3 * tri + j);
            indices.at(currentIndex++) = this->GetIndex(3 * tri + ((j + 1) % 3));
        }
    }

    return { indices, true };
}

template <typename Real>
int Mathematics::Delaunay2<Real>::GetContainingTriangle(const Vector2Type& p) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto dimension = this->GetDimension();

    if (dimension != 2)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("维度必须为2。"));
    }

    auto scP = (p - min) * scale;

    auto pathIndex = (pathLast >= 0 ? path.at(pathLast) : 0);
    pathLast = -1;
    lastEdgeV0 = -1;
    lastEdgeV1 = -1;
    lastEdgeOpposite = -1;
    lastEdgeOppositeIndex = -1;

    const auto mNumSimplices = this->GetNumSimplices();

    for (auto i = 0; i < mNumSimplices; ++i)
    {
        path.at(++pathLast) = pathIndex;

        if (System::EnumCastUnderlying(query->ToLine(scP, this->GetIndex(3 * pathIndex), this->GetIndex(3 * pathIndex + 1))) > 0)
        {
            pathIndex = this->GetAdjacency(3 * pathIndex);
            if (pathIndex == -1)
            {
                lastEdgeV0 = this->GetIndex(3 * pathIndex);
                lastEdgeV1 = this->GetIndex(3 * pathIndex + 1);
                lastEdgeOpposite = this->GetIndex(3 * pathIndex + 2);
                lastEdgeOppositeIndex = 2;
                return -1;
            }
            continue;
        }

        if (System::EnumCastUnderlying(query->ToLine(scP, this->GetIndex(3 * pathIndex + 1), this->GetIndex(3 * pathIndex + 2))) > 0)
        {
            pathIndex = this->GetAdjacency(3 * pathIndex + 1);
            if (pathIndex == -1)
            {
                lastEdgeV0 = this->GetIndex(3 * pathIndex + 1);
                lastEdgeV1 = this->GetIndex(3 * pathIndex + 2);
                lastEdgeOpposite = this->GetIndex(3 * pathIndex);
                lastEdgeOppositeIndex = 0;
                return -1;
            }
            continue;
        }

        if (System::EnumCastUnderlying(query->ToLine(scP, this->GetIndex(3 * pathIndex + 2), this->GetIndex(3 * pathIndex))) > 0)
        {
            pathIndex = this->GetAdjacency(3 * pathIndex + 2);
            if (pathIndex == -1)
            {
                lastEdgeV0 = this->GetIndex(3 * pathIndex + 2);
                lastEdgeV1 = this->GetIndex(3 * pathIndex);
                lastEdgeOpposite = this->GetIndex(3 * pathIndex + 1);
                lastEdgeOppositeIndex = 1;
                return -1;
            }
            continue;
        }

        lastEdgeV0 = -1;
        lastEdgeV1 = -1;
        lastEdgeOpposite = -1;
        lastEdgeOppositeIndex = -1;

        return pathIndex;
    }

    return -1;
}

template <typename Real>
int Mathematics::Delaunay2<Real>::GetPathLast() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return pathLast;
}

template <typename Real>
typename Mathematics::Delaunay2<Real>::IndicesType Mathematics::Delaunay2<Real>::GetPath() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return path;
}

template <typename Real>
int Mathematics::Delaunay2<Real>::GetLastEdge(int& v0, int& v1, int& v2) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    v0 = lastEdgeV0;
    v1 = lastEdgeV1;
    v2 = lastEdgeOpposite;

    return lastEdgeOppositeIndex;
}

template <typename Real>
typename Mathematics::Delaunay2<Real>::VertexType Mathematics::Delaunay2<Real>::GetVertexSet(int i) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto dimension = this->GetDimension();

    if (dimension != 2)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("维度必须为2。"));
    }

    const auto mNumSimplices = this->GetNumSimplices();

    if (0 <= i && i < mNumSimplices)
    {
        return { vertices.at(this->GetIndex(3 * i)), vertices.at(this->GetIndex(3 * i + 1)), vertices.at(this->GetIndex(3 * i + 2)), true };
    }

    return { Vector2Type{}, Vector2Type{}, Vector2Type{}, false };
}

template <typename Real>
typename Mathematics::Delaunay2<Real>::IndexType Mathematics::Delaunay2<Real>::GetIndexSet(int i) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto dimension = this->GetDimension();

    if (dimension != 2)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("维度必须为2。"));
    }

    const auto mNumSimplices = this->GetNumSimplices();

    if (0 <= i && i < mNumSimplices)
    {
        return { this->GetIndex(3 * i), this->GetIndex(3 * i + 1), this->GetIndex(3 * i + 2), true };
    }

    return { -1, -1, -1, false };
}

template <typename Real>
typename Mathematics::Delaunay2<Real>::IndexType Mathematics::Delaunay2<Real>::GetAdjacentSet(int i) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto dimension = this->GetDimension();

    if (dimension != 2)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("维度必须为2。"));
    }

    const auto mNumSimplices = this->GetNumSimplices();

    if (0 <= i && i < mNumSimplices)
    {
        return { this->GetAdjacency(3 * i), this->GetAdjacency(3 * i + 1), this->GetAdjacency(3 * i + 2), true };
    }

    return { -1, -1, -1, false };
}

template <typename Real>
typename Mathematics::Delaunay2<Real>::BaryType Mathematics::Delaunay2<Real>::GetBarycentricSet(int i, const Vector2Type& p) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto dimension = this->GetDimension();

    if (dimension != 2)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("维度必须为2。"));
    }

    const auto mNumSimplices = this->GetNumSimplices();

    if (0 <= i && i < mNumSimplices)
    {
        const auto& v0 = vertices.at(this->GetIndex(3 * i));
        const auto& v1 = vertices.at(this->GetIndex(3 * i + 1));
        const auto& v2 = vertices.at(this->GetIndex(3 * i + 2));
        const auto coordinates = p.GetBarycentrics(v0, v1, v2);

        return { coordinates[0], coordinates[1], coordinates[2], true };
    }

    return { Math<Real>::GetValue(0), Math<Real>::GetValue(0), Math<Real>::GetValue(0), true };
}

template <typename Real>
Mathematics::Delaunay2<Real>::Delaunay2(const String& filename)
    : ParentType{ 0, Math<Real>::GetValue(0), QueryType::Real },
      vertices{},
      numUniqueVertices{ 0 },
      sVertices{},
      query{},
      min{},
      scale{},
      triMesh{},
      lineOrigin{},
      lineDirection{},
      pathLast{ -1 },
      path{},
      lastEdgeV0{ -1 },
      lastEdgeV1{ -1 },
      lastEdgeOpposite{ -1 },
      lastEdgeOppositeIndex{ -1 }
{
    LoadFile(filename);

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
void Mathematics::Delaunay2<Real>::LoadFile(const String& filename)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    CoreTools::ReadFileManager inFile{ filename };

    if (!ParentType::Load(inFile))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("加载文件失败\n"));
    }

    query.reset();
    path.clear();

    const auto numVertices = this->GetNumVertices();
    const auto numSimplices = this->GetNumSimplices();

    vertices.resize(numVertices);
    sVertices.resize(numVertices);
    const auto pathSize = numSimplices + 1;
    path.resize(pathSize);

    inFile.Read(sizeof(int32_t), &numUniqueVertices);
    inFile.Read(sizeof(int32_t), &pathLast);
    inFile.Read(sizeof(int32_t), &lastEdgeV0);
    inFile.Read(sizeof(int32_t), &lastEdgeV1);
    inFile.Read(sizeof(int32_t), &lastEdgeOpposite);
    inFile.Read(sizeof(int32_t), &lastEdgeOppositeIndex);
    inFile.Read(sizeof(int32_t), pathSize, path.data());

    const auto twoNumVertices = Vector2Type::pointSize * numVertices;

    inFile.Read(sizeof(Real), twoNumVertices, vertices.data());
    inFile.Read(sizeof(Real), twoNumVertices, sVertices.data());
    inFile.Read(sizeof(Real), Vector2Type::pointSize, &min);
    inFile.Read(sizeof(Real), Vector2Type::pointSize, &scale);
    inFile.Read(sizeof(Real), Vector2Type::pointSize, &lineOrigin);
    inFile.Read(sizeof(Real), Vector2Type::pointSize, &lineDirection);

    switch (this->GetQueryType())
    {
        case QueryType::Int64:
        {
            query = std::make_shared<Query2Int64<Real>>(sVertices);
            break;
        }
        case QueryType::Integer:
        {
            query = std::make_shared<Query2Integer<Real>>(sVertices);
            break;
        }
        case QueryType::Rational:
        {
            query = std::make_shared<Query2Rational<Real>>(sVertices);
            break;
        }
        case QueryType::Real:
        {
            query = std::make_shared<Query2>(sVertices);
            break;
        }
        case QueryType::Filtered:
        {
            query = std::make_shared<Query2Filtered<Real>>(sVertices, this->GetEpsilon());
            break;
        }
    }
}

template <typename Real>
void Mathematics::Delaunay2<Real>::SaveFile(const String& filename) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    CoreTools::WriteFileManager outFile{ filename };

    if (!ParentType::Save(outFile))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("保存文件失败\n"));
    }

    const auto numSimplices = this->GetNumSimplices();
    const auto pathSize = numSimplices + 1;

    outFile.Write(sizeof(int32_t), &numUniqueVertices);
    outFile.Write(sizeof(int32_t), &pathLast);
    outFile.Write(sizeof(int32_t), &lastEdgeV0);
    outFile.Write(sizeof(int32_t), &lastEdgeV1);
    outFile.Write(sizeof(int32_t), &lastEdgeOpposite);
    outFile.Write(sizeof(int32_t), &lastEdgeOppositeIndex);
    outFile.Write(sizeof(int32_t), pathSize, path.data());

    const auto numVertices = this->GetNumVertices();

    const auto twoNumVertices = Vector2Type::pointSize * numVertices;

    outFile.Write(sizeof(Real), twoNumVertices, vertices.data());
    outFile.Write(sizeof(Real), twoNumVertices, vertices.data());
    outFile.Write(sizeof(Real), Vector2Type::pointSize, &min);
    outFile.Write(sizeof(Real), Vector2Type::pointSize, &scale);
    outFile.Write(sizeof(Real), Vector2Type::pointSize, &lineOrigin);
    outFile.Write(sizeof(Real), Vector2Type::pointSize, &lineDirection);
}

template <typename Real>
bool Mathematics::Delaunay2<Real>::GetContainingTriangle(int i, const Triangle& tri) const
{
    const auto numTriangles = triMesh.GetTriangles().size();
    for (auto t = 0u; t < numTriangles; ++t)
    {
        int j;
        for (j = 0; j < 3; ++j)
        {
            const std::array<int, 2> edge{ index.at(j).at(0), index.at(j).at(1) };
            if (System::EnumCastUnderlying(query->ToLine(i, tri.v.at(edge.at(0)), tri.v.at(edge.at(1)))) > 0)
            {
                if (tri.t.at(j))
                {
                    break;
                }
                else
                {
                    return false;
                }
            }
        }

        if (j == 3)
        {
            return true;
        }
    }

    return false;
}

template <typename Real>
void Mathematics::Delaunay2<Real>::GetAndRemoveInsertionPolygon(int i, std::set<TriangleSharedPtr>& candidates, std::set<OrderedEdgeKey>& boundary)
{
    ETManifoldMesh polygon{};
    while (!candidates.empty())
    {
        auto tri = *candidates.begin();
        candidates.erase(candidates.begin());

        for (int j = 0; j < 3; ++j)
        {
            auto adj = tri->t.at(j);
            if (adj && candidates.find(adj) == candidates.end())
            {
                if (System::EnumCastUnderlying(query->ToCircumcircle(i, adj->v.at(0), adj->v.at(1), adj->v.at(2))) <= 0)
                {
                    candidates.insert(adj);
                }
            }
        }

        polygon.InsertTriangle(tri->v.at(0), tri->v.at(1), tri->v.at(2));
        triMesh.RemoveTriangle(tri->v.at(0), tri->v.at(1), tri->v.at(2));
    }

    const auto& triangles = polygon.GetTriangles();

    for (const auto& element : triangles)
    {
        auto tri = element.second;
        for (int j = 0; j < 3; ++j)
        {
            if (!tri->t.at(j))
            {
                const std::array<int, 2> edge{ index.at(j).at(0), index.at(j).at(1) };
                boundary.insert(OrderedEdgeKey{ tri->v.at(edge.at(0)), tri->v.at(edge.at(1)) });
            }
        }
    }
}

template <typename Real>
void Mathematics::Delaunay2<Real>::Update(int i)
{
    const auto& triangles = triMesh.GetTriangles();
    auto tri = triangles.begin()->second;
    if (GetContainingTriangle(i, *tri))
    {
        std::set<TriangleSharedPtr> candidates{ tri };

        std::set<OrderedEdgeKey> boundary{};
        GetAndRemoveInsertionPolygon(i, candidates, boundary);

        for (const auto& key : boundary)
        {
            triMesh.InsertTriangle(i, key.GetKey(0), key.GetKey(1));
        }
    }
    else
    {
        std::set<OrderedEdgeKey> hull{};

        for (const auto& element : triangles)
        {
            auto value = element.second;
            for (int j = 0; j < 3; ++j)
            {
                if (!value->t.at(j))
                {
                    const std::array<int, 2> edge{ index.at(j).at(0), index.at(j).at(1) };
                    hull.insert(OrderedEdgeKey{ value->v.at(edge.at(0)), value->v.at(edge.at(1)) });
                }
            }
        }

        const auto& edgemap = triMesh.GetEdges();
        std::set<TriangleSharedPtr> candidates{};
        std::set<OrderedEdgeKey> visible{};

        for (const auto& key : hull)
        {
            if (System::EnumCastUnderlying(query->ToLine(i, key.GetKey(0), key.GetKey(1))) > 0)
            {
                const auto iter = edgemap.find(EdgeKey(key.GetKey(0), key.GetKey(1)));
                if (iter == edgemap.end())
                {
                    THROW_EXCEPTION(SYSTEM_TEXT("意外情况\n"));
                }

                MATHEMATICS_ASSERTION_0(iter->second->t.at(1) == 0, "意外情况\n");

                auto adj = iter->second->t.at(0);
                if (adj && candidates.find(adj) == candidates.end())
                {
                    if (System::EnumCastUnderlying(query->ToCircumcircle(i, adj->v.at(0), adj->v.at(1), adj->v.at(2))) <= 0)
                    {
                        candidates.insert(adj);
                    }
                    else
                    {
                        visible.insert(key);
                    }
                }
            }
        }

        std::set<OrderedEdgeKey> boundary{};
        GetAndRemoveInsertionPolygon(i, candidates, boundary);

        for (const auto& value : boundary)
        {
            if (System::EnumCastUnderlying(query->ToLine(i, value.GetKey(0), value.GetKey(1))) < 0)
            {
                triMesh.InsertTriangle(i, value.GetKey(0), value.GetKey(1));
            }
        }

        for (const auto& value : visible)
        {
            triMesh.InsertTriangle(i, value.GetKey(1), value.GetKey(0));
        }
    }
}

#endif  // MATHEMATICS_COMPUTATIONAL_GEOMETRY_DELAUNAY2_DETAIL_H