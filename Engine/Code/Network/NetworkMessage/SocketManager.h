///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/18 18:18)

#ifndef NETWORK_NETWORK_MESSAGE_SOCKET_MANAGER_H
#define NETWORK_NETWORK_MESSAGE_SOCKET_MANAGER_H

#include "Network/NetworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "MessageInterface.h"
#include "NetworkMessageEvent.h"
#include "Flags/MessageEventFlags.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/MessageEvent/EventInterface.h"
#include "Network/Interface/SendSocket.h"

NETWORK_NON_COPY_EXPORT_IMPL(SocketManagerImpl);

namespace Network
{
    class NETWORK_DEFAULT_DECLARE SocketManager : public CoreTools::EventInterface
    {
    public:
        NON_COPY_TYPE_DECLARE(SocketManager);

    protected:
        explicit SocketManager(CoreTools::DisableNotThrow disableNotThrow);

    public:
        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void InsertSocket(uint64_t socketID);
        void RemoveSocket(uint64_t socketID);

        void OnEvent(uint64_t socketID, int64_t messageID, const ConstMessageInterfaceSharedPtr& message);

        NODISCARD int GetSocketSize() const;

    protected:
        void InsertEvent(uint64_t socketID, int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent);
        void InsertEvent(uint64_t socketID, int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent, MessageEventPriority priority);
        void RemoveEvent(uint64_t socketID, int64_t messageID);
        void RemoveEvent(uint64_t socketID, int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent);

    private:
        virtual void InitEvent(uint64_t socketID) = 0;

    private:
        PackageType impl;
    };

    CORE_TOOLS_SHARED_PTR_DECLARE(SocketManager);
    CORE_TOOLS_WEAK_PTR_DECLARE(SocketManager);
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_MANAGER_H
