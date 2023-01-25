///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.0 (2023/01/13 13:06)

#include "OpenGLProgramAttributesTesting.h"
#include "System/OpenGL/Flags/OpenGLProgramFlags.h"
#include "System/OpenGL/OpenGLProgram.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenGLProgramAttributesTesting::OpenGLProgramAttributesTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLProgramAttributesTesting)

void System::OpenGLProgramAttributesTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLProgramAttributesTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ProgramAttributesTest);
}

void System::OpenGLProgramAttributesTesting::ProgramAttributesTest()
{
    const auto programHandle = CreateGLProgram();
    ASSERT_TRUE_FAILURE_THROW(IsGLProgram(programHandle), "����GL Programʧ�ܡ�");

    ASSERT_NOT_THROW_EXCEPTION_1(DoProgramAttributesTest, programHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(DeleteGLProgramTest, programHandle);
}

void System::OpenGLProgramAttributesTesting::DoProgramAttributesTest(OpenGLUInt programHandle)
{
    ASSERT_EQUAL(GetGLProgram(programHandle, ProgramAttributes::InfoLogLength), 0);
    ASSERT_EQUAL(GetGLProgram(programHandle, ProgramAttributes::AttachedShaders), 0);
    ASSERT_EQUAL(GetGLProgram(programHandle, ProgramAttributes::ActiveAttributes), 0);
    ASSERT_EQUAL(GetGLProgram(programHandle, ProgramAttributes::ActiveAttributeMaxLength), 0);
    ASSERT_EQUAL(GetGLProgram(programHandle, ProgramAttributes::ActiveUniforms), 0);
    ASSERT_EQUAL(GetGLProgram(programHandle, ProgramAttributes::ActiveUniformMaxLength), 0);
}
