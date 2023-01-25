///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/20 13:25)

#include "OpenGLGetTexturesTesting.h"
#include "System/OpenGL/OpenGLTextures.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenGLGetTexturesTesting::OpenGLGetTexturesTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLGetTexturesTesting)

void System::OpenGLGetTexturesTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLGetTexturesTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(OpenGLGetTextureTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OpenGLGetTexturesTest);
}

void System::OpenGLGetTexturesTesting::OpenGLGetTextureTest()
{
    const auto texture = GetGLGenTextures();
    ASSERT_LESS(0u, texture);

    ASSERT_NOT_THROW_EXCEPTION_1(SetGLDeleteTextureTest, texture);
}

void System::OpenGLGetTexturesTesting::OpenGLGetTexturesTest()
{
    TexturesType textures{};

    GetGLGenTextures(bufferSize, textures.data());
    ASSERT_NOT_THROW_EXCEPTION_1(DoOpenGLGetTexturesTest, textures);

    ASSERT_NOT_THROW_EXCEPTION_1(SetGLDeleteTexturesTest, textures);
}

void System::OpenGLGetTexturesTesting::DoOpenGLGetTexturesTest(const TexturesType& textures)
{
    for (auto texture : textures)
    {
        ASSERT_LESS(0u, texture);
    }
}
