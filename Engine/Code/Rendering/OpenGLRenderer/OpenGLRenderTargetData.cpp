///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/22 21:31)

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
    RENDERING_CLASS_IS_VALID_1;

    return impl->ReadColor(index, renderer);
}