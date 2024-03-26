/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/16 17:28)

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
    ASSERT_NOT_THROW_EXCEPTION_0(BindTexturesTest);
}

void System::OpenGLBindTexturesTesting::BindTexturesTest()
{
    for (const auto textureTarget : *this)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoBindTexturesTest, textureTarget);
    }
}

void System::OpenGLBindTexturesTesting::DoBindTexturesTest(TextureTarget textureTarget)
{
    const auto texture = GetGLGenTextures();
    ASSERT_LESS(0u, texture);

    ASSERT_NOT_THROW_EXCEPTION_2(SetBindTexturesTest, textureTarget, texture);

    ASSERT_NOT_THROW_EXCEPTION_1(DeleteTextureTest, texture);
}

void System::OpenGLBindTexturesTesting::SetBindTexturesTest(TextureTarget textureTarget, OpenGLUnsignedInt texture) const noexcept
{
    SetGLBindTexture(textureTarget, texture);
}
