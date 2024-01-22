/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:33)

#ifndef NETWORK_NETWORK_INTERFACE_SOCK_STREAM_H
#define NETWORK_NETWORK_INTERFACE_SOCK_STREAM_H

#include "Network/NetworkDll.h"

#include "NetworkInternalFwd.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"

template class NETWORK_DEFAULT_DECLARE std::weak_ptr<Network::SockStream>;
template class NETWORK_DEFAULT_DECLARE std::enable_shared_from_this<Network::SockStream>;

NETWORK_NON_COPY_EXPORT_IMPL(SockStreamImpl);

namespace Network
{
    class NETWORK_DEFAULT_DECLARE SockStream final : public std::enable_shared_from_this<SockStream>
    {
    public:
        NON_COPY_TYPE_DECLARE(SockStream);

    public:
        explicit SockStream(const ConfigurationStrategy& configurationStrategy);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int Send(const MessageBufferSharedPtr& messageBuffer);
        NODISCARD int Receive(const MessageBufferSharedPtr& messageBuffer);

        // 异步回调，必须保证this、EventInterface和MessageBuffer的生命周期和线程安全。
        void AsyncSend(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer);
        void AsyncReceive(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer);

        NODISCARD ACESockStreamType& GetACESockStream();
        NODISCARD BoostSockStreamType& GetBoostSockStream();
        NODISCARD WinSocketStreamType& GetNetworkSockStream();

        NODISCARD ACEHandleType GetACEHandle() const;

        void SetACEHandle(ACEHandleType handle);
        void SetNetworkHandle(WinSocketStreamType winSocket);

        NODISCARD bool CloseHandle();

        NODISCARD bool EnableNonBlock();

        NODISCARD std::string GetRemoteAddress() const;
        NODISCARD int GetRemotePort() const;

    private:
        PackageType impl;
    };

    using SockStreamSharedPtr = std::shared_ptr<SockStream>;
    using ConstSockStreamSharedPtr = std::shared_ptr<const SockStream>;
}

#endif  // NETWORK_NETWORK_INTERFACE_SOCK_STREAM_H
