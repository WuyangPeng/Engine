///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 11:11)

#include "LoggerTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/LogManager/Logger.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
CoreTools::LoggerTesting::LoggerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, LoggerTesting)

void CoreTools::LoggerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}
void CoreTools::LoggerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
}

void CoreTools::LoggerTesting::BaseTest()
{
    Logger firstLogger{ LogFilter::Mathematics, LogLevel::Info };

    ASSERT_ENUM_EQUAL(firstLogger.GetLogLevel(), LogLevel::Info);
    ASSERT_ENUM_EQUAL(firstLogger.GetLogFilterType(), LogFilter::Mathematics);

    Logger secondLogger{ firstLogger };

    ASSERT_ENUM_EQUAL(secondLogger.GetLogLevel(), LogLevel::Info);
    ASSERT_ENUM_EQUAL(secondLogger.GetLogFilterType(), LogFilter::Mathematics);

    firstLogger.SetLogLevel(LogLevel::Warn);

    ASSERT_ENUM_EQUAL(firstLogger.GetLogLevel(), LogLevel::Warn);
    ASSERT_ENUM_EQUAL(firstLogger.GetLogFilterType(), LogFilter::Mathematics);

    ASSERT_ENUM_EQUAL(secondLogger.GetLogLevel(), LogLevel::Info);
    ASSERT_ENUM_EQUAL(secondLogger.GetLogFilterType(), LogFilter::Mathematics);
}
