///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:35)

#ifndef MATHEMATICS_COMPUTATIONAL_GEOMETRY_DELAUNAY3_DETAIL_H
#define MATHEMATICS_COMPUTATIONAL_GEOMETRY_DELAUNAY3_DETAIL_H

#include "Delaunay2.h"
#include "Delaunay3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Algebra/Vector3Detail.h"
#include "Mathematics/Algebra/Vector3Information.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Query/Query2Filtered.h"
#include "Mathematics/Query/Query2Int64.h"
#include "Mathematics/Query/Query2Integer.h"
#include "Mathematics/Query/Query2Rational.h"
#include "Mathematics/Query/Query3Filtered.h"
#include "Mathematics/Query/Query3Int64.h"
#include "Mathematics/Query/Query3Integer.h"
#include "Mathematics/Query/Query3Rational.h"

template <typename Real>
Mathematics::Delaunay3<Real>::Delaunay3(const Vertices& vertices, Real epsilon, QueryType queryType)
    : ParentType{ boost::numeric_cast<int>(vertices.size()), epsilon, queryType },
      vertices{ vertices },
      numUniqueVertices{ 0 },
      sVertices{},
      query{ 0 },
      min{},
      scale{},
      tetraMesh{},
      lineOrigin{},
      lineDirection{},
      planeOrigin{},
      planeDirection{},
      pathLast{ -1 },
      path{},
      lastFaceV0{ -1 },
      lastFaceV1{ -1 },
      lastFaceV2{ -1 },
      lastFaceOpposite{ -1 },
      lastFaceOppositeIndex{}
{
    Init();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Delaunay3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
void Mathematics::Delaunay3<Real>::Init()
{
    Vector3Information<Real> info{ vertices, this->GetEpsilon() };
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

    if (info.GetDimension() == 2)
    {
        this->SetDimension(2);
        planeOrigin = info.GetOrigin();
        planeDirection.at(0) = info.GetDirectionX();
        planeDirection.at(1) = info.GetDirectionY();

        return;
    }

    this->SetDimension(3);

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
            expand = Math<Real>::GetValue(1 << 10);
            query = std::make_shared<Query3Int64<Real>>(sVertices);
        }
        else if (queryType == QueryType::Integer)
        {
            expand = Math<Real>::GetValue(1 << 20);
            query = std::make_shared<Query3Integer<Real>>(sVertices);
        }
        else
        {
            expand = Math<Real>::GetValue(1);
            query = std::make_shared<Query3>(sVertices);
        }

        scale *= expand;
        for (auto i = 0; i < numVertices; ++i)
        {
            sVertices.at(i) *= expand;
        }
    }
    else
    {
        min = Vector3Type::GetZero();
        scale = Math<Real>::GetValue(1);
        sVertices = vertices;

        if (queryType == QueryType::Rational)
        {
            query = std::make_shared<Query3Rational<Real>>(sVertices);
        }
        else
        {
            query = std::make_shared<Query3Filtered<Real>>(sVertices, this->GetEpsilon());
        }
    }

    std::array<int32_t, 4> extreme{ info.GetMinExtremeIndex(), info.GetPerpendicularExtremeIndex(), info.GetTetrahedronExtremeIndex(), info.GetMaxExtremeIndex() };

    if (!info.IsExtremeCCW())
    {
        std::swap(extreme.at(2), extreme.at(3));
    }

    tetraMesh.Insert(extreme.at(0), extreme.at(1), extreme.at(2), extreme.at(3));

    std::set<Vector3Type> processed{};
    for (auto i = 0; i < 4; ++i)
    {
        processed.emplace(sVertices.at(extreme.at(i)));
    }

    for (auto i = 0; i < numVertices; ++i)
    {
        if (processed.find(sVertices.at(i)) == processed.end())
        {
            Update(i);
            processed.emplace(sVertices.at(i));
        }
    }

    numUniqueVertices = boost::numeric_cast<int>(processed.size());

    std::map<TetrahedronSharedPtr, int> permute{};
    auto i = -1;
    permute[nullptr] = i++;
    const auto& smap = tetraMesh.GetTetrahedra();

    for (auto element = smap.begin(); element != smap.end(); ++element)
    {
        permute[element->second] = i++;
    }

    auto numSimplices = boost::numeric_cast<int>(tetraMesh.GetTetrahedra().size());
    this->SetNumSimplices(numSimplices);
    if (numSimplices > 0)
    {
        for (auto element = smap.begin(); element != smap.end(); ++element)
        {
            const auto& tetra = element->second;
            for (int j = 0; j < 4; ++j, ++i)
            {
                this->AddIndex(tetra->v.at(j));
                this->AddAdjacency(permute[tetra->s.at(j)]);
            }
        }

        MATHEMATICS_ASSERTION_0(i == 4 * numSimplices, "意外的不匹配。\n");

        pathLast = -1;

        const auto size = numSimplices + 1;
        path.resize(size);
    }
}

