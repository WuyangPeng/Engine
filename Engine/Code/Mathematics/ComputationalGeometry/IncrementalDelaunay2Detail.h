///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:36)

#ifndef MATHEMATICS_COMPUTATIONAL_GEOMETRY_INCREMENTAL_DELAUNAY2_DETAIL_H
#define MATHEMATICS_COMPUTATIONAL_GEOMETRY_INCREMENTAL_DELAUNAY2_DETAIL_H

#include "IncrementalDelaunay2.h"
#include "CoreTools/DataTypes/MinHeapDetail.h"
#include "CoreTools/DataTypes/MinHeapRecordDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Rational/RationalVector2Detail.h"

#include <stack>

template <typename Real>
Mathematics::IncrementalDelaunay2<Real>::IncrementalDelaunay2(Real xmin, Real ymin, Real xmax, Real ymax, Real uncertainty)
    : xMin{ xmin },
      xMax{ xmax },
      yMin{ ymin },
      yMax{ ymax },
      vMap{},
      vertexPool{},
      uncertainty{ uncertainty },
      ratVertexPool{},
      ratVertexEvaluated{},
      triangle{},
      numTriangles{ 0 },
      indices{},
      adjacencies{},
      pathLast{ -1 },
      path{},
      lastEdgeV0{ -1 },
      lastEdgeV1{ -1 },
      lastEdgeOpposite{ -1 },
      lastEdgeOppositeIndex{ -1 }
{
    MATHEMATICS_ASSERTION_0(xMin < xMax && yMin < yMax, "矩形边界无效。\n");
    MATHEMATICS_ASSERTION_0(Math<Real>::GetValue(0) <= uncertainty && uncertainty <= Math<Real>::GetValue(1), "无效的不确定性。\n");

    if (Math<Real>::GetValue(0) < uncertainty)
    {
        ratVertexPool = std::make_shared<std::vector<QRVector>>();
        ratVertexEvaluated = std::make_shared<std::vector<bool>>();
    }

    const auto x0 = (Math<Real>::GetValue(2)) * xmin - xmax;
    const auto y0 = (Math<Real>::GetValue(2)) * ymin - ymax;
    const auto x1 = (Math<Real>::GetValue(2)) * xmax - xmin + (Math<Real>::GetValue(3)) * (ymax - ymin);
    const auto y1 = y0;
    const auto x2 = x0;
    const auto y2 = (Math<Real>::GetValue(2)) * ymax - ymin + (Math<Real>::GetValue(3)) * (xmax - xmin);
    const Vector2 superVertex0{ x0, y0 };
    const Vector2 superVertex1{ x1, y1 };
    const Vector2 superVertex2{ x2, y2 };

    vMap[superVertex0] = 0;
    vMap[superVertex1] = 1;
    vMap[superVertex2] = 2;
    vertexPool.emplace_back(superVertex0);
    vertexPool.emplace_back(superVertex1);
    vertexPool.emplace_back(superVertex2);

    triangle.emplace(std::make_shared<Triangle>(0, 1, 2));

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::IncrementalDelaunay2<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
int Mathematics::IncrementalDelaunay2<Real>::Insert(const Vector2& position)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    if (position[0] < xMin || xMax < position[0] || position[1] < yMin || yMax < position[1])
    {
        return -1;
    }

    const auto viter = vMap.find(position);
    if (viter != vMap.end())
    {
        return viter->second;
    }

    const auto posIndex = boost::numeric_cast<int>(vertexPool.size());
    vMap[position] = posIndex;
    vertexPool.emplace_back(position);
    if (Math<Real>::GetValue(0) < uncertainty)
    {
        ratVertexPool->emplace_back(QRVector{});
        ratVertexEvaluated->emplace_back(false);
    }

    auto tri = GetContainingTriangleInternal(position);
    if (!tri)
    {
        MATHEMATICS_ASSERTION_0(false, "Unexpected condition\n");
        return -1;
    }

    std::stack<TriangleSharedPtr> triStack{};
    VEManifoldMesh polygon{ 0, Edge::EdgeCreator };
    triStack.emplace(tri);
    tri->onStack = true;

    while (!triStack.empty())
    {
        tri = triStack.top();
        triStack.pop();
        tri->onStack = false;
        for (auto j = 0; j < 3; ++j)
        {
            auto adj = tri->adjTriangle.at(j);
            if (adj)
            {
                const auto nullIndex = tri->DetachFrom(j, adj);

                if (adj->IsInsertionComponent(posIndex, position, tri, *this))
                {
                    if (!adj->onStack)
                    {
                        triStack.emplace(adj);
                        adj->onStack = true;
                    }
                }
                else
                {
                    auto v0 = tri->v.at(j);
                    auto v1 = tri->v.at((j + 1) % 3);
                    auto edge = std::dynamic_pointer_cast<Edge>(polygon.InsertEdge(v0, v1));
                    edge->nullIndex = nullIndex;
                    edge->tri = adj;
                }
            }
            else
            {
                auto v0 = tri->v.at(j);
                if (0 <= v0 && v0 <= 2)
                {
                    auto v1 = tri->v.at((j + 1) % 3);
                    if (0 <= v1 && v1 <= 2)
                    {
                        auto edge = std::dynamic_pointer_cast<Edge>(polygon.InsertEdge(v0, v1));
                        edge->nullIndex = -1;
                        edge->tri = 0;
                    }
                }
            }
        }

        triangle.erase(tri);
    }

    const auto& edgeMap = polygon.GetEdges();

    MATHEMATICS_ASSERTION_0(3 <= edgeMap.size() && polygon.IsClosed(), "多边形必须至少是一个三角形。\n");

    for (const auto& iter : edgeMap)
    {
        auto edge = std::dynamic_pointer_cast<Edge>(iter.second);

        tri = std::make_shared<Triangle>(posIndex, edge->v.at(0), edge->v.at(1));
        triangle.emplace(tri);

        tri->adjTriangle.at(1) = edge->tri;
        if (edge->tri)
        {
            edge->tri->adjTriangle.at(edge->nullIndex) = tri;
        }

        edge->tri = tri;
    }

    for (const auto& iter : edgeMap)
    {
        auto edge = std::dynamic_pointer_cast<Edge>(iter.second);
        auto adjEdge = std::dynamic_pointer_cast<Edge>(edge->e.at(0));
        edge->tri->adjTriangle.at(0) = adjEdge->tri;
        adjEdge = std::dynamic_pointer_cast<Edge>(edge->e.at(1));
        edge->tri->adjTriangle.at(2) = adjEdge->tri;
    }

    return posIndex;
}

