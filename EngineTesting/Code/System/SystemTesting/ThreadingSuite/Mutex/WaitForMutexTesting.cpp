///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.3 (2021/04/28 13:13)

#include "WaitForMutexTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
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
    constexpr auto threadCount = 12;

    auto mutexHandle = CreateSystemMutex();
    ASSERT_TRUE(IsSystemMutexValid(mutexHandle));

    boost::thread_group threadGroup{};
    for (auto i = 0; i < threadCount; ++i)
    {
        threadGroup.create_thread(boost::bind(&ClassType::WaitForMutexTest0, this, mutexHandle));
        threadGroup.create_thread(boost::bind(&ClassType::WaitForMutexTest1, this, mutexHandle));
        threadGroup.create_thread(boost::bind(&ClassType::WaitForMutexTest2, this, mutexHandle));
        threadGroup.create_thread(boost::bind(&ClassType::WaitForMutexTest3, this, mutexHandle));
    }

    threadGroup.join_all();

    ASSERT_TRUE(CloseSystemMutex(mutexHandle));     
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
