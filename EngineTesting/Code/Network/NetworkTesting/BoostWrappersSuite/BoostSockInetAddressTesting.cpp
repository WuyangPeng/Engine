///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/25 14:00)

#include "BoostSockInetAddressTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Helper/UserMacro.h"
#include "Network/Interface/SockAddress.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTestingDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
using std::make_shared;
using std::string;

Network::BoostSockInetAddressTesting::BoostSockInetAddressTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, BoostSockInetAddressTesting)

void Network::BoostSockInetAddressTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::BoostSockInetAddressTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_2(BoostSingletonTest<ClassType>, this, &ClassType::AddressTest);
}

void Network::BoostSockInetAddressTesting::AddressTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(Address1Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Address2Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Address3Test);
    ASSERT_THROW_EXCEPTION_0(ACEAddressExceptionTest);
    ASSERT_THROW_EXCEPTION_0(WinSocketAddressExceptionTest);
}

void Network::BoostSockInetAddressTesting::Address1Test()
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

void Network::BoostSockInetAddressTesting::Address2Test()
{
    auto port = GetPort();

    TestingTypeSharedPtr sockAddress{ make_shared<TestingType>(port, GetBoostServerConfigurationStrategy()) };

    const auto& boostInetAddress = sockAddress->GetBoostInetAddress();

    ASSERT_EQUAL(boostInetAddress.port(), port);
    ASSERT_EQUAL(boostInetAddress.address().to_string(), "0.0.0.0");

    ASSERT_NOT_THROW_EXCEPTION_1(CopyConstructorTest, sockAddress);
    ASSERT_NOT_THROW_EXCEPTION_1(CopyOperatorTest, sockAddress);
}

void Network::BoostSockInetAddressTesting::Address3Test()
{
    TestingTypeSharedPtr sockAddress{ make_shared<TestingType>(GetBoostServerConfigurationStrategy()) };

    const auto& boostInetAddress = sockAddress->GetBoostInetAddress();

    ASSERT_EQUAL(boostInetAddress.port(), 0);
    ASSERT_EQUAL(boostInetAddress.address().to_string(), "0.0.0.0");

    ASSERT_NOT_THROW_EXCEPTION_1(CopyConstructorTest, sockAddress);
    ASSERT_NOT_THROW_EXCEPTION_1(CopyOperatorTest, sockAddress);
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)

void Network::BoostSockInetAddressTesting::CopyConstructorTest(const SockAddressSharedPtr& sockAddress)
{
    const auto& boostInetAddress = sockAddress->GetBoostInetAddress();

    TestingType copySockAddress{ *sockAddress };

    const auto& copyBoostInetAddress = copySockAddress.GetBoostInetAddress();

    ASSERT_EQUAL(copyBoostInetAddress.port(), boostInetAddress.port());
    ASSERT_EQUAL(copyBoostInetAddress.address().to_string(), boostInetAddress.address().to_string());
}

void Network::BoostSockInetAddressTesting::CopyOperatorTest(const SockAddressSharedPtr& sockAddress)
{
    const auto& boostInetAddress = sockAddress->GetBoostInetAddress();

    TestingType copySockAddress{ GetBoostServerConfigurationStrategy() };
    copySockAddress = *sockAddress;

    const auto& copyBoostInetAddress = copySockAddress.GetBoostInetAddress();

    ASSERT_EQUAL(copyBoostInetAddress.port(), boostInetAddress.port());
    ASSERT_EQUAL(copyBoostInetAddress.address().to_string(), boostInetAddress.address().to_string());
}

#include STSTEM_WARNING_POP

void Network::BoostSockInetAddressTesting::ACEAddressExceptionTest()
{
    TestingType sockAddress{ GetHostName(), GetPort(), GetBoostServerConfigurationStrategy() };

    MAYBE_UNUSED auto value = sockAddress.GetACEInetAddress();
}

void Network::BoostSockInetAddressTesting::WinSocketAddressExceptionTest()
{
    TestingType sockAddress{ GetHostName(), GetPort(), GetBoostServerConfigurationStrategy() };

    MAYBE_UNUSED const auto& value = sockAddress.GetWinSockInetAddress();
}
