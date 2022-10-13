///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/20 13:57)

#include "Rendering/RenderingExport.h"

#include "PlatformTexture2DImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/Dx9Renderer/Dx9Texture2D.h"
#include "Rendering/OpenGLRenderer/OpenGLTexture2D.h"
#include "Rendering/Renderers/Flags/RendererTypes.h"
#include "Rendering/Renderers/Renderer.h"

Rendering::PlatformTexture2DImpl::PlatformTexture2DImpl() noexcept
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, PlatformTexture2DImpl)

// static
Rendering::PlatformTexture2DImpl::PlatformTexture2DSharedPtr Rendering::PlatformTexture2DImpl::Create(Renderer* renderer, const Texture2D* texture2D)
{
    if (renderer == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("renderer 为空。"s));
    }

    switch (renderer->GetRendererType())
    {
        case RendererTypes::Default:
            return CreateDefault(renderer, texture2D);
        case RendererTypes::Windows:
            return make_shared<Dx9Texture2D>(renderer, texture2D);
        case RendererTypes::Glut:
            return make_shared<OpenGLTexture2D>(renderer, texture2D);
        case RendererTypes::OpenGL:
            return make_shared<OpenGLTexture2D>(renderer, texture2D);
        case RendererTypes::Dx11:
            return make_shared<Dx9Texture2D>(renderer, texture2D);
        case RendererTypes::OpenGLES:
            return make_shared<OpenGLTexture2D>(renderer, texture2D);
        default:
            return CreateDefault(renderer, texture2D);
    }
}

// static
Rendering::PlatformTexture2DImpl::PlatformTexture2DSharedPtr Rendering::PlatformTexture2DImpl::CreateDefault(Renderer* renderer, const Texture2D* texture2D)
{
    return make_shared<OpenGLTexture2D>(renderer, texture2D);
}
