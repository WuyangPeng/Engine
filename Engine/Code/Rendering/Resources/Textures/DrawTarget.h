/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/29 13:54)

#ifndef RENDERING_RESOURCES_DRAW_TARGET_H
#define RENDERING_RESOURCES_DRAW_TARGET_H

#include "Rendering/RenderingDll.h"

#include "TextureDepthStencil.h"
#include "TextureRenderTarget.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/ObjectSystems/Object.h"
#include "Rendering/Base/RendererDrawTarget.h"
#include "Rendering/Resources/Flags/DataFormatType.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(DrawTarget, DrawTargetImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE DrawTarget : public CoreTools::Object
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(DrawTarget);
        using ParentType = Object;

        using RendererObjectSharedPtr = std::shared_ptr<RendererObject>;
        using RendererObjectContainer = std::vector<RendererObjectSharedPtr>;

    public:
        // 支持目标的数量取决于图形硬件和驱动程序。“numRenderTargets”必须至少1。
        DrawTarget(const std::string& name,
                   int numRenderTargets,
                   DataFormatType renderTargetFormat,
                   int width,
                   int height,
                   bool hasRenderTargetMipMaps = false,
                   bool createRenderTargetStorage = true,
                   DataFormatType depthStencilFormat = DataFormatType::Unknown,
                   bool createDepthStencilStorage = false);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(DrawTarget);
        CORE_TOOLS_NAMES_OVERRIDE_DECLARE;

        NODISCARD int GetNumTargets() const;

        NODISCARD DataFormatType GetRenderTargetFormat() const;
        NODISCARD int GetWidth() const;
        NODISCARD int GetHeight() const;
        NODISCARD bool HasRenderTargetMipMaps() const;
        NODISCARD DataFormatType GetDepthStencilFormat() const noexcept;
        NODISCARD TextureRenderTargetSharedPtr GetRenderTargetTexture(int index);
        NODISCARD TextureDepthStencilSharedPtr GetDepthStencilTexture();
        NODISCARD ConstTextureRenderTargetSharedPtr GetRenderTargetTexture(int index) const;
        NODISCARD ConstTextureDepthStencilSharedPtr GetDepthStencilTexture() const;
        NODISCARD bool HasDepthStencil() const noexcept;

        void AutoGenerateRenderTargetMipMaps();
        NODISCARD bool WantAutoGenerateRenderTargetMipMaps() const;

        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

        NODISCARD RendererDrawTargetSharedPtr CreateRendererDrawTarget(RendererTypes rendererTypes,
                                                                       const RendererObjectContainer& renderTargetTextures,
                                                                       const RendererObjectSharedPtr& depthStencilTexture) const;

    private:
        PackageType impl;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(DrawTarget);

#include SYSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(DrawTarget);
}

#endif  // RENDERING_RESOURCES_DRAW_TARGET_H
