///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/18 14:07)

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
        NODISCARD int GetCurrentSize() const;

    private:
        PackageType impl;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_BUFFER_SEND_STREAM_H