template <typename Real>
int Mathematics::IncrementalDelaunay2<Real>::Remove(const Vector2& position)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    const auto iter = vMap.find(position);
    if (iter == vMap.end())
    {
        return -1;
    }
    const auto posIndex = iter->second;

    auto initialTri = GetContainingTriangleInternal(position);
    if (!initialTri)
    {
        return -1;
    }

    std::vector<RPVertex> polygon{};
    auto tri = initialTri;
    do
    {
        auto i = 0;
        for (; i < 3; ++i)
        {
            if (tri->v.at(i) == posIndex)
            {
                break;
            }
        }
        if (i == 3)
        {
            return -1;
        }

        polygon.emplace_back(RPVertex{ tri->v.at((i + 1) % 3), tri, tri->adjTriangle.at(i) });
        tri = tri->adjTriangle.at((i + 2) % 3);
    } while (tri != initialTri);

    Triangulate Triangulate{ polygon, posIndex, this };
    vMap.erase(iter);

    return posIndex;
}

template <typename Real>
typename Mathematics::IncrementalDelaunay2<Real>::HullType Mathematics::IncrementalDelaunay2<Real>::GetAllTriangles() const
{
    MATHEMATICS_CLASS_IS_VALID_1;

    IndicesType result{};

    for (const auto& tri : triangle)
    {
        for (auto i = 0; i < 3; ++i)
        {
            result.emplace_back(tri->v.at(i));
        }
    }

    return HullType{ result, true };
}

template <typename Real>
void Mathematics::IncrementalDelaunay2<Real>::GenerateRepresentation()
{
    MATHEMATICS_CLASS_IS_VALID_1;

    indices.clear();
    adjacencies.clear();
    path.clear();

    std::map<TriangleSharedPtr, int> permute{};

    numTriangles = boost::numeric_cast<int>(triangle.size());

    auto i = 0;
    for (auto iter = triangle.begin(); iter != triangle.end(); ++iter)
    {
        auto tri = *iter;

        if ((0 <= tri->v.at(0) && tri->v.at(0) <= 2) || (0 <= tri->v.at(1) && tri->v.at(1) <= 2) || (0 <= tri->v.at(2) && tri->v.at(2) <= 2))
        {
            --numTriangles;
            continue;
        }

        permute[tri] = i;
        ++i;
    }
    permute[nullptr] = -1;

    if (numTriangles > 0)
    {
        const auto size = 3 * numTriangles;
        indices.resize(size);
        adjacencies.resize(size);

        i = 0;

        for (auto iter = triangle.begin(); iter != triangle.end(); ++iter)
        {
            auto tri = *iter;

            if ((0 <= tri->v.at(0) && tri->v.at(0) <= 2) || (0 <= tri->v.at(1) && tri->v.at(1) <= 2) || (0 <= tri->v.at(2) && tri->v.at(2) <= 2))
            {
                continue;
            }

            indices.at(i) = tri->v.at(0);
            if (ContainsSupervertex(*tri->adjTriangle.at(0)))
            {
                adjacencies.at(i++) = -1;
            }
            else
            {
                adjacencies.at(i++) = permute.at(tri->adjTriangle.at(0));
            }

            indices.at(i) = tri->v.at(1);
            if (ContainsSupervertex(*tri->adjTriangle.at(1)))
            {
                adjacencies.at(i++) = -1;
            }
            else
            {
                adjacencies.at(i++) = permute[tri->adjTriangle.at(1)];
            }

            indices.at(i) = tri->v.at(2);
            if (ContainsSupervertex(*tri->adjTriangle.at(2)))
            {
                adjacencies.at(i++) = -1;
            }
            else
            {
                adjacencies.at(i++) = permute[tri->adjTriangle.at(2)];
            }
        }
        MATHEMATICS_ASSERTION_0(i == 3 * numTriangles, "条件不一致。\n");

        pathLast = -1;

        const auto pathSize = numTriangles + 1;
        path.resize(pathSize);
    }
}

template <typename Real>
int Mathematics::IncrementalDelaunay2<Real>::GetNumTriangles() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return numTriangles;
}

template <typename Real>
typename Mathematics::IncrementalDelaunay2<Real>::IndicesType Mathematics::IncrementalDelaunay2<Real>::GetIndices() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return indices;
}

template <typename Real>
typename Mathematics::IncrementalDelaunay2<Real>::IndicesType Mathematics::IncrementalDelaunay2<Real>::GetAdjacencies() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return adjacencies;
}

template <typename Real>
std::vector<Mathematics::Vector2<Real>> Mathematics::IncrementalDelaunay2<Real>::GetVertices() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return vertexPool;
}

template <typename Real>
std::map<Mathematics::Vector2<Real>, int> Mathematics::IncrementalDelaunay2<Real>::GetUniqueVertices() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return vMap;
}

