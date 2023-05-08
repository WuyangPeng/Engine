///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/24 15:03)

#include "SingletonTestingDetail.h"
#include "SockAcceptorTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Helper/UserMacro.h"
#include "Network/Interface/SockAcceptor.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
Network::SockAcceptorTesting::SockAcceptorTesting(const OStreamShared& stream)
    : ParentType{ stream }, mPort{ 8010 }
{
#ifdef _DEBUG

    mPort += 4;

#endif  // _DEBUG

#ifdef BUILDING_NETWORK_STATIC

    mPort += 2;

#endif  // BUILDING_NETWORK_STATIC

#ifdef _WIN64

    mPort += 1;

#endif  // _WIN64

    NETWORK_SELF_CLASS_IS_VALID_0;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, SockAcceptorTesting)

void Network::SockAcceptorTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

namespace Network
{
    using TestingType = SockAcceptor;
}

void Network::SockAcceptorTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_2(ACESingletonTest<ClassType>, this, &ClassType::ACETest);
    ASSERT_NOT_THROW_EXCEPTION_2(BoostSingletonTest<ClassType>, this, &ClassType::BoostTest);
    ASSERT_NOT_THROW_EXCEPTION_2(NetworkSingletonTest<ClassType>, this, &ClassType::NetworkTest);
    ASSERT_NOT_THROW_EXCEPTION_2(NullSingletonTest<ClassType>, this, &ClassType::NullTest);
}

void Network::SockAcceptorTesting::ACETest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ACEConstructionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ACEGetACEHandleTest);
    ASSERT_THROW_EXCEPTION_0(ACEGetBoostHandleExceptionTest);
    ASSERT_THROW_EXCEPTION_0(ACEGetNetworkHandleExceptionTest);
}

void Network::SockAcceptorTesting::BoostTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BoostConstructionTest);
    ASSERT_THROW_EXCEPTION_0(BoostGetACEHandleExceptionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(BoostGetBoostHandleTest);
    ASSERT_THROW_EXCEPTION_0(BoostGetNetworkHandleExceptionTest);
}

void Network::SockAcceptorTesting::NetworkTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NetworkConstructionTest);
    ASSERT_THROW_EXCEPTION_0(NetworkGetACEHandleExceptionTest);
    ASSERT_THROW_EXCEPTION_0(NetworkGetBoostHandleExceptionTest); 
}

void Network::SockAcceptorTesting::ACEConstructionTest()
{
    TestingType sockAcceptor1{ "127.0.0.1", mPort + 20, GetACEServerConfigurationStrategy() };
    TestingType sockAcceptor2(mPort + 30, GetACEServerConfigurationStrategy());
}

void Network::SockAcceptorTesting::BoostConstructionTest()
{
    TestingType sockAcceptor1{ "127.0.0.1", mPort + 20, GetBoostServerConfigurationStrategy() };
    TestingType sockAcceptor2(mPort + 30, GetBoostServerConfigurationStrategy());
}

void Network::SockAcceptorTesting::NetworkConstructionTest()
{
    TestingType sockAcceptor1{ "127.0.0.1", mPort + 20, GetNetworkServerConfigurationStrategy() };
    TestingType sockAcceptor2(mPort + 30, GetNetworkServerConfigurationStrategy());
}

void Network::SockAcceptorTesting::ACEGetACEHandleTest()
{
    TestingType sockAcceptor1{ "127.0.0.1", mPort + 20, GetACEServerConfigurationStrategy() };
    MAYBE_UNUSED auto value = sockAcceptor1.GetACEHandle();
}

void Network::SockAcceptorTesting::ACEGetBoostHandleExceptionTest()
{
    TestingType sockAcceptor1{ "127.0.0.1", mPort, GetACEServerConfigurationStrategy() };
    MAYBE_UNUSED const auto value = sockAcceptor1.GetBoostHandle();
}

void Network::SockAcceptorTesting::ACEGetNetworkHandleExceptionTest()
{
    TestingType sockAcceptor1{ "127.0.0.1", mPort, GetACEServerConfigurationStrategy() };
    MAYBE_UNUSED const auto value = sockAcceptor1.GetWinSocket();
}

void Network::SockAcceptorTesting::BoostGetACEHandleExceptionTest()
{
    TestingType sockAcceptor1{ "127.0.0.1", mPort, GetBoostServerConfigurationStrategy() };
    MAYBE_UNUSED const auto value = sockAcceptor1.GetACEHandle();
}

void Network::SockAcceptorTesting::BoostGetBoostHandleTest()
{
    TestingType sockAcceptor1{ "127.0.0.1", mPort, GetBoostServerConfigurationStrategy() };
    MAYBE_UNUSED const auto value = sockAcceptor1.GetBoostHandle();
}

void Network::SockAcceptorTesting::BoostGetNetworkHandleExceptionTest()
{
    TestingType sockAcceptor1{ "127.0.0.1", mPort, GetBoostServerConfigurationStrategy() };
    MAYBE_UNUSED const auto value = sockAcceptor1.GetWinSocket();
}

void Network::SockAcceptorTesting::NetworkGetACEHandleExceptionTest()
{
    TestingType sockAcceptor1{ "127.0.0.1", mPort, GetNetworkServerConfigurationStrategy() };
    MAYBE_UNUSED const auto value = sockAcceptor1.GetACEHandle();
}

void Network::SockAcceptorTesting::NetworkGetBoostHandleExceptionTest()
{
    TestingType sockAcceptor{ "127.0.0.1", mPort, GetNetworkServerConfigurationStrategy() };
    MAYBE_UNUSED const auto value = sockAcceptor.GetBoostHandle();
}

void Network::SockAcceptorTesting::NullTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NullConstructionTest);
    ASSERT_THROW_EXCEPTION_0(NullGetACEHandleExceptionTest);
    ASSERT_THROW_EXCEPTION_0(NullGetBoostHandleExceptionTest);
    ASSERT_THROW_EXCEPTION_0(NullGetNetworkHandleExceptionTest);
}

void Network::SockAcceptorTesting::NullGetACEHandleExceptionTest()
{
    TestingType sockAcceptor1{ "127.0.0.1", mPort, GetNullServerConfigurationStrategy() };
    MAYBE_UNUSED const auto value = sockAcceptor1.GetACEHandle();
}

void Network::SockAcceptorTesting::NullGetBoostHandleExceptionTest()
{
    TestingType sockAcceptor1{ "127.0.0.1", mPort, GetNullServerConfigurationStrategy() };
    MAYBE_UNUSED const auto value = sockAcceptor1.GetBoostHandle();
}

void Network::SockAcceptorTesting::NullGetNetworkHandleExceptionTest()
{
    TestingType sockAcceptor1{ "127.0.0.1", mPort, GetNullServerConfigurationStrategy() };
    MAYBE_UNUSED const auto value = sockAcceptor1.GetWinSocket();
}

void Network::SockAcceptorTesting::NullConstructionTest()
{
    TestingType sockAcceptor1{ "127.0.0.1", mPort, GetNullServerConfigurationStrategy() };
    TestingType sockAcceptor2(mPort + 10, GetNullServerConfigurationStrategy());
}
