///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/18 11:11)

#include "EmptyStates.h"
#include "OpenStates.h"
#include "PlayingStates.h"
#include "StoppedStates.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/StateMachineManager/StateMachineBaseDetail.h"

using std::make_pair;

CORE_TOOLS_RTTI_DEFINE(CoreTools, OpenStates)

CoreTools::OpenStates::OpenStates() noexcept
    : ParentType{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, OpenStates)

CoreTools::OpenStates::StateSharedPtr CoreTools::OpenStates::Execute([[maybe_unused]] int64_t timeInterval)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return shared_from_this();
}

void CoreTools::OpenStates::Exit() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;
}

CoreTools::State<CoreTools::PlayerEntity>::MessageResult CoreTools::OpenStates::OnMessage(const Telegram& telegram)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    switch (telegram.GetMessageType())
    {
        case States::Empty:
            return { State<PlayerEntity>::MakeState<EmptyStates>(), true };
        case States::Open:
            return { shared_from_this(), true };
        case States::Stopped:
            return { State<PlayerEntity>::MakeState<StoppedStates>(), true };
        case States::Playing:
            return { State<PlayerEntity>::MakeState<PlayingStates>(), true };
        case States::Paused:
            return { shared_from_this(), true };
        case States::Previous:
            return { GetPossiblePreviousState(), true };
        default:
            break;
    }

    return make_pair(shared_from_this(), true);
}

void CoreTools::OpenStates::DoEnter() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;
}
