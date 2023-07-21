///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:41)

#include "Rendering/RenderingExport.h"

#include "GLSLProgramFactory.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/OpenGL/Flags/OpenGLProgramFlags.h"
#include "System/OpenGL/Flags/OpenGLShaderFlags.h"
#include "System/OpenGL/OpenGLProgram.h"
#include "System/OpenGL/OpenGLShader.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Rendering/Base/Flags/GraphicsObjectType.h"
#include "Rendering/RendererEngine/Flags/RendererTypes.h"
#include "Rendering/Shaders/ComputeProgram.h"
#include "Rendering/Shaders/Reflection.h"
#include "Rendering/Shaders/Flags/ShaderAPIType.h"
#include "Rendering/Shaders/Shader.h"
#include "Rendering/Shaders/VisualProgram.h"
#include "Rendering/Shaders/Flags/ReferenceType.h"

#include <CoreTools/Contract/Flags/DisableNotThrowFlags.h>

Rendering::ProgramFactoryImpl::ProgramFactorySharedPtr Rendering::GLSLProgramFactory::Create()
{
    return std::make_shared<ClassType>(CoreTools::DisableNotThrow::Disable);
}

Rendering::GLSLProgramFactory::GLSLProgramFactory(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow)
    : ParentType{ "#version 430", "main", "main", "main", "main", 0 }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, GLSLProgramFactory)

Rendering::ShaderAPIType Rendering::GLSLProgramFactory::GetAPI() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return ShaderAPIType::GLSL;
}

Rendering::GLSLProgramFactory::VisualProgramSharedPtr Rendering::GLSLProgramFactory::CreateFromNamedSources(MAYBE_UNUSED const std::string& vsName, const std::string& vsSource, MAYBE_UNUSED const std::string& psName, const std::string& psSource, MAYBE_UNUSED const std::string& gsName, const std::string& gsSource)
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    if (vsSource.empty() || psSource.empty())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("程序必须具有顶点着色器和像素着色器。"));
    }

    auto vsHandle = Compile(ShaderType::Vertex, vsSource);
    if (vsHandle == 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("编译顶点着色器失败。"));
    }

    auto psHandle = Compile(ShaderType::Fragment, psSource);
    if (psHandle == 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("编译像素着色器失败。"));
    }

    auto gsHandle = 0;
    if (gsSource != "")
    {
        gsHandle = Compile(ShaderType::Geometry, gsSource);
        if (gsHandle == 0)
        {
            THROW_EXCEPTION(SYSTEM_TEXT("编译几何着色器失败。"));
        }
    }

    auto programHandle = System::CreateGLProgram();
    if (programHandle == 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("程序创建失败。"));
    }

    System::AttachGLShader(programHandle, vsHandle);
    System::AttachGLShader(programHandle, psHandle);
    if (gsHandle > 0)
    {
        System::AttachGLShader(programHandle, gsHandle);
    }

    if (!Link(programHandle))
    {
        System::DetachGLShader(programHandle, vsHandle);
        System::DeleteGLShader(vsHandle);
        System::DetachGLShader(programHandle, psHandle);
        System::DeleteGLShader(psHandle);
        if (gsHandle)
        {
            System::DetachGLShader(programHandle, gsHandle);
            System::DeleteGLShader(gsHandle);
        }
        System::DeleteGLProgram(programHandle);

        THROW_EXCEPTION(SYSTEM_TEXT("链接失败。"));
    }

    auto program = std::make_shared<VisualProgram>(programHandle, vsHandle, psHandle, gsHandle);

    const auto reflector = program->GetReflector();
    auto vshader = std::make_shared<Shader>(GraphicsObjectType::VertexShader, RendererTypes::OpenGL, reflector, ReferenceType::Vertex);
    auto pshader = std::make_shared<Shader>(GraphicsObjectType::PixelShader, RendererTypes::OpenGL, reflector, ReferenceType::Pixel);

    program->SetVertexShader(vshader);
    program->SetPixelShader(pshader);
    if (gsHandle > 0)
    {
        auto gshader = std::make_shared<Shader>(GraphicsObjectType::GeometryShader, RendererTypes::OpenGL, reflector, ReferenceType::Geometry);

        program->SetGeometryShader(gshader);
    }

    return program;
}

Rendering::GLSLProgramFactory::ComputeProgramSharedPtr Rendering::GLSLProgramFactory::CreateFromNamedSource(MAYBE_UNUSED const std::string& csName, const std::string& csSource)
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    if (csSource.empty())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("程序必须具有计算着色器。 "));
    }

    auto csHandle = Compile(ShaderType::Compute, csSource);
    if (csHandle == 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("编译计算着色器失败。"));
    }

    auto programHandle = System::CreateGLProgram();
    if (programHandle == 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("程序创建失败。"));
    }

    System::AttachGLShader(programHandle, csHandle);

    if (!Link(programHandle))
    {
        System::DetachGLShader(programHandle, csHandle);
        System::DeleteGLShader(csHandle);
        System::DeleteGLProgram(programHandle);
        THROW_EXCEPTION(SYSTEM_TEXT("链接失败。"));
    }

    auto program = std::make_shared<ComputeProgram>(programHandle, csHandle);
    auto reflector = program->GetReflector();
    auto cshader = std::make_shared<Shader>(GraphicsObjectType::ComputeShader, RendererTypes::OpenGL, reflector, ReferenceType::Compute);

    program->SetComputeShader(cshader);

    return program;
}

Rendering::GLSLProgramFactory::OpenGLUInt Rendering::GLSLProgramFactory::Compile(ShaderType shaderType, const std::string& source)
{
    RENDERING_CLASS_IS_VALID_9;

    const auto handle = System::CreateGLShader(shaderType);
    if (handle > 0)
    {
        std::vector<std::string> glslDefines{};
        const auto size = GetDefinesSize() + 5;
        glslDefines.reserve(size);
        glslDefines.emplace_back(GetVersion() + "\n");

        glslDefines.emplace_back("#define GTE_USE_MAT_VEC 0\n");

        glslDefines.emplace_back("layout(std140, column_major) uniform;\n");
        glslDefines.emplace_back("layout(std430, column_major) buffer;\n");

        for (const auto& d : *this)
        {
            glslDefines.emplace_back("#define " + d.first + " " + d.second + "\n");
        }

        glslDefines.emplace_back(source);

        std::vector<GLchar const*> code;
        code.reserve(glslDefines.size());
        for (auto const& d : glslDefines)
        {
            code.emplace_back(d.c_str());
        }

        System::SetGLShaderSource(handle, boost::numeric_cast<System::OpenGLSize>(code.size()), code.data(), nullptr);

        System::CompileGLShader(handle);

        const auto status = GetGLShader(handle, System::ShaderStatus::Compile);
        if (status == GL_TRUE)
        {
            return handle;
        }

        const auto logLength = System::GetGLShader(handle, System::ShaderAttributes::InfoLogLength);
        if (logLength > 0)
        {
            auto message = System::GetGLShaderInfoLog(handle);

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

    const auto status = System::GetGLProgram(programHandle, System::ProgramStatus::Link);
    if (status == GL_TRUE)
    {
        return true;
    }

    const auto logLength = System::GetGLProgram(programHandle, System::ProgramAttributes::InfoLogLength);
    if (logLength > 0)
    {
        auto message = System::GetGLProgramInfoLog(programHandle);

        THROW_EXCEPTION(SYSTEM_TEXT("链接失败:\n") + CoreTools::StringConversion::MultiByteConversionStandard(message));
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("无效信息日志长度。"));
    }
}
