///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.2.5 (2021/11/03 21:08)

#include "MultithreadingApplicationsInWin32Testing.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookOperatingSystem/MultithreadingApplicationsInWin32/Helper/MultithreadingApplicationsInWin32ClassInvariantMacro.h"

BookConcurrentProgramming::MultithreadingApplicationsInWin32::MultithreadingApplicationsInWin32Testing::MultithreadingApplicationsInWin32Testing(const OStreamShared& stream)
    : ParentType{ stream }
{
    MULTITHREADING_APPLICATIONS_IN_WIN32_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookConcurrentProgramming::MultithreadingApplicationsInWin32, MultithreadingApplicationsInWin32Testing)

void BookConcurrentProgramming::MultithreadingApplicationsInWin32::MultithreadingApplicationsInWin32Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookConcurrentProgramming::MultithreadingApplicationsInWin32::MultithreadingApplicationsInWin32Testing::MainTest() noexcept
{
}
