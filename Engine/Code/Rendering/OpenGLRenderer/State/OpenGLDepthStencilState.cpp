/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2024/01/06 15:57)

#include "Rendering/RenderingExport.h"

#include "OpenGLDepthStencilState.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/OpenGLBase.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Rendering/OpenGLRenderer/Detail/State/OpenGLDepthStencilStateImpl.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, OpenGLDepthStencilState)

Rendering::OpenGLDepthStencilState::OpenGLDepthStencilState(const DepthStencilStateSharedPtr& depthStencilState, const std::string& name)
    : ParentType{ depthStencilState, name }, impl{ *depthStencilState }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, OpenGLDepthStencilState)

void Rendering::OpenGLDepthStencilState::Enable() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    if (impl->IsDepthEnable())
    {
        EnableGLState(System::OpenGLEnable::DepthTest);

        SetGLDepthFunc(impl->GetComparison());
    }
    else
    {
        DisableGLState(System::OpenGLEnable::DepthTest);
    }

    SetGLDepthMask(impl->GetWriteMask());

    if (impl->IsStencilEnable())
    {
        EnableGLState(System::OpenGLEnable::StencilTest);

        SetGLStencilFuncSeparate(System::RasterizerStateCullFace::Front, impl->GetFrontComparison(), impl->GetReference(), impl->GetStencilReadMask());
        SetGLStencilMaskSeparate(System::RasterizerStateCullFace::Front, impl->GetStencilWriteMask());
        SetGLStencilOpSeparate(System::RasterizerStateCullFace::Front, impl->GetFrontOnFail(), impl->GetFrontOnZFail(), impl->GetFrontOnZPass());

        SetGLStencilFuncSeparate(System::RasterizerStateCullFace::Back, impl->GetBackComparison(), impl->GetReference(), impl->GetStencilReadMask());
        SetGLStencilMaskSeparate(System::RasterizerStateCullFace::Back, impl->GetStencilWriteMask());
        SetGLStencilOpSeparate(System::RasterizerStateCullFace::Back, impl->GetBackOnFail(), impl->GetBackOnZFail(), impl->GetBackOnZPass());
    }
    else
    {
        DisableGLState(System::OpenGLEnable::StencilTest);
    }
}
