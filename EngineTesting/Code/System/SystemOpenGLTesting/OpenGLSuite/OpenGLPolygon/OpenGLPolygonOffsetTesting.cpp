/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 16:45)

#include "OpenGLPolygonOffsetTesting.h"
#include "System/OpenGL/OpenGLPolygon.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::OpenGLPolygonOffsetTesting::OpenGLPolygonOffsetTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLPolygonOffsetTesting)

void System::OpenGLPolygonOffsetTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLPolygonOffsetTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(OpenGLPolygonOffsetTest);
}

void System::OpenGLPolygonOffsetTesting::OpenGLPolygonOffsetTest() noexcept
{
    SetGLPolygonOffset(0.1f, 0.2f);
}
