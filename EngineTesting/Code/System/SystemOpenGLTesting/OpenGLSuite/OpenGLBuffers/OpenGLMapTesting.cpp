/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 16:44)

#include "OpenGLMapTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/OpenGLBuffers.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenGLMapTesting::OpenGLMapTesting(const OStreamShared& stream)
    : ParentType{ stream },
      handler{ 0 }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLMapTesting)

void System::OpenGLMapTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLMapTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MapTest);
}

void System::OpenGLMapTesting::InitTest()
{
    const OpenGLFloatContainer vertices{ -10.5f, -10.5f, 0.0f, 10.5f, -10.5f, 0.0f, 0.0f, 10.5f, 0.0f };

    handler = GetGLGenBuffers();
    SetGLBindBuffer(BindBuffer::ArrayBuffer, handler);
    SetGLBufferData(BindBuffer::ArrayBuffer, boost::numeric_cast<OpenGLSizePtr>(vertices.size()), vertices.data(), BufferUsage::Static);
    SetGLBindBuffer(BindBuffer::ArrayBuffer, 0);
}

void System::OpenGLMapTesting::MapTest()
{
    const auto mapBuffer = GetGLMapForWrite(BindBuffer::ArrayBuffer, handler);
    ASSERT_UNEQUAL_NULL_PTR(mapBuffer);

    ASSERT_TRUE(SetGLUnmap(BindBuffer::ArrayBuffer, handler));
}
