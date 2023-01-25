///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.3 (2022/10/11 22:45)

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
        System::EnableGLState(System::OpenGLEnable::SampleCoverage);
    }
    else
    {
        System::DisableGLState(System::OpenGLEnable::SampleCoverage);
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
                System::EnableGLState(System::OpenGLEnable::Blend, index);
                System::SetGLBlendFuncSeparate(index,
                                               target.GetSourceColor(),
                                               target.GetDestinationColor(),
                                               target.GetSourceAlpha(),
                                               target.GetDestinationAlpha());
                System::SetGLBlendEquationSeparate(index,
                                                   target.GetOperationColor(),
                                                   target.GetOperationAlpha());
            }
            else
            {
                System::DisableGLState(System::OpenGLEnable::Blend, index);
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
            System::EnableGLState(System::OpenGLEnable::Blend);

            System::SetGLBlendFuncSeparate(target.GetSourceColor(),
                                           target.GetDestinationColor(),
                                           target.GetSourceAlpha(),
                                           target.GetDestinationAlpha());
            System::SetGLBlendEquationSeparate(target.GetOperationColor(),
                                               target.GetOperationAlpha());
        }
        else
        {
            System::DisableGLState(System::OpenGLEnable::Blend);
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
