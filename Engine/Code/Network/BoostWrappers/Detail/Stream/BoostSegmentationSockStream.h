///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/15 17:15)

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
        explicit BoostSegmentationSockStream(CoreTools::DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD int Receive(const MessageBufferSharedPtr& messageBuffer) override;
        void AsyncReceive(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer) override;

    private:
        NODISCARD int ReceiveHead(const MessageBufferSharedPtr& messageBuffer);
        NODISCARD int ReceiveContent(const MessageBufferSharedPtr& messageBuffer);

        void AsyncReceiveHead(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer);
        void AsyncReceiveContent(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer, int originalWriteIndex);

        void SubclassAsyncReceiveHeadEvent(const ErrorCodeType& errorCode, const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer, int originalWriteIndex);
        void SubclassAsyncReceiveContentEvent(const ErrorCodeType& errorCode, const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer, int originalWriteIndex);

        void SubclassAsyncReceiveEvent(const ErrorCodeType& errorCode, const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer, int originalWriteIndex) override;

    private:
        StreamReceive streamReceive;
    };
}

#endif  // NETWORK_BOOST_WRAPPERS_BOOST_SEGMENTATION_SOCK_STREAM_H
