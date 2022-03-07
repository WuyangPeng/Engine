// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/13 16:38)

#include "BoostMainManagerUseThreadsTesting.h"
#include "System/Helper/PragmaWarning/AsioPost.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Threading/ScopedMutex.h"
#include "Network/Configuration/ConfigurationStrategy.h"
#include "Network/Interface/BaseMainManager.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTestingDetail.h"

#include "System/Helper/PragmaWarning/Bind.h"

using boost::bind;
using std::atomic_int;
using std::mutex;
using std::ostream;
using std::unique_lock;

Network::BoostMainManagerUseThreadsTesting ::BoostMainManagerUseThreadsTesting(const OStreamShared& osPtr)
    : ParentType{ osPtr }, m_IntCount{ 0 }, m_Int16Count{ 0 }, m_ConditionVariable{}
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, BoostMainManagerUseThreadsTesting)
void Network::BoostMainManagerUseThreadsTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::BoostMainManagerUseThreadsTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SingletonTest);
}

void Network::BoostMainManagerUseThreadsTesting ::SingletonTest()
{
    ASSERT_NOT_THROW_EXCEPTION_2(ThreadsBoostSingletonTest<ClassType>, this, &ClassType::IncrementTest);
    ASSERT_NOT_THROW_EXCEPTION_2(ThreadsBoostSingletonTest<ClassType>, this, &ClassType::SleepIncrementTest);
}

void Network::BoostMainManagerUseThreadsTesting ::IncrementTest()
{
    auto& ioContext = BASE_MAIN_MANAGER_SINGLETON.GetIOContext();

    m_IntCount = 0;

    boost::asio::post(ioContext, boost::bind(&ClassType::Increment, this));

    ASSERT_FALSE(BASE_MAIN_MANAGER_SINGLETON.IsContextStop());
    BASE_MAIN_MANAGER_SINGLETON.StopContext();
    ASSERT_EQUAL(m_IntCount, 1);
    ASSERT_TRUE(BASE_MAIN_MANAGER_SINGLETON.IsContextStop());

    const auto incrementCount = GetTestLoopCount();

    BASE_MAIN_MANAGER_SINGLETON.RestartContext();
    for (auto i = 0; i < incrementCount; ++i)
    {
        boost::asio::post(ioContext, bind(&ClassType::Increment, this));
    }

    ASSERT_FALSE(BASE_MAIN_MANAGER_SINGLETON.IsContextStop());
    BASE_MAIN_MANAGER_SINGLETON.StopContext();
    ASSERT_EQUAL(m_IntCount, 1 + incrementCount);
    ASSERT_TRUE(BASE_MAIN_MANAGER_SINGLETON.IsContextStop());
}

void Network::BoostMainManagerUseThreadsTesting ::SleepIncrementTest()
{
    auto& ioContext = BASE_MAIN_MANAGER_SINGLETON.GetIOContext();

    m_IntCount = 0;
    m_Int16Count = 0;

    boost::asio::post(ioContext, bind(&ClassType::IntSleepIncrement, this, boost::ref(ioContext), boost::ref(m_IntCount)));
    boost::asio::post(ioContext, bind(&ClassType::Int16SleepIncrement, this, boost::ref(ioContext), boost::ref(m_Int16Count)));

    const auto endCount = GetTestLoopCount() + 1;

    mutex testMutex;
    unique_lock lock{ testMutex };
    m_ConditionVariable.wait(lock);

    ASSERT_FALSE(BASE_MAIN_MANAGER_SINGLETON.IsContextStop());
    BASE_MAIN_MANAGER_SINGLETON.StopContext();
    ASSERT_EQUAL(m_IntCount, endCount);
    ASSERT_EQUAL(m_Int16Count, endCount);
    ASSERT_TRUE(BASE_MAIN_MANAGER_SINGLETON.IsContextStop());
}

void Network::BoostMainManagerUseThreadsTesting ::Increment() noexcept
{
    ++m_IntCount;
}

void Network::BoostMainManagerUseThreadsTesting ::IntSleepIncrement(IOContextType& ioContext, atomic_int& count)
{
    const auto endCount = GetTestLoopCount() + 1;

    if (++count < endCount)
    {
        boost::asio::post(ioContext, bind(&ClassType::IntSleepIncrement, this, boost::ref(ioContext), boost::ref(count)));
    }

    if (endCount <= m_IntCount && endCount <= m_Int16Count)
    {
        m_ConditionVariable.notify_one();
    }
}

void Network::BoostMainManagerUseThreadsTesting ::Int16SleepIncrement(IOContextType& ioContext, std::atomic_int16_t& count)
{
    const auto endCount = GetTestLoopCount() + 1;

    if (++count < endCount)
    {
        boost::asio::post(ioContext, bind(&ClassType::Int16SleepIncrement, this, boost::ref(ioContext), boost::ref(count)));
    }

    if (endCount <= m_IntCount && endCount <= m_Int16Count)
    {
        m_ConditionVariable.notify_one();
    }
}
