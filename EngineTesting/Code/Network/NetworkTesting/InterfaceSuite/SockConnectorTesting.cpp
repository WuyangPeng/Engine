// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/13 13:22)

#include "SockConnectorTesting.h" 
#include "SingletonTestingDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Network/Helper/UserMacro.h"
#include "Network/Interface/SockConnector.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE_USE_TESTING_TYPE(Network, SockConnector)

void Network::SockConnectorTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_2(ACESingletonTest<ClassType>, this, &ClassType::ACETest);
	ASSERT_NOT_THROW_EXCEPTION_2(BoostSingletonTest<ClassType>, this, &ClassType::BoostTest);
	ASSERT_NOT_THROW_EXCEPTION_2(NetworkSingletonTest<ClassType>, this, &ClassType::NetworkTest);
	ASSERT_NOT_THROW_EXCEPTION_2(NullSingletonTest<ClassType>, this, &ClassType::NullTest);
}

void Network::SockConnectorTesting
	::ACETest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(ACEConstructionTest);
}

void Network::SockConnectorTesting
	::BoostTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(BoostConstructionTest);
}

void Network::SockConnectorTesting
	::NetworkTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(NetworkConstructionTest);
}

void Network::SockConnectorTesting
	::ACEConstructionTest()
{
	TestingType connector{ GetACEServerConfigurationStrategy() };
}

void Network::SockConnectorTesting
	::BoostConstructionTest()
{
	TestingType connector{ GetBoostServerConfigurationStrategy() };
}

void Network::SockConnectorTesting
	::NetworkConstructionTest()
{
	TestingType connector{ GetNetworkServerConfigurationStrategy() };
}

void Network::SockConnectorTesting
	::NullTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(NullConstructionTest);
}

void Network::SockConnectorTesting
	::NullConstructionTest()
{
	TestingType connector{ GetNullServerConfigurationStrategy() };
}

