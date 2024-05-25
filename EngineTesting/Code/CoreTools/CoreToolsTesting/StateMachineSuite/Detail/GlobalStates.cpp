/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.9 (2024/04/23 12:58)

#include "EmptyStates.h"
#include "GlobalStates.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/StateMachineManager/StateDetail.h"
#include "CoreTools/StateMachineManager/StateMachineBaseDetail.h"

CORE_TOOLS_RTTI_DEFINE(CoreTools, GlobalStates)

CoreTools::GlobalStates::GlobalStates() noexcept
    : ParentType{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, GlobalStates)

CoreTools::GlobalStates::StateSharedPtr CoreTools::GlobalStates::Execute([[maybe_unused]] int64_t timeInterval)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return shared_from_this();
}

void CoreTools::GlobalStates::Exit() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;
}

CoreTools::State<CoreTools::PlayerEntity>::MessageResult CoreTools::GlobalStates::OnMessage(const Telegram& telegram)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    switch (telegram.GetMessageType())
    {
        case States::Empty:
            return { ParentType::MakeState<EmptyStates>(), true };
        case States::Open:
            return { shared_from_this(), true };
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

void CoreTools::GlobalStates::DoEnter() noexcept
{
}
