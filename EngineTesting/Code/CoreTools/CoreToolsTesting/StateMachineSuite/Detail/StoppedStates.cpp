///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 14:49)

#include "PausedStates.h"
#include "PlayingStates.h"
#include "StoppedStates.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/StateMachineManager/StateDetail.h"
#include "CoreTools/StateMachineManager/StateEntityDetail.h"
#include "CoreTools/StateMachineManager/StateMachineBaseDetail.h"

CORE_TOOLS_RTTI_DEFINE(CoreTools, StoppedStates)

CoreTools::StoppedStates::StoppedStates() noexcept
    : ParentType{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, StoppedStates)

CoreTools::StoppedStates::StateSharedPtr CoreTools::StoppedStates::Execute([[maybe_unused]] int64_t timeInterval)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return shared_from_this();
}

void CoreTools::StoppedStates::Exit() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;
}

CoreTools::State<CoreTools::PlayerEntity>::MessageResult CoreTools::StoppedStates::OnMessage(const Telegram& telegram)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    switch (telegram.GetMessageType())
    {
        case States::Empty:
            return { shared_from_this(), false };
        case States::Open:
            return { shared_from_this(), true };
        case States::Stopped:
            return { shared_from_this(), true };
        case States::Playing:
            return { ParentType::MakeState<PlayingStates>(), true };
        case States::Paused:
            return { ParentType::MakeState<PausedStates>(), true };
        case States::Previous:
            return { GetPossiblePreviousState(), true };
        default:
            break;
    }

    return make_pair(shared_from_this(), true);
}

void CoreTools::StoppedStates::DoEnter() noexcept
{
}