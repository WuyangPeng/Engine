///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/28 09:49)

#ifndef RENDERING_BASE_DRAW_TARGET_BRIDGE_H
#define RENDERING_BASE_DRAW_TARGET_BRIDGE_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "Rendering/Base/BaseFwd.h"
#include "Rendering/RendererEngine/RendererEngineFwd.h"
#include "Rendering/Resources/Textures/DrawTarget.h"

#include <map>
#include <memory>

RENDERING_DELAY_COPY_UNSHARED_EXPORT_IMPL(DrawTargetBridge, DrawTargetBridgeImpl);
template class RENDERING_DEFAULT_DECLARE std::weak_ptr<Rendering::DrawTargetBridge>;
template class RENDERING_DEFAULT_DECLARE std::enable_shared_from_this<Rendering::DrawTargetBridge>;

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE DrawTargetBridge : public std::enable_shared_from_this<DrawTargetBridge>
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(DrawTargetBridge);

        using DrawTargetBridgeSharedPtr = std::shared_ptr<ClassType>;

        using ConstDrawTargetSharedPtr = std::shared_ptr<const DrawTarget>;
        using RendererDrawTargetSharedPtr = std::shared_ptr<RendererDrawTarget>;
        using ConstRendererDrawTargetSharedPtr = std::shared_ptr<const RendererDrawTarget>;
        using RendererObjectSharedPtr = std::shared_ptr<RendererObject>;
        using RendererObjectContainer = std::vector<RendererObjectSharedPtr>;

    public:
        NODISCARD static DrawTargetBridgeSharedPtr Create();

        CLASS_INVARIANT_DECLARE;

        NODISCARD RendererDrawTargetSharedPtr BindDrawTarget(RendererTypes rendererTypes, const ConstDrawTargetSharedPtr& drawTarget, const RendererObjectContainer& renderTargetTextures, const RendererObjectSharedPtr& depthStencilTexture);
        void UnbindDrawTarget(const ConstDrawTargetSharedPtr& drawTarget);
        NODISCARD RendererDrawTargetSharedPtr GetDrawTarget(const ConstDrawTargetSharedPtr& drawTarget);
        NODISCARD ConstRendererDrawTargetSharedPtr GetDrawTarget(const ConstDrawTargetSharedPtr& drawTarget) const;
        NODISCARD bool HasDrawTarget(const ConstDrawTargetSharedPtr& drawTarget) const;

    private:
        enum class DrawTargetBridgeCreate
        {
            Init,
        };

    public:
        explicit DrawTargetBridge(DrawTargetBridgeCreate drawTargetBridgeCreate);

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_BASE_DRAW_TARGET_BRIDGE_H
