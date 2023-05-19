///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.8 (2023/05/18 10:25)

#include "BoostMainManagerUseMultiContextTesting.h"
#include "System/Helper/PragmaWarning/AsioPost.h"
#include "System/Helper/PragmaWarning/Bind.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Threading/ScopedMutex.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/Interface/BaseMainManager.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTestingDetail.h"

Network::BoostMainManagerUseMultiContextTesting::BoostMainManagerUseMultiContextTesting(const OStreamShared& stream)
    : ParentType{ stream }, count{ 0 }, conditionVariable{}
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, BoostMainManagerUseMultiContextTesting)

void Network::BoostMainManagerUseMultiContextTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::BoostMainManagerUseMultiContextTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SingletonTest);
}

void Network::BoostMainManagerUseMultiContextTesting::SingletonTest()
{
    ASSERT_NOT_THROW_EXCEPTION_2(MultiContextBoostSingletonTest<ClassType>, this, &ClassType::IncrementTest);
    ASSERT_NOT_THROW_EXCEPTION_2(MultiContextBoostSingletonTest<ClassType>, this, &ClassType::DecrementToZeroTest);
}

void Network::BoostMainManagerUseMultiContextTesting::IncrementTest()
{
    auto& ioContext = BASE_MAIN_MANAGER_SINGLETON.GetContext();

    count = 0;

    post(ioContext, boost::bind(&ClassType::Increment, this));

    ASSERT_FALSE(BASE_MAIN_MANAGER_SINGLETON.IsContextStop());
    BASE_MAIN_MANAGER_SINGLETON.StopContext();
    ASSERT_EQUAL(count, 1);
    ASSERT_TRUE(BASE_MAIN_MANAGER_SINGLETON.IsContextStop());

    const auto incrementCount = GetTestLoopCount();

    BASE_MAIN_MANAGER_SINGLETON.RestartContext();
    for (auto i = 0; i < incrementCount; ++i)
    {
        post(ioContext, boost::bind(&ClassType::Increment, this));
    }

    ASSERT_FALSE(BASE_MAIN_MANAGER_SINGLETON.IsContextStop());
    BASE_MAIN_MANAGER_SINGLETON.StopContext();
    ASSERT_EQUAL(count, 1 + incrementCount);
    ASSERT_TRUE(BASE_MAIN_MANAGER_SINGLETON.IsContextStop());
}

void Network::BoostMainManagerUseMultiContextTesting::DecrementToZeroTest()
{
    auto& ioContext = BASE_MAIN_MANAGER_SINGLETON.GetContext();

    const auto initCount = GetTestLoopCount() + 1;
    count = initCount;

    post(ioContext, bind(&ClassType::DecrementToZero, this, boost::ref(ioContext)));

    std::mutex testMutex;
    std::unique_lock lock{ testMutex };
    conditionVariable.wait(lock);

    ASSERT_FALSE(BASE_MAIN_MANAGER_SINGLETON.IsContextStop());
    BASE_MAIN_MANAGER_SINGLETON.StopContext();
    ASSERT_EQUAL(count, 0);
    ASSERT_TRUE(BASE_MAIN_MANAGER_SINGLETON.IsContextStop());
}

void Network::BoostMainManagerUseMultiContextTesting::Increment() noexcept
{
    ++count;
}

void Network::BoostMainManagerUseMultiContextTesting::DecrementToZero(IoContextType& ioContext)
{
    if (0 < count)
    {
        --count;

        const int beforeValue{ count };
        post(ioContext, bind(&ClassType::DecrementToZero, this, boost::ref(ioContext)));

        ASSERT_EQUAL(count, beforeValue);
    }
    else
    {
        conditionVariable.notify_one();
    }
}
