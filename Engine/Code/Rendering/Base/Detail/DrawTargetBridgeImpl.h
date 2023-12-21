/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/08 17:40)

#ifndef RENDERING_BASE_DRAW_TARGET_BRIDGE_IMPL_H
#define RENDERING_BASE_DRAW_TARGET_BRIDGE_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Base/BaseFwd.h"
#include "Rendering/RendererEngine/RendererEngineFwd.h"
#include "Rendering/Resources/ResourcesFwd.h"

#include <map>
#include <memory>
#include <vector>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE DrawTargetBridgeImpl
    {
    public:
        using ClassType = DrawTargetBridgeImpl;

        using ConstDrawTargetSharedPtr = std::shared_ptr<const DrawTarget>;
        using RendererDrawTargetSharedPtr = std::shared_ptr<RendererDrawTarget>;
        using ConstRendererDrawTargetSharedPtr = std::shared_ptr<const RendererDrawTarget>;
        using RendererObjectSharedPtr = std::shared_ptr<RendererObject>;
        using RendererObjectContainer = std::vector<RendererObjectSharedPtr>;

    public:
        DrawTargetBridgeImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD RendererDrawTargetSharedPtr BindDrawTarget(RendererTypes rendererTypes, const ConstDrawTargetSharedPtr& drawTarget, const RendererObjectContainer& renderTargetTextures, const RendererObjectSharedPtr& depthStencilTexture);
        void UnbindDrawTarget(const ConstDrawTargetSharedPtr& drawTarget) noexcept;
        NODISCARD RendererDrawTargetSharedPtr GetDrawTarget(const ConstDrawTargetSharedPtr& drawTarget);
        NODISCARD ConstRendererDrawTargetSharedPtr GetDrawTarget(const ConstDrawTargetSharedPtr& drawTarget) const;
        NODISCARD bool HasDrawTarget(const ConstDrawTargetSharedPtr& drawTarget) const;

    private:
        using DrawTargetContainer = std::map<ConstDrawTargetSharedPtr, RendererDrawTargetSharedPtr>;

    private:
        DrawTargetContainer container;
    };
}

#endif  // RENDERING_BASE_DRAW_TARGET_BRIDGE_IMPL_H
