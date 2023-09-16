///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/15 11:27)

#ifndef NETWORK_NETWORK_INTERFACE_BUFFER_SEND_STREAM_CONTAINER_H
#define NETWORK_NETWORK_INTERFACE_BUFFER_SEND_STREAM_CONTAINER_H

#include "Network/NetworkDll.h"

#include "Network/ACEWrappers/Using/ACEUsing.h"
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
