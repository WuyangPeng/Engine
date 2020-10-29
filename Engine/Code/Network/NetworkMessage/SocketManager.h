//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 10:17)

#ifndef NETWORK_NETWORK_MESSAGE_SOCKET_MANAGER_H
#define NETWORK_NETWORK_MESSAGE_SOCKET_MANAGER_H

#include "Network/NetworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "MessageInterface.h"
#include "NetworkMessageEvent.h"
#include "Flags/MessageEventFlags.h"
#include "CoreTools/MessageEvent/EventInterface.h"
#include "Network/Interface/SendSocket.h"

NETWORK_EXPORT_SHARED_PTR(SocketManagerImpl);

namespace Network
{
    class NETWORK_DEFAULT_DECLARE SocketManager : public CoreTools::EventInterface, private boost::noncopyable
    {
    public:
        NON_COPY_CLASSES_TYPE_DECLARE(SocketManager);

    public:
        SocketManager();

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    public:
        void InsertSocket(uint64_t socketID);
        void RemoveSocket(uint64_t socketID);

        void OnEvent(uint64_t socketID, int64_t messageID, const ConstMessageInterfaceSharedPtr& message);

        [[nodiscard]] int GetSocketSize() const;

    protected:
        void InsertEvent(uint64_t socketID, int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent);
        void InsertEvent(uint64_t socketID, int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent, MessageEventPriority priority);
        void RemoveEvent(uint64_t socketID, int64_t messageID);
        void RemoveEvent(uint64_t socketID, int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent);

    private:
        virtual void InitEvent(uint64_t socketID) = 0;

    private:
        IMPL_TYPE_DECLARE(SocketManager);
    };

    CORE_TOOLS_SHARED_PTR_DECLARE(SocketManager);
    CORE_TOOLS_WEAK_PTR_DECLARE(SocketManager);
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_MANAGER_H
