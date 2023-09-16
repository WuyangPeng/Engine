///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/31 13:46)

#include "AndroidInputEventFacadeTesting.h"
#include "System/Android/AndroidInputEventFacade.h"
#include "System/Android/Flags/AndroidInputFlags.h"
#include "System/Android/Flags/AndroidKeyCodesFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::AndroidInputEventFacadeTesting::AndroidInputEventFacadeTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }, androidInputEvent{}
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, AndroidInputEventFacadeTesting)

void System::AndroidInputEventFacadeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::AndroidInputEventFacadeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(AndroidInputEventTest);
}

void System::AndroidInputEventFacadeTesting::AndroidInputEventTest()
{
    AndroidInputEventFacade androidInputEventFacade{ &androidInputEvent };
    ASSERT_ENUM_EQUAL(androidInputEventFacade.GetType(), AndroidInputEventType::Key);
    ASSERT_EQUAL(androidInputEventFacade.GetDeviceId(), 0);
    ASSERT_ENUM_EQUAL(androidInputEventFacade.GetSource(), AndroidInputSource::Unknown);
    ASSERT_ENUM_EQUAL(androidInputEventFacade.GetAction(), AndroidKeyEventAction::Down);
    ASSERT_ENUM_EQUAL(androidInputEventFacade.GetFlags(), AndroidKeyEventFlag::Null);
    ASSERT_ENUM_EQUAL(androidInputEventFacade.GetKeyCode(), AndroidKeyCodes::Unknown);
    ASSERT_EQUAL(androidInputEventFacade.GetScanCode(), 0);
    ASSERT_ENUM_EQUAL(androidInputEventFacade.GetMetaState(), AndroidMeta::None);
    ASSERT_EQUAL(androidInputEventFacade.GetRepeatCount(), 0);
    ASSERT_EQUAL(androidInputEventFacade.GetDownTime(), 0);
    ASSERT_EQUAL(androidInputEventFacade.GetEventTime(), 0);
}
