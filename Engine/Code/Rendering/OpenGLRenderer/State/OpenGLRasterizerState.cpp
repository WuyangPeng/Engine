/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/06 16:09)

#include "Rendering/RenderingExport.h"

#include "OpenGLRasterizerState.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/OpenGLBase.h"
#include "System/OpenGL/OpenGLPolygon.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
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

    SetGLPolygonMode(System::RasterizerStateCullFace::FrontAndBack, impl->GetFillMode());

    if (impl->GetCullFace() != System::RasterizerStateCullFace::None)
    {
        EnableGLState(System::OpenGLEnable::CullFace);
        SetGLFrontFace(impl->GetFrontFace());
        SetGLCullFace(impl->GetCullFace());
    }
    else
    {
        DisableGLState(System::OpenGLEnable::CullFace);
    }

    if (Mathematics::MathF::Approximate(impl->GetDepthScale(), 0.0f) && Mathematics::MathF::Approximate(impl->GetDepthBias(), 0.0f))
    {
        EnableGLState(System::OpenGLEnable::PolygonOffsetFill);
        EnableGLState(System::OpenGLEnable::PolygonOffsetLine);
        EnableGLState(System::OpenGLEnable::PolygonOffsetPoint);
        System::SetGLPolygonOffset(impl->GetDepthScale(), impl->GetDepthBias());
    }
    else
    {
        DisableGLState(System::OpenGLEnable::PolygonOffsetFill);
        DisableGLState(System::OpenGLEnable::PolygonOffsetLine);
        DisableGLState(System::OpenGLEnable::PolygonOffsetPoint);
    }
}
 