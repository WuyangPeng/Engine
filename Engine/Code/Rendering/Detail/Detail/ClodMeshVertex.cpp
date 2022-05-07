///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/09 19:18)

#include "Rendering/RenderingExport.h"

#include "ClodMeshVertex.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::ClodMeshVertex::ClodMeshVertex() noexcept
    : adjEdges{}, adjTriangles{}, collapsible{ true }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, ClodMeshVertex)

void Rendering::ClodMeshVertex::InsertTriangleKey(const TriangleKey& triangleKey)
{
    RENDERING_CLASS_IS_VALID_9;

    adjTriangles.emplace(triangleKey);
}

void Rendering::ClodMeshVertex::InsertEdgeKey(const EdgeKey& edgeKey)
{
    RENDERING_CLASS_IS_VALID_9;

    adjEdges.emplace(edgeKey);
}

void Rendering::ClodMeshVertex::SetCollapsible(bool aCollapsible) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    collapsible = aCollapsible;
}

int Rendering::ClodMeshVertex::GetTriangleKeySize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(adjTriangles.size());
}

int Rendering::ClodMeshVertex::GetEdgeKeySize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(adjEdges.size());
}

bool Rendering::ClodMeshVertex::IsCollapsible() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return collapsible;
}

Rendering::ClodMeshVertex::TriangleKeySetConstIter Rendering::ClodMeshVertex::GetTriangleKeyBegin() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return adjTriangles.begin();
}

Rendering::ClodMeshVertex::TriangleKeySetConstIter Rendering::ClodMeshVertex::GetTriangleKeyEnd() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return adjTriangles.end();
}

Rendering::ClodMeshVertex::EdgeKeySetConstIter Rendering::ClodMeshVertex::GetEdgeKeyBegin() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return adjEdges.begin();
}

Rendering::ClodMeshVertex::EdgeKeySetConstIter Rendering::ClodMeshVertex::GetEdgeKeyEnd() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return adjEdges.end();
}

void Rendering::ClodMeshVertex::EraseTriangleKey(const TriangleKey& triangleKey)
{
    RENDERING_CLASS_IS_VALID_9;

    adjTriangles.erase(triangleKey);
}

void Rendering::ClodMeshVertex::EraseEdgeKey(const EdgeKey& edgeKey)
{
    RENDERING_CLASS_IS_VALID_9;

    adjEdges.erase(edgeKey);
}
