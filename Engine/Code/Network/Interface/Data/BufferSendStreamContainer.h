/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 17:16)

#ifndef NETWORK_NETWORK_INTERFACE_BUFFER_SEND_STREAM_CONTAINER_H
#define NETWORK_NETWORK_INTERFACE_BUFFER_SEND_STREAM_CONTAINER_H

#include "Network/NetworkDll.h"

#include "Network/AceWrappers/Using/AceUsing.h"
#include "Network/Interface/NetworkInternalFwd.h"
#include "Network/NetworkMessage/BufferSendStream.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE BufferSendStreamContainer final
    {
    public:
        using ClassType = BufferSendStreamContainer;

    public:
        BufferSendStreamContainer(int64_t socketId, ACEHandleType handle, int bufferSize, ParserStrategy parserStrategy, EncryptedCompressionStrategy encryptedCompressionStrategy);

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool Insert(const MessageInterfaceSharedPtr& message);

        void Save(const MessageBufferSharedPtr& messageBuffer);

        void Clear();

        NODISCARD bool IsEmpty() const noexcept;

        NODISCARD int GetCurrentSize() const noexcept;

        NODISCARD ACEHandleType GetACEHandle() const noexcept;
        NODISCARD int64_t GetSocketId() const noexcept;

    private:
        int64_t socketId;
        ACEHandle handle;
        BufferSendStream bufferSendStream;
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_REACTIVE_SERVER_H
