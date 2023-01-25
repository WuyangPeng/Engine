///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/15 13:26)

#include "OpenGLCompileShaderTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/OpenGL/Flags/OpenGLProgramFlags.h"
#include "System/OpenGL/Flags/OpenGLShaderFlags.h"
#include "System/OpenGL/OpenGLShader.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenGLCompileShaderTesting::OpenGLCompileShaderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLCompileShaderTesting)

void System::OpenGLCompileShaderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLCompileShaderTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CompileShaderTest);
}

void System::OpenGLCompileShaderTesting::CompileShaderTest()
{
    const auto shaderHandle = CreateGLShader(ShaderType::Vertex);

    ASSERT_NOT_THROW_EXCEPTION_1(DoCompileShaderTest, shaderHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(DeleteShaderTest, shaderHandle);
}

void System::OpenGLCompileShaderTesting::DoCompileShaderTest(OpenGLUInt shaderHandle)
{
    ASSERT_NOT_THROW_EXCEPTION_1(ShaderSourceTest, shaderHandle);

    CompileGLShader(shaderHandle);

    const auto shaderSourceLength = GetGLShader(shaderHandle, ShaderAttributes::ShaderSourceLength);

    ResultType result(shaderSourceLength);
    GetGLShaderSource(shaderHandle, boost::numeric_cast<OpenGLSize>(result.size()), nullptr, result.data());
}
