///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 11:10)

#include "LogFileNameTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/LogManager/LogFileName.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
using namespace std::literals;

CoreTools::LogFileNameTesting::LogFileNameTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, LogFileNameTesting)

void CoreTools::LogFileNameTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}
void CoreTools::LogFileNameTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(LogFileNameTest);
}

void CoreTools::LogFileNameTesting::LogFileNameTest()
{
    auto name = SYSTEM_TEXT("LogFileName"s);

    LogFileName logFileName{ name.c_str() };

    ASSERT_EQUAL(logFileName.GetFileName(), name);
}
