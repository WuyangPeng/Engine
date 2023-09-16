///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 14:27)

#include "OpenGLShaderAttributesTesting.h"
#include "System/OpenGL/Flags/OpenGLShaderFlags.h"
#include "System/OpenGL/OpenGLShader.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenGLShaderAttributesTesting::OpenGLShaderAttributesTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLShaderAttributesTesting)

void System::OpenGLShaderAttributesTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLShaderAttributesTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ShaderAttributesTest);
}

void System::OpenGLShaderAttributesTesting::ShaderAttributesTest()
{
    const auto shaderHandle = CreateGLShader(ShaderType::Vertex);

    ASSERT_NOT_THROW_EXCEPTION_1(DoShaderAttributesTest, shaderHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(DeleteShaderTest, shaderHandle);
}

void System::OpenGLShaderAttributesTesting::DoShaderAttributesTest(OpenGLUInt shaderHandle)
{
    ASSERT_EQUAL(GetGLShader(shaderHandle, ShaderAttributes::ShaderType), EnumCastUnderlying(ShaderType::Vertex));

    ASSERT_EQUAL(0, GetGLShader(shaderHandle, ShaderAttributes::ShaderSourceLength));

    ASSERT_NOT_THROW_EXCEPTION_1(ShaderSourceTest, shaderHandle);

    CompileGLShader(shaderHandle);

    ASSERT_EQUAL(GetGLShader(shaderHandle, ShaderAttributes::InfoLogLength), 0);

    ASSERT_LESS(0, GetGLShader(shaderHandle, ShaderAttributes::ShaderSourceLength));
}
