// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/26 14:14)

#ifndef RENDERING_RENDERERS_PLATFORM_INDEX_BUFFER_IMPL_H
#define RENDERING_RENDERERS_PLATFORM_INDEX_BUFFER_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Resources/Flags/BufferFlags.h"

#include <memory>

namespace Rendering
{
    class Renderer;
    class IndexBuffer;

    class RENDERING_HIDDEN_DECLARE PlatformIndexBufferImpl
    {
    public:
        using ClassType = PlatformIndexBufferImpl;
        using PlatformIndexBufferPtr = std::shared_ptr<ClassType>;

    public:
        PlatformIndexBufferImpl() noexcept;
        virtual ~PlatformIndexBufferImpl();
        PlatformIndexBufferImpl(const PlatformIndexBufferImpl&) = default;
        PlatformIndexBufferImpl& operator=(const PlatformIndexBufferImpl&) = default;
        PlatformIndexBufferImpl( PlatformIndexBufferImpl&&) = default;
        PlatformIndexBufferImpl& operator=( PlatformIndexBufferImpl&&) = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        // »º³åÇø²Ù×÷
        virtual void Enable(Renderer* renderer) = 0;
        virtual void Disable(Renderer* renderer) = 0;
        virtual void* Lock(BufferLocking mode) = 0;
        virtual void Unlock() = 0;

        static PlatformIndexBufferPtr Create(Renderer* renderer, const IndexBuffer* indexBuffer);

    private:
        static PlatformIndexBufferPtr CreateDefault(Renderer* renderer, const IndexBuffer* indexBuffer);
    };
}

#endif  // RENDERING_RENDERERS_PLATFORM_INDEX_BUFFER_IMPL_H
