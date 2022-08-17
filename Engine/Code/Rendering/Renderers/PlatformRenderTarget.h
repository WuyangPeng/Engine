///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/21 18:55)

#ifndef RENDERING_RENDERERS_PLATFORM_RENDER_TARGET_H
#define RENDERING_RENDERERS_PLATFORM_RENDER_TARGET_H

#include "Rendering/RenderingDll.h"

#include "RenderersFwd.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "Rendering/Resources/Flags/BufferFlags.h"
#include "Rendering/Resources/ResourcesFwd.h"
#include "Rendering/Resources/Textures/Texture2D.h"

RENDERING_NON_COPY_EXPORT_IMPL(PlatformRenderTargetImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE PlatformRenderTarget
    {
    public:
        NON_COPY_TYPE_DECLARE(PlatformRenderTarget);

    public:
        PlatformRenderTarget(Renderer* renderer, const DrawTarget* renderTarget);

        CLASS_INVARIANT_DECLARE;

        // 渲染目标的操作。
        void Enable(Renderer* renderer);
        void Disable(Renderer* renderer);
        NODISCARD ConstTexture2DSharedPtr ReadColor(int index, Renderer* renderer);

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_RENDERERS_PLATFORM_RENDER_TARGET_H
