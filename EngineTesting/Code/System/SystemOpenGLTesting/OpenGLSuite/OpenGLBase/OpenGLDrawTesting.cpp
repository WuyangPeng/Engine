/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 16:42)

#include "OpenGLDrawTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/OpenGLBase.h"
#include "System/OpenGL/OpenGLBuffers.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenGLDrawTesting::OpenGLDrawTesting(const OStreamShared& stream)
    : ParentType{ stream },
      vertexHandler{ 0 },
      vertices{ -10.5f, -10.5f, 0.0f, 10.5f, -10.5f, 0.0f, 0.0f, 10.5f, 0.0f },
      indices{ 0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 1, 2 },
      colors{ 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLDrawTesting)

void System::OpenGLDrawTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLDrawTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SetGLDrawRangeElementsTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetGLDrawArraysTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SetGLFlushTest);
}

void System::OpenGLDrawTesting::SetGLDrawRangeElementsTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InitDraw);

    SetGLClear(OpenGLClearMask::ColorBufferBit);

    SetGLBindVertexArray(vertexHandler);

    SetGLDrawRangeElements(PrimitiveType::Triangles,
                           0,
                           boost::numeric_cast<OpenGLUnsignedInt>(vertices.size()) - 1,
                           boost::numeric_cast<OpenGLSize>(indices.size()),
                           OpenGLData::UnsignedInt,
                           indices.data());

    SetGLBindVertexArray(0);
}

void System::OpenGLDrawTesting::SetGLDrawArraysTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InitDraw);

    SetGLClear(OpenGLClearMask::ColorBufferBit);

    SetGLBindVertexArray(vertexHandler);

    SetGLDrawArrays(PrimitiveType::TrianglesStrip, 0, 3);

    SetGLBindVertexArray(0);
}

void System::OpenGLDrawTesting::BindBufferTest(int index, const OpenGLFloatContainer& buffer)
{
    const auto handler = GetGLGenBuffers();

    SetGLBindBuffer(BindBuffer::ArrayBuffer, handler);
    SetGLBufferData(BindBuffer::ArrayBuffer, boost::numeric_cast<OpenGLSizePtr>(buffer.size()), buffer.data(), BufferUsage::Static);
    SetGLVertexAttributePointer(index, 3, OpenGLData::Float, false, 0, nullptr);
    SetGLEnableVertexAttributeArray(0);
}

void System::OpenGLDrawTesting::InitDraw()
{
    vertexHandler = GetGLGenVertexArrays();
    SetGLBindVertexArray(vertexHandler);

    ASSERT_NOT_THROW_EXCEPTION_2(BindBufferTest, 0, vertices);
    ASSERT_NOT_THROW_EXCEPTION_2(BindBufferTest, 1, colors);

    SetGLBindVertexArray(0);
    SetGLBindBuffer(BindBuffer::ArrayBuffer, 0);
}

void System::OpenGLDrawTesting::SetGLFlushTest() noexcept
{
    SetGLFlush();
}
