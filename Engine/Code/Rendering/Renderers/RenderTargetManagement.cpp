///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/22 14:40)

#include "Rendering/RenderingExport.h"

#include "PlatformRenderTarget.h"
#include "RenderTargetManagement.h"
#include "Detail/RenderTargetManagementImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;

Rendering::RenderTargetManagement::RenderTargetManagement(const RendererSharedPtr& renderer)
    : impl{ renderer }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, RenderTargetManagement)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, RenderTargetManagement, Bind, ConstDrawTargetSharedPtr, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, RenderTargetManagement, Unbind, ConstDrawTargetSharedPtr, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, RenderTargetManagement, Enable, ConstDrawTargetSharedPtr, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, RenderTargetManagement, Disable, ConstDrawTargetSharedPtr, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, RenderTargetManagement, GetResource, ConstDrawTargetSharedPtr, Rendering::RenderTargetManagement::PlatformRenderTargetSharedPtr)

Rendering::ConstTexture2DSharedPtr Rendering::RenderTargetManagement::ReadColor(int index, const ConstDrawTargetSharedPtr& renderTarget)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->ReadColor(index, renderTarget);
}
