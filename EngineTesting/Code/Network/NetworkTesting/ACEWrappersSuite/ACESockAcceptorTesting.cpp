///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/25 14:18)

#include "ACESockAcceptorTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Helper/UserMacro.h"
#include "Network/Interface/SockAcceptor.h"
#include "Network/Interface/SockAddress.h"
#include "Network/Interface/SockStream.h"
#include "Network/NetworkTesting/InterfaceSuite/Detail/TestSocketManager.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTestingDetail.h"

using std::make_shared;
using std::string;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Network, ACESockAcceptorTesting)

namespace Network
{
    using TestingType = SockAcceptor;
}

void Network::ACESockAcceptorTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_2(ACESingletonTest<ClassType>, this, &ClassType::AcceptorTest);
}

void Network::ACESockAcceptorTesting::AcceptorTest()
{
    string hostName{ "127.0.0.1" };
    uint16_t port{ 9120 };

#ifdef _DEBUG

    port += 4;

#endif  // _DEBUG

#ifdef BUILDING_NETWORK_STATIC

    port += 2;

#endif  // BUILDING_NETWORK_STATIC

#ifdef _WIN64

    port += 1;

#endif  // _WIN64

    TestingType sockAcceptor1{ port, GetACEServerConfigurationStrategy() };
    TestingType sockAcceptor2{ hostName, port + 10, GetACEServerConfigurationStrategy() };

    SockStreamSharedPtr sockStream{ make_shared<SockStream>(GetACEServerConfigurationStrategy()) };
    SockAddressSharedPtr sockAddress{ make_shared<SockAddress>(GetACEServerConfigurationStrategy()) };
    SocketManagerSharedPtr socketManager{ make_shared<TestSocketManager>(5) };

    auto enableNonBlock = sockAcceptor1.EnableNonBlock();

    auto result = sockAcceptor1.Accept(*sockStream);
    result = sockAcceptor1.Accept(*sockStream, *sockAddress);
    sockAcceptor1.AsyncAccept(socketManager, sockStream, sockAddress);
    sockAcceptor1.AsyncAccept(socketManager, sockStream);

    enableNonBlock = sockAcceptor2.EnableNonBlock();

    result = sockAcceptor2.Accept(*sockStream);
    result = sockAcceptor2.Accept(*sockStream, *sockAddress);
    sockAcceptor2.AsyncAccept(socketManager, sockStream, sockAddress);
    sockAcceptor2.AsyncAccept(socketManager, sockStream);
}
