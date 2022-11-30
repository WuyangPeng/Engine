///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.4 (2022/11/04 23:53)

#include "OpenGLProgramTesting.h"
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

using std::vector;
using namespace std::literals;

System::OpenGLProgramTesting::OpenGLProgramTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLProgramTesting)

void System::OpenGLProgramTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLProgramTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateProgramTest);
    ASSERT_NOT_THROW_EXCEPTION_0(LinkTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ProgramStatusTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ProgramAttributesTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ProgramResourceTest);
}

void System::OpenGLProgramTesting::CreateProgramTest()
{
    const auto programHandle = CreateGLProgram();

    ASSERT_TRUE(IsGLProgram(programHandle));

    DeleteGLProgram(programHandle);
}

void System::OpenGLProgramTesting::LinkTest()
{
    const auto programHandle = CreateGLProgram();
    ASSERT_TRUE(IsGLProgram(programHandle));

    LinkGLProgram(programHandle);

    auto infoLog = GetGLProgramInfoLog(programHandle);

    ASSERT_TRUE(infoLog.empty());

    DeleteGLProgram(programHandle);
}

void System::OpenGLProgramTesting::ProgramStatusTest()
{
    const auto programHandle = CreateGLProgram();
    ASSERT_TRUE(IsGLProgram(programHandle));

    ASSERT_FALSE(GetGLProgram(programHandle, ProgramStatus::Link));

    const auto shaderHandle = CreateGLShader(ShaderType::Vertex);

    vector<const GLchar*> code{};
    code.emplace_back("#version 400\n");
    code.emplace_back("uniform PVWMatrix\n");
    code.emplace_back("{\n");
    code.emplace_back("     mat4 pvwMatrix;\n");
    code.emplace_back("};\n");

    code.emplace_back("in vec3 modelPosition;\n");

    code.emplace_back("void main()\n");
    code.emplace_back("{\n");
    code.emplace_back("     gl_Position = pvwMatrix * vec4(modelPosition, 1.0f);\n");
    code.emplace_back("}\n");

    GetGLShaderSource(shaderHandle, boost::numeric_cast<GLsizei>(code.size()), code.data(), nullptr);

    CompileGLShader(shaderHandle);

    const auto status = GetGLShader(shaderHandle, ShaderStatus::Compile);
    ASSERT_TRUE_FAILURE_THROW(status, "着色器编译错误。");

    AttachGLShader(programHandle, shaderHandle);

    LinkGLProgram(programHandle);

    ASSERT_TRUE(GetGLProgram(programHandle, ProgramStatus::Link));

    ValidateGLProgram(programHandle);
    ASSERT_TRUE(GetGLProgram(programHandle, ProgramStatus::Validate));

    ASSERT_FALSE(GetGLProgram(programHandle, ProgramStatus::Delete));

    DeleteGLShader(shaderHandle);
    DeleteGLProgram(programHandle);
}

void System::OpenGLProgramTesting::ProgramAttributesTest()
{
    const auto programHandle = CreateGLProgram();
    ASSERT_TRUE(IsGLProgram(programHandle));

    ASSERT_EQUAL(GetGLProgram(programHandle, ProgramAttributes::InfoLogLength), 0);

    ASSERT_EQUAL(GetGLProgram(programHandle, ProgramAttributes::AttachedShaders), 0);
    ASSERT_EQUAL(GetGLProgram(programHandle, ProgramAttributes::ActiveAttributes), 0);
    ASSERT_EQUAL(GetGLProgram(programHandle, ProgramAttributes::ActiveAttributeMaxLength), 0);
    ASSERT_EQUAL(GetGLProgram(programHandle, ProgramAttributes::ActiveUniforms), 0);
    ASSERT_EQUAL(GetGLProgram(programHandle, ProgramAttributes::ActiveUniformMaxLength), 0);

    DeleteGLProgram(programHandle);
}

void System::OpenGLProgramTesting::ProgramResourceTest()
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

    const auto numResources = GetGLProgramInterface(programHandle, ProgramInterface::ProgramInput, ProgramInterfaceName::ActiveResources);
    ASSERT_EQUAL(numResources, 2);

    const vector<OpenGLEnum> properties{ EnumCastUnderlying(ProgramProperties::NameLength),
                                         EnumCastUnderlying(ProgramProperties::Type),
                                         EnumCastUnderlying(ProgramProperties::Location),
                                         EnumCastUnderlying(ProgramProperties::ArraySize),
                                         EnumCastUnderlying(ProgramProperties::ReferencedByVertexShader),
                                         EnumCastUnderlying(ProgramProperties::ReferencedByGeometryShader),
                                         EnumCastUnderlying(ProgramProperties::ReferencedByFragmentShader),
                                         EnumCastUnderlying(ProgramProperties::ReferencedByComputeShader),
                                         EnumCastUnderlying(ProgramProperties::ReferencedByTessControlShader),
                                         EnumCastUnderlying(ProgramProperties::ReferencedByTessEvaluationShader),
                                         EnumCastUnderlying(ProgramProperties::IsPerPatch),
                                         EnumCastUnderlying(ProgramProperties::LocationComponent) };

    const auto numProperties = boost::numeric_cast<GLsizei>(properties.size());

    vector<OpenGLInt> results(properties.size(), 0);
    for (auto i = 0; i < numResources; ++i)
    {
        GetGLProgramResource(programHandle, ProgramInterface::ProgramInput, i, numProperties, properties.data(), numProperties, nullptr, results.data());

        const auto numBytes = boost::numeric_cast<GLsizei>(results.at(0));

        vector<OpenGLChar> name(numBytes);
        GetGLProgramResourceName(programHandle, ProgramInterface::ProgramInput, i, numBytes, nullptr, name.data());

        const auto index = GetGLProgramResourceIndex(programHandle, ProgramInterface::ProgramInput, name.data());
        ASSERT_EQUAL(boost::numeric_cast<int>(index), i);
    }

    DeleteGLShader(shaderHandle);
    DeleteGLProgram(programHandle);
}
