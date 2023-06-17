///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 12:49)

#include "Rendering/RenderingExport.h"

#include "Detail/PlatformTextureCubeImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Rendering/Renderers/PlatformTextureCube.h"
#include "Rendering/Renderers/Renderer.h"

Rendering::PlatformTextureCube::PlatformTextureCube(Renderer* renderer, const TextureCube* textureCube)
    : impl{ CoreTools::ImplCreateUseFactory::Default, renderer, textureCube }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, PlatformTextureCube)

void Rendering::PlatformTextureCube::Enable(Renderer* renderer, int textureUnit)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->Enable(renderer, textureUnit);
}

void Rendering::PlatformTextureCube::Disable(Renderer* renderer, int textureUnit)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->Disable(renderer, textureUnit);
}

void* Rendering::PlatformTextureCube::Lock(int face, int level, BufferLocking mode)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->Lock(face, level, mode);
}

void Rendering::PlatformTextureCube::Unlock(int face, int level)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->Unlock(face, level);
}
