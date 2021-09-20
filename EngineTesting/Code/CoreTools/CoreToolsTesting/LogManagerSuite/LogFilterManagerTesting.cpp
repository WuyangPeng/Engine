// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/05 17:35)

#include "LogFilterManagerTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/LogManager/LogFilterManager.h"

using namespace std::literals;

namespace CoreTools
{
	ENUM_INCREMENTABLE_OPERATOR_DEFINE(LogFilter);
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, LogFilterManagerTesting)

void CoreTools::LogFilterManagerTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(ValidTest);
	ASSERT_NOT_THROW_EXCEPTION_0(GetLogFilterTypeTest);
}

void CoreTools::LogFilterManagerTesting
	::ValidTest()
{
	for (auto logFilter = LogFilter::System; logFilter < LogFilter::MaxLogFilter; ++logFilter)
	{
		auto describe = LogFilterManager::GetLogFilterDescribe(logFilter);
		ASSERT_FALSE(describe.empty());
	}
}

void CoreTools::LogFilterManagerTesting
	::GetLogFilterTypeTest()
{
	ASSERT_ENUM_EQUAL(LogFilterManager::GetLogFilterType(SYSTEM_TEXT("System"s)), LogFilter::System);
	ASSERT_ENUM_EQUAL(LogFilterManager::GetLogFilterType(SYSTEM_TEXT("CoreTools"s)), LogFilter::CoreTools);
	ASSERT_ENUM_EQUAL(LogFilterManager::GetLogFilterType(SYSTEM_TEXT("Mathematics"s)), LogFilter::Mathematics);
	ASSERT_ENUM_EQUAL(LogFilterManager::GetLogFilterType(SYSTEM_TEXT("Database"s)), LogFilter::Database);
	ASSERT_ENUM_EQUAL(LogFilterManager::GetLogFilterType(SYSTEM_TEXT("SoundEffect"s)), LogFilter::SoundEffect);
	ASSERT_ENUM_EQUAL(LogFilterManager::GetLogFilterType(SYSTEM_TEXT("Script"s)), LogFilter::Script);
	ASSERT_ENUM_EQUAL(LogFilterManager::GetLogFilterType(SYSTEM_TEXT("Network"s)), LogFilter::Network);
	ASSERT_ENUM_EQUAL(LogFilterManager::GetLogFilterType(SYSTEM_TEXT("Rendering"s)), LogFilter::Rendering);
	ASSERT_ENUM_EQUAL(LogFilterManager::GetLogFilterType(SYSTEM_TEXT("Physics"s)), LogFilter::Physics);
	ASSERT_ENUM_EQUAL(LogFilterManager::GetLogFilterType(SYSTEM_TEXT("Imagics"s)), LogFilter::Imagics);
	ASSERT_ENUM_EQUAL(LogFilterManager::GetLogFilterType(SYSTEM_TEXT("ArtificialIntellegence"s)), LogFilter::ArtificialIntellegence);
	ASSERT_ENUM_EQUAL(LogFilterManager::GetLogFilterType(SYSTEM_TEXT("UserInterface"s)), LogFilter::UserInterface);
	ASSERT_ENUM_EQUAL(LogFilterManager::GetLogFilterType(SYSTEM_TEXT("AssistTools"s)), LogFilter::AssistTools);
	ASSERT_ENUM_EQUAL(LogFilterManager::GetLogFilterType(SYSTEM_TEXT("Framework"s)), LogFilter::Framework);
	ASSERT_ENUM_EQUAL(LogFilterManager::GetLogFilterType(SYSTEM_TEXT("User"s)), LogFilter::User);
}




