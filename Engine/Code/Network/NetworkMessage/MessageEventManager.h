///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.7 (2023/05/08 10:31)

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
        void Insert(int64_t messageId, const NetworkMessageEventSharedPtr& messageEvent);
        void Insert(int64_t messageId, const NetworkMessageEventSharedPtr& messageEvent, MessageEventPriority priority);
        void Remove(int64_t messageId);
        void Remove(int64_t messageId, const NetworkMessageEventSharedPtr& messageEvent);

        void Insert(const std::string& messageDescribe, const NetworkMessageEventSharedPtr& messageEvent);
        void Insert(const std::string& messageDescribe, const NetworkMessageEventSharedPtr& messageEvent, MessageEventPriority priority);

        void OnEvent(int64_t socketId, int64_t messageId, const ConstMessageInterfaceSharedPtr& message);
        void OnEvent(int64_t socketId, const std::string& messageDescribe, const ConstMessageInterfaceSharedPtr& message);

    private:
        PackageType impl;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_EVENT_MANAGER_H
