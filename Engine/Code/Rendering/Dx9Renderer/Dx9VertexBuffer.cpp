///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/23 21:24)

#include "Rendering/RenderingExport.h"

#include "Dx9VertexBuffer.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/Renderers/BufferLockManagerDetail.h"
#include "Rendering/Resources/Buffers/VertexBuffer.h"

Rendering::Dx9VertexBuffer::Dx9VertexBuffer(MAYBE_UNUSED Renderer* renderer, MAYBE_UNUSED const VertexBuffer* vertexBuffer) noexcept
    : ParentType{}
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::Dx9VertexBuffer::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

void Rendering::Dx9VertexBuffer::Enable(MAYBE_UNUSED Renderer* renderer, MAYBE_UNUSED int vertexSize, MAYBE_UNUSED int streamIndex, MAYBE_UNUSED int offset) noexcept
{
    RENDERING_CLASS_IS_VALID_1;
}

void Rendering::Dx9VertexBuffer::Disable(MAYBE_UNUSED Renderer* renderer, MAYBE_UNUSED int streamIndex) noexcept
{
    RENDERING_CLASS_IS_VALID_1;
}

void* Rendering::Dx9VertexBuffer::Lock(MAYBE_UNUSED BufferLocking mode) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    return nullptr;
}

void Rendering::Dx9VertexBuffer::Unlock() noexcept
{
    RENDERING_CLASS_IS_VALID_1;
}
