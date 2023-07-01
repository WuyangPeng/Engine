///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:24)

#include "Rendering/RenderingExport.h"

#include "OpenGLRasterizerState.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/OpenGLBase.h"
#include "System/OpenGL/OpenGLPolygon.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Mathematics/Base/MathDetail.h"
#include "Rendering/OpenGLRenderer/Detail/State/OpenGLRasterizerStateImpl.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, OpenGLRasterizerState)

Rendering::OpenGLRasterizerState::OpenGLRasterizerState(const RasterizerStateSharedPtr& rasterizerState, const std::string& name)
    : ParentType{ rasterizerState, name }, impl{ *rasterizerState }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, OpenGLRasterizerState)

void Rendering::OpenGLRasterizerState::Enable() noexcept(gAssert < 3 || gMathematicsAssert < 3)
{
    RENDERING_CLASS_IS_VALID_9;

    System::SetGLPolygonMode(System::RasterizerStateCullFace::FrontAndBack, impl->GetFillMode());

    if (impl->GetCullFace() != System::RasterizerStateCullFace::None)
    {
        System::EnableGLState(System::OpenGLEnable::CullFace);
        System::SetGLFrontFace(impl->GetFrontFace());
        System::SetGLCullFace(impl->GetCullFace());
    }
    else
    {
        System::DisableGLState(System::OpenGLEnable::CullFace);
    }

    if (Mathematics::MathF::Approximate(impl->GetDepthScale(), 0.0f) && Mathematics::MathF::Approximate(impl->GetDepthBias(), 0.0f))
    {
        System::EnableGLState(System::OpenGLEnable::PolygonOffsetFill);
        System::EnableGLState(System::OpenGLEnable::PolygonOffsetLine);
        System::EnableGLState(System::OpenGLEnable::PolygonOffsetPoint);
        System::SetGLPolygonOffset(impl->GetDepthScale(), impl->GetDepthBias());
    }
    else
    {
        System::DisableGLState(System::OpenGLEnable::PolygonOffsetFill);
        System::DisableGLState(System::OpenGLEnable::PolygonOffsetLine);
        System::DisableGLState(System::OpenGLEnable::PolygonOffsetPoint);
    }
}

bool Rendering::OpenGLRasterizerState::Update(MAYBE_UNUSED int level)
{
    CoreTools::DisableNoexcept();

    return false;
}

bool Rendering::OpenGLRasterizerState::Update(MAYBE_UNUSED int item, MAYBE_UNUSED int level)
{
    CoreTools::DisableNoexcept();

    return false;
}

bool Rendering::OpenGLRasterizerState::CopyGpuToCpu()
{
    CoreTools::DisableNoexcept();

    return false;
}

bool Rendering::OpenGLRasterizerState::CopyGpuToCpu(MAYBE_UNUSED int level)
{
    CoreTools::DisableNoexcept();

    return false;
}

bool Rendering::OpenGLRasterizerState::CopyGpuToCpu(MAYBE_UNUSED int item, MAYBE_UNUSED int level)
{
    CoreTools::DisableNoexcept();

    return false;
}

bool Rendering::OpenGLRasterizerState::CopyCpuToGpu()
{
    CoreTools::DisableNoexcept();

    return false;
}

bool Rendering::OpenGLRasterizerState::CopyCpuToGpu(MAYBE_UNUSED int level)
{
    CoreTools::DisableNoexcept();

    return false;
}

bool Rendering::OpenGLRasterizerState::CopyCpuToGpu(MAYBE_UNUSED int item, MAYBE_UNUSED int level)
{
    CoreTools::DisableNoexcept();

    return false;
}

bool Rendering::OpenGLRasterizerState::GetNumActiveElements()
{
    CoreTools::DisableNoexcept();

    return false;
}
