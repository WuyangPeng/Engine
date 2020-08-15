// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎版本：0.0.2.4 (2020/03/10 14:22)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_BUFFER_IMPL_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_BUFFER_IMPL_H

#include "Network/NetworkDll.h"

#include "Network/NetworkMessage/NetworkMessageInternalFwd.h"

#include <atomic>
#include <memory>

namespace Network
{
    class NETWORK_HIDDEN_DECLARE MessageBufferImpl : public std::enable_shared_from_this<MessageBufferImpl>
    {
    public:
        using ClassType = MessageBufferImpl;
        using ImplPtr = std::shared_ptr<ClassType>;
        using ConstImplPtr = std::shared_ptr<const ClassType>;

    public:
        explicit MessageBufferImpl(ParserStrategy parserStrategy) noexcept;
        virtual ~MessageBufferImpl() noexcept;

        MessageBufferImpl(const MessageBufferImpl& rhs) noexcept;
        MessageBufferImpl& operator=(const MessageBufferImpl& rhs) noexcept;
        MessageBufferImpl(MessageBufferImpl&& rhs) noexcept;
        MessageBufferImpl& operator=(MessageBufferImpl&& rhs) noexcept;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

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
        virtual const char* GetCurrentReadBufferedPtr() const;
        virtual char* GetCurrentReadBufferedPtr();
        virtual const char* GetCurrentWriteBufferedPtr() const;
        virtual char* GetCurrentWriteBufferedPtr();
        virtual const char* GetInitialBufferedPtr() const = 0;
        virtual char* GetInitialBufferedPtr() = 0;

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
        void ClearCurrentIndex() noexcept;
        virtual void PushBack(const ConstImplPtr& messageBuffer);
        virtual ImplPtr Clone() const = 0;
        virtual BuffBlockSize GetBuffBlockSize() const = 0;
        virtual int GetSize() const = 0;
        virtual ImplPtr Expansion(int count) const = 0;

    private:
        bool IsNeedSwap() const noexcept;

    private:
        std::atomic_int m_CurrentReadIndex;
        std::atomic_int m_CurrentWriteIndex;
        std::atomic_int m_ReceiveCount;
        ParserStrategy m_ParserStrategy;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_BUFFER_IMPL_H
