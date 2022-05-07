///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/20 11:39)

#include "Rendering/RenderingExport.h"

#include "PlatformIndexBufferImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/Dx9Renderer/Dx9IndexBuffer.h"
#include "Rendering/OpenGLRenderer/OpenGLIndexBuffer.h"
#include "Rendering/Renderers/Flags/RendererTypes.h"
#include "Rendering/Renderers/Renderer.h"

using std::make_shared;

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
        case RendererTypes::Window:
            return make_shared<Dx9IndexBuffer>(renderer, indexBuffer);
        case RendererTypes::Glut:
            return make_shared<OpenGLIndexBuffer>(renderer, indexBuffer);
        case RendererTypes::OpenGL:
            return make_shared<OpenGLIndexBuffer>(renderer, indexBuffer);
        case RendererTypes::Dx9:
            return make_shared<Dx9IndexBuffer>(renderer, indexBuffer);
        case RendererTypes::OpenGLES:
            return make_shared<OpenGLIndexBuffer>(renderer, indexBuffer);
        default:
            return CreateDefault(renderer, indexBuffer);
    }
}

// static
Rendering::PlatformIndexBufferImpl::PlatformIndexBufferSharedPtr Rendering::PlatformIndexBufferImpl::CreateDefault(Renderer* renderer, const IndexBuffer* indexBuffer)
{
    return make_shared<OpenGLIndexBuffer>(renderer, indexBuffer);
}
