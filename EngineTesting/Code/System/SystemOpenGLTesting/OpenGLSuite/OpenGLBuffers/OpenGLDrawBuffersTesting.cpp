///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/31 14:23)

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

    ASSERT_NOT_THROW_EXCEPTION_0(OpenGLBindFrameBufferTest);
}

void System::OpenGLDrawBuffersTesting::BackDrawBuffersTest()
{
    SetGLDrawBuffers(boost::numeric_cast<OpenGLSize>(back.size()), back.data());
}

void System::OpenGLDrawBuffersTesting::OpenGLBindFrameBufferTest()
{
    const auto frameBuffers = GetGLGenFrameBuffers();
    ASSERT_LESS(0u, frameBuffers);

    ASSERT_NOT_THROW_EXCEPTION_1(DoOpenGLBindFrameBufferTest, frameBuffers);
    ASSERT_NOT_THROW_EXCEPTION_0(FrameBufferDrawBuffersTest);

    ASSERT_NOT_THROW_EXCEPTION_1(SetGLDeleteFrameBufferTest, frameBuffers);
}

void System::OpenGLDrawBuffersTesting::DoOpenGLBindFrameBufferTest(OpenGLUInt frameBuffers) noexcept
{
    SetGLBindFrameBuffer(FrameBufferType::DrawFrameBuffer, frameBuffers);
}

void System::OpenGLDrawBuffersTesting::FrameBufferDrawBuffersTest()
{
    SetGLDrawBuffers(boost::numeric_cast<OpenGLSize>(attachment.size()), attachment.data());
}