template <typename Real>
typename Mathematics::IncrementalDelaunay2<Real>::HullType Mathematics::IncrementalDelaunay2<Real>::GetHull() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    auto numEdges = 0;

    const auto adjQuantity = 3 * numTriangles;
    for (auto i = 0; i < adjQuantity; ++i)
    {
        if (adjacencies.at(i) == -1)
        {
            ++numEdges;
        }
    }

    MATHEMATICS_ASSERTION_0(numEdges > 0, "意外情况。\n");

    if (numEdges == 0)
    {
        return { IndicesType{}, false };
    }

    IndicesType indicesType{};

    for (auto i = 0; i < adjQuantity; ++i)
    {
        if (adjacencies.at(i) == -1)
        {
            const auto tri = i / 3;
            const auto j = i % 3;
            const auto index0 = 3 * tri + j;
            const auto index1 = 3 * tri + ((j + 1) % 3);
            indicesType.emplace_back(indices.at(index0));
            indicesType.emplace_back(indices.at(index1));
        }
    }

    return HullType{ indicesType, true };
}

template <typename Real>
int Mathematics::IncrementalDelaunay2<Real>::GetContainingTriangle(const Vector2& test) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (path.empty())
    {
        return -1;
    }

    auto pathIndex = (pathLast >= 0 ? path.at(pathLast) : 0);
    pathLast = -1;
    lastEdgeV0 = -1;
    lastEdgeV1 = -1;
    lastEdgeOpposite = -1;
    lastEdgeOppositeIndex = -1;

    const auto index0 = 3 * pathIndex;
    const auto index1 = index0 + 1;
    const auto index2 = index0 + 2;

    for (auto i = 0; i < numTriangles; i++)
    {
        path.at(++pathLast) = pathIndex;

        if (ToLine(test, indices.at(index0), indices.at(index1)) > 0)
        {
            pathIndex = adjacencies.at(index0);
            if (pathIndex == -1)
            {
                lastEdgeV0 = indices.at(index0);
                lastEdgeV1 = indices.at(index1);
                lastEdgeOpposite = indices.at(index2);
                lastEdgeOppositeIndex = 2;
                return -1;
            }
            continue;
        }

        if (ToLine(test, indices.at(index1), indices.at(index2)) > 0)
        {
            pathIndex = adjacencies.at(index1);
            if (pathIndex == -1)
            {
                lastEdgeV0 = indices.at(index1);
                lastEdgeV1 = indices.at(index2);
                lastEdgeOpposite = indices.at(index0);
                lastEdgeOppositeIndex = 0;
                return -1;
            }
            continue;
        }

        if (ToLine(test, indices.at(index2), indices.at(index0)) > 0)
        {
            pathIndex = adjacencies.at(index2);
            if (pathIndex == -1)
            {
                lastEdgeV0 = indices.at(index2);
                lastEdgeV1 = indices.at(index0);
                lastEdgeOpposite = indices.at(index1);
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
int Mathematics::IncrementalDelaunay2<Real>::GetPathLast() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return pathLast;
}

template <typename Real>
typename Mathematics::IncrementalDelaunay2<Real>::IndicesType Mathematics::IncrementalDelaunay2<Real>::GetPath() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return path;
}

template <typename Real>
int Mathematics::IncrementalDelaunay2<Real>::GetLastEdge(int& riV0, int& riV1, int& riV2) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    riV0 = lastEdgeV0;
    riV1 = lastEdgeV1;
    riV2 = lastEdgeOpposite;

    return lastEdgeOppositeIndex;
}

template <typename Real>
std::array<Mathematics::Vector2<Real>, 3> Mathematics::IncrementalDelaunay2<Real>::GetVertexSet(int i) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    std::array<Mathematics::Vector2<Real>, 3> akV{};
    if (0 <= i && i < numTriangles)
    {
        const auto index0 = 3 * i;
        const auto index1 = 3 * i + 1;
        const auto index2 = 3 * i + 2;

        akV.at(0) = vertexPool.at(indices.at(index0));
        akV.at(1) = vertexPool.at(indices.at(index1));
        akV.at(2) = vertexPool.at(indices.at(index2));

        return akV;
    }

    return akV;
}

template <typename Real>
std::array<int32_t, 3> Mathematics::IncrementalDelaunay2<Real>::GetIndexSet(int i) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    std::array<int32_t, 3> aiIndex{};
    if (0 <= i && i < numTriangles)
    {
        const auto index0 = 3 * i;
        const auto index1 = 3 * i + 1;
        const auto index2 = 3 * i + 2;

        aiIndex.at(0) = indices.at(index0);
        aiIndex.at(1) = indices.at(index1);
        aiIndex.at(2) = indices.at(index2);

        return aiIndex;
    }

    return aiIndex;
}

template <typename Real>
std::array<int32_t, 3> Mathematics::IncrementalDelaunay2<Real>::GetAdjacentSet(int i) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    std::array<int32_t, 3> aiAdjacent{};
    if (0 <= i && i < numTriangles)
    {
        const auto index0 = 3 * i;
        const auto index1 = 3 * i + 1;
        const auto index2 = 3 * i + 2;

        aiAdjacent.at(0) = adjacencies.at(index0);
        aiAdjacent.at(1) = adjacencies.at(index1);
        aiAdjacent.at(2) = adjacencies.at(index2);

        return aiAdjacent;
    }

    return aiAdjacent;
}

