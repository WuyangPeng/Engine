// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.2.4 (2020/03/11 09:54)

#ifndef NETWORK_NETWORK_INTERFACE_FWD_H
#define NETWORK_NETWORK_INTERFACE_FWD_H

#include <memory>

namespace Network
{
	class BaseMainManager;
	class SockAddress;
	class SockAcceptor;
	class SockConnector;
	class SockStream;
	class HandleSet;
	class HandleSetIterator;
	class SendSocket;
	class Client;
	class Server;
	class SendSocketManager;

	using SendSocketManagerSharedPtr = std::shared_ptr<SendSocketManager>;
	using ConstSendSocketManagerSharedPtr = std::shared_ptr<const SendSocketManager>;

	enum class StreamReceive;
	enum class SocketType;
}

#endif // NETWORK_NETWORK_INTERFACE_FWD_H