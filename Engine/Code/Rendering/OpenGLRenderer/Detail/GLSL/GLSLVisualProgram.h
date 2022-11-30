///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.4 (2022/11/06 21:05)

#ifndef RENDERING_OPENGL_RENDERER_GLSL_VISUAL_PROGRAM_H
#define RENDERING_OPENGL_RENDERER_GLSL_VISUAL_PROGRAM_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Renderers/RenderersFwd.h"
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
        NODISCARD GLSLReflection GetReflector() const override;

        NODISCARD VisualProgramSharedPtr Clone() const override;

    private:
        OpenGLUInt programHandle;
        OpenGLUInt vertexShaderHandle;
        OpenGLUInt pixelShaderHandle;
        OpenGLUInt geometryShaderHandle;
        GLSLReflection reflector;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_GLSL_VISUAL_PROGRAM_H
