// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒýÇæ²âÊÔ°æ±¾£º0.0.2.4 (2020/03/13 13:12)

#include "TestMessageEvent.h"
#include "CoreTools/Threading/ScopedMutex.h"

#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Interface/SendSocket.h"
#include "Network/NetworkMessage/NullMessage.h"

using std::make_shared;

Network::TestMessageEvent ::TestMessageEvent()
    : ParentType{}, m_CallBackTime{ 0 }, m_TestMessageEventCriticalSection{}, m_ServerWeakPtr{}
{
    m_TestMessageEventCriticalSection.Initialize();

    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::TestMessageEvent ::~TestMessageEvent()
{
    NETWORK_SELF_CLASS_IS_VALID_9;

    m_TestMessageEventCriticalSection.Delete();
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, TestMessageEvent);

uint64_t Network::TestMessageEvent ::GetCallBackTime() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return m_CallBackTime;
}

void Network::TestMessageEvent ::CallBackEvent([[maybe_unused]] uint64_t socketID, const ConstMessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_9;

    CoreTools::ScopedMutex scopedMutex{ m_TestMessageEventCriticalSection };

    m_CallBackTime += message->GetMessageID();

    auto serverSharedPtr = m_ServerWeakPtr.lock();

    if (serverSharedPtr)
    {
        MessageInterfaceSharedPtr sendMessage{ make_shared<NullMessage>(message->GetMessageID()) };
        serverSharedPtr->AsyncSend(socketID, sendMessage);
    }
}

void Network::TestMessageEvent ::SetServerWeakPtr(const ServerSharedPtr& ptr)
{
    NETWORK_CLASS_IS_VALID_9;

    m_ServerWeakPtr = ptr;
}
