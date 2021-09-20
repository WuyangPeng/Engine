///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.6 (2021/07/07 10:56)

#include "PostQuitMessageTesting.h"
#include "System/Windows/WindowsProcess.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#define TEST_POST_QUIT_MESSAGE
#undef TEST_POST_QUIT_MESSAGE

System::PostQuitMessageTesting::PostQuitMessageTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, PostQuitMessageTesting)

void System::PostQuitMessageTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::PostQuitMessageTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(PostQuitMessageTest);
}

void System::PostQuitMessageTesting::PostQuitMessageTest() noexcept
{
#ifdef TEST_POST_QUIT_MESSAGE
    MAYBE_UNUSED const auto result = PostSystemQuitMessage();
#endif  // TEST_POST_QUIT_MESSAGE
}
