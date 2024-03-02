///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.6 (2024/02/28 14:42)

#ifndef MATHEMATICS_MESHES_UNIQUE_VERTICES_SIMPLICES_DETAIL_H
#define MATHEMATICS_MESHES_UNIQUE_VERTICES_SIMPLICES_DETAIL_H

#include "UniqueVerticesSimplices.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename VertexType, typename IndexType, int Dimension>
requires(std::is_integral_v<IndexType> && !std::is_same_v<IndexType, bool>)
Mathematics::UniqueVerticesSimplices<VertexType, IndexType, Dimension>::UniqueVerticesSimplices() noexcept
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename VertexType, typename IndexType, int Dimension>
requires(std::is_integral_v<IndexType> && !std::is_same_v<IndexType, bool>)
bool Mathematics::UniqueVerticesSimplices<VertexType, IndexType, Dimension>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename VertexType, typename IndexType, int Dimension>
requires(std::is_integral_v<IndexType> && !std::is_same_v<IndexType, bool>)
void Mathematics::UniqueVerticesSimplices<VertexType, IndexType, Dimension>::GenerateIndexedSimplices(const VertexContainer& inVertices,
                                                                                                      VertexContainer& outVertices,
                                                                                                      IndexContainer& outIndices)
{
    if (inVertices.empty() || inVertices.size() % Dimension != 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("顶点数无效"))
    }

    outIndices.resize(inVertices.size());
    RemoveDuplicates(inVertices, outVertices, outIndices);
}

template <typename VertexType, typename IndexType, int Dimension>
requires(std::is_integral_v<IndexType> && !std::is_same_v<IndexType, bool>)
void Mathematics::UniqueVerticesSimplices<VertexType, IndexType, Dimension>::GenerateIndexedSimplices(const VertexContainer& inVertices,
                                                                                                      VertexContainer& outVertices,
                                                                                                      IndexDimensionContainer& outSimplices)
{
    if (inVertices.empty() || inVertices.size() % Dimension != 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("顶点数无效"))
    }

    outSimplices.resize(inVertices.size() / Dimension);
    IndexContainer outIndices(outSimplices.size() * Dimension);

    RemoveDuplicates(inVertices, outVertices, outIndices);

    auto i0 = 0;
    auto i1 = 0;
    for (const auto& element : outIndices)
    {
        outSimplices.at(i0).at(i1) = element;

        ++i1;
        if (i1 == Dimension)
        {
            ++i0;
            i1 = 0;
        }
    }
}

template <typename VertexType, typename IndexType, int Dimension>
requires(std::is_integral_v<IndexType> && !std::is_same_v<IndexType, bool>)
void Mathematics::UniqueVerticesSimplices<VertexType, IndexType, Dimension>::RemoveDuplicateVertices(const VertexContainer& inVertices,
                                                                                                     const IndexContainer& inIndices,
                                                                                                     VertexContainer& outVertices,
                                                                                                     IndexContainer& outIndices)
{
    if (inVertices.empty())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("顶点数无效"))
    }

    if (inIndices.empty() || inIndices.size() % Dimension != 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("索引数无效"))
    }

    const auto numVertices = boost::numeric_cast<IndexType>(inVertices.size());
    for (auto index : inIndices)
    {
        if (index < 0 || numVertices <= index)
        {
            THROW_EXCEPTION(SYSTEM_TEXT("无效索引"))
        }
    }

    IndexContainer inToOutMapping(inVertices.size());
    RemoveDuplicates(inVertices, outVertices, inToOutMapping);

    for (auto index : inIndices)
    {
        outIndices.emplace_back(inToOutMapping.at(index));
    }
}

