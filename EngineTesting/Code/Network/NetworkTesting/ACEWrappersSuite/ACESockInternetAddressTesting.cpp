///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/16 10:53)

#include "ACESockInternetAddressTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/Interface/SockAddress.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTestingDetail.h"

Network::ACESockInternetAddressTesting::ACESockInternetAddressTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, ACESockInternetAddressTesting)

void Network::ACESockInternetAddressTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::ACESockInternetAddressTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_2(ACESingletonTest<ClassType>, this, &ClassType::AddressTest);
}

void Network::ACESockInternetAddressTesting::AddressTest()
{
    const std::string aceHostName{ "127.0.0.1" };
    constexpr auto acePort = 7300;

    const SockAddress sockAddress{ aceHostName, acePort, GetBoostServerConfigurationStrategy() };

    ASSERT_EQUAL(sockAddress.GetPort(), acePort);
    ASSERT_EQUAL(sockAddress.GetAddress(), aceHostName + ":" + std::to_string(acePort));
}
