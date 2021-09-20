///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.6 (2021/07/07 10:56)

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
