/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 17:17)

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

void System::PostQuitMessageTesting::PostQuitMessageTest() const noexcept
{
#ifdef TEST_POST_QUIT_MESSAGE

    std::ignore = PostSystemQuitMessage();

#endif  // TEST_POST_QUIT_MESSAGE
}
