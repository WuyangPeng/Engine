///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.3 (2022/10/06 22:26)

#ifndef RENDERING_STATE_GLOBAL_STATE_FACTORY_H
#define RENDERING_STATE_GLOBAL_STATE_FACTORY_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Base/BaseFwd.h"
#include "Rendering/Renderers/RenderersFwd.h"
#include "Rendering/State/StateInternalFwd.h"

#include <memory>
#include <string>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE GlobalStateFactory
    {
    public:
        using ClassType = GlobalStateFactory;
        using GlobalStateSharedPtr = std::shared_ptr<GlobalStateImpl>;
        using RendererObjectBridgeSharedPtr = std::shared_ptr<RendererObjectBridge>;

    public:
        NODISCARD static GlobalStateSharedPtr Create(RendererTypes rendererTypes, const std::string& blendStateName, const std::string& depthStencilStateName, const std::string& rasterizerStateName, const RendererObjectBridgeSharedPtr& rendererObjectBridge);
    };
}

#endif  // RENDERING_STATE_GLOBAL_STATE_FACTORY_H
