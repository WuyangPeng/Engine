///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 11:26)

#include "LogMessagePrefixTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/LogManager/Flags/LogManagerFlags.h"
#include "CoreTools/LogManager/LogFilterManager.h"
#include "CoreTools/LogManager/LogLevelManager.h"
#include "CoreTools/LogManager/LogMessagePrefix.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::LogMessagePrefixTesting::LogMessagePrefixTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, LogMessagePrefixTesting)

void CoreTools::LogMessagePrefixTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}
void CoreTools::LogMessagePrefixTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(TimestampTest);
    ASSERT_NOT_THROW_EXCEPTION_0(LogLevelTest);
    ASSERT_NOT_THROW_EXCEPTION_0(LogFilterTest);
    ASSERT_NOT_THROW_EXCEPTION_0(NoPrefixTest);
}

void CoreTools::LogMessagePrefixTesting::TimestampTest()
{
    const LogMessagePrefix prefix{ AppenderPrint::PrefixTimestamp, LogLevel::Debug, LogFilter::System };

    const auto logLevelDescribe = LogLevelManager::GetLogLevelDescribe(LogLevel::Debug);
    const auto logFilterDescribe = LogFilterManager::GetLogFilterDescribe(LogFilter::System);
    const auto prefixDescribe = prefix.GetPrefix();

    ASSERT_EQUAL(prefixDescribe.find(logLevelDescribe), System::String::npos);
    ASSERT_EQUAL(prefixDescribe.find(logFilterDescribe), System::String::npos);

    ASSERT_LESS(0, prefix.GetPrefixSize());
}

void CoreTools::LogMessagePrefixTesting::LogLevelTest()
{
    const LogMessagePrefix prefix{ AppenderPrint::PrefixLogLevel, LogLevel::Error, LogFilter::Rendering };

    const auto logLevelDescribe = LogLevelManager::GetLogLevelDescribe(LogLevel::Error);
    const auto logFilterDescribe = LogFilterManager::GetLogFilterDescribe(LogFilter::Rendering);
    const auto prefixDescribe = prefix.GetPrefix();

    ASSERT_UNEQUAL(prefixDescribe.find(logLevelDescribe), System::String::npos);
    ASSERT_EQUAL(prefixDescribe.find(logFilterDescribe), System::String::npos);
}

void CoreTools::LogMessagePrefixTesting::LogFilterTest()
{
    const LogMessagePrefix prefix{ AppenderPrint::PrefixLogFilterType, LogLevel::Fatal, LogFilter::CoreTools };

    const auto logLevelDescribe = LogLevelManager::GetLogLevelDescribe(LogLevel::Fatal);
    const auto logFilterDescribe = LogFilterManager::GetLogFilterDescribe(LogFilter::CoreTools);
    const auto prefixDescribe = prefix.GetPrefix();

    ASSERT_EQUAL(prefixDescribe.find(logLevelDescribe), System::String::npos);
    ASSERT_UNEQUAL(prefixDescribe.find(logFilterDescribe), System::String::npos);
}

void CoreTools::LogMessagePrefixTesting::NoPrefixTest()
{
    const LogMessagePrefix prefixNone{ AppenderPrint::None, LogLevel::Info, LogFilter::Network };

    ASSERT_EQUAL(0, prefixNone.GetPrefixSize());

    const LogMessagePrefix prefixDisabled{ AppenderPrint::PrefixLogFilterType, LogLevel::Disabled, LogFilter::Mathematics };

    ASSERT_EQUAL(0, prefixDisabled.GetPrefixSize());
}
