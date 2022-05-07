///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/23 14:39)

#include "Rendering/RenderingExport.h"

#include "OpenGLMapping.h"
#include "OpenGLVertexBuffer.h"
#include "System/MemoryTools/MemoryHelper.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/Renderers/BufferLockManagerDetail.h"
#include "Rendering/Resources/VertexBuffer.h"

Rendering::OpenGLVertexBuffer::OpenGLVertexBuffer(MAYBE_UNUSED Renderer* renderer, const VertexBuffer* vertexBuffer)
    : ParentType{}, buffer{ 0 }
{
    Init(vertexBuffer);

    RENDERING_SELF_CLASS_IS_VALID_1;
}

void Rendering::OpenGLVertexBuffer::Init(const VertexBuffer* vertexBuffer)
{
    if (vertexBuffer != nullptr)
    {
        BufferLockManager<ClassType> manager(*this);
        auto data = manager.Lock(BufferLocking::WriteOnly);

        System::MemoryCopy(data, vertexBuffer->GetReadOnlyData(), vertexBuffer->GetNumBytes());
    }
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::OpenGLVertexBuffer::IsValid() const noexcept
{
    if (ParentType::IsValid() && 0 <= buffer)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

void Rendering::OpenGLVertexBuffer::Enable(MAYBE_UNUSED Renderer* renderer, MAYBE_UNUSED int vertexSize, MAYBE_UNUSED int streamIndex, [[maybe_unused]] int offset) noexcept
{
    RENDERING_CLASS_IS_VALID_1;
}

void Rendering::OpenGLVertexBuffer::Disable(MAYBE_UNUSED Renderer* renderer, MAYBE_UNUSED int streamIndex) noexcept
{
    RENDERING_CLASS_IS_VALID_1;
}

void* Rendering::OpenGLVertexBuffer::Lock(MAYBE_UNUSED BufferLocking mode) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    return nullptr;
}

void Rendering::OpenGLVertexBuffer::Unlock() noexcept
{
    RENDERING_CLASS_IS_VALID_1;
}
