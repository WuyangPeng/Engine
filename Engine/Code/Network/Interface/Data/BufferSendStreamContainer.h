///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/19 13:58)

#ifndef NETWORK_NETWORK_INTERFACE_BUFFER_SEND_STREAM_CONTAINER_H
#define NETWORK_NETWORK_INTERFACE_BUFFER_SEND_STREAM_CONTAINER_H

#include "Network/NetworkDll.h"

#include "Network/ACEWrappers/Using/ACEUsing.h"
#include "Network/NetworkMessage/BufferSendStream.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE BufferSendStreamContainer final
    {
    public:
        using ClassType = BufferSendStreamContainer;

    public:
        BufferSendStreamContainer(uint64_t socketID, ACEHandle handle, int bufferSize, ParserStrategy parserStrategy, EncryptedCompressionStrategy encryptedCompressionStrategy);

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool Insert(const MessageInterfaceSharedPtr& message);

        void Save(const MessageBufferSharedPtr& messageBuffer);

        void Clear();

        NODISCARD bool IsEmpty() const noexcept;

        NODISCARD int GetCurrentSize() const;

        NODISCARD ACEHandle GetACEHandle() const noexcept;
        NODISCARD uint64_t GetSocketID() const noexcept;

    private:
        uint64_t socketID;
        ACEHandle handle;
        BufferSendStream bufferSendStream;
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_REACTIVE_SERVER_H
