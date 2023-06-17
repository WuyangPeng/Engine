///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:35)

#ifndef RENDERING_RENDERERS_PLATFORM_INDEX_BUFFER_IMPL_H
#define RENDERING_RENDERERS_PLATFORM_INDEX_BUFFER_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Renderers/RenderersFwd.h"
#include "Rendering/Resources/Flags/BufferFlags.h"
#include "Rendering/Resources/ResourcesFwd.h"

#include <memory>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE PlatformIndexBufferImpl
    {
    public:
        using ClassType = PlatformIndexBufferImpl;
        using PlatformIndexBufferSharedPtr = std::shared_ptr<ClassType>;
        using FactoryType = PlatformIndexBufferImpl;

    public:
        PlatformIndexBufferImpl() noexcept;
        virtual ~PlatformIndexBufferImpl() noexcept = default;
        PlatformIndexBufferImpl(const PlatformIndexBufferImpl& rhs) noexcept = default;
        PlatformIndexBufferImpl& operator=(const PlatformIndexBufferImpl& rhs) noexcept = default;
        PlatformIndexBufferImpl(PlatformIndexBufferImpl&& rhs) noexcept = default;
        PlatformIndexBufferImpl& operator=(PlatformIndexBufferImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        // 缓冲区操作
        virtual void Enable(Renderer* renderer) = 0;
        virtual void Disable(Renderer* renderer) = 0;
        NODISCARD virtual void* Lock(BufferLocking mode) = 0;
        virtual void Unlock() = 0;

        NODISCARD static PlatformIndexBufferSharedPtr Create(Renderer* renderer, const IndexBuffer* indexBuffer);

    private:
        NODISCARD static PlatformIndexBufferSharedPtr CreateDefault(Renderer* renderer, const IndexBuffer* indexBuffer);
    };
}

#endif  // RENDERING_RENDERERS_PLATFORM_INDEX_BUFFER_IMPL_H
