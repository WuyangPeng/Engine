///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/16 23:32)

#include "OpenGLBindVertexBufferTestingDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenGLBindVertexBufferTesting::OpenGLBindVertexBufferTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLBindVertexBufferTesting)

void System::OpenGLBindVertexBufferTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLBindVertexBufferTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(OpenGLBindVertexBufferTest);
}

void System::OpenGLBindVertexBufferTesting::OpenGLBindVertexBufferTest()
{
    const auto buffer = GetGLGenBuffers();
    ASSERT_LESS(0u, buffer);

    ASSERT_NOT_THROW_EXCEPTION_1(DoOpenGLBindVertexBufferTest, buffer);

    ASSERT_NOT_THROW_EXCEPTION_1(SetGLDeleteBufferTest, buffer);
}

void System::OpenGLBindVertexBufferTesting::DoOpenGLBindVertexBufferTest(OpenGLUInt buffers)
{
    const auto vertexArray = GetGLGenVertexArrays();
    ASSERT_LESS(0u, vertexArray);

    ASSERT_NOT_THROW_EXCEPTION_3(BindVertexBufferTest, vertexArray, buffers, static_cast<OpenGLBoolean>(GL_FALSE));
    ASSERT_NOT_THROW_EXCEPTION_3(BindVertexBufferTest, vertexArray, buffers, static_cast<OpenGLBoolean>(GL_TRUE));

    ASSERT_NOT_THROW_EXCEPTION_1(SetGLDeleteVertexArrayTest, vertexArray);
}

void System::OpenGLBindVertexBufferTesting::BindVertexBufferTest(OpenGLUInt vertexArray, OpenGLUInt buffers, OpenGLBoolean normalized) noexcept
{
    DoBindVertexBufferTest<OpenGLData::Short, OpenGLShort>(vertexArray, buffers, normalized);
    DoBindVertexBufferTest<OpenGLData::Int, OpenGLInt>(vertexArray, buffers, normalized);
    DoBindVertexBufferTest<OpenGLData::Float, OpenGLFloat>(vertexArray, buffers, normalized);
    DoBindVertexBufferTest<OpenGLData::Double, OpenGLDouble>(vertexArray, buffers, normalized);
    DoBindVertexBufferTest<OpenGLData::Byte, OpenGLByte>(vertexArray, buffers, normalized);
    DoBindVertexBufferTest<OpenGLData::UnsignedByte, OpenGLUByte>(vertexArray, buffers, normalized);
    DoBindVertexBufferTest<OpenGLData::UnsignedShort, OpenGLUShort>(vertexArray, buffers, normalized);
    DoBindVertexBufferTest<OpenGLData::UnsignedInt, OpenGLUInt>(vertexArray, buffers, normalized);
    DoBindVertexBufferTest<OpenGLData::HalfFloat, OpenGLHalf>(vertexArray, buffers, normalized);
 
    DoBindVertexBufferTest<OpenGLData::UnsignedInt10F11F11FRev, OpenGLUInt>(vertexArray, buffers, normalized);
}
