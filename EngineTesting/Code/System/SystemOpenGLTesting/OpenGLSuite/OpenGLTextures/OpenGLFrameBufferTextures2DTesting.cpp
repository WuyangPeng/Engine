/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 16:48)

#include "OpenGLFrameBufferTextures2DTesting.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/Flags/OpenGLTextureFlags.h"
#include "System/OpenGL/OpenGLBuffers.h"
#include "System/OpenGL/OpenGLTextures.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenGLFrameBufferTextures2DTesting::OpenGLFrameBufferTextures2DTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLFrameBufferTextures2DTesting)

void System::OpenGLFrameBufferTextures2DTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLFrameBufferTextures2DTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_1(FrameBufferTextures2DTest, FrameBufferType::DrawFrameBuffer);
    ASSERT_NOT_THROW_EXCEPTION_1(FrameBufferTextures2DTest, FrameBufferType::FrameBuffer);
}

void System::OpenGLFrameBufferTextures2DTesting::FrameBufferTextures2DTest(FrameBufferType frameBufferType)
{
    const auto frameBuffers = GetGLGenFrameBuffers();
    ASSERT_LESS(0u, frameBuffers);

    ASSERT_NOT_THROW_EXCEPTION_2(DoFrameBufferTextures2DTest, frameBufferType, frameBuffers);

    ASSERT_NOT_THROW_EXCEPTION_1(DeleteFrameBufferTest, frameBuffers);
}

void System::OpenGLFrameBufferTextures2DTesting::DeleteFrameBufferTest(OpenGLUnsignedInt buffer) const noexcept
{
    SetGLDeleteFrameBuffers(buffer);
}

void System::OpenGLFrameBufferTextures2DTesting::DoFrameBufferTextures2DTest(FrameBufferType frameBufferType, OpenGLInt frameBuffers)
{
    SetGLBindFrameBuffer(frameBufferType, frameBuffers);

    const auto texture = GetGLGenTextures();
    ASSERT_LESS(0u, texture);

    ASSERT_NOT_THROW_EXCEPTION_2(FrameBufferTexturesTest, frameBufferType, texture);

    ASSERT_NOT_THROW_EXCEPTION_1(DeleteTextureTest, texture);
}

void System::OpenGLFrameBufferTextures2DTesting::FrameBufferTexturesTest(FrameBufferType frameBufferType, OpenGLInt texture) const noexcept
{
    SetGLBindTexture(TextureTarget::Texture2D, texture);

    SetGLFrameBufferTexture2D(frameBufferType, ColorAttachment::Color0, TextureTarget::Texture2D, texture, 1);
}
