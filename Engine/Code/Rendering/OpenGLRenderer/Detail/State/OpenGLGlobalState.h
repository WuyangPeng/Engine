///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.3 (2022/10/08 22:25)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_GLOBAL_STATE_H
#define RENDERING_OPENGL_RENDERER_OPENGL_GLOBAL_STATE_H

#include "Rendering/RenderingDll.h"

#include "Rendering/State/Detail/GlobalStateImpl.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE OpenGLGlobalState : public GlobalStateImpl
    {
    public:
        using ClassType = OpenGLGlobalState;
        using ParentType = GlobalStateImpl;

    public:
        OpenGLGlobalState(const std::string& blendStateName, const std::string& depthStencilStateName, const std::string& rasterizerStateName, const RendererObjectBridgeSharedPtr& rendererObjectBridge);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    public:
        void SetActiveBlendState(const BlendStateSharedPtr& state) override;
        void SetActiveDepthStencilState(const DepthStencilStateSharedPtr& state) override;
        void SetActiveRasterizerState(const RasterizerStateSharedPtr& state) override;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_OPENGL_GLOBAL_STATE_H
