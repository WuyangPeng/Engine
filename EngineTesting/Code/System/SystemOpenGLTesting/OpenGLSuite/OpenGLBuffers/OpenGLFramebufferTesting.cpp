///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/16 23:32)

#include "OpenGLFramebufferTesting.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/OpenGLBuffers.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenGLFramebufferTesting::OpenGLFramebufferTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLFramebufferTesting)

void System::OpenGLFramebufferTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLFramebufferTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(OpenGLGetFramebufferTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OpenGLGetFramebuffersTest);
}

void System::OpenGLFramebufferTesting::OpenGLGetFramebufferTest()
{
    const auto framebuffers = GetGLGenFramebuffers();
    ASSERT_LESS(0u, framebuffers);

    ASSERT_NOT_THROW_EXCEPTION_1(SetGLDeleteFramebufferTest, framebuffers);
}

void System::OpenGLFramebufferTesting::OpenGLGetFramebuffersTest()
{
    BufferType framebuffers{};

    GetGLGenFramebuffers(bufferSize, framebuffers.data());
    ASSERT_NOT_THROW_EXCEPTION_1(DoOpenGLGetFramebuffersTest, framebuffers);

    ASSERT_NOT_THROW_EXCEPTION_1(SetGLDeleteFramebuffersTest, framebuffers);
}

void System::OpenGLFramebufferTesting::DoOpenGLGetFramebuffersTest(const BufferType& buffers)
{
    for (auto buffer : buffers)
    {
        ASSERT_LESS(0u, buffer);
    }
}