template <typename Real>
std::array<Real, 3> Mathematics::IncrementalDelaunay2<Real>::GetBarycentricSet(int i, const Vector2& test) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    std::array<Real, 3> afBary{};
    if (0 <= i && i < numTriangles)
    {
        const auto index0 = 3 * i;
        const auto index1 = 3 * i + 1;
        const auto index2 = 3 * i + 2;

        const auto& kV0 = vertexPool.at(indices.at(index0));
        const auto& kV1 = vertexPool.at(indices.at(index1));
        const auto& kV2 = vertexPool.at(indices.at(index2));

        const auto barycentricCoordinates = test.GetBarycentrics(kV0, kV1, kV2);
        for (auto j = 0; j < 3; ++j)
        {
            afBary.at(j) = barycentricCoordinates[j];
        }

        return afBary;
    }

    return afBary;
}

template <typename Real>
int Mathematics::IncrementalDelaunay2<Real>::ToLine(const Vector2& test, int v0, int v1) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (uncertainty < Math<Real>::GetValue(1))
    {
        auto vertex0 = vertexPool.at(v0);
        auto vertex1 = vertexPool.at(v1);
        auto positive = false;
        if (vertex0 < vertex1)
        {
            positive = true;
        }
        else
        {
            auto kSave = vertex0;
            vertex0 = vertex1;
            vertex1 = kSave;
            positive = false;
        }

        auto x0 = test[0] - vertex0[0];
        auto y0 = test[1] - vertex0[1];
        auto x1 = vertex1[0] - vertex0[0];
        auto y1 = vertex1[1] - vertex0[1];
        auto det = x0 * y1 - x1 * y0;
        if (!positive)
        {
            det = -det;
        }

        if (Math<Real>::Approximate(uncertainty, Math<Real>::GetValue(0)))
        {
            return (Math<Real>::GetValue(0) < det ? +1 : (det < Math<Real>::GetValue(0) ? -1 : 0));
        }

        auto length0 = Math<Real>::Sqrt(x0 * x0 + y0 * y0);
        auto length1 = Math<Real>::Sqrt(x1 * x1 + y1 * y1);
        auto scaledUncertainty = uncertainty * length0 * length1;
        if (scaledUncertainty <= Math<Real>::FAbs(det))
        {
            return (Math<Real>::GetValue(0) < det ? +1 : (det < Math<Real>::GetValue(0) ? -1 : 0));
        }
    }

    const QRVector ratTest{ QRational{ test.GetX() }, QRational{ test.GetY() } };

    const std::array<int, 2> indicesArray{ v0, v1 };
    for (auto i = 0; i < 2; ++i)
    {
        auto j = indicesArray.at(i);
        if (!ratVertexEvaluated->at(j))
        {
            ratVertexEvaluated->at(j) = true;
            ratVertexPool->at(j).SetX(QRational{ vertexPool.at(j)[0] });
            ratVertexPool->at(j).SetY(QRational{ vertexPool.at(j)[1] });
        }
    }

    const auto& ratV0 = ratVertexPool->at(v0);
    const auto& ratV1 = ratVertexPool->at(v1);
    auto ratX0 = ratTest.GetX() - ratV0.GetX();
    auto ratY0 = ratTest.GetY() - ratV0.GetY();
    auto ratX1 = ratV1.GetX() - ratV0.GetX();
    auto ratY1 = ratV1.GetY() - ratV0.GetY();
    auto ratDet = ratX0 * ratY1 - ratX1 * ratY0;

    return (QRational{ 0 } < ratDet ? +1 : (ratDet < QRational{ 0 } ? -1 : 0));
}

template <typename Real>
int Mathematics::IncrementalDelaunay2<Real>::ToTriangle(const Vector2& test, int v0, int v1, int v2) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto sign0 = ToLine(test, v1, v2);
    if (sign0 > 0)
    {
        return +1;
    }

    const auto sign1 = ToLine(test, v0, v2);
    if (sign1 < 0)
    {
        return +1;
    }

    const auto sign2 = ToLine(test, v0, v1);
    if (sign2 > 0)
    {
        return +1;
    }

    return ((sign0 != 0 && sign1 != 0 && sign2 != 0) ? -1 : 0);
}

