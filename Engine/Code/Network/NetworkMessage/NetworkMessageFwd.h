//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 9:40)

#ifndef NETWORK_NETWORK_MESSAGE_FWD_H
#define NETWORK_NETWORK_MESSAGE_FWD_H

#include "CoreTools/Helper/SharedPtrMacro.h"

#include <memory>

namespace Network
{
    class MessageInterface;
    class DoubleMessage;
    class NullMessage;
    class NullDoubleMessage;

    template <typename E, typename T>
    class MessageContainer;

    template <typename E>
    class IntegerMessage;

    template <typename E>
    class StringMessage;

    enum class MultipleMessageByteType;

    template <MultipleMessageByteType byteType>
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
    class MultipleMessageContainer;

    template <typename E, MultipleMessageByteType ByteType, MultipleMessageByteType... Types>
    class MultipleMessage;

    template <typename E>
    class IntegerDoubleMessage;

    template <typename E>
    class StringDoubleMessage;

    template <typename E, MultipleMessageByteType ByteType, MultipleMessageByteType... Types>
    class MultipleDoubleMessage;

    template <typename E, typename T>
    class MessageContainerGroup;

    template <typename E, MultipleMessageByteType ByteType, MultipleMessageByteType... Types>
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

    CORE_TOOLS_SHARED_PTR_DECLARE(MessageInterface);
    CORE_TOOLS_SHARED_PTR_DECLARE(MessageSource);
    CORE_TOOLS_SHARED_PTR_DECLARE(MessageTarget);
    CORE_TOOLS_SHARED_PTR_DECLARE(MessageBuffer);
    CORE_TOOLS_SHARED_PTR_DECLARE(SocketManager);

    CORE_TOOLS_SHARED_PTR_DECLARE(NetworkMessageEvent);
    CORE_TOOLS_WEAK_PTR_DECLARE(NetworkMessageEvent);
}

#endif  // NETWORK_NETWORK_MESSAGE_FWD_H