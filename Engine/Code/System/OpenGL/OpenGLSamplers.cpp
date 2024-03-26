/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/03 00:12)

#include "System/SystemExport.h"

#include "OpenGLSamplers.h"
#include "Flags/OpenGLFlags.h"
#include "Detail/GL33Extensions.h"
#include "System/Helper/EnumCast.h"

void System::GetGLGenSamplers(OpenGLSize count, OpenGLUnsignedInt* samplers) noexcept
{
    GLGenSamplers(count, samplers);
}

System::OpenGLUnsignedInt System::GetGLGenSamplers() noexcept
{
    OpenGLUnsignedInt sampler{};
    GetGLGenSamplers(1, &sampler);

    return sampler;
}

void System::SetGLDeleteSamplers(OpenGLSize count, const OpenGLUnsignedInt* samplers) noexcept
{
    GLDeleteSamplers(count, samplers);
}

void System::SetGLDeleteSamplers(OpenGLUnsignedInt samplers) noexcept
{
    GLDeleteSamplers(1, &samplers);
}

void System::SetGLSamplerParameter(OpenGLUnsignedInt sampler, OpenGLTextureName pName, OpenGLInt param) noexcept
{
    GLSamplerParameterI(sampler, EnumCastUnderlying(pName), param);
}

void System::SetGLSamplerParameter(OpenGLUnsignedInt sampler, OpenGLTextureName pName, SamplerFilter param) noexcept
{
    SetGLSamplerParameter(sampler, pName, EnumCastUnderlying(param));
}

void System::SetGLSamplerParameter(OpenGLUnsignedInt sampler, OpenGLTextureName pName, TextureSamplerCoordinate param) noexcept
{
    SetGLSamplerParameter(sampler, pName, EnumCastUnderlying(param));
}

void System::SetGLSamplerParameter(OpenGLUnsignedInt sampler, OpenGLTextureName pName, OpenGLFloat param) noexcept
{
    GLSamplerParameterF(sampler, EnumCastUnderlying(pName), param);
}

void System::SetGLSamplerParameter(OpenGLUnsignedInt sampler, OpenGLTextureName pName, const OpenGLFloat* param) noexcept
{
    GLSamplerParameterFv(sampler, EnumCastUnderlying(pName), param);
}

void System::SetGLBindSampler(OpenGLUnsignedInt unit, OpenGLUnsignedInt sampler) noexcept
{
    GLBindSampler(unit, sampler);
}
