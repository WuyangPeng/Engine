///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/20 14:03)

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

        // ���㻺����������
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
