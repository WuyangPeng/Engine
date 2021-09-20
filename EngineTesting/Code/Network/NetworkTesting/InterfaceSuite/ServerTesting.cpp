// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/13 13:19)

#include "ServerTesting.h" 
#include "SingletonTestingDetail.h"
#include "Network/Interface/Server.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

using std::make_shared;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Network, ServerTesting)

void Network::ServerTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_2(ACESingletonTest<ClassType>, this, &ClassType::ACETest);
	ASSERT_NOT_THROW_EXCEPTION_2(BoostSingletonTest<ClassType>, this, &ClassType::BoostTest);
	ASSERT_NOT_THROW_EXCEPTION_2(NetworkSingletonTest<ClassType>, this, &ClassType::NetworkTest);
	ASSERT_NOT_THROW_EXCEPTION_2(NullSingletonTest<ClassType>, this, &ClassType::NullTest);
}

void Network::ServerTesting
	::ACETest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(ACEConstructionTest);
}

void Network::ServerTesting
	::BoostTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(BoostConstructionTest);
}

void Network::ServerTesting
	::NetworkTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(NetworkConstructionTest);
}

void Network::ServerTesting
	::NullTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(NullConstructionTest);
}

void Network::ServerTesting
	::ACEConstructionTest()
{
	ServerSharedPtr server{ make_shared<Server>(nullptr,GetACEServerConfigurationStrategy()) };
}

void Network::ServerTesting
	::BoostConstructionTest()
{
	ServerSharedPtr server{ make_shared<Server>(nullptr,GetBoostServerConfigurationStrategy()) };
}

void Network::ServerTesting
	::NetworkConstructionTest()
{
	ServerSharedPtr server{ make_shared<Server>(nullptr,GetNetworkServerConfigurationStrategy()) };
}

void Network::ServerTesting
	::NullConstructionTest()
{
	ServerSharedPtr server{ make_shared<Server>(nullptr,GetNullServerConfigurationStrategy()) };
}

