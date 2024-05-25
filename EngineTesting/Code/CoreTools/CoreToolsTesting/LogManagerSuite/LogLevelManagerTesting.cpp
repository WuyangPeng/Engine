/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/05/11 14:36)

#include "LogLevelManagerTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/LogManager/Flags/LogManagerFlags.h"
#include "CoreTools/LogManager/LogLevelManager.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using System::operator++;

CoreTools::LogLevelManagerTesting::LogLevelManagerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, LogLevelManagerTesting)

void CoreTools::LogLevelManagerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::LogLevelManagerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ValidTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GetLogLevelTest);
}

void CoreTools::LogLevelManagerTesting::ValidTest()
{
    for (auto logLevel = LogLevel::Disabled; logLevel < LogLevel::MaxLogLevels; ++logLevel)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(DoValidTest, logLevel);
    }
}

void CoreTools::LogLevelManagerTesting::DoValidTest(LogLevel logLevel)
{
    const auto describe = LogLevelManager::GetLogLevelDescribe(logLevel);
    ASSERT_FALSE(describe.empty());
}

void CoreTools::LogLevelManagerTesting::GetLogLevelTest()
{
    ASSERT_EQUAL(LogLevelManager::GetLogLevel("Disabled"), LogLevel::Disabled);
    ASSERT_EQUAL(LogLevelManager::GetLogLevel("Trace"), LogLevel::Trace);
    ASSERT_EQUAL(LogLevelManager::GetLogLevel("Debug"), LogLevel::Debug);
    ASSERT_EQUAL(LogLevelManager::GetLogLevel("Info"), LogLevel::Info);
    ASSERT_EQUAL(LogLevelManager::GetLogLevel("Warn"), LogLevel::Warn);
    ASSERT_EQUAL(LogLevelManager::GetLogLevel("Error"), LogLevel::Error);
    ASSERT_EQUAL(LogLevelManager::GetLogLevel("Fatal"), LogLevel::Fatal);
}
