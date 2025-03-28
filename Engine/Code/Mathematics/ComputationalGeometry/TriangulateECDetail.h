///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:36)

#ifndef MATHEMATICS_COMPUTATIONAL_GEOMETRY_TRIANGULATE_EC_DETAIL_H
#define MATHEMATICS_COMPUTATIONAL_GEOMETRY_TRIANGULATE_EC_DETAIL_H

#include "TriangulateEC.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector2Detail.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Query/Query2Filtered.h"
#include "Mathematics/Query/Query2Int64.h"
#include "Mathematics/Query/Query2Integer.h"
#include "Mathematics/Query/Query2Rational.h"

#include <queue>

template <typename Real>
Mathematics::TriangulateEC<Real>::TriangulateEC(const Positions& positions, QueryType queryType, Real epsilon, Indices& triangles)
    : vertices{}, cFirst{}, cLast{}, rFirst{}, rLast{}, eFirst{}, eLast{}, query{}, sPositions{}
{
    InitializePositions(positions, queryType, epsilon, 0);

    const auto numVertices = boost::numeric_cast<int>(positions.size());

    InitializeVertices(numVertices, Indices{});
    DoEarClipping(numVertices, Indices{}, triangles);

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::TriangulateEC<Real>::TriangulateEC(const Positions& positions, QueryType queryType, Real epsilon, const Indices& polygon, Indices& triangles)
    : vertices{}, cFirst{}, cLast{}, rFirst{}, rLast{}, eFirst{}, eLast{}, query{}, sPositions{}
{
    InitializePositions(positions, queryType, epsilon, 0);

    const auto numVertices = boost::numeric_cast<int>(positions.size());

    InitializeVertices(numVertices, polygon);
    DoEarClipping(numVertices, polygon, triangles);

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::TriangulateEC<Real>::TriangulateEC(const Positions& positions, QueryType queryType, Real epsilon, const Indices& outer, const Indices& inner, Indices& triangles)
    : vertices{}, cFirst{}, cLast{}, rFirst{}, rLast{}, eFirst{}, eLast{}, query{}, sPositions{}
{
    InitializePositions(positions, queryType, epsilon, 2);

    const auto nextElement = boost::numeric_cast<int>(positions.size());
    IndexMap indexMap{};
    Indices combined{};
    CombinePolygons(queryType, epsilon, nextElement, outer, inner, indexMap, combined);

    auto numVertices = boost::numeric_cast<int>(positions.size());

    InitializeVertices(numVertices, combined);
    DoEarClipping(numVertices, combined, triangles);

    RemapIndices(indexMap, triangles);

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::TriangulateEC<Real>::TriangulateEC(const Positions& positions, QueryType queryType, Real epsilon, const Indices& outer, const IndicesArray& inners, Indices& triangles)
    : vertices{}, cFirst{}, cLast{}, rFirst{}, rLast{}, eFirst{}, eLast{}, query{}, sPositions{}
{
    const auto numInners = boost::numeric_cast<int>(inners.size());
    const auto extraElements = 2 * numInners;
    InitializePositions(positions, queryType, epsilon, extraElements);

    auto nextElement = boost::numeric_cast<int>(positions.size());
    IndexMap indexMap{};
    Indices combined{};
    ProcessOuterAndInners(queryType, epsilon, outer, inners, nextElement, indexMap, combined);

    const auto numVertices = boost::numeric_cast<int>(combined.size());

    InitializeVertices(numVertices, combined);
    DoEarClipping(numVertices, combined, triangles);

    RemapIndices(indexMap, triangles);

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::TriangulateEC<Real>::TriangulateEC(const Positions& positions, QueryType queryType, Real epsilon, const TreeSharedPtr& tree, Indices& triangles)
    : vertices{}, cFirst{}, cLast{}, rFirst{}, rLast{}, eFirst{}, eLast{}, query{}, sPositions{}
{
    const auto extraElements = GetExtraElements(tree);
    InitializePositions(positions, queryType, epsilon, extraElements);

    auto nextElement = boost::numeric_cast<int>(positions.size());
    IndexMap indexMap{};

    std::queue<ConstTreeSharedPtr> treeQueue{};
    treeQueue.emplace(tree);

    while (treeQueue.size() > 0)
    {
        const auto outerNode = treeQueue.front();
        treeQueue.pop();

        auto numChildren = boost::numeric_cast<int>(outerNode->child.size());

        if (numChildren == 0)
        {
            auto numVertices = boost::numeric_cast<int>(outerNode->polygon.size());

            InitializeVertices(numVertices, outerNode->polygon);
            DoEarClipping(numVertices, outerNode->polygon, triangles);
        }
        else
        {
            std::vector<std::vector<int>> inners(numChildren);
            for (auto i = 0; i < numChildren; ++i)
            {
                const auto innerNode = outerNode->child.at(i);
                inners.at(i) = innerNode->polygon;
                const auto numGrandChildren = boost::numeric_cast<int>(innerNode->child.size());
                for (auto j = 0; j < numGrandChildren; ++j)
                {
                    treeQueue.push(innerNode->child.at(j));
                }
            }

            Indices combined{};
            ProcessOuterAndInners(queryType, epsilon, outerNode->polygon, inners, nextElement, indexMap, combined);

            auto numVertices = boost::numeric_cast<int>(combined.size());

            InitializeVertices(numVertices, combined);
            DoEarClipping(numVertices, combined, triangles);
        }
    }

    RemapIndices(indexMap, triangles);
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::TriangulateEC<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
void Mathematics::TriangulateEC<Real>::InitializePositions(const Positions& positions, QueryType queryType, Real epsilon, int extraElements)
{
    auto numPositions = boost::numeric_cast<int>(positions.size());
    MATHEMATICS_ASSERTION_0(numPositions >= 3, "必须至少是个三角形。\n");
    const auto numPosExtras = numPositions + extraElements;
    sPositions.resize(numPosExtras);

    if (queryType == QueryType::Filtered)
    {
        MATHEMATICS_ASSERTION_0(Math<Real>::GetValue(0) <= epsilon && epsilon <= Math<Real>::GetValue(1), "Epsilon 必须在0和1之间。\n");
    }

    switch (queryType)
    {
        case QueryType::Int64:
        {
            const auto aabb = Vector2Tools<Real>::ComputeExtremes(positions);
            const auto minValue = aabb.GetMinPoint();
            const auto maxValue = aabb.GetMaxPoint();

            auto range = maxValue - minValue;
            auto rmax = (range[0] >= range[1] ? range[0] : range[1]);
            auto scale = Math<Real>::GetValue(1 << 20) / rmax;
            for (auto i = 0; i < numPositions; ++i)
            {
                sPositions.at(i) = (positions.at(i) - minValue) * scale;
            }

            query = std::make_shared<Query2Int64<Real>>(sPositions);
            return;
        }

        case QueryType::Integer:
        {
            const auto aabb = Vector2Tools<Real>::ComputeExtremes(positions);
            const auto minValue = aabb.GetMinPoint();
            const auto maxValue = aabb.GetMaxPoint();
            auto range = maxValue - minValue;
            auto rmax = (range[0] >= range[1] ? range[0] : range[1]);
            auto scale = (Math<Real>::GetValue(1 << 24)) / rmax;
            for (auto i = 0; i < numPositions; ++i)
            {
                sPositions.at(i) = (positions.at(i) - minValue) * scale;
            }

            query = std::make_shared<Query2Integer<Real>>(sPositions);
            return;
        }

        case QueryType::Real:
        {
            for (auto i = 0; i < numPositions; ++i)
            {
                sPositions.at(i) = positions.at(i);
            }

            query = std::make_shared<Query2Type>(sPositions);
            return;
        }

        case QueryType::Rational:
        {
            for (auto i = 0; i < numPositions; ++i)
            {
                sPositions.at(i) = positions.at(i);
            }

            query = std::make_shared<Query2Rational<Real>>(sPositions);
            return;
        }

        case QueryType::Filtered:
        {
            for (auto i = 0; i < numPositions; ++i)
            {
                sPositions.at(i) = positions.at(i);
            }

            query = std::make_shared<Query2Filtered<Real>>(sPositions, epsilon);
            return;
        }
    }
}

template <typename Real>
void Mathematics::TriangulateEC<Real>::InitializeVertices(int numVertices, const Indices& indices)
{
    vertices.clear();
    vertices.resize(numVertices);
    cFirst = -1;
    cLast = -1;
    rFirst = -1;
    rLast = -1;
    eFirst = -1;
    eLast = -1;

    const auto numVerticesM1 = numVertices - 1;

    for (auto i = 0; i <= numVerticesM1; ++i)
    {
        Vertex& vertex = Get(i);
        vertex.index = (!indices.empty() ? indices.at(i) : i);
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
}

template <typename Real>
void Mathematics::TriangulateEC<Real>::DoEarClipping(int numVertices, const Indices& indices, Indices& triangles)
{
    if (rFirst == -1)
    {
        const auto numVerticesM1 = numVertices - 1;
        if (!indices.empty())
        {
            for (auto i = 1; i < numVerticesM1; ++i)
            {
                triangles.emplace_back(indices.at(0));
                triangles.emplace_back(indices.at(i));

                const auto next = i + 1;
                triangles.emplace_back(indices.at(next));
            }
        }
        else
        {
            for (auto i = 1; i < numVerticesM1; ++i)
            {
                triangles.emplace_back(0);
                triangles.emplace_back(i);
                triangles.emplace_back(i + 1);
            }
        }
        return;
    }

    for (auto i = cFirst; i != -1; i = Get(i).sNext)
    {
        if (IsEar(i))
        {
            InsertEndE(i);
        }
    }
    Get(eFirst).ePrev = eLast;
    Get(eLast).eNext = eFirst;

    auto bRemoveAnEar = true;
    while (bRemoveAnEar)
    {
        auto iVPrev = Get(eFirst).vPrev;
        auto iVNext = Get(eFirst).vNext;
        triangles.emplace_back(Get(iVPrev).index);
        triangles.emplace_back(Get(eFirst).index);
        triangles.emplace_back(Get(iVNext).index);

        RemoveV(eFirst);
        if (--numVertices == 3)
        {
            eFirst = RemoveE(eFirst);
            iVPrev = Get(eFirst).vPrev;
            iVNext = Get(eFirst).vNext;
            triangles.emplace_back(Get(iVPrev).index);
            triangles.emplace_back(Get(eFirst).index);
            triangles.emplace_back(Get(iVNext).index);
            bRemoveAnEar = false;
            continue;
        }

        const auto& VPrev = Get(iVPrev);
        if (VPrev.isEar)
        {
            if (!IsEar(iVPrev))
            {
                RemoveE(iVPrev);
            }
        }
        else
        {
            const auto wasReflex = !VPrev.isConvex;
            if (IsConvex(iVPrev))
            {
                if (wasReflex)
                {
                    RemoveR(iVPrev);
                }

                if (IsEar(iVPrev))
                {
                    InsertBeforeE(iVPrev);
                }
            }
        }

        const auto& VNext = Get(iVNext);
        if (VNext.isEar)
        {
            if (!IsEar(iVNext))
            {
                RemoveE(iVNext);
            }
        }
        else
        {
            const auto wasReflex = !VNext.isConvex;
            if (IsConvex(iVNext))
            {
                if (wasReflex)
                {
                    RemoveR(iVNext);
                }

                if (IsEar(iVNext))
                {
                    InsertAfterE(iVNext);
                }
            }
        }

        eFirst = RemoveE(eFirst);
    }
}

template <typename Real>
int Mathematics::TriangulateEC<Real>::TriangleQuery(const Vector2Type& position, QueryType queryType, Real epsilon, const std::array<Vector2Type, 3>& triangle) const
{
    std::vector<Vector2Type> triangleVec{ triangle.begin(), triangle.end() };

    switch (queryType)
    {
        case QueryType::Int64:
            return System::EnumCastUnderlying(Query2Int64<Real>(triangleVec).ToTriangle(position, 0, 1, 2));

        case QueryType::Integer:
            return System::EnumCastUnderlying(Query2Integer<Real>(triangleVec).ToTriangle(position, 0, 1, 2));

        case QueryType::Real:
            return System::EnumCastUnderlying(Query2Type(triangleVec).ToTriangle(position, 0, 1, 2));

        case QueryType::Rational:
            return System::EnumCastUnderlying(Query2Rational<Real>(triangleVec).ToTriangle(position, 0, 1, 2));

        case QueryType::Filtered:
            return System::EnumCastUnderlying(Query2Filtered<Real>(triangleVec, epsilon).ToTriangle(position, 0, 1, 2));
    }

    return 1;
}

template <typename Real>
void Mathematics::TriangulateEC<Real>::CombinePolygons(QueryType queryType,
                                                       Real epsilon,
                                                       int nextElement,
                                                       const Indices& outer,
                                                       const Indices& inner,
                                                       IndexMap& indexMap,
                                                       Indices& combined)
{
    auto numOuterVertices = boost::numeric_cast<int>(outer.size());
    auto numInnerVertices = boost::numeric_cast<int>(inner.size());

    auto xmax = sPositions.at(inner.at(0))[0];
    auto xmaxIndex = 0;

    for (auto i = 1; i < numInnerVertices; ++i)
    {
        Real x = sPositions.at(inner.at(i))[0];
        if (x > xmax)
        {
            xmax = x;
            xmaxIndex = i;
        }
    }
    auto m = sPositions.at(inner.at(xmaxIndex));

    Vector2Type intr{ Math<Real>::maxReal, m[1] };
    auto v0min = -1;
    auto v1min = -1;
    auto endMin = -1;

    auto s = Math<Real>::maxReal;
    auto t = Math<Real>::maxReal;
    for (auto i0 = numOuterVertices - 1, i1 = 0; i1 < numOuterVertices; i0 = i1++)
    {
        auto diff0 = sPositions.at(outer.at(i0)) - m;
        if (diff0[1] > Math<Real>::GetValue(0))
        {
            continue;
        }
        auto diff1 = sPositions.at(outer.at(i1)) - m;
        if (diff1[1] < Math<Real>::GetValue(0))
        {
            continue;
        }

        auto currentEndMin = -1;
        if (diff0[1] < Math<Real>::GetValue(0))
        {
            if (diff1[1] > Math<Real>::GetValue(0))
            {
                s = diff0[1] / (diff0[1] - diff1[1]);
                t = diff0[0] + s * (diff1[0] - diff0[0]);
            }
            else
            {
                t = diff1[0];
                currentEndMin = i1;
            }
        }
        else
        {
            if (diff1[1] > Math<Real>::GetValue(0))
            {
                t = diff0[0];
                currentEndMin = i0;
            }
            else
            {
                if (diff0[0] < diff1[0])
                {
                    t = diff0[0];
                    currentEndMin = i0;
                }
                else
                {
                    t = diff1[0];
                    currentEndMin = i1;
                }
            }
        }

        if (Math<Real>::GetValue(0) <= t && t < intr[0])
        {
            intr[0] = t;
            v0min = i0;
            v1min = i1;
            if (currentEndMin == -1)
            {
                endMin = -1;
            }
            else
            {
                endMin = currentEndMin;
            }
        }
        else if (t == intr[0])
        {
            MATHEMATICS_ASSERTION_0(endMin != -1 && currentEndMin != -1, "意外情况\n");

            const auto& shared = sPositions.at(outer.at(i1));

            const auto other = (endMin == v0min ? v1min : v0min);

            diff0 = sPositions.at(outer.at(i0)) - shared;
            diff1 = sPositions.at(outer.at(other)) - shared;
            auto dotperp = Vector2Tools<Real>::DotPerp(diff0, diff1);
            if (dotperp > Math<Real>::GetValue(0))
            {
                v0min = i0;
                v1min = i1;
                endMin = currentEndMin;
            }
        }
    }

    intr[0] += m[0];

    auto maxCosIndex = 0;
    if (endMin == -1)
    {
        MATHEMATICS_ASSERTION_0(v0min >= 0 && v1min >= 0, "意外情况\n");

        std::array<Vector2Type, 3> sTriangle{};
        auto pIndex = 0;
        if (sPositions.at(outer.at(v0min))[0] > sPositions.at(outer.at(v1min))[0])
        {
            sTriangle.at(0) = sPositions.at(outer.at(v0min));
            sTriangle.at(1) = intr;
            sTriangle.at(2) = m;
            pIndex = v0min;
        }
        else
        {
            sTriangle.at(0) = sPositions.at(outer.at(v1min));
            sTriangle.at(1) = m;
            sTriangle.at(2) = intr;
            pIndex = v1min;
        }

        auto diff = sTriangle.at(0) - m;
        auto maxSqrLen = Vector2Tools<Real>::GetLengthSquared(diff);
        auto maxCos = diff[0] * diff[0] / maxSqrLen;
        maxCosIndex = pIndex;
        for (auto i = 0; i < numOuterVertices; ++i)
        {
            if (i == pIndex)
            {
                continue;
            }

            auto curr = outer.at(i);
            auto prev = outer.at((i + numOuterVertices - 1) % numOuterVertices);
            auto next = outer.at((i + 1) % numOuterVertices);
            if (System::EnumCastUnderlying(query->ToLine(curr, prev, next)) <= 0 && TriangleQuery(sPositions.at(curr), queryType, epsilon, sTriangle) <= 0)
            {
                diff = sPositions.at(curr) - m;
                auto sqrLen = Vector2Tools<Real>::GetLengthSquared(diff);
                auto cs = diff[0] * diff[0] / sqrLen;
                if (cs > maxCos)
                {
                    maxSqrLen = sqrLen;
                    maxCos = cs;
                    maxCosIndex = i;
                }
                else if (cs == maxCos && sqrLen < maxSqrLen)
                {
                    maxSqrLen = sqrLen;
                    maxCosIndex = i;
                }
            }
        }
    }
    else
    {
        maxCosIndex = endMin;
    }

    const auto combineSize = numOuterVertices + numInnerVertices + 2;
    combined.resize(combineSize);
    auto cIndex = 0;
    for (auto i = 0; i <= maxCosIndex; ++i, ++cIndex)
    {
        combined.at(cIndex) = outer.at(i);
    }

    for (auto i = 0; i < numInnerVertices; ++i, ++cIndex)
    {
        auto j = (xmaxIndex + i) % numInnerVertices;
        combined.at(cIndex) = inner.at(j);
    }

    auto innerIndex = inner.at(xmaxIndex);
    sPositions.at(nextElement) = sPositions.at(innerIndex);
    combined.at(cIndex) = nextElement;
    auto iter = indexMap.find(innerIndex);
    if (iter != indexMap.end())
    {
        innerIndex = iter->second;
    }
    indexMap[nextElement] = innerIndex;
    ++cIndex;
    ++nextElement;

    auto outerIndex = outer.at(maxCosIndex);
    sPositions.at(nextElement) = sPositions.at(outerIndex);
    combined.at(cIndex) = nextElement;
    iter = indexMap.find(outerIndex);
    if (iter != indexMap.end())
    {
        outerIndex = iter->second;
    }
    indexMap[nextElement] = outerIndex;
    ++cIndex;
    ++nextElement;

    for (auto i = maxCosIndex + 1; i < numOuterVertices; ++i, ++cIndex)
    {
        combined.at(cIndex) = outer.at(i);
    }
}

template <typename Real>
void Mathematics::TriangulateEC<Real>::ProcessOuterAndInners(QueryType queryType, Real epsilon, const Indices& outer, const IndicesArray& inners, int& nextElement, IndexMap& indexMap, Indices& combined)
{
    auto numInners = boost::numeric_cast<int>(inners.size());
    std::vector<std::pair<Real, int>> pairs(numInners);

    for (auto i = 0; i < numInners; ++i)
    {
        const auto& inner = inners.at(i);
        auto numVertices = boost::numeric_cast<int>(inner.size());
        auto xmax = sPositions.at(inner.at(0))[0];
        for (auto j = 1; j < numVertices; ++j)
        {
            auto x = sPositions.at(inner.at(j))[0];
            if (x > xmax)
            {
                xmax = x;
            }
        }
        pairs.at(i).first = xmax;
        pairs.at(i).second = i;
    }
    std::sort(pairs.begin(), pairs.end());

    auto currentOuter = outer;
    for (auto i = numInners - 1; i >= 0; --i)
    {
        const auto& inner = inners.at(pairs.at(i).second);
        Indices currentCombined{};
        CombinePolygons(queryType, epsilon, nextElement, currentOuter, inner, indexMap, currentCombined);
        currentOuter = currentCombined;
        nextElement += 2;
    }

    for (auto i = 0u; i < currentOuter.size(); ++i)
    {
        combined.push_back(currentOuter.at(i));
    }
}

template <typename Real>
void Mathematics::TriangulateEC<Real>::RemapIndices(const IndexMap& indexMap, Indices& triangles) const
{
    const auto numTriangles = boost::numeric_cast<int>(triangles.size());
    for (auto i = 0; i < numTriangles; ++i)
    {
        const auto iter = indexMap.find(triangles.at(i));
        if (iter != indexMap.end())
        {
            triangles.at(i) = iter->second;
        }
    }
}

template <typename Real>
typename Mathematics::TriangulateEC<Real>::Vertex& Mathematics::TriangulateEC<Real>::Get(int i)
{
    return vertices.at(i);
}

template <typename Real>
bool Mathematics::TriangulateEC<Real>::IsConvex(int i)
{
    auto& vertex = Get(i);
    const auto curr = vertex.index;
    const auto prev = Get(vertex.vPrev).index;
    const auto next = Get(vertex.vNext).index;
    vertex.isConvex = (System::EnumCastUnderlying(query->ToLine(curr, prev, next)) > 0);

    return vertex.isConvex;
}

template <typename Real>
bool Mathematics::TriangulateEC<Real>::IsEar(int i)
{
    auto& vertex = Get(i);

    if (rFirst == -1)
    {
        vertex.isEar = true;
        return true;
    }

    const auto prev = Get(vertex.vPrev).index;
    const auto curr = vertex.index;
    const auto next = Get(vertex.vNext).index;
    vertex.isEar = true;
    for (auto j = rFirst; j != -1; j = Get(j).sNext)
    {
        if (j == vertex.vPrev || j == i || j == vertex.vNext)
        {
            continue;
        }

        const auto test = Get(j).index;
        if (sPositions.at(test) == sPositions.at(prev) || sPositions.at(test) == sPositions.at(curr) || sPositions.at(test) == sPositions.at(next))
        {
            continue;
        }

        if (System::EnumCastUnderlying(query->ToTriangle(test, prev, curr, next)) <= 0)
        {
            vertex.isEar = false;
            break;
        }
    }

    return vertex.isEar;
}

template <typename Real>
void Mathematics::TriangulateEC<Real>::InsertAfterC(int i)
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
void Mathematics::TriangulateEC<Real>::InsertAfterR(int i)
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
void Mathematics::TriangulateEC<Real>::InsertEndE(int i)
{
    if (eFirst == -1)
    {
        eFirst = i;
        eLast = i;
    }
    Get(eLast).eNext = i;
    Get(i).ePrev = eLast;
    eLast = i;
}

template <typename Real>
void Mathematics::TriangulateEC<Real>::InsertAfterE(int i)
{
    auto& first = Get(eFirst);
    const auto currENext = first.eNext;
    auto& vertex = Get(i);
    vertex.ePrev = eFirst;
    vertex.eNext = currENext;
    first.eNext = i;
    Get(currENext).ePrev = i;
}

template <typename Real>
void Mathematics::TriangulateEC<Real>::InsertBeforeE(int i)
{
    auto& first = Get(eFirst);
    const auto currEPrev = first.ePrev;
    auto& vertex = Get(i);
    vertex.ePrev = currEPrev;
    vertex.eNext = eFirst;
    first.ePrev = i;
    Get(currEPrev).eNext = i;
}

template <typename Real>
void Mathematics::TriangulateEC<Real>::RemoveV(int i)
{
    const auto currVPrev = Get(i).vPrev;
    const auto currVNext = Get(i).vNext;
    Get(currVPrev).vNext = currVNext;
    Get(currVNext).vPrev = currVPrev;
}

template <typename Real>
int Mathematics::TriangulateEC<Real>::RemoveE(int i)
{
    const auto currEPrev = Get(i).ePrev;
    const auto currENext = Get(i).eNext;
    Get(currEPrev).eNext = currENext;
    Get(currENext).ePrev = currEPrev;
    return currENext;
}

template <typename Real>
void Mathematics::TriangulateEC<Real>::RemoveR(int i)
{
    MATHEMATICS_ASSERTION_0(rFirst != -1 && rLast != -1, "反射顶点必须存在。\n");

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
void Mathematics::TriangulateEC<Real>::Delete(TreeSharedPtr& root)
{
    if (root)
    {
        std::queue<TreeSharedPtr> treeQueue{};
        treeQueue.emplace(root);

        while (treeQueue.size() > 0)
        {
            auto tree = treeQueue.front();
            treeQueue.pop();
            const auto numChildren = boost::numeric_cast<int>(tree->child.size());
            for (int i = 0; i < numChildren; ++i)
            {
                treeQueue.push(tree->child.at(i));
            }
        }

        root = 0;
    }
}

template <typename Real>
int Mathematics::TriangulateEC<Real>::GetExtraElements(const TreeSharedPtr& tree)
{
    auto extraElements = 0;

    std::queue<ConstTreeSharedPtr> treeQueue;
    treeQueue.emplace(tree);
    while (treeQueue.size() > 0)
    {
        const auto root = treeQueue.front();
        treeQueue.pop();
        const auto numChildren = boost::numeric_cast<int>(root->child.size());
        extraElements += 2 * numChildren;

        for (auto i = 0; i < numChildren; ++i)
        {
            const auto child = root->child.at(i);
            const auto numGrandChildren = boost::numeric_cast<int>(child->child.size());
            for (int j = 0; j < numGrandChildren; ++j)
            {
                treeQueue.push(child->child.at(j));
            }
        }
    }

    return extraElements;
}

template <typename Real>
Mathematics::TriangulateEC<Real>::Vertex::Vertex() noexcept
    : index{ -1 }, isConvex{ false }, isEar{ false }, vPrev{ -1 }, vNext{ -1 }, sPrev{ -1 }, sNext{ -1 }, ePrev{ -1 }, eNext{ -1 }
{
}

#endif  // MATHEMATICS_COMPUTATIONAL_GEOMETRY_TRIANGULATE_EC_DETAIL_H