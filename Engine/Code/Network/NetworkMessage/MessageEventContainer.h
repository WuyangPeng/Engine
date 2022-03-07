///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/18 15:39)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_EVENT_CONTAINER_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_EVENT_CONTAINER_H

#include "Network/NetworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "NetworkMessageInternalFwd.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"

NETWORK_DELAY_COPY_UNSHARED_EXPORT_IMPL(MessageEventContainer, MessageEventContainerImpl);

namespace Network
{
    class NETWORK_DEFAULT_DECLARE MessageEventContainer final
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(MessageEventContainer);

    public:
        NODISCARD static MessageEventContainer Create();

    private:
        explicit MessageEventContainer(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow);

    public:
        CLASS_INVARIANT_DECLARE;

        void Insert(const NetworkMessageEventSharedPtr& messageEvent);
        void Insert(const NetworkMessageEventSharedPtr& messageEvent, MessageEventPriority priority);
        void Remove(const NetworkMessageEventSharedPtr& messageEvent);

        void OnEvent(uint64_t socketID, const ConstMessageInterfaceSharedPtr& message);

    private:
        PackageType impl;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MESSAGE_EVENT_CONTAINER_H
