///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.4 (2022/11/06 21:05)

#ifndef RENDERING_OPENGL_RENDERER_GLSL_COMPUTE_PROGRAM_H
#define RENDERING_OPENGL_RENDERER_GLSL_COMPUTE_PROGRAM_H

#include "Rendering/RenderingDll.h"

#include "Rendering/OpenGLRenderer/GLSL/GLSLReflection.h"
#include "Rendering/Renderers/RenderersFwd.h"
#include "Rendering/Shaders/Detail/ComputeProgramImpl.h"

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
        NODISCARD GLSLReflection GetReflector() const override;
        NODISCARD ComputeProgramSharedPtr Clone() const override;

    private:
        OpenGLUInt programHandle;
        OpenGLUInt computeShaderHandle;
        GLSLReflection reflector;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_GLSL_COMPUTE_PROGRAM_H
