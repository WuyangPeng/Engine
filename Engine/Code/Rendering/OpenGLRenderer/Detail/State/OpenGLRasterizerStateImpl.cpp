/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/06 16:09)

#include "Rendering/RenderingExport.h"

#include "OpenGLRasterizerStateImpl.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/State/Flags/RasterizerStateCull.h"
#include "Rendering/State/Flags/RasterizerStateFill.h"
#include "Rendering/State/RasterizerState.h"

#include <array>

Rendering::OpenGLRasterizerStateImpl::OpenGLRasterizerStateImpl() noexcept
    : fillMode{ RasterizerStateFillMode::Fill },
      cullFace{ RasterizerStateCullFace::None },
      frontFace{ OpenGLFrontFace::CCW },
      depthScale{ 0.0f },
      depthBias{ 0.0f },
      enableScissor{ false }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::OpenGLRasterizerStateImpl::OpenGLRasterizerStateImpl(const RasterizerState& rasterizerState)
    : fillMode{ GetRasterizerStateFillMode(rasterizerState.GetFill()) },
      cullFace{ GetRasterizerStateCullFace(rasterizerState.GetCull()) },
      frontFace{ rasterizerState.IsFrontCcw() ? OpenGLFrontFace::CCW : OpenGLFrontFace::CW },
      depthScale{ rasterizerState.GetSlopeScaledDepthBias() },
      depthBias{ static_cast<float>(rasterizerState.GetDepthBias()) },
      enableScissor{ rasterizerState.IsEnableScissor() }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, OpenGLRasterizerStateImpl)

System::RasterizerStateFillMode Rendering::OpenGLRasterizerStateImpl::GetRasterizerStateFillMode(RasterizerStateFill rasterizerStateFill)
{
    using Container = std::array<System::RasterizerStateFillMode, System::EnumCastUnderlying(RasterizerStateFill::Count)>;
    static Container container{ System::RasterizerStateFillMode::Fill,
                                System::RasterizerStateFillMode::Line };

    return container.at(System::EnumCastUnderlying(rasterizerStateFill));
}

System::RasterizerStateCullFace Rendering::OpenGLRasterizerStateImpl::GetRasterizerStateCullFace(RasterizerStateCull rasterizerStateCull)
{
    using Container = std::array<System::RasterizerStateCullFace, System::EnumCastUnderlying(RasterizerStateCull::Count)>;
    static Container container{ System::RasterizerStateCullFace::None,
                                System::RasterizerStateCullFace::Front,
                                System::RasterizerStateCullFace::Back };

    return container.at(System::EnumCastUnderlying(rasterizerStateCull));
}

System::RasterizerStateFillMode Rendering::OpenGLRasterizerStateImpl::GetFillMode() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return fillMode;
}

System::RasterizerStateCullFace Rendering::OpenGLRasterizerStateImpl::GetCullFace() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return cullFace;
}

System::OpenGLFrontFace Rendering::OpenGLRasterizerStateImpl::GetFrontFace() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return frontFace;
}

float Rendering::OpenGLRasterizerStateImpl::GetDepthScale() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return depthScale;
}

float Rendering::OpenGLRasterizerStateImpl::GetDepthBias() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return depthBias;
}

bool Rendering::OpenGLRasterizerStateImpl::IsEnableScissor() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return enableScissor;
}
