//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 20:23)

#ifndef NETWORK_NETWORK_INTERFACE_SEND_SOCKET_MANAGER_H
#define NETWORK_NETWORK_INTERFACE_SEND_SOCKET_MANAGER_H

#include "Network/NetworkDll.h"

#include "SendSocket.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/MessageEvent/EventInterface.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/Interface/InterfaceFwd.h"
#include "Network/NetworkMessage/MessageInterface.h"

#include <boost/noncopyable.hpp>
#include <map>

EXPORT_NONCOPYABLE_CLASS(NETWORK);
NETWORK_EXPORT_SHARED_PTR(SendSocketManagerImpl);

namespace Network
{
    class NETWORK_DEFAULT_DECLARE SendSocketManager : private boost::noncopyable
    {
    public:
        NON_COPY_CLASSES_TYPE_DECLARE(SendSocketManager);

    public:
        explicit SendSocketManager(const std::string& fileName);

        CLASS_INVARIANT_DECLARE;

        // 发送网络消息
        void Send(const SocketData& socketData, uint64_t socketID, const MessageInterfaceSharedPtr& message);

        [[nodiscard]] SendSocketSharedPtr GetSendSocket(const SocketData& socketData);
        [[nodiscard]] SocketManagerSharedPtr GetSocketManager() noexcept;

    private:
        IMPL_TYPE_DECLARE(SendSocketManager);
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_SEND_SOCKET_MANAGER_H
