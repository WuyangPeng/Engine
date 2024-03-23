/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 17:31)

#ifndef NETWORK_NETWORK_INTERFACE_ACE_SOCK_STREAM_H
#define NETWORK_NETWORK_INTERFACE_ACE_SOCK_STREAM_H

#include "Network/NetworkDll.h"

#include "Network/Interface/Detail/SockStreamImpl.h"

#ifdef NETWORK_USE_ACE

namespace Network
{
    class NETWORK_HIDDEN_DECLARE AceSockStream : public SockStreamImpl
    {
    public:
        using ClassType = AceSockStream;
        using ParentType = SockStreamImpl;

    public:
        AceSockStream() noexcept;
        ~AceSockStream() noexcept;
        AceSockStream(const AceSockStream& rhs) = delete;
        AceSockStream& operator=(const AceSockStream& rhs) = delete;
        AceSockStream(AceSockStream&& rhs) noexcept = delete;
        AceSockStream& operator=(AceSockStream&& rhs) noexcept = delete;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD ACESockStreamNativeType& GetACESockStream() noexcept override;

        NODISCARD int Send(const MessageBufferSharedPtr& messageBuffer) override;
        NODISCARD int Receive(const MessageBufferSharedPtr& messageBuffer) override;

        void AsyncSend(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer) override;
        void AsyncReceive(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer) override;

        NODISCARD ACEHandleType GetACEHandle() const override;

        void SetACEHandle(ACEHandleType handle) override;
        NODISCARD bool CloseHandle() override;

        NODISCARD std::string GetRemoteAddress() const override;
        NODISCARD int GetRemotePort() const override;

        NODISCARD bool EnableNonBlock() override;

    private:
        ACE_SOCK_Stream aceSockStream;
    };
}

#endif  // NETWORK_USE_ACE

#endif  // NETWORK_NETWORK_INTERFACE_ACE_SOCK_STREAM_H
