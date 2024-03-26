/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/06 16:12)

#include "Rendering/RenderingExport.h"

#include "OpenGLSamplerState.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/Flags/OpenGLTextureFlags.h"
#include "System/OpenGL/OpenGLSamplers.h"
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

Rendering::OpenGLSamplerState::~OpenGLSamplerState() noexcept
{
    System::SetGLDeleteSamplers(ParentType::GetGLHandle());

    RENDERING_SELF_CLASS_IS_VALID_9;
}

void Rendering::OpenGLSamplerState::Init(const SamplerState& samplerState)
{
    const auto handler = System::GetGLGenSamplers();

    SetGLHandle(handler);

    SetGLSamplerParameter(handler, System::OpenGLTextureName::WrapS, GetSamplerStateMode(samplerState.GetMode(0)));
    SetGLSamplerParameter(handler, System::OpenGLTextureName::WrapT, GetSamplerStateMode(samplerState.GetMode(1)));
    SetGLSamplerParameter(handler, System::OpenGLTextureName::WrapR, GetSamplerStateMode(samplerState.GetMode(2)));

    SetGLSamplerParameter(handler, System::OpenGLTextureName::MinLod, samplerState.GetMinLod());
    SetGLSamplerParameter(handler, System::OpenGLTextureName::MaxLod, samplerState.GetMaxLod());
    SetGLSamplerParameter(handler, System::OpenGLTextureName::LodBias, samplerState.GetMipLodBias());

    const auto borderColor = samplerState.GetBorderColor().GetPoint();
    SetGLSamplerParameter(handler, System::OpenGLTextureName::BorderColor, borderColor.data());

    switch (samplerState.GetFilter())
    {
        case SamplerStateFilter::MinPMagPMipP:
        {
            SetGLSamplerParameter(handler, System::OpenGLTextureName::MinFilter, System::SamplerFilter::NearestMipmapNearest);
            SetGLSamplerParameter(handler, System::OpenGLTextureName::MagFilter, System::SamplerFilter::Nearest);
            break;
        }
        case SamplerStateFilter::MinPMagPMipL:
        {
            SetGLSamplerParameter(handler, System::OpenGLTextureName::MinFilter, System::SamplerFilter::NearestMipmapLinear);
            SetGLSamplerParameter(handler, System::OpenGLTextureName::MagFilter, System::SamplerFilter::Nearest);
            break;
        }
        case SamplerStateFilter::MinPMagLMipP:
        {
            SetGLSamplerParameter(handler, System::OpenGLTextureName::MinFilter, System::SamplerFilter::NearestMipmapNearest);
            SetGLSamplerParameter(handler, System::OpenGLTextureName::MagFilter, System::SamplerFilter::Linear);
            break;
        }
        case SamplerStateFilter::MinPMagLMipL:
        {
            SetGLSamplerParameter(handler, System::OpenGLTextureName::MinFilter, System::SamplerFilter::NearestMipmapLinear);
            SetGLSamplerParameter(handler, System::OpenGLTextureName::MagFilter, System::SamplerFilter::Linear);
            break;
        }
        case SamplerStateFilter::MinLMagPMipP:
        {
            SetGLSamplerParameter(handler, System::OpenGLTextureName::MinFilter, System::SamplerFilter::LinearMipmapNearest);
            SetGLSamplerParameter(handler, System::OpenGLTextureName::MagFilter, System::SamplerFilter::Nearest);
            break;
        }
        case SamplerStateFilter::MinLMagPMipL:
        {
            SetGLSamplerParameter(handler, System::OpenGLTextureName::MinFilter, System::SamplerFilter::LinearMipmapLinear);
            SetGLSamplerParameter(handler, System::OpenGLTextureName::MagFilter, System::SamplerFilter::Nearest);
            break;
        }
        case SamplerStateFilter::MinLMagLMipP:
        {
            SetGLSamplerParameter(handler, System::OpenGLTextureName::MinFilter, System::SamplerFilter::LinearMipmapNearest);
            SetGLSamplerParameter(handler, System::OpenGLTextureName::MagFilter, System::SamplerFilter::Linear);
            break;
        }
        case SamplerStateFilter::MinLMagLMipL:
        {
            SetGLSamplerParameter(handler, System::OpenGLTextureName::MinFilter, System::SamplerFilter::LinearMipmapLinear);
            SetGLSamplerParameter(handler, System::OpenGLTextureName::MagFilter, System::SamplerFilter::Linear);
            break;
        }
        default:
        {
            THROW_EXCEPTION(SYSTEM_TEXT("未知的采样器状态筛选器。\n"));
        }
    }
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, OpenGLSamplerState)

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
