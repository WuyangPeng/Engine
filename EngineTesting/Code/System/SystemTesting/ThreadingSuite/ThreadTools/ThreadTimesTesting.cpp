///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.3 (2021/05/11 14:20)

#include "ThreadTimesTesting.h"
#include "System/Threading/Thread.h"
#include "System/Threading/ThreadTools.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::ThreadTimesTesting::ThreadTimesTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, ThreadTimesTesting)

void System::ThreadTimesTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::ThreadTimesTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ThreadTimeTest);
}

void System::ThreadTimesTesting::ThreadTimeTest()
{
    FileTime creationTime{};
    FileTime exitTime{};
    FileTime kernelTime{};
    FileTime userTime{};

    ASSERT_TRUE(GetSystemThreadTimes(GetCurrentSystemThread(), &creationTime, &exitTime, &kernelTime, &userTime));
}
