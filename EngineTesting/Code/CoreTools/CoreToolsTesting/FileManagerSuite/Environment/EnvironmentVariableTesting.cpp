///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 11:59)

#include "EnvironmentVariableTesting.h"
#include "CoreTools/FileManager/EnvironmentVariable.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

CoreTools::EnvironmentVariableTesting::EnvironmentVariableTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, EnvironmentVariableTesting)

void CoreTools::EnvironmentVariableTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::EnvironmentVariableTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(EnvironmentTest);
    ASSERT_NOT_THROW_EXCEPTION_0(JsonTest);
}

void CoreTools::EnvironmentVariableTesting::EnvironmentTest()
{
    EnvironmentVariable variable{ SYSTEM_TEXT("EngineInclude"s) };

    const auto path = variable.GetVariable();

    ASSERT_UNEQUAL(path.find(SYSTEM_TEXT("Code"s)), System::String::npos);
}

void CoreTools::EnvironmentVariableTesting::JsonTest()
{
    EnvironmentVariable variable{ SYSTEM_TEXT("JSON"s) };

    const auto path = variable.GetVariable();

    ASSERT_EQUAL(path, SYSTEM_TEXT("JSON"s));
}