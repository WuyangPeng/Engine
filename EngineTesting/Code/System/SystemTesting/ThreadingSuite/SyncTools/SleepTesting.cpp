/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/12 18:22)

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
    SYSTEM_SELF_CLASS_IS_VALID_1;
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

    GetStream() << "�ȴ�5���ӡ�\n";

    ASSERT_EQUAL(SystemSleep(sleepTime, true), SleepReturn::Succeed);

    GetStream() << "�ȴ�5���ӡ�\n";

    ASSERT_EQUAL(SystemSleep(sleepTime, false), SleepReturn::Succeed);

    GetStream() << "�ȴ�5���ӡ�\n";

    SystemSleep(sleepTime);
}

void System::SleepTesting::PrintTipsMessage()
{
    GetStream() << "���������Ҫ�ȴ�15���ӡ�\n";

    SystemPause();
}
