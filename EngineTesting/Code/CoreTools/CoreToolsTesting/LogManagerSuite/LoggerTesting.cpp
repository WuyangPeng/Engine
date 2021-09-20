// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/05 17:35)

#include "LoggerTesting.h"
#include "CoreTools/LogManager/Logger.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, LoggerTesting)

void CoreTools::LoggerTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
}

void CoreTools::LoggerTesting
	::BaseTest()
{
	Logger firstLogger{ LogFilter::Mathematics,LogLevel::Info };

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
