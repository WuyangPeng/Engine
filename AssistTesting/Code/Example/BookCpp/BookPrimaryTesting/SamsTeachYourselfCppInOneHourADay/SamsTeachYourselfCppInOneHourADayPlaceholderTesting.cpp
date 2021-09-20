///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.6.0.1 (2021/01/02 22:59)

#include "SamsTeachYourselfCppInOneHourADayPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookCpp/SamsTeachYourselfCppInOneHourADay/Helper/SamsTeachYourselfCppInOneHourADayClassInvariantMacro.h"

BookPrimary::SamsTeachYourselfCppInOneHourADay::SamsTeachYourselfCppInOneHourADayPlaceholderTesting::SamsTeachYourselfCppInOneHourADayPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SAMS_TEACH_YOURSELF_CPP_IN_ONE_HOUR_A_DAY_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookPrimary::SamsTeachYourselfCppInOneHourADay, SamsTeachYourselfCppInOneHourADayPlaceholderTesting)

void BookPrimary::SamsTeachYourselfCppInOneHourADay::SamsTeachYourselfCppInOneHourADayPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookPrimary::SamsTeachYourselfCppInOneHourADay::SamsTeachYourselfCppInOneHourADayPlaceholderTesting::MainTest() noexcept
{
}
