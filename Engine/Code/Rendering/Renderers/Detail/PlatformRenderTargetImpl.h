// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎版本：0.0.0.3 (2019/07/26 14:18)

#ifndef RENDERING_RENDERERS_PLATFORM_RENDER_TARGET_IMPL_H
#define RENDERING_RENDERERS_PLATFORM_RENDER_TARGET_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Resources/Flags/BufferFlags.h"
#include "Rendering/Resources/Texture2D.h"

namespace Rendering
{
    class Renderer;
    class RenderTarget;
    class Texture2D;

    class RENDERING_HIDDEN_DECLARE PlatformRenderTargetImpl
    {
    public:
        using ClassType = PlatformRenderTargetImpl;
        using PlatformRenderTargetPtr = std::shared_ptr<ClassType>;

    public:
        PlatformRenderTargetImpl() noexcept;
        virtual ~PlatformRenderTargetImpl();
        PlatformRenderTargetImpl(const PlatformRenderTargetImpl&) = default;
        PlatformRenderTargetImpl& operator=(const PlatformRenderTargetImpl&) = default;
        PlatformRenderTargetImpl(PlatformRenderTargetImpl&&) = default;
        PlatformRenderTargetImpl& operator=(PlatformRenderTargetImpl&&) = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        // 渲染目标的操作。
        virtual void Enable(Renderer* renderer) = 0;
        virtual void Disable(Renderer* renderer) = 0;
        virtual ConstTexture2DSharedPtr ReadColor(int index, Renderer* renderer) = 0;

        static PlatformRenderTargetPtr Create(Renderer* renderer, const RenderTarget* renderTarget);

    private:
        static PlatformRenderTargetPtr CreateDefault(Renderer* renderer, const RenderTarget* renderTarget);
    };
}

#endif  // RENDERING_RENDERERS_PLATFORM_RENDER_TARGET_IMPL_H
