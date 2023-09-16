///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/04 16:20)

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

        void OnEvent(int64_t socketId, MessageEventManager& messageEventManager);

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
        void ReadMessageByDescribe(MessageSource& messageSource, int fullVersion, MessageHeadStrategy messageHeadStrategy);
        void ReadMessageById(MessageSource& messageSource, int fullVersion, MessageHeadStrategy messageHeadStrategy);

    private:
        ReceiveMessageLevel topLevel;
        ParserStrategy parserStrategy;
        EncryptedCompressionStrategy encryptedCompressionStrategy;
        MessageBufferSharedPtr lastMessageBuffer;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_BUFFER_RECEIVE_STREAM_IMPL_H
