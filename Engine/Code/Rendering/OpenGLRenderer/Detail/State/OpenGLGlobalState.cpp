///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.3 (2022/10/06 21:36)

#include "Rendering/RenderingExport.h"

#include "OpenGLGlobalState.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/Base/RendererObject.h"
#include "Rendering/Renderers/Flags/RendererTypes.h"
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
        THROW_EXCEPTION(SYSTEM_TEXT("stateָ��Ϊ�ա�"s));
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
        THROW_EXCEPTION(SYSTEM_TEXT("stateָ��Ϊ�ա�"s));
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
        THROW_EXCEPTION(SYSTEM_TEXT("stateָ��Ϊ�ա�"s));
    }

    if (state != GetActiveRasterizerState())
    {
        auto gl4State = BindRendererObject(RendererTypes::OpenGL, state);

        gl4State->Enable();
        ParentType::SetActiveRasterizerState(state);
    }
}
