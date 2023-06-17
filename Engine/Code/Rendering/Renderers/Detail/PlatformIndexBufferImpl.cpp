///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 12:42)

#include "Rendering/RenderingExport.h"

#include "PlatformIndexBufferImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/Dx9Renderer/Dx9IndexBuffer.h"
#include "Rendering/Renderers/Flags/RendererTypes.h"
#include "Rendering/Renderers/Renderer.h"

Rendering::PlatformIndexBufferImpl::PlatformIndexBufferImpl() noexcept
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, PlatformIndexBufferImpl)

// static
Rendering::PlatformIndexBufferImpl::PlatformIndexBufferSharedPtr Rendering::PlatformIndexBufferImpl::Create(Renderer* renderer, const IndexBuffer* indexBuffer)
{
    if (renderer == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("renderer 为空。"s));
    }

    switch (renderer->GetRendererType())
    {
        case RendererTypes::Default:
            return CreateDefault(renderer, indexBuffer);
        case RendererTypes::Windows:
            return make_shared<Dx9IndexBuffer>(renderer, indexBuffer);
        case RendererTypes::Glut:
            return make_shared<Dx9IndexBuffer>(renderer, indexBuffer);
        case RendererTypes::OpenGL:
            return make_shared<Dx9IndexBuffer>(renderer, indexBuffer);
        case RendererTypes::Dx11:
            return make_shared<Dx9IndexBuffer>(renderer, indexBuffer);
        case RendererTypes::OpenGLES:
            return make_shared<Dx9IndexBuffer>(renderer, indexBuffer);
        default:
            return CreateDefault(renderer, indexBuffer);
    }
}

// static
Rendering::PlatformIndexBufferImpl::PlatformIndexBufferSharedPtr Rendering::PlatformIndexBufferImpl::CreateDefault(Renderer* renderer, const IndexBuffer* indexBuffer)
{
    return make_shared<Dx9IndexBuffer>(renderer, indexBuffer);
}
