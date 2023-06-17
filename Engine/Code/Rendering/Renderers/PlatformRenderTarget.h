///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 11:36)

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

        // ��ȾĿ��Ĳ�����
        void Enable(Renderer* renderer);
        void Disable(Renderer* renderer);
        NODISCARD ConstTexture2DSharedPtr ReadColor(int index, Renderer* renderer);

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_RENDERERS_PLATFORM_RENDER_TARGET_H
