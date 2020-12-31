//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/28 16:28)

#ifndef NETWORK_BOOST_WRAPPERS_BOOST_FIXED_SOCK_STREAM_H
#define NETWORK_BOOST_WRAPPERS_BOOST_FIXED_SOCK_STREAM_H

#include "Network/NetworkDll.h"

#include "BoostSockStream.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE BoostFixedSockStream : public BoostSockStream
    {
    public:
        using ClassType = BoostFixedSockStream;
        using ParentType = BoostSockStream;

    public:
        BoostFixedSockStream() noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] int Receive(const MessageBufferSharedPtr& messageBuffer) override;
        void AsyncReceive(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer) override;

    private:
        void SubclassAsyncReceiveEvent(const ErrorCodeType& errorCode, const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer, int originalWriteIndex) override;
    };
}

#endif  // NETWORK_BOOST_WRAPPERS_BOOST_FIXED_SOCK_STREAM_H
