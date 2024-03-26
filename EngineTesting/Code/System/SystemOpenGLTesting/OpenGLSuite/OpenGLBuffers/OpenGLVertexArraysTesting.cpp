/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 16:44)

#include "OpenGLBindVertexBufferTestingDetail.h"
#include "OpenGLVertexArraysTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/OpenGL/OpenGLBuffers.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenGLVertexArraysTesting::OpenGLVertexArraysTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLVertexArraysTesting)

void System::OpenGLVertexArraysTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLVertexArraysTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(VertexArrayTest);
    ASSERT_NOT_THROW_EXCEPTION_0(VertexArraysTest);
    ASSERT_NOT_THROW_EXCEPTION_0(VertexArrayContainerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(BindBufferTest);
}

void System::OpenGLVertexArraysTesting::VertexArrayTest()
{
    const auto vertexArray = GetGLGenVertexArrays();
    ASSERT_LESS(0u, vertexArray);

    SetGLBindVertexArray(vertexArray);

    ASSERT_NOT_THROW_EXCEPTION_1(DeleteVertexArrayTest, vertexArray);
}

void System::OpenGLVertexArraysTesting::VertexArraysTest()
{
    BufferType vertexArrays{};
    GetGLGenVertexArrays(bufferSize, vertexArrays.data());

    ASSERT_NOT_THROW_EXCEPTION_1(BufferValidTest, vertexArrays);

    ASSERT_NOT_THROW_EXCEPTION_1(DeleteVertexArraysTest, vertexArrays);
}

void System::OpenGLVertexArraysTesting::VertexArrayContainerTest()
{
    const auto vertexArrays = GetGLGenVertexArrays(bufferSize);

    ASSERT_NOT_THROW_EXCEPTION_1(BufferContainerValidTest, vertexArrays);

    SetGLDeleteVertexArrays(bufferSize, vertexArrays.data());
}

void System::OpenGLVertexArraysTesting::BufferValidTest(const BufferType& buffers)
{
    for (auto buffer : buffers)
    {
        ASSERT_LESS(0u, buffer);
    }
}

void System::OpenGLVertexArraysTesting::BufferContainerValidTest(const OpenGLUnsignedIntIntContainer& buffers)
{
    for (auto buffer : buffers)
    {
        ASSERT_LESS(0u, buffer);
    }
}

void System::OpenGLVertexArraysTesting::BindBufferTest() const
{
    const OpenGLFloatContainer vertices{ -10.5f, -10.5f, 0.0f, 10.5f, -10.5f, 0.0f, 0.0f, 10.5f, 0.0f };

    const auto vertexHandler = GetGLGenVertexArrays();
    SetGLBindVertexArray(vertexHandler);

    const auto handler = GetGLGenBuffers();

    SetGLBindBuffer(BindBuffer::ArrayBuffer, handler);
    SetGLBufferData(BindBuffer::ArrayBuffer, boost::numeric_cast<OpenGLSizePtr>(vertices.size()), vertices.data(), BufferUsage::Static);
    SetGLVertexAttributePointer(0, 3, OpenGLData::Float, false, 0, nullptr);
    SetGLEnableVertexAttributeArray(0);

    SetGLBindVertexArray(0);
    SetGLBindBuffer(BindBuffer::ArrayBuffer, 0);
}
