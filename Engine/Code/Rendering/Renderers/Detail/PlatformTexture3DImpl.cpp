///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 12:43)

#include "Rendering/RenderingExport.h"

#include "PlatformTexture3DImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/Dx9Renderer/Dx9Texture3D.h"
#include "Rendering/OpenGLRenderer/OpenGLTexture3D.h"
#include "Rendering/Renderers/Flags/RendererTypes.h"
#include "Rendering/Renderers/Renderer.h"

Rendering::PlatformTexture3DImpl::PlatformTexture3DImpl() noexcept
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, PlatformTexture3DImpl)

// static
Rendering::PlatformTexture3DImpl::PlatformTexture3DSharedPtr Rendering::PlatformTexture3DImpl::Create(Renderer* renderer, const Texture3D* texture3D)
{
    if (renderer == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("renderer 为空。"s));
    }

    switch (renderer->GetRendererType())
    {
        case RendererTypes::Default:
            return CreateDefault(renderer, texture3D);
        case RendererTypes::Windows:
            return make_shared<Dx9Texture3D>(renderer, texture3D);
        case RendererTypes::Glut:
            return make_shared<OpenGLTexture3D>(renderer, texture3D);
        case RendererTypes::OpenGL:
            return make_shared<OpenGLTexture3D>(renderer, texture3D);
        case RendererTypes::Dx11:
            return make_shared<Dx9Texture3D>(renderer, texture3D);
        case RendererTypes::OpenGLES:
            return make_shared<OpenGLTexture3D>(renderer, texture3D);
        default:
            return CreateDefault(renderer, texture3D);
    }
}

// static
Rendering::PlatformTexture3DImpl::PlatformTexture3DSharedPtr Rendering::PlatformTexture3DImpl::CreateDefault(Renderer* renderer, const Texture3D* texture3D)
{
    return make_shared<OpenGLTexture3D>(renderer, texture3D);
}
