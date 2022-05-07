///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/22 18:12)

#include "Rendering/RenderingExport.h"

#include "OpenGLIndexBuffer.h"
#include "OpenGLMapping.h"
#include "System/MemoryTools/MemoryHelper.h"
#include "System/OpenGL/OpenGLAPI.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/Renderers/BufferLockManagerDetail.h"
#include "Rendering/Resources/IndexBuffer.h"

Rendering::OpenGLIndexBuffer::OpenGLIndexBuffer([[maybe_unused]] Renderer* renderer, const IndexBuffer* indexBuffer)
    : ParentType{}, buffer{ 0 }
{
    Init(indexBuffer);

    RENDERING_SELF_CLASS_IS_VALID_1;
}

// private
void Rendering::OpenGLIndexBuffer::Init(const IndexBuffer* indexBuffer)
{
    if (indexBuffer != nullptr)
    {
        BufferLockManager<ClassType> manager{ *this };

        void* data = manager.Lock(BufferLocking::WriteOnly);

        System::MemoryCopy(data, indexBuffer->GetReadOnlyData(), indexBuffer->GetNumBytes());
    }
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::OpenGLIndexBuffer::IsValid() const noexcept
{
    if (ParentType::IsValid() && 0 <= buffer)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

void Rendering::OpenGLIndexBuffer::Enable(MAYBE_UNUSED Renderer* renderer) noexcept
{
    RENDERING_CLASS_IS_VALID_1;
}

void Rendering::OpenGLIndexBuffer::Disable(MAYBE_UNUSED Renderer* renderer) noexcept
{
    RENDERING_CLASS_IS_VALID_1;
}

void* Rendering::OpenGLIndexBuffer::Lock(MAYBE_UNUSED BufferLocking mode) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    return nullptr;
}

void Rendering::OpenGLIndexBuffer::Unlock() noexcept
{
    RENDERING_CLASS_IS_VALID_1;
}
