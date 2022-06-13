///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/24 15:26)

#include "SingletonTestingDetail.h"
#include "SockStreamTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Network/Helper/UserMacro.h"
#include "Network/Interface/SockStream.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE_USE_TESTING_TYPE(Network, SockStream)

void Network::SockStreamTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_2(ACESingletonTest<ClassType>, this, &ClassType::ACETest);
    ASSERT_NOT_THROW_EXCEPTION_2(BoostSingletonTest<ClassType>, this, &ClassType::BoostTest);
    ASSERT_NOT_THROW_EXCEPTION_2(NetworkSingletonTest<ClassType>, this, &ClassType::NetworkTest);
    ASSERT_NOT_THROW_EXCEPTION_2(NullSingletonTest<ClassType>, this, &ClassType::NullTest);
}

void Network::SockStreamTesting::ACETest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ACEConstructionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ACEGetACESockStreamTest);
    ASSERT_THROW_EXCEPTION_0(ACEGetBoostSockStreamExceptionTest);
    ASSERT_THROW_EXCEPTION_0(ACEGetNetworkSockStreamExceptionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ACEGetACEHandleTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ACESetACEHandleTest);
    ASSERT_THROW_EXCEPTION_0(ACESetNetworkHandleExceptionTest);
}

void Network::SockStreamTesting::BoostTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BoostConstructionTest);
    ASSERT_THROW_EXCEPTION_0(BoostGetACESockStreamExceptionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(BoostGetBoostSockStreamTest);
    ASSERT_THROW_EXCEPTION_0(BoostGetNetworkSockStreamExceptionTest);
    ASSERT_THROW_EXCEPTION_0(BoostGetACEHandleExceptionTest);
    ASSERT_THROW_EXCEPTION_0(BoostSetACEHandleExceptionTest);
    ASSERT_THROW_EXCEPTION_0(BoostSetNetworkHandleExceptionTest);
}

