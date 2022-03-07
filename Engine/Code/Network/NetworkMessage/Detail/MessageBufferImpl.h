///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/18 10:44)

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
        using FactoryType = MessageBufferFactory;
        using MessageBufferSharedPtr = std::shared_ptr<MessageBuffer>;

    public:
        explicit MessageBufferImpl(ParserStrategy parserStrategy) noexcept;

        virtual ~MessageBufferImpl() noexcept = default;
        MessageBufferImpl(const MessageBufferImpl& rhs) noexcept;
        MessageBufferImpl& operator=(const MessageBufferImpl& rhs) noexcept;
        MessageBufferImpl(MessageBufferImpl&& rhs) noexcept;
        MessageBufferImpl& operator=(MessageBufferImpl&& rhs) noexcept;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        // 读
        NODISCARD int GetCurrentReadIndex() const noexcept;
        NODISCARD int GetRemainingReadCount() const noexcept;
        void ClearCurrentReadIndex() noexcept;
        void AddCurrentReadIndex(int stepping);
        void Read(int itemSize, void* data);
        void Read(int itemSize, int itemsNumber, void* data);

        // 写
        NODISCARD int GetCurrentWriteIndex() const noexcept;
        NODISCARD int GetRemainingWriteCount() const;
        void ClearCurrentWriteIndex() noexcept;
        void AddCurrentWriteIndex(int stepping);
        void Write(int itemSize, const void* data);
        void Write(int itemSize, int itemsNumber, const void* data);

        // 缓冲区
        NODISCARD virtual const char* GetCurrentReadBufferedPtr() const;
        NODISCARD virtual char* GetCurrentReadBufferedPtr();
        NODISCARD virtual const char* GetCurrentWriteBufferedPtr() const;
        NODISCARD virtual char* GetCurrentWriteBufferedPtr();
        NODISCARD virtual const char* GetInitialBufferedPtr() const = 0;
        NODISCARD virtual char* GetInitialBufferedPtr() = 0;

        // 接收数量
        NODISCARD int GetReceiveCount() const;
        void SetReceiveCount(int receiveCount);
        void DecreaseReceiveCount(int receiveCount);
        void SetMessageHeadReceiveCount();
        void SetMessageContentReceiveCount();

        // 消息长度
        NODISCARD int GetMessageLength() const;
        NODISCARD bool IsMessageReceiveEnd() const;
        void CheckingMessageHeadSize();
        void CheckingMessageContentSize();

        // 辅助函数
        NODISCARD ParserStrategy GetParserStrategy() const noexcept;
        void ClearCurrentIndex() noexcept;
        virtual void PushBack(const MessageBufferImpl& messageBuffer);
        NODISCARD virtual ImplPtr Clone() const = 0;
        NODISCARD virtual BuffBlockSize GetBuffBlockSize() const = 0;
        NODISCARD virtual int GetSize() const = 0;
        NODISCARD virtual ImplPtr Expansion(int count) const = 0;

    private:
        NODISCARD bool IsNeedSwap() const;

    private:
        std::atomic_int currentReadIndex;
        std::atomic_int currentWriteIndex;
        std::atomic_int m_ReceiveCount;
        ParserStrategy parserStrategy;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_BUFFER_IMPL_H
