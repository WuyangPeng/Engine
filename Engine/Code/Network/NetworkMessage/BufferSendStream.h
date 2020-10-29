//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/27 9:53)

#ifndef NETWORK_NETWORK_MESSAGE_BUFFER_SEND_STREAM_H
#define NETWORK_NETWORK_MESSAGE_BUFFER_SEND_STREAM_H

#include "Network/NetworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "NetworkMessageInternalFwd.h"

NETWORK_EXPORT_SHARED_PTR(BufferSendStreamImpl);

namespace Network
{
    class NETWORK_DEFAULT_DECLARE BufferSendStream final
    {
    public:
        DELAY_COPY_UNSHARE_CLASSES_TYPE_DECLARE(BufferSendStream);

    public:
        BufferSendStream(int bytesTotal, ParserStrategy parserStrategy);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] bool Insert(const MessageInterfaceSharedPtr& message);
        void Save(const MessageBufferSharedPtr& messageBuffer);
        void Clear();

        [[nodiscard]] bool IsEmpty() const noexcept;
        [[nodiscard]] int GetCurrentSize() const;

    private:
        IMPL_TYPE_DECLARE(BufferSendStream);
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_BUFFER_SEND_STREAM_H
