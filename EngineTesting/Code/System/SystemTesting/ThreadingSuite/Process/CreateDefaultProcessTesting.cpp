///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.3 (2021/05/11 16:57)

#include "CreateDefaultProcessTesting.h"
#include "System/Threading/Process.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

System::CreateDefaultProcessTesting ::CreateDefaultProcessTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
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
    ASSERT_TRUE(CreateSystemProcess(SYSTEM_TEXT("ProcessTest"s)));
}
