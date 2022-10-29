///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.3 (2022/10/15 23:50)

#include "Rendering/RenderingExport.h"

#include "OpenGLSamplerState.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/OpenGLAPI.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Rendering/State/Flags/SamplerStateFilter.h"
#include "Rendering/State/Flags/SamplerStateMode.h"

Rendering::OpenGLSamplerState::OpenGLSamplerState(const SamplerStateSharedPtr& samplerState, const std::string& name)
    : ParentType{ samplerState, name }
{
    Init(*samplerState);

    RENDERING_SELF_CLASS_IS_VALID_9;
}

void Rendering::OpenGLSamplerState::Init(const SamplerState& samplerState)
{
    const auto handler = System::GetGLGenSamplers();

    SetGLHandle(handler);

    System::SetGLSamplerParameter(handler, System::OpenGLTextureName::WrapS, GetSamplerStateMode(samplerState.GetMode(0)));
    System::SetGLSamplerParameter(handler, System::OpenGLTextureName::WrapT, GetSamplerStateMode(samplerState.GetMode(1)));
    System::SetGLSamplerParameter(handler, System::OpenGLTextureName::WrapR, GetSamplerStateMode(samplerState.GetMode(2)));

    System::SetGLSamplerParameter(handler, System::OpenGLTextureName::MinLod, samplerState.GetMinLOD());
    System::SetGLSamplerParameter(handler, System::OpenGLTextureName::MaxLod, samplerState.GetMaxLOD());
    System::SetGLSamplerParameter(handler, System::OpenGLTextureName::LodBias, samplerState.GetMipLODBias());

    const auto borderColor = samplerState.GetBorderColor().GetPoint();
    System::SetGLSamplerParameter(handler, System::OpenGLTextureName::BorderColor, borderColor.data());

    switch (samplerState.GetFilter())
    {
        case SamplerStateFilter::MinPMagPMipP:
        {
            System::SetGLSamplerParameter(handler, System::OpenGLTextureName::MinFilter, System::SamplerFilter::NearestMipmapNearest);
            System::SetGLSamplerParameter(handler, System::OpenGLTextureName::MagFilter, System::SamplerFilter::Nearest);
            break;
        }
        case SamplerStateFilter::MinPMagPMipL:
        {
            System::SetGLSamplerParameter(handler, System::OpenGLTextureName::MinFilter, System::SamplerFilter::NearestMipmapLinear);
            System::SetGLSamplerParameter(handler, System::OpenGLTextureName::MagFilter, System::SamplerFilter::Nearest);
            break;
        }
        case SamplerStateFilter::MinPMagLMipP:
        {
            System::SetGLSamplerParameter(handler, System::OpenGLTextureName::MinFilter, System::SamplerFilter::NearestMipmapNearest);
            System::SetGLSamplerParameter(handler, System::OpenGLTextureName::MagFilter, System::SamplerFilter::Linear);
            break;
        }
        case SamplerStateFilter::MinPMagLMipL:
        {
            System::SetGLSamplerParameter(handler, System::OpenGLTextureName::MinFilter, System::SamplerFilter::NearestMipmapLinear);
            System::SetGLSamplerParameter(handler, System::OpenGLTextureName::MagFilter, System::SamplerFilter::Linear);
            break;
        }
        case SamplerStateFilter::MinLMagPMipP:
        {
            System::SetGLSamplerParameter(handler, System::OpenGLTextureName::MinFilter, System::SamplerFilter::LinearMipmapNearest);
            System::SetGLSamplerParameter(handler, System::OpenGLTextureName::MagFilter, System::SamplerFilter::Nearest);
            break;
        }
        case SamplerStateFilter::MinLMagPMipL:
        {
            System::SetGLSamplerParameter(handler, System::OpenGLTextureName::MinFilter, System::SamplerFilter::LinearMipmapLinear);
            System::SetGLSamplerParameter(handler, System::OpenGLTextureName::MagFilter, System::SamplerFilter::Nearest);
            break;
        }
        case SamplerStateFilter::MinLMagLMipP:
        {
            System::SetGLSamplerParameter(handler, System::OpenGLTextureName::MinFilter, System::SamplerFilter::LinearMipmapNearest);
            System::SetGLSamplerParameter(handler, System::OpenGLTextureName::MagFilter, System::SamplerFilter::Linear);
            break;
        }
        case SamplerStateFilter::MinLMagLMipL:
        {
            System::SetGLSamplerParameter(handler, System::OpenGLTextureName::MinFilter, System::SamplerFilter::LinearMipmapLinear);
            System::SetGLSamplerParameter(handler, System::OpenGLTextureName::MagFilter, System::SamplerFilter::Linear);
            break;
        }
        default:
        {
            THROW_EXCEPTION(SYSTEM_TEXT("未知的采样器状态筛选器。\n"));
        }
    }
}

Rendering::OpenGLSamplerState::~OpenGLSamplerState() noexcept
{
    System::SetGLDeleteSamplers(GetGLHandle());

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, OpenGLSamplerState)

void Rendering::OpenGLSamplerState::Enable() noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

System::TextureSamplerCoordinate Rendering::OpenGLSamplerState::GetSamplerStateMode(SamplerStateMode samplerStateMode)
{
    using Container = std::array<System::TextureSamplerCoordinate, System::EnumCastUnderlying(SamplerStateMode::Count)>;
    static Container container{ System::TextureSamplerCoordinate::Repeat,
                                System::TextureSamplerCoordinate::MirroredRepeat,
                                System::TextureSamplerCoordinate::ClampEdge,
                                System::TextureSamplerCoordinate::ClampBorder,
                                System::TextureSamplerCoordinate::MirroredRepeat };

    return container.at(System::EnumCastUnderlying(samplerStateMode));
}
