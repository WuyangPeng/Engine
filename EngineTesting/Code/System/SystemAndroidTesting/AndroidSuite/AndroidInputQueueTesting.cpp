///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/12 13:39)

#include "AndroidInputQueueTesting.h"

#include "Detail/CallbackFunction.h"
#include "System/Android/AndroidInputQueue.h"
#include "System/Android/AndroidLooper.h"
#include "System/Android/Flags/AndroidNativeAppGlueFlags.h"
#include "System/Android/Using/AndroidNativeAppGlueUsing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::AndroidInputQueueTesting::AndroidInputQueueTesting(const OStreamShared& streamShared, AndroidApp* androidApp)
    : ParentType{ streamShared }, androidApp{ androidApp }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool System::AndroidInputQueueTesting::IsValid() const noexcept
{
    if (ParentType::IsValid() && androidApp != nullptr)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

void System::AndroidInputQueueTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::AndroidInputQueueTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(AndroidInputQueueTest);
}

void System::AndroidInputQueueTesting::AndroidInputQueueTest()
{
    AndroidLooper* looper{ nullptr };
    AndroidInputEvent outEvent{};
    auto outEventPtr = &outEvent;

    AndroidInputQueueAttachLooper(androidApp->GetInputQueue(), looper, LooperID::Main, Android::Looper::CallbackFunction, nullptr);
    AndroidInputQueueDetachLooper(androidApp->GetInputQueue());
    ASSERT_EQUAL(AndroidInputQueueHasEvents(androidApp->GetInputQueue()), 0);
    ASSERT_EQUAL(AndroidInputQueueGetEvent(androidApp->GetInputQueue(), &outEventPtr), 0);
    ASSERT_EQUAL(AndroidInputQueuePreDispatchEvent(androidApp->GetInputQueue(), &outEvent), 1);
    AndroidInputQueueFinishEvent(androidApp->GetInputQueue(), &outEvent, 0);
}
