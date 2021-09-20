// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/05 17:34)

#include "LogFileNameTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/LogManager/LogFileName.h" 

using namespace std::literals;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, LogFileNameTesting)

void CoreTools::LogFileNameTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(LogFileNameTest);
}

void CoreTools::LogFileNameTesting
	::LogFileNameTest()
{
	auto name = SYSTEM_TEXT("LogFileName"s);

	LogFileName logFileName{ name.c_str() };

	ASSERT_EQUAL(logFileName.GetFileName(), name);
}

