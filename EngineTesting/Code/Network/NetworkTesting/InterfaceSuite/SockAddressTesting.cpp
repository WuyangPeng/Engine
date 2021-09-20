// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/13 13:21)

#include "SingletonTestingDetail.h"
#include "SockAddressTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Network/Helper/UserMacro.h"
#include "Network/Interface/SockAddress.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE_USE_TESTING_TYPE(Network, SockAddress)

void Network::SockAddressTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_2(ACESingletonTest<ClassType>, this, &ClassType::ACETest);
    ASSERT_NOT_THROW_EXCEPTION_2(BoostSingletonTest<ClassType>, this, &ClassType::BoostTest);
    ASSERT_NOT_THROW_EXCEPTION_2(NetworkSingletonTest<ClassType>, this, &ClassType::NetworkTest);
    ASSERT_NOT_THROW_EXCEPTION_2(NullSingletonTest<ClassType>, this, &ClassType::NullTest);
}

void Network::SockAddressTesting ::ACETest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ACEConstructionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ACEGetACEInetAddressTest);
    ASSERT_THROW_EXCEPTION_0(ACEGetBoostInetAddressExceptionTest);
    ASSERT_THROW_EXCEPTION_0(ACEGetNetworkInetAddressExceptionTest);
}

void Network::SockAddressTesting ::BoostTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BoostConstructionTest);
    ASSERT_THROW_EXCEPTION_0(BoostGetACEInetAddressExceptionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(BoostGetBoostInetAddressTest);
    ASSERT_THROW_EXCEPTION_0(BoostGetNetworkInetAddressExceptionTest);
}

void Network::SockAddressTesting ::NetworkTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NetworkConstructionTest);
    ASSERT_THROW_EXCEPTION_0(NetworkGetACEInetAddressExceptionTest);
    ASSERT_THROW_EXCEPTION_0(NetworkGetBoostInetAddressExceptionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(NetworkGetNetworkInetAddressTest);
}

void Network::SockAddressTesting ::ACEConstructionTest()
{
    TestingType sockAddress1{ GetACEServerConfigurationStrategy() };
    ASSERT_EQUAL(sockAddress1.GetAddress(), "0.0.0.0:0");
    ASSERT_EQUAL(sockAddress1.GetPort(), 0);

    TestingType sockAddress2{ "127.0.0.1", 8010, GetACEServerConfigurationStrategy() };
    ASSERT_EQUAL(sockAddress2.GetAddress(), "127.0.0.1:8010");
    ASSERT_EQUAL(sockAddress2.GetPort(), 8010);

    TestingType sockAddress3{ 8010, GetACEServerConfigurationStrategy() };
    ASSERT_EQUAL(sockAddress3.GetAddress(), "0.0.0.0:8010");
    ASSERT_EQUAL(sockAddress3.GetPort(), 8010);
}

void Network::SockAddressTesting ::BoostConstructionTest()
{
    TestingType sockAddress1{ GetBoostServerConfigurationStrategy() };
    ASSERT_EQUAL(sockAddress1.GetAddress(), "0.0.0.0:0");
    ASSERT_EQUAL(sockAddress1.GetPort(), 0);

    TestingType sockAddress2{ "127.0.0.1", 8010, GetBoostServerConfigurationStrategy() };
    ASSERT_EQUAL(sockAddress2.GetAddress(), "127.0.0.1:8010");
    ASSERT_EQUAL(sockAddress2.GetPort(), 8010);

    TestingType sockAddress3{ 8010, GetBoostServerConfigurationStrategy() };
    ASSERT_EQUAL(sockAddress3.GetAddress(), "0.0.0.0:8010");
    ASSERT_EQUAL(sockAddress3.GetPort(), 8010);
}

void Network::SockAddressTesting ::NetworkConstructionTest()
{
    TestingType sockAddress1{ GetNetworkServerConfigurationStrategy() };
    ASSERT_EQUAL(sockAddress1.GetAddress(), "0.0.0.0:0");
    ASSERT_EQUAL(sockAddress1.GetPort(), 0);

    TestingType sockAddress2{ "127.0.0.1", 8010, GetNetworkServerConfigurationStrategy() };
    ASSERT_EQUAL(sockAddress2.GetAddress(), "127.0.0.1:8010");
    ASSERT_EQUAL(sockAddress2.GetPort(), 8010);

    TestingType sockAddress3{ 8010, GetNetworkServerConfigurationStrategy() };
    ASSERT_EQUAL(sockAddress3.GetAddress(), "0.0.0.0:8010");
    ASSERT_EQUAL(sockAddress3.GetPort(), 8010);
}

