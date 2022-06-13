///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/12 13:40)

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
