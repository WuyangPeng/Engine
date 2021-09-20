// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/13 16:37)

#include "BoostMainManagerTesting.h"  

#include "System/Helper/PragmaWarning/AsioPost.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Interface/BaseMainManager.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTestingDetail.h"

#include <boost/bind.hpp>

using std::ostream;
using boost::ref;
using boost::bind;

Network::BoostMainManagerTesting
	::BoostMainManagerTesting(const OStreamShared& osPtr)
	:ParentType{ osPtr }, m_Count{ 0 }
{
	NETWORK_SELF_CLASS_IS_VALID_1;
}

 CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, BoostMainManagerTesting)
void Network::BoostMainManagerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}


void Network::BoostMainManagerTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(SingletonTest);
}

void Network::BoostMainManagerTesting
	::SingletonTest()
{
	ASSERT_NOT_THROW_EXCEPTION_2(BoostSingletonTest<ClassType>, this, &ClassType::IncrementTest);
	ASSERT_NOT_THROW_EXCEPTION_2(BoostSingletonTest<ClassType>, this, &ClassType::DecrementToZeroTest);
}

void Network::BoostMainManagerTesting
	::IncrementTest()
{
	auto& ioContext = BASE_MAIN_MANAGER_SINGLETON.GetIOContext();

	m_Count = 0;

	boost::asio::post(ioContext, bind(&ClassType::Increment, this));
	BASE_MAIN_MANAGER_SINGLETON.StopContext();

	ASSERT_FALSE(BASE_MAIN_MANAGER_SINGLETON.IsContextStop());
	ASSERT_EQUAL(m_Count, 0);

	BASE_MAIN_MANAGER_SINGLETON.Run();
	ASSERT_TRUE(BASE_MAIN_MANAGER_SINGLETON.IsContextStop());
	ASSERT_EQUAL(m_Count, 1);

	const auto incrementCount = GetTestLoopCount();

	BASE_MAIN_MANAGER_SINGLETON.RestartContext();
	for (auto i = 0; i < incrementCount; ++i)
	{
		boost::asio::post(ioContext, bind(&ClassType::Increment, this));
	}

	BASE_MAIN_MANAGER_SINGLETON.StopContext();

	ASSERT_FALSE(BASE_MAIN_MANAGER_SINGLETON.IsContextStop());
	ASSERT_EQUAL(m_Count, 1);

	BASE_MAIN_MANAGER_SINGLETON.Run();
	ASSERT_TRUE(BASE_MAIN_MANAGER_SINGLETON.IsContextStop());
	ASSERT_EQUAL(m_Count, 1 + incrementCount);
}

void Network::BoostMainManagerTesting
	::DecrementToZeroTest()
{
	auto& ioContext = BASE_MAIN_MANAGER_SINGLETON.GetIOContext();

	const auto initCount = GetTestLoopCount() + 1;
	m_Count = initCount;

	boost::asio::post(ioContext, bind(&ClassType::DecrementToZero, this, ref(ioContext)));

	ASSERT_FALSE(BASE_MAIN_MANAGER_SINGLETON.IsContextStop());
	ASSERT_EQUAL(m_Count, initCount);

	BASE_MAIN_MANAGER_SINGLETON.Run();
	ASSERT_TRUE(BASE_MAIN_MANAGER_SINGLETON.IsContextStop());
	ASSERT_EQUAL(m_Count, 0);
}

void Network::BoostMainManagerTesting
	::Increment()
{
	++m_Count;
}

void Network::BoostMainManagerTesting
	::DecrementToZero(IOContextType& ioContext)
{
	if (0 < m_Count)
	{
		--m_Count;

		auto beforeValue = m_Count;
		boost::asio::post(ioContext, bind(&ClassType::DecrementToZero, this, ref(ioContext)));

		ASSERT_EQUAL(m_Count, beforeValue);
	}
	else
	{
		BASE_MAIN_MANAGER_SINGLETON.StopContext();
	}
}


