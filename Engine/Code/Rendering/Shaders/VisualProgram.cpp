/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/26 15:19)

#include "Rendering/RenderingExport.h"

#include "VisualProgram.h"
#include "Detail/VisualProgramImpl.h"
#include "System/OpenGL/Flags/OpenGLShaderFlags.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/Shaders/Reflection.h"

COPY_UNSHARED_CLONE_SELF_USE_CLONE_DEFINE(Rendering, VisualProgram)

Rendering::VisualProgram Rendering::VisualProgram::Create()
{
    return VisualProgram{ CoreTools::DisableNotThrow::Disable };
}

Rendering::VisualProgram::VisualProgramSharedPtr Rendering::VisualProgram::Create(const std::string& vertexShaderSource, const std::string& pixelShaderSource, const std::string& geometryShaderSource, const std::string& version, const ProgramDefines& defines)
{
    if (vertexShaderSource.empty() || pixelShaderSource.empty())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("程序必须具有顶点着色器和像素着色器。"))
    }

    const auto programHandle = GLSLProgramHandle::Create();

    GLSLShaderHandle vertexShaderHandle{ System::ShaderType::Vertex, vertexShaderSource, version, defines, programHandle.GetProgramHandle(), SYSTEM_TEXT("编译顶点着色器失败。") };
    GLSLShaderHandle pixelShaderHandle{ System::ShaderType::Fragment, pixelShaderSource, version, defines, programHandle.GetProgramHandle(), SYSTEM_TEXT("编译像素着色器失败。") };
    const auto geometryShaderHandle = !geometryShaderSource.empty() ? GLSLShaderHandle{ System::ShaderType::Geometry, geometryShaderSource, version, defines, programHandle.GetProgramHandle(), SYSTEM_TEXT("编译几何着色器失败。") } : GLSLShaderHandle{};

    programHandle.Link();

    const auto program = std::make_shared<VisualProgram>(programHandle, vertexShaderHandle, pixelShaderHandle, geometryShaderHandle);
    program->CreateShader(geometryShaderHandle.IsShader());

    return program;
}

Rendering::VisualProgram::VisualProgram(CoreTools::DisableNotThrow disableNotThrow)
    : impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    System::UnusedFunction(disableNotThrow);

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::VisualProgram::VisualProgram(const GLSLProgramHandle& programHandle, const GLSLShaderHandle& vertexShaderHandle, const GLSLShaderHandle& pixelShaderHandle, const GLSLShaderHandle& geometryShaderHandle)
    : impl{ CoreTools::ImplCreateUseFactory::Default, programHandle, vertexShaderHandle, pixelShaderHandle, geometryShaderHandle }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, VisualProgram)

Rendering::VisualProgram::ConstShaderSharedPtr Rendering::VisualProgram::GetVertexShader() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetVertexShader();
}

Rendering::VisualProgram::ConstShaderSharedPtr Rendering::VisualProgram::GetPixelShader() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetPixelShader();
}

Rendering::VisualProgram::ConstShaderSharedPtr Rendering::VisualProgram::GetGeometryShader() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetGeometryShader();
}

Rendering::VisualProgram::ShaderSharedPtr Rendering::VisualProgram::GetVertexShader() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->GetVertexShader();
}

Rendering::VisualProgram::ShaderSharedPtr Rendering::VisualProgram::GetPixelShader() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->GetPixelShader();
}

Rendering::VisualProgram::ShaderSharedPtr Rendering::VisualProgram::GetGeometryShader() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->GetGeometryShader();
}

void Rendering::VisualProgram::SetVertexShader(const ShaderSharedPtr& shader)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetVertexShader(shader);
}

void Rendering::VisualProgram::SetPixelShader(const ShaderSharedPtr& shader)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetPixelShader(shader);
}

void Rendering::VisualProgram::SetGeometryShader(const ShaderSharedPtr& shader)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetGeometryShader(shader);
}

Rendering::VisualProgram::ObjectSharedPtr Rendering::VisualProgram::GetObjectByName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->GetObjectByName(name);
}

Rendering::VisualProgram::ObjectSharedPtrContainer Rendering::VisualProgram::GetAllObjectsByName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->GetAllObjectsByName(name);
}

Rendering::VisualProgram::ConstObjectSharedPtr Rendering::VisualProgram::GetConstObjectByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetConstObjectByName(name);
}

Rendering::VisualProgram::ConstObjectSharedPtrContainer Rendering::VisualProgram::GetAllConstObjectsByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetAllConstObjectsByName(name);
}

int Rendering::VisualProgram::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetStreamingSize();
}

void Rendering::VisualProgram::Save(BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->Save(target);
}

void Rendering::VisualProgram::Load(BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->Load(source);
}

void Rendering::VisualProgram::Link(ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->Link(source);
}

void Rendering::VisualProgram::Register(ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->Register(target);
}

Rendering::Reflection Rendering::VisualProgram::GetReflector() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetReflector();
}

Rendering::VisualProgram::OpenGLUInt Rendering::VisualProgram::GetProgramHandle() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetProgramHandle();
}

void Rendering::VisualProgram::CreateShader(bool createGeometryShader)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->CreateShader(createGeometryShader);
}

void Rendering::VisualProgram::CreateVertexShader()
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->CreateVertexShader();
}

void Rendering::VisualProgram::CreatePixelShader()
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->CreatePixelShader();
}

void Rendering::VisualProgram::CreateGeometryShader()
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->CreateGeometryShader();
}
