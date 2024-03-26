/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 16:43)

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
    ASSERT_NOT_THROW_EXCEPTION_0(GetFrameBufferTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetFrameBuffersTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetFrameBufferContainerTest);
}

void System::OpenGLFrameBufferTesting::GetFrameBufferTest()
{
    const auto frameBuffers = GetGLGenFrameBuffers();
    ASSERT_LESS(0u, frameBuffers);

    ASSERT_NOT_THROW_EXCEPTION_1(DeleteFrameBufferTest, frameBuffers);
}

void System::OpenGLFrameBufferTesting::GetFrameBuffersTest()
{
    BufferType frameBuffers{};
    GetGLGenFrameBuffers(bufferSize, frameBuffers.data());

    ASSERT_NOT_THROW_EXCEPTION_1(DoGetFrameBuffersTest, frameBuffers);

    ASSERT_NOT_THROW_EXCEPTION_1(DeleteFrameBuffersTest, frameBuffers);
}

void System::OpenGLFrameBufferTesting::GetFrameBufferContainerTest()
{
    const auto frameBuffers = GetGLGenFrameBuffers(bufferSize);

    ASSERT_NOT_THROW_EXCEPTION_1(DoGetFrameBufferContainerTest, frameBuffers);

    SetGLDeleteFrameBuffers(bufferSize, frameBuffers.data());
}

void System::OpenGLFrameBufferTesting::DoGetFrameBuffersTest(const BufferType& buffers)
{
    for (auto buffer : buffers)
    {
        ASSERT_LESS(0u, buffer);
    }
}

void System::OpenGLFrameBufferTesting::DoGetFrameBufferContainerTest(const OpenGLUnsignedIntIntContainer& buffers)
{
    for (auto buffer : buffers)
    {
        ASSERT_LESS(0u, buffer);
    }
}