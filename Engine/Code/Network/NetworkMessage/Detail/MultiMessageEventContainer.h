///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.7 (2023/05/08 10:28)

#ifndef NETWORK_NETWORK_MESSAGE_MULTI_MESSAGE_EVENT_CONTAINER_H
#define NETWORK_NETWORK_MESSAGE_MULTI_MESSAGE_EVENT_CONTAINER_H

#include "Network/NetworkDll.h"

#include "MessageEventContainerImpl.h"
#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Contract/ImplStaticAssertHelper.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Network/NetworkMessage/NetworkMessageInternalFwd.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE MultiMessageEventContainer final : public MessageEventContainerImpl
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(MultiMessageEventContainer);
        using ParentType = MessageEventContainerImpl;

    public:
        explicit MultiMessageEventContainer(CoreTools::DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_FINAL_DECLARE;

        void Insert(const NetworkMessageEventSharedPtr& messageEvent) override;
        void Insert(const NetworkMessageEventSharedPtr& messageEvent, MessageEventPriority aPriority) override;
        void Remove(const NetworkMessageEventSharedPtr& messageEvent) noexcept override;

        void OnEvent(uint64_t socketId, const ConstMessageInterfaceSharedPtr& message) override;

        NODISCARD ImplPtr Clone() const override;
        NODISCARD ImplPtr CloneToMultiMessage() const override;
        NODISCARD ImplPtr CloneToPriorityMessage() const override;

        NODISCARD bool IsCanInsert() const noexcept override;
        NODISCARD bool IsPrioritySame(MessageEventPriority aPriority) const noexcept override;

    private:
        PackageType impl;
        MessageEventPriority priority;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MULTI_MESSAGE_EVENT_CONTAINER_H
