///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 13:45)

#include "AndroidLooperTesting.h"
#include "Detail/CallbackFunction.h"
#include "System/Android/AndroidLooper.h"
#include "System/Android/Flags/AndroidLooperFlags.h"
#include "System/Android/Flags/AndroidNativeAppGlueFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::AndroidLooperTesting::AndroidLooperTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, AndroidLooperTesting)

void System::AndroidLooperTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::AndroidLooperTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(AndroidLooperForThreadTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AndroidLooperPrepareTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AndroidLooperTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AndroidLooperPollTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AndroidLooperWakeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AndroidLooperFdTest);
}

void System::AndroidLooperTesting::AndroidLooperForThreadTest()
{
    ASSERT_EQUAL_NULL_PTR(AndroidLooperForThread());
}

void System::AndroidLooperTesting::AndroidLooperPrepareTest()
{
    ASSERT_EQUAL_NULL_PTR(AndroidLooperPrepare(0));
}

void System::AndroidLooperTesting::AndroidLooperTest() noexcept
{
    AndroidLooper looper{};
    AndroidLooperAcquire(&looper);
    AndroidLooperRelease(&looper);
}

void System::AndroidLooperTesting::AndroidLooperPollTest()
{
    int32_t outFd{};
    int32_t outEvents{};

    ASSERT_ENUM_EQUAL(AndroidLooperPollOnce(0, &outFd, &outEvents, nullptr), AndroidLooperEvent::Input);

    const auto result = AndroidLooperPollAll(0, &outFd, &outEvents, nullptr);

    ASSERT_TRUE(((result & AndroidLooperEvent::Input) == AndroidLooperEvent::Input) || result == AndroidLooperEvent::Null);
}

void System::AndroidLooperTesting::AndroidLooperWakeTest() noexcept
{
    AndroidLooper* looper{ nullptr };

    AndroidLooperWake(looper);
}

void System::AndroidLooperTesting::AndroidLooperFdTest()
{
    AndroidLooper looper{};

    ASSERT_EQUAL(AndroidLooperAddFd(&looper, 0, LooperId::Main, AndroidLooperEvent::Error, Android::Looper::CallbackFunction, nullptr), 0);
    ASSERT_EQUAL(AndroidLooperRemoveFd(&looper, 0), 0);
}
