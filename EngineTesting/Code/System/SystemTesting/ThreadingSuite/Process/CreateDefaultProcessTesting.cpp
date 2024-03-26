/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 18:28)

#include "CreateDefaultProcessTesting.h"
#include "System/Threading/Process.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::CreateDefaultProcessTesting::CreateDefaultProcessTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CreateDefaultProcessTesting)

void System::CreateDefaultProcessTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::CreateDefaultProcessTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ProcessTest);
}

void System::CreateDefaultProcessTesting::ProcessTest()
{
    ASSERT_TRUE(CreateSystemProcess(SYSTEM_TEXT("ProcessTest")));
}
