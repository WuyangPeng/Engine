//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/27 13:53)

#include "Network/NetworkExport.h"

#include "MultiMessageEventContainer.h"
#include "PriorityMessageEventContainer.h"
#include "SingleMessageEventContainer.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using std::make_shared;

Network::SingleMessageEventContainer::SingleMessageEventContainer() noexcept
    : ParentType{}, m_MessageEvent{}
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, SingleMessageEventContainer)

void Network::SingleMessageEventContainer::Insert(const NetworkMessageEventSharedPtr& messageEvent)
{
    NETWORK_CLASS_IS_VALID_9;

    if (m_MessageEvent.lock())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("��Ϣ�¼��Ѵ��ڣ�"s));
    }

    m_MessageEvent = messageEvent;
}

void Network::SingleMessageEventContainer::Remove(const NetworkMessageEventSharedPtr& messageEvent)
{
    NETWORK_CLASS_IS_VALID_9;

    if (m_MessageEvent.lock() == messageEvent)
    {
        m_MessageEvent.reset();
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("��Ϣ�¼������ڣ�"s));
    }
}

void Network::SingleMessageEventContainer::OnEvent(uint64_t socketID, const ConstMessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_9;

    auto messageEvent = m_MessageEvent.lock();

    if (messageEvent)
    {
        messageEvent->CallBackEvent(socketID, message);
    }
}

void Network::SingleMessageEventContainer::Insert(const NetworkMessageEventSharedPtr& messageEvent, [[maybe_unused]] MessageEventPriority priority)
{
    NETWORK_CLASS_IS_VALID_9;

    if (m_MessageEvent.lock())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("��Ϣ�¼��Ѵ��ڣ�"s));
    }

    m_MessageEvent = messageEvent;
}

Network::SingleMessageEventContainer::ImplPtr Network::SingleMessageEventContainer::Clone() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return make_shared<ClassType>(*this);
}

Network::SingleMessageEventContainer::ImplPtr Network::SingleMessageEventContainer::CloneToMultiMessage() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    auto messageEvent = m_MessageEvent.lock();
    auto multiMessageEventContainer = make_shared<MultiMessageEventContainer>(CoreTools::DisableNotThrow::Disable);

    if (messageEvent)
    {
        multiMessageEventContainer->Insert(messageEvent);
    }

    return multiMessageEventContainer;
}

Network::SingleMessageEventContainer::ImplPtr Network::SingleMessageEventContainer::CloneToPriorityMessage() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    auto messageEvent = m_MessageEvent.lock();
    auto priorityMessageEventContainer = make_shared<PriorityMessageEventContainer>();

    if (messageEvent)
    {
        priorityMessageEventContainer->Insert(messageEvent);
    }

    return priorityMessageEventContainer;
}

bool Network::SingleMessageEventContainer::IsCanInsert() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    if (!m_MessageEvent.lock())
        return true;
    else
        return false;
}

bool Network::SingleMessageEventContainer::IsPrioritySame([[maybe_unused]] MessageEventPriority priority) const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return false;
}
