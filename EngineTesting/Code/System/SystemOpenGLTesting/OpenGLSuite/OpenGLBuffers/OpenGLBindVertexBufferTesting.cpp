/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 16:43)

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

    ASSERT_NOT_THROW_EXCEPTION_1(DeleteBufferTest, buffer);
}

void System::OpenGLBindVertexBufferTesting::DoOpenGLBindVertexBufferTest(OpenGLUnsignedInt buffers)
{
    const auto vertexArray = GetGLGenVertexArrays();
    ASSERT_LESS(0u, vertexArray);

    ASSERT_NOT_THROW_EXCEPTION_3(BindVertexBufferTest, vertexArray, buffers, false);
    ASSERT_NOT_THROW_EXCEPTION_3(BindVertexBufferTest, vertexArray, buffers, true);

    ASSERT_NOT_THROW_EXCEPTION_1(DeleteVertexArrayTest, vertexArray);
}

void System::OpenGLBindVertexBufferTesting::BindVertexBufferTest(OpenGLUnsignedInt vertexArray, OpenGLUnsignedInt buffers, bool normalized) const noexcept
{
    DoBindVertexBufferTest<OpenGLData::Short, OpenGLShort>(vertexArray, buffers, normalized);
    DoBindVertexBufferTest<OpenGLData::Int, OpenGLInt>(vertexArray, buffers, normalized);
    DoBindVertexBufferTest<OpenGLData::Float, OpenGLFloat>(vertexArray, buffers, normalized);
    DoBindVertexBufferTest<OpenGLData::Double, OpenGLDouble>(vertexArray, buffers, normalized);
    DoBindVertexBufferTest<OpenGLData::Byte, OpenGLByte>(vertexArray, buffers, normalized);
    DoBindVertexBufferTest<OpenGLData::UnsignedByte, OpenGLUnsignedByte>(vertexArray, buffers, normalized);
    DoBindVertexBufferTest<OpenGLData::UnsignedShort, OpenGLUnsignedShort>(vertexArray, buffers, normalized);
    DoBindVertexBufferTest<OpenGLData::UnsignedInt, OpenGLUnsignedInt>(vertexArray, buffers, normalized);
    DoBindVertexBufferTest<OpenGLData::HalfFloat, OpenGLHalf>(vertexArray, buffers, normalized);

    DoBindVertexBufferTest<OpenGLData::UnsignedInt10F11F11FRev, OpenGLUnsignedInt>(vertexArray, buffers, normalized);
}
