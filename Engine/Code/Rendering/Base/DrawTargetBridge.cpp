/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/08 17:45)

#include "Rendering/RenderingExport.h"

#include "DrawTargetBridge.h"
#include "Detail/DrawTargetBridgeImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, DrawTargetBridge)

Rendering::DrawTargetBridge::DrawTargetBridgeSharedPtr Rendering::DrawTargetBridge::Create()
{
    return std::make_shared<DrawTargetBridge>(DrawTargetBridgeCreate::Init);
}

Rendering::DrawTargetBridge::DrawTargetBridge(DrawTargetBridgeCreate drawTargetBridgeCreate)
    : impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    System::UnusedFunction(drawTargetBridgeCreate);

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, DrawTargetBridge)

Rendering::DrawTargetBridge::RendererDrawTargetSharedPtr Rendering::DrawTargetBridge::BindDrawTarget(RendererTypes rendererTypes, const ConstDrawTargetSharedPtr& drawTarget, const RendererObjectContainer& renderTargetTextures, const RendererObjectSharedPtr& depthStencilTexture)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->BindDrawTarget(rendererTypes, drawTarget, renderTargetTextures, depthStencilTexture);
}

void Rendering::DrawTargetBridge::UnbindDrawTarget(const ConstDrawTargetSharedPtr& drawTarget)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->UnbindDrawTarget(drawTarget);
}

Rendering::DrawTargetBridge::RendererDrawTargetSharedPtr Rendering::DrawTargetBridge::GetDrawTarget(const ConstDrawTargetSharedPtr& drawTarget)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->GetDrawTarget(drawTarget);
}

Rendering::DrawTargetBridge::ConstRendererDrawTargetSharedPtr Rendering::DrawTargetBridge::GetDrawTarget(const ConstDrawTargetSharedPtr& drawTarget) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetDrawTarget(drawTarget);
}

bool Rendering::DrawTargetBridge::HasDrawTarget(const ConstDrawTargetSharedPtr& drawTarget) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->HasDrawTarget(drawTarget);
};
