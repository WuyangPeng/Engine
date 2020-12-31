//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/26 20:34)

#ifndef NETWORK_NETWORK_MESSAGE_BUFFER_SEND_STREAM_IMPL_H
#define NETWORK_NETWORK_MESSAGE_BUFFER_SEND_STREAM_IMPL_H

#include "Network/NetworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "Network/NetworkMessage/NetworkMessageInternalFwd.h"
#include "Network/NetworkMessage/SendMessageLevel.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE BufferSendStreamImpl final
    {
    public:
        using ClassType = BufferSendStreamImpl;

    public:
        BufferSendStreamImpl(int bytesTotal, ParserStrategy parserStrategy);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] bool Insert(const MessageInterfaceSharedPtr& message);
        void Save(const MessageBufferSharedPtr& messageBuffer);
        void Clear();

        [[nodiscard]] bool IsEmpty() const noexcept;
        [[nodiscard]] int GetCurrentSize() const;

    private:
        SendMessageLevel m_TopLevel;
        ParserStrategy m_ParserStrategy;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_BUFFER_SEND_STREAM_IMPL_H
