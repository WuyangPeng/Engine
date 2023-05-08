///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/25 13:59)

#include "BoostMainManagerUseMultiContextTesting.h"
#include "System/Helper/PragmaWarning/AsioPost.h"
#include "System/Helper/PragmaWarning/Bind.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Threading/ScopedMutex.h"
#include "Network/Interface/BaseMainManager.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTestingDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
using boost::bind;
using boost::ref;
using std::mutex;
using std::ostream;
using std::unique_lock;

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
    auto& ioContext = BASE_MAIN_MANAGER_SINGLETON.GetIOContext();

    count = 0;

    boost::asio::post(ioContext, bind(&ClassType::Increment, this));

    ASSERT_FALSE(BASE_MAIN_MANAGER_SINGLETON.IsContextStop());
    BASE_MAIN_MANAGER_SINGLETON.StopContext();
    ASSERT_EQUAL(count, 1);
    ASSERT_TRUE(BASE_MAIN_MANAGER_SINGLETON.IsContextStop());

    const auto incrementCount = GetTestLoopCount();

    BASE_MAIN_MANAGER_SINGLETON.RestartContext();
    for (auto i = 0; i < incrementCount; ++i)
    {
        boost::asio::post(ioContext, bind(&ClassType::Increment, this));
    }

    ASSERT_FALSE(BASE_MAIN_MANAGER_SINGLETON.IsContextStop());
    BASE_MAIN_MANAGER_SINGLETON.StopContext();
    ASSERT_EQUAL(count, 1 + incrementCount);
    ASSERT_TRUE(BASE_MAIN_MANAGER_SINGLETON.IsContextStop());
}

void Network::BoostMainManagerUseMultiContextTesting::DecrementToZeroTest()
{
    auto& ioContext = BASE_MAIN_MANAGER_SINGLETON.GetIOContext();

    const auto initCount = GetTestLoopCount() + 1;
    count = initCount;

    boost::asio::post(ioContext, bind(&ClassType::DecrementToZero, this, boost::ref(ioContext)));

    mutex testMutex;
    unique_lock lock{ testMutex };
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

void Network::BoostMainManagerUseMultiContextTesting::DecrementToZero(IOContextType& ioContext)
{
    if (0 < count)
    {
        --count;

        const int beforeValue{ count };
        boost::asio::post(ioContext, bind(&ClassType::DecrementToZero, this, boost::ref(ioContext)));

        ASSERT_EQUAL(count, beforeValue);
    }
    else
    {
        conditionVariable.notify_one();
    }
}
