///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/28 09:47)

#include "Rendering/RenderingExport.h"

#include "DrawTargetBridgeImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Rendering/Base/GraphicsObject.h"
#include "Rendering/Resources/Textures/DrawTarget.h"

Rendering::DrawTargetBridgeImpl::DrawTargetBridgeImpl() noexcept
    : container{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, DrawTargetBridgeImpl);

Rendering::DrawTargetBridgeImpl::RendererDrawTargetSharedPtr Rendering::DrawTargetBridgeImpl::BindDrawTarget(RendererTypes rendererTypes, const ConstDrawTargetSharedPtr& drawTarget, const RendererObjectContainer& renderTargetTextures, const RendererObjectSharedPtr& depthStencilTexture)
{
    RENDERING_CLASS_IS_VALID_9;

    if (auto iter = container.find(drawTarget);
        iter == container.end())
    {
        auto rendererDrawTarget = drawTarget->CreateRendererDrawTarget(rendererTypes, renderTargetTextures, depthStencilTexture);

        iter = container.emplace(drawTarget, rendererDrawTarget).first;

        return iter->second;
    }
    else
    {
        return iter->second;
    }
}

void Rendering::DrawTargetBridgeImpl::UnbindDrawTarget(const ConstDrawTargetSharedPtr& drawTarget) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    container.erase(drawTarget);
}

Rendering::DrawTargetBridgeImpl::RendererDrawTargetSharedPtr Rendering::DrawTargetBridgeImpl::GetDrawTarget(const ConstDrawTargetSharedPtr& drawTarget)
{
    RENDERING_CLASS_IS_VALID_9;

    return const_pointer_cast<RendererDrawTarget>(static_cast<const ClassType>(*this).GetDrawTarget(drawTarget));
}

Rendering::DrawTargetBridgeImpl::ConstRendererDrawTargetSharedPtr Rendering::DrawTargetBridgeImpl::GetDrawTarget(const ConstDrawTargetSharedPtr& drawTarget) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    if (const auto iter = container.find(drawTarget);
        iter != container.end())
    {
        return iter->second;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("DrawTarget未绑定。"s))
    }
}

bool Rendering::DrawTargetBridgeImpl::HasDrawTarget(const ConstDrawTargetSharedPtr& drawTarget) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return container.contains(drawTarget);
}
