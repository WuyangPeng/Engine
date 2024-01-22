/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:11)

#ifndef NETWORK_NETWORK_MESSAGE_BUFFER_SEND_STREAM_IMPL_H
#define NETWORK_NETWORK_MESSAGE_BUFFER_SEND_STREAM_IMPL_H

#include "Network/NetworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "Network/NetworkMessage/NetworkMessageInternalFwd.h"
#include "Network/NetworkMessage/SendMessageLevel.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE BufferSendStreamImpl final
    {
    public:
        using ClassType = BufferSendStreamImpl;

    public:
        BufferSendStreamImpl(int bytesTotal, ParserStrategy parserStrategy, EncryptedCompressionStrategy encryptedCompressionStrategy);

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool Insert(const MessageInterfaceSharedPtr& message);
        void Save(const MessageBufferSharedPtr& messageBuffer);
        void Clear();

        NODISCARD bool IsEmpty() const noexcept;
        NODISCARD int GetCurrentSize() const noexcept;

    private:
        void EncryptedCompression(const MessageBufferSharedPtr& messageBuffer) noexcept;

    private:
        SendMessageLevel topLevel;
        ParserStrategy parserStrategy;
        EncryptedCompressionStrategy encryptedCompressionStrategy;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_BUFFER_SEND_STREAM_IMPL_H
