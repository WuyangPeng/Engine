///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 15:25)

#include "SleepTesting.h"
#include "System/Threading/Flags/SyncToolsFlags.h"
#include "System/Threading/SyncTools.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::SleepTesting::SleepTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, SleepTesting)

void System::SleepTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::SleepTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SleepTest);
}

void System::SleepTesting::SleepTest()
{
    constexpr auto sleepTime = 5000;

    GetStream() << "等待5秒钟。\n";

    ASSERT_ENUM_EQUAL(SystemSleep(sleepTime, true), SleepReturn::Succeed);

    GetStream() << "等待5秒钟。\n";

    ASSERT_ENUM_EQUAL(SystemSleep(sleepTime, false), SleepReturn::Succeed);

    GetStream() << "等待5秒钟。\n";

    SystemSleep(sleepTime);
}

void System::SleepTesting::PrintTipsMessage()
{
    GetStream() << "这个测试需要等待15秒钟。\n";

    SystemPause();
}
