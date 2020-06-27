// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 14:17)

#ifndef NETWORK_NETWORK_MESSAGE_FWD_H
#define NETWORK_NETWORK_MESSAGE_FWD_H

#include <memory>

namespace Network
{
	class MessageInterface;
	class DoubleMessage;
	class NullMessage;
	class NullDoubleMessage;

	template<typename E, typename T>
	class MessageContainer;

	template<typename E>
	class IntegerMessage;

	template<typename E>
	class StringMessage;

	enum class MultipleMessageByteType;

	template<MultipleMessageByteType byteType>
	struct MultipleMessageCast;

	template<int Index, typename MultipleType>
	struct MultipleMessageElement;

	template<typename MultipleType>
	struct MultipleMessageSize;

	template<int Index, typename MultipleType>
	class MultipleMessageInitValue;

	template<int Index, typename MultipleType>
	class MultipleMessageStreamingSize;

	template<int Index, typename MultipleType>
	class MultipleMessageStreamingSave;

	template<int Index, typename MultipleType>
	class MultipleMessageStreamingLoad;

	template<typename E, MultipleMessageByteType ByteType, MultipleMessageByteType... Types>
	class MultipleMessageContainer;

	template<typename E, MultipleMessageByteType ByteType, MultipleMessageByteType... Types>
	class MultipleMessage;

	template<typename E>
	class IntegerDoubleMessage;

	template<typename E>
	class StringDoubleMessage;

	template<typename E, MultipleMessageByteType ByteType, MultipleMessageByteType... Types>
	class MultipleDoubleMessage;

	template<typename E, typename T>
	class MessageContainerGroup;

	template<typename E, MultipleMessageByteType ByteType, MultipleMessageByteType... Types>
	class MultipleMessageContainerGroup;

	class MessageInterfaceSharedPtrLess;
	class NetworkMessageEvent;
	class MessageTypeCondition;
	class MessageTypeConditionOperating;
	class MessageManager;
	class MessageEventContainer;
	class MessageEventManager; 	
	class SendMessageLevel;
	class ReceiveMessageLevel;
	class MessageBuffer;	
	class MessageSource;
	class MessageTarget;	
	class BufferSendStream;
	class BufferReceiveStream;
	class SocketManager;

	enum class MessageEventPriority;
	enum class SocketManagerEvent;
	enum class SocketManagerPoisition;

	enum class BuffBlockSize;

	enum class VersionsCondition;
	enum class MultipleMessageByteType; 

	using MessageInterfaceSharedPtr = std::shared_ptr<MessageInterface>;
	using NetworkMessageEventSharedPtr = std::shared_ptr<NetworkMessageEvent>;
}

#endif // NETWORK_NETWORK_MESSAGE_FWD_H