template <typename Real>
typename Mathematics::Delaunay3<Real>::Vertices Mathematics::Delaunay3<Real>::GetVertices() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return vertices;
}

template <typename Real>
int Mathematics::Delaunay3<Real>::GetNumUniqueVertices() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return numUniqueVertices;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::Delaunay3<Real>::GetLineOrigin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return lineOrigin;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::Delaunay3<Real>::GetLineDirection() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return lineDirection;
}

template <typename Real>
Mathematics::Delaunay1<Real> Mathematics::Delaunay3<Real>::GetDelaunay1() const
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
        projection.emplace_back(Vector3Tools<Real>::DotProduct(lineDirection, diff));
    }

    Delaunay1Type delaunay1{ projection, this->GetEpsilon(), this->GetQueryType() };

    return delaunay1;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::Delaunay3<Real>::GetPlaneOrigin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return planeOrigin;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::Delaunay3<Real>::GetPlaneDirection(int i) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return planeDirection.at(i);
}

template <typename Real>
Mathematics::Delaunay2<Real> Mathematics::Delaunay3<Real>::GetDelaunay2() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto dimension = this->GetDimension();

    if (dimension != 2)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("维度必须为2。"));
    }

    const auto numVertices = this->GetNumVertices();
    typename Delaunay2::Vertices projection(numVertices);
    for (int i = 0; i < numVertices; ++i)
    {
        auto diff = vertices.at(i) - planeOrigin;
        projection.at(i)[0] = Vector3Tools<Real>::DotProduct(planeDirection.at(0), diff);
        projection.at(i)[1] = Vector3Tools<Real>::DotProduct(planeDirection.at(1), diff);
    }

    return Delaunay2{ projection, this->GetEpsilon(), this->GetQueryType() };
}

template <typename Real>
typename Mathematics::Delaunay3<Real>::HullType Mathematics::Delaunay3<Real>::GetHull() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto dimension = this->GetDimension();

    if (dimension != 3)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("维度必须为3。"));
    }

    auto numTriangles = 0;

    const auto numAdjacent = 4 * this->GetNumSimplices();
    for (auto i = 0; i < numAdjacent; ++i)
    {
        if (this->GetAdjacency(i) == -1)
        {
            ++numTriangles;
        }
    }

    MATHEMATICS_ASSERTION_0(numTriangles > 0, "必须至少有一个四面体。\n");

    if (numTriangles == 0)
    {
        return { IndicesType{}, false };
    }

    auto currentIndex = 0;

    const auto size = 3 * numTriangles;
    IndicesType indices(size);
    for (auto i = 0; i < numAdjacent; ++i)
    {
        if (this->GetAdjacency(i) == -1)
        {
            const auto tetra = i / 4;
            const auto face = i % 4;
            for (auto j = 0; j < 4; ++j)
            {
                if (j != face)
                {
                    indices.at(currentIndex++) = this->GetIndex(4 * tetra + j);
                }
            }

            if ((face % 2) != 0)
            {
                const auto lhsIndex = currentIndex - 1;
                const auto rhsIndex = currentIndex - 2;
                std::swap(indices.at(lhsIndex), indices.at(rhsIndex));
            }
        }
    }

    return { indices, true };
}

