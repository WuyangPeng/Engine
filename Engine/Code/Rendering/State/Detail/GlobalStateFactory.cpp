///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.0 (2023/06/29 11:14)

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
