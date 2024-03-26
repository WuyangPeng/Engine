/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 17:09)

#include "AndroidLooperTesting.h"
#include "Detail/CallbackFunction.h"
#include "System/Android/AndroidLooper.h"
#include "System/Android/Flags/AndroidLooperFlags.h"
#include "System/Android/Flags/AndroidNativeAppGlueFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::AndroidLooperTesting::AndroidLooperTesting(const OStreamShared& stream)
    : ParentType{ stream }
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
    ASSERT_NOT_THROW_EXCEPTION_0(AndroidLooperFileDescriptorTest);
}

void System::AndroidLooperTesting::AndroidLooperForThreadTest()
{
    ASSERT_EQUAL_NULL_PTR(AndroidLooperForThread());
}

void System::AndroidLooperTesting::AndroidLooperPrepareTest()
{
    ASSERT_EQUAL_NULL_PTR(AndroidLooperPrepare(0));
}

void System::AndroidLooperTesting::AndroidLooperTest() const noexcept
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

void System::AndroidLooperTesting::AndroidLooperWakeTest() const noexcept
{
    AndroidLooper* looper{ nullptr };

    AndroidLooperWake(looper);
}

void System::AndroidLooperTesting::AndroidLooperFileDescriptorTest()
{
    AndroidLooper looper{};

    ASSERT_EQUAL(AndroidLooperAddFileDescriptor(&looper, 0, LooperId::Main, AndroidLooperEvent::Error, Android::Looper::CallbackFunction, nullptr), 0);
    ASSERT_EQUAL(AndroidLooperRemoveFd(&looper, 0), 0);
}
