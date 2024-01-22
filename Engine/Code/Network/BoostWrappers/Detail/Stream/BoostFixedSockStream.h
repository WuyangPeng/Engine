/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 17:22)

#ifndef NETWORK_BOOST_WRAPPERS_BOOST_FIXED_SOCK_STREAM_H
#define NETWORK_BOOST_WRAPPERS_BOOST_FIXED_SOCK_STREAM_H

#include "Network/NetworkDll.h"

#include "BoostSockStream.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE BoostFixedSockStream final : public BoostSockStream
    {
    public:
        using ClassType = BoostFixedSockStream;
        using ParentType = BoostSockStream;

    public:
        explicit BoostFixedSockStream(CoreTools::DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD int Receive(const MessageBufferSharedPtr& messageBuffer) override;
        void AsyncReceive(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer) override;

    private:
        void SubclassAsyncReceiveEvent(const ErrorCodeType& errorCode, const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer, int originalWriteIndex) override;
    };
}

#endif  // NETWORK_BOOST_WRAPPERS_BOOST_FIXED_SOCK_STREAM_H
