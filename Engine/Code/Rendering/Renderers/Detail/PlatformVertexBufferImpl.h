///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/20 14:03)

#ifndef RENDERING_RENDERERS_PLATFORM_VERTEX_BUFFER_IMPL_H
#define RENDERING_RENDERERS_PLATFORM_VERTEX_BUFFER_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Renderers/RenderersFwd.h"
#include "Rendering/Resources/Flags/BufferFlags.h"
#include "Rendering/Resources/ResourcesFwd.h"

#include <memory>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE PlatformVertexBufferImpl
    {
    public:
        using ClassType = PlatformVertexBufferImpl;
        using PlatformVertexBufferSharedPtr = std::shared_ptr<ClassType>;
        using FactoryType = ClassType;

    public:
        PlatformVertexBufferImpl() noexcept;
        virtual ~PlatformVertexBufferImpl() noexcept = default;
        PlatformVertexBufferImpl(const PlatformVertexBufferImpl& rhs) noexcept = default;
        PlatformVertexBufferImpl& operator=(const PlatformVertexBufferImpl& rhs) noexcept = default;
        PlatformVertexBufferImpl(PlatformVertexBufferImpl&& rhs) noexcept = default;
        PlatformVertexBufferImpl& operator=(PlatformVertexBufferImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        // 顶点缓冲区操作。
        virtual void Enable(Renderer* renderer, int vertexSize, int streamIndex, int offset) = 0;
        virtual void Disable(Renderer* renderer, int streamIndex) = 0;
        NODISCARD virtual void* Lock(BufferLocking mode) = 0;
        virtual void Unlock() = 0;

        NODISCARD static PlatformVertexBufferSharedPtr Create(Renderer* renderer, const VertexBuffer* vertexBuffer);

    private:
        NODISCARD static PlatformVertexBufferSharedPtr CreateDefault(Renderer* renderer, const VertexBuffer* vertexBuffer);
    };
}

#endif  // RENDERING_RENDERERS_PLATFORM_VERTEX_BUFFER_IMPL_H
