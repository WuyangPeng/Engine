///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/20 15:41)

#include "OpenGLFramebufferTextures2DTesting.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/OpenGLBuffers.h"
#include "System/OpenGL/OpenGLTextures.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenGLFramebufferTextures2DTesting::OpenGLFramebufferTextures2DTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLFramebufferTextures2DTesting)

void System::OpenGLFramebufferTextures2DTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLFramebufferTextures2DTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_1(OpenGLFramebufferTextures2DTest, FrameBufferType::DrawFramebuffer);
    ASSERT_NOT_THROW_EXCEPTION_1(OpenGLFramebufferTextures2DTest, FrameBufferType::Framebuffer);
}

void System::OpenGLFramebufferTextures2DTesting::OpenGLFramebufferTextures2DTest(FrameBufferType frameBufferType)
{
    const auto framebuffers = GetGLGenFramebuffers();
    ASSERT_LESS(0u, framebuffers);

    ASSERT_NOT_THROW_EXCEPTION_2(DoOpenGLFramebufferTextures2DTest, frameBufferType, framebuffers);

    ASSERT_NOT_THROW_EXCEPTION_1(SetGLDeleteFramebufferTest, framebuffers);
}

void System::OpenGLFramebufferTextures2DTesting::SetGLDeleteFramebufferTest(OpenGLUInt buffer) noexcept
{
    SetGLDeleteFramebuffers(buffer);
}

void System::OpenGLFramebufferTextures2DTesting::DoOpenGLFramebufferTextures2DTest(FrameBufferType frameBufferType, OpenGLInt framebuffers)
{
    SetGLBindFramebuffer(frameBufferType, framebuffers);

    const auto texture = GetGLGenTextures();
    ASSERT_LESS(0u, texture);

    ASSERT_NOT_THROW_EXCEPTION_2(FramebufferTexturesTest, frameBufferType, texture);

    ASSERT_NOT_THROW_EXCEPTION_1(SetGLDeleteTextureTest, texture);
}

void System::OpenGLFramebufferTextures2DTesting::FramebufferTexturesTest(FrameBufferType frameBufferType, OpenGLInt texture) noexcept
{
    SetGLBindTexture(TextureTarget::Texture2D, texture);

    SetGLFramebufferTexture2D(frameBufferType, ColorAttachent::Color0, TextureTarget::Texture2D, texture, 1);
}
