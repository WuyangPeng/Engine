///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/20 14:02)

#include "Rendering/RenderingExport.h"

#include "PlatformTextureCubeImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/Dx9Renderer/Dx9TextureCube.h"
#include "Rendering/Renderers/Flags/RendererTypes.h"
#include "Rendering/Renderers/Renderer.h"

Rendering::PlatformTextureCubeImpl::PlatformTextureCubeImpl() noexcept
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, PlatformTextureCubeImpl)

// static
Rendering::PlatformTextureCubeImpl::PlatformTextureCubeSharedPtr Rendering::PlatformTextureCubeImpl::Create(Renderer* renderer, const TextureCube* textureCube)
{
    if (renderer == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("renderer 为空。"s));
    }

    switch (renderer->GetRendererType())
    {
        case RendererTypes::Default:
            return CreateDefault(renderer, textureCube);
        case RendererTypes::Windows:
            return make_shared<Dx9TextureCube>(renderer, textureCube);
        case RendererTypes::Glut:
            return make_shared<Dx9TextureCube>(renderer, textureCube);
        case RendererTypes::OpenGL:
            return make_shared<Dx9TextureCube>(renderer, textureCube);
        case RendererTypes::Dx11:
            return make_shared<Dx9TextureCube>(renderer, textureCube);
        case RendererTypes::OpenGLES:
            return make_shared<Dx9TextureCube>(renderer, textureCube);
        default:
            return CreateDefault(renderer, textureCube);
    }
}

// static
Rendering::PlatformTextureCubeImpl::PlatformTextureCubeSharedPtr Rendering::PlatformTextureCubeImpl::CreateDefault(Renderer* renderer, const TextureCube* textureCube)
{
    return make_shared<Dx9TextureCube>(renderer, textureCube);
}
