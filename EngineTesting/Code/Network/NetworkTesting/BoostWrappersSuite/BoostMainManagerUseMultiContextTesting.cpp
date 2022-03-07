// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/13 16:38)

#include "BoostMainManagerUseMultiContextTesting.h"
#include "System/Helper/PragmaWarning/AsioPost.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Threading/ScopedMutex.h"
#include "Network/Interface/BaseMainManager.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTestingDetail.h"

#include "System/Helper/PragmaWarning/Bind.h"

using boost::bind;
using boost::ref;
using std::mutex;
using std::ostream;
using std::unique_lock;

Network::BoostMainManagerUseMultiContextTesting ::BoostMainManagerUseMultiContextTesting(const OStreamShared& osPtr)
    : ParentType{ osPtr }, m_Count{ 0 }, m_ConditionVariable{}
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, BoostMainManagerUseMultiContextTesting)
void Network::BoostMainManagerUseMultiContextTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::BoostMainManagerUseMultiContextTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SingletonTest);
}

void Network::BoostMainManagerUseMultiContextTesting ::SingletonTest()
{
    ASSERT_NOT_THROW_EXCEPTION_2(MultiContextBoostSingletonTest<ClassType>, this, &ClassType::IncrementTest);
    ASSERT_NOT_THROW_EXCEPTION_2(MultiContextBoostSingletonTest<ClassType>, this, &ClassType::DecrementToZeroTest);
}

void Network::BoostMainManagerUseMultiContextTesting ::IncrementTest()
{
    auto& ioContext = BASE_MAIN_MANAGER_SINGLETON.GetIOContext();

    m_Count = 0;

    boost::asio::post(ioContext, bind(&ClassType::Increment, this));

    ASSERT_FALSE(BASE_MAIN_MANAGER_SINGLETON.IsContextStop());
    BASE_MAIN_MANAGER_SINGLETON.StopContext();
    ASSERT_EQUAL(m_Count, 1);
    ASSERT_TRUE(BASE_MAIN_MANAGER_SINGLETON.IsContextStop());

    const auto incrementCount = GetTestLoopCount();

    BASE_MAIN_MANAGER_SINGLETON.RestartContext();
    for (auto i = 0; i < incrementCount; ++i)
    {
        boost::asio::post(ioContext, bind(&ClassType::Increment, this));
    }

    ASSERT_FALSE(BASE_MAIN_MANAGER_SINGLETON.IsContextStop());
    BASE_MAIN_MANAGER_SINGLETON.StopContext();
    ASSERT_EQUAL(m_Count, 1 + incrementCount);
    ASSERT_TRUE(BASE_MAIN_MANAGER_SINGLETON.IsContextStop());
}

void Network::BoostMainManagerUseMultiContextTesting ::DecrementToZeroTest()
{
    auto& ioContext = BASE_MAIN_MANAGER_SINGLETON.GetIOContext();

    const auto initCount = GetTestLoopCount() + 1;
    m_Count = initCount;

    boost::asio::post(ioContext, bind(&ClassType::DecrementToZero, this, boost::ref(ioContext)));

    mutex testMutex;
    unique_lock lock{ testMutex };
    m_ConditionVariable.wait(lock);

    ASSERT_FALSE(BASE_MAIN_MANAGER_SINGLETON.IsContextStop());
    BASE_MAIN_MANAGER_SINGLETON.StopContext();
    ASSERT_EQUAL(m_Count, 0);
    ASSERT_TRUE(BASE_MAIN_MANAGER_SINGLETON.IsContextStop());
}

void Network::BoostMainManagerUseMultiContextTesting ::Increment() noexcept
{
    ++m_Count;
}

void Network::BoostMainManagerUseMultiContextTesting ::DecrementToZero(IOContextType& ioContext)
{
    if (0 < m_Count)
    {
        --m_Count;

        const int beforeValue{ m_Count };
        boost::asio::post(ioContext, bind(&ClassType::DecrementToZero, this, boost::ref(ioContext)));

        ASSERT_EQUAL(m_Count, beforeValue);
    }
    else
    {
        m_ConditionVariable.notify_one();
    }
}