template <typename Real>
int Mathematics::IncrementalDelaunay2<Real>::ToCircumcircle(const Vector2& test, int v0, int v1, int v2) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (uncertainty < Math<Real>::GetValue(1))
    {
        auto vertex0 = vertexPool.at(v0);
        auto vertex1 = vertexPool.at(v1);
        auto vertex2 = vertexPool.at(v2);

        auto positive = false;
        if (vertex0 < vertex1)
        {
            if (vertex2 < vertex0)
            {
                // (2,0,1)
                auto save = vertex2;
                vertex2 = vertex1;
                vertex1 = vertex0;
                vertex0 = save;
                positive = true;
            }
            else if (vertex2 < vertex1)
            {
                // (0,2,1)
                auto save = vertex1;
                vertex1 = vertex2;
                vertex2 = save;
                positive = false;
            }
            else
            {
                // (0,1,2)
                positive = true;
            }
        }
        else
        {
            if (vertex2 < vertex1)
            {
                // (2,1,0)
                auto save = vertex0;
                vertex0 = vertex2;
                vertex2 = save;
                positive = false;
            }
            else if (vertex2 < vertex0)
            {
                // (1,2,0)
                auto save = vertex0;
                vertex0 = vertex1;
                vertex1 = vertex2;
                vertex2 = save;
                positive = true;
            }
            else
            {
                // (1,0,2)
                auto save = vertex0;
                vertex0 = vertex1;
                vertex1 = save;
                positive = false;
            }
        }

        auto s0x = vertex0[0] + test[0];
        auto d0x = vertex0[0] - test[0];
        auto s0y = vertex0[1] + test[1];
        auto d0y = vertex0[1] - test[1];
        auto s1x = vertex1[0] + test[0];
        auto d1x = vertex1[0] - test[0];
        auto s1y = vertex1[1] + test[1];
        auto d1y = vertex1[1] - test[1];
        auto s2x = vertex2[0] + test[0];
        auto d2x = vertex2[0] - test[0];
        auto s2y = vertex2[1] + test[1];
        auto d2y = vertex2[1] - test[1];
        auto z0 = s0x * d0x + s0y * d0y;
        auto z1 = s1x * d1x + s1y * d1y;
        auto z2 = s2x * d2x + s2y * d2y;
        auto c00 = d1y * z2 - d2y * z1;
        auto c01 = d2y * z0 - d0y * z2;
        auto c02 = d0y * z1 - d1y * z0;
        auto det = d0x * c00 + d1x * c01 + d2x * c02;
        if (!positive)
        {
            det = -det;
        }

        if (Math<Real>::Approximate(uncertainty, Math<Real>::GetValue(0)))
        {
            return (det < Math<Real>::GetValue(0) ? +1 : (det > Math<Real>::GetValue(0) ? -1 : 0));
        }

        auto length0 = Math<Real>::Sqrt(d0x * d0x + d0y * d0y + z0 * z0);
        auto length1 = Math<Real>::Sqrt(d1x * d1x + d1y * d1y + z1 * z1);
        auto length2 = Math<Real>::Sqrt(d2x * d2x + d2y * d2y + z2 * z2);
        auto scaledUncertainty = uncertainty * length0 * length1 * length2;
        if (Math<Real>::FAbs(det) >= scaledUncertainty)
        {
            return (det < Math<Real>::GetValue(0) ? 1 : (det > Math<Real>::GetValue(0) ? -1 : 0));
        }
    }

    const QRVector ratTest{ QRational{ test[0] }, QRational{ test[1] } };

    std::array<int, 3> indicesArray{ v0, v1, v2 };
    for (auto i = 0; i < 3; ++i)
    {
        auto j = indicesArray.at(i);
        if (!ratVertexEvaluated->at(j))
        {
            ratVertexEvaluated->at(j) = true;
            ratVertexPool->at(j).SetX(QRational{ vertexPool.at(j)[0] });
            ratVertexPool->at(j).SetY(QRational{ vertexPool.at(j)[1] });
        }
    }

    auto& ratV0 = ratVertexPool->at(v0);
    auto& ratV1 = ratVertexPool->at(v1);
    auto& ratV2 = ratVertexPool->at(v2);
    auto ratS0x = ratV0.GetX() + ratTest.GetX();
    auto ratD0x = ratV0.GetX() - ratTest.GetX();
    auto ratS0y = ratV0.GetY() + ratTest.GetY();
    auto ratD0y = ratV0.GetY() - ratTest.GetY();
    auto ratS1x = ratV1.GetX() + ratTest.GetX();
    auto ratD1x = ratV1.GetX() - ratTest.GetX();
    auto ratS1y = ratV1.GetY() + ratTest.GetY();
    auto ratD1y = ratV1.GetY() - ratTest.GetY();
    auto ratS2x = ratV2.GetX() + ratTest.GetX();
    auto ratD2x = ratV2.GetX() - ratTest.GetX();
    auto ratS2y = ratV2.GetY() + ratTest.GetY();
    auto ratD2y = ratV2.GetY() - ratTest.GetY();
    auto ratZ0 = ratS0x * ratD0x + ratS0y * ratD0y;
    auto ratZ1 = ratS1x * ratD1x + ratS1y * ratD1y;
    auto ratZ2 = ratS2x * ratD2x + ratS2y * ratD2y;
    auto ratC00 = ratD1y * ratZ2 - ratD2y * ratZ1;
    auto ratC01 = ratD2y * ratZ0 - ratD0y * ratZ2;
    auto ratC02 = ratD0y * ratZ1 - ratD1y * ratZ0;
    auto ratDet = ratD0x * ratC00 + ratD1x * ratC01 + ratD2x * ratC02;

    return (ratDet < QRational(0) ? +1 : (ratDet > QRational(0) ? -1 : 0));
}

template <typename Real>
typename Mathematics::IncrementalDelaunay2<Real>::TriangleSharedPtr Mathematics::IncrementalDelaunay2<Real>::GetContainingTriangleInternal(const Vector2& position) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    auto tri = *triangle.begin();
    auto numTriangle = boost::numeric_cast<int>(triangle.size());
    for (auto t = 0; t < numTriangle; ++t)
    {
        auto vertices = tri->v;

        if (ToLine(position, vertices.at(0), vertices.at(1)) > 0)
        {
            tri = tri->adjTriangle.at(0);
            if (!tri)
            {
                break;
            }
            continue;
        }

        if (ToLine(position, vertices.at(1), vertices.at(2)) > 0)
        {
            tri = tri->adjTriangle.at(1);
            if (!tri)
            {
                break;
            }
            continue;
        }

        if (ToLine(position, vertices.at(2), vertices.at(0)) > 0)
        {
            tri = tri->adjTriangle.at(2);
            if (!tri)
            {
                break;
            }
            continue;
        }

        return tri;
    }

    return 0;
}

template <typename Real>
bool Mathematics::IncrementalDelaunay2<Real>::ContainsSupervertex(const Triangle& tri) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    for (auto i = 0; i < 3; ++i)
    {
        if (0 <= tri.v.at(i) && tri.v.at(i) <= 2)
        {
            return true;
        }
    }
    return false;
}

