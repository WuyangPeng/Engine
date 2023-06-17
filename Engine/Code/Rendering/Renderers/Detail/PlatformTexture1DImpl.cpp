///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 12:43)

#include "Rendering/RenderingExport.h"

#include "PlatformTexture1DImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/Dx9Renderer/Dx9Texture1D.h"
#include "Rendering/OpenGLRenderer/OpenGLTexture1D.h"
#include "Rendering/Renderers/Flags/RendererTypes.h"
#include "Rendering/Renderers/Renderer.h"

Rendering::PlatformTexture1DImpl::PlatformTexture1DImpl() noexcept
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, PlatformTexture1DImpl)

// static
Rendering::PlatformTexture1DImpl::PlatformTexture1DSharedPtr Rendering::PlatformTexture1DImpl::Create(Renderer* renderer, const Texture1D* texture1D)
{
    if (renderer == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("renderer 为空。"s));
    }

    switch (renderer->GetRendererType())
    {
        case RendererTypes::Default:
            return CreateDefault(renderer, texture1D);
        case RendererTypes::Windows:
            return make_shared<Dx9Texture1D>(renderer, texture1D);
        case RendererTypes::Glut:
            return make_shared<OpenGLTexture1D>(renderer, texture1D);
        case RendererTypes::OpenGL:
            return make_shared<OpenGLTexture1D>(renderer, texture1D);
        case RendererTypes::Dx11:
            return make_shared<Dx9Texture1D>(renderer, texture1D);
        case RendererTypes::OpenGLES:
            return make_shared<OpenGLTexture1D>(renderer, texture1D);
        default:
            return CreateDefault(renderer, texture1D);
    }
}

// static
Rendering::PlatformTexture1DImpl::PlatformTexture1DSharedPtr Rendering::PlatformTexture1DImpl::CreateDefault(Renderer* renderer, const Texture1D* texture1D)
{
    return make_shared<OpenGLTexture1D>(renderer, texture1D);
}
