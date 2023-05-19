///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.8 (2023/05/11 11:35)

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

void Network::TestNetworkMessageEvent::CallBackEvent(int64_t socketId, const ConstMessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_9;

    if (0 < socketId)
    {
        const auto testNullMessage = boost::polymorphic_pointer_cast<const TestNullMessage>(message);

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
