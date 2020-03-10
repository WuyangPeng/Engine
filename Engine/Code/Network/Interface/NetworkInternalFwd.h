// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.1.0 (2019/10/18 13:39)


#ifndef NETWORK_INTERFACE_NETWORK_INTERNAL_FWD_H
#define NETWORK_INTERFACE_NETWORK_INTERNAL_FWD_H

#include "Network/NetworkDll.h" 

#include "System/Helper/UnicodeUsing.h"
#include "Network/ACEWrappers/Using/ACEUsing.h" 

#include "System/Helper/PragmaWarning/AsioIpTcp.h"
#include <memory>

namespace CoreTools
{
	class EventInterface;
	class CallbackParameters;	
}

namespace Network
{	
	class AddressData;
	class SockStream;
	class SockAddress;
	class SockAcceptor;
	class SockConnector;
	class MessageBuffer;
	class ConfigurationStrategy;
	class Client;

	using EventInterfaceSharedPtr = std::shared_ptr<CoreTools::EventInterface>;
	using SockStreamSharedPtr = std::shared_ptr<SockStream>;
	using SockAddressSharedPtr = std::shared_ptr<SockAddress>;
	using SockAcceptorSharedPtr = std::shared_ptr<SockAcceptor>;
	using MessageBufferSharedPtr = std::shared_ptr<MessageBuffer>;
	using ClientSharedPtr = std::shared_ptr<Client>;

	using ACEHandleType = ACEHandle;
	using BoostHandleType = boost::asio::ip::tcp::acceptor::native_handle_type;
	using WinSocketType = System::WinSocket;

	using ACEInetAddressType = ACEInetAddress;
	using BoostInetAddressType = boost::asio::ip::tcp::endpoint;
	using WinSockInetAddressType = System::WinSockAddrIn;

	using ACESockStreamType = ACESockStreamNativeType;
	using BoostSockStreamType = boost::asio::ip::tcp::socket;
	using WinSocketStreamType = System::WinSocket;	

	const System::String g_ACELogName{ SYSTEM_TEXT("BoostNetwork") };
	const System::String g_BoostLogName{ SYSTEM_TEXT("BoostNetwork") };

	using IOContextType = boost::asio::io_context;
	using ErrorCodeType = boost::system::error_code;	
} 

#endif // NETWORK_INTERFACE_NETWORK_INTERNAL_FWD_H
