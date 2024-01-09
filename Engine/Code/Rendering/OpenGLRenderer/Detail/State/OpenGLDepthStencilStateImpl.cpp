/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/06 15:55)

#include "Rendering/RenderingExport.h"

#include "OpenGLDepthStencilStateImpl.h"
#include "System/Helper/EnumCast.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/State/DepthStencilState.h"
#include "Rendering/State/Flags/DepthStencilStateComparison.h"
#include "Rendering/State/Flags/DepthStencilStateOperation.h"

#include <array>

Rendering::OpenGLDepthStencilStateImpl::OpenGLDepthStencilStateImpl() noexcept
    : depthEnable{ false },
      writeMask{ System::DepthStencilStateWriteMask::False },
      comparison{ StateMode::Never },
      stencilEnable{ false },
      stencilReadMask{ 0 },
      stencilWriteMask{ 0 },
      frontFace{},
      backFace{},
      reference{ 0 }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::OpenGLDepthStencilStateImpl::OpenGLDepthStencilStateImpl(const DepthStencilState& depthStencilState)
    : depthEnable{ depthStencilState.IsDepthEnable() },
      writeMask{ GetDepthStencilStateWriteMask(depthStencilState.GetWriteMask()) },
      comparison{ GetDepthStencilStateMode(depthStencilState.GetComparison()) },
      stencilEnable{ depthStencilState.IsStencilEnable() },
      stencilReadMask{ depthStencilState.GetStencilReadMask() },
      stencilWriteMask{ depthStencilState.GetStencilWriteMask() },
      frontFace{},
      backFace{},
      reference{ depthStencilState.GetReference() }
{
    const auto front = depthStencilState.GetFrontFace();
    frontFace.SetOnFail(GetDepthStencilStateOperation(front.GetFail()));
    frontFace.SetOnZFail(GetDepthStencilStateOperation(front.GetDepthFail()));
    frontFace.SetOnZPass(GetDepthStencilStateOperation(front.GetPass()));
    frontFace.SetComparison(GetDepthStencilStateMode(front.GetComparison()));

    const auto back = depthStencilState.GetBackFace();
    backFace.SetOnFail(GetDepthStencilStateOperation(back.GetFail()));
    backFace.SetOnZFail(GetDepthStencilStateOperation(back.GetDepthFail()));
    backFace.SetOnZPass(GetDepthStencilStateOperation(back.GetPass()));
    backFace.SetComparison(GetDepthStencilStateMode(back.GetComparison()));

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, OpenGLDepthStencilStateImpl)

System::DepthStencilStateMode Rendering::OpenGLDepthStencilStateImpl::GetDepthStencilStateMode(DepthStencilStateComparison depthStencilStateComparison)
{
    using Container = std::array<System::DepthStencilStateMode, System::EnumCastUnderlying(DepthStencilStateComparison::Count)>;
    static Container container{ System::DepthStencilStateMode::Never,
                                System::DepthStencilStateMode::Less,
                                System::DepthStencilStateMode::Equal,
                                System::DepthStencilStateMode::LessEqual,
                                System::DepthStencilStateMode::Greater,
                                System::DepthStencilStateMode::NotEqual,
                                System::DepthStencilStateMode::GreaterEqual,
                                System::DepthStencilStateMode::Always };

    return container.at(System::EnumCastUnderlying(depthStencilStateComparison));
}

System::DepthStencilStateOperation Rendering::OpenGLDepthStencilStateImpl::GetDepthStencilStateOperation(DepthStencilStateOperation depthStencilStateOperation)
{
    using Container = std::array<System::DepthStencilStateOperation, System::EnumCastUnderlying(DepthStencilStateOperation::Count)>;
    static Container container{ System::DepthStencilStateOperation::Keep,
                                System::DepthStencilStateOperation::Zero,
                                System::DepthStencilStateOperation::Replace,
                                System::DepthStencilStateOperation::Increment,
                                System::DepthStencilStateOperation::Decrement,
                                System::DepthStencilStateOperation::Invert,
                                System::DepthStencilStateOperation::Increment,
                                System::DepthStencilStateOperation::Decrement };

    return container.at(System::EnumCastUnderlying(depthStencilStateOperation));
}

System::DepthStencilStateWriteMask Rendering::OpenGLDepthStencilStateImpl::GetDepthStencilStateWriteMask(DepthStencilStateWriteMask depthStencilStateWriteMask)
{
    using Container = std::array<System::DepthStencilStateWriteMask, System::EnumCastUnderlying(DepthStencilStateComparison::Count)>;
    static Container container{ System::DepthStencilStateWriteMask::False,
                                System::DepthStencilStateWriteMask::True };

    return container.at(System::EnumCastUnderlying(depthStencilStateWriteMask));
}

