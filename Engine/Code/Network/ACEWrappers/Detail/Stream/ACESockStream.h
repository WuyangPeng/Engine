///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.8 (2023/05/09 14:04)

#ifndef NETWORK_NETWORK_INTERFACE_ACE_SOCK_STREAM_H
#define NETWORK_NETWORK_INTERFACE_ACE_SOCK_STREAM_H

#include "Network/NetworkDll.h"

#include "Network/Interface/Detail/SockStreamImpl.h"

#ifdef NETWORK_USE_ACE

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
