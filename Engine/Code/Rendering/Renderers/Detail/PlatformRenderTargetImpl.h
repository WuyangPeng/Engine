///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/20 13:39)

#ifndef RENDERING_RENDERERS_PLATFORM_RENDER_TARGET_IMPL_H
#define RENDERING_RENDERERS_PLATFORM_RENDER_TARGET_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Renderers/RenderersFwd.h"
#include "Rendering/Resources/Flags/BufferFlags.h"
#include "Rendering/Resources/ResourcesFwd.h"
#include "Rendering/Resources/Texture2D.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE PlatformRenderTargetImpl
    {
    public:
        using ClassType = PlatformRenderTargetImpl;
        using PlatformRenderTargetSharedPtr = std::shared_ptr<ClassType>;
        using FactoryType = PlatformRenderTargetImpl;

    public:
        PlatformRenderTargetImpl() noexcept;
        virtual ~PlatformRenderTargetImpl() noexcept = default;
        PlatformRenderTargetImpl(const PlatformRenderTargetImpl& rhs) noexcept = default;
        PlatformRenderTargetImpl& operator=(const PlatformRenderTargetImpl& rhs) noexcept = default;
        PlatformRenderTargetImpl(PlatformRenderTargetImpl&& rhs) noexcept = default;
        PlatformRenderTargetImpl& operator=(PlatformRenderTargetImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        // ��ȾĿ��Ĳ�����
        virtual void Enable(Renderer* renderer) = 0;
        virtual void Disable(Renderer* renderer) = 0;
        NODISCARD virtual ConstTexture2DSharedPtr ReadColor(int index, Renderer* renderer) = 0;

        NODISCARD static PlatformRenderTargetSharedPtr Create(Renderer* renderer, const RenderTarget* renderTarget);

    private:
        NODISCARD static PlatformRenderTargetSharedPtr CreateDefault(Renderer* renderer, const RenderTarget* renderTarget);
    };
}

#endif  // RENDERING_RENDERERS_PLATFORM_RENDER_TARGET_IMPL_H
