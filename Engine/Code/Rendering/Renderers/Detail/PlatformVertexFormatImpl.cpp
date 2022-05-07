///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/20 14:08)

#include "Rendering/RenderingExport.h"

#include "PlatformVertexFormatImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/Dx9Renderer/Dx9VertexFormat.h"
#include "Rendering/OpenGLRenderer/OpenGLVertexFormat.h"
#include "Rendering/Renderers/Flags/RendererTypes.h"
#include "Rendering/Renderers/Renderer.h"

Rendering::PlatformVertexFormatImpl::PlatformVertexFormatImpl() noexcept
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, PlatformVertexFormatImpl)

// static
Rendering::PlatformVertexFormatImpl::PlatformVertexFormatSharedPtr Rendering::PlatformVertexFormatImpl::Create(Renderer* renderer, const VertexFormat* vertexFormat)
{
    if (renderer == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("renderer Ϊ�ա�"s));
    }

    switch (renderer->GetRendererType())
    {
        case RendererTypes::Default:
            return CreateDefault(renderer, vertexFormat);
        case RendererTypes::Window:
            return make_shared<Dx9VertexFormat>(renderer, vertexFormat);
        case RendererTypes::Glut:
            return make_shared<OpenGLVertexFormat>(renderer, vertexFormat);
        case RendererTypes::OpenGL:
            return make_shared<OpenGLVertexFormat>(renderer, vertexFormat);
        case RendererTypes::Dx9:
            return make_shared<Dx9VertexFormat>(renderer, vertexFormat);
        case RendererTypes::OpenGLES:
            return make_shared<OpenGLVertexFormat>(renderer, vertexFormat);
        default:
            return CreateDefault(renderer, vertexFormat);
    }
}

// static
Rendering::PlatformVertexFormatImpl::PlatformVertexFormatSharedPtr Rendering::PlatformVertexFormatImpl::CreateDefault(Renderer* renderer, const VertexFormat* vertexFormat)
{
    return make_shared<OpenGLVertexFormat>(renderer, vertexFormat);
}
