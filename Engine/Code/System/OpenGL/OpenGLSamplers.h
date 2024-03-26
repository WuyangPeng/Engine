/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.6 (2024/03/01 17:37)

#ifndef SYSTEM_OPENGL_OPENGL_SAMPLERS_H
#define SYSTEM_OPENGL_OPENGL_SAMPLERS_H

#include "System/SystemDll.h"

#include "Fwd/OpenGLFlagsFwd.h"
#include "Using/OpenGLUsing.h"

namespace System
{
    void SYSTEM_DEFAULT_DECLARE GetGLGenSamplers(OpenGLSize count, OpenGLUnsignedInt* samplers) noexcept;
    NODISCARD OpenGLUnsignedInt SYSTEM_DEFAULT_DECLARE GetGLGenSamplers() noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLDeleteSamplers(OpenGLSize count, const OpenGLUnsignedInt* samplers) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLDeleteSamplers(OpenGLUnsignedInt samplers) noexcept;

    void SYSTEM_DEFAULT_DECLARE SetGLSamplerParameter(OpenGLUnsignedInt sampler, OpenGLTextureName pName, OpenGLInt param) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLSamplerParameter(OpenGLUnsignedInt sampler, OpenGLTextureName pName, TextureSamplerCoordinate param) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLSamplerParameter(OpenGLUnsignedInt sampler, OpenGLTextureName pName, SamplerFilter param) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLSamplerParameter(OpenGLUnsignedInt sampler, OpenGLTextureName pName, OpenGLFloat param) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLSamplerParameter(OpenGLUnsignedInt sampler, OpenGLTextureName pName, const OpenGLFloat* param) noexcept;

    void SYSTEM_DEFAULT_DECLARE SetGLBindSampler(OpenGLUnsignedInt unit, OpenGLUnsignedInt sampler) noexcept;
}

#endif  // SYSTEM_OPENGL_OPENGL_SAMPLERS_H