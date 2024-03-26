/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 18:30)

#include "CreateDefaultMutexTesting.h"
#include "System/Threading/Mutex.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::CreateDefaultMutexTesting::CreateDefaultMutexTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CreateDefaultMutexTesting)

void System::CreateDefaultMutexTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::CreateDefaultMutexTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateDefaultMutexTest);
}

void System::CreateDefaultMutexTesting::CreateDefaultMutexTest()
{
    const auto mutexHandle = CreateSystemMutex();
    ASSERT_TRUE(IsSystemMutexValid(mutexHandle));

    ASSERT_NOT_THROW_EXCEPTION_1(CloseMutexTest, mutexHandle);
}
