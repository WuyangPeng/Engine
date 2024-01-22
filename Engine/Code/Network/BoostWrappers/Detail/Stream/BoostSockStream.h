/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 17:21)

#ifndef NETWORK_BOOST_WRAPPERS_BOOST_SOCK_STREAM_H
#define NETWORK_BOOST_WRAPPERS_BOOST_SOCK_STREAM_H

#include "Network/NetworkDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "Network/Interface/Detail/SockStreamImpl.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE BoostSockStream : public SockStreamImpl
    {
    public:
        using ClassType = BoostSockStream;
        using ParentType = SockStreamImpl;

    public:
        explicit BoostSockStream(CoreTools::DisableNotThrow disableNotThrow);
        ~BoostSockStream() noexcept = 0;
        BoostSockStream(const BoostSockStream& rhs) = delete;
        BoostSockStream& operator=(const BoostSockStream& rhs) = delete;
        BoostSockStream(BoostSockStream&& rhs) noexcept = delete;
        BoostSockStream& operator=(BoostSockStream&& rhs) noexcept = delete;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD BoostSockStreamType& GetBoostSockStream() noexcept override;

        NODISCARD int Send(const MessageBufferSharedPtr& messageBuffer) override;
        void AsyncSend(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer) override;

        NODISCARD bool CloseHandle() override;

        NODISCARD bool EnableNonBlock() override;

        NODISCARD std::string GetRemoteAddress() const override;
        NODISCARD int GetRemotePort() const override;

    protected:
        NODISCARD int HandleReceive(const MessageBufferSharedPtr& messageBuffer);
        void HandleAsyncReceive(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer, int originalWriteIndex);

    private:
        void AsyncSendEvent(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer, int originalReadIndex, const ErrorCodeType& errorCode, size_t bytesTransferred);
        void AsyncReceiveEvent(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer, int originalWriteIndex, const ErrorCodeType& errorCode, size_t bytesTransferred);

        virtual void SubclassAsyncReceiveEvent(const ErrorCodeType& errorCode, const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer, int originalWriteIndex) = 0;

    private:
        BoostSockStreamType socket;
    };
}

#endif  // NETWORK_BOOST_WRAPPERS_BOOST_SOCK_STREAM_H
