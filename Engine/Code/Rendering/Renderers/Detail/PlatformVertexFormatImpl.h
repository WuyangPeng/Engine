///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/20 14:07)

#ifndef RENDERING_RENDERERS_PLATFORM_VERTEX_FORMAT_IMPL_H
#define RENDERING_RENDERERS_PLATFORM_VERTEX_FORMAT_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Renderers/RenderersFwd.h"
#include "Rendering/Resources/Flags/BufferFlags.h"
#include "Rendering/Resources/ResourcesFwd.h"

#include <memory>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE PlatformVertexFormatImpl
    {
    public:
        using ClassType = PlatformVertexFormatImpl;
        using PlatformVertexFormatSharedPtr = std::shared_ptr<ClassType>;
        using FactoryType = ClassType;

    public:
        PlatformVertexFormatImpl() noexcept;
        virtual ~PlatformVertexFormatImpl() noexcept = default;
        PlatformVertexFormatImpl(const PlatformVertexFormatImpl& rhs) noexcept = default;
        PlatformVertexFormatImpl& operator=(const PlatformVertexFormatImpl& rhs) noexcept = default;
        PlatformVertexFormatImpl(PlatformVertexFormatImpl&& rhs) noexcept = default;
        PlatformVertexFormatImpl& operator=(PlatformVertexFormatImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        // �����ʽ������
        virtual void Enable(Renderer* renderer) = 0;
        virtual void Disable(Renderer* renderer) = 0;

        NODISCARD static PlatformVertexFormatSharedPtr Create(Renderer* renderer, const VertexFormat* vertexFormat);

    private:
        NODISCARD static PlatformVertexFormatSharedPtr CreateDefault(Renderer* renderer, const VertexFormat* vertexFormat);
    };
}

#endif  // RENDERING_RENDERERS_PLATFORM_VERTEX_FORMAT_IMPL_H
