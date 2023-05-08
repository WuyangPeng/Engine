///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/24 15:10)

#include "SingletonTestingDetail.h"
#include "SockAddressTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Helper/UserMacro.h"
#include "Network/Interface/SockAddress.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
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
    ASSERT_NOT_THROW_EXCEPTION_0(ACEGetACEInetAddressTest);
    ASSERT_THROW_EXCEPTION_0(ACEGetBoostInetAddressExceptionTest);
    ASSERT_THROW_EXCEPTION_0(ACEGetNetworkInetAddressExceptionTest);
}

void Network::SockAddressTesting::BoostTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BoostConstructionTest);
    ASSERT_THROW_EXCEPTION_0(BoostGetACEInetAddressExceptionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(BoostGetBoostInetAddressTest);
    ASSERT_THROW_EXCEPTION_0(BoostGetNetworkInetAddressExceptionTest);
}

void Network::SockAddressTesting::NetworkTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NetworkConstructionTest);
    ASSERT_THROW_EXCEPTION_0(NetworkGetACEInetAddressExceptionTest);
    ASSERT_THROW_EXCEPTION_0(NetworkGetBoostInetAddressExceptionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(NetworkGetNetworkInetAddressTest);
}

void Network::SockAddressTesting::ACEConstructionTest()
{
    SockAddress sockAddress1{ GetACEServerConfigurationStrategy() };
    ASSERT_EQUAL(sockAddress1.GetAddress(), "0.0.0.0:0");
    ASSERT_EQUAL(sockAddress1.GetPort(), 0);

    SockAddress sockAddress2{ "127.0.0.1", 8010, GetACEServerConfigurationStrategy() };
    ASSERT_EQUAL(sockAddress2.GetAddress(), "127.0.0.1:8010");
    ASSERT_EQUAL(sockAddress2.GetPort(), 8010);

    SockAddress sockAddress3{ 8010, GetACEServerConfigurationStrategy() };
    ASSERT_EQUAL(sockAddress3.GetAddress(), "0.0.0.0:8010");
    ASSERT_EQUAL(sockAddress3.GetPort(), 8010);
}

void Network::SockAddressTesting::BoostConstructionTest()
{
    SockAddress sockAddress1{ GetBoostServerConfigurationStrategy() };
    ASSERT_EQUAL(sockAddress1.GetAddress(), "0.0.0.0:0");
    ASSERT_EQUAL(sockAddress1.GetPort(), 0);

    SockAddress sockAddress2{ "127.0.0.1", 8010, GetBoostServerConfigurationStrategy() };
    ASSERT_EQUAL(sockAddress2.GetAddress(), "127.0.0.1:8010");
    ASSERT_EQUAL(sockAddress2.GetPort(), 8010);

    SockAddress sockAddress3{ 8010, GetBoostServerConfigurationStrategy() };
    ASSERT_EQUAL(sockAddress3.GetAddress(), "0.0.0.0:8010");
    ASSERT_EQUAL(sockAddress3.GetPort(), 8010);
}

void Network::SockAddressTesting::NetworkConstructionTest()
{
    SockAddress sockAddress1{ GetNetworkServerConfigurationStrategy() };
    ASSERT_EQUAL(sockAddress1.GetAddress(), "0.0.0.0:0");
    ASSERT_EQUAL(sockAddress1.GetPort(), 0);

    SockAddress sockAddress2{ "127.0.0.1", 8010, GetNetworkServerConfigurationStrategy() };
    ASSERT_EQUAL(sockAddress2.GetAddress(), "127.0.0.1:8010");
    ASSERT_EQUAL(sockAddress2.GetPort(), 8010);

    SockAddress sockAddress3{ 8010, GetNetworkServerConfigurationStrategy() };
    ASSERT_EQUAL(sockAddress3.GetAddress(), "0.0.0.0:8010");
    ASSERT_EQUAL(sockAddress3.GetPort(), 8010);
}

void Network::SockAddressTesting::ACEGetACEInetAddressTest()
{
    const SockAddress sockAddress1{ GetACEServerConfigurationStrategy() };
    MAYBE_UNUSED auto value0 = sockAddress1.GetACEInetAddress();

    SockAddress sockAddress2{ GetACEServerConfigurationStrategy() };
    MAYBE_UNUSED auto value1 = sockAddress2.GetACEInetAddress();
}

void Network::SockAddressTesting::ACEGetBoostInetAddressExceptionTest()
{
    SockAddress sockAddress1{ GetACEServerConfigurationStrategy() };

    MAYBE_UNUSED const auto& value = sockAddress1.GetBoostInetAddress();
}

