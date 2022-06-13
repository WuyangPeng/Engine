///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/12 14:57)

#include "OpenGLAPITesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/OpenGLAPI.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/Math.h"

System::OpenGLAPITesting::OpenGLAPITesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLAPITesting)

void System::OpenGLAPITesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLAPITesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
    ASSERT_NOT_THROW_EXCEPTION_0(QueryTest);
}

void System::OpenGLAPITesting::BaseTest() noexcept
{
    constexpr auto width = 800;
    constexpr auto height = 600;

    ClearAllGLBufferBit();
    SetGLViewport(0, 0, width, height);
    SetupRenderStatus();
    SetGLDepthRange(0.0, 1.0);
}

void System::OpenGLAPITesting::QueryTest()
{
    const auto numExtensions = GetGLInteger(OpenGLQuery::NumExtensions);

    ASSERT_LESS_EQUAL(0, numExtensions);

    const auto isVertexArray = GetGLBoolean(OpenGLQuery::VertexArray);

    ASSERT_EQUAL(false, isVertexArray);

    const auto numExtensionsDouble = GetGLDouble(OpenGLQuery::NumExtensions);

    ASSERT_LESS_EQUAL(0, numExtensionsDouble);

    const auto numExtensionsFloat = GetGLFloat(OpenGLQuery::NumExtensions);

    ASSERT_LESS_EQUAL(0, numExtensionsFloat);

    ASSERT_APPROXIMATE(numExtensionsDouble, numExtensions, Mathematics::MathD::epsilon);
    ASSERT_APPROXIMATE(numExtensionsFloat, numExtensions, Mathematics::MathF::epsilon);
}
