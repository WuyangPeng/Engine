/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:13)

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
        explicit PriorityMessageEventContainer(CoreTools::DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_FINAL_DECLARE;

        void Insert(const NetworkMessageEventSharedPtr& messageEvent) override;
        void Insert(const NetworkMessageEventSharedPtr& messageEvent, MessageEventPriority priority) override;
        void Remove(const NetworkMessageEventSharedPtr& messageEvent) override;

        void OnEvent(uint64_t socketId, const ConstMessageInterfaceSharedPtr& message) override;

        NODISCARD ImplPtr Clone() const override;
        NODISCARD ImplPtr CloneToMultiMessage() const override;
        NODISCARD ImplPtr CloneToPriorityMessage() const override;

        NODISCARD bool IsCanInsert() const noexcept override;
        NODISCARD bool IsPrioritySame(MessageEventPriority priority) const noexcept override;

    private:
        using PriorityPointerContainer = std::vector<MultiMessageEventContainerImpl>;

    private:
        PriorityPointerContainer multiMessageEventContainer;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_PRIORITY_MESSAGE_EVENT_CONTAINER_H
