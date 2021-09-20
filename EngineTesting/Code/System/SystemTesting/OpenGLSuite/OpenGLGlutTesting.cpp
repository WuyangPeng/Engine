///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.6 (2021/06/28 11:26)

#include "OpenGLGlutTesting.h"
#include "System/OpenGL/OpenGLGlut.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <array>

using std::array;

System::OpenGLGlutTesting::OpenGLGlutTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, OpenGLGlutTesting)

void System::OpenGLGlutTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::OpenGLGlutTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GlutInitTest);

    // SystemOpenGLTesting有OpenGL函数的测试。
    // GlutMainLoopTesting有函数GlutMainLoop的测试。
}

void System::OpenGLGlutTesting::GlutInitTest() noexcept
{
    constexpr auto bufferSize = 1;
    array<char, bufferSize> buffer{};
    auto count = bufferSize;
    auto argv = buffer.data();

    GlutInit(&count, &argv);
}
