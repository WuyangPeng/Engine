///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 14:25)

#include "OpenGLProgramResourceTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/OpenGL/Flags/OpenGLProgramFlags.h"
#include "System/OpenGL/Flags/OpenGLShaderFlags.h"
#include "System/OpenGL/OpenGLBase.h"
#include "System/OpenGL/OpenGLProgram.h"
#include "System/OpenGL/OpenGLShader.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenGLProgramResourceTesting::OpenGLProgramResourceTesting(const OStreamShared& stream)
    : ParentType{ stream },
      properties{ EnumCastUnderlying(ProgramProperties::NameLength),
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
                  EnumCastUnderlying(ProgramProperties::LocationComponent) }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLProgramResourceTesting)

void System::OpenGLProgramResourceTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLProgramResourceTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ProgramResourceTest);
}

void System::OpenGLProgramResourceTesting::ProgramResourceTest()
{
    const auto programHandle = CreateGLProgram();
    ASSERT_TRUE_FAILURE_THROW(IsGLProgram(programHandle), "创建GL Program失败。");

    ASSERT_NOT_THROW_EXCEPTION_1(DoProgramResourceTest, programHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(DeleteGLProgramTest, programHandle);
}

void System::OpenGLProgramResourceTesting::DoProgramResourceTest(OpenGLUInt programHandle)
{
    const auto shaderHandle = CreateGLShader(ShaderType::Vertex);

    ASSERT_NOT_THROW_EXCEPTION_2(ShaderTest, shaderHandle, programHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(ProgramPropertiesTest, programHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(DeleteGLShaderTest, shaderHandle);
}

void System::OpenGLProgramResourceTesting::ShaderTest(OpenGLUInt shaderHandle, OpenGLUInt programHandle)
{
    ASSERT_NOT_THROW_EXCEPTION_1(ShaderSourceTest, shaderHandle);

    CompileGLShader(shaderHandle);

    AttachGLShader(programHandle, shaderHandle);

    LinkGLProgram(programHandle);
}

void System::OpenGLProgramResourceTesting::ProgramPropertiesTest(OpenGLUInt programHandle)
{
    const auto numResources = GetGLProgramInterface(programHandle, ProgramInterface::ProgramInput, ProgramInterfaceName::ActiveResources);

    for (auto index = 0; index < numResources; ++index)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoProgramPropertiesTest, programHandle, index);
    }
}

void System::OpenGLProgramResourceTesting::DoProgramPropertiesTest(OpenGLUInt programHandle, int index)
{
    const auto numProperties = boost::numeric_cast<OpenGLSize>(properties.size());

    PropertiesResultType results(numProperties);

    GetGLProgramResource(programHandle, ProgramInterface::ProgramInput, index, numProperties, properties.data(), numProperties, nullptr, results.data());

    for (auto propertyIndex = 0; propertyIndex < numProperties; ++propertyIndex)
    {
        ASSERT_NOT_THROW_EXCEPTION_3(ProgramResourceNameTest, programHandle, results.at(propertyIndex), index);
    }
}

void System::OpenGLProgramResourceTesting::ProgramResourceNameTest(OpenGLUInt programHandle, int numBytes, int index)
{
    if (numBytes <= 0)
        return;

    ResourceNameType name(numBytes);
    GetGLProgramResourceName(programHandle, ProgramInterface::ProgramInput, index, boost::numeric_cast<GLsizei>(numBytes), nullptr, name.data());

    if (name.empty() || (name.size() == 1 && name.at(0) == '\0'))
    {
        return;
    }

    const auto resourceIndex = GetGLProgramResourceIndex(programHandle, ProgramInterface::ProgramInput, name.data());
    ASSERT_EQUAL(boost::numeric_cast<int>(resourceIndex), index);
}
