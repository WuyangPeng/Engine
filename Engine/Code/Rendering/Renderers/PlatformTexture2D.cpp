///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/21 18:57)

#include "Rendering/RenderingExport.h"

#include "PlatformTexture2D.h"
#include "Renderer.h"
#include "Detail/PlatformTexture2DImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Rendering::PlatformTexture2D::PlatformTexture2D(Renderer* renderer, const Texture2D* texture2D)
    : impl{ CoreTools::ImplCreateUseFactory::Default, renderer, texture2D }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, PlatformTexture2D)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, PlatformTexture2D, Unlock, int, void)

void Rendering::PlatformTexture2D::Enable(Renderer* renderer, int textureUnit)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->Enable(renderer, textureUnit);
}

void Rendering::PlatformTexture2D::Disable(Renderer* renderer, int textureUnit)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->Disable(renderer, textureUnit);
}

void* Rendering::PlatformTexture2D::Lock(int level, BufferLocking mode)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->Lock(level, mode);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, PlatformTexture2D, GetTexture, Rendering::PlatformTexture2D::UInt)
