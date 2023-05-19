///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.8 (2023/05/09 11:35)

#ifndef NETWORK_NETWORK_STREAM_CONTAINER_H
#define NETWORK_NETWORK_STREAM_CONTAINER_H

#include "Network/NetworkDll.h"

#include "Network/Interface/SockStream.h"
#include "Network/NetworkMessage/BufferSendStream.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE StreamContainer final
    {
    public:
        using ClassType = StreamContainer;

    public:
        StreamContainer(const ConfigurationStrategy& configurationStrategy, const SockStreamSharedPtr& sockStream);

        CLASS_INVARIANT_DECLARE;

        void SetSockStream(const SockStreamSharedPtr& aSockStream) noexcept;

        NODISCARD SockStreamSharedPtr GetSockStream() noexcept;
        NODISCARD BufferSendStream& GetBufferSendStream() noexcept;

    private:
        BufferSendStream bufferSendStream;
        SockStreamSharedPtr sockStream;
    };
}

#endif  // NETWORK_NETWORK_STREAM_CONTAINER_H
