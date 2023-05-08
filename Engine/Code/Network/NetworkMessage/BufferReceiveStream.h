///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.7 (2023/05/08 13:40)

#ifndef NETWORK_NETWORK_MESSAGE_BUFFER_RECEIVE_STREAM_H
#define NETWORK_NETWORK_MESSAGE_BUFFER_RECEIVE_STREAM_H

#include "Network/NetworkDll.h"

#include "NetworkMessageInternalFwd.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"

NETWORK_DELAY_COPY_UNSHARED_EXPORT_IMPL(BufferReceiveStream, BufferReceiveStreamImpl);

namespace Network
{
    class NETWORK_DEFAULT_DECLARE BufferReceiveStream final
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(BufferReceiveStream);

    public:
        explicit BufferReceiveStream(const MessageBufferSharedPtr& messageBuffer, ParserStrategy parserStrategy, EncryptedCompressionStrategy encryptedCompressionStrategy);

        CLASS_INVARIANT_DECLARE;

        void OnEvent(uint64_t socketId, MessageEventManager& messageEventManager);

        // 如果读取未完成，需要继续解析
        NODISCARD bool IsFinish() const noexcept;

        void PushBack(const MessageBufferSharedPtr& messageBuffer);

    private:
        PackageType impl;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_BUFFER_RECEIVE_STREAM_H
