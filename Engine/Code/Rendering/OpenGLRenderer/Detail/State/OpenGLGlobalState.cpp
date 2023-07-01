///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:30)

#include "Rendering/RenderingExport.h"

#include "OpenGLGlobalState.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/Base/RendererObject.h"
#include "Rendering/RendererEngine/Flags/RendererTypes.h"
#include "Rendering/State/BlendState.h"
#include "Rendering/State/DepthStencilState.h"
#include "Rendering/State/RasterizerState.h"

Rendering::OpenGLGlobalState::OpenGLGlobalState(const std::string& blendStateName, const std::string& depthStencilStateName, const std::string& rasterizerStateName, const RendererObjectBridgeSharedPtr& rendererObjectBridge)
    : ParentType{ blendStateName, depthStencilStateName, rasterizerStateName, rendererObjectBridge }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, OpenGLGlobalState)

void Rendering::OpenGLGlobalState::SetActiveBlendState(const BlendStateSharedPtr& state)
{
    RENDERING_CLASS_IS_VALID_1;

    if (!state)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("state指针为空。"s));
    }

    if (state != GetActiveBlendState())
    {
        auto gl4State = BindRendererObject(RendererTypes::OpenGL, state);

        gl4State->Enable();
        ParentType::SetActiveBlendState(state);
    }
}

void Rendering::OpenGLGlobalState::SetActiveDepthStencilState(const DepthStencilStateSharedPtr& state)
{
    RENDERING_CLASS_IS_VALID_1;

    if (!state)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("state指针为空。"s));
    }

    if (state != GetActiveDepthStencilState())
    {
        auto gl4State = BindRendererObject(RendererTypes::OpenGL, state);

        gl4State->Enable();
        ParentType::SetActiveDepthStencilState(state);
    }
}

void Rendering::OpenGLGlobalState::SetActiveRasterizerState(const RasterizerStateSharedPtr& state)
{
    RENDERING_CLASS_IS_VALID_1;

    if (!state)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("state指针为空。"s));
    }

    if (state != GetActiveRasterizerState())
    {
        auto gl4State = BindRendererObject(RendererTypes::OpenGL, state);

        gl4State->Enable();
        ParentType::SetActiveRasterizerState(state);
    }
}
