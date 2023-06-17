///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 12:43)

#include "Rendering/RenderingExport.h"

#include "PlatformRenderTargetImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/Dx9Renderer/Dx9RenderTarget.h"
#include "Rendering/OpenGLRenderer/OpenGLRenderTarget.h"
#include "Rendering/Renderers/Flags/RendererTypes.h"
#include "Rendering/Renderers/Renderer.h"

Rendering::PlatformRenderTargetImpl::PlatformRenderTargetImpl() noexcept
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, PlatformRenderTargetImpl)

// static
Rendering::PlatformRenderTargetImpl::PlatformRenderTargetSharedPtr Rendering::PlatformRenderTargetImpl::Create(Renderer* renderer, const DrawTarget* renderTarget)
{
    if (renderer == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("renderer 为空。"s));
    }

    switch (renderer->GetRendererType())
    {
        case RendererTypes::Default:
            return CreateDefault(renderer, renderTarget);
        case RendererTypes::Windows:
            return make_shared<Dx9RenderTarget>(renderer, renderTarget);
        case RendererTypes::Glut:
            return make_shared<OpenGLRenderTarget>(renderer, renderTarget);
        case RendererTypes::OpenGL:
            return make_shared<OpenGLRenderTarget>(renderer, renderTarget);
        case RendererTypes::Dx11:
            return make_shared<Dx9RenderTarget>(renderer, renderTarget);
        case RendererTypes::OpenGLES:
            return make_shared<OpenGLRenderTarget>(renderer, renderTarget);
        default:
            return CreateDefault(renderer, renderTarget);
    }
}

// static
Rendering::PlatformRenderTargetImpl::PlatformRenderTargetSharedPtr Rendering::PlatformRenderTargetImpl::CreateDefault(Renderer* renderer, const DrawTarget* renderTarget)
{
    return make_shared<OpenGLRenderTarget>(renderer, renderTarget);
}
