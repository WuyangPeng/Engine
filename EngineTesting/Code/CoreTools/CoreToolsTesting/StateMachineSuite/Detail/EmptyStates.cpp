///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/18 11:08)

#include "EmptyStates.h"
#include "OpenStates.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/StateMachineManager/StateMachineBaseDetail.h"

CORE_TOOLS_RTTI_DEFINE(CoreTools, EmptyStates)

CoreTools::EmptyStates::EmptyStates() noexcept
    : ParentType{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, EmptyStates)

CoreTools::EmptyStates::StateSharedPtr CoreTools::EmptyStates::Execute([[maybe_unused]] int64_t timeInterval)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return shared_from_this();
}

void CoreTools::EmptyStates::Exit() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;
}

CoreTools::State<CoreTools::PlayerEntity>::MessageResult CoreTools::EmptyStates::OnMessage(const Telegram& telegram)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    switch (telegram.GetMessageType())
    {
        case States::Empty:
            return { shared_from_this(), false };
        case States::Open:
            return { State<PlayerEntity>::MakeState<OpenStates>(), true };
        case States::Stopped:
            return { shared_from_this(), true };
        case States::Playing:
            return { shared_from_this(), true };
        case States::Paused:
            return { shared_from_this(), true };
        case States::Previous:
            return { GetPossiblePreviousState(), true };
        default:
            break;
    }

    return { shared_from_this(), true };
}

void CoreTools::EmptyStates::DoEnter() noexcept
{
}
