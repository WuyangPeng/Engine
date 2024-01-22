/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2024/01/09 16:53)

#ifndef RENDERING_OPENGL_RENDERER_GLSL_COMPUTE_PROGRAM_H
#define RENDERING_OPENGL_RENDERER_GLSL_COMPUTE_PROGRAM_H

#include "Rendering/RenderingDll.h"

#include "Rendering/OpenGLRenderer/GLSL/GLSLProgramHandle.h"
#include "Rendering/OpenGLRenderer/GLSL/GLSLShaderHandle.h"
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
        GLSLComputeProgram(const GLSLProgramHandle& programHandle, const GLSLShaderHandle& computeShaderHandle);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD OpenGLUInt GetProgramHandle() const noexcept override;
        NODISCARD OpenGLUInt GetComputeShaderHandle() const noexcept;
        NODISCARD Reflection GetReflector() const override;
        NODISCARD ComputeProgramSharedPtr Clone() const override;

    private:
        GLSLProgramHandle programHandle;
        GLSLShaderHandle computeShaderHandle;
        Reflection reflector;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_GLSL_COMPUTE_PROGRAM_H
