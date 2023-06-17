///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 13:49)

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
        Dx9RenderTarget(Renderer* renderer, const DrawTarget* renderTarget) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void Enable(Renderer* renderer) noexcept override;
        void Disable(Renderer* renderer) noexcept override;
        NODISCARD ConstTexture2DSharedPtr ReadColor(int index, Renderer* renderer) noexcept override;
    };
}

#endif  // RENDERING_RENDERERS_DX9_RENDER_TARGET_H
