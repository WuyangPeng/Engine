///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 14:22)

#include "OpenGLBindFrameBufferTesting.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/OpenGLBuffers.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenGLBindFrameBufferTesting::OpenGLBindFrameBufferTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLBindFrameBufferTesting)

void System::OpenGLBindFrameBufferTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLBindFrameBufferTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(OpenGLBindFrameBufferTest);
}

void System::OpenGLBindFrameBufferTesting::OpenGLBindFrameBufferTest()
{
    const auto frameBuffers = GetGLGenFrameBuffers();
    ASSERT_LESS(0u, frameBuffers);

    ASSERT_NOT_THROW_EXCEPTION_1(DoOpenGLBindFrameBufferTest, frameBuffers);

    ASSERT_NOT_THROW_EXCEPTION_1(SetGLDeleteFrameBufferTest, frameBuffers);
}

void System::OpenGLBindFrameBufferTesting::DoOpenGLBindFrameBufferTest(OpenGLUInt frameBuffers) noexcept
{
    SetGLBindFrameBuffer(FrameBufferType::DrawFrameBuffer, frameBuffers);
    SetGLBindFrameBuffer(FrameBufferType::FrameBuffer, frameBuffers);
}
