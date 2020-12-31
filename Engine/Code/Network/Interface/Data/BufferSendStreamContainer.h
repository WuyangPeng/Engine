//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 15:31)

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
        BufferSendStreamContainer(uint64_t socketID, ACEHandle handle, int bufferSize, ParserStrategy parserStrategy);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] bool Insert(const MessageInterfaceSharedPtr& message);

        void Save(const MessageBufferSharedPtr& messageBuffer);

        void Clear();

        [[nodiscard]] bool IsEmpty() const noexcept;

        [[nodiscard]] uint32_t GetCurrentSize() const;

        [[nodiscard]] ACEHandle GetACEHandle() const noexcept;
        [[nodiscard]] uint64_t GetSocketID() const noexcept;

    private:
        uint64_t m_SocketID;
        ACEHandle m_Handle;
        BufferSendStream m_BufferSendStream;
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_REACTIVE_SERVER_H
