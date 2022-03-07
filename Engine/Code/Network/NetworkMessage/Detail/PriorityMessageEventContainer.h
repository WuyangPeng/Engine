///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/18 11:50)

#ifndef NETWORK_NETWORK_MESSAGE_PRIORITY_MESSAGE_EVENT_CONTAINER_H
#define NETWORK_NETWORK_MESSAGE_PRIORITY_MESSAGE_EVENT_CONTAINER_H

#include "Network/NetworkDll.h"

#include "MessageEventContainerImpl.h"
#include "MultiMessageEventContainerImpl.h"
#include "CoreTools/Contract/ContractFwd.h"

#include <vector>

namespace Network
{
    class NETWORK_HIDDEN_DECLARE PriorityMessageEventContainer final : public MessageEventContainerImpl
    {
    public:
        using ClassType = PriorityMessageEventContainer;
        using ParentType = MessageEventContainerImpl;

    public:
        explicit PriorityMessageEventContainer(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_FINAL_DECLARE;

        void Insert(const NetworkMessageEventSharedPtr& messageEvent) final;
        void Insert(const NetworkMessageEventSharedPtr& messageEvent, MessageEventPriority priority) final;
        void Remove(const NetworkMessageEventSharedPtr& messageEvent) final;

        void OnEvent(uint64_t socketID, const ConstMessageInterfaceSharedPtr& message) final;

        NODISCARD ImplPtr Clone() const final;
        NODISCARD ImplPtr CloneToMultiMessage() const final;
        NODISCARD ImplPtr CloneToPriorityMessage() const final;

        NODISCARD bool IsCanInsert() const noexcept final;
        NODISCARD bool IsPrioritySame(MessageEventPriority priority) const noexcept final;

    private:
        using PriorityPointerContainer = std::vector<MultiMessageEventContainerImpl>;

    private:
        PriorityPointerContainer multiMessageEventContainer;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_PRIORITY_MESSAGE_EVENT_CONTAINER_H
