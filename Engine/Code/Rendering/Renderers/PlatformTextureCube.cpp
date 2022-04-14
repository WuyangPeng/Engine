// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/29 10:16)

#include "Rendering/RenderingExport.h"

#include "Detail/PlatformTextureCubeImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Rendering/Renderers/PlatformTextureCube.h"
#include "Rendering/Renderers/Renderer.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"

Rendering::PlatformTextureCube::PlatformTextureCube(Renderer* renderer, const TextureCube* textureCube)
    : impl{ CoreTools::ImplCreateUseFactory::Default, renderer, textureCube }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::PlatformTextureCube::~PlatformTextureCube()
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, PlatformTextureCube)

void Rendering::PlatformTextureCube::Enable(Renderer* renderer, int textureUnit)
{
    ;

    return impl->Enable(renderer, textureUnit);
}

void Rendering::PlatformTextureCube::Disable(Renderer* renderer, int textureUnit)
{
    ;

    return impl->Disable(renderer, textureUnit);
}

void* Rendering::PlatformTextureCube::Lock(int face, int level, BufferLocking mode)
{
    ;

    return impl->Lock(face, level, mode);
}

void Rendering::PlatformTextureCube::Unlock(int face, int level)
{
    ;

    return impl->Unlock(face, level);
}
