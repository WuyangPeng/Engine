///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.1 (2021/07/31 21:59)

#include "AndroidLooperTesting.h"
#include "Detail/CallbackFunction.h"
#include "System/Android/AndroidLooper.h"
#include "System/Android/Flags/AndroidLooperFlags.h"
#include "System/Android/Flags/AndroidNativeAppGlueFlags.h"
#include "System/Android/Using/AndroidNativeAppGlueUsing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::AndroidLooperTesting::AndroidLooperTesting(const OStreamShared& streamShared, AndroidApp* androidApp)
    : ParentType{ streamShared }, androidApp{ androidApp }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool System::AndroidLooperTesting::IsValid() const noexcept
{
    if (ParentType::IsValid() && androidApp != nullptr)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

void System::AndroidLooperTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::AndroidLooperTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(AndroidLooperTest);
}

void System::AndroidLooperTesting::AndroidLooperTest()
{
    ASSERT_EQUAL_NULL_PTR(AndroidLooperForThread());
    ASSERT_EQUAL_NULL_PTR(AndroidLooperPrepare(0));

    AndroidLooper looper{};
    AndroidLooperAcquire(&looper);
    AndroidLooperRelease(&looper);

    ASSERT_ENUM_EQUAL(AndroidLooperPollOnce(0, nullptr, nullptr, nullptr), AndroidLooperEvent::Input);

    const auto result = AndroidLooperPollAll(0, nullptr, nullptr, nullptr);
    ASSERT_TRUE(result == AndroidLooperEvent::Input || EnumCastUnderlying(result) == -1);

    AndroidLooperWake(&looper);
    ASSERT_EQUAL(AndroidLooperAddFd(nullptr, 0, LooperID::Main, AndroidLooperEvent::Error, Android::Looper::CallbackFunction, nullptr), 1);
    ASSERT_EQUAL(AndroidLooperRemoveFd(&looper, 0), 1);
}
