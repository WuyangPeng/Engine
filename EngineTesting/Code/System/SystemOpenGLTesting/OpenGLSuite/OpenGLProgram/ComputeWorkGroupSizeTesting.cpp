/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 16:45)

#include "ComputeWorkGroupSizeTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/OpenGL/Flags/OpenGLProgramFlags.h"
#include "System/OpenGL/Flags/OpenGLShaderFlags.h"
#include "System/OpenGL/OpenGLProgram.h"
#include "System/OpenGL/OpenGLShader.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::ComputeWorkGroupSizeTesting::ComputeWorkGroupSizeTesting(const OStreamShared& stream)
    : ParentType{ stream },
      code{ "#version 430\n",

            "layout(local_size_x = 16, local_size_y = 16) in;\n",

            "void main()\n",
            "{\n",
            "}\n" }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, ComputeWorkGroupSizeTesting)

void System::ComputeWorkGroupSizeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::ComputeWorkGroupSizeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ComputeWorkGroupSizeTest);
}

void System::ComputeWorkGroupSizeTesting::SetGLDispatchComputeTest(OpenGLUnsignedInt programHandle) const noexcept
{
    SetUseProgram(programHandle);
    SetGLDispatchCompute(1024 / 16, 1024 / 16, 1);
}

void System::ComputeWorkGroupSizeTesting::ComputeWorkGroupSizeTest()
{
    const auto programHandle = CreateGLProgram();
    ASSERT_TRUE_FAILURE_THROW(IsGLProgram(programHandle), "����GL Programʧ�ܡ�");

    const auto shaderHandle = CreateGLShader(ShaderType::Compute);

    ASSERT_NOT_THROW_EXCEPTION_2(DoCreateGLShaderTest, shaderHandle, programHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(DoComputeWorkGroupSizeTest, programHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(SetGLDispatchComputeTest, programHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(DeleteGLShaderTest, shaderHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(DeleteGLProgramTest, programHandle);
}

void System::ComputeWorkGroupSizeTesting::DoCreateGLShaderTest(OpenGLUnsignedInt shaderHandle, OpenGLUnsignedInt programHandle)
{
    SetGLShaderSource(shaderHandle, boost::numeric_cast<OpenGLSize>(code.size()), code.data(), nullptr);

    CompileGLShader(shaderHandle);

    const auto status = GetGLShader(shaderHandle, ShaderStatus::Compile);
    ASSERT_TRUE_FAILURE_THROW(status, "��ɫ���������");

    AttachGLShader(programHandle, shaderHandle);

    LinkGLProgram(programHandle);

    ValidateGLProgram(programHandle);
}

void System::ComputeWorkGroupSizeTesting::DoComputeWorkGroupSizeTest(OpenGLUnsignedInt programHandle)
{
    const auto params = GetComputeWorkGroupSize(programHandle);

    ASSERT_EQUAL(16, params.at(0));
    ASSERT_EQUAL(16, params.at(1));
    ASSERT_EQUAL(1, params.at(2));

    ComputeWorkGroupSizeType result{};
    GetGLProgram(programHandle, ProgramAttributes::ComputeWorkGroupSize, result);

    ASSERT_EQUAL(result, params);
}