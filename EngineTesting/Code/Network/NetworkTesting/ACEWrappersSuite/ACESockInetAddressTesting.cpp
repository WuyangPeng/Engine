///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/25 14:21)

#include "ACESockInetAddressTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Helper/UserMacro.h"
#include "Network/Interface/SockAddress.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTestingDetail.h"

using std::string;
using std::to_string;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Network, ACESockInetAddressTesting)

namespace Network
{
    using TestingType = SockAddress;
}

void Network::ACESockInetAddressTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_2(ACESingletonTest<ClassType>, this, &ClassType::AddressTest);
}

void Network::ACESockInetAddressTesting::AddressTest()
{
    string hostName{ "127.0.0.1" };
    constexpr uint16_t port{ 7300 };

    TestingType sockAddress{ hostName, port, GetBoostServerConfigurationStrategy() };

    ASSERT_EQUAL(sockAddress.GetPort(), port);
    ASSERT_EQUAL(sockAddress.GetAddress(), hostName + ":" + to_string(port));
}
