//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/27 9:53)

#ifndef NETWORK_NETWORK_MESSAGE_BUFFER_RECEIVE_STREAM_H
#define NETWORK_NETWORK_MESSAGE_BUFFER_RECEIVE_STREAM_H

#include "Network/NetworkDll.h"

#include "NetworkMessageInternalFwd.h"
#include "CoreTools/Helper/ExportMacro.h"

NETWORK_EXPORT_SHARED_PTR(BufferReceiveStreamImpl);

namespace Network
{
    class NETWORK_DEFAULT_DECLARE BufferReceiveStream final
    {
    public:
        DELAY_COPY_UNSHARE_CLASSES_TYPE_DECLARE(BufferReceiveStream);

    public:
        explicit BufferReceiveStream(const MessageBufferSharedPtr& messageBuffer, ParserStrategy parserStrategy);

        CLASS_INVARIANT_DECLARE;

        void OnEvent(uint64_t socketID, const SocketManagerSharedPtr& socketManager);

        // �����ȡδ��ɣ���Ҫ��������
        [[nodiscard]] bool IsFinish() const noexcept;

        void PushBack(const MessageBufferSharedPtr& messageBuffer);

    private:
        IMPL_TYPE_DECLARE(BufferReceiveStream);
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_BUFFER_RECEIVE_STREAM_H
