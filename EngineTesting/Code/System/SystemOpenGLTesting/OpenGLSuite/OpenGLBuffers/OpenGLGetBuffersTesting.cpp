/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 16:43)

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
    ASSERT_NOT_THROW_EXCEPTION_0(GetBufferTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetBuffersTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetBufferContainerTest);
}

void System::OpenGLGetBuffersTesting::GetBufferTest()
{
    const auto buffer = GetGLGenBuffers();
    ASSERT_LESS(0u, buffer);

    ASSERT_NOT_THROW_EXCEPTION_1(DeleteBufferTest, buffer);
}

void System::OpenGLGetBuffersTesting::GetBuffersTest()
{
    BufferType buffers{};
    GetGLGenBuffers(bufferSize, buffers.data());

    ASSERT_NOT_THROW_EXCEPTION_1(DoGetBuffersTest, buffers);

    ASSERT_NOT_THROW_EXCEPTION_1(DeleteBuffersTest, buffers);
}

void System::OpenGLGetBuffersTesting::GetBufferContainerTest()
{
    const auto buffers = GetGLGenBuffers(bufferSize);

    ASSERT_NOT_THROW_EXCEPTION_1(DoGetBufferContainerTest, buffers);

    SetGLDeleteBuffers(bufferSize, buffers.data());
}

void System::OpenGLGetBuffersTesting::DoGetBuffersTest(const BufferType& buffers)
{
    for (auto buffer : buffers)
    {
        ASSERT_LESS(0u, buffer);
    }
}

void System::OpenGLGetBuffersTesting::DoGetBufferContainerTest(const OpenGLUnsignedIntIntContainer& buffers)
{
    for (auto buffer : buffers)
    {
        ASSERT_LESS(0u, buffer);
    }
}