template <typename Real>
void Mathematics::IncrementalDelaunay2<Real>::SwapEdge(const TriangleSharedPtr& tri0, const TriangleSharedPtr& tri1)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    auto i0 = 0;
    for (; i0 < 3; ++i0)
    {
        if (tri1 == tri0->adjTriangle.at(i0))
        {
            break;
        }
    }
    if (i0 == 3)
    {
        return;
    }

    const auto i0p1 = (i0 + 1) % 3;
    const auto i0p2 = (i0 + 2) % 3;

    auto i1 = 0;
    for (; i1 < 3; ++i1)
    {
        if (tri0 == tri1->adjTriangle.at(i1))
        {
            break;
        }
    }
    if (i1 == 3)
    {
        return;
    }

    const auto i1p1 = (i1 + 1) % 3;
    const auto i1p2 = (i1 + 2) % 3;

    tri0->v.at(i0p1) = tri1->v.at(i1p2);
    tri1->v.at(i1p1) = tri0->v.at(i0p2);

    auto adj = tri1->adjTriangle.at(i1p1);
    tri0->adjTriangle.at(i0) = adj;
    if (adj)
    {
        auto j = 0;
        for (; j < 3; ++j)
        {
            if (adj->adjTriangle.at(j) == tri1)
            {
                adj->adjTriangle.at(j) = tri0;
                break;
            }
        }
        if (j == 3)
        {
            return;
        }
    }

    adj = tri0->adjTriangle.at(i0p1);
    tri1->adjTriangle.at(i1) = adj;
    if (adj)
    {
        auto j = 0;
        for (; j < 3; ++j)
        {
            if (adj->adjTriangle.at(j) == tri0)
            {
                adj->adjTriangle.at(j) = tri1;
                break;
            }
        }
        if (j == 3)
        {
            MATHEMATICS_ASSERTION_0(false, "Unexpected condition.\n");
            return;
        }
    }

    tri0->adjTriangle.at(i0p1) = tri1;
    tri1->adjTriangle.at(i1p1) = tri0;
}

// IncrementalDelaunay2::Triangle

template <typename Real>
Mathematics::IncrementalDelaunay2<Real>::Triangle::Triangle(int v0, int v1, int v2) noexcept
    : v{ v0, v1, v2 }, adjTriangle{}, time{ -1 }, isComponent{ false }, onStack{ false }
{
}

template <typename Real>
bool Mathematics::IncrementalDelaunay2<Real>::Triangle::IsInsertionComponent(int posIndex, const Vector2& test, const TriangleSharedPtr& adj, const IncrementalDelaunay2& delaunay)
{
    if (posIndex != time)
    {
        time = posIndex;

        auto common = 0;
        auto svIndex = -1;
        for (auto j = 0; j < 3; ++j)
        {
            for (auto k = 0; k < 3; ++k)
            {
                if (v.at(j) == k)
                {
                    ++common;
                    svIndex = j;
                }
            }
        }

        auto relation = 0;
        if (common == 0)
        {
            relation = delaunay.ToCircumcircle(test, v.at(0), v.at(1), v.at(2));
        }
        else
        {
            auto v0 = 0;
            auto v1 = 0;
            if (common == 1)
            {
                v0 = v.at((svIndex + 1) % 3);
                v1 = v.at((svIndex + 2) % 3);
            }
            else
            {
                auto j = 0;
                for (; j < 3; ++j)
                {
                    if (adjTriangle.at(j) != 0 && adjTriangle.at(j) != adj)
                    {
                        break;
                    }
                }
                v0 = v.at(j);
                v1 = v.at((j + 1) % 3);
            }
            relation = delaunay.ToLine(test, v0, v1);
        }

        isComponent = (relation < 0);
    }

    return isComponent;
}

template <typename Real>
int Mathematics::IncrementalDelaunay2<Real>::Triangle::DetachFrom(int adjIndex, const TriangleSharedPtr& adj)
{
    MATHEMATICS_ASSERTION_0(0 <= adjIndex && adjIndex < 3 && adjTriangle.at(adjIndex) == adj, "无效输入。\n");

    adjTriangle.at(adjIndex) = nullptr;
    for (auto i = 0; i < 3; ++i)
    {
        if (adj->adjTriangle.at(i).get() == this)
        {
            adj->adjTriangle.at(i) = 0;
            return i;
        }
    }

    return -1;
}

// IncrementalDelaunay2::Edge

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26434)

template <typename Real>
Mathematics::IncrementalDelaunay2<Real>::Edge::Edge(int v0, int v1, int nullIndex, const TriangleSharedPtr& tri) noexcept
    : ParentType{ v0, v1 }, nullIndex{ nullIndex }, tri{ tri }
{
}

#include STSTEM_WARNING_POP

template <typename Real>
Mathematics::VEManifoldMesh::EdgeSharedPtr Mathematics::IncrementalDelaunay2<Real>::Edge::EdgeCreator(int v0, int v1)
{
    return std::make_shared<ClassType>(v0, v1, 0, nullptr);
}

// IncrementalDelaunay2::RPVertex

template <typename Real>
Mathematics::IncrementalDelaunay2<Real>::RPVertex::RPVertex(int index, const TriangleSharedPtr& tri, const TriangleSharedPtr& adj) noexcept
    : index{ index },
      tri{ tri },
      adj{ adj },
      isConvex{ false },
      isEarTip{ false },
      isSuperVertex{ false },
      weight{ Math<Real>::maxReal },
      vPrev{ -1 },
      vNext{ -1 },
      sPrev{ -1 },
      sNext{ -1 },
      earRecord{ 0 }
{
}

// IncrementalDelaunay2::Triangulate

