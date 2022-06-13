///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 11:11)

#include "LogLevelManagerTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/LogManager/LogLevelManager.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, LogLevelManagerTesting)

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
