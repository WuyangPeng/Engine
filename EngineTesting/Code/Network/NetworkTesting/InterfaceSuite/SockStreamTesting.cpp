// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/13 13:22)

#include "SockStreamTesting.h" 
#include "SingletonTestingDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Network/Helper/UserMacro.h"
#include "Network/Interface/SockStream.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE_USE_TESTING_TYPE(Network, SockStream)

void Network::SockStreamTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_2(ACESingletonTest<ClassType>, this, &ClassType::ACETest);
	ASSERT_NOT_THROW_EXCEPTION_2(BoostSingletonTest<ClassType>, this, &ClassType::BoostTest);
	ASSERT_NOT_THROW_EXCEPTION_2(NetworkSingletonTest<ClassType>, this, &ClassType::NetworkTest);
	ASSERT_NOT_THROW_EXCEPTION_2(NullSingletonTest<ClassType>, this, &ClassType::NullTest);
}

void Network::SockStreamTesting
	::ACETest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(ACEConstructionTest);
	ASSERT_NOT_THROW_EXCEPTION_0(ACEGetACESockStreamTest);
	ASSERT_THROW_EXCEPTION_0(ACEGetBoostSockStreamExceptionTest);
	ASSERT_THROW_EXCEPTION_0(ACEGetNetworkSockStreamExceptionTest);
	ASSERT_NOT_THROW_EXCEPTION_0(ACEGetACEHandleTest);
	ASSERT_NOT_THROW_EXCEPTION_0(ACESetACEHandleTest);
	ASSERT_THROW_EXCEPTION_0(ACESetNetworkHandleExceptionTest);
}

void Network::SockStreamTesting
	::BoostTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(BoostConstructionTest);
	ASSERT_THROW_EXCEPTION_0(BoostGetACESockStreamExceptionTest);
	ASSERT_NOT_THROW_EXCEPTION_0(BoostGetBoostSockStreamTest);
	ASSERT_THROW_EXCEPTION_0(BoostGetNetworkSockStreamExceptionTest);
	ASSERT_THROW_EXCEPTION_0(BoostGetACEHandleExceptionTest);
	ASSERT_THROW_EXCEPTION_0(BoostSetACEHandleExceptionTest);
	ASSERT_THROW_EXCEPTION_0(BoostSetNetworkHandleExceptionTest);
}

void Network::SockStreamTesting
	::NetworkTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(NetworkConstructionTest);
	ASSERT_THROW_EXCEPTION_0(NetworkGetACESockStreamExceptionTest);
	ASSERT_THROW_EXCEPTION_0(NetworkGetBoostSockStreamExceptionTest);
	ASSERT_NOT_THROW_EXCEPTION_0(NetworkGetNetworkSockStreamTest);
	ASSERT_THROW_EXCEPTION_0(NetworkGetACEHandleExceptionTest);
	ASSERT_THROW_EXCEPTION_0(NetworkSetACEHandleExceptionTest);
	ASSERT_NOT_THROW_EXCEPTION_0(NetworkSetNetworkHandleTest);
}

void Network::SockStreamTesting
	::ACEConstructionTest()
{
	TestingType sockStream{ GetACEServerConfigurationStrategy() };
}

void Network::SockStreamTesting
	::BoostConstructionTest()
{
	TestingType sockStream{ GetBoostServerConfigurationStrategy() };
}

void Network::SockStreamTesting
	::NetworkConstructionTest()
{
	TestingType sockStream{ GetNetworkServerConfigurationStrategy() };
}

void Network::SockStreamTesting
	::ACEGetACESockStreamTest()
{
	TestingType sockStream{ GetACEServerConfigurationStrategy() };
    [[maybe_unused]] auto value = sockStream.GetACESockStream();
}

void Network::SockStreamTesting
	::ACEGetBoostSockStreamExceptionTest()
{
	TestingType sockStream{ GetACEServerConfigurationStrategy() };
    [[maybe_unused]] auto& value = sockStream.GetBoostSockStream();
}

void Network::SockStreamTesting
	::ACEGetNetworkSockStreamExceptionTest()
{
	TestingType sockStream{ GetACEServerConfigurationStrategy() };
    [[maybe_unused]] auto value = sockStream.GetNetworkSockStream();
}

void Network::SockStreamTesting
	::BoostGetACESockStreamExceptionTest()
{
	TestingType sockStream{ GetBoostServerConfigurationStrategy() };
    [[maybe_unused]] auto value = sockStream.GetACESockStream();
}

void Network::SockStreamTesting
	::BoostGetBoostSockStreamTest()
{
	TestingType sockStream{ GetBoostServerConfigurationStrategy() };
    [[maybe_unused]] auto& value = sockStream.GetBoostSockStream();
}

void Network::SockStreamTesting
	::BoostGetNetworkSockStreamExceptionTest()
{
	TestingType sockStream{ GetBoostServerConfigurationStrategy() };
    [[maybe_unused]] auto value = sockStream.GetNetworkSockStream();
}

