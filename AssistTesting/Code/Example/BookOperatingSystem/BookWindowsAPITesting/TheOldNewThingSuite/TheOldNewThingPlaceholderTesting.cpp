///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.1.3 (2021/05/23 23:58)

#include "TheOldNewThingPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookOperatingSystem/TheOldNewThing/Helper/TheOldNewThingClassInvariantMacro.h"

BookWindowsAPI::TheOldNewThing::TheOldNewThingPlaceholderTesting::TheOldNewThingPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    THE_OLD_NEW_THING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookWindowsAPI::TheOldNewThing, TheOldNewThingPlaceholderTesting)

void BookWindowsAPI::TheOldNewThing::TheOldNewThingPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookWindowsAPI::TheOldNewThing::TheOldNewThingPlaceholderTesting::MainTest() noexcept
{
}
