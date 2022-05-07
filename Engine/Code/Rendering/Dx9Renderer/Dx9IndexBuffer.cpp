///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/23 17:17)

#include "Rendering/RenderingExport.h"

#include "Dx9IndexBuffer.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::Dx9IndexBuffer::Dx9IndexBuffer(MAYBE_UNUSED Renderer* renderer, MAYBE_UNUSED const IndexBuffer* indexBuffer) noexcept
    : ParentType{}
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::Dx9IndexBuffer::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

void Rendering::Dx9IndexBuffer::Enable(MAYBE_UNUSED Renderer* renderer) noexcept
{
    RENDERING_CLASS_IS_VALID_1;
}

void Rendering::Dx9IndexBuffer::Disable(MAYBE_UNUSED Renderer* renderer) noexcept
{
    RENDERING_CLASS_IS_VALID_1;
}

void* Rendering::Dx9IndexBuffer::Lock(MAYBE_UNUSED BufferLocking mode) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    return nullptr;
}

void Rendering::Dx9IndexBuffer::Unlock() noexcept
{
    RENDERING_CLASS_IS_VALID_1;
}