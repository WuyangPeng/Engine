///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 15:14)

#include "WaitForMutexTesting.h"
#include "System/Helper/PragmaWarning/Thread.h"
#include "System/Threading/Flags/SemaphoreFlags.h"
#include "System/Threading/Mutex.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::WaitForMutexTesting::WaitForMutexTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, WaitForMutexTesting)

void System::WaitForMutexTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::WaitForMutexTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(WaitMutexTest);
}

void System::WaitForMutexTesting::WaitMutexTest()
{
    const auto mutexHandle = CreateSystemMutex();
    ASSERT_TRUE(IsSystemMutexValid(mutexHandle));

    ASSERT_NOT_THROW_EXCEPTION_1(CreateThread, mutexHandle);

    ASSERT_NOT_THROW_EXCEPTION_1(CloseMutexTest, mutexHandle);
}

void System::WaitForMutexTesting::WaitForMutexTest0(WindowsHandle mutexHandle)
{
    ASSERT_TRUE(WaitForSystemMutex(mutexHandle));

    ASSERT_TRUE(ReleaseSystemMutex(mutexHandle));
}

void System::WaitForMutexTesting::WaitForMutexTest1(WindowsHandle mutexHandle)
{
    const auto flag = WaitForSystemMutex(mutexHandle, EnumCastUnderlying(MutexWait::Infinite));
    ASSERT_ENUM_EQUAL(flag, MutexWaitReturn::Object0);

    ASSERT_TRUE(ReleaseSystemMutex(mutexHandle));
}

void System::WaitForMutexTesting::WaitForMutexTest2(WindowsHandle mutexHandle)
{
    const auto flag = WaitForSystemMutex(mutexHandle, EnumCastUnderlying(MutexWait::Infinite), true);
    ASSERT_ENUM_EQUAL(flag, MutexWaitReturn::Object0);

    ASSERT_TRUE(ReleaseSystemMutex(mutexHandle));
}

void System::WaitForMutexTesting::WaitForMutexTest3(WindowsHandle mutexHandle)
{
    const auto flag = WaitForSystemMutex(mutexHandle, EnumCastUnderlying(MutexWait::Infinite), false);
    ASSERT_ENUM_EQUAL(flag, MutexWaitReturn::Object0);

    ASSERT_TRUE(ReleaseSystemMutex(mutexHandle));
}

void System::WaitForMutexTesting::CreateThread(WindowsHandle mutexHandle)
{
    boost::thread_group threadGroup{};
    for (auto i = 0; i < threadCount; ++i)
    {
        threadGroup.create_thread([this, mutexHandle]() {
            this->WaitForMutexTest0(mutexHandle);
        });

        threadGroup.create_thread([this, mutexHandle]() {
            this->WaitForMutexTest1(mutexHandle);
        });

        threadGroup.create_thread([this, mutexHandle]() {
            this->WaitForMutexTest2(mutexHandle);
        });

        threadGroup.create_thread([this, mutexHandle]() {
            this->WaitForMutexTest3(mutexHandle);
        });
    }

    threadGroup.join_all();
}
