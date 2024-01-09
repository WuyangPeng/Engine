/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/26 11:22)

#include "Rendering/RenderingExport.h"

#include "GlobalStateFactory.h"
#include "GlobalStateImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/OpenGLRenderer/Detail/State/OpenGLGlobalState.h"
#include "Rendering/RendererEngine/Flags/RendererTypes.h"

Rendering::GlobalStateFactory::GlobalStateSharedPtr Rendering::GlobalStateFactory::Create(RendererTypes rendererTypes, const std::string& blendStateName, const std::string& depthStencilStateName, const std::string& rasterizerStateName, const RendererObjectBridgeSharedPtr& rendererObjectBridge)
{
    switch (rendererTypes)
    {
        case RendererTypes::OpenGL:
            return std::make_shared<OpenGLGlobalState>(blendStateName, depthStencilStateName, rasterizerStateName, rendererObjectBridge);
        default:
            return std::make_shared<GlobalStateImpl>(blendStateName, depthStencilStateName, rasterizerStateName, rendererObjectBridge);
    }
}
