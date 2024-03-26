/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 16:48)

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
    ASSERT_NOT_THROW_EXCEPTION_0(GetTextureTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetTexturesTest);
}

void System::OpenGLGetTexturesTesting::GetTextureTest()
{
    const auto texture = GetGLGenTextures();
    ASSERT_LESS(0u, texture);

    ASSERT_NOT_THROW_EXCEPTION_1(DeleteTextureTest, texture);
}

void System::OpenGLGetTexturesTesting::GetTexturesTest()
{
    TexturesType textures{};

    GetGLGenTextures(bufferSize, textures.data());
    ASSERT_NOT_THROW_EXCEPTION_1(DoGetTexturesTest, textures);

    ASSERT_NOT_THROW_EXCEPTION_1(DeleteTexturesTest, textures);
}

void System::OpenGLGetTexturesTesting::DoGetTexturesTest(const TexturesType& textures)
{
    for (auto texture : textures)
    {
        ASSERT_LESS(0u, texture);
    }
}