void Network::SockStreamTesting::NetworkTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NetworkConstructionTest);
    ASSERT_THROW_EXCEPTION_0(NetworkGetACESockStreamExceptionTest);
    ASSERT_THROW_EXCEPTION_0(NetworkGetBoostSockStreamExceptionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(NetworkGetNetworkSockStreamTest);
    ASSERT_THROW_EXCEPTION_0(NetworkGetACEHandleExceptionTest);
    ASSERT_THROW_EXCEPTION_0(NetworkSetACEHandleExceptionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(NetworkSetNetworkHandleTest);
}

void Network::SockStreamTesting::ACEConstructionTest()
{
    TestingType sockStream{ GetACEServerConfigurationStrategy() };
}

void Network::SockStreamTesting::BoostConstructionTest()
{
    TestingType sockStream{ GetBoostServerConfigurationStrategy() };
}

void Network::SockStreamTesting::NetworkConstructionTest()
{
    TestingType sockStream{ GetNetworkServerConfigurationStrategy() };
}

void Network::SockStreamTesting::ACEGetACESockStreamTest()
{
    TestingType sockStream{ GetACEServerConfigurationStrategy() };
    MAYBE_UNUSED auto value = sockStream.GetACESockStream();
}

void Network::SockStreamTesting::ACEGetBoostSockStreamExceptionTest()
{
    TestingType sockStream{ GetACEServerConfigurationStrategy() };
    MAYBE_UNUSED const auto& value = sockStream.GetBoostSockStream();
}

void Network::SockStreamTesting::ACEGetNetworkSockStreamExceptionTest()
{
    TestingType sockStream{ GetACEServerConfigurationStrategy() };
    MAYBE_UNUSED const auto value = sockStream.GetNetworkSockStream();
}

void Network::SockStreamTesting::BoostGetACESockStreamExceptionTest()
{
    TestingType sockStream{ GetBoostServerConfigurationStrategy() };
    MAYBE_UNUSED auto value = sockStream.GetACESockStream();
}

void Network::SockStreamTesting::BoostGetBoostSockStreamTest()
{
    TestingType sockStream{ GetBoostServerConfigurationStrategy() };
    MAYBE_UNUSED const auto& value = sockStream.GetBoostSockStream();
}

void Network::SockStreamTesting::BoostGetNetworkSockStreamExceptionTest()
{
    TestingType sockStream{ GetBoostServerConfigurationStrategy() };
    MAYBE_UNUSED const auto value = sockStream.GetNetworkSockStream();
}

void Network::SockStreamTesting::NetworkGetACESockStreamExceptionTest()
{
    TestingType sockStream{ GetNetworkServerConfigurationStrategy() };
    MAYBE_UNUSED auto value = sockStream.GetACESockStream();
}

void Network::SockStreamTesting::NetworkGetBoostSockStreamExceptionTest()
{
    TestingType sockStream{ GetNetworkServerConfigurationStrategy() };
    MAYBE_UNUSED const auto& value = sockStream.GetBoostSockStream();
}

void Network::SockStreamTesting::NetworkGetNetworkSockStreamTest()
{
    TestingType sockStream{ GetNetworkServerConfigurationStrategy() };
    MAYBE_UNUSED const auto value = sockStream.GetNetworkSockStream();
}

void Network::SockStreamTesting::ACEGetACEHandleTest()
{
    TestingType sockStream{ GetACEServerConfigurationStrategy() };
    MAYBE_UNUSED const auto value = sockStream.GetACEHandle();
}

void Network::SockStreamTesting::ACESetACEHandleTest()
{
    TestingType sockStream{ GetACEServerConfigurationStrategy() };
    sockStream.SetACEHandle(nullptr);
}

void Network::SockStreamTesting::ACESetNetworkHandleExceptionTest()
{
    TestingType sockStream{ GetACEServerConfigurationStrategy() };
    sockStream.SetNetworkHandle(0);
}

void Network::SockStreamTesting::BoostGetACEHandleExceptionTest()
{
    TestingType sockStream{ GetBoostServerConfigurationStrategy() };
    MAYBE_UNUSED const auto value = sockStream.GetACEHandle();
}

void Network::SockStreamTesting::BoostSetACEHandleExceptionTest()
{
    TestingType sockStream{ GetBoostServerConfigurationStrategy() };
    sockStream.SetACEHandle(nullptr);
}

void Network::SockStreamTesting::BoostSetNetworkHandleExceptionTest()
{
    TestingType sockStream{ GetBoostServerConfigurationStrategy() };
    sockStream.SetNetworkHandle(0);
}

void Network::SockStreamTesting::NetworkGetACEHandleExceptionTest()
{
    TestingType sockStream{ GetNetworkServerConfigurationStrategy() };
    MAYBE_UNUSED auto value = sockStream.GetACEHandle();
}

void Network::SockStreamTesting::NetworkSetACEHandleExceptionTest()
{
    TestingType sockStream{ GetNetworkServerConfigurationStrategy() };
    sockStream.SetACEHandle(nullptr);
}

void Network::SockStreamTesting::NetworkSetNetworkHandleTest()
{
    TestingType sockStream{ GetNetworkServerConfigurationStrategy() };
    sockStream.SetNetworkHandle(0);
}

void Network::SockStreamTesting::NullTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NullConstructionTest);
    ASSERT_THROW_EXCEPTION_0(NullGetACESockStreamExceptionTest);
    ASSERT_THROW_EXCEPTION_0(NullGetBoostSockStreamExceptionTest);
    ASSERT_THROW_EXCEPTION_0(NullGetNetworkSockStreamExceptionTest);
    ASSERT_THROW_EXCEPTION_0(NullGetACEHandleExceptionTest);
    ASSERT_THROW_EXCEPTION_0(NullSetACEHandleExceptionTest);
    ASSERT_THROW_EXCEPTION_0(NullSetNetworkHandleExceptionTest);
}

void Network::SockStreamTesting::NullGetACEHandleExceptionTest()
{
    TestingType sockStream{ GetNullServerConfigurationStrategy() };
    MAYBE_UNUSED auto value = sockStream.GetACEHandle();
}

void Network::SockStreamTesting::NullSetACEHandleExceptionTest()
{
    TestingType sockStream{ GetNullServerConfigurationStrategy() };
    sockStream.SetACEHandle(0);
}

void Network::SockStreamTesting::NullSetNetworkHandleExceptionTest()
{
    TestingType sockStream{ GetNullServerConfigurationStrategy() };
    sockStream.SetNetworkHandle(0);
}

void Network::SockStreamTesting::NullConstructionTest()
{
    TestingType sockStream{ GetNullServerConfigurationStrategy() };
}

void Network::SockStreamTesting::NullGetACESockStreamExceptionTest()
{
    TestingType sockStream{ GetNullServerConfigurationStrategy() };
    MAYBE_UNUSED auto value = sockStream.GetACESockStream();
}

void Network::SockStreamTesting::NullGetBoostSockStreamExceptionTest()
{
    TestingType sockStream{ GetNullServerConfigurationStrategy() };
    MAYBE_UNUSED const auto& value = sockStream.GetBoostSockStream();
}

void Network::SockStreamTesting::NullGetNetworkSockStreamExceptionTest()
{
    TestingType sockStream{ GetNullServerConfigurationStrategy() };
    MAYBE_UNUSED const auto value = sockStream.GetNetworkSockStream();
}
