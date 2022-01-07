// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 19:15)

#include "EmptyStates.h"
#include "OpenStates.h"
#include "PlayingStates.h"
#include "StoppedStates.h"

#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include "CoreTools/StateMachineManager/StateMachineBaseDetail.h"

using std::make_pair;

CORE_TOOLS_RTTI_DEFINE(CoreTools, OpenStates)

CoreTools::OpenStates ::OpenStates() noexcept
    : ParentType{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

 

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, OpenStates)

CoreTools::OpenStates::StateSharedPtr CoreTools::OpenStates ::Execute([[maybe_unused]] int64_t timeInterval)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return shared_from_this();
}

void CoreTools::OpenStates ::Exit() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;
}

CoreTools::State<CoreTools::PlayerEntity>::MessageResult CoreTools::OpenStates ::OnMessage(const Telegram& telegram)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    switch (telegram.GetMessageType())
    {
        case States::Empty:
            return make_pair(State<PlayerEntity>::MakeState<EmptyStates>(), true);
        case States::Open:
            return make_pair(shared_from_this(), true);
        case States::Stopped:
            return make_pair(State<PlayerEntity>::MakeState<StoppedStates>(), true);
        case States::Playing:
            return make_pair(State<PlayerEntity>::MakeState<PlayingStates>(), true);
        case States::Paused:
            return make_pair(shared_from_this(), true);
        case States::Previous:
            return make_pair(GetPossiblePreviousState(), true);
        default:
            break;
    }

    return make_pair(shared_from_this(), true);
}

void CoreTools::OpenStates ::DoEnter() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;
}
