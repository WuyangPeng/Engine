///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:35)

#ifndef MATHEMATICS_COMPUTATIONAL_GEOMETRY_DELAUNAY1_DETAIL_H
#define MATHEMATICS_COMPUTATIONAL_GEOMETRY_DELAUNAY1_DETAIL_H

#include "Delaunay1.h"
#include "DelaunayDetail.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename Real>
Mathematics::Delaunay1<Real>::Delaunay1(const Vertices& vertices, Real epsilon, QueryType queryType)
    : ParentType{ boost::numeric_cast<int>(vertices.size()), epsilon, queryType }, vertices{ vertices }
{
    Init();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Delaunay1<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
void Mathematics::Delaunay1<Real>::Init()
{
    const auto numVertices = this->GetNumVertices();

    std::vector<SortedVertex> sorted(numVertices);

    for (auto i = 0; i < numVertices; ++i)
    {
        sorted.at(i).value = vertices.at(i);
        sorted.at(i).index = i;
    }
    std::sort(sorted.begin(), sorted.end());

    const auto endIndex = numVertices - 1;
    auto range = sorted.at(endIndex).value - sorted.at(0).value;
    if (this->GetEpsilon() <= range)
    {
        this->SetDimension(1);
        this->SetNumSimplices(numVertices - 1);

        const auto numSimplices = this->GetNumSimplices();
        const auto twoNumSimplices = 2 * numSimplices;
        IndicesType indices(twoNumSimplices);

        for (auto i = 0; i < numSimplices; ++i)
        {
            const auto twoI = 2 * i;
            const auto nextTwoI = twoI + 1;
            const auto nextI = i + 1;

            indices.at(twoI) = sorted.at(i).index;
            indices.at(nextTwoI) = sorted.at(nextI).index;
        }

        this->SetIndex(indices);

        IndicesType adjacencies(twoNumSimplices);
        for (auto i = 0; i < numSimplices; ++i)
        {
            const auto twoI = 2 * i;
            const auto nextTwoI = twoI + 1;

            adjacencies.at(twoI) = i - 1;
            adjacencies.at(nextTwoI) = i + 1;
        }

        const auto lastIndex = twoNumSimplices - 1;
        adjacencies.at(lastIndex) = -1;

        this->SetAdjacencies(adjacencies);
    }
}

template <typename Real>
typename Mathematics::Delaunay1<Real>::Vertices Mathematics::Delaunay1<Real>::GetVertices() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return vertices;
}

template <typename Real>
typename Mathematics::Delaunay1<Real>::HullType Mathematics::Delaunay1<Real>::GetHull() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto dimension = this->GetDimension();

    MATHEMATICS_ASSERTION_0(dimension == 1, "维度必须为 1。\n");
    if (dimension != 1)
    {
        return { -1, -1, false };
    }

    return { this->GetIndex(0), this->GetIndex(2 * this->GetNumSimplices() - 1), true };
}

template <typename Real>
int Mathematics::Delaunay1<Real>::GetContainingSegment(const Real p) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto dimension = this->GetDimension();
    MATHEMATICS_ASSERTION_0(dimension == 1, "维度必须为 1。\n");

    if (dimension != 1)
    {
        return -1;
    }

    if (p < vertices.at(this->GetIndex(0)))
    {
        return -1;
    }

    const auto numSimplices = this->GetNumSimplices();
    if (vertices.at(this->GetIndex(2 * numSimplices - 1)) < p)
    {
        return -1;
    }

    auto i = 0;
    for (; i < numSimplices; ++i)
    {
        if (p <= vertices.at(this->GetIndex(2 * i + 1)))
        {
            break;
        }
    }

    MATHEMATICS_ASSERTION_0(i < numSimplices, "输入错误。\n");

    return i;
}

