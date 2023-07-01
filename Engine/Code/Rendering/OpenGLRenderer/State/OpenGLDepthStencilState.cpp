///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:24)

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
        System::EnableGLState(System::OpenGLEnable::DepthTest);

        System::SetGLDepthFunc(impl->GetComparison());
    }
    else
    {
        System::DisableGLState(System::OpenGLEnable::DepthTest);
    }

    System::SetGLDepthMask(impl->GetWriteMask());

    if (impl->IsStencilEnable())
    {
        System::EnableGLState(System::OpenGLEnable::StencilTest);

        System::SetGLStencilFuncSeparate(System::RasterizerStateCullFace::Front, impl->GetFrontComparison(), impl->GetReference(), impl->GetStencilReadMask());
        System::SetGLStencilMaskSeparate(System::RasterizerStateCullFace::Front, impl->GetStencilWriteMask());
        System::SetGLStencilOpSeparate(System::RasterizerStateCullFace::Front, impl->GetFrontOnFail(), impl->GetFrontOnZFail(), impl->GetFrontOnZPass());

        System::SetGLStencilFuncSeparate(System::RasterizerStateCullFace::Back, impl->GetBackComparison(), impl->GetReference(), impl->GetStencilReadMask());
        System::SetGLStencilMaskSeparate(System::RasterizerStateCullFace::Back, impl->GetStencilWriteMask());
        System::SetGLStencilOpSeparate(System::RasterizerStateCullFace::Back, impl->GetBackOnFail(), impl->GetBackOnZFail(), impl->GetBackOnZPass());
    }
    else
    {
        System::DisableGLState(System::OpenGLEnable::StencilTest);
    }
}

bool Rendering::OpenGLDepthStencilState::Update(MAYBE_UNUSED int level)
{
    CoreTools::DisableNoexcept();

    return false;
}

bool Rendering::OpenGLDepthStencilState::Update(MAYBE_UNUSED int item, MAYBE_UNUSED int level)
{
    CoreTools::DisableNoexcept();

    return false;
}

bool Rendering::OpenGLDepthStencilState::CopyGpuToCpu()
{
    CoreTools::DisableNoexcept();

    return false;
}

bool Rendering::OpenGLDepthStencilState::CopyGpuToCpu(MAYBE_UNUSED int level)
{
    CoreTools::DisableNoexcept();

    return false;
}

bool Rendering::OpenGLDepthStencilState::CopyGpuToCpu(MAYBE_UNUSED int item, MAYBE_UNUSED int level)
{
    CoreTools::DisableNoexcept();

    return false;
}

bool Rendering::OpenGLDepthStencilState::CopyCpuToGpu()
{
    CoreTools::DisableNoexcept();

    return false;
}

bool Rendering::OpenGLDepthStencilState::CopyCpuToGpu(MAYBE_UNUSED int level)
{
    CoreTools::DisableNoexcept();

    return false;
}

bool Rendering::OpenGLDepthStencilState::CopyCpuToGpu(MAYBE_UNUSED int item, MAYBE_UNUSED int level)
{
    CoreTools::DisableNoexcept();

    return false;
}

bool Rendering::OpenGLDepthStencilState::GetNumActiveElements()
{
    CoreTools::DisableNoexcept();

    return false;
}
