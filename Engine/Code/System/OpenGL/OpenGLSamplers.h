///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.0 (2023/01/15 23:35)

#ifndef SYSTEM_OPENGL_OPENGL_SAMPLERS_H
#define SYSTEM_OPENGL_OPENGL_SAMPLERS_H

#include "System/SystemDll.h"

#include "Fwd/OpenGLFlagsFwd.h"
#include "Using/OpenGLUsing.h"
#include "System/Helper/GLExtensionsMacro.h"

namespace System
{
    void SYSTEM_DEFAULT_DECLARE GetGLGenSamplers(OpenGLSize count, OpenGLUInt* samplers) noexcept;
    NODISCARD OpenGLUInt SYSTEM_DEFAULT_DECLARE GetGLGenSamplers() noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLDeleteSamplers(OpenGLSize count, const OpenGLUInt* samplers) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLDeleteSamplers(OpenGLUInt samplers) noexcept;

    void SYSTEM_DEFAULT_DECLARE SetGLSamplerParameter(OpenGLUInt sampler, OpenGLTextureName pname, OpenGLInt param) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLSamplerParameter(OpenGLUInt sampler, OpenGLTextureName pname, TextureSamplerCoordinate param) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLSamplerParameter(OpenGLUInt sampler, OpenGLTextureName pname, SamplerFilter param) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLSamplerParameter(OpenGLUInt sampler, OpenGLTextureName pname, OpenGLFloat param) noexcept;
    void SYSTEM_DEFAULT_DECLARE SetGLSamplerParameter(OpenGLUInt sampler, OpenGLTextureName pname, const OpenGLFloat* param) noexcept;
}

#endif  // SYSTEM_OPENGL_OPENGL_SAMPLERS_H