template <typename Real>
typename Mathematics::Delaunay1<Real>::VertexType Mathematics::Delaunay1<Real>::GetVertexSet(int i) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto dimension = this->GetDimension();
    MATHEMATICS_ASSERTION_0(dimension == 1, "维度必须为 1。\n");

    if (dimension != 1)
    {
        return { Math<Real>::GetValue(0), Math<Real>::GetValue(0), false };
    }

    const auto numSimplices = this->GetNumSimplices();
    if (0 <= i && i < numSimplices)
    {
        return { vertices.at(this->GetIndex(2 * i)), vertices.at(this->GetIndex(2 * i + 1)), true };
    }

    return { Math<Real>::GetValue(0), Math<Real>::GetValue(0), false };
}

template <typename Real>
typename Mathematics::Delaunay1<Real>::HullType Mathematics::Delaunay1<Real>::GetIndexSet(int i) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto dimension = this->GetDimension();
    MATHEMATICS_ASSERTION_0(dimension == 1, "维度必须为 1。\n");

    if (dimension != 1)
    {
        return { -1, -1, false };
    }

    const auto numSimplices = this->GetNumSimplices();
    if (0 <= i && i < numSimplices)
    {
        return { this->GetIndex(2 * i), this->GetIndex(2 * i + 1), true };
    }

    return { -1, -1, false };
}

template <typename Real>
typename Mathematics::Delaunay1<Real>::HullType Mathematics::Delaunay1<Real>::GetAdjacentSet(int i) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto dimension = this->GetDimension();
    MATHEMATICS_ASSERTION_0(dimension == 1, "维度必须为 1。\n");

    if (dimension != 1)
    {
        return { -1, -1, false };
    }

    const auto numSimplices = this->GetNumSimplices();
    if (0 <= i && i < numSimplices)
    {
        return { this->GetAdjacency(2 * i), this->GetAdjacency(2 * i + 1), true };
    }

    return { -1, -1, false };
}

template <typename Real>
typename Mathematics::Delaunay1<Real>::VertexType Mathematics::Delaunay1<Real>::GetBarycentricSet(int i, const Real p) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto dimension = this->GetDimension();
    MATHEMATICS_ASSERTION_0(dimension == 1, "维度必须为 1。\n");

    if (dimension != 1)
    {
        return { Math<Real>::GetValue(0), Math<Real>::GetValue(0), false };
    }

    const auto numSimplices = this->GetNumSimplices();
    if (0 <= i && i < numSimplices)
    {
        auto v0 = vertices.at(this->GetIndex(2 * i));
        auto v1 = vertices.at(this->GetIndex(2 * i + 1));
        auto denom = v1 - v0;
        Real bary0{};
        if (this->GetEpsilon() < denom)
        {
            bary0 = (v1 - p) / denom;
        }
        else
        {
            bary0 = Math<Real>::GetValue(1);
        }

        return { bary0, Math<Real>::GetValue(1) - bary0, true };
    }

    return { Math<Real>::GetValue(0), Math<Real>::GetValue(0), false };
}

template <typename Real>
Mathematics::Delaunay1<Real>::Delaunay1(const String& filename)
    : ParentType{ 0, Math<Real>::GetValue(0), QueryType::Real }, vertices{}
{
    LoadFile(filename);

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
void Mathematics::Delaunay1<Real>::LoadFile(const String& filename)
{
    CoreTools::ReadFileManager inFile{ filename };

    if (!ParentType::Load(inFile))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("加载文件失败\n"));
    }

    vertices.resize(this->GetNumVertices());
    inFile.Read(sizeof(Real), this->GetNumVertices(), vertices.data());
}

template <typename Real>
void Mathematics::Delaunay1<Real>::SaveFile(const String& filename) const
{
    CoreTools::WriteFileManager outFile{ filename };

    if (!ParentType::Save(outFile))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("保存文件失败\n"));
    }

    outFile.Write(sizeof(Real), this->GetNumVertices(), vertices.data());
}

#endif  // MATHEMATICS_COMPUTATIONAL_GEOMETRY_DELAUNAY1_DETAIL_H