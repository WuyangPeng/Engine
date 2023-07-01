///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/29 11:06)

#ifndef RENDERING_STATE_GLOBAL_STATE_IMPL_H
#define RENDERING_STATE_GLOBAL_STATE_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Base/BaseFwd.h"
#include "Rendering/RendererEngine/RendererEngineFwd.h"
#include "Rendering/State/StateInternalFwd.h"

#include <memory>
#include <string>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE GlobalStateImpl
    {
    public:
        using ClassType = GlobalStateImpl;
        using FactoryType = GlobalStateFactory;

        using BlendStateSharedPtr = std::shared_ptr<BlendState>;
        using DepthStencilStateSharedPtr = std::shared_ptr<DepthStencilState>;
        using RasterizerStateSharedPtr = std::shared_ptr<RasterizerState>;

        using RendererObjectBridgeSharedPtr = std::shared_ptr<RendererObjectBridge>;
        using RendererObjectBridgeWeakPtr = std::weak_ptr<RendererObjectBridge>;
        using GraphicsObjectSharedPtr = std::shared_ptr<GraphicsObject>;
        using RendererObjectSharedPtr = std::shared_ptr<RendererObject>;
        using ConstRendererObjectSharedPtr = std::shared_ptr<const RendererObject>;

    public:
        GlobalStateImpl(const std::string& blendStateName, const std::string& depthStencilStateName, const std::string& rasterizerStateName, const RendererObjectBridgeSharedPtr& rendererObjectBridge);
        virtual ~GlobalStateImpl() noexcept = default;
        GlobalStateImpl(const GlobalStateImpl& rhs) noexcept = default;
        GlobalStateImpl& operator=(const GlobalStateImpl& rhs) noexcept = default;
        GlobalStateImpl(GlobalStateImpl&& rhs) noexcept = default;
        GlobalStateImpl& operator=(GlobalStateImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

    public:
        void CreateDefaultGlobalState();
        void DestroyDefaultGlobalState();

        virtual void SetActiveBlendState(const BlendStateSharedPtr& state);
        virtual void SetActiveDepthStencilState(const DepthStencilStateSharedPtr& state);
        virtual void SetActiveRasterizerState(const RasterizerStateSharedPtr& state);

        NODISCARD BlendStateSharedPtr GetActiveBlendState() noexcept;
        NODISCARD DepthStencilStateSharedPtr GetActiveDepthStencilState() noexcept;
        NODISCARD RasterizerStateSharedPtr GetActiveRasterizerState() noexcept;

        NODISCARD BlendStateSharedPtr GetDefaultBlendState() noexcept;
        NODISCARD DepthStencilStateSharedPtr GetDefaultDepthStencilState() noexcept;
        NODISCARD RasterizerStateSharedPtr GetDefaultRasterizerState() noexcept;

        void SetDefaultBlendState();
        void SetDefaultDepthStencilState();
        void SetDefaultRasterizerState();

    protected:
        NODISCARD RendererObjectSharedPtr BindRendererObject(RendererTypes rendererTypes, const GraphicsObjectSharedPtr& graphicsObject);
        void UnbindRendererObject(const GraphicsObjectSharedPtr& graphicsObject);
        NODISCARD RendererObjectSharedPtr GetRendererObject(const GraphicsObjectSharedPtr& graphicsObject);
        NODISCARD ConstRendererObjectSharedPtr GetRendererObject(const GraphicsObjectSharedPtr& graphicsObject) const;

    private:
        NODISCARD RendererObjectBridgeSharedPtr GetRendererObjectBridge();

    private:
        BlendStateSharedPtr defaultBlendState;
        BlendStateSharedPtr activeBlendState;
        DepthStencilStateSharedPtr defaultDepthStencilState;
        DepthStencilStateSharedPtr activeDepthStencilState;
        RasterizerStateSharedPtr defaultRasterizerState;
        RasterizerStateSharedPtr activeRasterizerState;
        RendererObjectBridgeWeakPtr rendererObjectBridge;
    };
}

#endif  // RENDERING_STATE_GLOBAL_STATE_IMPL_H
