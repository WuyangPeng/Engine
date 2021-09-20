///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.1.3 (2021/05/23 23:58)

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
