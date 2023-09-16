///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 14:24)

#include "OpenGLVertexArraysTesting.h"
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
    ASSERT_NOT_THROW_EXCEPTION_0(OpenGLVertexArrayTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OpenGLVertexArraysTest);
}

void System::OpenGLVertexArraysTesting::OpenGLVertexArrayTest()
{
    const auto vertexArray = GetGLGenVertexArrays();
    ASSERT_LESS(0u, vertexArray);

    SetGLBindVertexArray(vertexArray);

    ASSERT_NOT_THROW_EXCEPTION_1(SetGLDeleteVertexArrayTest, vertexArray);
}

void System::OpenGLVertexArraysTesting::OpenGLVertexArraysTest()
{
    BufferType vertexArrays{};

    GetGLGenVertexArrays(bufferSize, vertexArrays.data());
    ASSERT_NOT_THROW_EXCEPTION_1(DoOpenGLVertexArraysTest, vertexArrays);

    ASSERT_NOT_THROW_EXCEPTION_1(SetGLDeleteVertexArraysTest, vertexArrays);
}

void System::OpenGLVertexArraysTesting::DoOpenGLVertexArraysTest(const BufferType& buffers)
{
    for (auto buffer : buffers)
    {
        ASSERT_LESS(0u, buffer);
    }
}
