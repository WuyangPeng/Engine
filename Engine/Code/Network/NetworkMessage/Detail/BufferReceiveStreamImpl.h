///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/17 15:33)

#ifndef NETWORK_NETWORK_MESSAGE_BUFFER_RECEIVE_STREAM_IMPL_H
#define NETWORK_NETWORK_MESSAGE_BUFFER_RECEIVE_STREAM_IMPL_H

#include "Network/NetworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "Network/NetworkMessage/NetworkMessageInternalFwd.h"
#include "Network/NetworkMessage/ReceiveMessageLevel.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE BufferReceiveStreamImpl final
    {
    public:
        using ClassType = BufferReceiveStreamImpl;

    public:
        BufferReceiveStreamImpl(const MessageBufferSharedPtr& messageBuffer, ParserStrategy parserStrategy, EncryptedCompressionStrategy encryptedCompressionStrategy);

        CLASS_INVARIANT_DECLARE;

        void OnEvent(uint64_t socketID, const SocketManagerSharedPtr& socketManager);

        // 如果读取未完成，需要继续解析
        NODISCARD bool IsFinish() const noexcept;

        void PushBack(const MessageBufferSharedPtr& messageBuffer);

    private:
        void AnalysisBuffer(const MessageBufferSharedPtr& messageBuffer);
        void DoAnalysisBuffer(const MessageBufferSharedPtr& messageBuffer);
        void CopyToLastMessageSource();
        void SpliceMessageSource(const MessageBufferSharedPtr& messageBuffer);
        void ReadMessage(MessageSource& messageSource, int fullVersion);
        void EncryptedCompression() noexcept;

    private:
        ReceiveMessageLevel topLevel;
        ParserStrategy parserStrategy;
        EncryptedCompressionStrategy encryptedCompressionStrategy;
        MessageBufferSharedPtr lastMessageBuffer;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_BUFFER_RECEIVE_STREAM_IMPL_H
