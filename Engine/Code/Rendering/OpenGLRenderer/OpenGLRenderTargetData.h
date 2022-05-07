///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/22 21:30)

#ifndef RENDERING_RENDERERS_OPENGL_RENDER_TARGET_DATA_H
#define RENDERING_RENDERERS_OPENGL_RENDER_TARGET_DATA_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "Rendering/DataTypes/Flags/TextureFormat.h"
#include "Rendering/Renderers/RenderersFwd.h"
#include "Rendering/Resources/ResourcesFwd.h"
#include "Rendering/Resources/Texture2D.h"

RENDERING_NON_COPY_EXPORT_IMPL(OpenGLRenderTargetDataImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE OpenGLRenderTargetData
    {
    public:
        NON_COPY_TYPE_DECLARE(OpenGLRenderTargetData);

    public:
        OpenGLRenderTargetData(Renderer* renderer, const RenderTarget* renderTarget);

        CLASS_INVARIANT_DECLARE;

        // 渲染目标的操作。
        void Enable(Renderer* renderer) noexcept;
        void Disable(Renderer* renderer) noexcept;
        NODISCARD ConstTexture2DSharedPtr ReadColor(int index, Renderer* renderer);

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_RENDERERS_OPENGL_RENDER_TARGET_DATA_H
