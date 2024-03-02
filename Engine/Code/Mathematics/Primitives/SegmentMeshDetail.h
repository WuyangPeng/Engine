///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.6 (2024/03/02 21:18)

#ifndef MATHEMATICS_PRIMITIVES_SEGMENT_MESH_DETAIL_H
#define MATHEMATICS_PRIMITIVES_SEGMENT_MESH_DETAIL_H

#include "SegmentMesh.h"
#include "Flags/TopologyType.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
Mathematics::SegmentMesh<N, Real>::SegmentMesh() noexcept
    : topology{ TopologyType::Unknown }, vertices{}, indices{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
Mathematics::SegmentMesh<N, Real>::SegmentMesh(const VerticesType& vertices)
    : topology{ TopologyType::Disjoint },
      vertices{ vertices },
      indices(vertices.size() / 2)
{
    if (vertices.size() < 2)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("顶点数无效。"))
    }

    for (auto i = 0; i < boost::numeric_cast<int>(indices.size()); ++i)
    {
        indices.at(i).at(0) = 2 * i;
        indices.at(i).at(1) = indices.at(i).at(0) + 1;
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
Mathematics::SegmentMesh<N, Real>::SegmentMesh(const VerticesType& vertices, bool isOpen)
    : topology{ isOpen ? TopologyType::ContiguousOpen : TopologyType::ContiguousClosed },
      vertices{ vertices },
      indices(isOpen ? vertices.size() - 1 : vertices.size())
{
    if (vertices.size() < 2)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("顶点数无效。"))
    }

    const auto size = boost::numeric_cast<int>(indices.size());
    if (isOpen)
    {
        for (auto i0 = 0, i1 = 1; i0 < size; i0 = i1++)
        {
            indices.at(i0).at(0) = i0;
            indices.at(i0).at(1) = i1;
        }
    }
    else
    {
        for (auto i0 = size - 1, i1 = 0; i1 < size; i0 = i1++)
        {
            indices.at(i1).at(0) = i0;
            indices.at(i1).at(1) = i1;
        }
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
Mathematics::SegmentMesh<N, Real>::SegmentMesh(const VerticesType& vertices, const IndicesType& indices, bool validateIndices)
    : topology{ TopologyType::Indexed },
      vertices{ vertices },
      indices{ indices }
{
    const auto size = boost::numeric_cast<int>(vertices.size());
    if (size < 2 || indices.empty())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("顶点数或索引数无效。"))
    }

    if (validateIndices)
    {
        for (auto i = 0; i < size; ++i)
        {
            if (size <= indices.at(i).at(0) || size <= indices.at(i).at(1))
            {
                THROW_EXCEPTION(SYSTEM_TEXT("顶点数组的索引无效。"))
            }
        }
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::SegmentMesh<N, Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
Mathematics::TopologyType Mathematics::SegmentMesh<N, Real>::GetTopology() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return topology;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
typename Mathematics::SegmentMesh<N, Real>::VerticesType Mathematics::SegmentMesh<N, Real>::GetVertices() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return vertices;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
typename Mathematics::SegmentMesh<N, Real>::IndicesType Mathematics::SegmentMesh<N, Real>::GetIndices() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return indices;
}

#endif  // MATHEMATICS_PRIMITIVES_SEGMENT_MESH_DETAIL_H
