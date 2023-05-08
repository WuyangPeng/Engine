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
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Helper/UserMacro.h"
#include "Network/Interface/SockStream.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
Network::SockStreamTesting::SockStreamTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, SockStreamTesting)

void Network::SockStreamTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

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
    SockStream sockStream{ GetACEServerConfigurationStrategy() };
}

void Network::SockStreamTesting::BoostConstructionTest()
{
    SockStream sockStream{ GetBoostServerConfigurationStrategy() };
}

void Network::SockStreamTesting::NetworkConstructionTest()
{
    SockStream sockStream{ GetNetworkServerConfigurationStrategy() };
}

void Network::SockStreamTesting::ACEGetACESockStreamTest()
{
    SockStream sockStream{ GetACEServerConfigurationStrategy() };
    MAYBE_UNUSED auto value = sockStream.GetACESockStream();
}

void Network::SockStreamTesting::ACEGetBoostSockStreamExceptionTest()
{
    SockStream sockStream{ GetACEServerConfigurationStrategy() };
    MAYBE_UNUSED const auto& value = sockStream.GetBoostSockStream();
}

void Network::SockStreamTesting::ACEGetNetworkSockStreamExceptionTest()
{
    SockStream sockStream{ GetACEServerConfigurationStrategy() };
    MAYBE_UNUSED const auto value = sockStream.GetNetworkSockStream();
}

void Network::SockStreamTesting::BoostGetACESockStreamExceptionTest()
{
    SockStream sockStream{ GetBoostServerConfigurationStrategy() };
    MAYBE_UNUSED auto value = sockStream.GetACESockStream();
}

void Network::SockStreamTesting::BoostGetBoostSockStreamTest()
{
    SockStream sockStream{ GetBoostServerConfigurationStrategy() };
    MAYBE_UNUSED const auto& value = sockStream.GetBoostSockStream();
}

void Network::SockStreamTesting::BoostGetNetworkSockStreamExceptionTest()
{
    SockStream sockStream{ GetBoostServerConfigurationStrategy() };
    MAYBE_UNUSED const auto value = sockStream.GetNetworkSockStream();
}

void Network::SockStreamTesting::NetworkGetACESockStreamExceptionTest()
{
    SockStream sockStream{ GetNetworkServerConfigurationStrategy() };
    MAYBE_UNUSED auto value = sockStream.GetACESockStream();
}

void Network::SockStreamTesting::NetworkGetBoostSockStreamExceptionTest()
{
    SockStream sockStream{ GetNetworkServerConfigurationStrategy() };
    MAYBE_UNUSED const auto& value = sockStream.GetBoostSockStream();
}

void Network::SockStreamTesting::NetworkGetNetworkSockStreamTest()
{
    SockStream sockStream{ GetNetworkServerConfigurationStrategy() };
    MAYBE_UNUSED const auto value = sockStream.GetNetworkSockStream();
}

void Network::SockStreamTesting::ACEGetACEHandleTest()
{
    SockStream sockStream{ GetACEServerConfigurationStrategy() };
    MAYBE_UNUSED const auto value = sockStream.GetACEHandle();
}

void Network::SockStreamTesting::ACESetACEHandleTest()
{
    SockStream sockStream{ GetACEServerConfigurationStrategy() };
    sockStream.SetACEHandle(nullptr);
}

void Network::SockStreamTesting::ACESetNetworkHandleExceptionTest()
{
    SockStream sockStream{ GetACEServerConfigurationStrategy() };
    sockStream.SetNetworkHandle(0);
}

void Network::SockStreamTesting::BoostGetACEHandleExceptionTest()
{
    SockStream sockStream{ GetBoostServerConfigurationStrategy() };
    MAYBE_UNUSED const auto value = sockStream.GetACEHandle();
}

void Network::SockStreamTesting::BoostSetACEHandleExceptionTest()
{
    SockStream sockStream{ GetBoostServerConfigurationStrategy() };
    sockStream.SetACEHandle(nullptr);
}

void Network::SockStreamTesting::BoostSetNetworkHandleExceptionTest()
{
    SockStream sockStream{ GetBoostServerConfigurationStrategy() };
    sockStream.SetNetworkHandle(0);
}

void Network::SockStreamTesting::NetworkGetACEHandleExceptionTest()
{
    SockStream sockStream{ GetNetworkServerConfigurationStrategy() };
    MAYBE_UNUSED auto value = sockStream.GetACEHandle();
}

void Network::SockStreamTesting::NetworkSetACEHandleExceptionTest()
{
    SockStream sockStream{ GetNetworkServerConfigurationStrategy() };
    sockStream.SetACEHandle(nullptr);
}

void Network::SockStreamTesting::NetworkSetNetworkHandleTest()
{
    SockStream sockStream{ GetNetworkServerConfigurationStrategy() };
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
    SockStream sockStream{ GetNullServerConfigurationStrategy() };
    MAYBE_UNUSED auto value = sockStream.GetACEHandle();
}

void Network::SockStreamTesting::NullSetACEHandleExceptionTest()
{
    SockStream sockStream{ GetNullServerConfigurationStrategy() };
    sockStream.SetACEHandle(0);
}

void Network::SockStreamTesting::NullSetNetworkHandleExceptionTest()
{
    SockStream sockStream{ GetNullServerConfigurationStrategy() };
    sockStream.SetNetworkHandle(0);
}

void Network::SockStreamTesting::NullConstructionTest()
{
    SockStream sockStream{ GetNullServerConfigurationStrategy() };
}

void Network::SockStreamTesting::NullGetACESockStreamExceptionTest()
{
    SockStream sockStream{ GetNullServerConfigurationStrategy() };
    MAYBE_UNUSED auto value = sockStream.GetACESockStream();
}

void Network::SockStreamTesting::NullGetBoostSockStreamExceptionTest()
{
    SockStream sockStream{ GetNullServerConfigurationStrategy() };
    MAYBE_UNUSED const auto& value = sockStream.GetBoostSockStream();
}

void Network::SockStreamTesting::NullGetNetworkSockStreamExceptionTest()
{
    SockStream sockStream{ GetNullServerConfigurationStrategy() };
    MAYBE_UNUSED const auto value = sockStream.GetNetworkSockStream();
}
