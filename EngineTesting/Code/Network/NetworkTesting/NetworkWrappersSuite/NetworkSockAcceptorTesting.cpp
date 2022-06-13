///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 16:59)

#include "NetworkSockAcceptorTesting.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Helper/UserMacro.h"
#include "Network/Interface/SockAcceptor.h"
#include "Network/NetworkTesting/InterfaceSuite/Detail/TestSocketManager.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTestingDetail.h"

using std::make_shared;
using std::string;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Network, NetworkSockAcceptorTesting)

namespace Network
{
    using TestingType = SockAcceptor;
}

void Network::NetworkSockAcceptorTesting::MainTest() noexcept
{
    ASSERT_NOT_THROW_EXCEPTION_2(NetworkSingletonTest<ClassType>, this, &ClassType::AcceptorTest);
}

void Network::NetworkSockAcceptorTesting::AcceptorTest()
{
    string hostName{ "127.0.0.1" };
    const auto aPort = boost::numeric_cast<uint16_t>(9140 + System::GetEngineeringOffsetValue());

    TestingType sockAcceptor1{ aPort, GetNetworkServerConfigurationStrategy() };
    TestingType sockAcceptor2{ hostName, aPort, GetNetworkServerConfigurationStrategy() };
}
