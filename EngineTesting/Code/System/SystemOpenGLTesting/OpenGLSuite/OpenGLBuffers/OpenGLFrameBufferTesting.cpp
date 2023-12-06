///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 14:23)

#include "OpenGLFrameBufferTesting.h"
#include "System/OpenGL/OpenGLBuffers.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenGLFrameBufferTesting::OpenGLFrameBufferTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLFrameBufferTesting)

void System::OpenGLFrameBufferTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLFrameBufferTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(OpenGLGetFrameBufferTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OpenGLGetFrameBuffersTest);
}

void System::OpenGLFrameBufferTesting::OpenGLGetFrameBufferTest()
{
    const auto frameBuffers = GetGLGenFrameBuffers();
    ASSERT_LESS(0u, frameBuffers);

    ASSERT_NOT_THROW_EXCEPTION_1(SetGLDeleteFrameBufferTest, frameBuffers);
}

void System::OpenGLFrameBufferTesting::OpenGLGetFrameBuffersTest()
{
    BufferType frameBuffers{};

    GetGLGenFrameBuffers(bufferSize, frameBuffers.data());
    ASSERT_NOT_THROW_EXCEPTION_1(DoOpenGLGetFrameBuffersTest, frameBuffers);

    ASSERT_NOT_THROW_EXCEPTION_1(SetGLDeleteFrameBuffersTest, frameBuffers);
}

void System::OpenGLFrameBufferTesting::DoOpenGLGetFrameBuffersTest(const BufferType& buffers)
{
    for (auto buffer : buffers)
    {
        ASSERT_LESS(0u, buffer);
    }
}