template <typename Real>
Mathematics::IncrementalDelaunay2<Real>::Triangulate::Triangulate(std::vector<RPVertex>& polygon, int removal, IncrementalDelaunay2* delaunay)
    : polygon{ polygon },
      numVertices{ boost::numeric_cast<int>(polygon.size()) },
      delaunay{ delaunay },
      cFirst{ -1 },
      cLast{ -1 },
      rFirst{ -1 },
      rLast{ -1 },
      eHeap{ boost::numeric_cast<int>(polygon.size()), 1, Math<Real>::maxReal }
{
    const auto numVerticesM1 = numVertices - 1;

    for (auto i = 0; i <= numVerticesM1; ++i)
    {
        auto& vertex = Get(i);
        vertex.vPrev = (i > 0 ? i - 1 : numVerticesM1);
        vertex.vNext = (i < numVerticesM1 ? i + 1 : 0);
    }

    for (auto i = 0; i <= numVerticesM1; ++i)
    {
        if (IsConvex(i))
        {
            InsertAfterC(i);
        }
        else
        {
            InsertAfterR(i);
        }
    }

    for (auto i = cFirst; i != -1; i = Get(i).sNext)
    {
        if (IsEarTip(i))
        {
            auto weight = ComputeWeight(i, removal);
            Get(i).earRecord = eHeap.Insert(i, weight);
            Get(i).isEarTip = true;
        }
    }

    while (numVertices >= 3)
    {
        if (numVertices == 3)
        {
            MATHEMATICS_ASSERTION_0(eHeap.GetElementsNumber() == 3, "Unexpected condition\n");

            const auto record = eHeap.Remove();
            const auto uniqueIndex = record.GetUniqueIndex();

            const auto& vertex0 = Get(uniqueIndex);
            const auto vPrev = vertex0.vPrev;
            const auto vNext = vertex0.vNext;
            const auto& vertexP = Get(vPrev);
            const auto& vertexN = Get(vNext);
            auto tri0 = vertex0.tri;
            auto triP = vertexP.tri;
            auto triN = vertexN.tri;

            auto i0 = 0;
            for (i0 = 0; i0 < 3; ++i0)
            {
                if (tri0->v.at(i0) == removal)
                {
                    break;
                }
            }
            if (i0 == 3)
            {
                break;
            }

            tri0->v.at(i0) = vertexP.index;

            auto ip = 0;
            for (; ip < 3; ++ip)
            {
                if (triP->v.at(ip) == vertexP.index)
                {
                    break;
                }
            }

            if (ip == 3)
            {
                break;
            }

            auto adj = triP->adjTriangle.at(ip);
            tri0->adjTriangle.at(i0) = adj;
            if (adj)
            {
                auto i = 0;
                for (; i < 3; ++i)
                {
                    if (adj->v.at(i) == vertex0.index)
                    {
                        adj->adjTriangle.at(i) = tri0;
                        break;
                    }
                }
                if (i == 3)
                {
                    break;
                }
            }

            auto in = 0;
            for (; in < 3; ++in)
            {
                if (triN->v.at(in) == vertexN.index)
                {
                    break;
                }
            }

            if (in == 3)
            {
                break;
            }

            adj = triN->adjTriangle.at(in);
            tri0->adjTriangle.at((i0 + 2) % 3) = adj;
            if (adj)
            {
                auto j = 0;
                for (; j < 3; ++j)
                {
                    if (adj->v.at(j) == vertexP.index)
                    {
                        adj->adjTriangle.at(j) = tri0;
                        break;
                    }
                }

                if (j == 3)
                {
                    break;
                }
            }

            delaunay->triangle.erase(triP);
            delaunay->triangle.erase(triN);

            break;
        }

        const auto record = eHeap.Remove();
        auto index = record.GetUniqueIndex();
        auto weight = record.GetValue();
        const auto vPrev = Get(index).vPrev;
        const auto vNext = Get(index).vNext;
        delaunay->SwapEdge(Get(index).adj, Get(index).tri);
        Get(vPrev).tri = Get(index).tri;
        RemoveV(index);

        const auto& vertexP = Get(vPrev);
        if (vertexP.isEarTip)
        {
            if (!IsEarTip(vPrev))
            {
                eHeap.Update(Get(vPrev).earRecord, Math<Real>::GetValue(-1));
                const auto result = eHeap.Remove();
                index = result.GetUniqueIndex();
                weight = result.GetValue();

                MATHEMATICS_ASSERTION_0(index == vPrev && weight == Math<Real>::GetValue(-1), "意外情况。\n");
            }
        }
        else
        {
            const auto wasReflex = !vertexP.isConvex;
            if (IsConvex(vPrev))
            {
                if (wasReflex)
                {
                    RemoveR(vPrev);
                }

                if (IsEarTip(vPrev))
                {
                    weight = ComputeWeight(vPrev, removal);
                    Get(vPrev).earRecord = eHeap.Insert(vPrev, weight);
                    Get(vPrev).isEarTip = true;
                }
            }
        }

        const auto& vertexN = Get(vNext);
        if (vertexN.isEarTip)
        {
            if (!IsEarTip(vNext))
            {
                eHeap.Update(Get(vNext).earRecord, Math<Real>::GetValue(-1));
                const auto result = eHeap.Remove();
                index = result.GetUniqueIndex();
                weight = result.GetValue();
                MATHEMATICS_ASSERTION_0(index == vNext && weight == Math<Real>::GetValue(-1), "意外情况。\n");
            }
        }
        else
        {
            const auto wasReflex = !vertexN.isConvex;
            if (IsConvex(vNext))
            {
                if (wasReflex)
                {
                    RemoveR(vNext);
                }

                if (IsEarTip(vNext))
                {
                    weight = ComputeWeight(vNext, removal);
                    Get(vNext).earRecord = eHeap.Insert(vNext, weight);
                    Get(vNext).isEarTip = true;
                }
            }
        }
    }
}

template <typename Real>
typename Mathematics::IncrementalDelaunay2<Real>::RPVertex& Mathematics::IncrementalDelaunay2<Real>::Triangulate::Get(int i)
{
    return polygon.at(i);
}