template <typename Real>
int Mathematics::Delaunay3<Real>::GetContainingTetrahedron(const Vector3Type& p) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto dimension = this->GetDimension();

    if (dimension != 3)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("维度必须为3。"));
    }

    auto scP = (p - min) * scale;

    auto pathIndex = (pathLast >= 0 ? path.at(pathLast) : 0);
    pathLast = -1;
    lastFaceV0 = -1;
    lastFaceV1 = -1;
    lastFaceV2 = -1;
    lastFaceOpposite = -1;
    lastFaceOppositeIndex = -1;

    const auto numSimplices = this->GetNumSimplices();

    for (auto i = 0; i < numSimplices; ++i)
    {
        path.at(++pathLast) = pathIndex;

        if (System::EnumCastUnderlying(query->ToPlane(scP, this->GetIndex(4 * pathIndex + 1), this->GetIndex(4 * pathIndex + 2), this->GetIndex(4 * pathIndex + 3))) > 0)
        {
            pathIndex = this->GetAdjacency(4 * pathIndex);
            if (pathIndex == -1)
            {
                lastFaceV0 = this->GetIndex(4 * pathIndex + 1);
                lastFaceV1 = this->GetIndex(4 * pathIndex + 2);
                lastFaceV2 = this->GetIndex(4 * pathIndex + 3);
                lastFaceOpposite = this->GetIndex(4 * pathIndex);
                lastFaceOppositeIndex = 0;
                return -1;
            }
            continue;
        }

        if (System::EnumCastUnderlying(query->ToPlane(scP, this->GetIndex(4 * pathIndex), this->GetIndex(4 * pathIndex + 2), this->GetIndex(4 * pathIndex + 3))) < 0)
        {
            pathIndex = this->GetAdjacency(4 * pathIndex + 1);
            if (pathIndex == -1)
            {
                lastFaceV0 = this->GetIndex(4 * pathIndex);
                lastFaceV1 = this->GetIndex(4 * pathIndex + 2);
                lastFaceV2 = this->GetIndex(4 * pathIndex + 3);
                lastFaceOpposite = this->GetIndex(4 * pathIndex + 1);
                lastFaceOppositeIndex = 1;
                return -1;
            }
            continue;
        }

        if (System::EnumCastUnderlying(query->ToPlane(scP, this->GetIndex(4 * pathIndex), this->GetIndex(4 * pathIndex + 1), this->GetIndex(4 * pathIndex + 3))) > 0)
        {
            pathIndex = this->GetAdjacency(4 * pathIndex + 2);
            if (pathIndex == -1)
            {
                lastFaceV0 = this->GetIndex(4 * pathIndex);
                lastFaceV1 = this->GetIndex(4 * pathIndex + 1);
                lastFaceV2 = this->GetIndex(4 * pathIndex + 3);
                lastFaceOpposite = this->GetIndex(4 * pathIndex + 2);
                lastFaceOppositeIndex = 2;
                return -1;
            }
            continue;
        }

        if (System::EnumCastUnderlying(query->ToPlane(scP, this->GetIndex(4 * pathIndex), this->GetIndex(4 * pathIndex + 1), this->GetIndex(4 * pathIndex + 2))) < 0)
        {
            pathIndex = this->GetAdjacency(4 * pathIndex + 3);
            if (pathIndex == -1)
            {
                lastFaceV0 = this->GetIndex(4 * pathIndex);
                lastFaceV1 = this->GetIndex(4 * pathIndex + 1);
                lastFaceV2 = this->GetIndex(4 * pathIndex + 2);
                lastFaceOpposite = this->GetIndex(4 * pathIndex + 3);
                lastFaceOppositeIndex = 3;
                return -1;
            }
            continue;
        }

        lastFaceV0 = -1;
        lastFaceV1 = -1;
        lastFaceV2 = -1;
        lastFaceOppositeIndex = -1;

        return pathIndex;
    }

    return -1;
}

template <typename Real>
int Mathematics::Delaunay3<Real>::GetPathLast() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return pathLast;
}

template <typename Real>
typename Mathematics::Delaunay3<Real>::IndicesType Mathematics::Delaunay3<Real>::GetPath() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return path;
}

template <typename Real>
int Mathematics::Delaunay3<Real>::GetLastFace(int& v0, int& v1, int& v2, int& v3) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    v0 = lastFaceV0;
    v1 = lastFaceV1;
    v2 = lastFaceV2;
    v3 = lastFaceOpposite;

    return lastFaceOppositeIndex;
}

template <typename Real>
typename Mathematics::Delaunay3<Real>::VertexType Mathematics::Delaunay3<Real>::GetVertexSet(int i) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto dimension = this->GetDimension();

    if (dimension != 3)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("维度必须为3。"));
    }

    const auto numSimplices = this->GetNumSimplices();

    if (0 <= i && i < numSimplices)
    {
        return { vertices.at(this->GetIndex(4 * i)),
                 vertices.at(this->GetIndex(4 * i + 1)),
                 vertices.at(this->GetIndex(4 * i + 2)),
                 vertices.at(this->GetIndex(4 * i + 3)),
                 true };
    }

    return { Vector3Type{}, Vector3Type{}, Vector3Type{}, Vector3Type{}, false };
}

