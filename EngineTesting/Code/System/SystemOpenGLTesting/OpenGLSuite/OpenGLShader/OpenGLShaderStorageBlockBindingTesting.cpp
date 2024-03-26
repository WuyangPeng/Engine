/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/25 19:19)

#include "OpenGLShaderStorageBlockBindingTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/OpenGL/Flags/OpenGLProgramFlags.h"
#include "System/OpenGL/Flags/OpenGLShaderFlags.h"
#include "System/OpenGL/OpenGLBuffers.h"
#include "System/OpenGL/OpenGLProgram.h"
#include "System/OpenGL/OpenGLShader.h"
#include "System/SystemOpenGLTesting/OpenGLSuite/OpenGLBuffers/OpenGLBindVertexBufferTestingDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <iostream>

System::OpenGLShaderStorageBlockBindingTesting::OpenGLShaderStorageBlockBindingTesting(const OStreamShared& stream)
    : ParentType{ stream },
      computeShader{ "#version 430\n",

                     "layout(local_size_x = 16, local_size_y = 16, local_size_z = 1) in;\n",
                     "layout(std430, binding = 0) buffer storage\n",
                     "{\n",
                     "     int data[];\n",
                     "};\n",

                     "void main()\n",
                     "{\n",
                     "     data[0] = 1;\n",
                     "}\n" }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLShaderStorageBlockBindingTesting)

void System::OpenGLShaderStorageBlockBindingTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLShaderStorageBlockBindingTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ShaderStorageBlockBindingTest);
}

void System::OpenGLShaderStorageBlockBindingTesting::ShaderStorageBlockBindingTest()
{
    const auto programHandle = CreateGLProgram();
    ASSERT_TRUE_FAILURE_THROW(IsGLProgram(programHandle), "创建GL Program失败。");

    ASSERT_NOT_THROW_EXCEPTION_1(DoShaderStorageBlockBindingTest, programHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(DeleteProgramTest, programHandle);
}

void System::OpenGLShaderStorageBlockBindingTesting::DoShaderStorageBlockBindingTest(OpenGLUnsignedInt programHandle)
{
    const auto shaderHandle = CreateGLShader(ShaderType::Compute);

    SetGLShaderSource(shaderHandle, boost::numeric_cast<OpenGLSize>(computeShader.size()), computeShader.data(), nullptr);

    CompileGLShader(shaderHandle);

    const auto status = GetGLShader(shaderHandle, ShaderStatus::Compile);
    ASSERT_TRUE_FAILURE_THROW(status, "着色器编译错误。");

    AttachGLShader(programHandle, shaderHandle);
    LinkGLProgram(programHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(BlockBindingTest, programHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(DeleteShaderTest, shaderHandle);
}

void System::OpenGLShaderStorageBlockBindingTesting::BlockBindingTest(OpenGLUnsignedInt programHandle)
{
    const auto index = GetGLProgramResourceIndex(programHandle, ProgramInterface::ShaderStorageBlock, "storage");
    ASSERT_UNEQUAL(index, invalidGLIndex);

    SetGLShaderStorageBlockBinding(programHandle, index, 0);
}
