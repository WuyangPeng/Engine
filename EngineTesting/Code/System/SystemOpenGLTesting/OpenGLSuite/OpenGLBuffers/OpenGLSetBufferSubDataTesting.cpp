///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/18 0:50)

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
    ASSERT_NOT_THROW_EXCEPTION_0(SetGLBindBufferTest);
}

void System::OpenGLSetBufferSubDataTesting::SetGLBindBufferTest()
{
    const auto buffer = GetGLGenBuffers();
    ASSERT_LESS(0u, buffer);

    ASSERT_NOT_THROW_EXCEPTION_1(DoSetGLBindBufferTest, buffer);

    ASSERT_NOT_THROW_EXCEPTION_1(SetGLDeleteBufferTest, buffer);
}

void System::OpenGLSetBufferSubDataTesting::DoSetGLBindBufferTest(OpenGLUInt buffer)
{
    for (auto bindBuffer : *this)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(SetBindBufferTest, bindBuffer, buffer);

        ASSERT_NOT_THROW_EXCEPTION_1(GetBufferSubDataTest, bindBuffer);

        ASSERT_NOT_THROW_EXCEPTION_1(SetGLBufferSubDataTest, bindBuffer);
    }
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

void System::OpenGLSetBufferSubDataTesting::SetGLBufferSubDataTest(BindBuffer bindBuffer)
{
    BufferSubDataType subData{};
    subData.fill(2);

    SetGLBufferSubData(bindBuffer, bufferDataSize / 2, bufferDataSize / 2, subData.data());

    BufferDataType result{};
    GetGLBufferSubData(bindBuffer, 0, bufferDataSize, result.data());

    ASSERT_NOT_THROW_EXCEPTION_1(GetGLBufferSubDataResultTest, result);
}

void System::OpenGLSetBufferSubDataTesting::GetGLBufferSubDataResultTest(const BufferDataType& result)
{
    auto index = 0;
    for (auto data : result)
    {
        if (index < bufferDataSize / 2)
            ASSERT_EQUAL(data, 1);
        else
            ASSERT_EQUAL(data, 2);

        ++index;
    }
}
