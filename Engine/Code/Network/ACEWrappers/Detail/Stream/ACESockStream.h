//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/28 14:33)

#ifndef NETWORK_NETWORK_INTERFACE_ACE_SOCK_STREAM_H
#define NETWORK_NETWORK_INTERFACE_ACE_SOCK_STREAM_H

#include "Network/NetworkDll.h"

#ifdef NETWORK_USE_ACE

    #include "Network/Interface/Detail/SockStreamImpl.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE ACESockStream : public SockStreamImpl
    {
    public:
        using ClassType = ACESockStream;
        using ParentType = SockStreamImpl;

    public:
        ACESockStream() noexcept;
        ~ACESockStream() noexcept;
        ACESockStream(const ACESockStream& rhs) = delete;
        ACESockStream& operator=(const ACESockStream& rhs) = delete;
        ACESockStream(ACESockStream&& rhs) noexcept = delete;
        ACESockStream& operator=(ACESockStream&& rhs) noexcept = delete;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] ACESockStreamNativeType& GetACESockStream() noexcept override;

        [[nodiscard]] int Send(const MessageBufferSharedPtr& messageBuffer) override;
        [[nodiscard]] int Receive(const MessageBufferSharedPtr& messageBuffer) override;

        void AsyncSend(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer) override;
        void AsyncReceive(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer) override;

        [[nodiscard]] ACEHandle GetACEHandle() const override;

        void SetACEHandle(ACEHandle handle) override;
        [[nodiscard]] bool CloseHandle() override;

        [[nodiscard]] const std::string GetRemoteAddress() const override;
        [[nodiscard]] int GetRemotePort() const override;

        [[nodiscard]] bool EnableNonBlock() override;

    private:
        ACE_SOCK_Stream m_ACESockStream;
    };
}

#endif  // NETWORK_USE_ACE

#endif  // NETWORK_NETWORK_INTERFACE_ACE_SOCK_STREAM_H