template <typename VertexType, typename IndexType, int Dimension>
requires(std::is_integral_v<IndexType> && !std::is_same_v<IndexType, bool>)
void Mathematics::UniqueVerticesSimplices<VertexType, IndexType, Dimension>::RemoveDuplicateVertices(const VertexContainer& inVertices,
                                                                                                     const IndexDimensionContainer& inSimplices,
                                                                                                     VertexContainer& outVertices,
                                                                                                     IndexDimensionContainer& outSimplices)
{
    if (inVertices.empty())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("顶点数无效"))
    }

    if (inSimplices.empty())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("简单数无效"))
    }

    const auto numVertices = boost::numeric_cast<IndexType>(inVertices.size());
    for (const auto& simplex : inSimplices)
    {
        for (auto d = 0; d < Dimension; ++d)
        {
            if (simplex.at(d) < 0 || numVertices <= simplex.at(d))
            {
                THROW_EXCEPTION(SYSTEM_TEXT("无效索引"))
            }
        }
    }

    IndexContainer inToOutMapping(inVertices.size());
    RemoveDuplicates(inVertices, outVertices, inToOutMapping);

    const auto numSimplices = boost::numeric_cast<int>(inSimplices.size());
    outSimplices.resize(numSimplices);
    for (auto s = 0; s < numSimplices; ++s)
    {
        for (auto d = 0; d < Dimension; ++d)
        {
            outSimplices.at(s).at(d) = inToOutMapping.at(inSimplices.at(s).at(d));
        }
    }
}

template <typename VertexType, typename IndexType, int Dimension>
requires(std::is_integral_v<IndexType> && !std::is_same_v<IndexType, bool>)
void Mathematics::UniqueVerticesSimplices<VertexType, IndexType, Dimension>::RemoveUnusedVertices(const VertexContainer& inVertices,
                                                                                                  const IndexContainer& inIndices,
                                                                                                  VertexContainer& outVertices,
                                                                                                  IndexContainer& outIndices)
{
    if (inVertices.empty())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("顶点数无效"))
    }

    if (inIndices.empty() || inIndices.size() % Dimension != 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("索引数无效"))
    }

    const auto numVertices = boost::numeric_cast<IndexType>(inVertices.size());
    for (auto index : inIndices)
    {
        if (index < 0 || numVertices <= index)
        {
            THROW_EXCEPTION(SYSTEM_TEXT("无效索引"))
        }
    }

    outIndices.resize(inIndices.size());
    RemoveUnused(inVertices, boost::numeric_cast<int>(inIndices.size()), inIndices, outVertices, outIndices);
}

template <typename VertexType, typename IndexType, int Dimension>
requires(std::is_integral_v<IndexType> && !std::is_same_v<IndexType, bool>)
void Mathematics::UniqueVerticesSimplices<VertexType, IndexType, Dimension>::RemoveUnusedVertices(const VertexContainer& inVertices,
                                                                                                  const IndexDimensionContainer& inSimplices,
                                                                                                  VertexContainer& outVertices,
                                                                                                  IndexDimensionContainer& outSimplices)
{
    if (inVertices.empty())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("顶点数无效"))
    }

    if (inSimplices.empty())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("简单数无效"))
    }

    const IndexType numVertices = boost::numeric_cast<IndexType>(inVertices.size());
    for (const auto& simplex : inSimplices)
    {
        for (auto d = 0; d < Dimension; ++d)
        {
            if (simplex.at(d) < 0 || numVertices <= simplex.at(d))
            {
                THROW_EXCEPTION(SYSTEM_TEXT("无效索引"))
            }
        }
    }

    outSimplices.resize(inSimplices.size());
    const auto numInIndices = boost::numeric_cast<int>(Dimension * inSimplices.size());

    IndexContainer inIndices{};

    for (const auto& element : inSimplices)
    {
        for (const auto& index : element)
        {
            inIndices.emplace_back(index);
        }
    }

    IndexContainer outIndices(outSimplices.size() * Dimension);

    RemoveUnused(inVertices, numInIndices, inIndices, outVertices, outIndices);

    auto i0 = 0;
    auto i1 = 0;
    for (const auto& element : outIndices)
    {
        outSimplices.at(i0).at(i1) = element;

        ++i1;
        if (i1 == Dimension)
        {
            ++i0;
            i1 = 0;
        }
    }
}

