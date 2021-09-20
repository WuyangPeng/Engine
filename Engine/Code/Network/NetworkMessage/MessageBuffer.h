//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 9:57)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_BUFFER_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_BUFFER_H

#include "Network/NetworkDll.h"

#include "NetworkMessageInternalFwd.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <memory>
#include "CoreTools/Contract/ImplStaticAssertHelper.h"


EXPORT_SHARED_PTR(Network, MessageBufferImpl, NETWORK_DEFAULT_DECLARE);
namespace Network
{
    class NETWORK_DEFAULT_DECLARE MessageBuffer final
    {
    public:
    public:
        void Swap(MessageBuffer& rhs) noexcept;

    public:
        TYPE_DECLARE(MessageBuffer);
        using ClassShareType = CoreTools::CopyUnsharedClasses;
        ~MessageBuffer() noexcept = default;
        MessageBuffer(const MessageBuffer& rhs);
        MessageBuffer& operator=(const MessageBuffer& rhs);
        MessageBuffer(MessageBuffer&& rhs) noexcept;
        MessageBuffer& operator=(MessageBuffer&& rhs) noexcept;
        CORE_TOOLS_SHARED_PTR_DECLARE(MessageBuffer);
        using ImplTypeSharedPtr = std::shared_ptr<ImplType>;

    public:
        MessageBuffer(BuffBlockSize buffBlockSize, int count, ParserStrategy parserStrategy);
        MessageBuffer(BuffBlockSize buffBlockSize, ParserStrategy parserStrategy);
        MessageBuffer(int count, ParserStrategy parserStrategy);
        explicit MessageBuffer(const ImplTypeSharedPtr& messageBuffer) noexcept;

        CLASS_INVARIANT_DECLARE;

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
        [[nodiscard]] const char* GetCurrentReadBufferedPtr() const;
        [[nodiscard]] char* GetCurrentReadBufferedPtr();
        [[nodiscard]] const char* GetCurrentWriteBufferedPtr() const;
        [[nodiscard]] char* GetCurrentWriteBufferedPtr();
        [[nodiscard]] const char* GetInitialBufferedPtr() const;
        [[nodiscard]] char* GetInitialBufferedPtr();

        // 接收数量
        [[nodiscard]] int GetReceiveCount() const;
        void SetReceiveCount(int receiveCount);
        void DecreaseReceiveCount(int receiveCount);
        void SetMessageHeadReceiveCount();
        void SetMessageContentReceiveCount();

        // 消息长度
        [[nodiscard]] int GetMessageLength() const;
        bool IsMessageReceiveEnd() const;
        void CheckingMessageHeadSize();
        void CheckingMessageContentSize();

        // 辅助函数
        [[nodiscard]] ParserStrategy GetParserStrategy() const noexcept;
        [[nodiscard]] int GetSize() const;
        void PushBack(const MessageBuffer& messageBuffer);
        void ClearCurrentIndex() noexcept;
        [[nodiscard]] MessageBufferSharedPtr Expansion(int count) const;
        [[nodiscard]] MessageBufferSharedPtr Clone() const;

    private:
        using MessageBufferImplPtr = std::shared_ptr<ImplType>;

    private:
        MessageBufferImplPtr impl;
    };

    using MessageBufferSharedPtr = MessageBuffer::MessageBufferSharedPtr;
    using ConstMessageBufferSharedPtr = MessageBuffer::ConstMessageBufferSharedPtr;
}

 
EXPORT_SHARED_PTR(Network, MessageBuffer, NETWORK_DEFAULT_DECLARE);
#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_BUFFER_H
