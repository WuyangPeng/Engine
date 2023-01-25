///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/16 23:32)

#include "OpenGLDrawBuffersTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/OpenGLBuffers.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenGLDrawBuffersTesting::OpenGLDrawBuffersTesting(const OStreamShared& stream)
    : ParentType{ stream },
      back{ EnumCastUnderlying(ColorAttachent::Back) },
      attachment{ EnumCastUnderlying(ColorAttachent::Color0) }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLDrawBuffersTesting)

void System::OpenGLDrawBuffersTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLDrawBuffersTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BackDrawBuffersTest);

    ASSERT_NOT_THROW_EXCEPTION_0(OpenGLBindFramebufferTest);
}

void System::OpenGLDrawBuffersTesting::BackDrawBuffersTest()
{
    SetGLDrawBuffers(boost::numeric_cast<OpenGLSize>(back.size()), back.data());
}

void System::OpenGLDrawBuffersTesting::OpenGLBindFramebufferTest()
{
    const auto framebuffers = GetGLGenFramebuffers();
    ASSERT_LESS(0u, framebuffers);

    ASSERT_NOT_THROW_EXCEPTION_1(DoOpenGLBindFramebufferTest, framebuffers);
    ASSERT_NOT_THROW_EXCEPTION_0(FramebufferDrawBuffersTest);

    ASSERT_NOT_THROW_EXCEPTION_1(SetGLDeleteFramebufferTest, framebuffers);
}

void System::OpenGLDrawBuffersTesting::DoOpenGLBindFramebufferTest(OpenGLUInt framebuffers) noexcept
{
    SetGLBindFramebuffer(FrameBufferType::DrawFramebuffer, framebuffers);
}

void System::OpenGLDrawBuffersTesting::FramebufferDrawBuffersTest()
{
    SetGLDrawBuffers(boost::numeric_cast<OpenGLSize>(attachment.size()), attachment.data());
}
