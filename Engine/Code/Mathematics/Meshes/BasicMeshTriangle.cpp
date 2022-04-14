///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.4 (2022/03/22 16:20)

#include "Mathematics/MathematicsExport.h"

#include "BasicMeshTriangle.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Mathematics::BasicMeshTriangle::BasicMeshTriangle() noexcept
    : vertices{ -1, -1, -1 }, edges{ -1, -1, -1 }, triangles{ -1, -1, -1 }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Mathematics, BasicMeshTriangle)

int Mathematics::BasicMeshTriangle::GetVertex(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return vertices.at(index);
}

int Mathematics::BasicMeshTriangle::GetEdge(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return edges.at(index);
}

int Mathematics::BasicMeshTriangle::GetTriangle(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return triangles.at(index);
}

void Mathematics::BasicMeshTriangle::SetVertex(int index, int vertex)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    vertices.at(index) = vertex;
}

void Mathematics::BasicMeshTriangle::SetEdge(int index, int edge)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    edges.at(index) = edge;
}

void Mathematics::BasicMeshTriangle::SetTriangle(int index, int triangle)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    triangles.at(index) = triangle;
}
