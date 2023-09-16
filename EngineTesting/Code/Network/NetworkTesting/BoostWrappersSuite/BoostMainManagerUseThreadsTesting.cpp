///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/16 10:35)

#include "BoostMainManagerUseThreadsTesting.h"
#include "System/Helper/PragmaWarning/AsioPost.h"
#include "System/Helper/PragmaWarning/Bind.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Threading/ScopedMutex.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/Interface/BaseMainManager.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTestingDetail.h"

Network::BoostMainManagerUseThreadsTesting::BoostMainManagerUseThreadsTesting(const OStreamShared& stream)
    : ParentType{ stream }, intCount{ 0 }, int16Count{ 0 }, conditionVariable{}
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, BoostMainManagerUseThreadsTesting)

void Network::BoostMainManagerUseThreadsTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::BoostMainManagerUseThreadsTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SingletonTest);
}

void Network::BoostMainManagerUseThreadsTesting::SingletonTest()
{
    ASSERT_NOT_THROW_EXCEPTION_2(ThreadsBoostSingletonTest<ClassType>, this, &ClassType::IncrementTest);
    ASSERT_NOT_THROW_EXCEPTION_2(ThreadsBoostSingletonTest<ClassType>, this, &ClassType::SleepIncrementTest);
}

void Network::BoostMainManagerUseThreadsTesting::IncrementTest()
{
    auto& ioContext = BASE_MAIN_MANAGER_SINGLETON.GetContext();

    intCount = 0;

    post(ioContext, boost::bind(&ClassType::Increment, this));

    ASSERT_FALSE(BASE_MAIN_MANAGER_SINGLETON.IsContextStop());
    BASE_MAIN_MANAGER_SINGLETON.StopContext();
    ASSERT_EQUAL(intCount, 1);
    ASSERT_TRUE(BASE_MAIN_MANAGER_SINGLETON.IsContextStop());

    const auto incrementCount = GetTestLoopCount();

    BASE_MAIN_MANAGER_SINGLETON.RestartContext();
    for (auto i = 0; i < incrementCount; ++i)
    {
        post(ioContext, boost::bind(&ClassType::Increment, this));
    }

    ASSERT_FALSE(BASE_MAIN_MANAGER_SINGLETON.IsContextStop());
    BASE_MAIN_MANAGER_SINGLETON.StopContext();
    ASSERT_EQUAL(intCount, 1 + incrementCount);
    ASSERT_TRUE(BASE_MAIN_MANAGER_SINGLETON.IsContextStop());
}

void Network::BoostMainManagerUseThreadsTesting::SleepIncrementTest()
{
    auto& ioContext = BASE_MAIN_MANAGER_SINGLETON.GetContext();

    intCount = 0;
    int16Count = 0;

    post(ioContext, bind(&ClassType::IntSleepIncrement, this, boost::ref(ioContext), boost::ref(intCount)));
    post(ioContext, bind(&ClassType::Int16SleepIncrement, this, boost::ref(ioContext), boost::ref(int16Count)));

    const auto endCount = GetTestLoopCount() + 1;

    std::mutex testMutex;
    std::unique_lock lock{ testMutex };
    conditionVariable.wait(lock);

    ASSERT_FALSE(BASE_MAIN_MANAGER_SINGLETON.IsContextStop());
    BASE_MAIN_MANAGER_SINGLETON.StopContext();
    ASSERT_EQUAL(intCount, endCount);
    ASSERT_EQUAL(int16Count, endCount);
    ASSERT_TRUE(BASE_MAIN_MANAGER_SINGLETON.IsContextStop());
}

void Network::BoostMainManagerUseThreadsTesting::Increment() noexcept
{
    ++intCount;
}

void Network::BoostMainManagerUseThreadsTesting::IntSleepIncrement(IoContextType& ioContext, std::atomic_int& count)
{
    const auto endCount = GetTestLoopCount() + 1;

    if (++count < endCount)
    {
        post(ioContext, bind(&ClassType::IntSleepIncrement, this, boost::ref(ioContext), boost::ref(count)));
    }

    if (endCount <= intCount && endCount <= int16Count)
    {
        conditionVariable.notify_one();
    }
}

void Network::BoostMainManagerUseThreadsTesting::Int16SleepIncrement(IoContextType& ioContext, std::atomic_int16_t& count)
{
    const auto endCount = GetTestLoopCount() + 1;

    if (++count < endCount)
    {
        post(ioContext, bind(&ClassType::Int16SleepIncrement, this, boost::ref(ioContext), boost::ref(count)));
    }

    if (endCount <= intCount && endCount <= int16Count)
    {
        conditionVariable.notify_one();
    }
}
