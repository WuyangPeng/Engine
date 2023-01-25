///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/14 0:15)

#include "OpenGLProgramStatusTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/OpenGL/Flags/OpenGLProgramFlags.h"
#include "System/OpenGL/Flags/OpenGLShaderFlags.h"
#include "System/OpenGL/OpenGLProgram.h"
#include "System/OpenGL/OpenGLShader.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenGLProgramStatusTesting::OpenGLProgramStatusTesting(const OStreamShared& stream)
    : ParentType{ stream },
      code{ "#version 400\n",
            "uniform PVWMatrix\n",
            "{\n",
            "     mat4 pvwMatrix;\n",
            "};\n",

            "in vec3 modelPosition;\n",

            "void main()\n",
            "{\n",
            "     gl_Position = pvwMatrix * vec4(modelPosition, 1.0f);\n",
            "}\n" }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLProgramStatusTesting)

void System::OpenGLProgramStatusTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLProgramStatusTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ProgramStatusTest);
}

void System::OpenGLProgramStatusTesting::ProgramStatusTest()
{
    const auto programHandle = CreateGLProgram();
    ASSERT_TRUE_FAILURE_THROW(IsGLProgram(programHandle), "创建GL Program失败。");

    ASSERT_NOT_THROW_EXCEPTION_1(DoProgramStatusTest, programHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(DeleteGLProgramTest, programHandle);
}

void System::OpenGLProgramStatusTesting::DoProgramStatusTest(OpenGLUInt programHandle)
{
    ASSERT_NOT_THROW_EXCEPTION_1(ProgramStatusFalseTest, programHandle);

    const auto shaderHandle = CreateGLShader(ShaderType::Vertex);

    ASSERT_NOT_THROW_EXCEPTION_2(DoCreateGLShaderTest, shaderHandle, programHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(DeleteGLShaderTest, shaderHandle);
}

void System::OpenGLProgramStatusTesting::ProgramStatusFalseTest(OpenGLUInt programHandle)
{
    ASSERT_FALSE(GetGLProgram(programHandle, ProgramStatus::Link));
    ASSERT_FALSE(GetGLProgram(programHandle, ProgramStatus::Validate));
    ASSERT_FALSE(GetGLProgram(programHandle, ProgramStatus::Delete));
}

void System::OpenGLProgramStatusTesting::ValidateGLProgramTest(OpenGLUInt programHandle)
{
    ValidateGLProgram(programHandle);
    ASSERT_TRUE(GetGLProgram(programHandle, ProgramStatus::Validate));
}

void System::OpenGLProgramStatusTesting::DoCreateGLShaderTest(OpenGLUInt shaderHandle, OpenGLUInt programHandle)
{
    SetGLShaderSource(shaderHandle, boost::numeric_cast<OpenGLSize>(code.size()), code.data(), nullptr);

    CompileGLShader(shaderHandle);

    const auto status = GetGLShader(shaderHandle, ShaderStatus::Compile);
    ASSERT_TRUE_FAILURE_THROW(status, "着色器编译错误。");

    AttachGLShader(programHandle, shaderHandle);

    LinkGLProgram(programHandle);

    ASSERT_TRUE(GetGLProgram(programHandle, ProgramStatus::Link));

    ASSERT_NOT_THROW_EXCEPTION_1(ValidateGLProgramTest, programHandle);

    ASSERT_FALSE(GetGLProgram(programHandle, ProgramStatus::Delete));
}
