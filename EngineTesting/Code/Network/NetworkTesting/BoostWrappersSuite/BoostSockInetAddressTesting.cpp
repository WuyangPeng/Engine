// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/13 16:39)

#include "BoostSockInetAddressTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Helper/UserMacro.h"
#include "Network/Interface/SockAddress.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTestingDetail.h"

using std::make_shared;
using std::string;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Network, BoostSockInetAddressTesting)

void Network::BoostSockInetAddressTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_2(BoostSingletonTest<ClassType>, this, &ClassType::AddressTest);
}

void Network::BoostSockInetAddressTesting ::AddressTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(Address1Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Address2Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Address3Test);
    ASSERT_THROW_EXCEPTION_0(ACEAddressExceptionTest);
    ASSERT_THROW_EXCEPTION_0(WinSocketAddressExceptionTest);
}

void Network::BoostSockInetAddressTesting ::Address1Test()
{
    auto hostName = GetHostName();
    auto port = GetPort();

    TestingTypeSharedPtr sockAddress{ make_shared<TestingType>(hostName, port, GetBoostServerConfigurationStrategy()) };

    const auto& boostInetAddress = sockAddress->GetBoostInetAddress();
    ASSERT_EQUAL(boostInetAddress.port(), port);
    ASSERT_EQUAL(boostInetAddress.address().to_string(), hostName);

    ASSERT_NOT_THROW_EXCEPTION_1(CopyConstructorTest, sockAddress);
    ASSERT_NOT_THROW_EXCEPTION_1(CopyOperatorTest, sockAddress);
}

void Network::BoostSockInetAddressTesting ::Address2Test()
{
    auto port = GetPort();

    TestingTypeSharedPtr sockAddress{ make_shared<TestingType>(port, GetBoostServerConfigurationStrategy()) };

    const auto& boostInetAddress = sockAddress->GetBoostInetAddress();

    ASSERT_EQUAL(boostInetAddress.port(), port);
    ASSERT_EQUAL(boostInetAddress.address().to_string(), "0.0.0.0");

    ASSERT_NOT_THROW_EXCEPTION_1(CopyConstructorTest, sockAddress);
    ASSERT_NOT_THROW_EXCEPTION_1(CopyOperatorTest, sockAddress);
}

void Network::BoostSockInetAddressTesting ::Address3Test()
{
    TestingTypeSharedPtr sockAddress{ make_shared<TestingType>(GetBoostServerConfigurationStrategy()) };

    const auto& boostInetAddress = sockAddress->GetBoostInetAddress();

    ASSERT_EQUAL(boostInetAddress.port(), 0);
    ASSERT_EQUAL(boostInetAddress.address().to_string(), "0.0.0.0");

    ASSERT_NOT_THROW_EXCEPTION_1(CopyConstructorTest, sockAddress);
    ASSERT_NOT_THROW_EXCEPTION_1(CopyOperatorTest, sockAddress);
}

void Network::BoostSockInetAddressTesting ::CopyConstructorTest(const SockAddressSharedPtr& sockAddress)
{
    const auto& boostInetAddress = sockAddress->GetBoostInetAddress();

    TestingType copySockAddress{ *sockAddress };

    const auto& copyBoostInetAddress = copySockAddress.GetBoostInetAddress();

    ASSERT_EQUAL(copyBoostInetAddress.port(), boostInetAddress.port());
    ASSERT_EQUAL(copyBoostInetAddress.address().to_string(), boostInetAddress.address().to_string());
}

void Network::BoostSockInetAddressTesting ::CopyOperatorTest(const SockAddressSharedPtr& sockAddress)
{
    const auto& boostInetAddress = sockAddress->GetBoostInetAddress();

    TestingType copySockAddress{ GetBoostServerConfigurationStrategy() };
    copySockAddress = *sockAddress;

    const auto& copyBoostInetAddress = copySockAddress.GetBoostInetAddress();

    ASSERT_EQUAL(copyBoostInetAddress.port(), boostInetAddress.port());
    ASSERT_EQUAL(copyBoostInetAddress.address().to_string(), boostInetAddress.address().to_string());
}

void Network::BoostSockInetAddressTesting ::ACEAddressExceptionTest()
{
    TestingType sockAddress{ GetHostName(), GetPort(), GetBoostServerConfigurationStrategy() };

    [[maybe_unused]] auto value = sockAddress.GetACEInetAddress();
}

void Network::BoostSockInetAddressTesting ::WinSocketAddressExceptionTest()
{
    TestingType sockAddress{ GetHostName(), GetPort(), GetBoostServerConfigurationStrategy() };

    [[maybe_unused]] auto value = sockAddress.GetWinSockInetAddress();
}
