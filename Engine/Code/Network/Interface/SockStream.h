//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/27 20:26)

#ifndef NETWORK_NETWORK_INTERFACE_SOCK_STREAM_H
#define NETWORK_NETWORK_INTERFACE_SOCK_STREAM_H

#include "Network/NetworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "NetworkInternalFwd.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include <boost/noncopyable.hpp>

template class NETWORK_DEFAULT_DECLARE std::weak_ptr<Network::SockStream>;
template class NETWORK_DEFAULT_DECLARE std::enable_shared_from_this<Network::SockStream>;

NETWORK_NON_COPY_EXPORT_IMPL(SockStreamImpl);

namespace Network
{
    class NETWORK_DEFAULT_DECLARE SockStream final :    public std::enable_shared_from_this<SockStream>
    {
    public:
        NON_COPY_TYPE_DECLARE(SockStream);

    public:
        explicit SockStream(const ConfigurationStrategy& configurationStrategy);
        ~SockStream() noexcept = default;
        SockStream(const SockStream& rhs) noexcept = delete;
        SockStream& operator=(const SockStream& rhs) noexcept = delete;
        SockStream(SockStream&& rhs) noexcept = delete;
        SockStream& operator=(SockStream&& rhs) noexcept = delete;


        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] int Send(const MessageBufferSharedPtr& messageBuffer);
        [[nodiscard]] int Receive(const MessageBufferSharedPtr& messageBuffer);

        // �첽�ص������뱣֤this��EventInterface��MessageBuffer���������ں��̰߳�ȫ��
        void AsyncSend(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer);
        void AsyncReceive(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer);

        [[nodiscard]] ACESockStreamType& GetACESockStream();
        [[nodiscard]] BoostSockStreamType& GetBoostSockStream();
        [[nodiscard]] WinSocketStreamType& GetNetworkSockStream();

        [[nodiscard]] ACEHandleType GetACEHandle() const;

        void SetACEHandle(ACEHandleType handle);
        void SetNetworkHandle(WinSocketStreamType winSocket);

        [[nodiscard]] bool CloseHandle();

        [[nodiscard]] bool EnableNonBlock();

        [[nodiscard]] const std::string GetRemoteAddress() const;
        [[nodiscard]] int GetRemotePort() const;

    private:
        PackageType impl;
    };

    using SockStreamSharedPtr = std::shared_ptr<SockStream>;
    using ConstSockStreamSharedPtr = std::shared_ptr<const SockStream>;
}

#endif  // NETWORK_NETWORK_INTERFACE_SOCK_STREAM_H
