//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/26 20:41)

#ifndef NETWORK_NETWORK_MESSAGE_MULTI_MESSAGE_EVENT_CONTAINER_H
#define NETWORK_NETWORK_MESSAGE_MULTI_MESSAGE_EVENT_CONTAINER_H

#include "Network/NetworkDll.h"

#include "MessageEventContainerImpl.h"
#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Network/NetworkMessage/NetworkMessageInternalFwd.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE MultiMessageEventContainer final : public MessageEventContainerImpl
    {
    public:
        COPY_UNSHARE_CLASSES_TYPE_DECLARE(MultiMessageEventContainer, DESTRUCTOR_DEFAULT);
        using ParentType = MessageEventContainerImpl;

    public:
        explicit MultiMessageEventContainer(CoreTools::DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_FINAL_DECLARE;

        void Insert(const NetworkMessageEventSharedPtr& messageEvent) final;
        void Insert(const NetworkMessageEventSharedPtr& messageEvent, MessageEventPriority priority) final;
        void Remove(const NetworkMessageEventSharedPtr& messageEvent) noexcept final;

        void OnEvent(uint64_t socketID, const ConstMessageInterfaceSharedPtr& message) final;

        [[nodiscard]] ImplPtr Clone() const final;
        [[nodiscard]] ImplPtr CloneToMultiMessage() const final;
        [[nodiscard]] ImplPtr CloneToPriorityMessage() const final;

        [[nodiscard]] bool IsCanInsert() const noexcept final;
        [[nodiscard]] bool IsPrioritySame(MessageEventPriority priority) const noexcept final;

    private:
        IMPL_TYPE_DECLARE(MultiMessageEventContainer);
        MessageEventPriority m_Priority;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MULTI_MESSAGE_EVENT_CONTAINER_H
