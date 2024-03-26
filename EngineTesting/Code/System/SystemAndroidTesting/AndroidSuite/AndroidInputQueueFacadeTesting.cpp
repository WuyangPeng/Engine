/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 17:09)

#include "AndroidInputQueueFacadeTesting.h"

#include "Detail/CallbackFunction.h"
#include "System/Android/AndroidInputQueueFacade.h"
#include "System/Android/AndroidLooper.h"
#include "System/Android/Flags/AndroidNativeAppGlueFlags.h"
#include "System/Android/Using/AndroidNativeAppGlueUsing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::AndroidInputQueueFacadeTesting::AndroidInputQueueFacadeTesting(const OStreamShared& stream, AndroidApp* androidApp)
    : ParentType{ stream }, androidInputQueue{ GetAndroidInputQueue(androidApp) }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

System::AndroidInputQueue* System::AndroidInputQueueFacadeTesting::GetAndroidInputQueue(AndroidApp* androidApp)
{
    if (androidApp == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("androidAppΪ�ա�"))
    }

    const auto androidInputQueue = androidApp->GetInputQueue();

    if (androidInputQueue == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("InputQueueΪ�ա�"))
    }

    return androidInputQueue;
}

#ifdef OPEN_CLASS_INVARIANT

bool System::AndroidInputQueueFacadeTesting::IsValid() const noexcept
{
    return ParentType::IsValid() && androidInputQueue != nullptr;
}

#endif  // OPEN_CLASS_INVARIANT

void System::AndroidInputQueueFacadeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::AndroidInputQueueFacadeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(AndroidInputQueueLooperTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AndroidInputQueueHasEventsTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AndroidInputQueueEventTest);
}

void System::AndroidInputQueueFacadeTesting::AndroidInputQueueLooperTest() const noexcept
{
    AndroidInputQueueFacade androidInputQueueFacade{ androidInputQueue };

    AndroidLooper* looper{ nullptr };
    androidInputQueueFacade.AttachLooper(looper, LooperId::Main, Android::Looper::CallbackFunction, nullptr);
    androidInputQueueFacade.DetachLooper();
}

void System::AndroidInputQueueFacadeTesting::AndroidInputQueueHasEventsTest()
{
    const AndroidInputQueueFacade androidInputQueueFacade{ androidInputQueue };

    ASSERT_EQUAL(androidInputQueueFacade.HasEvents(), 0);
}

void System::AndroidInputQueueFacadeTesting::AndroidInputQueueEventTest()
{
    AndroidInputQueueFacade androidInputQueueFacade{ androidInputQueue };

    AndroidInputEvent outEvent{};
    auto outEventPtr = &outEvent;

    ASSERT_EQUAL(androidInputQueueFacade.GetEvent(&outEventPtr), androidInputQueue->GetSize());
    ASSERT_EQUAL(androidInputQueueFacade.PreviousDispatchEvent(&outEvent), 0);
    androidInputQueueFacade.FinishEvent(&outEvent, 0);
}
