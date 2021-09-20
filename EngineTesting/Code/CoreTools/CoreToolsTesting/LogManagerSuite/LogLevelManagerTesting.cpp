// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ²âÊÔ°æ±¾£º0.0.2.3 (2020/03/05 17:35)

#include "LogLevelManagerTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/LogManager/LogLevelManager.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, LogLevelManagerTesting)

void CoreTools::LogLevelManagerTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(ValidTest);
}

void CoreTools::LogLevelManagerTesting
	::ValidTest()
{
	for (auto logLevel = LogLevel::Disabled; logLevel < LogLevel::MaxLogLevels; ++logLevel)
	{
		auto describe = LogLevelManager::GetLogLevelDescribe(logLevel);
		ASSERT_FALSE(describe.empty());
	}
}


