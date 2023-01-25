///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/14 15:58)

#include "OpenGLProgramInterfaceTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/OpenGL/Flags/OpenGLProgramFlags.h"
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

void System::OpenGLProgramInterfaceTesting::DoProgramResourceTest(OpenGLUInt programHandle)
{
    const auto shaderHandle = CreateGLShader(ShaderType::Vertex);

    ASSERT_NOT_THROW_EXCEPTION_2(ShaderTest, shaderHandle, programHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(ProgramInterfaceTest, programHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(DeleteGLShaderTest, shaderHandle);
}

void System::OpenGLProgramInterfaceTesting::ShaderTest(OpenGLUInt shaderHandle, OpenGLUInt programHandle)
{
    ASSERT_NOT_THROW_EXCEPTION_1(ShaderSourceTest, shaderHandle);

    CompileGLShader(shaderHandle);

    AttachGLShader(programHandle, shaderHandle);

    LinkGLProgram(programHandle);
}

void System::OpenGLProgramInterfaceTesting::ProgramInterfaceTest(OpenGLUInt programHandle)
{
    for (auto outer = 0u; outer < GetProgramInterfaceCount(); ++outer)
    {
        for (auto inner = 0u; inner < GetProgramInterfaceNameCount(); ++inner)
        {
            const auto programInterface = GetProgramInterface(outer);
            const auto programInterfaceName = GetProgramInterfaceName(inner);

            if (IsProgramInterfaceInvalid(programInterface, programInterfaceName))
                continue;

            const auto numResources = GetGLProgramInterface(programHandle, programInterface, programInterfaceName);
            ASSERT_LESS_EQUAL(0, numResources);
        }
    }
}
