///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/15 12:20)

#include "EnvironmentVariableTesting.h"
#include "System/FileManager/EnvironmentVariable.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

System::EnvironmentVariableTesting::EnvironmentVariableTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, EnvironmentVariableTesting)

void System::EnvironmentVariableTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::EnvironmentVariableTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(EnvironmentTest);
}

void System::EnvironmentVariableTesting::EnvironmentTest()
{
    const auto variableName = SYSTEM_TEXT("EngineTestingInclude"s);

    TChar* environmentVariable{ nullptr };

    ASSERT_TRUE(GetEnvironment(variableName, environmentVariable));
    ASSERT_UNEQUAL_NULL_PTR(environmentVariable);

    FreeEnvironment(environmentVariable);
    ASSERT_EQUAL_NULL_PTR(environmentVariable);
}
