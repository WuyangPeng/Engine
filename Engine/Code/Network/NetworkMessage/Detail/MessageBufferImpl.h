//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/26 20:36)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_BUFFER_IMPL_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_BUFFER_IMPL_H

#include "Network/NetworkDll.h"

#include "System/Helper/PragmaWarning.h"
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

        virtual ~MessageBufferImpl() noexcept = default;
        MessageBufferImpl(const MessageBufferImpl& rhs) noexcept;
        MessageBufferImpl& operator=(const MessageBufferImpl& rhs) noexcept;
        MessageBufferImpl(MessageBufferImpl&& rhs) noexcept;
        MessageBufferImpl& operator=(MessageBufferImpl&& rhs) noexcept;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        // 读
        [[nodiscard]] int GetCurrentReadIndex() const noexcept;
        [[nodiscard]] int GetRemainingReadCount() const noexcept;
        void ClearCurrentReadIndex() noexcept;
        void AddCurrentReadIndex(int stepping);
        void Read(int itemSize, void* data);
        void Read(int itemSize, int itemsNumber, void* data);

        // 写
        [[nodiscard]] int GetCurrentWriteIndex() const noexcept;
        [[nodiscard]] int GetRemainingWriteCount() const;
        void ClearCurrentWriteIndex() noexcept;
        void AddCurrentWriteIndex(int stepping);
        void Write(int itemSize, const void* data);
        void Write(int itemSize, int itemsNumber, const void* data);

        // 缓冲区
        [[nodiscard]] virtual const char* GetCurrentReadBufferedPtr() const;
        [[nodiscard]] virtual char* GetCurrentReadBufferedPtr();
        [[nodiscard]] virtual const char* GetCurrentWriteBufferedPtr() const;
        [[nodiscard]] virtual char* GetCurrentWriteBufferedPtr();
        [[nodiscard]] virtual const char* GetInitialBufferedPtr() const = 0;
        [[nodiscard]] virtual char* GetInitialBufferedPtr() = 0;

        // 接收数量
        [[nodiscard]] int GetReceiveCount() const;
        void SetReceiveCount(int receiveCount);
        void DecreaseReceiveCount(int receiveCount);
        void SetMessageHeadReceiveCount();
        void SetMessageContentReceiveCount();

        // 消息长度
        [[nodiscard]] int GetMessageLength() const;
        [[nodiscard]] bool IsMessageReceiveEnd() const;
        void CheckingMessageHeadSize();
        void CheckingMessageContentSize();

        // 辅助函数
        [[nodiscard]] ParserStrategy GetParserStrategy() const noexcept;
        void ClearCurrentIndex() noexcept;
        virtual void PushBack(const ConstImplPtr& messageBuffer);
        [[nodiscard]] virtual ImplPtr Clone() const = 0;
        [[nodiscard]] virtual BuffBlockSize GetBuffBlockSize() const = 0;
        [[nodiscard]] virtual int GetSize() const = 0;
        [[nodiscard]] virtual ImplPtr Expansion(int count) const = 0;

    private:
        [[nodiscard]] bool IsNeedSwap() const;

    private:
        std::atomic_int m_CurrentReadIndex;
        std::atomic_int m_CurrentWriteIndex;
        std::atomic_int m_ReceiveCount;
        ParserStrategy m_ParserStrategy;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_BUFFER_IMPL_H
