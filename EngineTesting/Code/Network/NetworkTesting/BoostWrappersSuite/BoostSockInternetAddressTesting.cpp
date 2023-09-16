///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/16 10:34)

#include "BoostSockInternetAddressTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/Interface/SockAddress.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTestingDetail.h"

Network::BoostSockInternetAddressTesting::BoostSockInternetAddressTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, BoostSockInternetAddressTesting)

void Network::BoostSockInternetAddressTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::BoostSockInternetAddressTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_2(BoostSingletonTest<ClassType>, this, &ClassType::AddressTest);
}

void Network::BoostSockInternetAddressTesting::AddressTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(Address0Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Address1Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Address2Test);
    ASSERT_THROW_EXCEPTION_0(ACEAddressExceptionTest);
    ASSERT_THROW_EXCEPTION_0(WinSocketAddressExceptionTest);
}

void Network::BoostSockInternetAddressTesting::Address0Test()
{
    const auto boostHostName = GetHostName();
    const auto boostPort = GetPort();

    const TestingType sockAddress{ boostHostName, boostPort, GetBoostServerConfigurationStrategy() };

    const auto& boostInternetAddress = sockAddress.GetBoostInternetAddress();
    ASSERT_EQUAL(boostInternetAddress.port(), boostPort);
    ASSERT_EQUAL(boostInternetAddress.address().to_string(), boostHostName);

    ASSERT_NOT_THROW_EXCEPTION_1(CopyConstructorTest, sockAddress);
    ASSERT_NOT_THROW_EXCEPTION_1(CopyOperatorTest, sockAddress);
}

void Network::BoostSockInternetAddressTesting::Address1Test()
{
    const auto boostPort = GetPort();

    const TestingType sockAddress{ boostPort, GetBoostServerConfigurationStrategy() };

    const auto& boostInternetAddress = sockAddress.GetBoostInternetAddress();

    ASSERT_EQUAL(boostInternetAddress.port(), boostPort);
    ASSERT_EQUAL(boostInternetAddress.address().to_string(), "0.0.0.0");

    ASSERT_NOT_THROW_EXCEPTION_1(CopyConstructorTest, sockAddress);
    ASSERT_NOT_THROW_EXCEPTION_1(CopyOperatorTest, sockAddress);
}

void Network::BoostSockInternetAddressTesting::Address2Test()
{
    const TestingType sockAddress{ GetBoostServerConfigurationStrategy() };

    const auto& boostInternetAddress = sockAddress.GetBoostInternetAddress();

    ASSERT_EQUAL(boostInternetAddress.port(), 0);
    ASSERT_EQUAL(boostInternetAddress.address().to_string(), "0.0.0.0");

    ASSERT_NOT_THROW_EXCEPTION_1(CopyConstructorTest, sockAddress);
    ASSERT_NOT_THROW_EXCEPTION_1(CopyOperatorTest, sockAddress);
}

void Network::BoostSockInternetAddressTesting::CopyConstructorTest(const SockAddress& sockAddress)
{
    const auto& boostInternetAddress = sockAddress.GetBoostInternetAddress();

    TestingType copySockAddress{ sockAddress };

    const auto& copyBoostInternetAddress = copySockAddress.GetBoostInternetAddress();

    ASSERT_EQUAL(copyBoostInternetAddress.port(), boostInternetAddress.port());
    ASSERT_EQUAL(copyBoostInternetAddress.address().to_string(), boostInternetAddress.address().to_string());
}

void Network::BoostSockInternetAddressTesting::CopyOperatorTest(const SockAddress& sockAddress)
{
    const auto& boostInternetAddress = sockAddress.GetBoostInternetAddress();

    TestingType copySockAddress{ GetBoostServerConfigurationStrategy() };
    copySockAddress = sockAddress;

    const auto& copyBoostInternetAddress = copySockAddress.GetBoostInternetAddress();

    ASSERT_EQUAL(copyBoostInternetAddress.port(), boostInternetAddress.port());
    ASSERT_EQUAL(copyBoostInternetAddress.address().to_string(), boostInternetAddress.address().to_string());
}

void Network::BoostSockInternetAddressTesting::ACEAddressExceptionTest()
{
    TestingType sockAddress{ GetHostName(), GetPort(), GetBoostServerConfigurationStrategy() };

    MAYBE_UNUSED auto result = sockAddress.GetACEInternetAddress();
}

void Network::BoostSockInternetAddressTesting::WinSocketAddressExceptionTest()
{
    TestingType sockAddress{ GetHostName(), GetPort(), GetBoostServerConfigurationStrategy() };

    MAYBE_UNUSED const auto& result = sockAddress.GetWinSockInternetAddress();
}
