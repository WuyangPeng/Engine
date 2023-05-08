///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/23 15:46)

#include "TestNetworkMessageEvent.h"
#include "TestNullMessage.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "System/Threading/SyncTools.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

Network::TestNetworkMessageEvent::TestNetworkMessageEvent() noexcept
    : ParentType{}, value{ 0 }, nowTime{ 0 }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, TestNetworkMessageEvent);

void Network::TestNetworkMessageEvent::CallBackEvent(uint64_t socketID, const ConstMessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_9;

    if (0 < socketID)
    {
        auto testNullMessage = boost::polymorphic_pointer_cast<const TestNullMessage>(message);
        if (testNullMessage == nullptr)
            return;

        value += testNullMessage->GetValue();

        nowTime = System::GetTimeInMicroseconds();

        System::SystemSleep(1);
    }
}

int Network::TestNetworkMessageEvent::GetValue() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return value;
}

int64_t Network::TestNetworkMessageEvent::GetNowTime() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return nowTime;
}
