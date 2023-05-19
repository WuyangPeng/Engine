///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.8 (2023/05/15 10:14)

#include "SingletonTestingDetail.h"
#include "SockAddressTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/Helper/UserMacro.h"
#include "Network/Interface/SockAddress.h"

Network::SockAddressTesting::SockAddressTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, SockAddressTesting)

void Network::SockAddressTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::SockAddressTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_2(ACESingletonTest<ClassType>, this, &ClassType::ACETest);
    ASSERT_NOT_THROW_EXCEPTION_2(BoostSingletonTest<ClassType>, this, &ClassType::BoostTest);
    ASSERT_NOT_THROW_EXCEPTION_2(NetworkSingletonTest<ClassType>, this, &ClassType::NetworkTest);
    ASSERT_NOT_THROW_EXCEPTION_2(NullSingletonTest<ClassType>, this, &ClassType::NullTest);
}

void Network::SockAddressTesting::ACETest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ACEConstructionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ACEGetACEInternetAddressTest);
    ASSERT_THROW_EXCEPTION_0(ACEGetBoostInternetAddressExceptionTest);
    ASSERT_THROW_EXCEPTION_0(ACEGetNetworkInternetAddressExceptionTest);
}

void Network::SockAddressTesting::BoostTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BoostConstructionTest);
    ASSERT_THROW_EXCEPTION_0(BoostGetACEInternetAddressExceptionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(BoostGetBoostInternetAddressTest);
    ASSERT_THROW_EXCEPTION_0(BoostGetNetworkInternetAddressExceptionTest);
}

void Network::SockAddressTesting::NetworkTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NetworkConstructionTest);
    ASSERT_THROW_EXCEPTION_0(NetworkGetACEInternetAddressExceptionTest);
    ASSERT_THROW_EXCEPTION_0(NetworkGetBoostInternetAddressExceptionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(NetworkGetNetworkInternetAddressTest);
}

void Network::SockAddressTesting::ACEConstructionTest()
{
    const SockAddress sockAddress0{ GetACEServerConfigurationStrategy() };
    ASSERT_EQUAL(sockAddress0.GetAddress(), "0.0.0.0:0");
    ASSERT_EQUAL(sockAddress0.GetPort(), 0);

    const SockAddress sockAddress1{ "127.0.0.1", 8010, GetACEServerConfigurationStrategy() };
    ASSERT_EQUAL(sockAddress1.GetAddress(), "127.0.0.1:8010");
    ASSERT_EQUAL(sockAddress1.GetPort(), 8010);

    const SockAddress sockAddress2{ 8010, GetACEServerConfigurationStrategy() };
    ASSERT_EQUAL(sockAddress2.GetAddress(), "0.0.0.0:8010");
    ASSERT_EQUAL(sockAddress2.GetPort(), 8010);
}

void Network::SockAddressTesting::BoostConstructionTest()
{
    const SockAddress sockAddress0{ GetBoostServerConfigurationStrategy() };
    ASSERT_EQUAL(sockAddress0.GetAddress(), "0.0.0.0:0");
    ASSERT_EQUAL(sockAddress0.GetPort(), 0);

    const SockAddress sockAddress1{ "127.0.0.1", 8010, GetBoostServerConfigurationStrategy() };
    ASSERT_EQUAL(sockAddress1.GetAddress(), "127.0.0.1:8010");
    ASSERT_EQUAL(sockAddress1.GetPort(), 8010);

    const SockAddress sockAddress2{ 8010, GetBoostServerConfigurationStrategy() };
    ASSERT_EQUAL(sockAddress2.GetAddress(), "0.0.0.0:8010");
    ASSERT_EQUAL(sockAddress2.GetPort(), 8010);
}

void Network::SockAddressTesting::NetworkConstructionTest()
{
    const SockAddress sockAddress0{ GetNetworkServerConfigurationStrategy() };
    ASSERT_EQUAL(sockAddress0.GetAddress(), "0.0.0.0:0");
    ASSERT_EQUAL(sockAddress0.GetPort(), 0);

    const SockAddress sockAddress1{ "127.0.0.1", 8010, GetNetworkServerConfigurationStrategy() };
    ASSERT_EQUAL(sockAddress1.GetAddress(), "127.0.0.1:8010");
    ASSERT_EQUAL(sockAddress1.GetPort(), 8010);

    const SockAddress sockAddress2{ 8010, GetNetworkServerConfigurationStrategy() };
    ASSERT_EQUAL(sockAddress2.GetAddress(), "0.0.0.0:8010");
    ASSERT_EQUAL(sockAddress2.GetPort(), 8010);
}

void Network::SockAddressTesting::ACEGetACEInternetAddressTest()
{
    const SockAddress sockAddress0{ GetACEServerConfigurationStrategy() };
    MAYBE_UNUSED auto result0 = sockAddress0.GetACEInternetAddress();

    const SockAddress sockAddress1{ GetACEServerConfigurationStrategy() };
    MAYBE_UNUSED auto result1 = sockAddress1.GetACEInternetAddress();
}

