//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 10:00)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_EVENT_MANAGER_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_EVENT_MANAGER_H

#include "Network/NetworkDll.h"

#include "NetworkMessageEvent.h"
#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
NETWORK_DELAY_COPY_UNSHARED_EXPORT_IMPL(MessageEventManager, MessageEventManagerImpl);

namespace Network
{
    class NETWORK_DEFAULT_DECLARE MessageEventManager final
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(MessageEventManager);

    public:
        explicit MessageEventManager(CoreTools::DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_DECLARE;

    public:
        void Insert(int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent);
        void Insert(int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent, MessageEventPriority priority);
        void Remove(int64_t messageID);
        void Remove(int64_t messageID, const NetworkMessageEventSharedPtr& messageEvent);

        void OnEvent(int64_t messageID, uint64_t socketID, const ConstMessageInterfaceSharedPtr& message);

    private:
        PackageType impl;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_EVENT_MANAGER_H
