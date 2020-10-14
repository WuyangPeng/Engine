// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎版本：0.0.2.4 (2020/03/10 14:29)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_BUFFER_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_BUFFER_H

#include "Network/NetworkDll.h"

#include "NetworkMessageInternalFwd.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <memory>

NETWORK_EXPORT_SHARED_PTR(MessageBufferImpl);

namespace Network
{
    enum class ParserStrategy;

    class NETWORK_DEFAULT_DECLARE MessageBuffer
    {
    public:
        COPY_UNSHARE_CLASSES_TYPE_DECLARE(MessageBuffer, = default);
        using MessageBufferSharedPtr = std::shared_ptr<MessageBuffer>;
        using ConstMessageBufferSharedPtr = std::shared_ptr<const MessageBuffer>;
        using ImplTypeSharedPtr = std::shared_ptr<ImplType>;

    public:
        MessageBuffer(BuffBlockSize buffBlockSize, int count, ParserStrategy parserStrategy);
        MessageBuffer(BuffBlockSize buffBlockSize, ParserStrategy parserStrategy);
        MessageBuffer(int count, ParserStrategy parserStrategy);
        explicit MessageBuffer(const ImplTypeSharedPtr& messageBuffer) noexcept;
     

        CLASS_INVARIANT_DECLARE;

        // 读
        int GetCurrentReadIndex() const noexcept;
        int GetRemainingReadCount() const noexcept;
        void ClearCurrentReadIndex() noexcept;
        void AddCurrentReadIndex(int stepping);
        void Read(int itemSize, void* data);
        void Read(int itemSize, int itemsNumber, void* data);

        // 写
        int GetCurrentWriteIndex() const noexcept;
        int GetRemainingWriteCount() const;
        void ClearCurrentWriteIndex() noexcept;
        void AddCurrentWriteIndex(int stepping);
        void Write(int itemSize, const void* data);
        void Write(int itemSize, int itemsNumber, const void* data);

        // 缓冲区
        const char* GetCurrentReadBufferedPtr() const;
        char* GetCurrentReadBufferedPtr();
        const char* GetCurrentWriteBufferedPtr() const;
        char* GetCurrentWriteBufferedPtr();
        const char* GetInitialBufferedPtr() const;
        char* GetInitialBufferedPtr();

        // 接收数量
        int GetReceiveCount() const;
        void SetReceiveCount(int receiveCount);
        void DecreaseReceiveCount(int receiveCount);
        void SetMessageHeadReceiveCount();
        void SetMessageContentReceiveCount();

        // 消息长度
        int GetMessageLength() const;
        bool IsMessageReceiveEnd() const;
        void CheckingMessageHeadSize();
        void CheckingMessageContentSize();

        // 辅助函数
        ParserStrategy GetParserStrategy() const noexcept;
        int GetSize() const;
        void PushBack(const ConstMessageBufferSharedPtr& messageBuffer);
        void ClearCurrentIndex() noexcept;
        MessageBufferSharedPtr Expansion(int count) const;
        MessageBufferSharedPtr Clone() const;

    private:
        IMPL_TYPE_DECLARE(MessageBuffer);
    };

    using MessageBufferSharedPtr = MessageBuffer::MessageBufferSharedPtr;
    using ConstMessageBufferSharedPtr = MessageBuffer::ConstMessageBufferSharedPtr;
}

NETWORK_EXPORT_SHARED_PTR(MessageBuffer);

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_BUFFER_H
