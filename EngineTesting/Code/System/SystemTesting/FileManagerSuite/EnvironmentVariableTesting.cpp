/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 13:03)

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
    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(environmentVariable, "���Կ�ܵĻ������������ڡ�"s);

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
