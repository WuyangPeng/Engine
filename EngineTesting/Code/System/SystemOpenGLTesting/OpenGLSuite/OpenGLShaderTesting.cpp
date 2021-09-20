///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.6 (2021/06/28 11:25)

#include "OpenGLShaderTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/OpenGL/Flags/OpenGLProgramFlags.h"
#include "System/OpenGL/Flags/OpenGLShaderFlags.h"
#include "System/OpenGL/OpenGLAPI.h"
#include "System/OpenGL/OpenGLProgram.h"
#include "System/OpenGL/OpenGLShader.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <vector>

using std::string;
using std::vector;

System::OpenGLShaderTesting::OpenGLShaderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLShaderTesting)

void System::OpenGLShaderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLShaderTesting::MainTest() noexcept
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateShaderTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AttachShaderTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CompileShaderTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ShaderStatusTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ShaderAttributesTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetUniformLocationTest);
}

void System::OpenGLShaderTesting::CreateShaderTest()
{
    const auto shaderHandle = CreateGLShader(ShaderType::Vertex);

    ASSERT_TRUE(IsGLShader(shaderHandle));

    DeleteGLShader(shaderHandle);
}

void System::OpenGLShaderTesting::AttachShaderTest()
{
    const auto programHandle = CreateGLProgram();
    ASSERT_TRUE(IsGLProgram(programHandle));

    const auto shaderHandle = CreateGLShader(ShaderType::Vertex);
    AttachGLShader(programHandle, shaderHandle);

    OpenGLUInt shaderResult{ 0 };
    GetAttachedGLShaders(programHandle, 1, nullptr, &shaderResult);
    ASSERT_EQUAL(shaderResult, shaderHandle);

    auto infoLog = GetGLShaderInfoLog(shaderHandle);

    ASSERT_TRUE(infoLog.empty());

    DetachGLShader(programHandle, shaderHandle);

    DeleteGLShader(shaderHandle);
    DeleteGLProgram(programHandle);
}

void System::OpenGLShaderTesting::CompileShaderTest()
{
    const auto shaderHandle = CreateGLShader(ShaderType::Vertex);

    vector<const GLchar*> code{};
    code.emplace_back("#version 400\n");
    code.emplace_back("uniform PVWMatrix\n");
    code.emplace_back("{\n");
    code.emplace_back("     mat4 pvwMatrix;\n");
    code.emplace_back("};\n");

    code.emplace_back("in vec3 modelPosition;\n");
    code.emplace_back("in vec3 inPosition;\n");

    code.emplace_back("void main()\n");
    code.emplace_back("{\n");
    code.emplace_back("     gl_Position = pvwMatrix * vec4(modelPosition, 1.0f) * vec4(inPosition, 1.0f);\n");
    code.emplace_back("}\n");

    GetGLShaderSource(shaderHandle, boost::numeric_cast<GLsizei>(code.size()), code.data(), nullptr);

    CompileGLShader(shaderHandle);

    DeleteGLShader(shaderHandle);
}

void System::OpenGLShaderTesting::ShaderStatusTest()
{
    const auto shaderHandle = CreateGLShader(ShaderType::Vertex);

    vector<const GLchar*> code{};
    code.emplace_back("#version 400\n");
    code.emplace_back("uniform PVWMatrix\n");
    code.emplace_back("{\n");
    code.emplace_back("     mat4 pvwMatrix;\n");
    code.emplace_back("};\n");

    code.emplace_back("in vec3 modelPosition;\n");
    code.emplace_back("in vec3 inPosition;\n");

    code.emplace_back("void main()\n");
    code.emplace_back("{\n");
    code.emplace_back("     gl_Position = pvwMatrix * vec4(modelPosition, 1.0f) * vec4(inPosition, 1.0f);\n");
    code.emplace_back("}\n");

    GetGLShaderSource(shaderHandle, boost::numeric_cast<GLsizei>(code.size()), code.data(), nullptr);

    ASSERT_EQUAL(GetGLShader(shaderHandle, ShaderStatus::Compile), false);

    CompileGLShader(shaderHandle);

    ASSERT_EQUAL(GetGLShader(shaderHandle, ShaderStatus::Compile), true);

    ASSERT_EQUAL(GetGLShader(shaderHandle, ShaderStatus::Delete), false);

    DeleteGLShader(shaderHandle);
}

