///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 14:27)

#include "OpenGLBindTexturesTesting.h"
#include "System/OpenGL/OpenGLTextures.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenGLBindTexturesTesting::OpenGLBindTexturesTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLBindTexturesTesting)

void System::OpenGLBindTexturesTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLBindTexturesTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(OpenGLBindTexturesTest);
}

void System::OpenGLBindTexturesTesting::OpenGLBindTexturesTest()
{
    for (auto textureTarget : *this)
    {
        const auto texture = GetGLGenTextures();
        ASSERT_LESS(0u, texture);

        ASSERT_NOT_THROW_EXCEPTION_2(DoOpenGLBindTexturesTest, textureTarget, texture);

        ASSERT_NOT_THROW_EXCEPTION_1(SetGLDeleteTextureTest, texture);
    }
}

void System::OpenGLBindTexturesTesting::DoOpenGLBindTexturesTest(TextureTarget textureTarget, OpenGLUInt texture) noexcept
{
    SetGLBindTexture(textureTarget, texture);
}
