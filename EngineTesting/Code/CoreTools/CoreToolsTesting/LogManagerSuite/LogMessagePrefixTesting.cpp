// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/05 17:36)

#include "LogMessagePrefixTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/LogManager/LogLevelManager.h"
#include "CoreTools/LogManager/LogFilterManager.h"
#include "CoreTools/LogManager/LogMessagePrefix.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, LogMessagePrefixTesting)

void CoreTools::LogMessagePrefixTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(TimestampTest);
	ASSERT_NOT_THROW_EXCEPTION_0(LogLevelTest);
	ASSERT_NOT_THROW_EXCEPTION_0(LogFilterTest);
	ASSERT_NOT_THROW_EXCEPTION_0(NoPrefixTest);
}

void CoreTools::LogMessagePrefixTesting
	::TimestampTest()
{
	LogMessagePrefix prefix{ AppenderPrint::PrefixTimestamp,LogLevel::Debug,LogFilter::System };

	auto logLevelDescribe = LogLevelManager::GetLogLevelDescribe(LogLevel::Debug);
	auto logFilterDescribe = LogFilterManager::GetLogFilterDescribe(LogFilter::System);
	auto prefixDescribe = prefix.GetPrefix();

	ASSERT_EQUAL(prefixDescribe.find(logLevelDescribe), System::String::npos);
	ASSERT_EQUAL(prefixDescribe.find(logFilterDescribe), System::String::npos);

	ASSERT_LESS(0, prefix.GetPrefixSize());
}

void CoreTools::LogMessagePrefixTesting
	::LogLevelTest()
{
	LogMessagePrefix prefix{ AppenderPrint::PrefixLogLevel,LogLevel::Error,LogFilter::Rendering };

	auto logLevelDescribe = LogLevelManager::GetLogLevelDescribe(LogLevel::Error);
	auto logFilterDescribe = LogFilterManager::GetLogFilterDescribe(LogFilter::Rendering);
	auto prefixDescribe = prefix.GetPrefix();

	ASSERT_UNEQUAL(prefixDescribe.find(logLevelDescribe), System::String::npos);
	ASSERT_EQUAL(prefixDescribe.find(logFilterDescribe), System::String::npos);
}

void CoreTools::LogMessagePrefixTesting
	::LogFilterTest()
{
	LogMessagePrefix prefix{ AppenderPrint::PrefixLogFilterType,LogLevel::Fatal,LogFilter::CoreTools };

	auto logLevelDescribe = LogLevelManager::GetLogLevelDescribe(LogLevel::Fatal);
	auto logFilterDescribe = LogFilterManager::GetLogFilterDescribe(LogFilter::CoreTools);
	auto prefixDescribe = prefix.GetPrefix();

	ASSERT_EQUAL(prefixDescribe.find(logLevelDescribe), System::String::npos);
	ASSERT_UNEQUAL(prefixDescribe.find(logFilterDescribe), System::String::npos);
}

void CoreTools::LogMessagePrefixTesting
	::NoPrefixTest()
{
	LogMessagePrefix prefixNone{ AppenderPrint::None,LogLevel::Info,LogFilter::Network };

	ASSERT_EQUAL(0, prefixNone.GetPrefixSize());

	LogMessagePrefix prefixDisabled{ AppenderPrint::PrefixLogFilterType,LogLevel::Disabled,	LogFilter::Mathematics };

	ASSERT_EQUAL(0, prefixDisabled.GetPrefixSize());
}