template <typename VertexType, typename IndexType, int Dimension>
requires(std::is_integral_v<IndexType> && !std::is_same_v<IndexType, bool>)
void Mathematics::UniqueVerticesSimplices<VertexType, IndexType, Dimension>::RemoveDuplicateAndUnusedVertices(const VertexContainer& inVertices,
                                                                                                              const IndexContainer& inIndices,
                                                                                                              VertexContainer& outVertices,
                                                                                                              IndexContainer& outIndices)
{
    VertexContainer vertices{};
    IndexContainer indices{};
    RemoveDuplicateVertices(inVertices, inIndices, vertices, indices);
    RemoveUnusedVertices(vertices, indices, outVertices, outIndices);
}

template <typename VertexType, typename IndexType, int Dimension>
requires(std::is_integral_v<IndexType> && !std::is_same_v<IndexType, bool>)
void Mathematics::UniqueVerticesSimplices<VertexType, IndexType, Dimension>::RemoveDuplicateAndUnusedVertices(const VertexContainer& inVertices,
                                                                                                              const IndexDimensionContainer& inSimplices,
                                                                                                              VertexContainer& outVertices,
                                                                                                              IndexDimensionContainer& outSimplices)
{
    VertexContainer vertices{};
    IndexDimensionContainer simplices{};
    RemoveDuplicateVertices(inVertices, inSimplices, vertices, simplices);
    RemoveUnusedVertices(vertices, simplices, outVertices, outSimplices);
}

template <typename VertexType, typename IndexType, int Dimension>
requires(std::is_integral_v<IndexType> && !std::is_same_v<IndexType, bool>)
void Mathematics::UniqueVerticesSimplices<VertexType, IndexType, Dimension>::RemoveDuplicates(const VertexContainer& inVertices,
                                                                                              VertexContainer& outVertices,
                                                                                              IndexContainer& inToOutMapping)
{
    /// 构造唯一的顶点。
    const auto numInVertices = boost::numeric_cast<int>(inVertices.size());
    auto numOutVertices = 0;
    std::map<VertexType, IndexType> result{};
    for (auto i = 0; i < numInVertices; ++i)
    {
        const auto iter = result.find(inVertices.at(i));
        if (iter != result.cend())
        {
            /// 该顶点是先前插入到贴图中的顶点的副本。
            /// 它的索引i将被修改为第一个找到的顶点的索引
            inToOutMapping.at(i) = iter->second;
        }
        else
        {
            /// 顶点是第一次出现。
            result.emplace(inVertices.at(i), boost::numeric_cast<IndexType>(numOutVertices));
            inToOutMapping.at(i) = boost::numeric_cast<IndexType>(numOutVertices);
            ++numOutVertices;
        }
    }

    /// 将唯一顶点打包到阵列中。
    outVertices.resize(numOutVertices);
    for (const auto& element : result)
    {
        outVertices.at(element.second) = element.first;
    }
}

template <typename VertexType, typename IndexType, int Dimension>
requires(std::is_integral_v<IndexType> && !std::is_same_v<IndexType, bool>)
void Mathematics::UniqueVerticesSimplices<VertexType, IndexType, Dimension>::RemoveUnused(const VertexContainer& inVertices,
                                                                                          int numInIndices,
                                                                                          const IndexContainer& inIndices,
                                                                                          VertexContainer& outVertices,
                                                                                          IndexContainer& outIndices)
{
    /// 获取所用索引的唯一集合。
    std::set<IndexType> usedIndices{};
    for (auto i = 0; i < numInIndices; ++i)
    {
        usedIndices.emplace(inIndices.at(i));
    }

    /// 找到使用过的顶点，并将它们打包到阵列中。
    outVertices.resize(usedIndices.size());
    auto numOutVertices = 0;
    std::map<IndexType, IndexType> result{};
    for (auto oldIndex : usedIndices)
    {
        outVertices.at(numOutVertices) = inVertices.at(oldIndex);
        result.emplace(oldIndex, boost::numeric_cast<IndexType>(numOutVertices));
        ++numOutVertices;
    }

    /// 将旧索引重新分配给新索引。
    for (auto i = 0; i < numInIndices; ++i)
    {
        outIndices.at(i) = result.find(inIndices.at(i))->second;
    }
}

#endif  // MATHEMATICS_MESHES_UNIQUE_VERTICES_SIMPLICES_DETAIL_H