void Network::SockAddressTesting ::ACEGetACEInetAddressTest()
{
    const TestingType sockAddress1{ GetACEServerConfigurationStrategy() };
    [[maybe_unused]] auto value0 = sockAddress1.GetACEInetAddress();

    TestingType sockAddress2{ GetACEServerConfigurationStrategy() };
    [[maybe_unused]] auto value1 = sockAddress2.GetACEInetAddress();
}

void Network::SockAddressTesting ::ACEGetBoostInetAddressExceptionTest()
{
    TestingType sockAddress1{ GetACEServerConfigurationStrategy() };

     [[maybe_unused]] auto value = sockAddress1.GetBoostInetAddress();
}

void Network::SockAddressTesting ::ACEGetNetworkInetAddressExceptionTest()
{
    TestingType sockAddress1{ GetACEServerConfigurationStrategy() };

    [[maybe_unused]] auto value = sockAddress1.GetWinSockInetAddress();
}

void Network::SockAddressTesting ::BoostGetACEInetAddressExceptionTest()
{
    TestingType sockAddress1{ GetBoostServerConfigurationStrategy() };

   [[maybe_unused]] auto value = sockAddress1.GetACEInetAddress();
}

void Network::SockAddressTesting ::BoostGetBoostInetAddressTest()
{
    const TestingType sockAddress1{ GetBoostServerConfigurationStrategy() };
    [[maybe_unused]] auto value0 = sockAddress1.GetBoostInetAddress();

    TestingType sockAddress2{ GetBoostServerConfigurationStrategy() };
    [[maybe_unused]] auto value1 = sockAddress2.GetBoostInetAddress();
}

void Network::SockAddressTesting ::BoostGetNetworkInetAddressExceptionTest()
{
    TestingType sockAddress1{ GetBoostServerConfigurationStrategy() };

    [[maybe_unused]] auto value = sockAddress1.GetWinSockInetAddress();
}

void Network::SockAddressTesting ::NetworkGetACEInetAddressExceptionTest()
{
    TestingType sockAddress1{ GetNetworkServerConfigurationStrategy() };

    [[maybe_unused]] auto value = sockAddress1.GetACEInetAddress();
}

void Network::SockAddressTesting ::NetworkGetBoostInetAddressExceptionTest()
{
    TestingType sockAddress1{ GetNetworkServerConfigurationStrategy() };

    [[maybe_unused]] auto value = sockAddress1.GetBoostInetAddress();
}

void Network::SockAddressTesting ::NetworkGetNetworkInetAddressTest()
{
    const TestingType sockAddress1{ GetNetworkServerConfigurationStrategy() };
    [[maybe_unused]] auto value0 = sockAddress1.GetWinSockInetAddress();

    TestingType sockAddress2{ GetNetworkServerConfigurationStrategy() };
    [[maybe_unused]] auto value1 = sockAddress2.GetWinSockInetAddress();
}

void Network::SockAddressTesting ::NullTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NullConstructionTest);
    ASSERT_THROW_EXCEPTION_0(NullGetACEInetAddressExceptionTest);
    ASSERT_THROW_EXCEPTION_0(NullGetBoostInetAddressExceptionTest);
    ASSERT_THROW_EXCEPTION_0(NullGetNetworkInetAddressExceptionTest);
}

void Network::SockAddressTesting ::NullConstructionTest()
{
    TestingType sockAddress1{ GetNullServerConfigurationStrategy() };
    ASSERT_EQUAL(sockAddress1.GetAddress(), "0.0.0.0:0");
    ASSERT_EQUAL(sockAddress1.GetPort(), 0);

    TestingType sockAddress2{ "127.0.0.1", 8010, GetNullServerConfigurationStrategy() };
    ASSERT_EQUAL(sockAddress2.GetAddress(), "127.0.0.1:8010");
    ASSERT_EQUAL(sockAddress2.GetPort(), 8010);

    TestingType sockAddress3{ 8010, GetNullServerConfigurationStrategy() };
    ASSERT_EQUAL(sockAddress3.GetAddress(), "0.0.0.0:8010");
    ASSERT_EQUAL(sockAddress3.GetPort(), 8010);
}

void Network::SockAddressTesting ::NullGetACEInetAddressExceptionTest()
{
    TestingType sockAddress1{ GetNullServerConfigurationStrategy() };

    [[maybe_unused]] auto value = sockAddress1.GetACEInetAddress();
}

void Network::SockAddressTesting ::NullGetBoostInetAddressExceptionTest()
{
    TestingType sockAddress1{ GetNullServerConfigurationStrategy() };

    [[maybe_unused]] auto value = sockAddress1.GetBoostInetAddress();
}

void Network::SockAddressTesting ::NullGetNetworkInetAddressExceptionTest()
{
    TestingType sockAddress1{ GetNullServerConfigurationStrategy() };

    [[maybe_unused]] auto value = sockAddress1.GetWinSockInetAddress();
}
