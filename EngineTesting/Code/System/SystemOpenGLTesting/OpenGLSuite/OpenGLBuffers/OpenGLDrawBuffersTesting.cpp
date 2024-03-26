/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 16:43)

#include "OpenGLDrawBuffersTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/OpenGLBuffers.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenGLDrawBuffersTesting::OpenGLDrawBuffersTesting(const OStreamShared& stream)
    : ParentType{ stream },
      back{ EnumCastUnderlying(ColorAttachment::Back) },
      attachment{ EnumCastUnderlying(ColorAttachment::Color0) }
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

    ASSERT_NOT_THROW_EXCEPTION_0(BindFrameBufferTest);
}

void System::OpenGLDrawBuffersTesting::BackDrawBuffersTest() const
{
    SetGLDrawBuffers(back);
}

void System::OpenGLDrawBuffersTesting::BindFrameBufferTest()
{
    const auto frameBuffers = GetGLGenFrameBuffers();
    ASSERT_LESS(0u, frameBuffers);

    ASSERT_NOT_THROW_EXCEPTION_1(DoBindFrameBufferTest, frameBuffers);
    ASSERT_NOT_THROW_EXCEPTION_0(FrameBufferDrawBuffersTest);

    ASSERT_NOT_THROW_EXCEPTION_1(DeleteFrameBufferTest, frameBuffers);
}

void System::OpenGLDrawBuffersTesting::DoBindFrameBufferTest(OpenGLUnsignedInt frameBuffers) const noexcept
{
    SetGLBindFrameBuffer(FrameBufferType::DrawFrameBuffer, frameBuffers);
}

void System::OpenGLDrawBuffersTesting::FrameBufferDrawBuffersTest() const
{
    SetGLDrawBuffers(boost::numeric_cast<OpenGLSize>(attachment.size()), attachment.data());
}