template <typename Real>
typename Mathematics::Delaunay3<Real>::IndexType Mathematics::Delaunay3<Real>::GetIndexSet(int i) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto dimension = this->GetDimension();

    if (dimension != 3)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("维度必须为3。"));
    }

    const auto numSimplices = this->GetNumSimplices();

    if (0 <= i && i < numSimplices)
    {
        return { this->GetIndex(4 * i), this->GetIndex(4 * i + 1), this->GetIndex(4 * i + 2), this->GetIndex(4 * i + 3), true };
    }

    return { -1, -1, -1, -1, false };
}

template <typename Real>
typename Mathematics::Delaunay3<Real>::IndexType Mathematics::Delaunay3<Real>::GetAdjacentSet(int i) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto dimension = this->GetDimension();

    if (dimension != 3)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("维度必须为3。"));
    }

    const auto numSimplices = this->GetNumSimplices();

    if (0 <= i && i < numSimplices)
    {
        return { this->GetAdjacency(4 * i), this->GetAdjacency(4 * i + 1), this->GetAdjacency(4 * i + 2), this->GetAdjacency(4 * i + 3), true };
    }

    return { -1, -1, -1, -1, false };
}

template <typename Real>
typename Mathematics::Delaunay3<Real>::BaryType Mathematics::Delaunay3<Real>::GetBarycentricSet(int i, const Vector3Type& p) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto dimension = this->GetDimension();

    if (dimension != 3)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("维度必须为3。"));
    }

    const auto numSimplices = this->GetNumSimplices();

    if (0 <= i && i < numSimplices)
    {
        const auto& v0 = vertices.at(this->GetIndex(4 * i));
        const auto& v1 = vertices.at(this->GetIndex(4 * i + 1));
        const auto& v2 = vertices.at(this->GetIndex(4 * i + 2));
        const auto& v3 = vertices.at(this->GetIndex(4 * i + 3));
        const auto barycentricCoordinates = p.GetBarycentrics(v0, v1, v2, v3);

        return { barycentricCoordinates[0], barycentricCoordinates[1], barycentricCoordinates[2], barycentricCoordinates[3], true };
    }

    return { Math<Real>::GetValue(0), Math<Real>::GetValue(0), Math<Real>::GetValue(0), Math<Real>::GetValue(0), true };
}

template <typename Real>
Mathematics::Delaunay3<Real>::Delaunay3(const String& filename)
    : ParentType{ 0, Math<Real>::GetValue(0), QueryType::Real },
      vertices{},
      numUniqueVertices{ 0 },
      sVertices{},
      query{ 0 },
      min{},
      scale{},
      tetraMesh{},
      lineOrigin{},
      lineDirection{},
      planeOrigin{},
      planeDirection{},
      pathLast{ -1 },
      path{},
      lastFaceV0{ -1 },
      lastFaceV1{ -1 },
      lastFaceV2{ -1 },
      lastFaceOpposite{ -1 },
      lastFaceOppositeIndex{}
{
    LoadFile(filename);

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
void Mathematics::Delaunay3<Real>::LoadFile(const String& filename)
{
    CoreTools::ReadFileManager inFile{ filename };

    if (!ParentType::Load(inFile))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("加载文件失败\n"));
    }

    const auto numVertices = this->GetNumVertices();

    query.reset();
    path.clear();
    vertices.resize(numVertices);
    sVertices.resize(numVertices);

    const auto numSimplices = this->GetNumSimplices();
    const auto pathSize = numSimplices + 1;
    path.resize(pathSize);

    inFile.Read(sizeof(int32_t), &numUniqueVertices);
    inFile.Read(sizeof(int32_t), &pathLast);
    inFile.Read(sizeof(int32_t), &lastFaceV0);
    inFile.Read(sizeof(int32_t), &lastFaceV1);
    inFile.Read(sizeof(int32_t), &lastFaceV2);
    inFile.Read(sizeof(int32_t), &lastFaceOpposite);
    inFile.Read(sizeof(int32_t), &lastFaceOppositeIndex);
    inFile.Read(sizeof(int32_t), pathSize, path.data());

    const auto threeNumVertices = Vector3Type::pointSize * numVertices;

    inFile.Read(sizeof(Real), threeNumVertices, vertices.data());
    inFile.Read(sizeof(Real), threeNumVertices, sVertices.data());
    inFile.Read(sizeof(Real), Vector3Type::pointSize, &min);
    inFile.Read(sizeof(Real), Vector3Type::pointSize, &scale);
    inFile.Read(sizeof(Real), Vector3Type::pointSize, &lineOrigin);
    inFile.Read(sizeof(Real), Vector3Type::pointSize, &lineDirection);
    inFile.Read(sizeof(Real), Vector3Type::pointSize, &planeOrigin);
    inFile.Read(sizeof(Real), 6, planeDirection.data());

    const auto queryType = this->GetQueryType();
    switch (queryType)
    {
        case QueryType::Int64:
        {
            query = std::make_shared<Query3Int64<Real>>(sVertices);
            break;
        }
        case QueryType::Integer:
        {
            query = std::make_shared<Query3Integer<Real>>(sVertices);
            break;
        }
        case QueryType::Rational:
        {
            query = std::make_shared<Query3Rational<Real>>(sVertices);
            break;
        }
        case QueryType::Real:
        {
            query = std::make_shared<Query3>(sVertices);
            break;
        }
        case QueryType::Filtered:
        {
            query = std::make_shared<Query3Filtered<Real>>(sVertices, this->GetEpsilon());
            break;
        }
    }
}

