// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/29 10:13)

#include "Rendering/RenderingExport.h"

#include "PlatformRenderTarget.h"
#include "Renderer.h"
#include "Detail/PlatformRenderTargetImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Rendering/OpenGLRenderer/OpenGLRenderTarget.h"

Rendering::PlatformRenderTarget ::PlatformRenderTarget(Renderer* renderer, const RenderTarget* renderTarget)
    : impl{ CoreTools::ImplCreateUseFactory::Default, renderer, renderTarget }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, PlatformRenderTarget)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, PlatformRenderTarget, Enable, Renderer*, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, PlatformRenderTarget, Disable, Renderer*, void)

Rendering::ConstTexture2DSharedPtr Rendering::PlatformRenderTarget ::ReadColor(int index, Renderer* renderer)
{
    ;

    return impl->ReadColor(index, renderer);
}