// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/29 11:25)

#include "Rendering/RenderingExport.h"

#include "OpenGLRenderTargetData.h"
#include "OpenGLRenderTargetDataImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;

Rendering::OpenGLRenderTargetData::OpenGLRenderTargetData(Renderer* renderer, const RenderTarget* renderTarget)
    : impl{ renderer, renderTarget }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, OpenGLRenderTargetData)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, OpenGLRenderTargetData, Enable, Renderer*, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, OpenGLRenderTargetData, Disable, Renderer*, void)

Rendering::ConstTexture2DSharedPtr Rendering::OpenGLRenderTargetData::ReadColor(int index, Renderer* renderer)
{
    ;

    return impl->ReadColor(index, renderer);
}