///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/22 14:38)

#ifndef RENDERING_RENDERERS_RENDER_TARGET_MANAGEMENT_H
#define RENDERING_RENDERERS_RENDER_TARGET_MANAGEMENT_H

#include "Rendering/RenderingDll.h"

#include "RenderersFwd.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/Resources/RenderTarget.h"
#include "Rendering/Resources/Texture2D.h"

RENDERING_NON_COPY_EXPORT_IMPL(RenderTargetManagementImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE RenderTargetManagement
    {
    public:
        NON_COPY_TYPE_DECLARE(RenderTargetManagement);
        using ConstRenderTargetSharedPtr = std::shared_ptr<const RenderTarget>;
        using PlatformRenderTargetSharedPtr = std::shared_ptr<PlatformRenderTarget>;
        using RendererSharedPtr = std::shared_ptr<Renderer>;

    public:
        explicit RenderTargetManagement(const RendererSharedPtr& renderer);

        CLASS_INVARIANT_DECLARE;

        void Bind(const ConstRenderTargetSharedPtr& renderTarget);
        void Unbind(const ConstRenderTargetSharedPtr& renderTarget);
        void Enable(const ConstRenderTargetSharedPtr& renderTarget);
        void Disable(const ConstRenderTargetSharedPtr& renderTarget);
        NODISCARD ConstTexture2DSharedPtr ReadColor(int index, const ConstRenderTargetSharedPtr& renderTarget);

        NODISCARD PlatformRenderTargetSharedPtr GetResource(const ConstRenderTargetSharedPtr& renderTarget);

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_RENDERERS_RENDER_TARGET_MANAGEMENT_H
