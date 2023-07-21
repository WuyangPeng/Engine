///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:21)

#ifndef RENDERING_OPENGL_RENDERER_GLSL_VISUAL_PROGRAM_H
#define RENDERING_OPENGL_RENDERER_GLSL_VISUAL_PROGRAM_H

#include "Rendering/RenderingDll.h"

#include "Rendering/RendererEngine/RendererEngineFwd.h"
#include "Rendering/Shaders/Reflection.h"
#include "Rendering/Shaders/Detail/VisualProgramImpl.h"

namespace Rendering
{
    class GLSLVisualProgram : public VisualProgramImpl
    {
    public:
        using ClassType = GLSLVisualProgram;
        using ParentType = VisualProgramImpl;
        using OpenGLUInt = System::OpenGLUInt;

    public:
        GLSLVisualProgram(OpenGLUInt programHandle, OpenGLUInt vertexShaderHandle, OpenGLUInt pixelShaderHandle, OpenGLUInt geometryShaderHandle);
        ~GLSLVisualProgram() noexcept;
        GLSLVisualProgram(const GLSLVisualProgram& rhs) = default;
        GLSLVisualProgram& operator=(const GLSLVisualProgram& rhs) = default;
        GLSLVisualProgram(GLSLVisualProgram&& rhs) noexcept = default;
        GLSLVisualProgram& operator=(GLSLVisualProgram&& rhs) noexcept = default;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD OpenGLUInt GetProgramHandle() const noexcept;
        NODISCARD OpenGLUInt GetVertexShaderHandle() const noexcept;
        NODISCARD OpenGLUInt GetPixelShaderHandle() const noexcept;
        NODISCARD OpenGLUInt GetGShaderHandle() const noexcept;
        NODISCARD Reflection GetReflector() const override;

        NODISCARD VisualProgramSharedPtr Clone() const override;

    private:
        OpenGLUInt programHandle;
        OpenGLUInt vertexShaderHandle;
        OpenGLUInt pixelShaderHandle;
        OpenGLUInt geometryShaderHandle;
        Reflection reflector;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_GLSL_VISUAL_PROGRAM_H
