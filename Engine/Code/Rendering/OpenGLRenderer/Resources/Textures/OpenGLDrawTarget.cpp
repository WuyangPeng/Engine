/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/08 15:44)

#include "Rendering/RenderingExport.h"

#include "OpenGLDrawTarget.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Rendering/OpenGLRenderer/Detail/Resources/Textures/OpenGLDrawTargetImpl.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, OpenGLDrawTarget)

Rendering::OpenGLDrawTarget::OpenGLDrawTarget(const ConstDrawTargetSharedPtr& target, const OpenGLTextureRenderTargetContainer& renderTargetTextures, const OpenGLTextureDepthStencilSharedPtr& depthStencilTexture)
    : ParentType{ target }, impl{ target, renderTargetTextures, depthStencilTexture }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, OpenGLDrawTarget)

Rendering::OpenGLDrawTarget::ConstOpenGLTextureRenderTargetSharedPtr Rendering::OpenGLDrawTarget::GetRenderTargetTexture(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetRenderTargetTexture(index);
}

Rendering::OpenGLDrawTarget::ConstOpenGLTextureDepthStencilSharedPtr Rendering::OpenGLDrawTarget::GetDepthStencilTexture() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetDepthStencilTexture();
}

void Rendering::OpenGLDrawTarget::Enable()
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->Enable();
}

void Rendering::OpenGLDrawTarget::Disable()
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->Disable();
}
