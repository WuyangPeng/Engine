/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 16:45)

#include "OpenGLProgramInterfaceTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/OpenGL/Flags/OpenGLShaderFlags.h"
#include "System/OpenGL/OpenGLBase.h"
#include "System/OpenGL/OpenGLProgram.h"
#include "System/OpenGL/OpenGLShader.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenGLProgramInterfaceTesting::OpenGLProgramInterfaceTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLProgramInterfaceTesting)

void System::OpenGLProgramInterfaceTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLProgramInterfaceTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ProgramResourceTest);
}

void System::OpenGLProgramInterfaceTesting::ProgramResourceTest()
{
    const auto programHandle = CreateGLProgram();
    ASSERT_TRUE_FAILURE_THROW(IsGLProgram(programHandle), "创建GL Program失败。");

    ASSERT_NOT_THROW_EXCEPTION_1(DoProgramResourceTest, programHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(DeleteGLProgramTest, programHandle);
}

void System::OpenGLProgramInterfaceTesting::DoProgramResourceTest(OpenGLUnsignedInt programHandle)
{
    const auto shaderHandle = CreateGLShader(ShaderType::Vertex);

    ASSERT_NOT_THROW_EXCEPTION_2(ShaderTest, shaderHandle, programHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(ProgramInterfaceTest, programHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(DeleteGLShaderTest, shaderHandle);
}

void System::OpenGLProgramInterfaceTesting::ShaderTest(OpenGLUnsignedInt shaderHandle, OpenGLUnsignedInt programHandle)
{
    ASSERT_NOT_THROW_EXCEPTION_1(ShaderSourceTest, shaderHandle);

    CompileGLShader(shaderHandle);

    AttachGLShader(programHandle, shaderHandle);

    LinkGLProgram(programHandle);
}

void System::OpenGLProgramInterfaceTesting::ProgramInterfaceTest(OpenGLUnsignedInt programHandle)
{
    for (auto outer = 0; outer < GetProgramInterfaceCount(); ++outer)
    {
        for (auto inner = 0; inner < GetProgramInterfaceNameCount(); ++inner)
        {
            ASSERT_NOT_THROW_EXCEPTION_3(DoProgramInterfaceTest, programHandle, outer, inner);
        }
    }
}

void System::OpenGLProgramInterfaceTesting::DoProgramInterfaceTest(System::OpenGLUnsignedInt programHandle, int outer, int inner)
{
    const auto programInterface = GetProgramInterface(outer);
    const auto programInterfaceName = GetProgramInterfaceName(inner);

    if (!IsProgramInterfaceInvalid(programInterface, programInterfaceName))
    {
        const auto numResources = GetGLProgramInterface(programHandle, programInterface, programInterfaceName);
        ASSERT_LESS_EQUAL(0, numResources);
    }
}
