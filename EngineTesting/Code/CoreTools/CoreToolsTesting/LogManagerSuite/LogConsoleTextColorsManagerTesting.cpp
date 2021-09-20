// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎测试版本：0.0.2.3 (2020/03/05 17:34)

#include "LogConsoleTextColorsManagerTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/LogManager/LogConsoleTextColorsManager.h"

using std::cout;
using std::cerr;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, LogConsoleTextColorsManagerTesting)

void CoreTools::LogConsoleTextColorsManagerTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(ErrorConsoleTextColorsManagerTest);
	ASSERT_NOT_THROW_EXCEPTION_0(OutputConsoleTextColorsManagerTest);
}

void CoreTools::LogConsoleTextColorsManagerTesting
	::ErrorConsoleTextColorsManagerTest()
{
	LogConsoleTextColorsManager firstManager{ LogLevel::Error };

	CERR << SYSTEM_TEXT("这条信息在控制台显示为红色。\n");

	LogConsoleTextColorsManager secondManager{ OStreamShared{false},LogLevel::Warn };

	cerr << "这条信息在控制台显示为黄色。\n";
}

void CoreTools::LogConsoleTextColorsManagerTesting
	::OutputConsoleTextColorsManagerTest()
{
	LogConsoleTextColorsManager firstManager{ LogLevel::Debug };

	COUT << SYSTEM_TEXT("这条信息在控制台显示为青色。\n");

	LogConsoleTextColorsManager secondManager{ OStreamShared{}, LogLevel::Info };

	cout << "这条信息在控制台显示为绿色。\n";
}





