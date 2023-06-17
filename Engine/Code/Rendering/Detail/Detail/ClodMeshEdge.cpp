///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:52)

#include "Rendering/RenderingExport.h"

#include "ClodMeshEdge.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::ClodMeshEdge::ClodMeshEdge() noexcept
    : adjTriangles{}, minHeapRecordIndex{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, ClodMeshEdge)

void Rendering::ClodMeshEdge::InsertTriangleKey(const TriangleKey& triangleKey)
{
    RENDERING_CLASS_IS_VALID_9;

    adjTriangles.insert(triangleKey);
}

int Rendering::ClodMeshEdge::GetTriangleKeySize() const  
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(adjTriangles.size());
}

Rendering::ClodMeshEdge::TriangleKeySetConstIter Rendering::ClodMeshEdge::GetTriangleKeyBegin() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return adjTriangles.begin();
}

Rendering::ClodMeshEdge::TriangleKeySetConstIter Rendering::ClodMeshEdge::GetTriangleKeyEnd() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return adjTriangles.end();
}

int Rendering::ClodMeshEdge::GetMinHeapRecordIndex() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return minHeapRecordIndex;
}

void Rendering::ClodMeshEdge::SetMinHeapRecordIndex(int index) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    minHeapRecordIndex = index;
}

void Rendering::ClodMeshEdge::EraseTriangleKey(const TriangleKey& triangleKey)
{
    RENDERING_CLASS_IS_VALID_9;

    adjTriangles.erase(triangleKey);
}

Rendering::ClodMeshEdge::TriangleKey Rendering::ClodMeshEdge::GetBeginTriangleKey() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(!adjTriangles.empty(), "三角形键值集合不能为空！");

    return *adjTriangles.begin();
}

Rendering::ClodMeshEdge::TriangleKey Rendering::ClodMeshEdge::GetEndTriangleKey() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(!adjTriangles.empty(), "三角形键值集合不能为空！");

    return *adjTriangles.rbegin();
}
