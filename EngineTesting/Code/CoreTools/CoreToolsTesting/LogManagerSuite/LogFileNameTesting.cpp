///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 11:10)

#include "LogFileNameTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/LogManager/LogFileName.h"

using namespace std::literals;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, LogFileNameTesting)

void CoreTools::LogFileNameTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(LogFileNameTest);
}

void CoreTools::LogFileNameTesting::LogFileNameTest()
{
    auto name = SYSTEM_TEXT("LogFileName"s);

    LogFileName logFileName{ name.c_str() };

    ASSERT_EQUAL(logFileName.GetFileName(), name);
}