template <typename Real>
bool Mathematics::IncrementalDelaunay2<Real>::Triangulate::IsConvex(int i)
{
    auto& vertex = Get(i);
    const auto curr = delaunay->GetVertices().at(vertex.index);
    const auto prev = Get(vertex.vPrev).index;
    const auto next = Get(vertex.vNext).index;
    vertex.isConvex = (delaunay->ToLine(curr, prev, next) > 0);

    return vertex.isConvex;
}

template <typename Real>
bool Mathematics::IncrementalDelaunay2<Real>::Triangulate::IsEarTip(int i)
{
    auto& vertex = Get(i);

    if (rFirst == -1)
    {
        vertex.isEarTip = true;
        return true;
    }

    const auto prev = Get(vertex.vPrev).index;
    const auto curr = vertex.index;
    const auto next = Get(vertex.vNext).index;
    vertex.isEarTip = true;
    for (auto j = rFirst; j != -1; j = Get(j).sNext)
    {
        if (j == vertex.vPrev || j == i || j == vertex.vNext)
        {
            continue;
        }

        auto test = delaunay->GetVertices().at(Get(j).index);
        if (delaunay->ToTriangle(test, prev, curr, next) <= 0)
        {
            vertex.isEarTip = false;
            break;
        }
    }

    return vertex.isEarTip;
}

template <typename Real>
void Mathematics::IncrementalDelaunay2<Real>::Triangulate::InsertAfterC(int i)
{
    if (cFirst == -1)
    {
        cFirst = i;
    }
    else
    {
        Get(cLast).sNext = i;
        Get(i).sPrev = cLast;
    }

    cLast = i;
}

template <typename Real>
void Mathematics::IncrementalDelaunay2<Real>::Triangulate::InsertAfterR(int i)
{
    if (rFirst == -1)
    {
        rFirst = i;
    }
    else
    {
        Get(rLast).sNext = i;
        Get(i).sPrev = rLast;
    }

    rLast = i;
}

template <typename Real>
void Mathematics::IncrementalDelaunay2<Real>::Triangulate::RemoveV(int i)
{
    const auto currVPrev = Get(i).vPrev;
    const auto currVNext = Get(i).vNext;
    Get(currVPrev).vNext = currVNext;
    Get(currVNext).vPrev = currVPrev;
    --numVertices;
}

template <typename Real>
void Mathematics::IncrementalDelaunay2<Real>::Triangulate::RemoveR(int i)
{
    MATHEMATICS_ASSERTION_0(rFirst != -1 && rLast != -1, "列表必须为非空。\n");

    if (i == rFirst)
    {
        rFirst = Get(i).sNext;
        if (rFirst != -1)
        {
            Get(rFirst).sPrev = -1;
        }
        Get(i).sNext = -1;
    }
    else if (i == rLast)
    {
        rLast = Get(i).sPrev;
        if (rLast != -1)
        {
            Get(rLast).sNext = -1;
        }
        Get(i).sPrev = -1;
    }
    else
    {
        const auto currSPrev = Get(i).sPrev;
        const auto currSNext = Get(i).sNext;
        Get(currSPrev).sNext = currSNext;
        Get(currSNext).sPrev = currSPrev;
        Get(i).sNext = -1;
        Get(i).sPrev = -1;
    }
}

template <typename Real>
Real Mathematics::IncrementalDelaunay2<Real>::Triangulate::ComputeWeight(int v0, int p)
{
    auto& vertex0 = Get(v0);

    MATHEMATICS_ASSERTION_0(vertex0.isEarTip, "顶点必须是ear tip\n");

    if (0 <= vertex0.index && vertex0.index <= 2)
    {
        vertex0.isSuperVertex = true;
        vertex0.weight = Math<Real>::maxReal;
        return vertex0.weight;
    }

    const auto prev = vertex0.vPrev;
    const auto next = vertex0.vNext;
    const auto& vertexP = Get(prev);
    const auto& vertexN = Get(next);

    const auto posP = delaunay->GetVertices().at(vertexP.index);
    const auto pos0 = delaunay->GetVertices().at(vertex0.index);
    const auto posN = delaunay->GetVertices().at(vertexN.index);
    const auto posR = delaunay->GetVertices().at(p);

    auto x0 = pos0[0] - posP[0];
    auto y0 = pos0[1] - posP[1];
    auto x1 = posN[0] - posP[0];
    auto y1 = posN[1] - posP[1];
    auto denom = x0 * y1 - x1 * y0;

    auto s0x = posP[0] + posR[0];
    auto d0x = posP[0] - posR[0];
    auto s0y = posP[1] + posR[1];
    auto d0y = posP[1] - posR[1];
    auto s1x = pos0[0] + posR[0];
    auto d1x = pos0[0] - posR[0];
    auto s1y = pos0[1] + posR[1];
    auto d1y = pos0[1] - posR[1];
    auto s2x = posN[0] + posR[0];
    auto d2x = posN[0] - posR[0];
    auto s2y = posN[1] + posR[1];
    auto d2y = posN[1] - posR[1];
    auto z0 = s0x * d0x + s0y * d0y;
    auto z1 = s1x * d1x + s1y * d1y;
    auto z2 = s2x * d2x + s2y * d2y;
    auto c00 = d1y * z2 - d2y * z1;
    auto c01 = d2y * z0 - d0y * z2;
    auto c02 = d0y * z1 - d1y * z0;
    auto numer = d0x * c00 + d1x * c01 + d2x * c02;

    vertex0.weight = numer / denom;

    return vertex0.weight;
}

#endif  // MATHEMATICS_COMPUTATIONAL_GEOMETRY_INCREMENTAL_DELAUNAY2_DETAIL_H