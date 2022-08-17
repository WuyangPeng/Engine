///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/21 10:24)

#ifndef RENDERING_RENDERERS_RENDER_TARGET_MANAGEMENT_IMPL_H
#define RENDERING_RENDERERS_RENDER_TARGET_MANAGEMENT_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Renderers/RenderersFwd.h"
#include "Rendering/Resources/Textures/DrawTarget.h"
#include "Rendering/Resources/Textures/Texture2D.h"

#include <map>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE RenderTargetManagementImpl
    {
    public:
        using ClassType = RenderTargetManagementImpl;
        using ConstDrawTargetSharedPtr = ConstDrawTargetSharedPtr;
        using PlatformRenderTargetSharedPtr = std::shared_ptr<PlatformRenderTarget>;
        using RendererSharedPtr = std::shared_ptr<Renderer>;

    public:
        explicit RenderTargetManagementImpl(const RendererSharedPtr& renderer);

        CLASS_INVARIANT_DECLARE;

        void Bind(const ConstDrawTargetSharedPtr& renderTarget);
        void Unbind(const ConstDrawTargetSharedPtr& renderTarget);
        void Enable(const ConstDrawTargetSharedPtr& renderTarget);
        void Disable(const ConstDrawTargetSharedPtr& renderTarget);
        NODISCARD ConstTexture2DSharedPtr ReadColor(int index, const ConstDrawTargetSharedPtr& renderTarget);

        NODISCARD PlatformRenderTargetSharedPtr GetResource(const ConstDrawTargetSharedPtr& renderTarget);

    private:
        using RenderTargetMap = std::map<ConstDrawTargetSharedPtr, PlatformRenderTargetSharedPtr>;

    private:
        std::weak_ptr<Renderer> renderer;
        RenderTargetMap renderTargets;
    };
}

#endif  // RENDERING_RENDERERS_RENDER_TARGET_MANAGEMENT_IMPL_H