template <typename Real>
void Mathematics::Delaunay3<Real>::SaveFile(const String& filename) const
{
    CoreTools::WriteFileManager outFile{ filename };

    if (!ParentType::Save(outFile))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("保存文件失败\n"));
    }

    const auto numSimplices = this->GetNumSimplices();
    const auto pathSize = numSimplices + 1;

    outFile.Write(sizeof(int32_t), &numUniqueVertices);
    outFile.Write(sizeof(int32_t), &pathLast);
    outFile.Write(sizeof(int32_t), &lastFaceV0);
    outFile.Write(sizeof(int32_t), &lastFaceV1);
    outFile.Write(sizeof(int32_t), &lastFaceV2);
    outFile.Write(sizeof(int32_t), &lastFaceOpposite);
    outFile.Write(sizeof(int32_t), &lastFaceOpposite);
    outFile.Write(sizeof(int32_t), pathSize, path.data());

    const auto numVertices = this->GetNumVertices();
    const auto threeNumVertices = Vector3Type::pointSize * numVertices;

    outFile.Write(sizeof(Real), threeNumVertices, vertices.data());
    outFile.Write(sizeof(Real), threeNumVertices, sVertices.data());
    outFile.Write(sizeof(Real), Vector3Type::pointSize, &min);
    outFile.Write(sizeof(Real), Vector3Type::pointSize, &scale);
    outFile.Write(sizeof(Real), Vector3Type::pointSize, &lineOrigin);
    outFile.Write(sizeof(Real), Vector3Type::pointSize, &lineDirection);
    outFile.Write(sizeof(Real), Vector3Type::pointSize, &planeOrigin);
    outFile.Write(sizeof(Real), 6, planeDirection.data());
}

template <typename Real>
bool Mathematics::Delaunay3<Real>::GetContainingTetrahedron(int i, const Tetrahedron& tetra) const
{
    const auto numTetra = tetraMesh.GetTetrahedra().size();
    for (auto t = 0u; t < numTetra; ++t)
    {
        auto j = 0;
        for (; j < 4; ++j)
        {
            const std::array<int, 3> face{ TetrahedronKey::oppositeFace.at(j).at(0), TetrahedronKey::oppositeFace.at(j).at(1), TetrahedronKey::oppositeFace.at(j).at(2) };
            if (System::EnumCastUnderlying(query->ToPlane(i, tetra.v.at(face.at(0)), tetra.v.at(face.at(1)), tetra.v.at(face.at(2)))) > 0)
            {
                if (tetra.s.at(j))
                {
                    break;
                }
                else
                {
                    return false;
                }
            }
        }

        if (j == 4)
        {
            return true;
        }
    }

    return false;
}

