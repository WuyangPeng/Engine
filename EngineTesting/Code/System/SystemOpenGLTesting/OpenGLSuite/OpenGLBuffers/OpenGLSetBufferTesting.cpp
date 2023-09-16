///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 14:23)

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
    ASSERT_NOT_THROW_EXCEPTION_0(SetGLBindBufferTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetGLBufferDataTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetGLBindBufferBaseTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetGLBindBufferRangeTest);
}

void System::OpenGLSetBufferTesting::SetGLBindBufferTest()
{
    const auto buffer = GetGLGenBuffers();
    ASSERT_LESS(0u, buffer);

    ASSERT_NOT_THROW_EXCEPTION_1(DoSetGLBindBufferTest, buffer);

    ASSERT_NOT_THROW_EXCEPTION_1(SetGLDeleteBufferTest, buffer);
}

void System::OpenGLSetBufferTesting::DoSetGLBindBufferTest(OpenGLUInt buffer)
{
    for (auto bindBuffer : *this)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(SetBindBufferTest, bindBuffer, buffer);
    }
}

void System::OpenGLSetBufferTesting::SetGLBufferDataTest()
{
    BufferType buffers{};

    GetGLGenBuffers(bufferSize, buffers.data());

    ASSERT_NOT_THROW_EXCEPTION_1(DoSetGLBufferDataTest, buffers);

    ASSERT_NOT_THROW_EXCEPTION_1(SetGLDeleteBuffersTest, buffers);
}

void System::OpenGLSetBufferTesting::DoSetGLBufferDataTest(const BufferType& buffers)
{
    auto index = 0;
    for (auto bindBuffer : *this)
    {
        ASSERT_NOT_THROW_EXCEPTION_3(SetBufferData, bindBuffer, buffers, index);

        ++index;
    }
}

void System::OpenGLSetBufferTesting::SetBufferData(BindBuffer bindBuffer, const BufferType& buffers, int index)
{
    SetGLBindBuffer(bindBuffer, buffers.at(index % buffers.size()));

    BufferDataType bufferData{};
    bufferData.fill(1);

    SetGLBufferData(bindBuffer, bufferDataSize, bufferData.data(), BufferUsage::Static);
    SetGLBufferData(bindBuffer, bufferDataSize, bufferData.data(), BufferUsage::Dynamic);
    SetGLBufferData(bindBuffer, bufferDataSize, bufferData.data(), BufferUsage::Stream);
}

void System::OpenGLSetBufferTesting::SetGLBindBufferBaseTest()
{
    const auto buffer = GetGLGenBuffers();
    ASSERT_LESS(0u, buffer);

    DoSetGLBindBufferBaseTest(buffer);

    ASSERT_NOT_THROW_EXCEPTION_1(SetGLDeleteBufferTest, buffer);
}

void System::OpenGLSetBufferTesting::DoSetGLBindBufferBaseTest(OpenGLUInt buffer) noexcept
{
    SetGLBindBufferBase(BindBuffer::ShaderStorageBuffer, 0, buffer);
    SetGLBindBufferBase(BindBuffer::UniformBuffer, 0, buffer);
    SetGLBindBufferBase(BindBuffer::AtomicCounterBuffer, 0, buffer);
    SetGLBindBufferBase(BindBuffer::TransformFeedbackBuffer, 0, buffer);
}

void System::OpenGLSetBufferTesting::SetGLBindBufferRangeTest()
{
    const auto buffer = GetGLGenBuffers();
    ASSERT_LESS(0u, buffer);

    DoSetGLBindBufferRangeTest(buffer);

    ASSERT_NOT_THROW_EXCEPTION_1(SetGLDeleteBufferTest, buffer);
}

void System::OpenGLSetBufferTesting::DoSetGLBindBufferRangeTest(OpenGLUInt buffer) noexcept
{
    SetGLBindBufferRange(BindBuffer::ShaderStorageBuffer, 0, buffer, 0, 4);
    SetGLBindBufferRange(BindBuffer::UniformBuffer, 0, buffer, 0, 4);
    SetGLBindBufferRange(BindBuffer::AtomicCounterBuffer, 0, buffer, 0, 4);
    SetGLBindBufferRange(BindBuffer::TransformFeedbackBuffer, 0, buffer, 0, 4);
}
