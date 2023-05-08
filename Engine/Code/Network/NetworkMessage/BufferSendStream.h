///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.7 (2023/05/08 13:32)

#ifndef NETWORK_NETWORK_MESSAGE_BUFFER_SEND_STREAM_H
#define NETWORK_NETWORK_MESSAGE_BUFFER_SEND_STREAM_H

#include "Network/NetworkDll.h"

#include "NetworkMessageInternalFwd.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"

NETWORK_DELAY_COPY_UNSHARED_EXPORT_IMPL(BufferSendStream, BufferSendStreamImpl);

namespace Network
{
    class NETWORK_DEFAULT_DECLARE BufferSendStream final
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(BufferSendStream);

    public:
        BufferSendStream(int bytesTotal, ParserStrategy parserStrategy, EncryptedCompressionStrategy encryptedCompressionStrategy);

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool Insert(const MessageInterfaceSharedPtr& message);
        void Save(const MessageBufferSharedPtr& messageBuffer);
        void Clear();

        NODISCARD bool IsEmpty() const noexcept;
        NODISCARD int GetCurrentSize() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_BUFFER_SEND_STREAM_H
