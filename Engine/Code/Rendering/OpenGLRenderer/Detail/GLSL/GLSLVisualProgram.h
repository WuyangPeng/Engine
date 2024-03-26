/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2024/01/09 16:56)

#ifndef RENDERING_OPENGL_RENDERER_GLSL_VISUAL_PROGRAM_H
#define RENDERING_OPENGL_RENDERER_GLSL_VISUAL_PROGRAM_H

#include "Rendering/RenderingDll.h"

#include "Rendering/OpenGLRenderer/GLSL/GLSLProgramHandle.h"
#include "Rendering/Shaders/Detail/VisualProgramImpl.h"
#include "Rendering/Shaders/Reflection.h"

namespace Rendering
{
    class GLSLVisualProgram : public VisualProgramImpl
    {
    public:
        using ClassType = GLSLVisualProgram;
        using ParentType = VisualProgramImpl;

        using OpenGLUInt = System::OpenGLUnsignedInt;

    public:
        GLSLVisualProgram(const GLSLProgramHandle& programHandle, const GLSLShaderHandle& vertexShaderHandle, const GLSLShaderHandle& pixelShaderHandle, const GLSLShaderHandle& geometryShaderHandle);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD OpenGLUInt GetProgramHandle() const noexcept override;
        NODISCARD OpenGLUInt GetVertexShaderHandle() const noexcept;
        NODISCARD OpenGLUInt GetPixelShaderHandle() const noexcept;
        NODISCARD OpenGLUInt GetGShaderHandle() const noexcept;
        NODISCARD Reflection GetReflector() const override;

        NODISCARD VisualProgramSharedPtr Clone() const override;

    private:
        GLSLProgramHandle programHandle;
        GLSLShaderHandle vertexShaderHandle;
        GLSLShaderHandle pixelShaderHandle;
        GLSLShaderHandle geometryShaderHandle;
        Reflection reflector;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_GLSL_VISUAL_PROGRAM_H
