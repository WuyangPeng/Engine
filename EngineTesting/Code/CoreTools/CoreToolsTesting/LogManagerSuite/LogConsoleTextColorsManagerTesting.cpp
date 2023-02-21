///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 11:10)

#include "LogConsoleTextColorsManagerTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/LogManager/LogConsoleTextColorsManager.h"
#include "CoreTools/LogManager/Flags/LogManagerFlags.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
using std::cerr;
using std::cout;

CoreTools::LogConsoleTextColorsManagerTesting::LogConsoleTextColorsManagerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, LogConsoleTextColorsManagerTesting)

void CoreTools::LogConsoleTextColorsManagerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}
void CoreTools::LogConsoleTextColorsManagerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ErrorConsoleTextColorsManagerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OutputConsoleTextColorsManagerTest);
}

void CoreTools::LogConsoleTextColorsManagerTesting::ErrorConsoleTextColorsManagerTest()
{
    LogConsoleTextColorsManager firstManager{ LogLevel::Error };

    CERR << SYSTEM_TEXT("这条信息在控制台显示为红色。\n");

    LogConsoleTextColorsManager secondManager{ OStreamShared{ false }, LogLevel::Warn };

    cerr << "这条信息在控制台显示为黄色。\n";
}

void CoreTools::LogConsoleTextColorsManagerTesting::OutputConsoleTextColorsManagerTest()
{
    LogConsoleTextColorsManager firstManager{ LogLevel::Debug };

    COUT << SYSTEM_TEXT("这条信息在控制台显示为青色。\n");

    LogConsoleTextColorsManager secondManager{ OStreamShared{ true }, LogLevel::Info };

    cout << "这条信息在控制台显示为绿色。\n";
}
