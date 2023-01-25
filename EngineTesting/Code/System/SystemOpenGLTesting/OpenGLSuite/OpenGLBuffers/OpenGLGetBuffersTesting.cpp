///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/16 23:32)

#include "OpenGLGetBuffersTesting.h"
#include "System/OpenGL/OpenGLBuffers.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenGLGetBuffersTesting::OpenGLGetBuffersTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLGetBuffersTesting)

void System::OpenGLGetBuffersTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLGetBuffersTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(OpenGLGetBufferTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OpenGLGetBuffersTest);
}

void System::OpenGLGetBuffersTesting::OpenGLGetBufferTest()
{
    const auto buffer = GetGLGenBuffers();
    ASSERT_LESS(0u, buffer);

    ASSERT_NOT_THROW_EXCEPTION_1(SetGLDeleteBufferTest, buffer);
}

void System::OpenGLGetBuffersTesting::OpenGLGetBuffersTest()
{
    BufferType buffers{};

    GetGLGenBuffers(bufferSize, buffers.data());
    ASSERT_NOT_THROW_EXCEPTION_1(DoOpenGLGetBuffersTest, buffers);

    ASSERT_NOT_THROW_EXCEPTION_1(SetGLDeleteBuffersTest, buffers);
}

void System::OpenGLGetBuffersTesting::DoOpenGLGetBuffersTest(const BufferType& buffers)
{
    for (auto buffer : buffers)
    {
        ASSERT_LESS(0u, buffer);
    }
}
