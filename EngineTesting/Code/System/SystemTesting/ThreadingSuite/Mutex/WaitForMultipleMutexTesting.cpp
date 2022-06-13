///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/12 18:51)

#include "WaitForMultipleMutexTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/PragmaWarning/Thread.h"
#include "System/Threading/Flags/SemaphoreFlags.h"
#include "System/Threading/Mutex.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <vector>

using std::vector;

System::WaitForMultipleMutexTesting::WaitForMultipleMutexTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
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
    constexpr auto threadCount = 12;
    constexpr auto mutexSize = 5;
    vector<WindowsHandle> mutexHandle{};

    for (auto i = 0; i < mutexSize; ++i)
    {
        auto handle = CreateSystemMutex();
        ASSERT_TRUE(IsSystemMutexValid(handle));

        mutexHandle.emplace_back(handle);
    }

    boost::thread_group threadGroup{};
    for (auto i = 0; i < threadCount; ++i)
    {
        threadGroup.create_thread(boost::bind(&ClassType::WaitForMutexTest0, this, mutexHandle));
        threadGroup.create_thread(boost::bind(&ClassType::WaitForMutexTest1, this, mutexHandle));
        threadGroup.create_thread(boost::bind(&ClassType::WaitForMutexTest2, this, mutexHandle));
    }

    threadGroup.join_all();

    for (auto handle : mutexHandle)
    {
        ASSERT_TRUE(CloseSystemMutex(handle));
    }
}

void System::WaitForMultipleMutexTesting::WaitForMutexTest0(const std::vector<WindowsHandle>& mutexHandle)
{
    const auto flag = WaitForSystemMutex(boost::numeric_cast<WindowsDWord>(mutexHandle.size()), mutexHandle.data(), true, EnumCastUnderlying(MutexWait::Infinite));
    ASSERT_ENUM_UNEQUAL(flag, MutexWaitReturn::Failed);

    for (auto handle : mutexHandle)
    {
        ASSERT_TRUE(ReleaseSystemMutex(handle));
    }
}

void System::WaitForMultipleMutexTesting::WaitForMutexTest1(const std::vector<WindowsHandle>& mutexHandle)
{
    const auto flag = WaitForSystemMutex(boost::numeric_cast<WindowsDWord>(mutexHandle.size()), mutexHandle.data(), true, EnumCastUnderlying(MutexWait::Infinite), true);
    ASSERT_ENUM_UNEQUAL(flag, MutexWaitReturn::Failed);

    for (auto handle : mutexHandle)
    {
        ASSERT_TRUE(ReleaseSystemMutex(handle));
    }
}

void System::WaitForMultipleMutexTesting::WaitForMutexTest2(const std::vector<WindowsHandle>& mutexHandle)
{
    const auto flag = WaitForSystemMutex(boost::numeric_cast<WindowsDWord>(mutexHandle.size()), mutexHandle.data(), true, EnumCastUnderlying(MutexWait::Infinite), false);
    ASSERT_ENUM_UNEQUAL(flag, MutexWaitReturn::Failed);

    for (auto handle : mutexHandle)
    {
        ASSERT_TRUE(ReleaseSystemMutex(handle));
    }
}
