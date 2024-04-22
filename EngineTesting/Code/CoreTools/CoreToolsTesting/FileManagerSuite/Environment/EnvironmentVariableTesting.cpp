/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/16 16:44)

#include "EnvironmentVariableTesting.h"
#include "CoreTools/FileManager/EnvironmentVariable.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

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
    const EnvironmentVariable variable{ SYSTEM_TEXT("EngineInclude") };

    const auto path = variable.GetVariable();

    ASSERT_UNEQUAL(path.find(SYSTEM_TEXT("Code")), System::String::npos);
}

void CoreTools::EnvironmentVariableTesting::JsonTest()
{
    const EnvironmentVariable variable{ SYSTEM_TEXT("JSON") };

    const auto path = variable.GetVariable();

    ASSERT_EQUAL(path, SYSTEM_TEXT("JSON"));
}