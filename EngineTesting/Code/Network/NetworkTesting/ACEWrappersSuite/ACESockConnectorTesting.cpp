// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/13 16:11)

#include "ACESockConnectorTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Configuration/ConfigurationParameter.h"
#include "Network/Helper/UserMacro.h"
#include "Network/Interface/SockAddress.h"
#include "Network/Interface/SockConnector.h"
#include "Network/Interface/SockStream.h"
#include "Network/NetworkTesting/InterfaceSuite/Detail/TestSocketManager.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTestingDetail.h"

#include <thread>

using std::make_shared;
using std::thread;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Network, ACESockConnectorTesting)

namespace Network
{
    using TestingType = SockConnector;
}

void Network::ACESockConnectorTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_2(ACESingletonTest<ClassType>, this, &ClassType::ConnectorTest);
}

void Network::ACESockConnectorTesting ::ConnectorTest()
{
    ConfigurationStrategy clientConfigurationStrategy{ GetACEServerConfigurationStrategy() };
    TestingType sockConnector{ clientConfigurationStrategy };

    TestSocketManagerSharedPtr socketManager{ make_shared<TestSocketManager>(5) };
    SockStreamSharedPtr sockStream{ make_shared<SockStream>(clientConfigurationStrategy) };
    SockAddressSharedPtr sockAddress{ make_shared<SockAddress>(clientConfigurationStrategy.GetIP(), clientConfigurationStrategy.GetPort(), clientConfigurationStrategy) };

    [[maybe_unused]] auto value = sockConnector.Connect(sockStream, sockAddress);
    sockConnector.AsyncConnect(socketManager, sockStream, sockAddress);
}