bool Rendering::OpenGLDepthStencilStateImpl::IsDepthEnable() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return depthEnable;
}

void Rendering::OpenGLDepthStencilStateImpl::SetDepthEnable(bool aDepthEnable) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    depthEnable = aDepthEnable;
}

System::DepthStencilStateWriteMask Rendering::OpenGLDepthStencilStateImpl::GetWriteMask() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return writeMask;
}

void Rendering::OpenGLDepthStencilStateImpl::SetWriteMask(StateWriteMask aWriteMask) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    writeMask = aWriteMask;
}

Rendering::OpenGLDepthStencilStateImpl::StateMode Rendering::OpenGLDepthStencilStateImpl::GetComparison() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return comparison;
}

void Rendering::OpenGLDepthStencilStateImpl::SetComparison(StateMode aComparison) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    comparison = aComparison;
}

bool Rendering::OpenGLDepthStencilStateImpl::IsStencilEnable() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return stencilEnable;
}

void Rendering::OpenGLDepthStencilStateImpl::SetStencilEnable(bool aStencilEnable) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    stencilEnable = aStencilEnable;
}

Rendering::OpenGLDepthStencilStateImpl::OpenGLInt Rendering::OpenGLDepthStencilStateImpl::GetStencilReadMask() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return stencilReadMask;
}

void Rendering::OpenGLDepthStencilStateImpl::SetStencilReadMask(OpenGLInt aStencilReadMask) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    stencilReadMask = aStencilReadMask;
}

Rendering::OpenGLDepthStencilStateImpl::OpenGLInt Rendering::OpenGLDepthStencilStateImpl::GetStencilWriteMask() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return stencilWriteMask;
}

void Rendering::OpenGLDepthStencilStateImpl::SetStencilWriteMask(OpenGLInt aStencilWriteMask) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    stencilWriteMask = aStencilWriteMask;
}

Rendering::OpenGLDepthStencilStateImpl::OpenGLInt Rendering::OpenGLDepthStencilStateImpl::GetReference() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return reference;
}

void Rendering::OpenGLDepthStencilStateImpl::SetReference(OpenGLInt aReference) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    reference = aReference;
}

System::DepthStencilStateOperation Rendering::OpenGLDepthStencilStateImpl::GetFrontOnFail() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return frontFace.GetOnFail();
}

void Rendering::OpenGLDepthStencilStateImpl::SetFrontOnFail(StateOperation onFail) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return frontFace.SetOnFail(onFail);
}

System::DepthStencilStateOperation Rendering::OpenGLDepthStencilStateImpl::GetFrontOnZFail() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return frontFace.GetOnZFail();
}

void Rendering::OpenGLDepthStencilStateImpl::SetFrontOnZFail(StateOperation onZFail) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return frontFace.SetOnZFail(onZFail);
}

System::DepthStencilStateOperation Rendering::OpenGLDepthStencilStateImpl::GetFrontOnZPass() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return frontFace.GetOnZPass();
}

void Rendering::OpenGLDepthStencilStateImpl::SetFrontOnZPass(StateOperation onZPass) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return frontFace.SetOnZPass(onZPass);
}

System::DepthStencilStateMode Rendering::OpenGLDepthStencilStateImpl::GetFrontComparison() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return frontFace.GetComparison();
}

void Rendering::OpenGLDepthStencilStateImpl::SetFrontComparison(StateMode aComparison) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return frontFace.SetComparison(aComparison);
}

System::DepthStencilStateOperation Rendering::OpenGLDepthStencilStateImpl::GetBackOnFail() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return backFace.GetOnFail();
}

void Rendering::OpenGLDepthStencilStateImpl::SetBackOnFail(StateOperation onFail) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return backFace.SetOnFail(onFail);
}

System::DepthStencilStateOperation Rendering::OpenGLDepthStencilStateImpl::GetBackOnZFail() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return backFace.GetOnZFail();
}

void Rendering::OpenGLDepthStencilStateImpl::SetBackOnZFail(StateOperation onZFail) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return backFace.SetOnZFail(onZFail);
}

System::DepthStencilStateOperation Rendering::OpenGLDepthStencilStateImpl::GetBackOnZPass() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return backFace.GetOnZPass();
}

void Rendering::OpenGLDepthStencilStateImpl::SetBackOnZPass(StateOperation onZPass) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return backFace.SetOnZPass(onZPass);
}

System::DepthStencilStateMode Rendering::OpenGLDepthStencilStateImpl::GetBackComparison() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return backFace.GetComparison();
}

void Rendering::OpenGLDepthStencilStateImpl::SetBackComparison(StateMode aComparison) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return backFace.SetComparison(aComparison);
}
