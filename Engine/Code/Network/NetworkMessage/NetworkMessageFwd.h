/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:18)

#ifndef NETWORK_NETWORK_MESSAGE_FWD_H
#define NETWORK_NETWORK_MESSAGE_FWD_H

#include "CoreTools/Helper/SharedPtrMacro.h"

#include <google/protobuf/message.h>
#include <memory>

namespace Network
{
    enum class MessageEventPriority;
    enum class SocketManagerEvent;
    enum class SocketManagerPosition;

    enum class BuffBlockSize;

    enum class VersionsCondition;
    enum class MultipleMessageByteType;

    class MessageInterface;
    class NullMessage;
    class NullDoubleMessage;

    template <typename T>
    requires(std::is_base_of_v<google::protobuf::Message, T>)
    class ProtoBufMessage;

    template <typename T>
    class JsonMessage;

    template <typename E, typename T>
    requires(std::is_enum_v<E>)
    class MessageContainer;

    template <typename E>
    requires(std::is_enum_v<E>)
    class IntegerMessage;

    template <typename E>
    requires(std::is_enum_v<E>)
    class StringMessage;

    template <MultipleMessageByteType ByteType>
    struct MultipleMessageCast;

    template <int Index, typename MultipleType>
    struct MultipleMessageElement;

    template <typename MultipleType>
    struct MultipleMessageSize;

    template <int Index, typename MultipleType>
    class MultipleMessageInitValue;

    template <int Index, typename MultipleType>
    class MultipleMessageStreamingSize;

    template <int Index, typename MultipleType>
    class MultipleMessageStreamingSave;

    template <int Index, typename MultipleType>
    class MultipleMessageStreamingLoad;

    template <typename E, MultipleMessageByteType ByteType, MultipleMessageByteType... Types>
    requires(std::is_enum_v<E>)
    class MultipleMessageContainer;

    template <typename E, MultipleMessageByteType ByteType, MultipleMessageByteType... Types>
    requires(std::is_enum_v<E>)
    class MultipleMessage;

    template <typename E, typename T>
    requires(std::is_enum_v<E>)
    class MessageContainerGroup;

    template <typename E, MultipleMessageByteType ByteType, MultipleMessageByteType... Types>
    requires(std::is_enum_v<E>)
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

    CORE_TOOLS_SHARED_PTR_DECLARE(MessageInterface);
    CORE_TOOLS_SHARED_PTR_DECLARE(MessageSource);
    CORE_TOOLS_SHARED_PTR_DECLARE(MessageTarget);
    CORE_TOOLS_SHARED_PTR_DECLARE(MessageBuffer);
    CORE_TOOLS_SHARED_PTR_DECLARE(MessageEventManager);

    CORE_TOOLS_SHARED_PTR_DECLARE(NetworkMessageEvent);
    CORE_TOOLS_WEAK_PTR_DECLARE(NetworkMessageEvent);
}

#endif  // NETWORK_NETWORK_MESSAGE_FWD_H