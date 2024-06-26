/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 18:29)

#include "WaitForMultipleMutexTesting.h"
#include "System/Helper/PragmaWarning/Thread.h"
#include "System/Threading/Flags/SemaphoreFlags.h"
#include "System/Threading/Mutex.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::WaitForMultipleMutexTesting::WaitForMultipleMutexTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, WaitForMultipleMutexTesting)

void System::WaitForMultipleMutexTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::WaitForMultipleMutexTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(WaitMultipleObjectsTest);
}

void System::WaitForMultipleMutexTesting::WaitMultipleObjectsTest()
{
    Container mutexHandles{};

    ASSERT_NOT_THROW_EXCEPTION_1(CreateMutexTest, mutexHandles);

    ASSERT_NOT_THROW_EXCEPTION_1(CreateThreadTest, mutexHandles);

    for (auto handle : mutexHandles)
    {
        ASSERT_NOT_THROW_EXCEPTION_1(CloseMutexTest, handle);
    }
}

void System::WaitForMultipleMutexTesting::WaitForMutexTest0(const Container& mutexHandles)
{
    const auto flag = WaitForSystemMutex(boost::numeric_cast<WindowsDWord>(mutexHandles.size()), mutexHandles.data(), true, EnumCastUnderlying(MutexWait::Infinite));
    ASSERT_UNEQUAL(flag, MutexWaitReturn::Failed);

    for (const auto handle : mutexHandles)
    {
        ASSERT_TRUE(ReleaseSystemMutex(handle));
    }
}

void System::WaitForMultipleMutexTesting::WaitForMutexTest1(const Container& mutexHandles)
{
    const auto flag = WaitForSystemMutex(boost::numeric_cast<WindowsDWord>(mutexHandles.size()), mutexHandles.data(), true, EnumCastUnderlying(MutexWait::Infinite), true);
    ASSERT_UNEQUAL(flag, MutexWaitReturn::Failed);

    for (const auto handle : mutexHandles)
    {
        ASSERT_TRUE(ReleaseSystemMutex(handle));
    }
}

void System::WaitForMultipleMutexTesting::WaitForMutexTest2(const Container& mutexHandles)
{
    const auto flag = WaitForSystemMutex(boost::numeric_cast<WindowsDWord>(mutexHandles.size()), mutexHandles.data(), true, EnumCastUnderlying(MutexWait::Infinite), false);
    ASSERT_UNEQUAL(flag, MutexWaitReturn::Failed);

    for (const auto handle : mutexHandles)
    {
        ASSERT_TRUE(ReleaseSystemMutex(handle));
    }
}

void System::WaitForMultipleMutexTesting::CreateMutexTest(Container& mutexHandles)
{
    constexpr auto mutexSize = 5;
    for (auto i = 0; i < mutexSize; ++i)
    {
        const auto handle = CreateSystemMutex();
        ASSERT_TRUE(IsSystemMutexValid(handle));

        mutexHandles.emplace_back(handle);
    }
}

void System::WaitForMultipleMutexTesting::CreateThreadTest(const Container& mutexHandles)
{
    boost::thread_group threadGroup{};
    for (auto i = 0; i < threadCount; ++i)
    {
        threadGroup.create_thread([this, mutexHandles]() {
            this->WaitForMutexTest0(mutexHandles);
        });

        threadGroup.create_thread([this, mutexHandles]() {
            this->WaitForMutexTest1(mutexHandles);
        });

        threadGroup.create_thread([this, mutexHandles]() {
            this->WaitForMutexTest2(mutexHandles);
        });
    }

    threadGroup.join_all();
}
