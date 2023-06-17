///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 12:43)

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
        THROW_EXCEPTION(SYSTEM_TEXT("renderer 为空。"s));
    }

    switch (renderer->GetRendererType())
    {
        case RendererTypes::Default:
            return CreateDefault(renderer, vertexFormat);
        case RendererTypes::Windows:
            return make_shared<Dx9VertexFormat>(renderer, vertexFormat);
        case RendererTypes::Glut:
            return make_shared<OpenGLVertexFormat>(renderer, vertexFormat);
        case RendererTypes::OpenGL:
            return make_shared<OpenGLVertexFormat>(renderer, vertexFormat);
        case RendererTypes::Dx11:
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