template <typename Real>
void Mathematics::Delaunay3<Real>::GetAndRemoveInsertionPolyhedron(int i, std::set<TetrahedronSharedPtr>& candidates, std::set<TriangleKey>& boundary)
{
    TSManifoldMesh polyhedron{};
    while (!candidates.empty())
    {
        auto tetra = *candidates.begin();
        candidates.erase(candidates.begin());

        for (auto j = 0; j < 4; ++j)
        {
            auto adj = tetra->s.at(j);
            if (adj && candidates.find(adj) == candidates.end())
            {
                if (System::EnumCastUnderlying(query->ToCircumsphere(i, adj->v.at(0), adj->v.at(1), adj->v.at(2), adj->v.at(3))) <= 0)
                {
                    candidates.emplace(adj);
                }
            }
        }

        polyhedron.Insert(tetra->v.at(0), tetra->v.at(1), tetra->v.at(2), tetra->v.at(3));
        tetraMesh.Remove(tetra->v.at(0), tetra->v.at(1), tetra->v.at(2), tetra->v.at(3));
    }

    const auto& smap = polyhedron.GetTetrahedra();

    for (auto element = smap.begin(); element != smap.end(); ++element)
    {
        auto tetra = element->second;
        for (int j = 0; j < 4; ++j)
        {
            if (!tetra->s.at(j))
            {
                const std::array<int, 3> face{ TetrahedronKey::oppositeFace.at(j).at(0),
                                               TetrahedronKey::oppositeFace.at(j).at(1),
                                               TetrahedronKey::oppositeFace.at(j).at(2) };
                boundary.emplace(tetra->v.at(face.at(0)), tetra->v.at(face.at(1)), tetra->v.at(face.at(2)));
            }
        }
    }
}

template <typename Real>
void Mathematics::Delaunay3<Real>::Update(int i)
{
    const auto& smap = tetraMesh.GetTetrahedra();
    auto tetra = smap.begin()->second;
    if (GetContainingTetrahedron(i, *tetra))
    {
        std::set<TetrahedronSharedPtr> candidates{ tetra };

        std::set<TriangleKey> boundary{};
        GetAndRemoveInsertionPolyhedron(i, candidates, boundary);

        for (const auto& key : boundary)
        {
            tetraMesh.Insert(i, key.GetKey(0), key.GetKey(1), key.GetKey(2));
        }
    }
    else
    {
        std::set<TriangleKey> hull{};

        for (auto element = smap.begin(); element != smap.end(); ++element)
        {
            auto value = element->second;
            for (int j = 0; j < 4; ++j)
            {
                if (!value->s.at(j))
                {
                    const std::array<int, 3> face{ TetrahedronKey::oppositeFace.at(j).at(0),
                                                   TetrahedronKey::oppositeFace.at(j).at(1),
                                                   TetrahedronKey::oppositeFace.at(j).at(2) };
                    hull.emplace(value->v.at(face.at(0)), value->v.at(face.at(1)), value->v.at(face.at(2)));
                }
            }
        }

        const auto& trimap = tetraMesh.GetTriangles();
        std::set<TetrahedronSharedPtr> candidates{};
        std::set<TriangleKey> visible{};

        for (const auto& key : hull)
        {
            if (System::EnumCastUnderlying(query->ToPlane(i, key.GetKey(0), key.GetKey(1), key.GetKey(2))) > 0)
            {
                const auto iter = trimap.find(UnorderedTriangleKey(key.GetKey(0), key.GetKey(1), key.GetKey(2)));
                if (iter == trimap.end())
                {
                    THROW_EXCEPTION(SYSTEM_TEXT("意外情况\n"));
                }

                MATHEMATICS_ASSERTION_0(iter->second->t.at(1) == 0, "意外情况\n");

                auto adj = iter->second->t.at(0);
                if (adj && candidates.find(adj) == candidates.end())
                {
                    if (System::EnumCastUnderlying(query->ToCircumsphere(i, adj->v.at(0), adj->v.at(1), adj->v.at(2), adj->v.at(3))) <= 0)
                    {
                        candidates.emplace(adj);
                    }
                    else
                    {
                        visible.emplace(key);
                    }
                }
            }
        }

        std::set<TriangleKey> boundary{};
        GetAndRemoveInsertionPolyhedron(i, candidates, boundary);

        for (const auto& key : boundary)
        {
            if (System::EnumCastUnderlying(query->ToPlane(i, key.GetKey(0), key.GetKey(1), key.GetKey(2))) < 0)
            {
                tetraMesh.Insert(i, key.GetKey(0), key.GetKey(1), key.GetKey(2));
            }
        }

        for (const auto& key : visible)
        {
            tetraMesh.Insert(i, key.GetKey(0), key.GetKey(2), key.GetKey(1));
        }
    }
}

#endif  // MATHEMATICS_COMPUTATIONAL_GEOMETRY_DELAUNAY3_DETAIL_H