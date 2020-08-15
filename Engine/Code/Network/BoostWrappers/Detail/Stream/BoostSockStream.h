// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ����汾��0.0.2.4 (2020/03/11 15:48)

#ifndef NETWORK_BOOST_WRAPPERS_BOOST_SOCK_STREAM_H
#define NETWORK_BOOST_WRAPPERS_BOOST_SOCK_STREAM_H

#include "Network/NetworkDll.h"

#include "Network/Interface/Detail/SockStreamImpl.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE BoostSockStream : public SockStreamImpl
    {
    public:
        using ClassType = BoostSockStream;
        using ParentType = SockStreamImpl;

    public:
        BoostSockStream();
        ~BoostSockStream() = 0;
        BoostSockStream(const BoostSockStream&) = default;
        BoostSockStream& operator=(const BoostSockStream&) = default;
        BoostSockStream(BoostSockStream&&) noexcept = default;
        BoostSockStream& operator=(BoostSockStream&&) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

        BoostSockStreamType& GetBoostSockStream() noexcept override;

        int Send(const MessageBufferSharedPtr& messageBuffer) override;
        void AsyncSend(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer) override;

        bool CloseHandle() override;

        bool EnableNonBlock() override;

        const std::string GetRemoteAddress() const override;
        int GetRemotePort() const override;

    protected:
        int HandleReceive(const MessageBufferSharedPtr& messageBuffer);
        void HandleAsyncReceive(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer, int originalWriteIndex);

    private:
        void AsyncSendEvent(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer, int originalReadIndex, const ErrorCodeType& errorCode, size_t bytesTransferred);
        void AsyncReceiveEvent(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer, int originalWriteIndex, const ErrorCodeType& errorCode, size_t bytesTransferred);

        virtual void SubclassAsyncReceiveEvent(const ErrorCodeType& errorCode, const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer, int originalWriteIndex) = 0;

    private:
        BoostSockStreamType m_Socket;
    };
}

#endif  // NETWORK_BOOST_WRAPPERS_BOOST_SOCK_STREAM_H
