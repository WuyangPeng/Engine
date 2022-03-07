// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒýÇæ²âÊÔ°æ±¾£º0.0.2.4 (2020/03/13 16:29)

#include "BoostSockConnectorHandleTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Interface/SockAddress.h"
#include "Network/Interface/SockConnector.h"
#include "Network/Interface/SockStream.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTestingDetail.h"

using std::make_shared;
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26414)
#include SYSTEM_WARNING_DISABLE(26418)
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26429)
UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Network, BoostSockConnectorHandleTesting)

void Network::BoostSockConnectorHandleTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_2(BoostSingletonTest<ClassType>, this, &ClassType::ConnectorTest);
}

void Network::BoostSockConnectorHandleTesting ::ConnectorTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CopyConstructorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyOperatorTest);
}

void Network::BoostSockConnectorHandleTesting ::CopyConstructorTest()
{
    auto configurationStrategy = GetBoostServerConfigurationStrategy(GetRealOffset());

    SockStreamSharedPtr sockStream{ make_shared<SockStream>(configurationStrategy) };
    SockAddressSharedPtr sockAddress{ make_shared<SockAddress>(configurationStrategy.GetIP(), configurationStrategy.GetPort(), configurationStrategy) };

    TestingType sockConnector{ configurationStrategy };
  //  TestingType copySockConnector{ sockConnector };

    // ´¥·¢¸´ÖÆ²Ù×÷
 //   [[maybe_unused]] auto value = copySockConnector.Connect(sockStream, sockAddress);
}

void Network::BoostSockConnectorHandleTesting ::CopyOperatorTest()
{
    auto configurationStrategy = GetBoostServerConfigurationStrategy(GetRealOffset());

    SockStreamSharedPtr sockStream{ make_shared<SockStream>(configurationStrategy) };
    SockAddressSharedPtr sockAddress{ make_shared<SockAddress>(configurationStrategy.GetIP(), configurationStrategy.GetPort(), configurationStrategy) };

    TestingType sockConnector{ configurationStrategy };
    TestingType copySockConnector{ GetBoostClientConfigurationStrategy() };

  //  copySockConnector = sockConnector;

    // ´¥·¢¸´ÖÆ²Ù×÷
   // copySockConnector.Connect(sockStream, sockAddress);
}
