// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/12 13:25)

#include "TestNetworkMessageEvent.h"
#include "TestNullMessage.h"
#include "boost/polymorphic_cast.hpp"
#include "System/Threading/SyncTools.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

Network::TestNetworkMessageEvent ::TestNetworkMessageEvent() noexcept
    : ParentType{}, m_Value{ 0 }, m_NowTime{ 0 }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)
CLASS_INVARIANT_STUB_DEFINE(Network, TestNetworkMessageEvent);

void Network::TestNetworkMessageEvent ::CallBackEvent(uint64_t socketID, const ConstMessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_9;

    if (0 < socketID)
    {
        auto testNullMessage = boost::polymorphic_cast<const TestNullMessage*>(message.get());
        if (testNullMessage == nullptr)
            return;

        m_Value += testNullMessage->GetValue();

        m_NowTime = System::GetTimeInMicroseconds();

        System::SystemSleep(1);
    }
}

int Network::TestNetworkMessageEvent ::GetValue() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return m_Value;
}

int64_t Network::TestNetworkMessageEvent ::GetNowTime() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return m_NowTime;
}