void Network::SockAddressTesting::ACEGetBoostInternetAddressExceptionTest()
{
    SockAddress sockAddress{ GetACEServerConfigurationStrategy() };

    MAYBE_UNUSED const auto& result = sockAddress.GetBoostInternetAddress();
}

void Network::SockAddressTesting::ACEGetNetworkInternetAddressExceptionTest()
{
    SockAddress sockAddress{ GetACEServerConfigurationStrategy() };

    MAYBE_UNUSED const auto& result = sockAddress.GetWinSockInternetAddress();
}

void Network::SockAddressTesting::BoostGetACEInternetAddressExceptionTest()
{
    const SockAddress sockAddress0{ GetBoostServerConfigurationStrategy() };

    MAYBE_UNUSED const auto& result = sockAddress0.GetACEInternetAddress();
}

void Network::SockAddressTesting::BoostGetBoostInternetAddressTest()
{
    const SockAddress sockAddress0{ GetBoostServerConfigurationStrategy() };
    MAYBE_UNUSED const auto& result0 = sockAddress0.GetBoostInternetAddress();

    const SockAddress sockAddress1{ GetBoostServerConfigurationStrategy() };
    MAYBE_UNUSED const auto& result1 = sockAddress1.GetBoostInternetAddress();
}

void Network::SockAddressTesting::BoostGetNetworkInternetAddressExceptionTest()
{
    const SockAddress sockAddress{ GetBoostServerConfigurationStrategy() };

    MAYBE_UNUSED const auto& result = sockAddress.GetWinSockInternetAddress();
}

void Network::SockAddressTesting::NetworkGetACEInternetAddressExceptionTest()
{
    const SockAddress sockAddress{ GetNetworkServerConfigurationStrategy() };

    MAYBE_UNUSED const auto result = sockAddress.GetACEInternetAddress();
}

void Network::SockAddressTesting::NetworkGetBoostInternetAddressExceptionTest()
{
    const SockAddress sockAddress{ GetNetworkServerConfigurationStrategy() };

    MAYBE_UNUSED const auto& result = sockAddress.GetBoostInternetAddress();
}

void Network::SockAddressTesting::NetworkGetNetworkInternetAddressTest()
{
    const SockAddress sockAddress0{ GetNetworkServerConfigurationStrategy() };
    MAYBE_UNUSED const auto& result0 = sockAddress0.GetWinSockInternetAddress();

    const SockAddress sockAddress1{ GetNetworkServerConfigurationStrategy() };
    MAYBE_UNUSED const auto& result1 = sockAddress1.GetWinSockInternetAddress();
}

void Network::SockAddressTesting::NullTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NullConstructionTest);
    ASSERT_THROW_EXCEPTION_0(NullGetACEInternetAddressExceptionTest);
    ASSERT_THROW_EXCEPTION_0(NullGetBoostInternetAddressExceptionTest);
    ASSERT_THROW_EXCEPTION_0(NullGetNetworkInternetAddressExceptionTest);
}

void Network::SockAddressTesting::NullConstructionTest()
{
    const SockAddress sockAddress0{ 8010, GetNullServerConfigurationStrategy() };
    ASSERT_EQUAL(sockAddress0.GetAddress(), "0.0.0.0:8010");
    ASSERT_EQUAL(sockAddress0.GetPort(), 8010);

    const SockAddress sockAddress1{ GetNullServerConfigurationStrategy() };
    ASSERT_EQUAL(sockAddress1.GetAddress(), "0.0.0.0:0");
    ASSERT_EQUAL(sockAddress1.GetPort(), 0);

    const SockAddress sockAddress2{ "127.0.0.1", 8010, GetNullServerConfigurationStrategy() };
    ASSERT_EQUAL(sockAddress2.GetAddress(), "127.0.0.1:8010");
    ASSERT_EQUAL(sockAddress2.GetPort(), 8010);
}

void Network::SockAddressTesting::NullGetACEInternetAddressExceptionTest()
{
    SockAddress sockAddress{ GetNullServerConfigurationStrategy() };

    MAYBE_UNUSED auto result = sockAddress.GetACEInternetAddress();
}

void Network::SockAddressTesting::NullGetBoostInternetAddressExceptionTest()
{
    SockAddress sockAddress{ GetNullServerConfigurationStrategy() };

    MAYBE_UNUSED const auto& result = sockAddress.GetBoostInternetAddress();
}

void Network::SockAddressTesting::NullGetNetworkInternetAddressExceptionTest()
{
    SockAddress sockAddress{ GetNullServerConfigurationStrategy() };

    MAYBE_UNUSED const auto& result = sockAddress.GetWinSockInternetAddress();
}
