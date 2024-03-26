/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 16:48)

#include "OpenGLTexturesParameterTesting.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/Flags/OpenGLTextureFlags.h"
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
    ASSERT_NOT_THROW_EXCEPTION_0(TexturesParameterTest);
}

void System::OpenGLTexturesParameterTesting::TexturesParameterTest()
{
    for (auto textureTarget : *this)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoTexturesParameterTest, textureTarget);
    }
}

void System::OpenGLTexturesParameterTesting::DoTexturesParameterTest(TextureTarget textureTarget) const noexcept
{
    SetGLTexturesParameter(textureTarget, TextureParameter::TextureBaseLevel, 0);
    SetGLTexturesParameter(textureTarget, TextureParameter::TextureMaxLevel, 4);
}
