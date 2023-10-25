///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 11:25)

#include "LogLevelManagerTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
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
}

void CoreTools::LogLevelManagerTesting::ValidTest()
{
    for (auto logLevel = LogLevel::Disabled; logLevel < LogLevel::MaxLogLevels; ++logLevel)
    {
        auto describe = LogLevelManager::GetLogLevelDescribe(logLevel);
        ASSERT_FALSE(describe.empty());
    }
}
