/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/18 22:09)

#include "LoggerTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
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

    ASSERT_EQUAL(logger0.GetLogLevel(), LogLevel::Info);
    ASSERT_EQUAL(logger0.GetLogFilterType(), LogFilter::Mathematics);

    const Logger logger1{ logger0 };

    ASSERT_NOT_THROW_EXCEPTION_2(DoBaseTest, logger1, LogLevel::Info);

    logger0.SetLogLevel(LogLevel::Warn);

    ASSERT_NOT_THROW_EXCEPTION_2(DoBaseTest, logger0, LogLevel::Warn);
    ASSERT_NOT_THROW_EXCEPTION_2(DoBaseTest, logger1, LogLevel::Info);
}

void CoreTools::LoggerTesting::DoBaseTest(const Logger& logger, LogLevel logLevel)
{
    ASSERT_EQUAL(logger.GetLogLevel(), logLevel);
    ASSERT_EQUAL(logger.GetLogFilterType(), LogFilter::Mathematics);
}
