/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/09 16:56)

#include "Rendering/RenderingExport.h"

#include "GLSLProgramFactory.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/OpenGL/Flags/OpenGLProgramFlags.h"
#include "System/OpenGL/Flags/OpenGLShaderFlags.h"
#include "System/OpenGL/OpenGLProgram.h"
#include "System/OpenGL/OpenGLShader.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Rendering/Base/Flags/GraphicsObjectType.h"
#include "Rendering/RendererEngine/Flags/RendererTypes.h"
#include "Rendering/Shaders/ComputeProgram.h"
#include "Rendering/Shaders/Flags/ReferenceType.h"
#include "Rendering/Shaders/Flags/ShaderAPIType.h"
#include "Rendering/Shaders/Reflection.h"
#include "Rendering/Shaders/Shader.h"
#include "Rendering/Shaders/VisualProgram.h"

Rendering::ProgramFactoryImpl::ProgramFactorySharedPtr Rendering::GLSLProgramFactory::Create()
{
    return std::make_shared<ClassType>(CoreTools::DisableNotThrow::Disable);
}

Rendering::GLSLProgramFactory::GLSLProgramFactory(CoreTools::DisableNotThrow disableNotThrow)
    : ParentType{ "#version 430", "main", "main", "main", "main", 0 }
{
    System::UnusedFunction(disableNotThrow);

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, GLSLProgramFactory)

Rendering::ShaderAPIType Rendering::GLSLProgramFactory::GetAPI() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return ShaderAPIType::GLSL;
}

Rendering::GLSLProgramFactory::VisualProgramSharedPtr Rendering::GLSLProgramFactory::CreateFromNamedSources(const std::string& vertexShaderName, const std::string& vertexShaderSource, const std::string& pixelShaderName, const std::string& pixelShaderSource, const std::string& geometryShaderName, const std::string& geometryShaderSource)
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(vertexShaderName, pixelShaderName, geometryShaderName);

    if (vertexShaderSource.empty() || pixelShaderSource.empty())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("程序必须具有顶点着色器和像素着色器。"));
    }

    auto vertexShaderHandle = Compile(ShaderType::Vertex, vertexShaderSource);
    if (vertexShaderHandle == 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("编译顶点着色器失败。"));
    }

    auto pixelShaderHandle = Compile(ShaderType::Fragment, pixelShaderSource);
    if (pixelShaderHandle == 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("编译像素着色器失败。"));
    }

    auto geometryShaderHandle = 0;
    if (geometryShaderSource != "")
    {
        geometryShaderHandle = Compile(ShaderType::Geometry, geometryShaderSource);
        if (geometryShaderHandle == 0)
        {
            THROW_EXCEPTION(SYSTEM_TEXT("编译几何着色器失败。"));
        }
    }

    auto programHandle = System::CreateGLProgram();
    if (programHandle == 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("程序创建失败。"));
    }

    System::AttachGLShader(programHandle, vertexShaderHandle);
    System::AttachGLShader(programHandle, pixelShaderHandle);
    if (geometryShaderHandle > 0)
    {
        System::AttachGLShader(programHandle, geometryShaderHandle);
    }

    if (!Link(programHandle))
    {
        System::DetachGLShader(programHandle, vertexShaderHandle);
        System::DeleteGLShader(vertexShaderHandle);
        System::DetachGLShader(programHandle, pixelShaderHandle);
        System::DeleteGLShader(pixelShaderHandle);
        if (geometryShaderHandle)
        {
            System::DetachGLShader(programHandle, geometryShaderHandle);
            System::DeleteGLShader(geometryShaderHandle);
        }
        System::DeleteGLProgram(programHandle);

        THROW_EXCEPTION(SYSTEM_TEXT("链接失败。"));
    }

    auto program = std::make_shared<VisualProgram>(programHandle, vertexShaderHandle, pixelShaderHandle, geometryShaderHandle);

    const auto reflector = program->GetReflector();
    const auto vertexShader = std::make_shared<Shader>(GraphicsObjectType::VertexShader, RendererTypes::OpenGL, reflector, ReferenceType::Vertex);
    const auto pixelShader = std::make_shared<Shader>(GraphicsObjectType::PixelShader, RendererTypes::OpenGL, reflector, ReferenceType::Pixel);

    program->SetVertexShader(vertexShader);
    program->SetPixelShader(pixelShader);
    if (geometryShaderHandle > 0)
    {
        const auto geometryShader = std::make_shared<Shader>(GraphicsObjectType::GeometryShader, RendererTypes::OpenGL, reflector, ReferenceType::Geometry);

        program->SetGeometryShader(geometryShader);
    }

    return program;
}

