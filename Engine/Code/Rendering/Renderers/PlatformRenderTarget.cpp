///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/21 18:55)

#include "Rendering/RenderingExport.h"

#include "PlatformRenderTarget.h"
#include "Renderer.h"
#include "Detail/PlatformRenderTargetImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Rendering/OpenGLRenderer/OpenGLRenderTarget.h"

Rendering::PlatformRenderTarget::PlatformRenderTarget(Renderer* renderer, const DrawTarget* renderTarget)
    : impl{ CoreTools::ImplCreateUseFactory::Default, renderer, renderTarget }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, PlatformRenderTarget)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, PlatformRenderTarget, Enable, Renderer*, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, PlatformRenderTarget, Disable, Renderer*, void)

Rendering::ConstTexture2DSharedPtr Rendering::PlatformRenderTarget::ReadColor(int index, Renderer* renderer)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->ReadColor(index, renderer);
}