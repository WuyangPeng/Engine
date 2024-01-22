///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.4 (2024/01/15 09:48)

#ifndef RENDERING_OPENGL_RENDERER_GLSL_SHADER_HANDLE_H
#define RENDERING_OPENGL_RENDERER_GLSL_SHADER_HANDLE_H

#include "Rendering/RenderingDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "System/OpenGL/Fwd/OpenGLFlagsFwd.h"
#include "System/OpenGL/Using/OpenGLUsing.h"
#include "Rendering/Shaders/ShadersFwd.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE GLSLShaderHandle
    {
    public:
        using ClassType = GLSLShaderHandle;

        using String = System::String;
        using OpenGLUInt = System::OpenGLUInt;
        using ShaderType = System::ShaderType;

    public:
        GLSLShaderHandle() noexcept;
        GLSLShaderHandle(ShaderType shaderType, const std::string& source, const std::string& version, const ProgramDefines& defines, OpenGLUInt programHandle, const String& errorMessage);
        ~GLSLShaderHandle() noexcept;
        GLSLShaderHandle(const GLSLShaderHandle& rhs) = default;
        GLSLShaderHandle& operator=(const GLSLShaderHandle& rhs) = default;
        GLSLShaderHandle(GLSLShaderHandle&& rhs) noexcept = default;
        GLSLShaderHandle& operator=(GLSLShaderHandle&& rhs) noexcept = default;

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool IsShader() const noexcept;
        NODISCARD OpenGLUInt GetShaderHandle() const noexcept;

    private:
        void Compile(const std::string& source, const std::string& version, const ProgramDefines& defines, const String& errorMessage) const;
        void ShaderSource(const std::string& source, const std::string& version, const ProgramDefines& defines) const;
        void Compile() const;
        void AttachShader() const noexcept;
        void DetachGLShader() const noexcept;

    private:
        using OpenGLChar = System::OpenGLChar;
        using DefinesType = std::vector<std::string>;
        using CodeType = std::vector<const OpenGLChar*>;

    private:
        OpenGLUInt programHandle;
        OpenGLUInt shaderHandle;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_GLSL_SHADER_HANDLE_H