Rendering::GLSLProgramFactory::ComputeProgramSharedPtr Rendering::GLSLProgramFactory::CreateFromNamedSource(const std::string& computeShaderName, const std::string& computeShaderSource)
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(computeShaderName);

    if (computeShaderSource.empty())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("程序必须具有计算着色器。 "));
    }

    auto computeShaderHandle = Compile(ShaderType::Compute, computeShaderSource);
    if (computeShaderHandle == 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("编译计算着色器失败。"));
    }

    auto programHandle = System::CreateGLProgram();
    if (programHandle == 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("程序创建失败。"));
    }

    System::AttachGLShader(programHandle, computeShaderHandle);

    if (!Link(programHandle))
    {
        System::DetachGLShader(programHandle, computeShaderHandle);
        System::DeleteGLShader(computeShaderHandle);
        System::DeleteGLProgram(programHandle);
        THROW_EXCEPTION(SYSTEM_TEXT("链接失败。"));
    }

    auto program = std::make_shared<ComputeProgram>(programHandle, computeShaderHandle);
    auto reflector = program->GetReflector();
    const auto computeShader = std::make_shared<Shader>(GraphicsObjectType::ComputeShader, RendererTypes::OpenGL, reflector, ReferenceType::Compute);

    program->SetComputeShader(computeShader);

    return program;
}

Rendering::GLSLProgramFactory::OpenGLUInt Rendering::GLSLProgramFactory::Compile(ShaderType shaderType, const std::string& source)
{
    RENDERING_CLASS_IS_VALID_9;

    if (const auto handle = System::CreateGLShader(shaderType);
        0 < handle)
    {
        std::vector<std::string> glslDefines{};
        const auto size = GetDefinesSize() + 5;
        glslDefines.reserve(size);
        glslDefines.emplace_back(GetVersion() + "\n");

        glslDefines.emplace_back("#define GTE_USE_MAT_VEC 0\n");

        glslDefines.emplace_back("layout(std140, column_major) uniform;\n");
        glslDefines.emplace_back("layout(std430, column_major) buffer;\n");

        for (const auto& define : *this)
        {
            glslDefines.emplace_back("#define " + define.first + " " + define.second + "\n");
        }

        glslDefines.emplace_back(source);

        std::vector<GLchar const*> code{};
        code.reserve(glslDefines.size());
        for (const auto& define : glslDefines)
        {
            code.emplace_back(define.c_str());
        }

        System::SetGLShaderSource(handle, boost::numeric_cast<System::OpenGLSize>(code.size()), code.data(), nullptr);

        System::CompileGLShader(handle);

        if (const auto status = GetGLShader(handle, System::ShaderStatus::Compile);
            status == GL_TRUE)
        {
            return handle;
        }

        if (const auto logLength = System::GetGLShader(handle, System::ShaderAttributes::InfoLogLength);
            logLength > 0)
        {
            const auto message = System::GetGLShaderInfoLog(handle);

            THROW_EXCEPTION(SYSTEM_TEXT("编译失败:\n") + CoreTools::StringConversion::MultiByteConversionStandard(message));
        }
        else
        {
            THROW_EXCEPTION(SYSTEM_TEXT("无效信息日志长度。"));
        }
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("无法创建着色器。"));
    }
}

bool Rendering::GLSLProgramFactory::Link(OpenGLUInt programHandle)
{
    RENDERING_CLASS_IS_VALID_9;

    System::LinkGLProgram(programHandle);

    if (const auto status = System::GetGLProgram(programHandle, System::ProgramStatus::Link);
        status == GL_TRUE)
    {
        return true;
    }

    if (const auto logLength = System::GetGLProgram(programHandle, System::ProgramAttributes::InfoLogLength);
        0 < logLength)
    {
        const auto message = System::GetGLProgramInfoLog(programHandle);

        THROW_EXCEPTION(SYSTEM_TEXT("链接失败:\n") + CoreTools::StringConversion::MultiByteConversionStandard(message));
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("无效信息日志长度。"));
    }
}
