///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.0 (2023/01/16 23:32)

#include "OpenGLBindFramebufferTesting.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/OpenGLBuffers.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenGLBindFramebufferTesting::OpenGLBindFramebufferTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLBindFramebufferTesting)

void System::OpenGLBindFramebufferTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLBindFramebufferTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(OpenGLBindFramebufferTest);
}

void System::OpenGLBindFramebufferTesting::OpenGLBindFramebufferTest()
{
    const auto framebuffers = GetGLGenFramebuffers();
    ASSERT_LESS(0u, framebuffers);

    ASSERT_NOT_THROW_EXCEPTION_1(DoOpenGLBindFramebufferTest, framebuffers);

    ASSERT_NOT_THROW_EXCEPTION_1(SetGLDeleteFramebufferTest, framebuffers);
}

void System::OpenGLBindFramebufferTesting::DoOpenGLBindFramebufferTest(OpenGLUInt framebuffers) noexcept
{
    SetGLBindFramebuffer(FrameBufferType::DrawFramebuffer, framebuffers);
    SetGLBindFramebuffer(FrameBufferType::Framebuffer, framebuffers);
}
