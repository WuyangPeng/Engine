/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.6 (2024/03/01 17:37)

#ifndef SYSTEM_OPENGL_OPENGL_SAMPLERS_H
#define SYSTEM_OPENGL_OPENGL_SAMPLERS_H

#include "System/SystemDll.h"

#include "Fwd/OpenGLFlagsFwd.h"
#include "Using/OpenGLUsing.h"

namespace System
{
    void SYSTEM_DEFAULT_DECLARE GetGLGenSamplers(OpenGLSize count, OpenGLUInt* samplers) noexcept;
    NODISCARD OpenGLUInt SYSTEM_DEFAULT_DECLARE GetGLGenSamplers() noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLDeleteSamplers(OpenGLSize count, const OpenGLUInt* samplers) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLDeleteSamplers(OpenGLUInt samplers) noexcept;

    void SYSTEM_DEFAULT_DECLARE SetGLSamplerParameter(OpenGLUInt sampler, OpenGLTextureName pName, OpenGLInt param) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLSamplerParameter(OpenGLUInt sampler, OpenGLTextureName pName, TextureSamplerCoordinate param) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLSamplerParameter(OpenGLUInt sampler, OpenGLTextureName pName, SamplerFilter param) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLSamplerParameter(OpenGLUInt sampler, OpenGLTextureName pName, OpenGLFloat param) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLSamplerParameter(OpenGLUInt sampler, OpenGLTextureName pName, const OpenGLFloat* param) noexcept;

    void SYSTEM_DEFAULT_DECLARE SetGLBindSampler(OpenGLUInt unit, OpenGLUInt sampler) noexcept;
}

#endif  // SYSTEM_OPENGL_OPENGL_SAMPLERS_H