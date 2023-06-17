///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 10:17)

#include "Mathematics/MathematicsExport.h"

#include "BasicMeshVertexImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Mathematics::BasicMeshVertexImpl::BasicMeshVertexImpl() noexcept
    : vertices{}, edges{}, triangles{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Mathematics, BasicMeshVertexImpl)

int Mathematics::BasicMeshVertexImpl::GetVertex(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return vertices.at(index);
}

int Mathematics::BasicMeshVertexImpl::GetEdge(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return edges.at(index);
}

int Mathematics::BasicMeshVertexImpl::GetTriangle(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return triangles.at(index);
}

void Mathematics::BasicMeshVertexImpl::InsertEdge(int vertex, int edge)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    // 检查顶点/边是否在相邻数组（如果在则什么都不做）。
    for (auto vertice : vertices)
    {
        if (vertex == vertice)
        {
            return;
        }
    }

    vertices.emplace_back(vertex);
    edges.emplace_back(edge);
}

void Mathematics::BasicMeshVertexImpl::InsertTriangle(int triangle)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    // 检查三角形是否在相邻数组（如果在则什么都不做）。
    for (auto i : triangles)
    {
        if (triangle == i)
        {
            return;
        }
    }

    triangles.emplace_back(triangle);
}