void Network::SockStreamTesting
::NetworkGetACESockStreamExceptionTest()
{
	TestingType sockStream{ GetNetworkServerConfigurationStrategy() };
    [[maybe_unused]] auto value = sockStream.GetACESockStream();
}

void Network::SockStreamTesting
	::NetworkGetBoostSockStreamExceptionTest()
{
	TestingType sockStream{ GetNetworkServerConfigurationStrategy() };
    [[maybe_unused]] auto& value = sockStream.GetBoostSockStream();
}

void Network::SockStreamTesting
	::NetworkGetNetworkSockStreamTest()
{
	TestingType sockStream{ GetNetworkServerConfigurationStrategy() };
    [[maybe_unused]] auto value = sockStream.GetNetworkSockStream();
}

void Network::SockStreamTesting
	::ACEGetACEHandleTest()
{
	TestingType sockStream{ GetACEServerConfigurationStrategy() };
    [[maybe_unused]] auto value = sockStream.GetACEHandle();
}

void Network::SockStreamTesting
	::ACESetACEHandleTest()
{
	TestingType sockStream{ GetACEServerConfigurationStrategy() };
	sockStream.SetACEHandle(nullptr);
}

void Network::SockStreamTesting
	::ACESetNetworkHandleExceptionTest()
{
	TestingType sockStream{ GetACEServerConfigurationStrategy() };
	sockStream.SetNetworkHandle(0);
}

void Network::SockStreamTesting
	::BoostGetACEHandleExceptionTest()
{
	TestingType sockStream{ GetBoostServerConfigurationStrategy() };
    [[maybe_unused]] auto value = sockStream.GetACEHandle();
}

void Network::SockStreamTesting
	::BoostSetACEHandleExceptionTest()
{
	TestingType sockStream{ GetBoostServerConfigurationStrategy() };
	sockStream.SetACEHandle(nullptr);
}

void Network::SockStreamTesting
	::BoostSetNetworkHandleExceptionTest()
{
	TestingType sockStream{ GetBoostServerConfigurationStrategy() };
	sockStream.SetNetworkHandle(0);
}

void Network::SockStreamTesting
	::NetworkGetACEHandleExceptionTest()
{
	TestingType sockStream{ GetNetworkServerConfigurationStrategy() };
    [[maybe_unused]] auto value = sockStream.GetACEHandle();
}

void Network::SockStreamTesting
	::NetworkSetACEHandleExceptionTest()
{
	TestingType sockStream{ GetNetworkServerConfigurationStrategy() };
	sockStream.SetACEHandle(nullptr);
}

void Network::SockStreamTesting
	::NetworkSetNetworkHandleTest()
{
	TestingType sockStream{ GetNetworkServerConfigurationStrategy() };
	sockStream.SetNetworkHandle(0);
}

void Network::SockStreamTesting
	::NullTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(NullConstructionTest);
	ASSERT_THROW_EXCEPTION_0(NullGetACESockStreamExceptionTest);
	ASSERT_THROW_EXCEPTION_0(NullGetBoostSockStreamExceptionTest);
	ASSERT_THROW_EXCEPTION_0(NullGetNetworkSockStreamExceptionTest);
	ASSERT_THROW_EXCEPTION_0(NullGetACEHandleExceptionTest);
	ASSERT_THROW_EXCEPTION_0(NullSetACEHandleExceptionTest);
	ASSERT_THROW_EXCEPTION_0(NullSetNetworkHandleExceptionTest);
}

void Network::SockStreamTesting
	::NullGetACEHandleExceptionTest()
{
	TestingType sockStream{ GetNullServerConfigurationStrategy() };
    [[maybe_unused]] auto value = sockStream.GetACEHandle();
}

void Network::SockStreamTesting
	::NullSetACEHandleExceptionTest()
{
	TestingType sockStream{ GetNullServerConfigurationStrategy() };
	sockStream.SetACEHandle(0);
}

void Network::SockStreamTesting
	::NullSetNetworkHandleExceptionTest()
{
	TestingType sockStream{ GetNullServerConfigurationStrategy() };
	sockStream.SetNetworkHandle(0);
}

void Network::SockStreamTesting
	::NullConstructionTest()
{
	TestingType sockStream{ GetNullServerConfigurationStrategy() };
}

void Network::SockStreamTesting
	::NullGetACESockStreamExceptionTest()
{
	TestingType sockStream{ GetNullServerConfigurationStrategy() };
    [[maybe_unused]] auto value = sockStream.GetACESockStream();
}

void Network::SockStreamTesting
	::NullGetBoostSockStreamExceptionTest()
{
	TestingType sockStream{ GetNullServerConfigurationStrategy() };
    [[maybe_unused]] auto& value = sockStream.GetBoostSockStream();
}

void Network::SockStreamTesting
	::NullGetNetworkSockStreamExceptionTest()
{
	TestingType sockStream{ GetNullServerConfigurationStrategy() };
    [[maybe_unused]] auto value = sockStream.GetNetworkSockStream();
}

