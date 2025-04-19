/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/06 11:33)

#include "Rendering/RenderingExport.h"

#include "OpenGLBlendStateImpl.h"
#include "System/Helper/EnumCast.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/State/Flags/BlendStateColorWrite.h"
#include "Rendering/State/Flags/BlendStateMode.h"
#include "Rendering/State/Flags/BlendStateOperation.h"

#include <array>

using System::operator&;

Rendering::OpenGLBlendStateImpl::OpenGLBlendStateImpl() noexcept
    : enableAlphaToCoverage{ false },
      enableIndependentBlend{ false },
      blendStateTarget{},
      blendColor{ 0.0f, 0.0f, 0.0f, 0.0f },
      sampleMask{ 0xFFFFFFFFu }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::OpenGLBlendStateImpl::OpenGLBlendStateImpl(const BlendState& blendState)
    : enableAlphaToCoverage{ blendState.IsEnableAlphaToCoverage() },
      enableIndependentBlend{ blendState.IsEnableIndependentBlend() },
      blendStateTarget{},
      blendColor{ blendState.GetBlendColor() },
      sampleMask{ blendState.GetSampleMask() }
{
    for (auto i = 0; i < numBlendStateTargets; ++i)
    {
        const auto& in = blendState.GetBlendStateTarget(i);
        auto& out = blendStateTarget.at(i);
        out.SetEnable(in.IsEnable() ? GL_TRUE : GL_FALSE);
        out.SetSourceColor(GetBlendStateMode(in.GetSourceColor()));
        out.SetDestinationColor(GetBlendStateMode(in.GetDestinationColor()));
        out.SetOperationColor(GetBlendStateOperation(in.GetOperationColor()));
        out.SetSourceAlpha(GetBlendStateMode(in.GetSourceAlpha()));
        out.SetDestinationAlpha(GetBlendStateMode(in.GetDestinationAlpha()));
        out.SetOperationAlpha(GetBlendStateOperation(in.GetOperationAlpha()));
        out.SetRedMask(((in.GetMask() & BlendStateColorWrite::EnableRed) != BlendStateColorWrite::EnableRed) ? GL_TRUE : GL_FALSE);
        out.SetGreenMask(((in.GetMask() & BlendStateColorWrite::EnableGreen) != BlendStateColorWrite::EnableGreen) ? GL_TRUE : GL_FALSE);
        out.SetBlueMask(((in.GetMask() & BlendStateColorWrite::EnableBlue) != BlendStateColorWrite::EnableBlue) ? GL_TRUE : GL_FALSE);
        out.SetAlphaMask(((in.GetMask() & BlendStateColorWrite::EnableAlpha) != BlendStateColorWrite::EnableAlpha) ? GL_TRUE : GL_FALSE);
    }

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, OpenGLBlendStateImpl)

bool Rendering::OpenGLBlendStateImpl::IsEnableAlphaToCoverage() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return enableAlphaToCoverage;
}

void Rendering::OpenGLBlendStateImpl::SetEnableAlphaToCoverage(bool aEnableAlphaToCoverage) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    enableAlphaToCoverage = aEnableAlphaToCoverage;
}

bool Rendering::OpenGLBlendStateImpl::IsEnableIndependentBlend() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return enableIndependentBlend;
}

void Rendering::OpenGLBlendStateImpl::SetEnableIndependentBlend(bool aEnableIndependentBlend) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    enableIndependentBlend = aEnableIndependentBlend;
}

Rendering::OpenGLBlendStateImpl::ColourType Rendering::OpenGLBlendStateImpl::GetBlendColor() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return blendColor;
}

void Rendering::OpenGLBlendStateImpl::SetBlendColor(const ColourType& aBlendColor) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    blendColor = aBlendColor;
}

uint32_t Rendering::OpenGLBlendStateImpl::GetSampleMask() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return sampleMask;
}

void Rendering::OpenGLBlendStateImpl::SetSampleMask(uint32_t aSampleMask) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    sampleMask = aSampleMask;
}

Rendering::OpenGLBlendStateTarget Rendering::OpenGLBlendStateImpl::GetBlendStateTarget(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return blendStateTarget.at(index);
}

void Rendering::OpenGLBlendStateImpl::SetBlendStateTarget(int index, const OpenGLBlendStateTarget& aBlendStateTarget)
{
    RENDERING_CLASS_IS_VALID_9;

    blendStateTarget.at(index) = aBlendStateTarget;
}

Rendering::OpenGLBlendStateImpl::BlendStateTargetContainerConstIter Rendering::OpenGLBlendStateImpl::begin() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return blendStateTarget.cbegin();
}

Rendering::OpenGLBlendStateImpl::BlendStateTargetContainerConstIter Rendering::OpenGLBlendStateImpl::end() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return blendStateTarget.cend();
}

System::BlendStateMode Rendering::OpenGLBlendStateImpl::GetBlendStateMode(BlendStateMode blendStateMode)
{
    using Container = std::array<System::BlendStateMode, System::EnumCastUnderlying(BlendStateMode::Count)>;
    static Container container{ System::BlendStateMode::Zero,
                                System::BlendStateMode::One,
                                System::BlendStateMode::SourceColor,
                                System::BlendStateMode::OneMinusSourceColor,
                                System::BlendStateMode::SourceAlpha,
                                System::BlendStateMode::OneMinusSourceAlpha,
                                System::BlendStateMode::DestinationAlpha,
                                System::BlendStateMode::OneMinusDestinationAlpha,
                                System::BlendStateMode::DestinationColor,
                                System::BlendStateMode::OneMinusDestinationColor,
                                System::BlendStateMode::SourceAlphaSaturate,
                                System::BlendStateMode::ConstantColor,
                                System::BlendStateMode::OneMinusConstantColor,
                                System::BlendStateMode::Source1Color,
                                System::BlendStateMode::OneMinusSource1Color,
                                System::BlendStateMode::Source1Alpha,
                                System::BlendStateMode::OneMinusSource1Alpha };

    return container.at(System::EnumCastUnderlying(blendStateMode));
}

System::BlendStateOperation Rendering::OpenGLBlendStateImpl::GetBlendStateOperation(BlendStateOperation blendStateOperation)
{
    using Container = std::array<System::BlendStateOperation, System::EnumCastUnderlying(BlendStateOperation::Count)>;
    static Container container{ System::BlendStateOperation::FuncAdd,
                                System::BlendStateOperation::FuncSubtract,
                                System::BlendStateOperation::FuncReverseSubtract,
                                System::BlendStateOperation::Min,
                                System::BlendStateOperation::Max };

    return container.at(System::EnumCastUnderlying(blendStateOperation));
}
