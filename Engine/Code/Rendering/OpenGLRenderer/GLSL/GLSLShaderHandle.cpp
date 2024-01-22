///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.4 (2024/01/15 09:48)

#include "Rendering/RenderingExport.h"

#include "GLSLShaderHandle.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/OpenGL/Flags/OpenGLProgramFlags.h"
#include "System/OpenGL/Flags/OpenGLShaderFlags.h"
#include "System/OpenGL/OpenGLProgram.h"
#include "System/OpenGL/OpenGLShader.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Rendering/Shaders/ProgramDefines.h"

Rendering::GLSLShaderHandle::GLSLShaderHandle() noexcept
    : programHandle{}, shaderHandle{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::GLSLShaderHandle::GLSLShaderHandle(ShaderType shaderType, const std::string& source, const std::string& version, const ProgramDefines& defines, OpenGLUInt programHandle, const String& errorMessage)
    : programHandle{ programHandle }, shaderHandle{ CreateGLShader(shaderType) }
{
    Compile(source, version, defines, errorMessage);

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::GLSLShaderHandle::~GLSLShaderHandle() noexcept
{
    RENDERING_SELF_CLASS_IS_VALID_9;

    DetachGLShader();
}

void Rendering::GLSLShaderHandle::DetachGLShader() const noexcept
{
    if (0 < shaderHandle && System::IsGLShader(shaderHandle))
    {
        System::DetachGLShader(programHandle, shaderHandle);
        System::DeleteGLShader(shaderHandle);
    }
}

void Rendering::GLSLShaderHandle::Compile(const std::string& source, const std::string& version, const ProgramDefines& defines, const String& errorMessage) const
{
    if (0 < shaderHandle)
    {
        ShaderSource(source, version, defines);
        Compile();
        AttachShader();
    }
    else
    {
        THROW_EXCEPTION(errorMessage)
    }
}

void Rendering::GLSLShaderHandle::ShaderSource(const std::string& source, const std::string& version, const ProgramDefines& defines) const
{
    /// 为定义做准备
    /// 1. GLSL程序的版本，例如“#version 400”。
    /// 2. 定义矩阵矢量乘法约定：如果选择为MATHEMATICS_USE_MATRIX_VECTOR，
    ///    则“#define MATHEMATICS_USE_MATRIX_VECTOR 1”，
    ///    否则“#define MATHEMATICS_USE_MATRIX_VECTOR 0”。
    /// 3. "layout(std140, *_major) uniform;"
    ///    为所有uniform矩阵选择默认值row_major或column_major。
    ///    并选择std140布局。
    /// 4. "layout(std430, *_major) buffer;"
    ///    为所有buffer矩阵选择默认值row_major或column_major。
    ///    并选择std430布局。
    /// 将源代码字符串附加到定义中。
    DefinesType sourceContainer{};
    const auto size = defines.GetSize() + 5;
    sourceContainer.reserve(size);
    sourceContainer.emplace_back(version + "\n");

#ifdef MATHEMATICS_USE_MATRIX_VECTOR

    sourceContainer.emplace_back("#define MATHEMATICS_USE_MATRIX_VECTOR 1\n");

#else  // !MATHEMATICS_USE_MATRIX_VECTOR

    sourceContainer.emplace_back("#define MATHEMATICS_USE_MATRIX_VECTOR 0\n");

#endif  // MATHEMATICS_USE_MATRIX_VECTOR

#ifdef MATHEMATICS_USE_ROW_MAJOR

    sourceContainer.emplace_back("layout(std140, row_major) uniform;\n");
    sourceContainer.emplace_back("layout(std430, row_major) buffer;\n");

#else  // !MATHEMATICS_USE_ROW_MAJOR

    sourceContainer.emplace_back("layout(std140, column_major) uniform;\n");
    sourceContainer.emplace_back("layout(std430, column_major) buffer;\n");

#endif  // MATHEMATICS_USE_ROW_MAJOR

    for (const auto& define : defines)
    {
        sourceContainer.emplace_back("#define " + define.first + " " + define.second + "\n");
    }

    sourceContainer.emplace_back(source);

    // 重新打包glShaderSource的定义。
    CodeType code{};
    code.reserve(sourceContainer.size());
    for (const auto& define : sourceContainer)
    {
        code.emplace_back(define.c_str());
    }

    System::SetGLShaderSource(shaderHandle, boost::numeric_cast<System::OpenGLSize>(code.size()), code.data(), nullptr);
}

void Rendering::GLSLShaderHandle::Compile() const
{
    System::CompileGLShader(shaderHandle);

    if (!GetGLShader(shaderHandle, System::ShaderStatus::Compile))
    {
        if (const auto logLength = GetGLShader(shaderHandle, System::ShaderAttributes::InfoLogLength);
            0 < logLength)
        {
            const auto message = System::GetGLShaderInfoLog(shaderHandle);

            THROW_EXCEPTION(SYSTEM_TEXT("编译失败:\n") + CoreTools::StringConversion::MultiByteConversionStandard(message))
        }
        else
        {
            THROW_EXCEPTION(SYSTEM_TEXT("无效信息日志长度。"))
        }
    }
}

void Rendering::GLSLShaderHandle::AttachShader() const noexcept
{
    System::AttachGLShader(programHandle, shaderHandle);
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, GLSLShaderHandle)

bool Rendering::GLSLShaderHandle::IsShader() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return 0 < shaderHandle;
}

Rendering::GLSLShaderHandle::OpenGLUInt Rendering::GLSLShaderHandle::GetShaderHandle() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return shaderHandle;
}
