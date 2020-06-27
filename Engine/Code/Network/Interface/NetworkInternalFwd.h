// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/11 09:53)

#ifndef NETWORK_INTERFACE_NETWORK_INTERNAL_FWD_H
#define NETWORK_INTERFACE_NETWORK_INTERNAL_FWD_H

#include "Network/NetworkDll.h" 

#include "InterfaceFwd.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Helper/PragmaWarning/AsioIpTcp.h"
#include "Network/ACEWrappers/Using/ACEUsing.h" 

#include <memory>

namespace CoreTools
{
	class EventInterface;
	class CallbackParameters;	
}

namespace Network
{	
	class ClientImpl;
	class ServerImpl;
	class HandleSetImpl;
	class SockStreamImpl;
	class SockAddressImpl;
	class SockAcceptorImpl;
	class SockConnectorImpl;
	class BoostSockStream;
	class BoostSockAcceptor;
	class BaseMainManagerImpl;
	class HandleSetIteratorImpl;

	class AddressData;	 
	class MessageBuffer;
	class ConfigurationStrategy; 

	using ClientSharedPtr = std::shared_ptr<Client>;
	using ServerSharedPtr = std::shared_ptr<Server>;

	class SocketManager;
	using SocketManagerSharedPtr = std::shared_ptr<SocketManager>;
	using SockStreamSharedPtr = std::shared_ptr<SockStream>;
	using SockAddressSharedPtr = std::shared_ptr<SockAddress>;
	using SockAcceptorSharedPtr = std::shared_ptr<SockAcceptor>;
	using MessageBufferSharedPtr = std::shared_ptr<MessageBuffer>;
	using EventInterfaceSharedPtr = std::shared_ptr<CoreTools::EventInterface>;	

	using ACEHandleType = ACEHandle;
	using BoostHandleType = boost::asio::ip::tcp::acceptor::native_handle_type;
	using WinSocketType = System::WinSocket;

	using ACEInetAddressType = ACEInetAddress;
	using BoostInetAddressType = boost::asio::ip::tcp::endpoint;
	using WinSockInetAddressType = System::WinSockAddrIn;

	using ACESockStreamType = ACESockStreamNativeType;
	using BoostSockStreamType = boost::asio::ip::tcp::socket;
	using WinSocketStreamType = System::WinSocket;	

	#include STSTEM_WARNING_PUSH

	#include SYSTEM_WARNING_DISABLE(26426) 
		const System::String g_ACELogName{ SYSTEM_TEXT("BoostNetwork") };
		const System::String g_BoostLogName{ SYSTEM_TEXT("BoostNetwork") };
	#include STSTEM_WARNING_POP

	using IOContextType = boost::asio::io_context;
	using ErrorCodeType = boost::system::error_code;	
} 

#endif // NETWORK_INTERFACE_NETWORK_INTERNAL_FWD_H
