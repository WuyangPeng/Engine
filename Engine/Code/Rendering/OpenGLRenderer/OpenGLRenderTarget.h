///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/22 21:28)

#ifndef RENDERING_RENDERERS_OPENGL_RENDER_TARGET_H
#define RENDERING_RENDERERS_OPENGL_RENDER_TARGET_H

#include "Rendering/RenderingDll.h"

#include "OpenGLRenderTargetData.h"
#include "Rendering/Renderers/Detail/PlatformRenderTargetImpl.h"
#include "Rendering/Renderers/RenderersFwd.h"
#include "Rendering/Resources/ResourcesFwd.h"

namespace Rendering
{
    class OpenGLRenderTarget : public PlatformRenderTargetImpl
    {
    public:
        using ClassType = OpenGLRenderTarget;
        using ParentType = PlatformRenderTargetImpl;

    public:
        OpenGLRenderTarget(Renderer* renderer, const DrawTarget* renderTarget);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void Enable(Renderer* renderer) noexcept override;
        void Disable(Renderer* renderer) noexcept override;
        NODISCARD ConstTexture2DSharedPtr ReadColor(int index, Renderer* renderer) override;

    private:
        OpenGLRenderTargetData openGLRenderTargetData;
    };
}

#endif  // RENDERING_RENDERERS_OPENGL_RENDER_TARGET_H
