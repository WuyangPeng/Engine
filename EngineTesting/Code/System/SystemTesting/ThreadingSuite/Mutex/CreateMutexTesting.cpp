///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.3 (2021/04/28 10:27)

#include "CreateMutexTesting.h"
#include "System/Threading/Mutex.h"
#include "System/Time/DeltaTime.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::CreateMutexTesting::CreateMutexTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CreateMutexTesting)

void System::CreateMutexTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::CreateMutexTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateMutexTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CreateMutexUseNameTest);
}

void System::CreateMutexTesting::CreateMutexTest()
{
    auto mutexHandle = CreateSystemMutex(nullptr, false, nullptr);

    ASSERT_TRUE(IsSystemMutexValid(mutexHandle));

    ASSERT_TRUE(CloseSystemMutex(mutexHandle));
}

void System::CreateMutexTesting::CreateMutexUseNameTest()
{
    auto mutexName = ToString(GetTimeInSeconds()) + GetEngineeringTypesSuffix();

    auto mutexHandle = CreateSystemMutex(nullptr, false, mutexName.c_str());

    ASSERT_TRUE(IsSystemMutexValid(mutexHandle));

    ASSERT_TRUE(CloseSystemMutex(mutexHandle));
}
