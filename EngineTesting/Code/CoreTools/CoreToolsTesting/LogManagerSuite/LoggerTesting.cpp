///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.6 (2023/04/12 15:11)

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
    Logger logger0{ LogFilter::Mathematics, LogLevel::Info };

    ASSERT_ENUM_EQUAL(logger0.GetLogLevel(), LogLevel::Info);
    ASSERT_ENUM_EQUAL(logger0.GetLogFilterType(), LogFilter::Mathematics);

    const Logger logger1{ logger0 };

    ASSERT_ENUM_EQUAL(logger1.GetLogLevel(), LogLevel::Info);
    ASSERT_ENUM_EQUAL(logger1.GetLogFilterType(), LogFilter::Mathematics);

    logger0.SetLogLevel(LogLevel::Warn);

    ASSERT_ENUM_EQUAL(logger0.GetLogLevel(), LogLevel::Warn);
    ASSERT_ENUM_EQUAL(logger0.GetLogFilterType(), LogFilter::Mathematics);

    ASSERT_ENUM_EQUAL(logger1.GetLogLevel(), LogLevel::Info);
    ASSERT_ENUM_EQUAL(logger1.GetLogFilterType(), LogFilter::Mathematics);
}
