/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 16:47)

#include "OpenGLGetUniformLocationTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/OpenGL/Flags/OpenGLProgramFlags.h"
#include "System/OpenGL/Flags/OpenGLShaderFlags.h"
#include "System/OpenGL/OpenGLBase.h"
#include "System/OpenGL/OpenGLProgram.h"
#include "System/OpenGL/OpenGLShader.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenGLGetUniformLocationTesting::OpenGLGetUniformLocationTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLGetUniformLocationTesting)

void System::OpenGLGetUniformLocationTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLGetUniformLocationTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GetUniformLocationTest);
}

void System::OpenGLGetUniformLocationTesting::GetUniformLocationTest()
{
    const auto programHandle = CreateGLProgram();
    ASSERT_TRUE_FAILURE_THROW(IsGLProgram(programHandle), "创建GL Program失败。");

    ASSERT_NOT_THROW_EXCEPTION_1(DoGetUniformLocationTest, programHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(DeleteProgramTest, programHandle);
}

void System::OpenGLGetUniformLocationTesting::DoGetUniformLocationTest(OpenGLUnsignedInt programHandle)
{
    const auto shaderHandle = CreateGLShader(ShaderType::Vertex);

    ASSERT_NOT_THROW_EXCEPTION_1(ShaderSourceTest, shaderHandle);

    ASSERT_NOT_THROW_EXCEPTION_2(UniformTest, shaderHandle, programHandle);
    ASSERT_NOT_THROW_EXCEPTION_1(BlockBindingTest, programHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(DeleteShaderTest, shaderHandle);
}

void System::OpenGLGetUniformLocationTesting::UniformTest(OpenGLUnsignedInt shaderHandle, OpenGLUnsignedInt programHandle)
{
    const auto uniformName = GetUniformName(shaderHandle, programHandle);

    const auto uniform = GetGLUniformLocation(programHandle, uniformName.c_str());
    ASSERT_UNEQUAL(uniform, 0);

    SetGLUniform1(uniform, 0);
}

void System::OpenGLGetUniformLocationTesting::BlockBindingTest(OpenGLUnsignedInt programHandle) const noexcept
{
    SetGLUniformBlockBinding(programHandle, 0, 0);
}

std::string System::OpenGLGetUniformLocationTesting::GetUniformName(OpenGLUnsignedInt shaderHandle, OpenGLUnsignedInt programHandle)
{
    CompileGLShader(shaderHandle);

    AttachGLShader(programHandle, shaderHandle);

    LinkGLProgram(programHandle);

    const auto numResources = GetGLProgramInterface(programHandle, ProgramInterface::Uniform, ProgramInterfaceName::ActiveResources);
    ASSERT_EQUAL(numResources, 1);

    constexpr auto properties = EnumCastUnderlying<OpenGLEnum>(ProgramProperties::NameLength);

    OpenGLInt results{ 0 };
    GetGLProgramResource(programHandle, ProgramInterface::Uniform, 0, 1, &properties, 1, nullptr, &results);

    ResultType name(results);
    GetGLProgramResourceName(programHandle, ProgramInterface::Uniform, 0, results, nullptr, name.data());

    std::string uniformName{ name.begin(), name.end() };

    return uniformName;
}
