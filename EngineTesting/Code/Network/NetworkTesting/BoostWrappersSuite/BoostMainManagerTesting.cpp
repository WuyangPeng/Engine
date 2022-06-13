///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/25 13:58)

#include "BoostMainManagerTesting.h"
#include "System/Helper/Platform.h"
#include "System/Helper/PragmaWarning/AsioPost.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Interface/BaseMainManager.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTestingDetail.h"
#include "System/Helper/PragmaWarning/Bind.h"

using boost::bind;
using boost::ref;
using std::ostream;

Network::BoostMainManagerTesting::BoostMainManagerTesting(const OStreamShared& stream)
    : ParentType{ stream }, count{ 0 }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, BoostMainManagerTesting)

void Network::BoostMainManagerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::BoostMainManagerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SingletonTest);
}

void Network::BoostMainManagerTesting::SingletonTest()
{
    ASSERT_NOT_THROW_EXCEPTION_2(BoostSingletonTest<ClassType>, this, &ClassType::IncrementTest);
    ASSERT_NOT_THROW_EXCEPTION_2(BoostSingletonTest<ClassType>, this, &ClassType::DecrementToZeroTest);
}

void Network::BoostMainManagerTesting::IncrementTest()
{
    auto& ioContext = BASE_MAIN_MANAGER_SINGLETON.GetIOContext();

    count = 0;

    boost::asio::post(ioContext, bind(&ClassType::Increment, this));
    BASE_MAIN_MANAGER_SINGLETON.StopContext();

    ASSERT_FALSE(BASE_MAIN_MANAGER_SINGLETON.IsContextStop());
    ASSERT_EQUAL(count, 0);

    BASE_MAIN_MANAGER_SINGLETON.Run();
    ASSERT_TRUE(BASE_MAIN_MANAGER_SINGLETON.IsContextStop());
    ASSERT_EQUAL(count, 1);

    const auto incrementCount = GetTestLoopCount();

    BASE_MAIN_MANAGER_SINGLETON.RestartContext();
    for (auto i = 0; i < incrementCount; ++i)
    {
        boost::asio::post(ioContext, bind(&ClassType::Increment, this));
    }

    BASE_MAIN_MANAGER_SINGLETON.StopContext();

    ASSERT_FALSE(BASE_MAIN_MANAGER_SINGLETON.IsContextStop());
    ASSERT_EQUAL(count, 1);

    BASE_MAIN_MANAGER_SINGLETON.Run();
    ASSERT_TRUE(BASE_MAIN_MANAGER_SINGLETON.IsContextStop());
    ASSERT_EQUAL(count, 1 + incrementCount);
}

void Network::BoostMainManagerTesting::DecrementToZeroTest()
{
    auto& ioContext = BASE_MAIN_MANAGER_SINGLETON.GetIOContext();

    const auto initCount = GetTestLoopCount() + 1;
    count = initCount;

    boost::asio::post(ioContext, bind(&ClassType::DecrementToZero, this, boost::ref(ioContext)));

    ASSERT_FALSE(BASE_MAIN_MANAGER_SINGLETON.IsContextStop());
    ASSERT_EQUAL(count, initCount);

    BASE_MAIN_MANAGER_SINGLETON.Run();
    ASSERT_TRUE(BASE_MAIN_MANAGER_SINGLETON.IsContextStop());
    ASSERT_EQUAL(count, 0);
}

void Network::BoostMainManagerTesting::Increment() noexcept
{
    ++count;
}

void Network::BoostMainManagerTesting::DecrementToZero(IOContextType& ioContext)
{
    if (0 < count)
    {
        --count;

        const auto beforeValue = count;
        boost::asio::post(ioContext, bind(&ClassType::DecrementToZero, this, boost::ref(ioContext)));

        ASSERT_EQUAL(count, beforeValue);
    }
    else
    {
        BASE_MAIN_MANAGER_SINGLETON.StopContext();
    }
}
