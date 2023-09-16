///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 15:08)

#include "CreateMutexUseNameTesting.h"
#include "System/Threading/Mutex.h"
#include "System/Time/DeltaTime.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::CreateMutexUseNameTesting::CreateMutexUseNameTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CreateMutexUseNameTesting)

void System::CreateMutexUseNameTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::CreateMutexUseNameTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateMutexUseNameTest);
}

void System::CreateMutexUseNameTesting::CreateMutexUseNameTest()
{
    const auto mutexName = ToString(GetTimeInSeconds()) + GetEngineeringTypesSuffix();

    const auto mutexHandle = CreateSystemMutex(nullptr, false, mutexName.c_str());

    ASSERT_TRUE(IsSystemMutexValid(mutexHandle));

    ASSERT_NOT_THROW_EXCEPTION_1(CloseMutexTest, mutexHandle);
}
