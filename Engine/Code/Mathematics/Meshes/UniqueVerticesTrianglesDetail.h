///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/23 16:02)

#ifndef MATHEMATICS_MESHES_UNIQUE_VERTICES_TRIANGLES_DETAIL_H
#define MATHEMATICS_MESHES_UNIQUE_VERTICES_TRIANGLES_DETAIL_H

#include "UniqueVerticesTriangles.h"
#include "CoreTools/DataTypes/TupleDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include <map>

template <int N, typename Real>
Mathematics::UniqueVerticesTriangles<N, Real>::UniqueVerticesTriangles(int numTriangles, const std::vector<CoreTools::Tuple<N, Real>>& inVertices)
    : numInVertices{ 3 * numTriangles },
      numOutVertices{},
      inToOutMapping{},
      outVertices{},
      outIndices{}
{
    ConstructUniqueVertices(inVertices);

    outIndices = inToOutMapping;

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int N, typename Real>
Mathematics::UniqueVerticesTriangles<N, Real>::UniqueVerticesTriangles(int numInVertices, const std::vector<CoreTools::Tuple<N, Real>>& inVertices, int numTriangles, const std::vector<int>& inIndices)
    : numInVertices{ numInVertices },
      numOutVertices{},
      inToOutMapping{},
      outVertices{},
      outIndices{}
{
    ConstructUniqueVertices(inVertices);

    const auto numIndices = 3 * numTriangles;
    outIndices.resize(numIndices);
    for (auto i = 0; i < numIndices; ++i)
    {
        outIndices.at(i) = inToOutMapping.at(inIndices.at(i));
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <int N, typename Real>
bool Mathematics::UniqueVerticesTriangles<N, Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <int N, typename Real>
int Mathematics::UniqueVerticesTriangles<N, Real>::GetOutputIndexFor(int inputIndex) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return inToOutMapping.at(inputIndex);
}

template <int N, typename Real>
void Mathematics::UniqueVerticesTriangles<N, Real>::ConstructUniqueVertices(const std::vector<CoreTools::Tuple<N, Real>>& inVertices)
{
    inToOutMapping.resize(numInVertices);
    std::map<CoreTools::Tuple<N, Real>, int> table{};
    numOutVertices = 0;

    for (auto i = 0; i < numInVertices; ++i)
    {
        const auto iter = table.find(inVertices.at(i));
        if (iter != table.end())
        {
            inToOutMapping.at(i) = iter->second;
        }
        else
        {
            table.emplace(inVertices.at(i), numOutVertices);
            inToOutMapping.at(i) = numOutVertices;
            numOutVertices++;
        }
    }

    outVertices.resize(numOutVertices);
    for (const auto& value : table)
    {
        outVertices.at(value.second) = value.first;
    }
}

template <int N, typename Real>
std::vector<CoreTools::Tuple<N, Real>> Mathematics::UniqueVerticesTriangles<N, Real>::GetOutVertices() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return outVertices;
}

template <int N, typename Real>
std::vector<int> Mathematics::UniqueVerticesTriangles<N, Real>::GetOutIndices() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return outIndices;
}

#endif  // MATHEMATICS_MESHES_UNIQUE_VERTICES_TRIANGLES_DETAIL_H