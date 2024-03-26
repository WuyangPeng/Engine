/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 16:43)

#include "OpenGLSetBufferSubDataTesting.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/OpenGLBuffers.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenGLSetBufferSubDataTesting::OpenGLSetBufferSubDataTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLSetBufferSubDataTesting)

void System::OpenGLSetBufferSubDataTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLSetBufferSubDataTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SetBufferSubDataTest);
}

void System::OpenGLSetBufferSubDataTesting::SetBufferSubDataTest()
{
    const auto buffer = GetGLGenBuffers();
    ASSERT_LESS(0u, buffer);

    ASSERT_NOT_THROW_EXCEPTION_1(DoSetBufferSubDataTest, buffer);

    ASSERT_NOT_THROW_EXCEPTION_1(DeleteBufferTest, buffer);
}

void System::OpenGLSetBufferSubDataTesting::DoSetBufferSubDataTest(OpenGLUnsignedInt buffer)
{
    for (const auto bindBuffer : *this)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(BindBufferTest, buffer, bindBuffer);
    }
}

void System::OpenGLSetBufferSubDataTesting::BindBufferTest(OpenGLUnsignedInt buffer, BindBuffer bindBuffer)
{
    ASSERT_NOT_THROW_EXCEPTION_2(SetBindBufferTest, bindBuffer, buffer);

    ASSERT_NOT_THROW_EXCEPTION_1(GetBufferSubDataTest, bindBuffer);

    ASSERT_NOT_THROW_EXCEPTION_1(BufferSubDataTest, bindBuffer);
}

void System::OpenGLSetBufferSubDataTesting::GetBufferSubDataTest(BindBuffer bindBuffer)
{
    BufferDataType bufferData{};
    bufferData.fill(1);

    SetGLBufferData(bindBuffer, bufferDataSize, bufferData.data(), BufferUsage::Dynamic);

    BufferDataType result{};
    GetGLBufferSubData(bindBuffer, 0, bufferDataSize, result.data());

    ASSERT_EQUAL(bufferData, result);
}

void System::OpenGLSetBufferSubDataTesting::BufferSubDataTest(BindBuffer bindBuffer)
{
    BufferSubDataType subData{};
    subData.fill(2);

    SetGLBufferSubData(bindBuffer, bufferDataSize / 2, bufferDataSize / 2, subData.data());

    BufferDataType result{};
    GetGLBufferSubData(bindBuffer, 0, bufferDataSize, result.data());

    ASSERT_NOT_THROW_EXCEPTION_1(GetBufferSubDataResultTest, result);
}

void System::OpenGLSetBufferSubDataTesting::GetBufferSubDataResultTest(const BufferDataType& result)
{
    auto index = 0;
    for (auto data : result)
    {
        if (index < bufferDataSize / 2)
        {
            ASSERT_EQUAL(data, 1);
        }
        else
        {
            ASSERT_EQUAL(data, 2);
        }

        ++index;
    }
}
