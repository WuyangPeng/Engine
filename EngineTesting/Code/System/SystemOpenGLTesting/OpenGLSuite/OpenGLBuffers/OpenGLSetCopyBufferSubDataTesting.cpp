///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 14:24)

#include "OpenGLSetCopyBufferSubDataTesting.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/OpenGLBuffers.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenGLSetCopyBufferSubDataTesting::OpenGLSetCopyBufferSubDataTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLSetCopyBufferSubDataTesting)

void System::OpenGLSetCopyBufferSubDataTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLSetCopyBufferSubDataTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(RandomShuffle);
    ASSERT_NOT_THROW_EXCEPTION_0(SetGLCopyBufferSubDataTest);
}

void System::OpenGLSetCopyBufferSubDataTesting::GetBufferSubDataTest(BindBuffer bindBuffer)
{
    const BufferDataType bufferData{};
    SetGLBufferData(bindBuffer, bufferDataSize, bufferData.data(), BufferUsage::Dynamic);

    BufferDataType result{};
    GetGLBufferSubData(bindBuffer, 0, bufferDataSize, result.data());

    ASSERT_EQUAL(bufferData, result);
}

void System::OpenGLSetCopyBufferSubDataTesting::SetGLCopyBufferSubDataTest()
{
    BufferType buffers{};

    GetGLGenBuffers(bufferSize, buffers.data());

    ASSERT_NOT_THROW_EXCEPTION_1(DoSetGLCopyBufferSubDataTest, buffers);

    ASSERT_NOT_THROW_EXCEPTION_1(SetGLDeleteBuffersTest, buffers);
}

void System::OpenGLSetCopyBufferSubDataTesting::DoSetGLCopyBufferSubDataTest(BufferType buffers)
{
    for (auto index = 0u; index < GetSubDataBindBufferSize(); ++index)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(SetBindBufferTest, GetSubDataBindBuffer(index), buffers.at(index));

        ASSERT_NOT_THROW_EXCEPTION_1(GetBufferSubDataTest, GetSubDataBindBuffer(index));
    }

    for (auto index = 0u; index < GetSubDataBindBufferSize(); ++index)
    {
        const auto nextIndex = index + 1;

        ASSERT_NOT_THROW_EXCEPTION_2(CopyBufferSubDataTest, GetSubDataBindBuffer(index), GetSubDataBindBuffer(nextIndex));
    }
}

void System::OpenGLSetCopyBufferSubDataTesting::CopyBufferSubDataTest(BindBuffer readTarget, BindBuffer writeTarget)
{
    BufferDataType subData{};
    subData.fill(3);

    SetGLBufferSubData(readTarget, 0, bufferDataSize, subData.data());

    SetGLCopyBufferSubData(readTarget, writeTarget, 0, 0, bufferDataSize);

    BufferDataType result{};
    GetGLBufferSubData(writeTarget, 0, bufferDataSize, result.data());

    ASSERT_EQUAL(subData, result);
}
