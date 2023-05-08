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
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/Helper/UserMacro.h"
#include "Network/Interface/SockAcceptor.h"
#include "Network/Interface/SockAddress.h"
#include "Network/Interface/SockStream.h"
#include "Network/NetworkTesting/InterfaceSuite/Detail/TestSocketManager.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTestingDetail.h"
using std::make_shared;
using std::string;

Network::ACESockAcceptorTesting::ACESockAcceptorTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, ACESockAcceptorTesting)

void Network::ACESockAcceptorTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

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

    ++port;

    TestingType sockAcceptor1{ port - 1, GetACEServerConfigurationStrategy() };
    TestingType sockAcceptor2{ hostName, port + 9, GetACEServerConfigurationStrategy() };
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26414)
    SockStreamSharedPtr sockStream{ make_shared<SockStream>(GetACEServerConfigurationStrategy()) };
    SockAddressSharedPtr sockAddress{ make_shared<SockAddress>(GetACEServerConfigurationStrategy()) };
    //  SocketManagerSharedPtr socketManager{ make_shared<TestSocketManager>(5) };

    auto enableNonBlock = sockAcceptor1.EnableNonBlock();

    auto result = sockAcceptor1.Accept(*sockStream);
    result = sockAcceptor1.Accept(*sockStream, *sockAddress);
    //  sockAcceptor1.AsyncAccept(socketManager, sockStream, sockAddress);
    //  sockAcceptor1.AsyncAccept(socketManager, sockStream);

    enableNonBlock = sockAcceptor2.EnableNonBlock();

    result = sockAcceptor2.Accept(*sockStream);
    result = sockAcceptor2.Accept(*sockStream, *sockAddress);
    //  sockAcceptor2.AsyncAccept(socketManager, sockStream, sockAddress);
    //  sockAcceptor2.AsyncAccept(socketManager, sockStream);
#include STSTEM_WARNING_POP
}
