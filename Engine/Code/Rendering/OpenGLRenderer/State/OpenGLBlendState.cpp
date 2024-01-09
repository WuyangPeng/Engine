/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/06 12:50)

#include "Rendering/RenderingExport.h"

#include "OpenGLBlendState.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"

#include "System/OpenGL/OpenGLBase.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Rendering/OpenGLRenderer/Detail/State/OpenGLBlendStateImpl.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, OpenGLBlendState)

Rendering::OpenGLBlendState::OpenGLBlendState(const BlendStateSharedPtr& blendState, const std::string& name)
    : ParentType{ blendState, name }, impl{ *blendState }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, OpenGLBlendState)

void Rendering::OpenGLBlendState::Enable()
{
    RENDERING_CLASS_IS_VALID_9;

    EnableAlphaToCoverage();
    EnableIndependentBlend();
    SetGLBlendColor();
}

void Rendering::OpenGLBlendState::EnableAlphaToCoverage() noexcept
{
    if (impl->IsEnableAlphaToCoverage())
    {
        EnableGLState(System::OpenGLEnable::SampleCoverage);
    }
    else
    {
        DisableGLState(System::OpenGLEnable::SampleCoverage);
    }
}

void Rendering::OpenGLBlendState::EnableIndependentBlend()
{
    if (impl->IsEnableIndependentBlend())
    {
        auto index = 0;
        for (const auto& target : *impl)
        {
            if (target.IsEnable())
            {
                EnableGLState(System::OpenGLEnable::Blend, index);
                SetGLBlendFuncSeparate(index,
                                               target.GetSourceColor(),
                                               target.GetDestinationColor(),
                                               target.GetSourceAlpha(),
                                               target.GetDestinationAlpha());
                SetGLBlendEquationSeparate(index,
                                                   target.GetOperationColor(),
                                                   target.GetOperationAlpha());
            }
            else
            {
                DisableGLState(System::OpenGLEnable::Blend, index);
            }

            System::SetGLColorMask(index, target.IsRedMask(), target.IsGreenMask(), target.IsBlueMask(), target.IsAlphaMask());
            System::SetGLSampleMask(index, impl->GetSampleMask());

            ++index;
        }
    }
    else
    {
        const auto target = impl->GetBlendStateTarget(0);
        if (target.IsEnable())
        {
            EnableGLState(System::OpenGLEnable::Blend);

            SetGLBlendFuncSeparate(target.GetSourceColor(),
                                           target.GetDestinationColor(),
                                           target.GetSourceAlpha(),
                                           target.GetDestinationAlpha());
            SetGLBlendEquationSeparate(target.GetOperationColor(),
                                               target.GetOperationAlpha());
        }
        else
        {
            DisableGLState(System::OpenGLEnable::Blend);
        }

        System::SetGLColorMask(target.IsRedMask(), target.IsGreenMask(), target.IsBlueMask(), target.IsAlphaMask());
        System::SetGLSampleMask(0, impl->GetSampleMask());
    }
}

void Rendering::OpenGLBlendState::SetGLBlendColor() noexcept
{
    const auto blendColor = impl->GetBlendColor();
    System::SetGLBlendColor(blendColor.GetRed(), blendColor.GetGreen(), blendColor.GetBlue(), blendColor.GetAlpha());
}
