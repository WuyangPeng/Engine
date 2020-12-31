//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 20:26)

#ifndef NETWORK_NETWORK_INTERFACE_SOCK_STREAM_H
#define NETWORK_NETWORK_INTERFACE_SOCK_STREAM_H

#include "Network/NetworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "NetworkInternalFwd.h"

#include <boost/noncopyable.hpp>

template class NETWORK_DEFAULT_DECLARE std::weak_ptr<Network::SockStream>;
template class NETWORK_DEFAULT_DECLARE std::enable_shared_from_this<Network::SockStream>;

NETWORK_EXPORT_SHARED_PTR(SockStreamImpl);
EXPORT_NONCOPYABLE_CLASS(NETWORK);

namespace Network
{
    class NETWORK_DEFAULT_DECLARE SockStream final : private boost::noncopyable, public std::enable_shared_from_this<SockStream>
    {
    public:
        NON_COPY_CLASSES_TYPE_DECLARE(SockStream);

    public:
        explicit SockStream(const ConfigurationStrategy& configurationStrategy);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] int Send(const MessageBufferSharedPtr& messageBuffer);
        [[nodiscard]] int Receive(const MessageBufferSharedPtr& messageBuffer);

        // 异步回调，必须保证this、EventInterface和MessageBuffer的生命周期和线程安全。
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
        IMPL_TYPE_DECLARE(SockStream);
    };

    using SockStreamSharedPtr = std::shared_ptr<SockStream>;
    using ConstSockStreamSharedPtr = std::shared_ptr<const SockStream>;
}

#endif  // NETWORK_NETWORK_INTERFACE_SOCK_STREAM_H
