//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/28 16:28)

#ifndef NETWORK_BOOST_WRAPPERS_BOOST_SEGMENTATION_SOCK_STREAM_H
#define NETWORK_BOOST_WRAPPERS_BOOST_SEGMENTATION_SOCK_STREAM_H

#include "Network/NetworkDll.h"

#include "BoostSockStream.h"
#include "Network/Interface/Flags/StreamFlags.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE BoostSegmentationSockStream : public BoostSockStream
    {
    public:
        using ClassType = BoostSegmentationSockStream;
        using ParentType = BoostSockStream;

    public:
        BoostSegmentationSockStream() noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] int Receive(const MessageBufferSharedPtr& messageBuffer) override;
        void AsyncReceive(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer) override;

    private:
        [[nodiscard]] int ReceiveHead(const MessageBufferSharedPtr& messageBuffer);
        [[nodiscard]] int ReceiveContent(const MessageBufferSharedPtr& messageBuffer);

        void AsyncReceiveHead(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer);
        void AsyncReceiveContent(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer, int originalWriteIndex);

        void SubclassAsyncReceiveHeadEvent(const ErrorCodeType& errorCode, const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer, int originalWriteIndex);
        void SubclassAsyncReceiveContentEvent(const ErrorCodeType& errorCode, const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer, int originalWriteIndex);

        void SubclassAsyncReceiveEvent(const ErrorCodeType& errorCode, const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer, int originalWriteIndex) override;

    private:
        StreamReceive m_StreamReceive;
    };
}

#endif  // NETWORK_BOOST_WRAPPERS_BOOST_SEGMENTATION_SOCK_STREAM_H
