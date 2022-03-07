///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/18 15:40)

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
        NODISCARD static MessageEventManager Create();

    private:
        explicit MessageEventManager(CoreTools::DisableNotThrow disableNotThrow);

    public:
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
