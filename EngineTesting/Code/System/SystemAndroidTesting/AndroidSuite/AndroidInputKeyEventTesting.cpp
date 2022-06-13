///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/12 13:38)

#include "AndroidInputKeyEventTesting.h"
#include "System/Android/AndroidInputKeyEvent.h"
#include "System/Android/AndroidInputQueue.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::AndroidInputKeyEventTesting::AndroidInputKeyEventTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }, androidInputEvent{}
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, AndroidInputKeyEventTesting)

void System::AndroidInputKeyEventTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::AndroidInputKeyEventTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(AndroidInputEventTest);
}

void System::AndroidInputKeyEventTesting::AndroidInputEventTest()
{
    ASSERT_ENUM_EQUAL(AndroidInputEventGetType(&androidInputEvent), AndroidInputEventType::Key);
    ASSERT_EQUAL(AndroidInputEventGetDeviceID(&androidInputEvent), 0);
    ASSERT_ENUM_EQUAL(AndroidInputEventGetSource(&androidInputEvent), AndroidInputSource::Keyborad);
    ASSERT_ENUM_EQUAL(AndroidKeyEventGetAction(&androidInputEvent), AndroidKeyEventAction::Down);
    ASSERT_ENUM_EQUAL(AndroidKeyEventGetFlags(&androidInputEvent), AndroidKeyEvent::SoftKeyboard);
    ASSERT_ENUM_EQUAL(AndroidKeyEventGetKeyCode(&androidInputEvent), AndroidKeyCodes::A);
    ASSERT_EQUAL(AndroidKeyEventGetScanCode(&androidInputEvent), 0);
    ASSERT_ENUM_EQUAL(AndroidKeyEventGetMetaState(&androidInputEvent), AndroidMeta::None);
    ASSERT_EQUAL(AndroidKeyEventGetRepeatCount(&androidInputEvent), 1);
    ASSERT_EQUAL(AndroidKeyEventGetDownTime(&androidInputEvent), 0);
    ASSERT_EQUAL(AndroidKeyEventGetEventTime(&androidInputEvent), 0);
}
