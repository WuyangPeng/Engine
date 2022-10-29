///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.3 (2022/10/06 22:38)

#ifndef RENDERING_STATE_GLOBAL_STATE_H
#define RENDERING_STATE_GLOBAL_STATE_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/Base/BaseFwd.h"
#include "Rendering/Renderers/RenderersFwd.h"
#include "Rendering/State/StateInternalFwd.h"

#include <memory>
#include <string>

RENDERING_COPY_UNSHARED_EXPORT_IMPL(GlobalState, GlobalStateImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE GlobalState
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(GlobalState);
        using BlendStateSharedPtr = std::shared_ptr<BlendState>;
        using DepthStencilStateSharedPtr = std::shared_ptr<DepthStencilState>;
        using RasterizerStateSharedPtr = std::shared_ptr<RasterizerState>;
        using RendererObjectBridgeSharedPtr = std::shared_ptr<RendererObjectBridge>;

    public:
        GlobalState(RendererTypes rendererTypes, const std::string& blendStateName, const std::string& depthStencilStateName, const std::string& rasterizerStateName, const RendererObjectBridgeSharedPtr& rendererObjectBridge);

        CLASS_INVARIANT_DECLARE;

    public:
        void CreateDefaultGlobalState();
        void DestroyDefaultGlobalState();

        void SetActiveBlendState(const BlendStateSharedPtr& state);
        void SetActiveDepthStencilState(const DepthStencilStateSharedPtr& state);
        void SetActiveRasterizerState(const RasterizerStateSharedPtr& state);

        NODISCARD BlendStateSharedPtr GetActiveBlendState() noexcept;
        NODISCARD DepthStencilStateSharedPtr GetActiveDepthStencilState() noexcept;
        NODISCARD RasterizerStateSharedPtr GetActiveRasterizerState() noexcept;

        NODISCARD BlendStateSharedPtr GetDefaultBlendState() noexcept;
        NODISCARD DepthStencilStateSharedPtr GetDefaultDepthStencilState() noexcept;
        NODISCARD RasterizerStateSharedPtr GetDefaultRasterizerState() noexcept;

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_STATE_GLOBAL_STATE_H
