/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 16:44)

#include "OpenGLSetBufferTesting.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/OpenGLBuffers.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenGLSetBufferTesting::OpenGLSetBufferTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLSetBufferTesting)

void System::OpenGLSetBufferTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLSetBufferTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(OpenGLSetBindBufferTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OpenGLSetBufferDataTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OpenGLSetBindBufferBaseTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OpenGLSetBindBufferRangeTest);
}

void System::OpenGLSetBufferTesting::OpenGLSetBindBufferTest()
{
    const auto buffer = GetGLGenBuffers();
    ASSERT_LESS(0u, buffer);

    ASSERT_NOT_THROW_EXCEPTION_1(DoOpenGLSetBindBufferTest, buffer);

    ASSERT_NOT_THROW_EXCEPTION_1(DeleteBufferTest, buffer);
}

void System::OpenGLSetBufferTesting::DoOpenGLSetBindBufferTest(OpenGLUnsignedInt buffer)
{
    for (auto bindBuffer : *this)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(SetBindBufferTest, bindBuffer, buffer);
    }
}

void System::OpenGLSetBufferTesting::OpenGLSetBufferDataTest()
{
    BufferType buffers{};

    GetGLGenBuffers(bufferSize, buffers.data());

    ASSERT_NOT_THROW_EXCEPTION_1(DoOpenGLSetBufferDataTest, buffers);

    ASSERT_NOT_THROW_EXCEPTION_1(DeleteBuffersTest, buffers);
}

void System::OpenGLSetBufferTesting::DoOpenGLSetBufferDataTest(const BufferType& buffers)
{
    auto index = 0;
    for (auto bindBuffer : *this)
    {
        ASSERT_NOT_THROW_EXCEPTION_3(SetBufferData, bindBuffer, buffers, index);

        ++index;
    }
}

void System::OpenGLSetBufferTesting::SetBufferData(BindBuffer bindBuffer, const BufferType& buffers, int index) const
{
    SetGLBindBuffer(bindBuffer, buffers.at(index % buffers.size()));

    BufferDataType bufferData{};
    bufferData.fill(1);

    SetGLBufferData(bindBuffer, bufferDataSize, bufferData.data(), BufferUsage::Static);
    SetGLBufferData(bindBuffer, bufferDataSize, bufferData.data(), BufferUsage::Dynamic);
    SetGLBufferData(bindBuffer, bufferDataSize, bufferData.data(), BufferUsage::Stream);
}

void System::OpenGLSetBufferTesting::OpenGLSetBindBufferBaseTest()
{
    const auto buffer = GetGLGenBuffers();
    ASSERT_LESS(0u, buffer);

    DoOpenGLSetBindBufferBaseTest(buffer);

    ASSERT_NOT_THROW_EXCEPTION_1(DeleteBufferTest, buffer);
}

void System::OpenGLSetBufferTesting::DoOpenGLSetBindBufferBaseTest(OpenGLUnsignedInt buffer) const noexcept
{
    SetGLBindBufferBase(BindBuffer::ShaderStorageBuffer, 0, buffer);
    SetGLBindBufferBase(BindBuffer::UniformBuffer, 0, buffer);
    SetGLBindBufferBase(BindBuffer::AtomicCounterBuffer, 0, buffer);
    SetGLBindBufferBase(BindBuffer::TransformFeedbackBuffer, 0, buffer);
}

void System::OpenGLSetBufferTesting::OpenGLSetBindBufferRangeTest()
{
    const auto buffer = GetGLGenBuffers();
    ASSERT_LESS(0u, buffer);

    DoOpenGLSetBindBufferRangeTest(buffer);

    ASSERT_NOT_THROW_EXCEPTION_1(DeleteBufferTest, buffer);
}

void System::OpenGLSetBufferTesting::DoOpenGLSetBindBufferRangeTest(OpenGLUnsignedInt buffer) const noexcept
{
    SetGLBindBufferRange(BindBuffer::ShaderStorageBuffer, 0, buffer, 0, 4);
    SetGLBindBufferRange(BindBuffer::UniformBuffer, 0, buffer, 0, 4);
    SetGLBindBufferRange(BindBuffer::AtomicCounterBuffer, 0, buffer, 0, 4);
    SetGLBindBufferRange(BindBuffer::TransformFeedbackBuffer, 0, buffer, 0, 4);
}
