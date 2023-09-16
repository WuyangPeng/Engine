///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/04 16:23)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_BUFFER_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_BUFFER_H

#include "Network/NetworkDll.h"

#include "NetworkMessageInternalFwd.h"
#include "CoreTools/Contract/ImplStaticAssertHelper.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <memory>

NETWORK_COPY_UNSHARED_EXPORT_IMPL(MessageBuffer, MessageBufferImpl);

namespace Network
{
    class NETWORK_DEFAULT_DECLARE MessageBuffer final
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(MessageBuffer);

        using MessageBufferSharedPtr = std::shared_ptr<MessageBuffer>;
        using ConstMessageBufferSharedPtr = std::shared_ptr<const MessageBuffer>;

    public:
        MessageBuffer(BuffBlockSize buffBlockSize, int count, ParserStrategy parserStrategy);
        MessageBuffer(BuffBlockSize buffBlockSize, ParserStrategy parserStrategy);
        MessageBuffer(int count, ParserStrategy parserStrategy);

        CLASS_INVARIANT_DECLARE;

        // ��
        NODISCARD int GetCurrentReadIndex() const noexcept;
        NODISCARD int GetRemainingReadCount() const noexcept;
        void ClearCurrentReadIndex() noexcept;
        void AddCurrentReadIndex(int stepping);
        void Read(int itemSize, void* data);
        void Read(int itemSize, int itemsNumber, void* data);

        // д
        NODISCARD int GetCurrentWriteIndex() const noexcept;
        NODISCARD int GetRemainingWriteCount() const;
        void ClearCurrentWriteIndex() noexcept;
        void AddCurrentWriteIndex(int stepping);
        void Write(int itemSize, const void* data);
        void Write(int itemSize, int itemsNumber, const void* data);

        // ������
        NODISCARD const char* GetCurrentReadBufferedPtr() const;
        NODISCARD char* GetCurrentReadBufferedPtr();
        NODISCARD const char* GetCurrentWriteBufferedPtr() const;
        NODISCARD char* GetCurrentWriteBufferedPtr();
        NODISCARD const char* GetInitialBufferedPtr() const;
        NODISCARD char* GetInitialBufferedPtr();

        // ��������
        NODISCARD int GetReceiveCount() const;
        void SetReceiveCount(int receiveCount);
        void DecreaseReceiveCount(int receiveCount);
        void SetMessageHeadReceiveCount();
        void SetMessageContentReceiveCount();

        // ��Ϣ����
        NODISCARD int GetMessageLength() const;
        NODISCARD bool IsMessageReceiveEnd() const;
        void CheckingMessageHeadSize();
        void CheckingMessageContentSize();

        // ��������
        NODISCARD ParserStrategy GetParserStrategy() const noexcept;
        NODISCARD int GetSize() const;
        void PushBack(const MessageBuffer& messageBuffer);
        void ClearCurrentIndex() noexcept;
        NODISCARD MessageBufferSharedPtr Expansion(int count) const;
        NODISCARD MessageBufferSharedPtr Clone() const;

    private:
        PackageType impl;
    };

    using MessageBufferSharedPtr = MessageBuffer::MessageBufferSharedPtr;
    using ConstMessageBufferSharedPtr = MessageBuffer::ConstMessageBufferSharedPtr;
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_BUFFER_H
