///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:21)

#ifndef RENDERING_OPENGL_RENDERER_GLSL_COMPUTE_PROGRAM_H
#define RENDERING_OPENGL_RENDERER_GLSL_COMPUTE_PROGRAM_H

#include "Rendering/RenderingDll.h"

#include "Rendering/RendererEngine/RendererEngineFwd.h"
#include "Rendering/Shaders/Detail/ComputeProgramImpl.h"
#include "Rendering/Shaders/Reflection.h"

namespace Rendering
{
    class GLSLComputeProgram : public ComputeProgramImpl
    {
    public:
        using ClassType = GLSLComputeProgram;
        using ParentType = ComputeProgramImpl;
        using OpenGLUInt = System::OpenGLUInt;

    public:
        GLSLComputeProgram(OpenGLUInt programHandle, OpenGLUInt computeShaderHandle);
        ~GLSLComputeProgram() noexcept;
        GLSLComputeProgram(const GLSLComputeProgram& rhs) = default;
        GLSLComputeProgram& operator=(const GLSLComputeProgram& rhs) = default;
        GLSLComputeProgram(GLSLComputeProgram&& rhs) noexcept = default;
        GLSLComputeProgram& operator=(GLSLComputeProgram&& rhs) noexcept = default;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD OpenGLUInt GetProgramHandle() const noexcept;
        NODISCARD OpenGLUInt GetComputeShaderHandle() const noexcept;
        NODISCARD Reflection GetReflector() const override;
        NODISCARD ComputeProgramSharedPtr Clone() const override;

    private:
        OpenGLUInt programHandle;
        OpenGLUInt computeShaderHandle;
        Reflection reflector;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_GLSL_COMPUTE_PROGRAM_H
