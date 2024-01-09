/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/21 17:25)

#include "System/SystemExport.h"

#include "OpenGLSamplers.h"
#include "Flags/OpenGLFlags.h"
#include "Detail/GL33Extensions.h"
#include "System/Helper/EnumCast.h"

void System::GetGLGenSamplers(OpenGLSize count, OpenGLUInt* samplers) noexcept
{
    GLGenSamplers(count, samplers);
}

System::OpenGLUInt System::GetGLGenSamplers() noexcept
{
    OpenGLUInt sampler{};
    GetGLGenSamplers(1, &sampler);

    return sampler;
}

void System::SetGLDeleteSamplers(OpenGLSize count, const OpenGLUInt* samplers) noexcept
{
    GLDeleteSamplers(count, samplers);
}

void System::SetGLDeleteSamplers(OpenGLUInt samplers) noexcept
{
    GLDeleteSamplers(1, &samplers);
}

void System::SetGLSamplerParameter(OpenGLUInt sampler, OpenGLTextureName pName, OpenGLInt param) noexcept
{
    GLSamplerParameteri(sampler, EnumCastUnderlying(pName), param);
}

void System::SetGLSamplerParameter(OpenGLUInt sampler, OpenGLTextureName pName, SamplerFilter param) noexcept
{
    SetGLSamplerParameter(sampler, pName, EnumCastUnderlying(param));
}

void System::SetGLSamplerParameter(OpenGLUInt sampler, OpenGLTextureName pName, TextureSamplerCoordinate param) noexcept
{
    SetGLSamplerParameter(sampler, pName, EnumCastUnderlying(param));
}

void System::SetGLSamplerParameter(OpenGLUInt sampler, OpenGLTextureName pName, OpenGLFloat param) noexcept
{
    GLSamplerParameterf(sampler, EnumCastUnderlying(pName), param);
}

void System::SetGLSamplerParameter(OpenGLUInt sampler, OpenGLTextureName pName, const OpenGLFloat* param) noexcept
{
    GLSamplerParameterfv(sampler, EnumCastUnderlying(pName), param);
}

void System::SetGLBindSampler(OpenGLUInt unit, OpenGLUInt sampler) noexcept
{
    GLBindSampler(unit, sampler);
}