void Network::SockAddressTesting::ACEGetNetworkInetAddressExceptionTest()
{
    SockAddress sockAddress1{ GetACEServerConfigurationStrategy() };

    MAYBE_UNUSED const auto& value = sockAddress1.GetWinSockInetAddress();
}

void Network::SockAddressTesting::BoostGetACEInetAddressExceptionTest()
{
    SockAddress sockAddress1{ GetBoostServerConfigurationStrategy() };

    MAYBE_UNUSED const auto& value = sockAddress1.GetACEInetAddress();
}

void Network::SockAddressTesting::BoostGetBoostInetAddressTest()
{
    const SockAddress sockAddress1{ GetBoostServerConfigurationStrategy() };
    MAYBE_UNUSED const auto& value0 = sockAddress1.GetBoostInetAddress();

    SockAddress sockAddress2{ GetBoostServerConfigurationStrategy() };
    MAYBE_UNUSED const auto& value1 = sockAddress2.GetBoostInetAddress();
}

void Network::SockAddressTesting::BoostGetNetworkInetAddressExceptionTest()
{
    SockAddress sockAddress1{ GetBoostServerConfigurationStrategy() };

    MAYBE_UNUSED const auto& value = sockAddress1.GetWinSockInetAddress();
}

void Network::SockAddressTesting::NetworkGetACEInetAddressExceptionTest()
{
    SockAddress sockAddress1{ GetNetworkServerConfigurationStrategy() };

    MAYBE_UNUSED const auto value = sockAddress1.GetACEInetAddress();
}

void Network::SockAddressTesting::NetworkGetBoostInetAddressExceptionTest()
{
    SockAddress sockAddress1{ GetNetworkServerConfigurationStrategy() };

    MAYBE_UNUSED const auto& value = sockAddress1.GetBoostInetAddress();
}

void Network::SockAddressTesting::NetworkGetNetworkInetAddressTest()
{
    const SockAddress sockAddress1{ GetNetworkServerConfigurationStrategy() };
    MAYBE_UNUSED const auto& value0 = sockAddress1.GetWinSockInetAddress();

    SockAddress sockAddress2{ GetNetworkServerConfigurationStrategy() };
    MAYBE_UNUSED const auto& value1 = sockAddress2.GetWinSockInetAddress();
}

void Network::SockAddressTesting::NullTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NullConstructionTest);
    ASSERT_THROW_EXCEPTION_0(NullGetACEInetAddressExceptionTest);
    ASSERT_THROW_EXCEPTION_0(NullGetBoostInetAddressExceptionTest);
    ASSERT_THROW_EXCEPTION_0(NullGetNetworkInetAddressExceptionTest);
}

void Network::SockAddressTesting::NullConstructionTest()
{
    SockAddress sockAddress1{ GetNullServerConfigurationStrategy() };
    ASSERT_EQUAL(sockAddress1.GetAddress(), "0.0.0.0:0");
    ASSERT_EQUAL(sockAddress1.GetPort(), 0);

    SockAddress sockAddress2{ "127.0.0.1", 8010, GetNullServerConfigurationStrategy() };
    ASSERT_EQUAL(sockAddress2.GetAddress(), "127.0.0.1:8010");
    ASSERT_EQUAL(sockAddress2.GetPort(), 8010);

    SockAddress sockAddress3{ 8010, GetNullServerConfigurationStrategy() };
    ASSERT_EQUAL(sockAddress3.GetAddress(), "0.0.0.0:8010");
    ASSERT_EQUAL(sockAddress3.GetPort(), 8010);
}

void Network::SockAddressTesting::NullGetACEInetAddressExceptionTest()
{
    SockAddress sockAddress1{ GetNullServerConfigurationStrategy() };

    MAYBE_UNUSED auto value = sockAddress1.GetACEInetAddress();
}

void Network::SockAddressTesting::NullGetBoostInetAddressExceptionTest()
{
    SockAddress sockAddress1{ GetNullServerConfigurationStrategy() };

    MAYBE_UNUSED const auto& value = sockAddress1.GetBoostInetAddress();
}

void Network::SockAddressTesting::NullGetNetworkInetAddressExceptionTest()
{
    SockAddress sockAddress1{ GetNullServerConfigurationStrategy() };

    MAYBE_UNUSED const auto& value = sockAddress1.GetWinSockInetAddress();
}
