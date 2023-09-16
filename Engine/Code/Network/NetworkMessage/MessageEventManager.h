///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/04 16:28)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_EVENT_MANAGER_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_EVENT_MANAGER_H

#include "Network/NetworkDll.h"

#include "NetworkMessageEvent.h"
#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/MessageEvent/EventInterface.h"

NETWORK_DELAY_COPY_UNSHARED_EXPORT_IMPL(MessageEventManager, MessageEventManagerImpl);

namespace Network
{
    class NETWORK_DEFAULT_DECLARE MessageEventManager final
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(MessageEventManager);

        using MessageEventManagerSharedPtr = std::shared_ptr<ClassType>;
        using EventInterfaceSharedPtr = CoreTools::EventInterfaceSharedPtr;

    public:
        NODISCARD static MessageEventManager Create();
        NODISCARD static MessageEventManagerSharedPtr CreateSharedPtr();

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

        void SetCallbackEvent(const EventInterfaceSharedPtr& eventInterface);
        NODISCARD EventInterfaceSharedPtr GetCallbackEvent();

    private:
        PackageType impl;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_EVENT_MANAGER_H
