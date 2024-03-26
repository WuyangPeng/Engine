/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 13:03)

#include "EnvironmentVariableTesting.h"
#include "System/FileManager/EnvironmentVariable.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

System::EnvironmentVariableTesting::EnvironmentVariableTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, EnvironmentVariableTesting)

void System::EnvironmentVariableTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::EnvironmentVariableTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(EnvironmentExistTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EnvironmentNonExistentTest);
}

void System::EnvironmentVariableTesting::EnvironmentExistTest()
{
    const auto variableName = SYSTEM_TEXT("EngineTestingInclude"s);

    TChar* environmentVariable{ nullptr };

    ASSERT_TRUE(GetEnvironment(variableName, environmentVariable));
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(environmentVariable, "测试框架的环境变量不存在。"s);

    FreeEnvironment(environmentVariable);
    ASSERT_EQUAL_NULL_PTR(environmentVariable);
}

void System::EnvironmentVariableTesting::EnvironmentNonExistentTest()
{
    const auto variableName = SYSTEM_TEXT("NonExistent"s);

    TChar* environmentVariable{ nullptr };

    ASSERT_TRUE(GetEnvironment(variableName, environmentVariable));
    ASSERT_EQUAL_NULL_PTR(environmentVariable);

    if (environmentVariable != nullptr)
    {
        FreeEnvironment(environmentVariable);
        ASSERT_EQUAL_NULL_PTR(environmentVariable);
    }
}
