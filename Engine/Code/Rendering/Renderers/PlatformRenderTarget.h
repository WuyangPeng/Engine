// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎版本：0.0.0.3 (2019/07/26 15:31)

#ifndef RENDERING_RENDERERS_PLATFORM_RENDER_TARGET_H
#define RENDERING_RENDERERS_PLATFORM_RENDER_TARGET_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Resources/Flags/BufferFlags.h"
#include "Rendering/Resources/Texture2D.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include <boost/noncopyable.hpp>

RENDERING_NON_COPY_EXPORT_IMPL(PlatformRenderTargetImpl);

namespace Rendering
{
    class Renderer;
    class RenderTarget;
    class Texture2D;

    class RENDERING_DEFAULT_DECLARE PlatformRenderTarget
    {
    public:
        NON_COPY_TYPE_DECLARE(PlatformRenderTarget);

    public:
        PlatformRenderTarget(Renderer* renderer, const RenderTarget* renderTarget);
        ~PlatformRenderTarget() noexcept = default;
        PlatformRenderTarget(const PlatformRenderTarget& rhs) noexcept = delete;
        PlatformRenderTarget& operator=(const PlatformRenderTarget& rhs) noexcept = delete;
        PlatformRenderTarget(PlatformRenderTarget&& rhs) noexcept = delete;
        PlatformRenderTarget& operator=(PlatformRenderTarget&& rhs) noexcept = delete;
        CLASS_INVARIANT_DECLARE;

        // 渲染目标的操作。
        void Enable(Renderer* renderer);
        void Disable(Renderer* renderer);
        ConstTexture2DSharedPtr ReadColor(int index, Renderer* renderer);

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_RENDERERS_PLATFORM_RENDER_TARGET_H