void System::OpenGLShaderTesting::ShaderAttributesTest()
{
    const auto shaderHandle = CreateGLShader(ShaderType::Vertex);

    ASSERT_EQUAL(GetGLShader(shaderHandle, ShaderAttributes::ShaderType), EnumCastUnderlying(ShaderType::Vertex));

    ASSERT_EQUAL(0, GetGLShader(shaderHandle, ShaderAttributes::ShaderSourceLength));

    vector<const GLchar*> code{};
    code.emplace_back("#version 400\n");
    code.emplace_back("uniform PVWMatrix\n");
    code.emplace_back("{\n");
    code.emplace_back("     mat4 pvwMatrix;\n");
    code.emplace_back("};\n");

    code.emplace_back("in vec3 modelPosition;\n");
    code.emplace_back("in vec3 inPosition;\n");

    code.emplace_back("void main()\n");
    code.emplace_back("{\n");
    code.emplace_back("     gl_Position = pvwMatrix * vec4(modelPosition, 1.0f) * vec4(inPosition, 1.0f);\n");
    code.emplace_back("}\n");

    GetGLShaderSource(shaderHandle, boost::numeric_cast<GLsizei>(code.size()), code.data(), nullptr);

    CompileGLShader(shaderHandle);

    ASSERT_EQUAL(GetGLShader(shaderHandle, ShaderAttributes::InfoLogLength), 0);

    ASSERT_LESS(0, GetGLShader(shaderHandle, ShaderAttributes::ShaderSourceLength));

    DeleteGLShader(shaderHandle);
}

void System::OpenGLShaderTesting::GetUniformLocationTest()
{
    const auto programHandle = CreateGLProgram();
    ASSERT_TRUE(IsGLProgram(programHandle));

    const auto shaderHandle = CreateGLShader(ShaderType::Vertex);

    vector<const GLchar*> code{};
    code.emplace_back("#version 400\n");
    code.emplace_back("uniform PVWMatrix\n");
    code.emplace_back("{\n");
    code.emplace_back("     mat4 pvwMatrix;\n");
    code.emplace_back("};\n");

    code.emplace_back("in vec3 modelPosition;\n");
    code.emplace_back("in vec3 inPosition;\n");

    code.emplace_back("void main()\n");
    code.emplace_back("{\n");
    code.emplace_back("     gl_Position = pvwMatrix * vec4(modelPosition, 1.0f) * vec4(inPosition, 1.0f);\n");
    code.emplace_back("}\n");

    GetGLShaderSource(shaderHandle, boost::numeric_cast<GLsizei>(code.size()), code.data(), nullptr);

    CompileGLShader(shaderHandle);

    AttachGLShader(programHandle, shaderHandle);

    LinkGLProgram(programHandle);

    const auto numResources = GetGLProgramInterface(programHandle, ProgramInterface::Uniform, ProgramInterfaceName::ActiveResources);
    ASSERT_EQUAL(numResources, 1);

    auto properties = EnumCastUnderlying<OpenGLEnum>(ProgramProperties::NameLength);

    OpenGLInt results{ 0 };
    GetGLProgramResource(programHandle, ProgramInterface::Uniform, 0, 1, &properties, 1, nullptr, &results);

    vector<OpenGLChar> name(results);
    GetGLProgramResourceName(programHandle, ProgramInterface::Uniform, 0, results, nullptr, name.data());

    string uniformName{ name.begin(), name.end() };

    const auto uniform = GetGLUniformLocation(programHandle, uniformName.c_str());
    ASSERT_UNEQUAL(uniform, 0);

    DeleteGLShader(shaderHandle);
    DeleteGLProgram(programHandle);
}
