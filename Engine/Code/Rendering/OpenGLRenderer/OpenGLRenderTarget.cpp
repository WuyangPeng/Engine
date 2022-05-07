///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/22 21:29)

#include "Rendering/RenderingExport.h"

#include "OpenGLMapping.h"
#include "OpenGLRenderTarget.h"
#include "OpenGLTexture2D.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::OpenGLRenderTarget::OpenGLRenderTarget(Renderer* renderer, const RenderTarget* renderTarget)
    : ParentType{}, openGLRenderTargetData{ renderer, renderTarget }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, OpenGLRenderTarget)

void Rendering::OpenGLRenderTarget::Enable(Renderer* renderer) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return openGLRenderTargetData.Enable(renderer);
}

void Rendering::OpenGLRenderTarget::Disable(Renderer* renderer) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return openGLRenderTargetData.Disable(renderer);
}

Rendering::ConstTexture2DSharedPtr Rendering::OpenGLRenderTarget::ReadColor(int index, Renderer* renderer)
{
    RENDERING_CLASS_IS_VALID_9;

    return openGLRenderTargetData.ReadColor(index, renderer);
}
