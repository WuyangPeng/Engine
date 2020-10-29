//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/27 10:00)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_EVENT_CONTAINER_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_EVENT_CONTAINER_H

#include "Network/NetworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "NetworkMessageInternalFwd.h"

NETWORK_EXPORT_SHARED_PTR(MessageEventContainerImpl);

namespace Network
{
    class NETWORK_DEFAULT_DECLARE MessageEventContainer final
    {
    public:
        DELAY_COPY_UNSHARE_CLASSES_TYPE_DECLARE(MessageEventContainer);

    public:
        MessageEventContainer();

        CLASS_INVARIANT_DECLARE;

        void Insert(const NetworkMessageEventSharedPtr& messageEvent);
        void Insert(const NetworkMessageEventSharedPtr& messageEvent, MessageEventPriority priority);
        void Remove(const NetworkMessageEventSharedPtr& messageEvent);

        void OnEvent(uint64_t socketID, const ConstMessageInterfaceSharedPtr& message);

    private:
        IMPL_TYPE_DECLARE(MessageEventContainer);
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_EVENT_CONTAINER_H
