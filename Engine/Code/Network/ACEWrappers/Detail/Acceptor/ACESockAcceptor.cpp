// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/11 13:44)

#include "Network/NetworkExport.h" 

#ifdef NETWORK_USE_ACE

#include "ACESockAcceptor.h"
#include "System/Helper/EnumCast.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/MessageEvent/EventInterface.h"
#include "CoreTools/MessageEvent/CallbackParameters.h"
#include "Network/Interface/SockStream.h"
#include "Network/Interface/SockAddress.h"
#include "Network/ACEWrappers/Using/ACEUsing.h"
#include "Network/ACEWrappers/Detail/Address/ACESockInetAddress.h"
#include "Network/NetworkMessage/Flags/MessageEventFlags.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"

#include "System/Helper/PragmaWarning/NumericCast.h"

using std::string;

Network::ACESockAcceptor
	::ACESockAcceptor(int port)
	:ParentType{}, m_ACESockAcceptor{}
{
	ACEInetAddress inetAddress;

	if (inetAddress.set(boost::numeric_cast<uint16_t>(port)) != 0 || m_ACESockAcceptor.open(inetAddress) != 0)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("…Ë÷√µÿ÷∑ ß∞‹£°"));
	}

	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::ACESockAcceptor
	::ACESockAcceptor(const string& hostName, int port)
	:ParentType{}, m_ACESockAcceptor{}
{
	ACEInetAddress inetAddress;

	if (inetAddress.set(boost::numeric_cast<uint16_t>(port), hostName.c_str()) != 0 || m_ACESockAcceptor.open(inetAddress) != 0)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("…Ë÷√µÿ÷∑ ß∞‹£°"));
	}

	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::ACESockAcceptor
	::~ACESockAcceptor()
{
	m_ACESockAcceptor.close();

	NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, ACESockAcceptor)

bool Network::ACESockAcceptor
	::Accept(const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress)
{
	NETWORK_CLASS_IS_VALID_9;

	if (m_ACESockAcceptor.accept(sockStream->GetACESockStream(), &sockAddress->GetACEInetAddress()) == 0)
		return true;
	else
		return false;
}

bool Network::ACESockAcceptor
	::Accept(const SockStreamSharedPtr& sockStream)
{
	NETWORK_CLASS_IS_VALID_9;

	if (m_ACESockAcceptor.accept(sockStream->GetACESockStream()) == 0)
		return true;
	else
		return false;
}

Network::ACEHandle Network::ACESockAcceptor
	::GetACEHandle()
{
	NETWORK_CLASS_IS_VALID_9;

	return m_ACESockAcceptor.get_handle();
}

bool Network::ACESockAcceptor
	::EnableNonBlock()
{
	NETWORK_CLASS_IS_VALID_9;

	if (m_ACESockAcceptor.enable(g_NonBlock) == 0)
		return true;
	else
		return false;
}

void Network::ACESockAcceptor
	::AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream)
{
	NETWORK_CLASS_IS_VALID_9;

	auto result = m_ACESockAcceptor.accept(sockStream->GetACESockStream());

	if (result == 0)
	{
		CoreTools::CallbackParameters callbackParameters{};
		callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::Event), System::EnumCastUnderlying(SocketManagerEvent::AsyncAcceptor));
		callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::WrappersStrategy), System::EnumCastUnderlying(WrappersStrategy::ACE));
		callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::Error), result);

		eventInterface->EventFunction(callbackParameters);
	}
}

void Network::ACESockAcceptor
	::AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress)
{
	NETWORK_CLASS_IS_VALID_9;

	auto result = m_ACESockAcceptor.accept(sockStream->GetACESockStream(), &sockAddress->GetACEInetAddress());

	if (result == 0)
	{
		CoreTools::CallbackParameters callbackParameters{};
		callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::Event), System::EnumCastUnderlying(SocketManagerEvent::AsyncAcceptor));
		callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::WrappersStrategy), System::EnumCastUnderlying(WrappersStrategy::ACE));
		callbackParameters.SetValue(System::EnumCastUnderlying(SocketManagerPoisition::Error), result);

		eventInterface->EventFunction(callbackParameters);
	}
}

const std::string Network::ACESockAcceptor
	::GetAddress() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	ACESockInetAddress address;

	if (m_ACESockAcceptor.get_local_addr(address.GetACEInetAddress()) == 0)
	{
		return address.GetAddress();
	}
	else
	{
		return "";
	}
}

int Network::ACESockAcceptor
	::GetPort() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	ACESockInetAddress address;

	if (m_ACESockAcceptor.get_local_addr(address.GetACEInetAddress()) == 0)
	{
		return address.GetPort();
	}
	else
	{
		return 0;
	}
}

#endif // NETWORK_USE_ACE