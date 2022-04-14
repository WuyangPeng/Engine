// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/29 10:14)

#include "Rendering/RenderingExport.h"

#include "PlatformTexture2D.h"
#include "Renderer.h"
#include "Detail/PlatformTexture2DImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"

Rendering::PlatformTexture2D::PlatformTexture2D(Renderer* renderer, const Texture2D* texture2D)
    : impl{ CoreTools::ImplCreateUseFactory::Default, renderer, texture2D }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::PlatformTexture2D::~PlatformTexture2D()
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, PlatformTexture2D)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, PlatformTexture2D, Unlock, int, void)

void Rendering::PlatformTexture2D::Enable(Renderer* renderer, int textureUnit)
{
    ;

    return impl->Enable(renderer, textureUnit);
}

void Rendering::PlatformTexture2D::Disable(Renderer* renderer, int textureUnit)
{
    ;

    return impl->Disable(renderer, textureUnit);
}

void* Rendering::PlatformTexture2D::Lock(int level, BufferLocking mode)
{
    ;

    return impl->Lock(level, mode);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, PlatformTexture2D, GetTexture, Rendering::PlatformTexture2D::UInt)
