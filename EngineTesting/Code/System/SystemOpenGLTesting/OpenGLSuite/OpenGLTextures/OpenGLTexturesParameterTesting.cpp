///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 14:28)

#include "OpenGLTexturesParameterTesting.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/OpenGLTextures.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenGLTexturesParameterTesting::OpenGLTexturesParameterTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLTexturesParameterTesting)

void System::OpenGLTexturesParameterTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLTexturesParameterTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(OpenGLTexturesParameterTest);
}

void System::OpenGLTexturesParameterTesting::OpenGLTexturesParameterTest()
{
    for (auto textureTarget : *this)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoOpenGLTexturesParameterTest, textureTarget);
    }
}

void System::OpenGLTexturesParameterTesting::DoOpenGLTexturesParameterTest(TextureTarget textureTarget) noexcept
{
    SetGLTexturesParameter(textureTarget, TextureParameter::TextureBaseLevel, 0);
    SetGLTexturesParameter(textureTarget, TextureParameter::TextureMaxLevel, 4);
}
