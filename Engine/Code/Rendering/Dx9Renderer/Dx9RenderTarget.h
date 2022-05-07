///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/23 18:15)

#ifndef RENDERING_RENDERERS_DX9_RENDER_TARGET_H
#define RENDERING_RENDERERS_DX9_RENDER_TARGET_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Renderers/Detail/PlatformRenderTargetImpl.h"

namespace Rendering
{
    class Dx9RenderTarget : public PlatformRenderTargetImpl
    {
    public:
        using ClassType = Dx9RenderTarget;
        using ParentType = PlatformRenderTargetImpl;

    public:
        Dx9RenderTarget(Renderer* renderer, const RenderTarget* renderTarget) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void Enable(Renderer* renderer) noexcept override;
        void Disable(Renderer* renderer) noexcept override;
        NODISCARD ConstTexture2DSharedPtr ReadColor(int index, Renderer* renderer) noexcept override;
    };
}

#endif  // RENDERING_RENDERERS_DX9_RENDER_TARGET_H
