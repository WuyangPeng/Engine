///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:22)

#include "Rendering/RenderingExport.h"

#include "OpenGLRenderTargetData.h"
#include "OpenGLRenderTargetDataImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Rendering::OpenGLRenderTargetData::OpenGLRenderTargetData(BaseRenderer* renderer, const DrawTarget* renderTarget)
    : impl{ renderer, renderTarget }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, OpenGLRenderTargetData)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, OpenGLRenderTargetData, Enable, BaseRenderer*, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, OpenGLRenderTargetData, Disable, BaseRenderer*, void)

Rendering::ConstTexture2DSharedPtr Rendering::OpenGLRenderTargetData::ReadColor(int index, BaseRenderer* renderer)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->ReadColor(index, renderer);
}